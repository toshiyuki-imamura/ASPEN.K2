#ifndef ASPEN_INT64_H_INCLUDED
#  define ASPEN_INT64_H_INCLUDED		1

#  include <stdint.h>
typedef	int64_t	int64;
typedef	struct { int64 x, y; }	int64v2;

#  ifdef __cplusplus

// for int

__host__ __device__ __forceinline__ int64
__add ( int64 const a,  int64 const b )
{
  int64 const t = (a + b);
  return  t;
}

__host__ __device__ __forceinline__ void
add2 ( int64 const a1, int64 const b1, int64 &d1,
       int64 const a2, int64 const b2, int64 &d2 )
{
  int64 const t1 = __add( a1, b1 );
  int64 const t2 = __add( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int64
__sub ( int64 const a,  int64 const b )
{
  int64 const t = (a - b);
  return  t;
}

__host__ __device__ __forceinline__ void
sub2 ( int64 const a1, int64 const b1, int64 &d1,
       int64 const a2, int64 const b2, int64 &d2 )
{
  int64 const t1 = __sub( a1, b1 );
  int64 const t2 = __sub( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int64
__mul ( int64 const a,  int64 const b )
{
  int64 const t = (a * b);
  return  t;
}

__host__ __device__ __forceinline__ void
mul2 ( int64 const a1, int64 const b1, int64 &d1,
       int64 const a2, int64 const b2, int64 &d2 )
{
  int64 const t1 = __mul( a1, b1 );
  int64 const t2 = __mul( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int64
fma ( int64 const a, int64 const b, int64 const c )
{
  int64 const t = (a * b + c);
  return  t;
}

__host__ __device__ __forceinline__ void
fma2 ( int64 const a1, int64 const b1, int64 const c1, int64 &d1,
       int64 const a2, int64 const b2, int64 const c2, int64 &d2 )
{
  int64 const t1 = fma( a1, b1, c1 );
  int64 const t2 = fma( a2, b2, c2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int
isnan ( int64 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isinf ( int64 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isfinite ( int64 const a )
{
  return true;
}

__host__ __device__ __forceinline__ int64
Abs ( int64 const a )
{
  int64  t;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "abs.s64\t%0, %1;"
                 : "=l"(t) : "l"(a) );
#    else
  t = ( a >= 0 ? a : -a );
#    endif
  return  t;
}

__host__ __device__ __forceinline__ int64
Conj ( int64 const a )
{
  return ( a );
}

__host__ __device__ __forceinline__ int64
__choose__ ( bool const flag, int64 const a, int64 const b )
{
  return ( flag ? a : b );
}

#  endif

#endif

