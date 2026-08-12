void __threadfence();
#include "aspen_devel.h"
#include "aspen_version.h"

class ASPEN_GPU_info
{
  //
private:
  int     device_ID;
  cudaStream_t	stream;
  cudaStream_t	stream_default;
  int     numbers_MPs;
  char *  device_Name;
  int     device_Major;
  int     device_Minor;
  int     driver_Version;
  int     runtime_Version;
  size_t  global_memory;
  size_t  lwork;
  void *  work;
  int     aspen_version;
  char    aspen_codename[32];
  char    aspen_release_date[32];
  //
#if 0
  nvmlDevice_t device;
  unsigned int max_freq_graph;
  unsigned int max_freq_mem;
#endif
  //
#if CHECK_TUNED_GPUID
#include "get_tuned_gpuid.h"
#endif

public:
  virtual
  ~ASPEN_GPU_info ( void )
  {
    cudaFree( work );
    free ( device_Name );
    cudaStreamDestroy( stream_default );
  } // destructor

  _____ int64_t const_ZERO[4];

  ASPEN_GPU_info ( const int  device_id )
  {
    cudaError_t error;
#if CHECK_TUNED_GPUID
    int t_dev = API(get_tuned_gpuid)();
    if ( device_id != t_dev ) {
      fprintf( stderr, "Not matched with the tuned gpuid.\n" );
      fflush ( stderr );
      exit(1);
    }
#endif
    device_ID = device_id;

    int p_dev; cudaGetDevice( &p_dev );
    if ( device_id != p_dev ) {
      error = cudaSetDevice( device_id );
      if ( error != cudaSuccess ) {
        exit(1);
      }
    }

#if 0
    {
      nvmlReturn_t error;
      error = nvmlInit();
      nvmlDeviceGetHandleByIndex( 0, &device );
      if ( error != NVML_SUCCESS ) {
        exit(1);
      }
      error = nvmlDeviceGetMaxClockInfo ( device, NVML_CLOCK_GRAPHICS, &max_freq_graph );
      error = nvmlDeviceGetMaxClockInfo ( device, NVML_CLOCK_MEM, &max_freq_mem );
    }
#endif

    error = cudaStreamCreate( &stream_default );
    if ( error != cudaSuccess ) {
      exit(1);
    }
    stream = NULL;

    struct cudaDeviceProp deviceProp;
    error = cudaGetDeviceProperties ( &deviceProp, device_id );
    if ( error != cudaSuccess ) {
      exit(1);
    }

    numbers_MPs  = deviceProp.multiProcessorCount;
    int len = strlen ( deviceProp.name );
    // trick to adjust older CUDA SDK's and 11.5
    if ( strncmp( "NVIDIA ", deviceProp.name, 7 ) == 0 ) {
      device_Name = (char *) malloc ( len-7 + 1 );
      strcpy( device_Name, deviceProp.name+7 );
    } else {
      device_Name = (char *) malloc ( len + 1 );
      strcpy( device_Name, deviceProp.name );
    }
    device_Major = deviceProp.major;
    device_Minor = deviceProp.minor;

    cudaDriverGetVersion( &driver_Version );
    cudaRuntimeGetVersion( &runtime_Version );

    global_memory = deviceProp.totalGlobalMem;

    {
      // lwork*lwork+4*lwork < global_memory
      // (lwork+2)^2 < global_memory + 4
      // (lwork+2)^2/4 < global_memory/4 + 1
      // (lwork+2)/2 < sqrt(global_memory/4 + 1)
      //  lwork < 2*(sqrt(global_memory/4 + 1) - 1)
      size_t num_pages = (global_memory/4096)*4096;
      lwork = 0;
      for(int sizet=1; sizet<=4*sizeof(double); sizet*=2) {
        size_t L = num_pages/sizet;
        size_t opt_L = (size_t)sqrt((double)L/4+1)-1;
        size_t ll = std::max((size_t)1,(size_t)(2*opt_L*0.98));
        ll = (ll/128)*128;
	lwork = std::max(ll, lwork);
      }
      size_t const lll = (size_t)std::max(numbers_MPs/5,20);
//      size_t const lll = (size_t)32;
      lwork = lwork*lll;
      error = cudaMalloc( (void **)&work, lwork );
    }

    if ( device_id != p_dev ) cudaSetDevice( p_dev );

    aspen_version = ASPEN_MAJOR_VERSION*1000000
      + ASPEN_MINOR_VERSION*1000
      + ASPEN_PATCH_LEVEL;
    strcpy( aspen_codename, ASPEN_CODENAME );
    strcpy( aspen_release_date, ASPEN_RELEASE_DATE );

    memset( const_ZERO, 0, sizeof(int64_t)*4 );

  } // constructor

