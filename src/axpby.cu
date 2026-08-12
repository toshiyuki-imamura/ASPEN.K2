#include "../tuning/CURRENT_GPU"
#include "aspen_devel.h"
#include "aspen_types.h"


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__global__ void 
API(AXPBY_kernel) ( const TYPE beta, TYPE * y, const TYPE alpha, const TYPE * x, const long n, const long incx, const long incy )
{
  const long pos = threadIdx.x + MULTIPLE * BLOCK_SIZE * blockIdx.x;
  x += pos*incx; y += pos*incy;

  if ( pos+BLOCK_SIZE*MULTIPLE <= n ) {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      y[0] = beta * y[0] + alpha * x[0];
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; y += BLOCK_SIZE*incy; }
    }
  } else {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      if ( pos+BLOCK_SIZE*i < n ) { y[0] = beta * y[0] + alpha * x[0]; }
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; y += BLOCK_SIZE*incy; }
    }
  }
}


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__host__ void
API(AXPBY_host) ( const TYPE beta, TYPE * y, const TYPE alpha, const TYPE * x, const int n, const int incx, const int incy )
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

  API(AXPBY_kernel) < TYPE , BLOCK_SIZE, MULTIPLE >
    <<< g1, t1, 32, stream
    >>> ( beta, y, alpha, x, (long) n, (long) incx, (long) incy );

  if ( dev != p_dev ) cudaSetDevice( p_dev );
}


#define BLOCK_SIZE	(16*12)
#define	MULTIPLE	(2)

extern "C" void
API(haxpby) ( const int n, const half alpha, const half * x, const int incx, const half beta, half *y, const int incy )
{
  if ( n <= 0 ) return;
#if ASPEN_HALF_ENABLED
#if CUDA_VERSION==8000
  if ( alpha == makeCONST<half>(0) ) {
    if ( beta == makeCONST<half>(1) ) return;
  }
#endif
  API(AXPBY_host) < half, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
#endif
}

extern "C" void
API(saxpby) ( const int n, const float alpha, const float * x, const int incx, const float beta, float *y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<float>(0) ) {
    if ( beta == makeCONST<float>(1) ) return;
  }
  API(AXPBY_host) < float, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(daxpby) ( const int n, const double alpha, const double * x, const int incx, const double beta, double * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<double>(0) ) {
    if ( beta == makeCONST<double>(1) ) return;
  }
  API(AXPBY_host) < double, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(waxpby) ( const int n, const cuddreal alpha, const cuddreal * x, const int incx, cuddreal beta, cuddreal * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuddreal>(0) ) {
    if ( beta == makeCONST<cuddreal>(1) ) return;
  }
  API(AXPBY_host) < cuddreal, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(caxpby) ( const int n, const cuFloatComplex alpha, const cuFloatComplex * x, const int incx, const cuFloatComplex beta, cuFloatComplex * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuFloatComplex>(0) ) {
    if ( beta == makeCONST<cuFloatComplex>(1) ) return;
  }
  API(AXPBY_host) < cuFloatComplex, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(zaxpby) ( const int n, const cuDoubleComplex alpha, const cuDoubleComplex * x, const int incx, cuDoubleComplex beta, cuDoubleComplex * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuDoubleComplex>(0) ) {
    if ( beta == makeCONST<cuDoubleComplex>(1) ) return;
  }
  API(AXPBY_host) < cuDoubleComplex, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(uaxpby) ( const int n, const cuddcomplex alpha, const cuddcomplex * x, const int incx, cuddcomplex beta, cuddcomplex * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuddcomplex>(0) ) {
    if ( beta == makeCONST<cuddcomplex>(1) ) return;
  }
  API(AXPBY_host) < cuddcomplex, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(i16axpby) ( const int n, const int16 alpha, const int16 * x, const int incx, int16 beta, int16 * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int16>(0) ) {
    if ( beta == makeCONST<int16>(1) ) return;
  }
  API(AXPBY_host) < int16, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(i32axpby) ( const int n, const int32 alpha, const int32 * x, const int incx, int32 beta, int32 * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int32>(0) ) {
    if ( beta == makeCONST<int32>(1) ) return;
  }
  API(AXPBY_host) < int32, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(i64axpby) ( const int n, const int64 alpha, const int64 * x, const int incx, int64 beta, int64 * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int64>(0) ) {
    if ( beta == makeCONST<int64>(1) ) return;
  }
  API(AXPBY_host) < int64, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

extern "C" void
API(i128axpby) ( const int n, const int128 alpha, const int128 * x, const int incx, int128 beta, int128 * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int128>(0) ) {
    if ( beta == makeCONST<int128>(1) ) return;
  }
  API(AXPBY_host) < int128, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}

#if 0
extern "C" void
API(bf16axpby) ( const int n, const bfloat16 alpha, const bfloat16 * x, const int incx, bfloat16 beta, bfloat16 * y, const int incy )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<bfloat16>(0) ) {
    if ( beta == makeCONST<bfloat16>(1) ) return;
  }
  API(AXPBY_host) < bfloat16, BLOCK_SIZE, MULTIPLE > ( beta, y, alpha, x, n, incx, incy );
}
#endif

