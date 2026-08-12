#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <magma.h>

#define	ITER	6

#include "test-common.h"
#include "magma.h"


void
set_matrix( enum _FUNCS func,
            int N, TYPE *A, int LDA, TYPE *B, TYPE *C )
{
#pragma omp parallel for
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      MAT(A,j,i,LDA)=CONST(0);
    }
  }
#pragma omp parallel for
  for(int i=0;i<N*1;i++) VEC(B,i)=CONST(1);
#pragma omp parallel for
  for(int i=0;i<N*1;i++) VEC(C,i)=CONST(0);
}


int
main(int argc, char *argv[])
{
  TYPE	alpha = CONST(3.0);
  TYPE	beta  = CONST(0.0);//4.0;
  TYPE	*A, *B, *C;
  TYPE	*dA, *dB, *dC, *dW;
  int	N, M, K;
  int	LDA, LDB, LDC;
  int	i;
  char	mode;
  int	blk;
  FILE	*fp;
  int	id = get_gpu_id();


  enum _FUNCS func;
  char	*func_name = (char *)"";

  magma_init( );
  cudaSetDevice( id );

  cublasStatus_t stat;
  cublasHandle_t handle;
  cublasAtomicsMode_t atomic_mode = CUBLAS_ATOMICS_ALLOWED;
  stat = cublasCreate( &handle );
  cublasSetAtomicsMode( handle, atomic_mode );







  {
    char *argv0 = argv[0];
    if ( strrchr(argv0, '/') != argv0 ) {
      argv0 = strrchr(argv0,'/')+1;
    }
#if TYPE_DOUBLE || TYPE_FLOAT
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
  int N_max = get_device_WorkSize( id, sizeof(TYPE) );

  while (1) {

    fscanf(fp,"%d", &N);
    if ( N <= 1 ) break;
    if ( N > N_max ) continue;


    int     M = N;
#if 1
    if ( argc <= 3 )
      //if ( 0 )
      {
        if ( sizeof(TYPE) == 4 ) {
          if ( M < 12600 ) M = 12600;
        }
        if ( sizeof(TYPE) == 8 ) {
          if ( M < 9000 ) M = 9000;
        }
        if ( sizeof(TYPE) == 16 ) {
          if ( M < 6300 ) M = 6300;
        }
        if ( sizeof(TYPE) == 32 ) {
          if ( M < 4500 ) M = 4500;
        }
      }
#endif


    int     LDM = ((M-1)/(256/sizeof(TYPE))+1);
    LDM *= (256/sizeof(TYPE));
    LDA = ((N-1)/(256/sizeof(TYPE))+1);
    LDA *= (256/sizeof(TYPE));

    size_t len;
    len = ((size_t)sizeof(TYPE)*M)*LDM;
    A = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    B = (TYPE *)malloc( len );
    len = ((size_t)sizeof(TYPE)*N);
    C = (TYPE *)malloc( len );

    cublasAlloc( M*LDM, sizeof(TYPE), (void**)&dA );
    cublasAlloc( N*1,   sizeof(TYPE), (void**)&dB );
    cublasAlloc( N*1,   sizeof(TYPE), (void**)&dC );

    int ldwork = LDM*((N+64-1)/64);
    cublasAlloc(ldwork, sizeof(TYPE), (void**)&dW);

    if(dA==NULL||dB==NULL||dC==NULL) {
      fprintf(stderr, "# Fail to allocate memory %lx %lx %lx \n",
              (unsigned long)dA, (unsigned long)dB, (unsigned long)dC);
      if(dA!=NULL) cublasFree(dA);
      if(dB!=NULL) cublasFree(dB);
      if(dC!=NULL) cublasFree(dC);
      N_fault++;
      goto FFF;
    } else {
      N_fault=0;
    }



    printf("N= %d ", N);
    fflush(stdout);

    set_matrix( func, N, A, LDA, B, C );
    cublasSetMatrix(LDM, M, sizeof(TYPE), A, LDM, dA, LDM);
    cublasSetVector(N, sizeof(TYPE), B, 1, dB, 1);
    cublasSetVector(N, sizeof(TYPE), C, 1, dC, 1);
    cudaDeviceSynchronize();



    double	tt[1000];
    for(i=0;i<ITER;i++){

      cudaDeviceSynchronize();
      double	tt1 = get_wtime();

      int	incb = 1;
      int	incc = 1;
      char	*opt = (char *)"U";

      switch (func) {
#if TYPE_DOUBLE || TYPE_FLOAT
      case SYMV_U:
        magmablassymv_work
          ( MagmaUpper, N, alpha, dA, LDA, dB, 1, beta, dC, 1, dW, ldwork, magmablasGetQueue() );
        break;
      case SYMV_L:
        magmablassymv_work
          ( MagmaLower, N, alpha, dA, LDA, dB, 1, beta, dC, 1, dW, ldwork, magmablasGetQueue() );
        break;
#else
      case HEMV_U:
        magmablashemv_work
          ( MagmaUpper, N, alpha, dA, LDA, dB, 1, beta, dC, 1, dW, ldwork, magmablasGetQueue() );
        break;
      case HEMV_L:
        magmablashemv_work
          ( MagmaLower, N, alpha, dA, LDA, dB, 1, beta, dC, 1, dW, ldwork, magmablasGetQueue() );
        break;
#endif
      }

      cudaDeviceSynchronize();
      double	tt2 = get_wtime();
      tt[i]=tt2-tt1;

    }
  EEE: fflush(stdout);


    { // sorting
      for(i=0;i<ITER;i++) 
        for(int j=i+1;j<ITER;j++)
          if(tt[i]>tt[j]){ double s=tt[i]; tt[i]=tt[j]; tt[j]=s; }

      // stats
      double	tmax=tt[ITER-1];
      double	t = tt[(ITER-1)/2];
      double	tvar=0.0;
      for(i=0;i<ITER;i++) tvar+=(tt[i]-t)*(tt[i]-t);
      tvar-=(tmax-t)*(tmax-t);
      tvar=sqrt(tvar)/(ITER-1);

      fflush(stdout);
      printf("%g [s] ", t);
#if TYPE_DOUBLE || TYPE_FLOAT
      printf("%g GFLOPS ", ((2.0*N)*N/t*1e-9));
#else
      printf("%g GFLOPS ", (4*(2.0*N)*N/t*1e-9));
#endif
      printf("%g ", tvar);
      if ( tvar/t > 2E-2 ) {
        printf("**%g**", tvar/t );
      }
      printf("%d ", LDA);
      fflush(stdout);
    }


  GGG: fflush(stdout);
    cublasFree(dA); //printf(":dA");
    cublasFree(dB); //printf(":dB");
    cublasFree(dC); //printf(":dC");
    cublasFree(dW); //printf(":dC");

  FFF: fflush(stdout);
    free(A); //printf(":A");
    free(B); //printf(":B");
    free(C); //printf(":C");

  HHH: fflush(stdout);
    printf("\n");

    if ( N_fault > 4 ) break;
    if ( feof(fp) ) break;
  }
  fflush(stdout);


  cublasDestroy( handle );
  fclose(fp);
}

