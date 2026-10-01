#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <complex.h>
#include <iostream>
#include <omp.h>
extern "C" {
#if USE_MKL
#  include <mkl_cblas.h>
#else
#  include <cblas.h>
#endif
}
#include <cuda_runtime.h>
#include <cublas_v2.h>

#define        ITER        1

#include "aspen_const.h"


#if TYPE_DD
#  include "aspen_ddreal.h"
#endif
#if TYPE_DD_COMPLEX
#  include "aspen_ddreal.h"
#  include "aspen_ddcomplex.h"
#endif

#if TYPE_HALF
#  include "../half/include/half.hpp"
#endif
#if TYPE_HALF_COMPLEX
#  include "../half/include/half.hpp"
#  include "aspen_half_complex.h"
#endif

#define USE_CUDA_EVENT_TIMER        0
#include "test-common.h"
#include "test.h"

#if TYPE_BF16
#  define        TYPE_NO_TEST        1
#else
#  define        TYPE_NO_TEST        0
#endif

#if !TYPE_NO_TEST

template <class T> T rand_(void) { T t = (T)rand(); return t; }

template <> half rand_<half>(void) {
  const float t = (float)rand() / RAND_MAX;
  half r = float2half(t);
  return r;
}

template <> float rand_<float>(void) {
  const float t = (float)rand();
  return t / RAND_MAX;
}

template <> double rand_<double>(void) {
  const double t = (double)rand();
  return t / RAND_MAX;
}

template <> int16 rand_<int16>(void) {
  int16 t;
  short t1 = (short)rand();
  t1 &= 0x803f;
  t = t1;
  return t;
}

template <> int32 rand_<int32>(void) {
  int32 t;
  int t1 = (int)rand();
  t1 &= 0x80000fff;
  t = t1;
  return t;
}

unsigned int unsigned_rand32(void)
{
  union { 
    unsigned int ui;
    signed int si;
  } v;
  v.si = rand();
  return v.ui;
}

template <> int64 rand_<int64>(void) {
  int64 t;
  unsigned long t1 = (unsigned long)unsigned_rand32();
  unsigned long t2 = (unsigned long)unsigned_rand32();
  union {
    unsigned long ul;
    signed long sl;
  } v;
  t1 &= 0x0000000000ffffff;
  t2 <<= 32;
  t2 &= 0x8000000000000000;
  v.ul = t2 | t1;
  t = v.sl;
  return t;
}

template <> int128 rand_<int128>(void) {
  uint64_t t1 = (uint64_t)rand_<int64>();
  uint64_t t2 = (uint64_t)rand_<int64>();
  int128 t;
  t = t1;
  t <<= 64;
  t |= t2;
  return t;
}

#if 0
template <> bfloat16 rand_<bfloat16>(void) {
  union { 
    unsigned short x[2];
    float y;
  } u;
  u.y = rand_<float>();
  bfloat16 t; t.x = u.x[1];
  return t;
}
#endif

#if TYPE_DD || TYPE_DD_COMPLEX
template <> cuddreal rand_<cuddreal>(void) {
  const double t1 = rand_<double>();
  const double t2 = rand_<double>() / (((long)1)<<53);
  const cuddreal t = { t1, makeCONST<double>(0) };
  const cuddreal s = { t2, makeCONST<double>(0) };
  return t+s;
}
#endif

template <> cuHalfComplex rand_<cuHalfComplex>(void) {
  const half tx = rand_<half>(), ty = rand_<half>();
  const cuHalfComplex t = { tx, ty };
  return t;
}

template <> cuFloatComplex rand_<cuFloatComplex>(void) {
  const float tx = rand_<float>(), ty = rand_<float>();
  const cuFloatComplex t = { tx, ty };
  return t;
}

template <> cuDoubleComplex rand_<cuDoubleComplex>(void) {
  const double tx = rand_<double>(), ty = rand_<double>();
  const cuDoubleComplex t = { tx, ty };
  return t;
}

