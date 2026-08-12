#include "../tuning/CURRENT_GPU"
#include "aspen_devel.h"
#include "aspen_types.h"


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__global__ void 
API_private(SCAL_kernel) ( const TYPE alpha, TYPE * x, const long n, const long incx )
{
  long pos = threadIdx.x + MULTIPLE * BLOCK_SIZE * blockIdx.x;
  x += pos*incx;

  if ( pos+BLOCK_SIZE*MULTIPLE <= n ) {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      x[0] *= alpha;
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; }
    }
  } else {
#pragma unroll
    for ( int i=0; i<MULTIPLE; ++i ) {
      if ( pos+BLOCK_SIZE*i < n ) x[0] *= alpha;
      if ( MULTIPLE > 1 ) { x += BLOCK_SIZE*incx; }
    }
  }
}


template < class TYPE, int BLOCK_SIZE, int MULTIPLE >
__host__ void
API_private(SCAL_host) ( const TYPE alpha, TYPE * x, const int n, const int incx )
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

  API_private(SCAL_kernel) < TYPE , BLOCK_SIZE, MULTIPLE >
    <<< g1, t1, 32, stream
    >>> ( alpha, x, (long) n, (long) incx );

  if ( dev != p_dev ) cudaSetDevice( p_dev );
}


#define BLOCK_SIZE	(16*12)
#define	MULTIPLE	(2)

extern "C" void
API(hscal) ( const int n, const half alpha, half * x, const int incx )
{
  if ( n <= 0 ) return;
#if ASPEN_HALF_ENABLED
#if CUDA_VERSION==8000
  if ( alpha == makeCONST<half>(1) ) return;
  if ( alpha == makeCONST<half>(0) ) {
    API(HZERO) ( x, n );
  } else
#endif
    {
      API_private(SCAL_host) < half, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
    }
#endif
}

extern "C" void
API(sscal) ( const int n, const float alpha, float * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<float>(1) ) return;
  if ( alpha == makeCONST<float>(0) ) {
    API(SZERO) ( x, n );
  } else {
    API_private(SCAL_host) < float, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(dscal) ( const int n, double alpha, double * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<double>(1) ) return;
  if ( alpha == makeCONST<double>(0) ) {
    API(DZERO) ( x, n );
  } else {
    API_private(SCAL_host) < double, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(wscal) ( const int n, const cuddreal alpha, cuddreal * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuddreal>(1) ) return;
  if ( alpha == makeCONST<cuddreal>(0) ) {
    API(WZERO) ( x, n );
  } else {
    API_private(SCAL_host) < cuddreal, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(cscal) ( const int n, const cuFloatComplex alpha, cuFloatComplex * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuFloatComplex>(1) ) return;
  if ( alpha == makeCONST<cuFloatComplex>(0) ) {
    API(CZERO) ( x, n );
  } else {
    API_private(SCAL_host) < cuFloatComplex, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(zscal) ( const int n, const cuDoubleComplex alpha, cuDoubleComplex * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuDoubleComplex>(1) ) return;
  if ( alpha == makeCONST<cuDoubleComplex>(0) ) {
    API(ZZERO) ( x, n );
  } else {
    API_private(SCAL_host) < cuDoubleComplex, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(uscal) ( const int n, const cuddcomplex alpha, cuddcomplex * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<cuddcomplex>(1) ) return;
  if ( alpha == makeCONST<cuddcomplex>(0) ) {
    API(UZERO) ( x, n );
  } else {
    API_private(SCAL_host) < cuddcomplex, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(i16scal) ( const int n, const int16 alpha, int16 * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int16>(1) ) return;
  if ( alpha == makeCONST<int16>(0) ) {
    API(I16ZERO) ( x, n );
  } else {
    API_private(SCAL_host) < int16, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(i32scal) ( const int n, const int32 alpha, int32 * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int32>(1) ) return;
  if ( alpha == makeCONST<int32>(0) ) {
    API(I32ZERO) ( x, n );
  } else {
    API_private(SCAL_host) < int32, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(i64scal) ( const int n, const int64 alpha, int64 * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int64>(1) ) return;
  if ( alpha == makeCONST<int64>(0) ) {
    API(I64ZERO) ( x, n );
  } else {
    API_private(SCAL_host) < int64, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

extern "C" void
API(i128scal) ( const int n, const int128 alpha, int128 * x, const int incx )
{
  if ( n <= 0 ) return;
  if ( alpha == makeCONST<int128>(1) ) return;
  if ( alpha == makeCONST<int128>(0) ) {
    API(I128ZERO) ( x, n );
  } else {
    API_private(SCAL_host) < int128, BLOCK_SIZE, MULTIPLE > ( alpha, x, n, incx );
  }
}

