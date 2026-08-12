#ifndef ASPEN_DFCOMPLEX_H_INCLUDED
#  define ASPEN_DFCOMPLEX_H_INCLUDED		1

#  include <stdint.h>
#  include <cuComplex.h>
#  include "aspen_ddreal.h"

#  define	ASPEN_DFCOMPLEX_struct_body     \
  cudfreal x; cudfreal y

typedef struct __align__(16) {
  ASPEN_DFCOMPLEX_struct_body;
} __cudfcomplex_raw__;

#  ifndef __cplusplus

typedef	__cudfcomplex_raw__	cudfcomplex_raw;
typedef	__cudfcomplex_raw__	cudfcomplex;

#  else

struct __align__(16) __cudfcomplex__
{
 private:
  ASPEN_DFCOMPLEX_struct_body;
 public:
#    if __cplusplus >= 201103L
  __cudfcomplex__() = default;
#    else
  __host__ __device__ __forceinline__
    __cudfcomplex__() { }
#    endif
  __host__ __device__ __forceinline__
    __cudfcomplex__( __cudfcomplex_raw__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __cudfcomplex__ &operator= ( __cudfcomplex_raw__ const &h ) { x = h.x; y = h.y; return *this; }
  __host__ __device__ __forceinline__
    operator __cudfcomplex_raw__() const { __cudfcomplex_raw__ h; h.x = x; h.y = y; return h; }

  __host__ __device__ __forceinline__
    __cudfcomplex__( cudfreal const &a, cudfreal const &b ) { x = a; y = b; }

  __host__ __device__ __forceinline__
    operator cudfreal() const {
    return x;
  }

  __host__ __device__ __forceinline__
    operator cuFloatComplex() const {
    cudfreal_raw const x_ = x;
    cudfreal_raw const y_ = y;
    cuFloatComplex const t = { x_.x, y_.x };
    return t;
  }

  __host__ __device__ __forceinline__
    cudfreal real() const {
    return x;
  }
  __host__ __device__ __forceinline__
    cudfreal imag() const {
    return y;
  }
  __host__ __device__ __forceinline__
    cudfreal real(cudfreal const x) {
    this->x = x; return x;
  }
  __host__ __device__ __forceinline__
    cudfreal imag(cudfreal const y) {
    this->y = y; return y;
  }
};

typedef	struct __cudfcomplex__		cudfcomplex;
typedef	       __cudfcomplex_raw__	cudfcomplex_raw;


#    if GPU_ARCH>300
__device__ __forceinline__ cudfcomplex
__ldg ( cudfcomplex const * a )
{
  cudfcomplex * aa = (cudfcomplex *)a;
  cudfcomplex_raw * p_ = (reinterpret_cast<cudfcomplex_raw *>(aa));
  cudfcomplex_raw t_;
  t_.x = __ldg( (cudfreal *)&(p_->x) );
  t_.y = __ldg( (cudfreal *)&(p_->y) );
  return t_;
}
#    endif


__device__ __forceinline__ cudfreal
get_real( cudfcomplex &a )
{ return a.real(); }

__device__ __forceinline__ cudfreal
get_imag( cudfcomplex &a )
{ return a.imag(); }

__device__ __forceinline__ void
set_real( cudfcomplex &a, cudfreal const x )
{ a.real( x ); }

__device__ __forceinline__ void
set_imag( cudfcomplex &a, cudfreal const y )
{ a.imag( y ); }


__host__ __device__ __forceinline__ bool
operator== ( cudfcomplex const a, cudfcomplex const b )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;
  bool const ret = ((a_.x == b_.x) && (a_.y == b_.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( cudfcomplex const a, cudfcomplex const b )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;
  bool const ret = ((a_.x != b_.x) || (a_.y != b_.y)) ? true : false;
  return ret;
}


__host__ __device__ __forceinline__ cudfcomplex
operator+ ( cudfcomplex const a )
{
  return (a);
}

__host__ __device__ __forceinline__ cudfcomplex
operator+ ( cudfcomplex const a, cudfcomplex const b )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;
  cudfcomplex_raw t_;
  add2 ( a_.x, b_.x, t_.x,  a_.y, b_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ void
operator+= ( cudfcomplex &a, cudfcomplex const b )
{
  a = (a + b);
}

__host__ __device__ __forceinline__ cudfcomplex
operator- ( cudfcomplex const a )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw t_ = a_;
  t_.x = - t_.x;
  t_.y = - t_.y;
  return t_;
}

__host__ __device__ __forceinline__ cudfcomplex
operator- ( cudfcomplex const a, cudfcomplex const b )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;
  cudfcomplex_raw t_;
  sub2 ( a_.x, b_.x, t_.x,  a_.y, b_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ void
operator-= ( cudfcomplex &a, cudfcomplex const b )
{
  a = (a - b);
}

__host__ __device__ __forceinline__ cudfcomplex
operator* ( cudfcomplex const a, cudfcomplex const b )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;
  cudfcomplex_raw t_;
  cudfreal e = -a_.y;
  mul2 ( a_.x, b_.x, t_.x,  a_.x, b_.y, t_.y );
  fma2 ( e,    b_.y, t_.x, t_.x,  a_.y, b_.x, t_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cudfcomplex
operator* ( cudfcomplex const a, cudfreal const b )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw t_;
  mul2 ( a_.x, b, t_.x,  a_.y, b, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cudfcomplex
operator* ( cudfreal const a, cudfcomplex const b )
{
  cudfcomplex t = (b * a);
  return t;
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( cudfcomplex &a, T const b )
{
  a = (a * b);
}

__host__ __device__ __forceinline__ cudfcomplex
fma ( cudfcomplex const a, cudfcomplex const b, cudfcomplex const c )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;
  cudfcomplex_raw const c_ = c;
  cudfcomplex_raw t_;
  cudfreal e = -a_.y;
  fma2 ( a_.x, b_.x, c_.x, t_.x,  a_.x, b_.y, c_.y, t_.y );
  fma2 ( e,    b_.y, t_.x, t_.x,  a_.y, b_.x, t_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cudfcomplex
fma ( cudfcomplex const a, cudfreal const b, cudfcomplex const c )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const c_ = c;
  cudfcomplex_raw t_;
  fma2 ( a_.x, b, c_.x, t_.x,  a_.y, b, c_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cudfcomplex
fma ( cudfreal const a, cudfcomplex const b, cudfcomplex const c )
{
  cudfcomplex t = fma( b, a, c );
  return t;
}

__host__ __device__ __forceinline__ cudfcomplex
CUWDIV ( cudfcomplex const a, cudfcomplex const b )
{
  /*
   * almost similar approach to divide a complex number as cuComplex.h
   */
  cudfreal const     ZERO_   = __cudfreal__( (float)0, (float)0 );
  cudfcomplex const  ZERO    = __cudfcomplex__( ZERO_, ZERO_ );
  cudfreal const     NAN_DF  = __cudfreal__( NAN, NAN );
  cudfcomplex const  NAN_DFC = __cudfcomplex__( NAN_DF, NAN_DF );
  cudfreal const     ONE_    = __cudfreal__( (float)1, (float)0 );
  cudfcomplex const  ONE     = __cudfcomplex__( ONE_, ZERO_ );
  cudfreal const     MONE_   = __cudfreal__( (float)1, (float)0 );
  cudfcomplex const  MONE    = __cudfcomplex__( MONE_, ZERO_ );

  if ( b == ZERO ) { return NAN_DFC; }
  if ( a == ZERO ) { return ZERO; }
  if ( b == ONE  ) { return a; }
  if ( b == MONE ) { return -a; }

  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;

  cudfreal s = Abs(b_.x) + Abs(b_.y);
  cudfreal r = ONE_ / s;
  cudfreal const ar = a_.x * r;
  cudfreal const ai = a_.y * r;
  cudfreal const br = b_.x * r;
  cudfreal const bi = b_.y * r;
  s = (br * br) + (bi * bi);
  r = ONE_ / s;
  cudfcomplex const t = __cudfcomplex__(
                                        ((ar * br) + (ai * bi)) * r,
                                        ((ai * br) - (ar * bi)) * r );
  return t;
}

__host__ __device__ __forceinline__ cudfcomplex
operator/ ( cudfcomplex const a, cudfcomplex const b )
{
  cudfcomplex const t = CUWDIV ( a, b );
  return t;
}

__host__ __device__ __forceinline__ cudfcomplex
operator/ ( cudfcomplex const a, cudfreal const b )
{
  cudfreal const z = { (float)0, (float)0 };
  cudfcomplex const c = { b, z };
  cudfcomplex const t = a / c;
  return t;
}
__host__ __device__ __forceinline__ cudfcomplex
operator/ ( cudfcomplex const a, float const b )
{
  cudfreal const c = { b, (float)0 };
  cudfcomplex const t = a / c;
  return t;
}

__host__ __device__ __forceinline__ cudfcomplex
operator/ ( cudfcomplex const a, int const b )
{
  float const c = (float)b;
  cudfcomplex const t = a / c;
  return t;
}

template < class T >
__host__ __device__ __forceinline__ void
operator/= ( cudfcomplex &a, T const b )
{
  a = ( a / b );
}


__host__ __device__ __forceinline__ void
add2 ( cudfcomplex const a1, cudfcomplex const b1, cudfcomplex &d1,
       cudfcomplex const a2, cudfcomplex const b2, cudfcomplex &d2 )
{
  cudfcomplex_raw const a1_ = a1;
  cudfcomplex_raw const a2_ = a2;
  cudfcomplex_raw const b1_ = b1;
  cudfcomplex_raw const b2_ = b2;
  cudfcomplex_raw t1_, t2_;
  add2 ( a1_.x, b1_.x, t1_.x,  a2_.x, b2_.x, t2_.x );
  add2 ( a1_.y, b1_.y, t1_.y,  a2_.y, b2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ void
sub2 ( cudfcomplex const a1, cudfcomplex const b1, cudfcomplex &d1,
       cudfcomplex const a2, cudfcomplex const b2, cudfcomplex &d2 )
{
  cudfcomplex_raw const a1_ = a1;
  cudfcomplex_raw const a2_ = a2;
  cudfcomplex_raw const b1_ = b1;
  cudfcomplex_raw const b2_ = b2;
  cudfcomplex_raw t1_, t2_;
  sub2 ( a1_.x, b1_.x, t1_.x,  a2_.x, b2_.x, t2_.x );
  sub2 ( a1_.y, b1_.y, t1_.y,  a2_.y, b2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ void
mul2 ( cudfcomplex const a1, cudfcomplex const b1, cudfcomplex &d1,
       cudfcomplex const a2, cudfcomplex const b2, cudfcomplex &d2 )
{
  cudfcomplex_raw const a1_ = a1;
  cudfcomplex_raw const a2_ = a2;
  cudfcomplex_raw const b1_ = b1;
  cudfcomplex_raw const b2_ = b2;
  cudfcomplex_raw t1_, t2_;
  cudfreal e1 = -a1_.y, e2 = -a2_.y;
  mul2 ( a1_.x, b1_.x, t1_.x,  a2_.x, b2_.x, t2_.x );
  mul2 ( a1_.x, b1_.y, t1_.y,  a2_.x, b2_.y, t2_.y );
  fma2 ( e1,    b1_.y, t1_.x, t1_.x,  e2,    b1_.y, t2_.x, t2_.x );
  fma2 ( a1_.y, b1_.x, t1_.y, t1_.y,  a2_.y, b1_.x, t2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ void
fma2 ( cudfcomplex const a1, cudfcomplex const b1, cudfcomplex const c1, cudfcomplex &d1,
       cudfcomplex const a2, cudfcomplex const b2, cudfcomplex const c2, cudfcomplex &d2 )
{
  cudfcomplex_raw const a1_ = a1;
  cudfcomplex_raw const a2_ = a2;
  cudfcomplex_raw const b1_ = b1;
  cudfcomplex_raw const b2_ = b2;
  cudfcomplex_raw const c1_ = c1;
  cudfcomplex_raw const c2_ = c2;
  cudfcomplex_raw t1_, t2_;
  cudfreal e1 = -a1_.y, e2 = -a2_.y;
  fma2( a1_.x, b1_.x, c1_.x, t1_.x,  a2_.x, b2_.x, c2_.x, t2_.x );
  fma2( a1_.x, b1_.y, c1_.y, t1_.y,  a2_.x, b2_.y, c2_.y, t2_.y );
  fma2( e1,    b1_.y, t1_.x, t1_.x,  e2,    b2_.y, t2_.x, t2_.x );
  fma2( a1_.y, b1_.x, t1_.y, t1_.y,  a2_.y, b2_.x, t2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ int
isnan ( cudfcomplex const a )
{
  cudfcomplex_raw const a_ = a;
  return (isnan(a_.x) || isnan(a_.y));
}

__host__ __device__ __forceinline__ int
isinf ( cudfcomplex const a )
{
  cudfcomplex_raw const a_ = a;
  return (isinf(a_.x) || isinf(a_.y));
}

__host__ __device__ __forceinline__ int
isfinite ( cudfcomplex const a )
{
  cudfcomplex_raw const a_ = a;
  return (isfinite(a_.x) && isfinite(a_.y));
}

__host__ __device__ __forceinline__ cudfreal
Abs ( cudfcomplex const a )
{
  cudfcomplex_raw const a_ = a;
  cudfreal const r2 = a_.x*a_.x + a_.y*a_.y;
  cudfreal const t = Sqrt( r2 );
  return t;
}

__host__ __device__ __forceinline__ cudfcomplex
Conj ( cudfcomplex const a )
{
  cudfcomplex_raw t_ = a;
  t_.x =   t_.x;
  t_.y = - t_.y;
  return t_;
}

__host__ __device__ __forceinline__ cudfcomplex
__choose__ ( bool const flag, cudfcomplex const a, cudfcomplex const b )
{
  cudfcomplex_raw const a_ = a;
  cudfcomplex_raw const b_ = b;
  cudfcomplex_raw t_;
  t_.x = __choose__( flag, a_.x, b_.x );
  t_.y = __choose__( flag, a_.y, b_.y );
  return t_;
}

#  endif
#  undef	ASPEN_DFCOMPLEX_struct_body

#endif