#if TYPE_DD_COMPLEX
template <> cuddcomplex rand_<cuddcomplex>(void) {
  const cuddreal tx = rand_<cuddreal>(), ty = rand_<cuddreal>();
  const cuddcomplex t = { tx, ty };
  return t; }
#endif


template < class T >
void symv(
          const char *uplo,
          const int n,
          const T alpha, const T * A, const int lda,
          const T * x, const int incx,
          const T beta, T * y, const int incy
          )
{

  const T ZERO = makeCONST < T > (0);
  static int num_threads; 
#pragma omp parallel
  {
#pragma omp master
    { num_threads = omp_get_num_threads(); }
  }

  size_t len;
  len = ((size_t)sizeof(T))*n;
  T *w = (T*)malloc( len );
  len = ((size_t)sizeof(T))*n*num_threads;
  T *wk = (T*)malloc( len );

#define        SET_private_WK_HEAD(n)                          \
  wk + ((size_t)omp_get_thread_num())*((size_t)(n));

  for(int j=0;j<n;j++){ VEC2(y,j,incy) = VEC2(y,j,incy)*beta; VEC(w,j) = ZERO; }
#pragma omp parallel
  {
    T *WK = SET_private_WK_HEAD(n);
    for(int j=0;j<n;j++){ VEC(WK,j) = ZERO; }
  }

  if ( *uplo == 'u' || *uplo == 'U' ) {

#pragma omp parallel for
    for(int i=0;i<n;i++){
      T *WK = SET_private_WK_HEAD(n);
      T s = ZERO, u = VEC2(x,i,incx);
      for(int j=0;j<i;j++){
        T t = MAT(A,j,i,lda);
        VEC(WK,j) = VEC(WK,j) + t * u;
        s         = s + Conj(t) * VEC2(x,j,incx);
#if 0
#if TYPE_HALF
        std::cout << j << "," << i << " " << t.val << " "
                  << u.val << " " << VEC(WK,j).val << " "
                  << (t*u).val << std::endl;
#endif
#endif
      }
      //      s = s + MAT(A,i,i,lda) * VEC2(x,i,incx);
      VEC(w,i) = MAT(A,i,i,lda) * VEC2(x,i,incx);
      //      VEC(WK,i) = VEC(WK,i) + s;
      VEC(WK,i) = s;
    }
#pragma omp parallel for schedule(dynamic)
    for(int i=0;i<n;i++){
      for(int j=0;j<num_threads;j++){
        VEC(w,i) = VEC(w,i) + MAT(wk,i,j,n);
      }
    }
#pragma omp parallel for schedule(dynamic)
    for(int i=0;i<n;i++){
      VEC2(y,i,incy) = VEC2(y,i,incy) + alpha * VEC(w,i);
    }

  } else if ( *uplo == 'l' || *uplo == 'L' ) {

#pragma omp parallel for
    for(int i=0;i<n;i++){
      T *WK = SET_private_WK_HEAD(n);
      T s = ZERO, u = VEC2(x,i,incx);
      s = s + MAT(A,i,i,lda) * VEC2(x,i,incx);
      for(int j=i+1;j<n;j++){
        T t = MAT(A,j,i,lda);
        VEC(WK,j) = VEC(WK,j) + t * u;
        s         = s + Conj(t) * VEC2(x,j,incx);
      }
      VEC(WK,i) = VEC(WK,i) + s;
    }
#pragma omp parallel for schedule(dynamic)
    for(int i=0;i<n;i++){
      for(int j=0;j<num_threads;j++){
        VEC(w,i) = VEC(w,i) + MAT(wk,i,j,n);
      }
    }
#pragma omp parallel for schedule(dynamic)
    for(int i=0;i<n;i++){
      VEC2(y,i,incy) = VEC2(y,i,incy) + alpha * VEC(w,i);
    }
  }

  free(w);
  free(wk);
}

void hsymv(
           const char *uplo,
           const int n,
           const half alpha, const half * A, const int lda,
           const half * x, const int incx,
           const half beta, half * y, const int incy
           )
{
  symv < half > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}

