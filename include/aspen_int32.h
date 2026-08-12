#ifndef ASPEN_INT32_H_INCLUDED
#  define ASPEN_INT32_H_INCLUDED		1

#  include <stdint.h>
typedef int32_t	int32;
typedef struct { int32 x,y; }		int32v2;
typedef struct { int32 x,y,z; }		int32v3;
typedef struct { int32 x,y,z,w; }	int32v4;

#  ifdef __cplusplus

// for int

__host__ __device__ __forceinline__ int32
__add ( int32 const a,  int32 const b )
{
  int32 const t = (a + b);
  return  t;
}

__host__ __device__ __forceinline__ void
add2 ( int32 const a1, int32 const b1, int32 &d1,
       int32 const a2, int32 const b2, int32 &d2 )
{
  int32 const t1 = __add( a1, b1 );
  int32 const t2 = __add( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int32
__sub ( int32 const a,  int32 const b )
{
  int32 const t = (a - b);
  return  t;
}

__host__ __device__ __forceinline__ void
sub2 ( int32 const a1, int32 const b1, int32 &d1,
       int32 const a2, int32 const b2, int32 &d2 )
{
  int32 const t1 = __sub( a1, b1 );
  int32 const t2 = __sub( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int32
__mul ( int32 const a,  int32 const b )
{
  int32 const t = (a * b);
  return  t;
}

__host__ __device__ __forceinline__ void
mul2 ( int32 const a1, int32 const b1, int32 &d1,
       int32 const a2, int32 const b2, int32 &d2 )
{
  int32 const t1 = __mul( a1, b1 );
  int32 const t2 = __mul( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int32
fma ( int32 const a, int32 const b, int32 const c )
{
  int32 const t = (a * b + c);
  return  t;
}

__host__ __device__ __forceinline__ void
fma2 ( int32 const a1, int32 const b1, int32 const c1, int32 &d1,
       int32 const a2, int32 const b2, int32 const c2, int32 &d2 )
{
  int32 const t1 = fma( a1, b1, c1 );
  int32 const t2 = fma( a2, b2, c2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int
isnan ( int32 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isinf ( int32 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isfinite ( int32 const a )
{
  return true;
}

__host__ __device__ __forceinline__ int32
Abs ( int32 const a )
{
  int32  t;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "abs.s32\t%0, %1;"
                 : "=r"(t) : "r"(a) );
#    else
  t = ( a >= 0 ? a : -a );
#    endif
  return  t;
}

__host__ __device__ __forceinline__ int32
Conj ( int32 const a )
{
  return ( a );
}

__host__ __device__ __forceinline__ int32
__choose__ ( bool const flag, int32 const a, int32 const b )
{
  return ( flag ? a : b );
}

#  endif

#endif

