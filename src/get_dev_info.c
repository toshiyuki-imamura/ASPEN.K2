#include <sys/sysinfo.h>
void __threadfence(void);
#include "aspen_devel.h"

int print_dev_info ( const char *device_name,
                     const int MPs, const int CG,
                     const size_t MMEM, const size_t WORK,
		     const size_t MAXDIM[] );

int
main( int argc, char *argv[] )
{
  int	id = 0;
  if ( argc > 1 ) {
    sscanf( argv[1], "%d", &id );
  } else {
    char *id_str = getenv("ASPEN_GPU_ID");
    if ( id_str ) {
      sscanf( id_str, "%d", &id );
    }
  }

  cudaError_t err = cudaSetDevice( id );
  if ( err != cudaSuccess ) {
    size_t	MAXDIM[4] = { 0, 0, 0, 0};
    perror("CUDA device open FAILED");
    print_dev_info ( "unknown", (int)0, (int)0, (size_t)0, (size_t)0, &MAXDIM[0] );
    return EXIT_FAILURE;
  }

  ASPEN_init   ( id );

  char	device_name[1024]; ASPEN_get_device_Name( device_name );
  int	MPs     = ASPEN_get_numbers_MP( );
  int	CG      = ASPEN_get_device_CC( );
  size_t	MMEM    = ASPEN_get_device_Memory( );
  size_t	MAXDIM[10];
  size_t	WORK    = ASPEN_get_device_WorkSize( );
  MMEM -= WORK;

  {
    char *s = device_name;
    while ( (s = strchr( s, ' ' )) != NULL ) { *s = '-'; }
  }

  struct sysinfo info;
  sysinfo( & info );

  if ( info.totalram < MMEM ) {
    MMEM = info.totalram;
  }
  MMEM /= 4096;
  MMEM *= 4096;

  MAXDIM[0] = MMEM / (sizeof(double));
  MAXDIM[0] = (size_t)(sqrt((double)MAXDIM[0])*0.95);

  MAXDIM[1] = MMEM / (sizeof(float));
  MAXDIM[1] = (size_t)(sqrt((double)MAXDIM[1])*0.95);

  MAXDIM[2] = MMEM / (sizeof(double)*2);
  MAXDIM[2] = (size_t)(sqrt((double)MAXDIM[2])*0.95);

  MAXDIM[3] = MMEM / (sizeof(double)*4);
  MAXDIM[3] = (size_t)(sqrt((double)MAXDIM[3])*0.95);

  MAXDIM[4] = MMEM / (sizeof(unsigned short));
  MAXDIM[4] = (size_t)(sqrt((double)MAXDIM[4])*0.95);

  print_dev_info ( device_name, MPs, CG, MMEM, WORK, MAXDIM );

  printf( "// cuda version\n" );
  printf( "CUDA= %d\n",  ASPEN_get_runtime_Version() );

  printf( "// ASPEN.K2 version\n" );
  printf( "ASPEN_K2= %d.%d",  ASPEN_MAJOR_VERSION, ASPEN_MINOR_VERSION );
  if ( ASPEN_PATCH_LEVEL > 0 ) printf( "p%d",  ASPEN_PATCH_LEVEL );
  printf( " %s\n", ASPEN_CODENAME );

  return EXIT_SUCCESS;
}

int
print_dev_info ( const char *device_name,
                 const int MPs, const int CG,
		 const size_t MMEM, const size_t WORK,
		 const size_t MAXDIM[] )
{
  printf( "// device name\n" );
  printf( "DEVICE= %s\n"   , device_name );
  printf( "// the number of multi-processors\n" );
  printf( "MP= %d\n"       , MPs         );
  printf( "// compute-compatibility generation\n" );
  printf( "CG= %d\n"       , CG          );
  printf( "// capacity of the global memory or host memory\n" );
  printf( "MAXmem= %ld\n"  , MMEM        );
  printf( "// capacity of the work area reserved on the GPU\n" );
  printf( "WORK= %ld\n"    , WORK        );
  printf( "// for double or cuFloatComplex or int64\n" );
  printf( "MAXDIM= %ld\n"  , MAXDIM[0]   );
  printf( "// for float or cuHalfComplex or int32\n" );
  printf( "MAXDIM2= %ld\n" , MAXDIM[1]   );
  printf( "// for cuDoubleComplex or DD or int128\n" );
  printf( "MAXDIM3= %ld\n" , MAXDIM[2]   );
  printf( "// for DD-Complex\n" );
  printf( "MAXDIM4= %ld\n" , MAXDIM[3]   );
  printf( "// for half or int16\n" );
  printf( "MAXDIM5= %ld\n" , MAXDIM[4]   );

  return EXIT_SUCCESS;
}

