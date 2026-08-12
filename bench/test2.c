#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <complex.h>
#include <omp.h>
extern "C" {
#if USE_MKL
#include <mkl_cblas.h>
#else
#include <cblas.h>
#endif
}
#include <cuda_runtime.h>
#include <cublas_v2.h>

#define	ITER	6
#define	LOCAL_ITR_MAX	3

#include "aspen_const.h"


#if TYPE_HALF_COMPLEX
#include "aspen_half_complex.h"
#endif
#if TYPE_DD
#include "aspen_ddreal.h"
#endif
#if TYPE_DD_COMPLEX
#include "aspen_ddreal.h"
#include "aspen_ddcomplex.h"
#endif

#if TYPE_INT16
#include "aspen_int16.h"
#endif
#if TYPE_INT32
#include "aspen_int32.h"
#endif
#if TYPE_INT64
#include "aspen_int64.h"
#endif
#if TYPE_INT128
#include "aspen_int128.h"
#endif


#define USE_CUDA_EVENT_TIMER	0
#include "test-common.h"
#include "test.h"

extern "C" void WarmUp_GPU( const int id );
#if 0
extern "C" void	ASPEN_max_freq(void);
#endif


void
set_matrix_vectors( const int N, TYPE *A, const int lda, TYPE *X, TYPE *Y,
                    const enum _FUNCS func );



void
set_matrix_vectors( const int N, TYPE *A, const int lda, TYPE *X, TYPE *Y,
                    const enum _FUNCS func )
{
#pragma omp parallel
  {
#pragma omp for
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        MAT(A,j,i,lda)=makeCONST<TYPE>(0);
      }
    }

#pragma omp for
    for(int i=0;i<N;i++) VEC(X,i)=makeCONST<TYPE>(1);
#pragma omp for
    for(int i=0;i<N;i++) VEC(Y,i)=makeCONST<TYPE>(1);
  }
}


void
call_func( const enum _FUNCS func, const int blk,
           const int N, TYPE * dA, const int LDA,
           TYPE * dB, const int incB,
           TYPE * dC, const int incC,
           const TYPE alpha, const TYPE beta )
{
  switch (func) {

#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128 | TYPE_BF16
  case SYMV_U:
    ASPEN_SYMVu (blk, N, dA, LDA, dB, incB, dC, incC, alpha, beta);
    break;

  case SYMV_L:
    ASPEN_SYMVl (blk, N, dA, LDA, dB, incB, dC, incC, alpha, beta);
    break;
#endif

#if TYPE_DD_COMPLEX || TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
  case HEMV_U:
    ASPEN_HEMVu (blk, N, dA, LDA, dB, incB, dC, incC, alpha, beta);
    break;

  case HEMV_L:
    ASPEN_HEMVl (blk, N, dA, LDA, dB, incB, dC, incC, alpha, beta);
    break;
#endif

  }
}