#if !TYPE_HALF
void wsymv(
           const char *uplo,
           const int n,
           const cuddreal alpha, const cuddreal * A, const int lda,
           const cuddreal * x, const int incx,
           const cuddreal beta, cuddreal * y, const int incy
           )
{
  symv < cuddreal > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}

void khemv(
           const char *uplo,
           const int n,
           const cuHalfComplex alpha, const cuHalfComplex * A, const int lda,
           const cuHalfComplex * x, const int incx,
           const cuHalfComplex beta, cuHalfComplex * y, const int incy
           )
{
  symv < cuHalfComplex > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}

void uhemv(
           const char *uplo,
           const int n,
           const cuddcomplex alpha, const cuddcomplex * A, const int lda,
           const cuddcomplex * x, const int incx,
           const cuddcomplex beta, cuddcomplex * y, const int incy
           )
{
  symv < cuddcomplex > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}

void i16symv(
             const char *uplo,
             const int n,
             const int16 alpha, const int16 * A, const int lda,
             const int16 * x, const int incx,
             const int16 beta, int16 * y, const int incy
             )
{
  symv < int16 > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}

void i32symv(
             const char *uplo,
             const int n,
             const int32 alpha, const int32 * A, const int lda,
             const int32 * x, const int incx,
             const int32 beta, int32 * y, const int incy
             )
{
  symv < int32 > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}
void i64symv(
             const char *uplo,
             const int n,
             const int64 alpha, const int64 * A, const int lda,
             const int64 * x, const int incx,
             const int64 beta, int64 * y, const int incy
             )
{
  symv < int64 > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}
void i128symv(
              const char *uplo,
              const int n,
              const int128 alpha, const int128 * A, const int lda,
              const int128 * x, const int incx,
              const int128 beta, int128 * y, const int incy
              )
{
  symv < int128 > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}
#if 0
void bf16symv(
              const char *uplo,
              const int n,
              const bfloat16 alpha, const bfloat16 * A, const int lda,
              const bfloat16 * x, const int incx,
              const bfloat16 beta, bfloat16 * y, const int incy
              )
{
  symv < bfloat16 > ( uplo, n, alpha, A, lda, x, incx, beta, y, incy );
}
#endif
#endif

void
set_matrix_vectors( const int N, TYPE *A, const int lda, TYPE *X, TYPE *Y,
                    const enum _FUNCS func );

void
set_matrix_vectors( const int N, TYPE *A, const int lda, TYPE *X, TYPE *Y,
                    const enum _FUNCS func )
{

  srand(0);

  for(int i=0;i<N;i++) {
    for(int j=0;j<lda;j++) {
      MAT(A,j,i,lda)=makeCONST<TYPE>(0);
    }
  }

  TYPE one = makeCONST<TYPE>(1);
#if 1
#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
  for(int i=0;i<N;i++) VEC(X,i) = 
	  (2*rand_<TYPE>()-one) / (int)sqrt(sqrt((double)N));
  for(int i=0;i<N;i++) VEC(Y,i) =
 	  (2*rand_<TYPE>()-one) / (int)sqrt(sqrt((double)N));
#if TYPE_DOUBLE
  for(int i=0; i<10; i++) {
    unsigned int j = unsigned_rand32() % N;
    VEC(X,j) *= sqrt((double)N);
    unsigned int k = unsigned_rand32() % N;
    VEC(Y,k) *= sqrt((double)N);
  } 
#endif
#else
  for(int i=0;i<N;i++) VEC(X,i) = rand_<TYPE>();
  for(int i=0;i<N;i++) VEC(Y,i) = rand_<TYPE>();
#endif

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
      MAT(A,j,i,lda) =  rand_<TYPE>() / N;
#else
      MAT(A,j,i,lda) =  rand_<TYPE>();
#endif
    }
  }
#else
  for(int i=0;i<N;i++) VEC(X,i) = makeCONST<TYPE>(1);
  for(int i=0;i<N;i++) VEC(Y,i) = makeCONST<TYPE>(1);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      MAT(A,j,i,lda) =  makeCONST<TYPE>(i+j);
    }
  }
