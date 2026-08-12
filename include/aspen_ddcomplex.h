#ifndef ASPEN_DDCOMPLEX_H_INCLUDED
#  define ASPEN_DDCOMPLEX_H_INCLUDED		1

#  include <stdint.h>
#  include <cuComplex.h>
#  include "aspen_ddreal.h"

#  define	ASPEN_DDCOMPLEX_struct_body     \
  cuddreal x; cuddreal y

typedef struct __align__(16) {
  ASPEN_DDCOMPLEX_struct_body;
} __cuddcomplex_raw__;

#  ifndef __cplusplus

typedef	__cuddcomplex_raw__	cuddcomplex_raw;
typedef	__cuddcomplex_raw__	cuddcomplex;

#  else

struct __align__(16) __cuddcomplex__
{
 private:
  ASPEN_DDCOMPLEX_struct_body;
 public:
#    if __cplusplus >= 201103L
  __cuddcomplex__() = default;
#    else
  __host__ __device__ __forceinline__
    __cuddcomplex__() { }
#    endif
  __host__ __device__ __forceinline__
    __cuddcomplex__( __cuddcomplex_raw__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __cuddcomplex__ &operator= ( __cuddcomplex_raw__ const &h ) { x = h.x; y = h.y; return *this; }
  __host__ __device__ __forceinline__
    operator __cuddcomplex_raw__() const { __cuddcomplex_raw__ h; h.x = x; h.y = y; return h; }

  __host__ __device__ __forceinline__
    __cuddcomplex__( cuddreal const &a, cuddreal const &b ) { x = a; y = b; }

  __host__ __device__ __forceinline__
    __cuddcomplex_raw__ * raw( void ) { return reinterpret_cast<__cuddcomplex_raw__*>(this); }

  __host__ __device__ __forceinline__
    operator cuddreal() const {
    return x;
  }

  __host__ __device__ __forceinline__
    operator cuDoubleComplex() const {
    cuddreal_raw const x_ = x;
    cuddreal_raw const y_ = y;
    cuDoubleComplex const t = { x_.x, y_.x };
    return t;
  }

  __host__ __device__ __forceinline__
    cuddreal real() const {
    return x;
  }
  __host__ __device__ __forceinline__
    cuddreal imag() const {
    return y;
  }
  __host__ __device__ __forceinline__
    cuddreal real( cuddreal const x) {
    this->x = x; return x;
  }
  __host__ __device__ __forceinline__
    cuddreal imag( cuddreal const y) {
    this->y = y; return y;
  }
};

typedef	struct __cuddcomplex__		cuddcomplex;
typedef	       __cuddcomplex_raw__	cuddcomplex_raw;


#    if GPU_ARCH>300
__device__ __forceinline__ cuddcomplex
__ldg ( cuddcomplex const * a )
{
  cuddcomplex * aa = (cuddcomplex *)a;
  cuddcomplex_raw * p_ = (reinterpret_cast<cuddcomplex_raw *>(aa));
  cuddcomplex_raw t_;
  t_.x = __ldg( (cuddreal *)&(p_->x) );
  t_.y = __ldg( (cuddreal *)&(p_->y) );
  return t_;
}
#    endif


__host__ __device__ __forceinline__ cuddreal
get_real( cuddcomplex &a )
{ return a.real(); }

__host__ __device__ __forceinline__ cuddreal
get_imag( cuddcomplex &a )
{ return a.imag(); }

__host__ __device__ __forceinline__ void
set_real( cuddcomplex &a, cuddreal const x )
{ a.real( x ); }

__host__ __device__ __forceinline__ void
set_imag( cuddcomplex &a, cuddreal const y )
{ a.imag( y ); }


__host__ __device__ __forceinline__ bool
operator== ( cuddcomplex const a, cuddcomplex const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;
  bool const ret = ((a_.x == b_.x) && (a_.y == b_.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( cuddcomplex const a, cuddcomplex const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;
  bool const ret = ((a_.x != b_.x) || (a_.y != b_.y)) ? true : false;
  return ret;
}


__host__ __device__ __forceinline__ cuddcomplex
operator+ ( cuddcomplex const a )
{
  return (a);
}

__host__ __device__ __forceinline__ cuddcomplex
operator+ ( cuddcomplex const a, cuddcomplex const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;
  cuddcomplex_raw t_;
  add2 ( a_.x, b_.x, t_.x,  a_.y, b_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
operator+ ( cuddcomplex const a, cuddreal const b )
{
  cuddcomplex_raw const a_ = a;
  cuddreal_raw const b_ = b;
  cuddcomplex_raw t_ = { a_.x + b_, a_.y };
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
operator+ ( cuddreal const a, cuddcomplex const b )
{
  cuddreal const    a_ = a;
  cuddcomplex const b_ = b;
  return (b_ + a_);
}

__host__ __device__ __forceinline__ cuddcomplex
operator+ ( cuddcomplex const a, double const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw t_ = { a_.x + b, a_.y };
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
operator+ ( double const a, cuddcomplex const b )
{
  double const      a_ = a;
  cuddcomplex const b_ = b;
  return (b_ + a_);
}


template < class T >
__host__ __device__ __forceinline__ void
operator+= ( cuddcomplex &a, T const b )
{
  a = (a + b);
}

__host__ __device__ __forceinline__ cuddcomplex
operator- ( cuddcomplex const a )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw t_ = a_;
  t_.x = - t_.x;
  t_.y = - t_.y;
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
operator- ( cuddcomplex const a, cuddcomplex const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;
  cuddcomplex_raw t_;
  sub2 ( a_.x, b_.x, t_.x,  a_.y, b_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ void
operator-= ( cuddcomplex &a, cuddcomplex const b )
{
  a = (a - b);
}

__host__ __device__ __forceinline__ cuddcomplex
operator* ( cuddcomplex const a, cuddcomplex const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;
  cuddcomplex_raw t_;
  cuddreal e = -a_.y;
  mul2 ( a_.x, b_.x, t_.x,  a_.x, b_.y, t_.y );
  fma2 ( e,    b_.y, t_.x, t_.x,  a_.y, b_.x, t_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
operator* ( cuddcomplex const a, cuddreal const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw t_;
  mul2 ( a_.x, b, t_.x,  a_.y, b, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
operator* ( cuddreal const a, cuddcomplex const b )
{
  cuddreal const    a_ = a;
  cuddcomplex const b_ = b;
  return ( b_ * a_ );
}

__host__ __device__ __forceinline__ cuddcomplex
operator* ( cuddcomplex const a, double const b )
{
  cuddcomplex_raw const a_ = a;
  return (cuddcomplex) { a_.x * b, a_.y * b };
}

__host__ __device__ __forceinline__ cuddcomplex
operator* ( double const a, cuddcomplex const b )
{
  double const      a_ = a;
  cuddcomplex const b_ = b;
  return ( b_ * a_ );
}

__host__ __device__ __forceinline__ cuddcomplex
operator* ( cuddcomplex const a, int const b )
{
  cuddcomplex_raw const a_ = a;
  double const c = (double)b;
  return (cuddcomplex) { a_.x * c, a_.y * c };
}

__host__ __device__ __forceinline__ cuddcomplex
operator* ( int const a, cuddcomplex const b )
{
  int const         a_ = a;
  cuddcomplex const b_ = b;
  return ( b_ * a_ );
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( cuddcomplex &a, T const b )
{
  a = ( a * b );
}

__host__ __device__ __forceinline__ cuddcomplex
fma ( cuddcomplex const a, cuddcomplex const b, cuddcomplex const c )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;
  cuddcomplex_raw const c_ = c;
  cuddcomplex_raw t_;
  cuddreal e = -a_.y;
  fma2 ( a_.x, b_.x, c_.x, t_.x,  a_.x, b_.y, c_.y, t_.y );
  fma2 ( e,    b_.y, t_.x, t_.x,  a_.y, b_.x, t_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
fma ( cuddcomplex const a, cuddreal const b, cuddcomplex const c )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const c_ = c;
  cuddcomplex_raw t_;
  fma2 ( a_.x, b, c_.x, t_.x,  a_.y, b, c_.y, t_.y );
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
fma ( cuddreal const a, cuddcomplex const b, cuddcomplex const c )
{
  cuddcomplex t = fma( b, a, c );
  return t;
}

__host__ __device__ __forceinline__ cuddcomplex
CUWDIV ( cuddcomplex const a, cuddcomplex const b )
{
  /*
   * almost similar approach to divide a complex number as cuComplex.h
   */
  cuddreal const     ZERO_   = __cuddreal__( (double)0, (double)0 );
  cuddcomplex const  ZERO    = __cuddcomplex__( ZERO_, ZERO_ );
  cuddreal const     NAN_DD  = __cuddreal__( NAN, NAN );
  cuddcomplex const  NAN_DDC = __cuddcomplex__( NAN_DD, NAN_DD );
  cuddreal const     ONE_    = __cuddreal__( (double)1, (double)0 );
  cuddcomplex const  ONE     = __cuddcomplex__( ONE_, ZERO_ );
  cuddreal const     MONE_   = __cuddreal__( (double)1, (double)0 );
  cuddcomplex const  MONE    = __cuddcomplex__( MONE_, ZERO_ );

  if ( b == ZERO ) { return NAN_DDC; }
  if ( a == ZERO ) { return ZERO; }
  if ( b == ONE  ) { return a; }
  if ( b == MONE ) { return -a; }

  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;

  cuddreal s = Abs(b_.x) + Abs(b_.y);
  cuddreal r = ONE_ / s;
  cuddreal const ar = a_.x * r;
  cuddreal const ai = a_.y * r;
  cuddreal const br = b_.x * r;
  cuddreal const bi = b_.y * r;
  s = (br * br) + (bi * bi);
  r = ONE_ / s;
  cuddcomplex const t = __cuddcomplex__(
                                        ((ar * br) + (ai * bi)) * r,
                                        ((ai * br) - (ar * bi)) * r );
  return t;
}

__host__ __device__ __forceinline__ cuddcomplex
operator/ ( cuddcomplex const a, cuddcomplex const b )
{
  cuddcomplex const t = CUWDIV ( a, b );
  return t;
}

__host__ __device__ __forceinline__ cuddcomplex
operator/ ( cuddcomplex const a, cuddreal const b )
{
  cuddreal const z = { 0, 0 };
  cuddcomplex const c = { b, z };
  return ( a / c );
}

__host__ __device__ __forceinline__ cuddcomplex
operator/ ( cuddcomplex const a, double const b )
{
  cuddreal const c = { b, 0 };
  return ( a / c );
}

__host__ __device__ __forceinline__ cuddcomplex
operator/ ( cuddcomplex const a, int const b )
{
  double const c = (double)b;
  return ( a / c );
}

template < class T >
__host__ __device__ __forceinline__ void
operator/= ( cuddcomplex &a, T const b )
{
  a = ( a / b );
}


__host__ __device__ __forceinline__ void
add2 ( cuddcomplex const a1, cuddcomplex const b1, cuddcomplex &d1,
       cuddcomplex const a2, cuddcomplex const b2, cuddcomplex &d2 )
{
  cuddcomplex_raw const a1_ = a1;
  cuddcomplex_raw const a2_ = a2;
  cuddcomplex_raw const b1_ = b1;
  cuddcomplex_raw const b2_ = b2;
  cuddcomplex_raw t1_, t2_;
  add2 ( a1_.x, b1_.x, t1_.x,  a2_.x, b2_.x, t2_.x );
  add2 ( a1_.y, b1_.y, t1_.y,  a2_.y, b2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ void
sub2 ( cuddcomplex const a1, cuddcomplex const b1, cuddcomplex &d1,
       cuddcomplex const a2, cuddcomplex const b2, cuddcomplex &d2 )
{
  cuddcomplex_raw const a1_ = a1;
  cuddcomplex_raw const a2_ = a2;
  cuddcomplex_raw const b1_ = b1;
  cuddcomplex_raw const b2_ = b2;
  cuddcomplex_raw t1_, t2_;
  sub2 ( a1_.x, b1_.x, t1_.x,  a2_.x, b2_.x, t2_.x );
  sub2 ( a1_.y, b1_.y, t1_.y,  a2_.y, b2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ void
mul2 ( cuddcomplex const a1, cuddcomplex const b1, cuddcomplex &d1,
       cuddcomplex const a2, cuddcomplex const b2, cuddcomplex &d2 )
{
  cuddcomplex_raw const a1_ = a1;
  cuddcomplex_raw const a2_ = a2;
  cuddcomplex_raw const b1_ = b1;
  cuddcomplex_raw const b2_ = b2;
  cuddcomplex_raw t1_, t2_;
  cuddreal e1 = -a1_.y, e2 = -a2_.y;
  mul2 ( a1_.x, b1_.x, t1_.x,  a2_.x, b2_.x, t2_.x );
  mul2 ( a1_.x, b1_.y, t1_.y,  a2_.x, b2_.y, t2_.y );
  fma2 ( e1,    b1_.y, t1_.x, t1_.x,  e2,    b1_.y, t2_.x, t2_.x );
  fma2 ( a1_.y, b1_.x, t1_.y, t1_.y,  a2_.y, b1_.x, t2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ void
fma2 ( cuddcomplex const a1, cuddcomplex const b1, cuddcomplex const c1, cuddcomplex &d1,
       cuddcomplex const a2, cuddcomplex const b2, cuddcomplex const c2, cuddcomplex &d2 )
{
  cuddcomplex_raw const a1_ = a1;
  cuddcomplex_raw const a2_ = a2;
  cuddcomplex_raw const b1_ = b1;
  cuddcomplex_raw const b2_ = b2;
  cuddcomplex_raw const c1_ = c1;
  cuddcomplex_raw const c2_ = c2;
  cuddcomplex_raw t1_, t2_;
  cuddreal e1 = -a1_.y, e2 = -a2_.y;
  fma2( a1_.x, b1_.x, c1_.x, t1_.x,  a2_.x, b2_.x, c2_.x, t2_.x );
  fma2( a1_.x, b1_.y, c1_.y, t1_.y,  a2_.x, b2_.y, c2_.y, t2_.y );
  fma2( e1,    b1_.y, t1_.x, t1_.x,  e2,    b2_.y, t2_.x, t2_.x );
  fma2( a1_.y, b1_.x, t1_.y, t1_.y,  a2_.y, b2_.x, t2_.y, t2_.y );
  d1 = t1_; d2 = t2_;
}

__host__ __device__ __forceinline__ int
isnan ( cuddcomplex const a )
{
  cuddcomplex_raw const a_ = a;
  return (isnan(a_.x) || isnan(a_.y));
}

__host__ __device__ __forceinline__ int
isinf ( cuddcomplex const a )
{
  cuddcomplex_raw const a_ = a;
  return (isinf(a_.x) || isinf(a_.y));
}

__host__ __device__ __forceinline__ int
isfinite ( cuddcomplex const a )
{
  cuddcomplex_raw const a_ = a;
  return (isfinite(a_.x) && isfinite(a_.y));
}

__host__ __device__ __forceinline__ cuddreal
Abs ( cuddcomplex const a )
{
  cuddcomplex_raw const a_ = a;
  cuddreal const r2 = a_.x*a_.x + a_.y*a_.y;
  cuddreal const t = Sqrt( r2 );
  return t;
}

__host__ __device__ __forceinline__ void
makeConj ( cuddcomplex & a )
{
  set_imag(a, -get_imag(a));
}

__host__ __device__ __forceinline__ cuddcomplex
Conj ( cuddcomplex const a )
{
  cuddcomplex_raw t_ = a;
  t_.x =   t_.x;
  t_.y = - t_.y;
  return t_;
}

__host__ __device__ __forceinline__ cuddcomplex
__choose__ ( bool const flag, cuddcomplex const a, cuddcomplex const b )
{
  cuddcomplex_raw const a_ = a;
  cuddcomplex_raw const b_ = b;
  cuddcomplex_raw t_;
  t_.x = __choose__( flag, a_.x, b_.x );
  t_.y = __choose__( flag, a_.y, b_.y );
  return t_;
}

#  endif
#  undef	ASPEN_DDCOMPLEX_struct_body

#endif

