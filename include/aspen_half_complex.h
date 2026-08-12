#ifndef ASPEN_HALF_COMPLEX_H_INCLUDED
#  define ASPEN_HALF_COMPLEX_H_INCLUDED	1

// minimum functions are preliminary implemented

#  include <stdint.h>
#  include "aspen_half.h"

#  if ASPEN_HALF_ENABLED

typedef struct __align__(4) {
  half x; half y;
} __cuHalfComplex_raw__;

#    ifndef __cplusplus

typedef __cuHalfComplex_raw__	cuHalfComplex_raw;
typedef __cuHalfComplex_raw__	cuHalfComplex;

#    else

struct __align__(4) __cuHalfComplex__ 
{
 private:
  half x; half y;
 public:
#      if __cplusplus >= 201103L
  __cuHalfComplex__() = default;
#      else
  __host__ __device__ __forceinline__
    __cuHalfComplex__() { }
#      endif
  __host__ __device__ __forceinline__
    __cuHalfComplex__( __cuHalfComplex_raw__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __cuHalfComplex__ &operator= ( __cuHalfComplex_raw__ const &h ) { x = h.x; y = h.y; return *this; }
  __host__ __device__ __forceinline__
    operator __cuHalfComplex_raw__() const { __cuHalfComplex_raw__ h; h.x = x; h.y = y; return h; }

  __host__ __device__ __forceinline__
    __cuHalfComplex__( half const &a, half const &b ) { x = a; y = b; }

  __host__ __device__ __forceinline__
    __cuHalfComplex_raw__ * raw( void ) { return reinterpret_cast<__cuHalfComplex_raw__*>(this); }

  __host__ __device__ __forceinline__
    operator half() const {
    return x;
  }

  __host__ __device__ __forceinline__
    half real() const {
    return x;
  }
  __host__ __device__ __forceinline__
    half imag() const {
    return y;
  }
  __host__ __device__ __forceinline__
    half real( half const x ) {
    this->x = x; return x;
  }
  __host__ __device__ __forceinline__
    half imag( half const y ) {
    this->y = y; return y;
  }
};

typedef struct __cuHalfComplex__	cuHalfComplex;
typedef        __cuHalfComplex_raw__	cuHalfComplex_raw;


__host__ __device__ __forceinline__ half
get_real( cuHalfComplex &a )
{ return a.real(); }

__host__ __device__ __forceinline__ half
get_imag( cuHalfComplex &a )
{ return a.imag(); }

__host__ __device__ __forceinline__ void
set_real( cuHalfComplex &a, half const x )
{ a.real( x ); }

__host__ __device__ __forceinline__ void
set_imag( cuHalfComplex &a, half const y )
{ a.imag( y ); }



// comparation operator on host is not supported yet
__host__ __device__ __forceinline__ bool
operator== ( cuHalfComplex const a, cuHalfComplex const b )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const b_ = b;
  bool const ret = (a_.x == b_.x && a_.y == b_.y) ? true : false;
  return ret;
}

// comparation operator on host is not supported yet
__host__ __device__ __forceinline__ bool
operator!= ( cuHalfComplex const a, cuHalfComplex const b )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const b_ = b;
  bool const ret = (a_.x != b_.x || a_.y != b_.y) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ cuHalfComplex
operator+  ( cuHalfComplex const a )
{
  return a;
}

__host__ __device__ __forceinline__ cuHalfComplex
operator+  ( cuHalfComplex const a, cuHalfComplex const b )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const b_ = b;
  cuHalfComplex_raw t_;
  t_.x = a_.x + b_.x;
  t_.y = a_.y + b_.y;
  return t_;
}

__host__ __device__ __forceinline__ void
operator+= ( cuHalfComplex &a, cuHalfComplex const b )
{
  a = (a + b);
}

__host__ __device__ __forceinline__ cuHalfComplex
operator- ( cuHalfComplex const a )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw t_ = a_;
  t_.x = -t_.x;
  t_.y = -t_.y;
  return  t_;
}

__host__ __device__ __forceinline__ cuHalfComplex
operator-  ( cuHalfComplex const a, cuHalfComplex const b )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const b_ = b;
  cuHalfComplex_raw t_;
  t_.x = a_.x - b_.x;
  t_.y = a_.y - b_.y;
  return  t_;
}

__host__ __device__ __forceinline__ void
operator-= ( cuHalfComplex &a, cuHalfComplex const b )
{
  a = (a - b);
}

__host__ __device__ __forceinline__ cuHalfComplex
operator* ( cuHalfComplex const a, cuHalfComplex const b )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const b_ = b;
  cuHalfComplex_raw t_;
  half const e = -a_.y;
  t_.x = a_.x * b_.x;
  t_.y = a_.x * b_.y;
  t_.x = t_.x + e * b_.y;
  t_.y = t_.y + a_.y * b_.x;
  return  t_;
}