#endif

#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT128 || TYPE_INT64 || TYPE_INT32 || TYPE_INT16 || TYPE_BF16
  if ( func == SYMV_U ) {
#pragma omp parallel for
    for(int i=0;i<N;i++) {
      for(int j=0;j<i;j++) {
        TYPE  t1  = MAT(A,j,i,lda);
        TYPE  t2  = MAT(A,i,j,lda);
        MAT(A,i,j,lda) = makeCONST<TYPE>(0);
        MAT(A,j,i,lda) = t1+t2;
#if TYPE_DD
        MAT(A,j,i,lda).hi(MAT(A,j,i,lda).hi()/2);
        MAT(A,j,i,lda).err(MAT(A,j,i,lda).err()/2);
#else
#if TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF
        MAT(A,j,i,lda) /= 2;
#endif
#endif
      }
    }
  }
  if ( func == SYMV_L ) {
#pragma omp parallel for
    for(int i=0;i<N;i++) {
      for(int j=i+1;j<N;j++) {
        TYPE  t1  = MAT(A,j,i,lda);
        TYPE  t2  = MAT(A,i,j,lda);
        MAT(A,i,j,lda) = makeCONST<TYPE>(0);
        MAT(A,j,i,lda) = t1+t2;
#if TYPE_DD
        MAT(A,j,i,lda).hi(MAT(A,j,i,lda).hi()/2);
        MAT(A,j,i,lda).err(MAT(A,j,i,lda).err()/2);
#else
#if TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF
        MAT(A,j,i,lda) /= 2;
#endif
#endif
      }
    }
  }
#else
  if ( func == HEMV_U ) {
#pragma omp parallel for
    for(int i=0;i<N;i++) {
      set_imag( MAT(A,i,i,lda), makeCONST<TYPE_>(0) );
      for(int j=0;j<i;j++) {
        TYPE  t1  = MAT(A,j,i,lda);
        TYPE  t2  = MAT(A,i,j,lda);
        MAT(A,i,j,lda) = makeCONST<TYPE>(0);
        MAT(A,j,i,lda) = t1+t2;
#if TYPE_DD_COMPLEX
        double xx = MAT(A,j,i,lda).real().hi() / 2;
        double xy = MAT(A,j,i,lda).real().err() / 2;
        double yx = MAT(A,j,i,lda).imag().hi() / 2;
        double yy = MAT(A,j,i,lda).imag().err() / 2;
        MAT(A,j,i,lda) = __cuddcomplex__( __cuddreal__(xx, xy), __cuddreal__(yx, yy) );
#else
        MAT(A,j,i,lda) = MAT(A,j,i,lda) / 2;
#endif
      }
    }
  }
  if ( func == HEMV_L ) {
#pragma omp parallel for
    for(int i=0;i<N;i++) {
      set_imag( MAT(A,i,i,lda), makeCONST<TYPE_>(0) );
      for(int j=i+1;j<N;j++) {
        TYPE  t1  = MAT(A,j,i,lda);
        TYPE  t2  = MAT(A,i,j,lda);
        MAT(A,i,j,lda) = makeCONST<TYPE>(0);
        MAT(A,j,i,lda) = t1+t2;
#if TYPE_DD_COMPLEX
        double xx = MAT(A,j,i,lda).real().hi() / 2;
        double xy = MAT(A,j,i,lda).real().err() / 2;
        double yx = MAT(A,j,i,lda).imag().hi() / 2;
        double yy = MAT(A,j,i,lda).imag().err() / 2;
        MAT(A,j,i,lda) = __cuddcomplex__( __cuddreal__(xx, xy), __cuddreal__(yx, yy) );
#else
        MAT(A,j,i,lda) = MAT(A,j,i,lda) / 2;
#endif
      }
    }
  }
#endif
}
#endif

