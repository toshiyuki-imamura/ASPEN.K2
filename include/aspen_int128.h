#ifndef ASPEN_INT128_H_INCLUDED
#  define ASPEN_INT128_H_INCLUDED		1

#  include <stdint.h>

typedef	__int128	int128;

#  ifdef __cplusplus

// for int128

__host__ __device__ __forceinline__ int128
fma ( int128 const a, int128 const b, int128 const c )
{
  int128 const t = ((a * b) + c);
  return  t;
}

__host__ __device__ __forceinline__ int
isnan ( int128 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isinf ( int128 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isfinite ( int128 const a )
{
  return true;
}

__host__ __device__ __forceinline__ int128
Abs ( int128 const a )
{
  int128  t;
  t = ( a >= 0 ? a : -a );
  return  t;
}

__host__ __device__ __forceinline__ int128
Conj ( int128 const a )
{
  return ( a );
}

__host__ __device__ __forceinline__ int128
__choose__ ( bool const flag, int128 const a, int128 const b )
{
  return ( flag ? a : b );
}

#  endif

#endif

