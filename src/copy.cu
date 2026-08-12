#include "../tuning/CURRENT_GPU"
#include "aspen_devel.h"
#include "aspen_types.h"


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__global__ void 
API_private(COPY_kernel) ( TYPE * y, TYPE const * x, long const n, long const incx, long const incy )
{
  long const pos = threadIdx.x + MULTIPLE * BLOCK_SIZE * blockIdx.x;
  x += pos*incx; y += pos*incy;

  if ( pos+BLOCK_SIZE*MULTIPLE <= n ) {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      y[0] = x[0];
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; y += BLOCK_SIZE*incy; }
    }
  } else {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      if ( pos+BLOCK_SIZE*i < n ) { y[0] = x[0]; }
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; y += BLOCK_SIZE*incy; }
    }
  }
}


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__host__ void
API_private(COPY_host) ( TYPE * y, TYPE const * x, int const n, int const incx,int const incy )
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

  API_private(COPY_kernel) < TYPE , BLOCK_SIZE, MULTIPLE >
    <<< g1, t1, 32, stream
    >>> ( y, x, (long) n, (long) incx, (long) incy );

  if ( dev != p_dev ) cudaSetDevice( p_dev );
}


#define BLOCK_SIZE	(16*12)
#define	MULTIPLE	(2)

extern "C" void
API(hcopy) ( int const n, half const * x, int const incx, half * y,int const incy )
{
  if ( n <= 0 ) return;
#if ASPEN_HALF_ENABLED
  API_private(COPY_host) < half, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
#endif
}

extern "C" void
API(scopy) ( int const n, float const * x, int const incx, float * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < float, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(dcopy) ( int const n, double const * x, int const incx, double * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < double, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(wcopy) ( int const n, cuddreal const * x, int const incx, cuddreal * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < cuddreal, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(ccopy) ( int const n, cuFloatComplex const * x, int const incx, cuFloatComplex * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < cuFloatComplex, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(zcopy) ( int const n, cuDoubleComplex const * x, int const incx, cuDoubleComplex * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < cuDoubleComplex, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(ucopy) ( int const n, cuddcomplex const * x, int const incx, cuddcomplex * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < cuddcomplex, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i16copy) ( int const n, int16 const * x, int const incx, int16 * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < int16, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i32copy) ( int const n, int32 const * x, int const incx, int32 * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < int32, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i64copy) ( int const n, int64 const * x, int const incx, int64 * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < int64, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

extern "C" void
API(i128copy) ( int const n, int128 const * x, int const incx, int128 * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < int128, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}

#if 0
extern "C" void
API(bf16copy) ( int const n, bfloat16 const * x, int const incx, bfloat16 * y,int const incy )
{
  if ( n <= 0 ) return;
  API_private(COPY_host) < bfloat16, BLOCK_SIZE, MULTIPLE > ( y, x, n, incx, incy );
}
#endif


