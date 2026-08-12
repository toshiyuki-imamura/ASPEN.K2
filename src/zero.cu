#include "../tuning/CURRENT_GPU"
#include "aspen_devel.h"
#include "aspen_types.h"


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__global__ void 
API_private(ZERO_kernel) ( TYPE * x, long const n )
{
  long pos = threadIdx.x + MULTIPLE * BLOCK_SIZE * blockIdx.x;
  x += pos;

  if ( pos+BLOCK_SIZE*MULTIPLE <= n ) {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      x[0] = makeCONST<TYPE> ( 0 );
      if ( MULTIPLE > 1 ) x += BLOCK_SIZE;
    }
  } else {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      if ( pos+BLOCK_SIZE*i < n ) x[0] = makeCONST<TYPE> ( 0 );
      if ( MULTIPLE > 1 ) x += BLOCK_SIZE;
    }
  }
}


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__host__ void
API_private(ZERO_host) ( TYPE * x, int const n )
{
  int t1 = BLOCK_SIZE;
  int tt = MULTIPLE*t1;
  int n_blk = n / tt;
  int n_res = ((n_blk*tt<n)?1:0);
  int g1 = n_blk + n_res;

  int dev = API(get_device_ID)();
  int p_dev; cudaGetDevice( &p_dev );
  if ( dev != p_dev ) cudaSetDevice( dev );

  cudaStream_t stream = API(get_Stream)();

  API_private(ZERO_kernel) < TYPE , BLOCK_SIZE, MULTIPLE >
    <<< g1, t1, 32, stream
    >>> ( x, (long) n );

  if ( dev != p_dev ) cudaSetDevice( p_dev );
}


#define BLOCK_SIZE	(16*12)
#define	MULTIPLE	(2)

extern "C" void
API(HZERO) ( half * x, int const n )
{
  if ( n <= 0 ) return;
#if ASPEN_HALF_ENABLED
  API_private(ZERO_host) < half, BLOCK_SIZE, MULTIPLE > ( x, n );
#endif
}

extern "C" void
API(SZERO) ( float * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < float, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(DZERO) ( double * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < double, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(KZERO) ( cuHalfComplex * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < cuHalfComplex, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(CZERO) ( cuFloatComplex * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < cuFloatComplex, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(ZZERO) ( cuDoubleComplex * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < cuDoubleComplex, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(WZERO) ( cuddreal * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < cuddreal, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(UZERO) ( cuddcomplex * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < cuddcomplex, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(I16ZERO) ( int16 * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < int16, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(I32ZERO) ( int32 * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < int32, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(I64ZERO) ( int64 * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < int64, BLOCK_SIZE, MULTIPLE > ( x, n );
}

extern "C" void
API(I128ZERO) ( int128 * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < int128, BLOCK_SIZE, MULTIPLE > ( x, n );
}

#if 0
extern "C" void
API(BF16ZERO) ( bfloat16 * x, int const n )
{
  if ( n <= 0 ) return;
  API_private(ZERO_host) < bfloat16, BLOCK_SIZE, MULTIPLE > ( x, n );
}
#endif