int
main(int argc, char *argv[])
{
  TYPE	alpha, beta;

  TYPE	*A,  *B,  *C;
  TYPE	*dA, *dB, *dC;

  int	N, M, K;
  int	LDA, LDB, LDC;
  int	i;
  int	blk;
  FILE	*fp;
  int	id = get_gpu_id();

  enum _FUNCS func;
  char	*func_name = (char *)"";


  //  CUDA device setup
  CUDA_INVOKE( cudaSetDevice, ( id ) );

  cublasStatus_t stat;
  cublasHandle_t handle;
  stat = cublasCreate( &handle );

  //  CUDA BLAS initialization
  ASPEN_init( id );


  //  function name check
  {
    char *argv0 = argv[0];
    if ( strrchr(argv0, '/') != argv0 ) {
      argv0 = strrchr(argv0,'/')+1;
    }
#if TYPE_DD || TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128 || TYPE_BF16
    if ( 0 == strcmp(argv0,TEST2_SYMV_U) ) {
      func      = SYMV_U;
      func_name = (char *)NAME_SYMV_U;
    }
    if ( 0 == strcmp(argv0,TEST2_SYMV_L) ) {
      func      = SYMV_L;
      func_name = (char *)NAME_SYMV_L;
    }
#else
    if ( 0 == strcmp(argv0,TEST2_HEMV_U) ) {
      func      = HEMV_U;
      func_name = (char *)NAME_HEMV_U;
    }
    if ( 0 == strcmp(argv0,TEST2_HEMV_L) ) {
      func      = HEMV_L;
      func_name = (char *)NAME_HEMV_L;
    }
#endif
  }


  // arg list check
  if ( argc > 1 ) {
    fp=fopen(argv[1], "r");
  } else {
    fp=fopen("IN", "r");
  }
  if ( fp == NULL ) {
    fprintf(stderr,"Cannot open parameter file.\n");
    ASPEN_shutdown();
    exit(1);
  } else {
    // dummy
    fscanf(fp,"%d", &N);
  }
  if ( argc > 2 ) {
    sscanf(argv[2], "%d", &blk);
    printf("%% BLK specified=%d\n", blk);
  } else {
    blk = -1; //64;
  }


  // clock detection
  system( "nvidia-smi -q -d CLOCK | awk '/^[ \t]*(Max .*)?Clock/{ print \"#\"$0 }/MHz/{ print \"#\"$0 }/Customer/{ getline; print \"#\"$0; exit }'" );
  fflush(stdout);

  // print header
  print_head( func_name, argc, argv );
  fflush(stdout);


  // Determining the maximum size of arrays
  int N_fault=0;
  int N_max = get_Max_N( sizeof(TYPE) );
  printf("Nmax=%d\n", N_max);
  int siz = 256/sizeof(TYPE);


  // setting scalar parameters
  alpha =  makeCONST<TYPE>(3);
#if !__isHALF__ && !__isHALF_COMPLEX__
  alpha += makeCONST<TYPE>(3*EPS);
#endif
  beta  =  makeCONST<TYPE>(4);
#if !__isHALF__ && !__isHALF_COMPLEX__
  beta  += makeCONST<TYPE>(4*EPS);
#endif
  int overflow = 0;

  for(int Itr = 0; fscanf(fp,"%d", &N) > 0; Itr++ ) {

    double tmax0 = 1e+100; 

    if ( N < 0 ) break;
    if ( N > N_max ) { N = N_max; if ( overflow++ ) continue; }

    if ( N == 0 ) {

      dA = dB = dC = NULL;
      size_t len = ((size_t)sizeof(TYPE)*1)*1;
      CUDA_INVOKE( cudaMalloc, ( (void**)&dA, len ) );
      CUDA_INVOKE( cudaMemset, ( dA, 0, len ) );
      CUDA_INVOKE( cudaMalloc, ( (void**)&dB, len ) );
      CUDA_INVOKE( cudaMemset, ( dB, 0, len ) );
      CUDA_INVOKE( cudaMalloc, ( (void**)&dC, len ) );
      CUDA_INVOKE( cudaMemset, ( dC, 0, len ) );

      // cold startup and displaying a header
      call_func( func, blk, 0, dA, 1, dB, 1, dC, 1, alpha, beta);
      call_func( func, blk, 1, dA, 1, dB, 1, dC, 1, alpha, beta);

      CUDA_INVOKE( cudaFree, (dA) );
      CUDA_INVOKE( cudaFree, (dB) );
      CUDA_INVOKE( cudaFree, (dC) );

      continue;

    }


    size_t len;
    //LDA = N;
    LDA = ((N-1)/siz+1)*siz;


    // Allocating the host data
    len = ((size_t)sizeof(TYPE)*N)*LDA;
    A = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    B = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    C = (TYPE *)malloc( len );


    // Allocating the device data
    len = ((size_t)sizeof(TYPE)*N)*LDA; dA = NULL;
    CUDA_INVOKE( cudaMalloc, ( (void**)&dA, len ) );
    len = ((size_t)sizeof(TYPE)*N); dB = NULL;
    CUDA_INVOKE( cudaMalloc, ( (void**)&dB, len ) );
    len = ((size_t)sizeof(TYPE)*N); dC = NULL;
    CUDA_INVOKE( cudaMalloc, ( (void**)&dC, len ) );

    if(dA==NULL||dB==NULL||dC==NULL) {
      fprintf(stderr, "# Fail to allocate Dev_array %dx%d, %d*4\n",
              N, LDA, N);
      fprintf(stderr, "# Fail to allocate memory %lx %lx %lx \n",
              (unsigned long)dA, (unsigned long)dB, (unsigned long)dC);
      if(dA!=NULL) CUDA_INVOKE( cudaFree, (dA) );
      if(dB!=NULL) CUDA_INVOKE( cudaFree, (dB) );
      if(dC!=NULL) CUDA_INVOKE( cudaFree, (dC) );
      N_fault++;
      goto FFF;
    } else {
      N_fault=0;
    }


    printf("N= %8d  ", N);
    fflush(stdout);
    fflush(stdout);
    fflush(stdout);


    set_matrix_vectors( N, A, LDA, B, C, func );

    len = ((size_t)sizeof(TYPE)*N)*LDA;
    CUDA_INVOKE( cudaMemcpy, ( dA, A, len, cudaMemcpyHostToDevice ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMemcpy, ( dB, B, len, cudaMemcpyHostToDevice ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMemcpy, ( dC, C, len, cudaMemcpyHostToDevice ) );

    fflush(stdout);

    for (int local_itr=0; local_itr<LOCAL_ITR_MAX; local_itr++ ) {

      cudaDeviceSynchronize();

      double tt[ITER];
      for(int i=0;i<ITER;i++){

        len = ((size_t)sizeof(TYPE)*N);
        CUDA_INVOKE( cudaMemcpy, ( dC, C, len, cudaMemcpyHostToDevice ) );
        cudaDeviceSynchronize();
#if 0
	ASPEN_max_freq();
        WarmUp_GPU( id );
	ASPEN_max_freq();
        cudaDeviceSynchronize();
#endif

        double tt1 = get_wtime();

        int	incb = 1;
        int	incc = 1;
        char	*opt = (char *)"U";

        call_func (func, blk, N, dA, LDA, dB, 1, dC, 1, alpha, beta);

        cudaDeviceSynchronize();

        double tt2 = get_wtime();
        tt[i] = tt2 - tt1;

      } fflush(stdout);


      for(int i=0;i<ITER;i++) 
        for(int j=i+1;j<ITER;j++)
          if(tt[i]>tt[j]){ double s=tt[i]; tt[i]=tt[j]; tt[j]=s; }

      // stats
      double	tmax=tt[ITER-1];
      double	t = tt[(ITER-1)/2];
      double	tvar=0.0;
      for(int i=0;i<ITER;i++) tvar+=(tt[i]-t)*(tt[i]-t);
      tvar-=(tmax-t)*(tmax-t);
      tvar=sqrt(tvar)/(ITER-1);

      if ( local_itr+1<LOCAL_ITR_MAX ) {
        if ( tmax > tmax0*1.05 ) continue;
        tmax0 = fmin(tmax0, tmax);
        if ( tvar/t > 2E-2 ) continue;
      }

      fflush(stdout);

      printf("%e [s]  ", t);
#if TYPE_DOUBLE || TYPE_FLOAT || TYPE_HALF || TYPE_BF16
      printf("%e [GFLOPS]  ", ((2.0*N)*N/t*1e-9));
#endif
#if TYPE_DD 
      printf("%e [GDDFLOPS]  ", ((2.0*N)*N/t*1e-9));
#endif
#if TYPE_INT16 || TYPE_INT32 || TYPE_INT64 || TYPE_INT128
      printf("%e [GOPS]  ", ((2.0*N)*N/t*1e-9));
#endif
#if TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX || TYPE_HALF_COMPLEX
      printf("%e [GFLOPS]  ", (4*(2.0*N)*N/t*1e-9));
#endif
#if TYPE_DD_COMPLEX
      printf("%e [GDDFLOPS]  ", (4*(2.0*N)*N/t*1e-9));
#endif
      printf("%e ", tvar);
      printf("%8d ", LDA);

      fflush(stdout); break;
    }


  GGG: fflush(stdout);

    CUDA_INVOKE( cudaFree, (dA) );
    CUDA_INVOKE( cudaFree, (dB) );
    CUDA_INVOKE( cudaFree, (dC) );

  FFF: fflush(stdout);

    free(A); //printf(":A");
    free(B); //printf(":B");
    free(C); //printf(":C");

    printf("\n");
    fflush(stdout);
    fflush(stdout);

    if ( N_fault > 0 ) break;
    if ( feof(fp) ) break;
  }

  cublasDestroy( handle );
  ASPEN_shutdown();
 HHH:
  cudaDeviceReset();
  fclose(fp);
 FIN:
  return 0;

}