  // query methods
  int get_device_ID ( void )
  {
    return device_ID;
  }

  cudaStream_t get_Stream ( void )
  {
    return stream != NULL ? stream : stream_default;
  }

  void set_Stream ( cudaStream_t st )
  {
    stream = st;
  }

  int get_numbers_MP ( void )
  {
    return numbers_MPs;
  }

  void get_device_Name ( char *name )
  {
    strcpy(name, device_Name);
  }

  int get_device_Major ( void )
  {
    return device_Major;
  }

  int get_device_Minor ( void )
  {
    return device_Minor;
  }

  int get_driver_Version ( void )
  {
    return driver_Version;
  }

  int get_runtime_Version ( void )
  {
    return runtime_Version;
  }

  size_t get_device_Memory ( void )
  {
    return global_memory;
  }

  size_t get_device_WorkSize ( void )
  {
    return lwork;
  }

  void * get_device_WorkArea ( void )
  {
    return work;
  }

  void get_version_info ( int *version, char *codename, char *releasedate )
  {
    *version = aspen_version;
    strcpy( codename,    aspen_codename );
    strcpy( releasedate, aspen_release_date );
  }

#if 0
  void max_freq ( void )
  {
    int min_freq_mem = (int)(max_freq_mem * .8);
    nvmlDeviceSetMemoryLockedClocks ( device, min_freq_mem, max_freq_mem );
    nvmlDeviceSetApplicationsClocks ( device, max_freq_mem, max_freq_graph );
    nvmlDeviceSetAutoBoostedClocksEnabled ( device, NVML_FEATURE_DISABLED );
  }
#endif

};


static ASPEN_GPU_info * GPU = NULL;

extern "C" {

  int API(init) ( int device_id )
  {
    if ( GPU != NULL ) {
      fprintf( stderr, "ASPEN was already initialized.\n" );
      fprintf( stderr, "You might forgot to shutdown.\n" );
      fflush ( stderr );
      return 1;
    }
    GPU = new ASPEN_GPU_info( device_id );
    return 0;
  }

#if 0
#define	check_GPU( ... )						\
  _MACRO_WRAP_ (							\
		if ( GPU == NULL ) {					\
                  perror( "not Initialized" ); exit(1); };              \
                                                                        )
#else
#define	check_GPU( ... )	/* */
#endif

  int API(shutdown) ( void )
  {
    check_GPU( );
    if ( GPU ) {
      delete GPU;
      GPU = NULL;
    }
    return 0;
  }

  int API(get_device_ID) ( void )
  {
    check_GPU( );
    return GPU->get_device_ID ( );
  }

  cudaStream_t API(get_Stream) ( void )
  {
    check_GPU( );
    return GPU->get_Stream ( );
  }

  void API(set_Stream) ( cudaStream_t st )
  {
    check_GPU( );
    GPU->set_Stream ( st );
  }

  int API(get_numbers_MP) ( void )
  {
    check_GPU( );
    return GPU->get_numbers_MP ( );
  }

  void API(get_device_Name) ( char * name )
  {
    check_GPU( );
    GPU->get_device_Name ( name );
  }

  int API(get_device_Major) ( void )
  {
    check_GPU( );
    return GPU->get_device_Major ( );
  }

  int API(get_device_Minor) ( void )
  {
    check_GPU( );
    return GPU->get_device_Minor ( );
  }

  int API(get_device_CC) ( void )
  {
    check_GPU( );
    return (GPU->get_device_Minor ( ) + GPU->get_device_Major ( ) * 10) * 10;
  }

  int API(get_driver_Version) ( void )
  {
    check_GPU( );
    return GPU->get_driver_Version ( );
  }

  int API(get_runtime_Version) ( void )
  {
    check_GPU( );
    return GPU->get_runtime_Version ( );
  }

  size_t API(get_device_Memory) ( void )
  {
    check_GPU( );
    return GPU->get_device_Memory ( );
  }

  size_t API(get_device_WorkSize) ( void )
  {
    check_GPU( );
    return GPU->get_device_WorkSize ( );
  }

  void * API(get_device_WorkArea) ( void )
  {
    check_GPU( );
    return GPU->get_device_WorkArea ( );
  }

  void API(get_version_info) ( int *version, char *codename, char *releasedate )
  {
    check_GPU( );
    GPU->get_version_info ( version, codename, releasedate );
  }

  void * API(const_ZERO) ( void )
  {
    check_GPU( );
    return (void *)GPU->const_ZERO;
  }

#if 0
  void API(max_freq) ( void )
  {
    check_GPU( );
    GPU->max_freq ();
  }
#endif

}