int
main(int argc, char *argv[])
{
  TYPE        alpha, beta;

  TYPE        *A, *B, *C, *D;
  TYPE        *X;
  TYPE        *dA, *dB, *dC, *dD;

  int        N, M, K;
  int        LDA, LDB, LDC;
  int        i;
  int        blk;
  FILE        *fp;
  int        verify = 0;
  int        id = get_gpu_id();

  enum _FUNCS func;
  char        *func_name = (char *)"";


  CUDA_INVOKE( cudaSetDevice, (id) );

  cublasStatus_t stat;
  cublasHandle_t handle;
  stat = cublasCreate( &handle );


  ASPEN_init( id );

  {
    char *argv0 = argv[0];
    if ( strrchr(argv0, '/') != argv0 ) {
      argv0 = strrchr(argv0,'/')+1;
    }
#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT128 || TYPE_INT64 || TYPE_INT32 || TYPE_INT16 || TYPE_BF16
    if ( 0 == strcmp(argv0,TEST_SYMV_U) ) {
      func      = SYMV_U;
      func_name = (char *)NAME_SYMV_U;
    }
    if ( 0 == strcmp(argv0,TEST_SYMV_L) ) {
      func      = SYMV_L;
      func_name = (char *)NAME_SYMV_L;
    }
#else
    if ( 0 == strcmp(argv0,TEST_HEMV_U) ) {
      func      = HEMV_U;
      func_name = (char *)NAME_HEMV_U;
    }
    if ( 0 == strcmp(argv0,TEST_HEMV_L) ) {
      func      = HEMV_L;
      func_name = (char *)NAME_HEMV_L;
    }
#endif
  }

  if ( argc > 1 ) {
    fp=fopen(argv[1], "r");
  } else {
    fp=fopen("IN", "r");
  }
  if ( fp == NULL ) {
    fprintf(stderr,"Cannot open parameter file.\n");
    ASPEN_shutdown();
    exit(1);
  }

  fscanf(fp,"%d", &N);

  if ( argc > 2 ) {
    sscanf(argv[2], "%d", &blk);
    printf("%% BLK specified=%d\n", blk);
  } else {
    blk = -1; //64;
  }

  {
    verify = 1;
  }

  print_head( func_name, argc, argv );

  fflush(stdout);

#if TYPE_NO_TEST
  exit(0);
#else


#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
  TYPE_ eps; {
    TYPE_ one = makeCONST<TYPE_>(1);
    eps = one;
    while ( true ) {
      TYPE_ eps_ = eps; eps = eps / 2;
      TYPE_ c = one + eps;
      if ( c == one ) { 
        eps = eps_; break;
      }
    }
  }
#if TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
  const TYPE gamma = makeCONST<TYPE>(1) + (TYPE){eps, eps};
#else
  const TYPE gamma = makeCONST<TYPE>(1) + eps;
#endif
  alpha =  3*gamma;
  beta  =  4*gamma;
#endif
#if TYPE_INT128 || TYPE_INT64 || TYPE_INT32 || TYPE_INT16
  alpha = makeCONST<TYPE>(3);
  beta  = makeCONST<TYPE>(4);
#endif


  int N_fault=0;
  int N_max = get_Max_N( sizeof(TYPE) );
  int overflow = 0;

  for(int Itr = 0; fscanf(fp,"%d", &N) > 0; Itr++ ) {

    if ( N == 0 ) continue;
    if ( N < 1 ) break;
    if ( N > N_max ) { N = N_max; if ( overflow++ ) continue; }
    if ( N > 50000 ) { continue; }

    size_t len;
    int siz = 256/sizeof(TYPE);
    LDA = ((N-1)/siz+1)*siz;

    len = ((size_t)sizeof(TYPE)*N)*LDA;
    A = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    B = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    C = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    D = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    X = (TYPE *)malloc( len );
    if(A==NULL||B==NULL||C==NULL||D==NULL||X==NULL) {
      if(A!=NULL) free(A);
      if(B!=NULL) free(B);
      if(C!=NULL) free(C);
      if(D!=NULL) free(D);
      if(X!=NULL) free(X);
      fprintf(stderr, "# Fail to allocate Host_arra\n");
      goto HHH;
    }

    len = ((size_t)sizeof(TYPE)*N)*LDA;
    CUDA_INVOKE( cudaMalloc, ( (void**)&dA, len ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMalloc, ( (void**)&dB, len ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMalloc, ( (void**)&dC, len ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMalloc, ( (void**)&dD, len ) );

    if(dA==NULL||dB==NULL||dC==NULL||dD==NULL) {
      fprintf(stderr, "# Fail to allocate Dev_array %dx%d, %d*4\n",
              N, LDA, N);
      fprintf(stderr, "# Fail to allocate memory %lx %lx %lx %lx\n",
              (unsigned long)dA, (unsigned long)dB, (unsigned long)dC, (unsigned long)dD);
      if(dA!=NULL) cudaFree(dA);
      if(dB!=NULL) cudaFree(dB);
      if(dC!=NULL) cudaFree(dC);
      if(dD!=NULL) cudaFree(dD);
      N_fault++;
      goto FFF;
    } else {
      N_fault=0;
    }

    printf("N= %8d ", N);
    fflush(stdout);
    fflush(stdout);
    fflush(stdout);


    set_matrix_vectors( N, A, LDA, B, C, func );

    for(int i=0;i<N;i++) X[i] = D[i] = C[i];

    if ( argc > 3 ) { ; } else {
      len = ((size_t)sizeof(TYPE)*N)*LDA;
      CUDA_INVOKE( cudaMemcpy, ( dA, A, len, cudaMemcpyHostToDevice ) );
      len = ((size_t)sizeof(TYPE)*N);
      CUDA_INVOKE( cudaMemcpy, ( dB, B, len, cudaMemcpyHostToDevice ) );
      len = ((size_t)sizeof(TYPE)*N);
      CUDA_INVOKE( cudaMemcpy, ( dC, C, len, cudaMemcpyHostToDevice ) );
    }

    fflush(stdout);
    cudaDeviceSynchronize();

    for(int i=0;i<ITER;i++){

      int        incb = 1;
      int        incc = 1;
      char        *opt = (char *)"U";

      cudaDeviceSynchronize();
      do_usleep(100);
      switch (func) {

#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT128 || TYPE_INT64 || TYPE_INT32 || TYPE_INT16 || TYPE_BF16
      case SYMV_U:
        ASPEN_SYMVu (blk, N, dA, LDA, dB, 1, dC, 1, alpha, beta);
        break;

      case SYMV_L:
        ASPEN_SYMVl (blk, N, dA, LDA, dB, 1, dC, 1, alpha, beta);
        break;
#endif

#if TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
      case HEMV_U:
        ASPEN_HEMVu (blk, N, dA, LDA, dB, 1, dC, 1, alpha, beta);
        break;

      case HEMV_L:
        ASPEN_HEMVl (blk, N, dA, LDA, dB, 1, dC, 1, alpha, beta);
        break;
#endif

      }
      cudaDeviceSynchronize();
      len = ((size_t)sizeof(TYPE)*N);
      CUDA_INVOKE( cudaMemcpy, ( C, dC, len, cudaMemcpyDeviceToHost ) );

#if 1
      if(N<=50000) {
      int ok_repro = 1;
      for(int I_=0; I_<8; I_++) {

      cudaDeviceSynchronize();
      len = ((size_t)sizeof(TYPE)*N);
      CUDA_INVOKE( cudaMemcpy, ( dD, X, len, cudaMemcpyHostToDevice ) );
      do_usleep(100);
      switch (func) {

#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT128 || TYPE_INT64 || TYPE_INT32 || TYPE_INT16 || TYPE_BF16
      case SYMV_U:
        ASPEN_SYMVu (blk, N, dA, LDA, dB, 1, dD, 1, alpha, beta);
        break;

      case SYMV_L:
        ASPEN_SYMVl (blk, N, dA, LDA, dB, 1, dD, 1, alpha, beta);
        break;
#endif

#if TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
      case HEMV_U:
        ASPEN_HEMVu (blk, N, dA, LDA, dB, 1, dD, 1, alpha, beta);
        break;

      case HEMV_L:
        ASPEN_HEMVl (blk, N, dA, LDA, dB, 1, dD, 1, alpha, beta);
        break;
#endif

      }
      len = ((size_t)sizeof(TYPE)*N);
      CUDA_INVOKE( cudaMemcpy, ( D, dD, len, cudaMemcpyDeviceToHost ) );
      cudaDeviceSynchronize();

      int this_is_ok_repro = 1;
      for(int j=0; j<N; j++) {
        if ( C[j] == D[j] ) { ; } else { this_is_ok_repro = 0; break; }
      }
      fflush(stdout);
      if ( this_is_ok_repro ) {
        printf(".");
      } else {
        printf("x");
      }
      ok_repro &= this_is_ok_repro;

      }

      if ( ok_repro ) {
        printf("\n+++ REPRO OK +++\n");
      } else {      
        printf("\n*******************\n");
        printf("*** REPRO ERROR ***\n");
        printf("*******************\n");
      }

      }
#endif
#if 1
      cudaError_t cu_err = cudaGetLastError();
      if ( cu_err != cudaSuccess ) {
        printf("CUDA internal ERROR detected\n"); goto JJJ;
      }
#endif

      if ( argc > 3 ) goto FIN;

#if 1
      if(verify){
        if(i==0&&N<50000){
//          cudaDeviceSynchronize();
//          do_usleep(100);
//          for(int j=0;j<N;j++) {
//            C[j] = makeCONST<TYPE>(0);
//          }
//          len = ((size_t)sizeof(TYPE)*N);
//          CUDA_INVOKE( cudaMemcpy, ( C, dC, len, cudaMemcpyDeviceToHost ) );
//          cudaDeviceSynchronize();
//          do_usleep(100);
          {

#if TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX
#define        T(x)        (void *)x
#define        P(x)        (void *)&x
#else
#define        T(x)        x
#define        P(x)        x
#endif

#if TYPE_DD || TYPE_DD_COMPLEX || TYPE_HALF || TYPE_HALF_COMPLEX || TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128 || TYPE_BF16
#define        OPTIONS_U        "U"
#define        OPTIONS_L        "L"
#define        OPTIONS_N        "N"
#define        OPTIONS_T        "T"
#define        OPTIONS_C        "C"
#else
#define OPTIONS_U        CblasColMajor, CblasUpper
#define OPTIONS_L        CblasColMajor, CblasLower
#define OPTIONS_N        CblasColMajor, CblasNoTrans
#define OPTIONS_T        CblasColMajor, CblasTrans
#define OPTIONS_C        CblasColMajor, CblasConjTrans
#endif

            switch (func) {

#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT128 || TYPE_INT64 || TYPE_INT32 || TYPE_INT16 || TYPE_BF16
            case SYMV_U:
              cblas_symv ( 
                          OPTIONS_U,
                          N, P(alpha), T(A), LDA, T(B), 1, P(beta), T(X), 1 );
              break;

            case SYMV_L:
              cblas_symv ( 
                          OPTIONS_L,
                          N, P(alpha), T(A), LDA, T(B), 1, P(beta), T(X), 1 );
              break;
#endif

#if TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
            case HEMV_U:
              cblas_hemv ( 
                          OPTIONS_U,
                          N, P(alpha), T(A), LDA, T(B), 1, P(beta), T(X), 1 );
              break;

            case HEMV_L:
              cblas_hemv ( 
                          OPTIONS_L,
                          N, P(alpha), T(A), LDA, T(B), 1, P(beta), T(X), 1 );
              break;
#endif

            }
          }
          do_usleep(100);

#if TYPE_DOUBLE
#define        FABS        fabs
#endif
#if TYPE_FLOAT
#define        FABS        fabsf
#endif
#if TYPE_HALF || TYPE_HALF_COMPLEX
#define        FABS        Abs
#endif
#if TYPE_DD || TYPE_DD_COMPLEX
#define        FABS        Abs
#endif
#if TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX 
#define        FABS        abs
#endif
#if TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128 || TYPE_BF16
#define        FABS        Abs
#endif

#if TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128 || TYPE_BF16
#define        CONV_TYPE        TYPE
#endif
#if TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX
#define        CONV_TYPE        std::complex<TYPE_>
#endif
#if TYPE_HALF_COMPLEX
#define        CONV_TYPE        cuHalfComplex
#endif
#if TYPE_DD
#define        CONV_TYPE        cuddreal
#endif
#if TYPE_DD_COMPLEX
#define        CONV_TYPE        cuddcomplex
#endif


#if TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128
          const double tol = 0;
#else
          const double tol = 128*EPS;
#endif

#if TYPE_DD || TYPE_DD_COMPLEX
#define        TYPE__        cuddreal
#else
#if TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128
#define        TYPE__        TYPE
#else
#define        TYPE__        double
#endif
#endif

          static TYPE__ t1,t2,t3;
          t1 = t2 = t3 = makeCONST<TYPE__>(0);

          CONV_TYPE *P = (CONV_TYPE *)C;
          CONV_TYPE *Q = (CONV_TYPE *)X;

          for(size_t j=0;j<N;j++){
              t1 = t1 + (TYPE__)FABS(VEC(P,j)-VEC(Q,j));
              t2 = t2 + (TYPE__)FABS(VEC(P,j));
              t3 = t3 + (TYPE__)FABS(VEC(Q,j));
          }

          double T1,T2,T3;
#if TYPE_DD || TYPE_DD_COMPLEX || TYPE_INT16 || TYPE_INT128 || TYPE_HALF || TYPE_HALF_COMPLEX
#if TYPE_DD || TYPE_DD_COMPLEX
          T1 = (double)(t1.hi());
          T2 = (double)(t2.hi());
          T3 = (double)(t3.hi());
#endif
#if TYPE_INT16
          T1 = (double)(t1);
          T2 = (double)(t2);
          T3 = (double)(t3);
#endif
#if TYPE_INT128
          T1 = (double)(t1);
          T2 = (double)(t2);
          T3 = (double)(t3);
#endif
#if TYPE_HALF || TYPE_HALF_COMPLEX
          T1 = (double)(t1);
          T2 = (double)(t2);
          T3 = (double)(t3);
#endif
#else
          T1 = (double)(t1);
          T2 = (double)(t2);
          T3 = (double)(t3);
#endif
          T1 = T1 / N;
          T2 = T2 / N;
          T3 = T3 / N;

          printf( " | ASPEN - CBLAS |/N = %20.17e\n", T1 );
          printf( " | ASPEN |/N = %20.17e, | CBLAS |/N = %20.17e\n", T2, T3 );
          printf( " TOL = %e ", tol * FABS(T3) );

          if ( (tol > 0 && T1 > tol * T2) ||
               (tol == 0 && T1 != 0) ) {
            printf( " \n" );
            printf( " ********* \n" );
            printf( " **ERROR** \n" );
            printf( " ********* \n" );
          } else {
            printf( " ++PASSED++\n" );
          }

          cudaDeviceSynchronize();
          do_usleep(100);
        }
      }

#endif

    }

  EEE:;

    cudaDeviceSynchronize();

    fflush(stdout);
  GGG:
    fflush(stdout);

    CUDA_INVOKE( cudaFree, (dA) ); //printf(":dA");
    CUDA_INVOKE( cudaFree, (dB) ); //printf(":dB");
    CUDA_INVOKE( cudaFree, (dC) ); //printf(":dC");
    CUDA_INVOKE( cudaFree, (dD) ); //printf(":dC");

  FFF:
    free(A); //printf(":A");
    free(B); //printf(":B");
    free(C); //printf(":C");
    free(D); //printf(":D");
    free(X); //printf(":X");

  HHH:
    printf("\n");
    fflush(stdout);
    fflush(stdout);

    if ( N_fault > 0 ) break;
    if ( feof(fp) ) break;
  }


  cublasDestroy( handle );
  ASPEN_shutdown();
 JJJ:
  cudaDeviceReset();
  fclose(fp);
 FIN:
  return 0;
#endif

}

