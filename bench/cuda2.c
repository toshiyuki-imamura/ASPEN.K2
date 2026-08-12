#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>


#define	ITER	6

#include "test-common.h"
#include "cuda.h"

extern "C" void WarmUp_GPU( const int id );


void
set_matrix( enum _FUNCS func,
            int N, TYPE *A, int LDA, TYPE *B, TYPE *C )
{

#pragma omp parallel
  {
#pragma omp for
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        MAT(A,j,i,LDA)=CONST(0);
      }
    }
#pragma omp for
    for(int i=0;i<N*1;i++) VEC(B,i)=CONST(1);
#pragma omp for
    for(int i=0;i<N*1;i++) VEC(C,i)=CONST(0);
  }

}


int
main( int argc, char *argv[] )
{
  TYPE	alpha = CONST(3.0);
  TYPE	beta  = CONST(0.0);//4.0;
  TYPE	*A, *B, *C;
  TYPE	*dA, *dB, *dC;
  int	N, M, K;
  int	LDA, LDB, LDC;
  int	i;
  char	mode;
  int	blk;
  FILE	*fp;
  int	id = get_gpu_id();

  enum _FUNCS func;
  char	*func_name = (char *)"";

  cublasHandle_t handle;


  cudaSetDevice( id );


  cublasCreate( &handle );
  if ( argc > 2 ) {
    int mode;
    sscanf(argv[2], "%d", &mode);
    if ( mode ) {
      cublasAtomicsMode_t atomic_mode = CUBLAS_ATOMICS_ALLOWED;
      cublasSetAtomicsMode( handle, atomic_mode );
    }
  }

  {
    char *argv0 = argv[0];
    if ( strrchr(argv0, '/') != argv0 ) {
      argv0 = strrchr(argv0,'/')+1;
    }
#if TYPE_DOUBLE || TYPE_FLOAT
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
    exit(1);
  }

  fscanf(fp,"%d", &N);
  if ( N == 0 ) {
    mode = 'U';
  } else {
    mode= 'U';
  }

#if 0
  if ( argc > 2 ) {
    sscanf(argv[2], "%d", &blk);
    printf("%% BLK specified=%d\n", blk);
  } else {
    blk = -1; //64;
  }
#endif

  print_head( func_name, argc, argv );

  int N_fault=0;
  int N_max = get_Max_N( sizeof(TYPE) );
  printf("Nmax=%d\n", N_max);
  int overflow = 0;

  while (1) {

    fscanf(fp,"%d", &N);
    if ( N <= 1 ) break;
    if ( N > N_max ) { N = N_max; if ( overflow++ ) continue; }

    int     LDM = ((N-1)/(256/sizeof(TYPE))+1);
    LDM *= (256/sizeof(TYPE));
    LDA = ((N-1)/(256/sizeof(TYPE))+1);
    LDA *= (256/sizeof(TYPE));

    size_t len;
    len = ((size_t)sizeof(TYPE)*N)*LDM;
    A = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    B = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    C = (TYPE *)malloc( len );

    len = ((size_t)sizeof(TYPE)*N)*LDM;
    CUDA_INVOKE( cudaMalloc, ( (void**)&dA, len ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMalloc, ( (void**)&dB, len ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMalloc, ( (void**)&dC, len ) );

    if(dA==NULL||dB==NULL||dC==NULL) {
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

    set_matrix( func, N, A, LDA, B, C );
    len = ((size_t)sizeof(TYPE)*N)*LDM;
    CUDA_INVOKE( cudaMemcpy, ( dA, A, len, cudaMemcpyHostToDevice ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMemcpy, ( dB, B, len, cudaMemcpyHostToDevice ) );
    len = ((size_t)sizeof(TYPE)*N);
    CUDA_INVOKE( cudaMemcpy, ( dC, C, len, cudaMemcpyHostToDevice ) );

    while ( 1 ) {

      cudaDeviceSynchronize();

      double	tt[ITER];
      for(int i=0;i<ITER;i++){

        len = ((size_t)sizeof(TYPE)*N);
        CUDA_INVOKE( cudaMemcpy, ( dC, C, len, cudaMemcpyHostToDevice ) );
        cudaDeviceSynchronize();
#if 0
        WarmUp_GPU( id );
        cudaDeviceSynchronize();
#endif

        double	tt1 = get_wtime();

        int	incb = 1;
        int	incc = 1;
        char	*opt = (char *)"U";

        switch (func) {
#if TYPE_DOUBLE || TYPE_FLOAT
        case SYMV_U:
          cublassymv
            ( handle, CUBLAS_FILL_MODE_UPPER, N, &alpha, dA, LDA, dB, 1, &beta, dC, 1);
          break;
        case SYMV_L:
          cublassymv
            ( handle, CUBLAS_FILL_MODE_LOWER, N, &alpha, dA, LDA, dB, 1, &beta, dC, 1);
          break;
#else
        case HEMV_U:
          cublashemv
            ( handle, CUBLAS_FILL_MODE_UPPER, N, &alpha, dA, LDA, dB, 1, &beta, dC, 1);
          break;
        case HEMV_L:
          cublashemv
            ( handle, CUBLAS_FILL_MODE_LOWER, N, &alpha, dA, LDA, dB, 1, &beta, dC, 1);
          break;
#endif
        }

        cudaDeviceSynchronize();
        double	tt2 = get_wtime();
        tt[i]=tt2-tt1;

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
      if ( tvar/t > 2E-2 ) continue;

      fflush(stdout);

      printf("%e [s]  ", t);
#if TYPE_DOUBLE || TYPE_FLOAT
      printf("%e [GFLOPS]  ", ((2.0*N)*N/t*1e-9));
#else
      printf("%e [GFLOPS]  ", (4*(2.0*N)*N/t*1e-9));
#endif
      printf("%e ", tvar);
      printf("%8d ", LDA);

      fflush(stdout); break;
    }


  GGG: fflush(stdout);
    CUDA_INVOKE( cudaFree, (dA) ); //printf(":dA");
    CUDA_INVOKE( cudaFree, (dB) ); //printf(":dB");
    CUDA_INVOKE( cudaFree, (dC) ); //printf(":dC");


  FFF: fflush(stdout);
    free(A); //printf(":A");
    free(B); //printf(":B");
    free(C); //printf(":C");


  HHH: fflush(stdout);
    printf("\n");

    if ( N_fault > 0 ) break;
    if ( feof(fp) ) break;
  }
  fflush(stdout);


  cublasDestroy( handle );
  fclose(fp);
}

