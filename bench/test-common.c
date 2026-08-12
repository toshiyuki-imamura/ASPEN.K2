#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

#include <cuda_runtime.h>
#include <cuda.h>
#if CUDA_VERSION<5000
#   include <cutil.h>
#endif
#include <cublas.h>

#include <time.h>
#include <sys/time.h>

//#include "test-common.h"


extern "C" {

  int
  get_gpu_id( void )
  {
    char    *id_str = getenv("ASPEN_GPU_ID");
    int     id = (id_str==NULL)?(0):(atoi(id_str));
    return	id;
  }

  void
  print_head( char *func_name, int argc, char **argv )
  {
    char	t[1024];
    struct cudaDeviceProp deviceProp;
    int  id = get_gpu_id();
    cudaGetDeviceProperties ( &deviceProp, id );
    int driver_Version;
    cudaDriverGetVersion( &driver_Version );
    int runtime_Version;
    cudaRuntimeGetVersion( &runtime_Version );

    printf("<!--/****************************************\n");
    printf("Evaluating the performance on %s\n", func_name);
    {
      printf("\n %% ");
      for(int i=0;i<argc;i++) { printf("%s ",argv[i]); }
      printf("\n\n");
    }
    printf("Date : ");
    fflush(stdout);
    system("date");
    fflush(stdout);
    printf("Host : ");
    fflush(stdout);
    system("hostname");
    fflush(stdout);
    printf("Device Name : %s\n", deviceProp.name);
    fflush(stdout);
    printf("CUDA Driver : %d.%d\n",
           (driver_Version/1000),
           (driver_Version%100)/10);
    system("head -1 /proc/driver/nvidia/version");
    fflush(stdout);
    printf("Runtime Driver : %d.%d\n",
           (runtime_Version/1000),
           (runtime_Version%100)/10);
    fflush(stdout);
    if ( runtime_Version > driver_Version ) {
      printf("******** CAUTION ********\n");
      printf("The installed video-driver is too old for the runtime.\n");
      fflush(stdout);
    }
    printf("*****************************************/-->\n");
    fflush(stdout);
  }

  double
  get_wtime(void)
  {
    struct timespec ts;
    clock_gettime( CLOCK_REALTIME, &ts );
    return (ts.tv_sec+ts.tv_nsec*1e-9);
  }

  void
  do_usleep(int usec)
  {
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = (long)usec;
    ts.tv_nsec *= 1000;
    nanosleep( &ts, NULL );
  }

  size_t
  get_device_WorkSize( int dev, int size )
  {
    size_t  free_mem, total_mem;
    cudaMemGetInfo( &free_mem, &total_mem );

    const size_t  Lwork = free_mem/size;
    const size_t  Lblk  = 256/size;
    size_t  ldm   = 0;
    size_t  lwork = 0;

    lwork = (size_t)(sqrt((double)Lwork)*0.95);
#if 0
    while ( 1 ) {
      ldm = ((lwork-1)/Lblk+1) * Lblk;
      const size_t swork = (lwork + 3) * ldm;
      if ( swork <= Lwork ) break;
      lwork --;
    }

    ldm = (ldm/Lblk)*Lblk;
    return ( ldm );
#else
    return ( lwork );
#endif
  }

  void Check_GPU_status( char * message )
  {
    size_t  free_mem, total_mem;
    cudaError_t err;
    err = cudaMemGetInfo( &free_mem, &total_mem );
    if ( err != cudaSuccess ) {
      printf("%s / mem_info error %ld %ld %s\n",
             message, free_mem, total_mem, cudaGetErrorString(err) );
    }
  }

  int get_Max_N( size_t sizeof_T )
  {
    size_t free_mem, total_mem;
    cudaMemGetInfo( &free_mem, &total_mem );

    size_t MMEM = total_mem; // free_mem;
    MMEM /= 4096;
    MMEM *= 4096;
    MMEM /= sizeof_T;
    size_t N;
    N = (size_t)sqrt((double)MMEM/4+1)-1;
    N = (size_t)(2*N*0.98);
    N /= 128;
    N *= 128;
    if ( N < 1 ) N = 1;

    return (int)N;
  }

}