__host__ __device__ __forceinline__ cuHalfComplex
operator* ( cuHalfComplex const a, half const b )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw t_;
  t_.x = a_.x * b;
  t_.y = a_.y * b;
  return  t_;
}

__host__ __device__ __forceinline__ cuHalfComplex
operator* ( half const a, cuHalfComplex const b )
{
  return ( b * a );
}

__host__ __device__ __forceinline__ cuHalfComplex
operator* ( cuHalfComplex const a, int const b )
{
  half const c = (half)b;
  return  ( a * c );
}

__host__ __device__ __forceinline__ cuHalfComplex
operator* ( int const a, cuHalfComplex const b )
{
  return (b * a);
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( cuHalfComplex &a, T const b )
{
  a = (a * b);
}

__host__ __device__ __forceinline__ cuHalfComplex
operator/ ( cuHalfComplex const a, cuHalfComplex const b )
{
  cuHalfComplex_raw const b_ = b;
  half const r = b_.x * b_.x + b_.y * b_.y;
  cuHalfComplex_raw t_ = a * Conj(b);
  t_.x /= r;
  t_.y /= r;
  return  t_;
}

__host__ __device__ __forceinline__ cuHalfComplex
operator/ ( cuHalfComplex const a, half const b )
{
  cuHalfComplex const c = { b, (half)0 };
  return  ( a / c );
}

__host__ __device__ __forceinline__ cuHalfComplex
operator/ ( cuHalfComplex const a, int const b )
{
  half const c = (half)b;
  return  ( a / c );
}

template < class T >
__host__ __device__ __forceinline__ void
operator/= ( cuHalfComplex &a, T const b )
{
  a = ( a / b );
}

__host__ __device__ __forceinline__ cuHalfComplex
fma ( cuHalfComplex const a, cuHalfComplex const b, cuHalfComplex const c )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const b_ = b;
  cuHalfComplex_raw const c_ = c;
  cuHalfComplex_raw t_;
  t_.x = fma( a_.x, b_.x, c_.x );
  t_.y = fma( a_.x, b_.y, c_.y );
  t_.x = fma( -a_.y, b_.y, t_.x );
  t_.y = fma( a_.y, b_.x, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cuHalfComplex
fma ( cuHalfComplex const a, half const b, cuHalfComplex const c )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const c_ = c;
  cuHalfComplex_raw t_;
  t_.x = fma( a_.x, b, c_.x );
  t_.y = fma( a_.y, b, c_.y );
  return t_;
}

__host__ __device__ __forceinline__ cuHalfComplex
fma ( half const a, cuHalfComplex const b, cuHalfComplex const c )
{
  return fma( b, a, c );
}

#      if 0
__device__ __forceinline__ int
isnan ( cuHalfComplex const a )
{
  cuHalfComplex_raw const a_ = a;
  return (isnan(a_.x) || isnan(a_.y));
}

__device__ __forceinline__ int
isinf ( cuHalfComplex const a )
{
  cuHalfComplex_raw const a_ = a;
  return (isinf(a_.x) || isinf(a_.y));
}
#      endif

#      if defined(__CUDA_ARCH__)
__host__ __device__ __forceinline__ int
isfinite ( cuHalfComplex const a )
{
  cuHalfComplex_raw const a_ = a;
  return (isfinite(a_.x) && isfinite(a_.y));
}
#      endif

__host__ __device__ __forceinline__ cuHalfComplex
Conj ( cuHalfComplex const a ) {
  half const ar = a.real();
  half const ai = a.imag();
  return cuHalfComplex( ar, -ai );
}

__host__ __device__ __forceinline__ void
makeConj ( cuHalfComplex & a ) {
  set_imag(a, -get_imag(a));
}

__host__ __device__ __forceinline__ half
Abs ( cuHalfComplex const a )
{
  cuHalfComplex_raw const a_ = a;
#      if 1
  half const r2 = a_.x * a_.x + a_.y * a_.y;
  half const t = float2half( sqrt( half2float(r2) ) );
  return t;
#      else
  half const rx = Abs(a_.x);
  half const ry = Abs(a_.y);
  half const rr = rx > ry ? rx : ry;
  half z; z.raw = (int16_t)0;
  if ( rr == z ) {
    return z;
  } else {
    half const rf = rx < ry ? rx : ry;
    half const rt = rf/rr;
    half const o = rr/rr;
    half const r2 = o + rt * rt;
    half const t = float2half( sqrt( half2float(r2) ) );
    return t*rr;
  }
#      endif
}

__host__ __device__ __forceinline__ cuHalfComplex
__choose__ ( bool const flag, cuHalfComplex const a, cuHalfComplex const b )
{
  cuHalfComplex_raw const a_ = a;
  cuHalfComplex_raw const b_ = b;
  cuHalfComplex_raw t_;
  t_.x = __choose__( flag, a_.x, b_.x );
  t_.y = __choose__( flag, a_.y, b_.y );
  return t_;
}

#    endif

#  endif

#endif

