#include "../tuning/CURRENT_GPU"
#include "aspen_devel.h"
#include "aspen_types.h"


template < class TYPE >
__forceinline__  __device__ void
swap( TYPE &a, TYPE &b )
{
  TYPE c = a; a = b; b = c;
}

template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__global__ void 
API_private(SWAP_kernel) ( TYPE * y, TYPE * x, const long n, const long incx, const long incy )
{
  const long pos = threadIdx.x + MULTIPLE * BLOCK_SIZE * blockIdx.x;
  x += pos*incx; y += pos*incy;

  if ( pos+BLOCK_SIZE*MULTIPLE <= n ) {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      swap( x[0], y[0] );
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; y += BLOCK_SIZE*incy; }
    }
  } else {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      if ( pos+BLOCK_SIZE*i < n ) { swap( x[0], y[0] ); }
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; y += BLOCK_SIZE*incy; }
    }
  }
}


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__host__ void
API_private(SWAP_host) ( TYPE * y, TYPE * x, const int n, const int incx, const int incy )
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

  API_private(SWAP_kernel) < TYPE , BLOCK_SIZE, MULTIPLE >
    <<< g1, t1, 32, stream
    >>> ( y, x, (long) n, (long) incx, (long) incy );

  if ( dev != p_dev ) cudaSetDevice( p_dev );
}


#define BLOCK_SIZE	(16*12)
#define	MULTIPLE	(2)

extern "C" void
API(hswap) ( const int n, half * x, const int incx, half * y, const int incy )
{
  if ( n <= 0 ) return;
#if ASPEN_HALF_ENABLED
  API_private(SWAP_host) < half, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
#endif
}

extern "C" void
API(sswap) ( const int n, float * x, const int incx, float * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < float, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(dswap) ( const int n, double * x, const int incx, double * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < double, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(zswap) ( const int n, cuDoubleComplex * x, const int incx, cuDoubleComplex * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < cuDoubleComplex, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(cswap) ( const int n, cuFloatComplex * x, const int incx, cuFloatComplex * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < cuFloatComplex, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(wswap) ( const int n, cuddreal * x, const int incx, cuddreal * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < cuddreal, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(uswap) ( const int n, cuddcomplex * x, const int incx, cuddcomplex * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < cuddcomplex, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i16swap) ( const int n, int16 * x, const int incx, int16 * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < int16, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i32swap) ( const int n, int32 * x, const int incx, int32 * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < int32, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i64swap) ( const int n, int64 * x, const int incx, int64 * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < int64, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i128swap) ( const int n, int128 * x, const int incx, int128 * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < int128, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

#if 0
extern "C" void
API(bf16swap) ( const int n, bfloat16 * x, const int incx, bfloat16 * y, const int incy )
{
  if ( n <= 0 ) return;
  API_private(SWAP_host) < bfloat16, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}
#endif

