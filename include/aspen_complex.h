#ifndef ASPEN_COMPLEX_H_INCLUDED
#  define ASPEN_COMPLEX_H_INCLUDED	1

#  include <stdint.h>
#  include <cuComplex.h>
#  include "aspen_real.h"


#  ifdef __cplusplus

/*********************************************************************
 * cuFloatComplex
 *********************************************************************/

__device__ __forceinline__ float
get_real( cuFloatComplex &a )
{ return a.x; }

__device__ __forceinline__ float
get_imag( cuFloatComplex &a )
{ return a.y; }

__device__ __forceinline__ void
set_real( cuFloatComplex &a, float const x )
{ a.x = x; }

__device__ __forceinline__ void
set_imag( cuFloatComplex &a, float const y )
{ a.y = y; }


__host__ __device__ __forceinline__ cuFloatComplex
fma ( cuFloatComplex const a, cuFloatComplex const b, cuFloatComplex const c )
{
  cuFloatComplex t;
  t.x = fma( a.x, b.x, c.x );
  t.y = fma( a.x, b.y, c.y );
  float const e = -a.y;
  t.x = fma( e, b.y, t.x );
  t.y = fma( a.y, b.x, t.y );
  return t;
}


__host__ __device__ __forceinline__ bool
operator== ( cuFloatComplex const a, cuFloatComplex const b )
{
  bool const ret = ((a.x == b.x) && (a.y == b.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( cuFloatComplex const a, cuFloatComplex const b )
{
  bool const ret = ((a.x != b.x) || (a.y != b.y)) ? true : false;
  return ret;
}


__host__ __device__ __forceinline__ cuFloatComplex
operator+  ( cuFloatComplex const a )
{
  return a;
}

__host__ __device__ __forceinline__ cuFloatComplex
operator+  ( cuFloatComplex const a, cuFloatComplex const b )
{
  return { a.x + b.x, a.y + b.y };
}

__host__ __device__ __forceinline__ cuFloatComplex
operator+  ( cuFloatComplex const a, float const b )
{
  return { a.x + b, a.y };
}

__host__ __device__ __forceinline__ cuFloatComplex
operator+  ( float const a, cuFloatComplex const b )
{
  return { a + b.x, b.y };
}

__host__ __device__ __forceinline__ void
operator+= ( cuFloatComplex &a, cuFloatComplex const b )
{
  a = ( a + b );
}

__host__ __device__ __forceinline__ cuFloatComplex
operator- ( cuFloatComplex const a )
{
  cuFloatComplex const t = { -a.x, -a.y };
  return  t;
}

__host__ __device__ __forceinline__ cuFloatComplex
operator- ( cuFloatComplex const a, cuFloatComplex const b )
{
  return { a.x - b.x, a.y - b.y };
}

__host__ __device__ __forceinline__ cuFloatComplex
operator- ( cuFloatComplex const a, float const b )
{
  return { a.x - b, a.y };
}

__host__ __device__ __forceinline__ cuFloatComplex
operator- ( float const a, cuFloatComplex const b )
{
  return { a - b.x, -b.y };
}

__host__ __device__ __forceinline__ void
operator-= ( cuFloatComplex &a, cuFloatComplex const b )
{
  a = ( a - b );
}

__host__ __device__ __forceinline__ cuFloatComplex
operator* ( cuFloatComplex const a, cuFloatComplex const b )
{
  return cuCmulf ( a, b );
}

__host__ __device__ __forceinline__ cuFloatComplex
operator* ( cuFloatComplex const a, float const b )
{
  return (cuFloatComplex) { a.x * b, a.y * b };
}

__host__ __device__ __forceinline__ cuFloatComplex
operator* ( float const a, cuFloatComplex const b )
{
  float const a_ = a;
  cuFloatComplex const b_ = b;
  return ( b_ * a_ );
}

__host__ __device__ __forceinline__ cuFloatComplex
operator* ( cuFloatComplex const a, int const b )
{
  return ( a * (float)b );
}

__host__ __device__ __forceinline__ cuFloatComplex
operator* ( int const a, cuFloatComplex const b )
{
  int const a_ = a;
  cuFloatComplex const b_ = b;
  return ( b_ * a_ );
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( cuFloatComplex &a, const T b )
{
  a = ( a * b );
}

__host__ __device__ __forceinline__ cuFloatComplex
operator/ ( cuFloatComplex const a, cuFloatComplex const b )
{
  return cuCdivf ( a, b );
}

__host__ __device__ __forceinline__ cuFloatComplex
operator/ ( cuFloatComplex const a, float const b )
{
  return (cuFloatComplex) { a.x / b, a.y / b };
}

__host__ __device__ __forceinline__ cuFloatComplex
operator/ ( cuFloatComplex const a, int const b )
{
  return ( a / (float)b );
}

template < class T >
__host__ __device__ __forceinline__ void
operator/= ( cuFloatComplex &a, T const b )
{
  a = ( a / b );
}

__host__ __device__ __forceinline__ void
add2 ( cuFloatComplex const a1, cuFloatComplex const b1, cuFloatComplex &d1,
       cuFloatComplex const a2, cuFloatComplex const b2, cuFloatComplex &d2 )
{
  cuFloatComplex t1,t2;
  t1 = a1 + b1;
  t2 = a2 + b2;
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
sub2 ( cuFloatComplex const a1, cuFloatComplex const b1, cuFloatComplex &d1,
       cuFloatComplex const a2, cuFloatComplex const b2, cuFloatComplex &d2 )
{
  cuFloatComplex t1,t2;
  t1 = a1 - b1;
  t2 = a2 - b2;
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
mul2 ( cuFloatComplex const a1, cuFloatComplex const b1, cuFloatComplex &d1,
       cuFloatComplex const a2, cuFloatComplex const b2, cuFloatComplex &d2 )
{
  cuFloatComplex t1,t2;
  t1.x = __mul( a1.x, b1.x );
  t1.y = __mul( a1.x, b1.y );
  t2.x = __mul( a2.x, b2.x );
  t2.y = __mul( a2.x, b2.y );
  float const e1 = -a1.y;
  float const e2 = -a2.y;
  t1.x = fma( e1, b1.y, t1.x );
  t2.x = fma( e2, b2.y, t2.x );
  t1.y = fma( a1.y, b1.x, t1.y );
  t2.y = fma( a2.y, b2.x, t2.y );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
fma2 ( cuFloatComplex const a1, cuFloatComplex const b1, cuFloatComplex const c1, cuFloatComplex &d1,
       cuFloatComplex const a2, cuFloatComplex const b2, cuFloatComplex const c2, cuFloatComplex &d2 )
{
  cuFloatComplex t1, t2;
  fma2( a1.x, b1.x, c1.x, t1.x,
        a2.x, b2.x, c2.x, t2.x );
  fma2( a1.x, b1.y, c1.y, t1.y,
        a2.x, b2.y, c2.y, t2.y );
  float const e1 = -a1.y;
  float const e2 = -a2.y;
  fma2( e1, b1.y, t1.x, t1.x,
        e2, b2.y, t2.x, t2.x );
  fma2( a1.y, b1.x, t1.y, t1.y,
        a2.y, b2.x, t2.y, t2.y );
  d1 = t1; d2 = t2;
}


__host__ __device__ __forceinline__ cuFloatComplex
fma ( cuFloatComplex const a, float const b, cuFloatComplex const c )
{
  cuFloatComplex t;
  t.x = fma( a.x, b, c.x );
  t.y = fma( a.y, b, t.y );
  return t;
}

__host__ __device__ __forceinline__ cuFloatComplex
fma ( float const a, cuFloatComplex const b, cuFloatComplex const c )
{
  cuFloatComplex t;
  t.x = fma( a, b.x, c.x );
  t.y = fma( a, b.y, c.y );
  return t;
}

__host__ __device__ __forceinline__ int
isnan ( cuFloatComplex const a )
{
  return (isnan(a.x) || isnan(a.y));
}

__host__ __device__ __forceinline__ int
isinf ( cuFloatComplex const a )
{
  return (isinf(a.x) || isinf(a.y));
}

__host__ __device__ __forceinline__ int
isfinite ( cuFloatComplex const a )
{
#    if defined(__CUDA_ARCH__)
  uint b;
  asm volatile ( "and.b32\t%0, %1, %2;" : "=r"(b) : "f"(a.x), "f"(a.y) );
  uint const mask = 0x7f800000;
  return (b & mask) != mask;
#    else
  return (isfinite(a.x) && isfinite(a.y));
#    endif
}

__host__ __device__ __forceinline__ float
Abs ( cuFloatComplex const a )
{
  return cuCabsf ( a );
}

__host__ __device__ __forceinline__ void
makeConj ( cuFloatComplex & a ) {
  a = cuConjf ( a );
}

__host__ __device__ __forceinline__ cuFloatComplex
Conj ( cuFloatComplex const a ) {
  return cuConjf ( a );
}

__host__ __device__ __forceinline__ cuFloatComplex
__choose__ ( bool const flag, cuFloatComplex const a, cuFloatComplex const b )
{
  cuFloatComplex t = { (flag ? a.x : b.x), (flag ? a.y : b.y) };
  return t;
}

/*********************************************************************
 * cuDoubleComplex
 *********************************************************************/

__device__ __forceinline__ double
get_real( cuDoubleComplex &a )
{ return a.x; }

__device__ __forceinline__ double
get_imag( cuDoubleComplex &a )
{ return a.y; }

__device__ __forceinline__ void
set_real( cuDoubleComplex &a, double const x )
{ a.x = x; }

__device__ __forceinline__ void
set_imag( cuDoubleComplex &a, double const y )
{ a.y = y; }


__host__ __device__ __forceinline__ cuDoubleComplex
fma ( cuDoubleComplex const a, cuDoubleComplex const b, cuDoubleComplex const c)
{
  cuDoubleComplex t;
  t.x = fma( a.x, b.x, c.x );
  t.y = fma( a.x, b.y, c.y );
  double const e = -a.y;
  t.x = fma( e, b.y, t.x );
  t.y = fma( a.y, b.x, t.y );
  return t;
}


__host__ __device__ __forceinline__ bool
operator== ( cuDoubleComplex const a, cuDoubleComplex const b )
{
  bool const ret = ((a.x == b.x) && (a.y == b.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( cuDoubleComplex const a, cuDoubleComplex const b )
{
  bool const ret = ((a.x != b.x) || (a.y != b.y)) ? true : false;
  return ret;
}


__host__ __device__ __forceinline__ cuDoubleComplex
operator+ ( cuDoubleComplex const a )
{
  return a;
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator+ ( cuDoubleComplex const a, cuDoubleComplex const b )
{
  return { a.x + b.x, a.y + b.y };
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator+ ( cuDoubleComplex const a, double const b )
{
  return { a.x + b, a.y };
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator+ ( double const a, cuDoubleComplex const b )
{
  return { a + b.x, b.y };
}

__host__ __device__ __forceinline__ void
operator+= ( cuDoubleComplex &a, cuDoubleComplex const b )
{
  a = ( a + b );
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator- ( cuDoubleComplex const a )
{
  return (cuDoubleComplex) { -a.x, -a.y };
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator- ( cuDoubleComplex const a, cuDoubleComplex const b )
{
  return { a.x - b.x, a.y - b.y };
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator- ( cuDoubleComplex const a, double const b )
{
  return { a.x - b, a.y };
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator- ( double const a, cuDoubleComplex const b )
{
  return { a - b.x, -b.y };
}

__host__ __device__ __forceinline__ void
operator-= ( cuDoubleComplex &a, cuDoubleComplex const b )
{
  a = ( a - b );
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator* ( cuDoubleComplex const a, cuDoubleComplex const b )
{
  return cuCmul ( a, b );
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator* ( cuDoubleComplex const a, double const b )
{
  return (cuDoubleComplex) { a.x * b, a.y * b };
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator* ( double const a, cuDoubleComplex const b )
{
  double const a_ = a;
  cuDoubleComplex const b_ = b;
  return ( b_ * a_ );
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator* ( cuDoubleComplex const a, int const b )
{
  double const c = (double)b;
  return ( a * c );
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator* ( int const a, cuDoubleComplex const b )
{
  int const a_ = a;
  cuDoubleComplex const b_ = b;
  return ( b_ * a_ );
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( cuDoubleComplex &a, const T b )
{
  a = ( a * b );
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator/ ( cuDoubleComplex const a, cuDoubleComplex const b )
{
  return ( a / b );
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator/ ( cuDoubleComplex const a, double const b )
{
  return (cuDoubleComplex) { a.x / b, a.y / b };
}

__host__ __device__ __forceinline__ cuDoubleComplex
operator/ ( cuDoubleComplex const a, int const b )
{
  return ( a / (double)b );
}

template < class T >
__host__ __device__ __forceinline__ void
operator/= ( cuDoubleComplex &a, const T b )
{
  a = ( a / b );
}

__host__ __device__ __forceinline__ void
add2 ( cuDoubleComplex const a1, cuDoubleComplex const b1, cuDoubleComplex &d1,
       cuDoubleComplex const a2, cuDoubleComplex const b2, cuDoubleComplex &d2 )
{
  cuDoubleComplex t1,t2;
  t1 = a1 + b1;
  t2 = a2 + b2;
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
sub2 ( cuDoubleComplex const a1, cuDoubleComplex const b1, cuDoubleComplex &d1,
       cuDoubleComplex const a2, cuDoubleComplex const b2, cuDoubleComplex &d2 )
{
  cuDoubleComplex t1,t2;
  t1 = a1 - b1;
  t2 = a2 - b2;
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
mul2 ( cuDoubleComplex const a1, cuDoubleComplex const b1, cuDoubleComplex &d1,
       cuDoubleComplex const a2, cuDoubleComplex const b2, cuDoubleComplex &d2 )
{
  cuDoubleComplex t1,t2;
  t1.x = __mul( a1.x, b1.x );
  t1.y = __mul( a1.x, b1.y );
  t2.x = __mul( a2.x, b2.x );
  t2.y = __mul( a2.x, b2.y );
  double const e1 = -a1.y;
  double const e2 = -a2.y;
  t1.x = fma( e1, b1.y, t1.x );
  t2.x = fma( e2, b2.y, t2.x );
  t1.y = fma( a1.y, b1.x, t1.y );
  t2.y = fma( a2.y, b2.x, t2.y );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
fma2 ( cuDoubleComplex const a1, cuDoubleComplex const b1, cuDoubleComplex const c1, cuDoubleComplex &d1,
       cuDoubleComplex const a2, cuDoubleComplex const b2, cuDoubleComplex const c2, cuDoubleComplex &d2 )
{
  cuDoubleComplex t1, t2;
  fma2( a1.x, b1.x, c1.x, t1.x,
        a2.x, b2.x, c2.x, t2.x );
  fma2( a1.x, b1.y, c1.y, t1.y,
        a2.x, b2.y, c2.y, t2.y );
  double const e1 = -a1.y;
  double const e2 = -a2.y;
  fma2( e1, b1.y, t1.x, t1.x,
        e2, b2.y, t2.x, t2.x );
  fma2( a1.y, b1.x, t1.y, t1.y,
        a2.y, b2.x, t2.y, t2.y );
  d1 = t1; d2 = t2;
}


__host__ __device__ __forceinline__ cuDoubleComplex
fma ( cuDoubleComplex const a, double const b, cuDoubleComplex const c)
{
  cuDoubleComplex t;
  t.x = fma( a.x, b, c.x );
  t.y = fma( a.y, b, t.y );
  return t;
}

__host__ __device__ __forceinline__ cuDoubleComplex
fma ( double const a, cuDoubleComplex const b, cuDoubleComplex const c)
{
  cuDoubleComplex t;
  t.x = fma( a, b.x, c.x );
  t.y = fma( a, b.y, c.y );
  return t;
}

__host__ __device__ __forceinline__ int
isnan ( cuDoubleComplex const a )
{
  return (isnan(a.x) || isnan(a.y));
}

__host__ __device__ __forceinline__ int
isinf ( cuDoubleComplex const a )
{
  return (isinf(a.x) || isinf(a.y));
}

__host__ __device__ __forceinline__ int
isfinite ( cuDoubleComplex const a )
{
#    if defined(__CUDA_ARCH__)
  uint const b  = __double2hiint( a.x ) & __double2hiint( a.y );
  uint const mask = 0x7ff00000;
  return (b & mask) != mask;
#    else
  return (isfinite(a.x) && isfinite(a.y));
#    endif
}

__host__ __device__ __forceinline__ double
Abs ( cuDoubleComplex const a )
{
  return cuCabs( a );
}

__host__ __device__ __forceinline__ void
makeConj ( cuDoubleComplex & a )
{
  a = cuConj ( a );
}

__host__ __device__ __forceinline__ cuDoubleComplex
Conj ( cuDoubleComplex const a )
{
  return cuConj ( a );
}

__host__ __device__ __forceinline__ cuDoubleComplex
__choose__ ( bool const flag, cuDoubleComplex const a, cuDoubleComplex const b )
{
  cuDoubleComplex t = { (flag ? a.x : b.x), (flag ? a.y : b.y) };
  return t;
}

#  endif

#endif

