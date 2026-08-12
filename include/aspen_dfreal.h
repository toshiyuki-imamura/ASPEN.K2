#ifndef ASPEN_DFREAL_H_INCLUDED
#  define ASPEN_DFREAL_H_INCLUDED		1

#  include <stdint.h>
#  include <cuComplex.h>
#  include "aspen_real.h"

#  define ASPEN_DFREAL_struct_body              \
  float x; float y

typedef struct __align__(8) {
  ASPEN_DFREAL_struct_body;
} __cudfreal_raw__;

#  ifndef __cplusplus

typedef	__cudfreal_raw__		cudfreal_raw;
typedef	__cudfreal_raw__		cudfreal;

#  else

struct __align__(8) __cudfreal__
{
 private:
  ASPEN_DFREAL_struct_body;
 public:
#    if __cplusplus >= 201103L
  __cudfreal__() = default;
#    else
  __host__ __device__ __forceinline__
    __cudfreal__() { }
#    endif
  __host__ __device__ __forceinline__
    __cudfreal__( __cudfreal_raw__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __cudfreal__ &operator= ( __cudfreal_raw__ const &h ) { x = h.x; y = h.y; return *this; }
  __host__ __device__ __forceinline__
    operator __cudfreal_raw__() const { __cudfreal_raw__ h; h.x = x; h.y = y; return h; }

  __host__ __device__ __forceinline__
    __cudfreal__( float const hi, float const err ) { x = hi; y = err; }
  __host__ __device__ __forceinline__
    __cudfreal__( float const hi ) { x = hi; y = (float)0.; }

  __host__ __device__ __forceinline__
    __cudfreal__( __cudfreal__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __cudfreal__( volatile __cudfreal__ const &h ) { x = h.x; y = h.y; }

  template < class T >
    __host__ __device__ __forceinline__
    operator T() const {
    return (T)(x);
  }

  __host__ __device__ __forceinline__
    __cudfreal_raw__ * raw( void ) { return reinterpret_cast<__cudfreal_raw__*>(this); }

  __host__ __device__ __forceinline__
    float hi(void) const {
    return x;
  }
  __host__ __device__ __forceinline__
    float err(void) const {
    return y;
  }
  __host__ __device__ __forceinline__
    float hi(const float x) {
    this->x = x; return x;
  }
  __host__ __device__ __forceinline__
    float err(const float y) {
    this->y = y; return y;
  }
};

typedef	struct __cudfreal__		cudfreal;
typedef	       __cudfreal_raw__		cudfreal_raw;


#    if GPU_ARCH>300
__device__ __forceinline__ cudfreal
__ldg ( cudfreal const * a )
{
  cudfreal * aa = (cudfreal *)a;
  float2 const * p = (reinterpret_cast<float2 *>(aa));
  float2 b = __ldg( p );
  cudfreal_raw const c = *(reinterpret_cast<cudfreal_raw *>(&b));
  return c;
}
#    endif


__host__ __device__ __forceinline__ bool
operator== ( cudfreal const a, cudfreal const b )
{
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  bool const ret = ((a_.x == b_.x) && (a_.y == b_.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator== ( float const a, cudfreal const b )
{
  cudfreal const c = __cudfreal__( a, (float)0. );
  return (c == b);
}

__host__ __device__ __forceinline__ bool
operator== ( cudfreal const a, float const b )
{
  return (b == a);
}

__host__ __device__ __forceinline__ bool
operator!= ( cudfreal const a, cudfreal const b)
{
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  bool const ret = ((a_.x != b_.x) || (a_.y != b_.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( float const a, cudfreal const b)
{
  cudfreal const c = __cudfreal__( a, (float)0. );
  return (c != b);
}

__host__ __device__ __forceinline__ bool
operator!= ( cudfreal const a, float const b)
{
  return (b != a);
}

__host__ __device__ __forceinline__ bool
operator< ( cudfreal const a, cudfreal const b)
{
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  bool ret;
  if ( a_.x == b_.x ) {
    ret = (a_.y < b_.y) ? true : false;
  } else {
    ret = (a_.x < b_.x) ? true : false;
  }
  return ret;
}

__host__ __device__ __forceinline__ bool
operator< ( float const a, cudfreal const b)
{
  cudfreal const c = __cudfreal__( a, (float)0. );
  return (c < b);
}

__host__ __device__ __forceinline__ bool
operator< ( cudfreal const a, float const b)
{
  cudfreal const c = __cudfreal__( b, (float)0. );
  return (a < c);
}

__host__ __device__ __forceinline__ bool
operator> ( cudfreal const a, cudfreal const b)
{
  return (b < a);
}

__host__ __device__ __forceinline__ bool
operator> ( float const a, cudfreal const b)
{
  return (b < a);
}

__host__ __device__ __forceinline__ bool
operator> ( cudfreal const a, float const b)
{
  return (b < a);
}

__host__ __device__ __forceinline__ bool
operator<= ( cudfreal const a, cudfreal const b)
{
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  bool ret;
  if ( a_.x == b_.x ) {
    ret = (a_.y <= b_.y) ? true : false;
  } else {
    ret = (a_.x < b_.x) ? true : false;
  }
  return ret;
}

__host__ __device__ __forceinline__ bool
operator<= ( float const a, cudfreal const b)
{
  cudfreal const c = __cudfreal__( a, (float)0. );
  return (c <= b);
}

__host__ __device__ __forceinline__ bool
operator<= ( cudfreal const a, float const b)
{
  cudfreal const c = __cudfreal__( b, (float)0. );
  return (a <= c);
}

__host__ __device__ __forceinline__ bool
operator>= ( cudfreal const a, cudfreal const b)
{
  return (b <= a);
}

__host__ __device__ __forceinline__ bool
operator>= ( float const a, cudfreal const b)
{
  return (b <= a);
}

__host__ __device__ __forceinline__ bool
operator>= ( cudfreal const a, float const b)
{
  return (b <= a);
}


__host__ __device__ __forceinline__ float
__fmad ( float const a,  float const b, float const c )
{
  return  fmaf ( a, b, c );
}


__host__ __device__ __forceinline__ void
cuTwoSum ( float const a, float const b, float &s, float &e )
{
  float const  S = __add ( a, b );
  float const  u = __sub ( S, a );
  float const  v = __sub ( S, u );
  float const  p = __sub ( a, v );
  float const  q = __sub ( b, u );
  float const  E = __add ( p, q );
  s = S; e = E;
}

__host__ __device__ __forceinline__ void
cuTwoSum2 ( float const a1, float const b1, float &s1, float &e1,
            float const a2, float const b2, float &s2, float &e2 )
{
  float const  S1 = __add ( a1, b1 );
  float const  S2 = __add ( a2, b2 );
  float const  u1 = __sub ( S1, a1 );
  float const  u2 = __sub ( S2, a2 );
  float const  v1 = __sub ( S1, u1 );
  float const  v2 = __sub ( S2, u2 );
  float const  p1 = __sub ( a1, v1 );
  float const  p2 = __sub ( a2, v2 );
  float const  q1 = __sub ( b1, u1 );
  float const  q2 = __sub ( b2, u2 );
  float const  E1 = __add ( p1, q1 );
  float const  E2 = __add ( p2, q2 );
  s1 = S1; e1 = E1;
  s2 = S2; e2 = E2;
}

__host__ __device__ __forceinline__ void
cuQuickTwoSum ( float const a, float const b, float &s, float &e )
{
  float const  S = __add ( a, b );
  float const  v = __sub ( S, a );
  float const  E = __sub ( b, v );
  s = S; e = E;
}

__host__ __device__ __forceinline__ void
cuQuickTwoSum2 ( float const a1, float const b1, float &s1, float &e1,
                 float const a2, float const b2, float &s2, float &e2 )
{
  float const  S1 = __add ( a1, b1 );
  float const  S2 = __add ( a2, b2 );
  float const  v1 = __sub ( S1, a1 );
  float const  v2 = __sub ( S2, a2 );
  float const  E1 = __sub ( b1, v1 );
  float const  E2 = __sub ( b2, v2 );
  s1 = S1; e1 = E1;
  s2 = S2; e2 = E2;
}

__host__ __device__ __forceinline__ void
cuTwoProdFMA ( float const a, float const b, float &s, float &e )
{
  float const  S = __mul ( a, b );
  float const  E = __fmad ( a, b, -S );
  s = S; e = E;
}

__host__ __device__ __forceinline__ cudfreal
CUWADD ( cudfreal const a, cudfreal const b )
{
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  cudfreal_raw t_, c_;
  cuTwoSum ( a_.x, b_.x, t_.x, t_.y );
  float const  r = __add( a_.y, b_.y );
  t_.y = __add ( t_.y, r );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cudfreal
CUwADD ( float const a, cudfreal const b )
{
  cudfreal_raw const b_ = b;
  cudfreal_raw t_, c_;
  cuTwoSum ( a, b_.x, t_.x, t_.y );
  t_.y = __add ( t_.y, b_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cudfreal
CUwADD ( cudfreal const a, float const b )
{
  cudfreal_raw const a_ = a;
  cudfreal_raw t_, c_;
  cuTwoSum ( a_.x, b, t_.x, t_.y );
  t_.y = __add ( t_.y, a_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ void
CUWADD2 ( cudfreal const a1, cudfreal const b1, cudfreal &d1,
          cudfreal const a2, cudfreal const b2, cudfreal &d2 )
{
  cudfreal_raw const a1_ = a1;
  cudfreal_raw const a2_ = a2;
  cudfreal_raw const b1_ = b1;
  cudfreal_raw const b2_ = b2;
  cudfreal_raw t1_,t2_, c1_,c2_;
  cuTwoSum2 ( a1_.x, b1_.x, t1_.x, t1_.y,
              a2_.x, b2_.x, t2_.x, t2_.y );
  float const  r1 = __add( a1_.y, b1_.y );
  float const  r2 = __add( a2_.y, b2_.y );
  t1_.y = __add ( t1_.y, r1 );
  t2_.y = __add ( t2_.y, r2 );
  cuQuickTwoSum2 ( t1_.x, t1_.y, c1_.x, c1_.y,
                   t2_.x, t2_.y, c2_.x, c2_.y );
  d1    = c1_;
  d2    = c2_;
}

__host__ __device__ __forceinline__ cudfreal
CUWSUB ( cudfreal const a, cudfreal const b )
{
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  cudfreal_raw t_, c_;
  cuTwoSum ( a_.x, -b_.x, t_.x, t_.y );
  t_.y = __add ( t_.y, __sub ( a_.y, b_.y ) );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cudfreal
CUwSUB ( float const a, cudfreal const b )
{
  cudfreal_raw const b_ = b;
  cudfreal_raw t_, c_;
  cuTwoSum ( a, -b_.x, t_.x, t_.y );
  t_.y = __sub ( t_.y, b_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cudfreal
CUwSUB ( cudfreal const a, float const b )
{
  cudfreal_raw const a_ = a;
  cudfreal_raw t_, c_;
  cuTwoSum ( a_.x, -b, t_.x, t_.y );
  t_.y = __add ( t_.y, a_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ void
CUWSUB2 ( cudfreal const a1, cudfreal const b1, cudfreal &d1,
          cudfreal const a2, cudfreal const b2, cudfreal &d2 )
{
  cudfreal_raw const a1_ = a1;
  cudfreal_raw const a2_ = a2;
  cudfreal_raw const b1_ = b1;
  cudfreal_raw const b2_ = b2;
  cudfreal_raw t1_,t2_, c1_,c2_;
  cuTwoSum ( a1_.x, -b1_.x, t1_.x, t1_.y );
  cuTwoSum ( a2_.x, -b2_.x, t2_.x, t2_.y );
  t1_.y = __add ( t1_.y, __sub ( a1_.y, b1_.y ) );
  t2_.y = __add ( t2_.y, __sub ( a2_.y, b2_.y ) );
  cuQuickTwoSum ( t1_.x, t1_.y, c1_.x, c1_.y );
  cuQuickTwoSum ( t2_.x, t2_.y, c2_.x, c2_.y );
  d1    = c1_;
  d2    = c2_;
}

__host__ __device__ __forceinline__ cudfreal
CUWMUL ( cudfreal const a, cudfreal const b )
{
#    if 0
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  float t, e;
  cudfreal_raw c_;
  cuTwoProdFMA ( a_.x, b_.x, t, e );
  e = __add ( e, __add( __mul( a_.x, b_.y ), __mul( a_.y, b_.x ) ) );
  cuQuickTwoSum ( t, e, c_.x, c_.y );
  return c_;
#    else
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  float t, e;
  cudfreal_raw c_;
  t    = __fmad ( a_.y, b_.x, __mul( a_.x, b_.y ) );
  c_.x = __fmad ( a_.x, b_.x, t );
  e    = __fmad ( a_.x, b_.x, -c_.x );
  c_.y = __add ( e, t );
  return c_;
#    endif
}

__host__ __device__ __forceinline__ cudfreal
CUwMUL ( float const a, cudfreal const b )
{
  cudfreal_raw const b_ = b;
  float t, e;
  cudfreal_raw c_;
  t    = __mul( a, b_.y );
  c_.x = __fmad ( a, b_.x, t );
  e    = __fmad ( a, b_.x, -c_.x );
  c_.y = __add ( e, t );
  return c_;
}

__host__ __device__ __forceinline__ cudfreal
CUwMUL ( cudfreal const a, float const b )
{
  cudfreal_raw const a_ = a;
  float t, e;
  cudfreal_raw c_;
  t    = __mul ( a_.y, b );
  c_.x = __fmad ( a_.x, b, t );
  e    = __fmad ( a_.x, b, -c_.x );
  c_.y = __add ( e, t );
  return c_;
}

__host__ __device__ __forceinline__ void
CUWMUL2 ( cudfreal const a1, cudfreal const b1, cudfreal &d1,
          cudfreal const a2, cudfreal const b2, cudfreal &d2 )
{
  cudfreal_raw const a1_ = a1;
  cudfreal_raw const a2_ = a2;
  cudfreal_raw const b1_ = b1;
  cudfreal_raw const b2_ = b2;
  float t1,t2, e1,e2;
  float s1,s2;
  cudfreal_raw c1_,c2_;
  s1    = __mul( a1_.x, b1_.y );
  s2    = __mul( a2_.x, b2_.y );
  t1    = __fmad ( a1_.y, b1_.x, s1 );
  t2    = __fmad ( a2_.y, b2_.x, s2 );
  c1_.x = __fmad ( a1_.x, b1_.x, t1 );
  c2_.x = __fmad ( a2_.x, b2_.x, t2 );
  s1    = -c1_.x;
  s2    = -c2_.x;
  e1    = __fmad ( a1_.x, b1_.x, s1 );
  e2    = __fmad ( a2_.x, b2_.x, s2 );
  c1_.y = __add ( e1, t1 );
  c2_.y = __add ( e2, t2 );
  d1    = c1_;
  d2    = c2_;
}


__host__ __device__ __forceinline__ cudfreal
operator+ ( cudfreal const a )
{
  return a;
}

__host__ __device__ __forceinline__ cudfreal
operator+ ( cudfreal const a, cudfreal const b )
{
  return CUWADD ( a, b );
}

__host__ __device__ __forceinline__ cudfreal
operator+ ( float const a, cudfreal const b )
{
  return CUwADD ( a, b );
}

__host__ __device__ __forceinline__ cudfreal
operator+ ( cudfreal const a, float const b )
{
  return CUwADD ( a, b );
}

__host__ __device__ __forceinline__ void
operator+= ( cudfreal &a, cudfreal const b )
{
  a = ( a + b );
}

__host__ __device__ __forceinline__ void
operator+= ( cudfreal &a, float const b )
{
  a = ( a + b );
}

__host__ __device__ __forceinline__ cudfreal
operator- ( cudfreal const a )
{
  cudfreal_raw r_ = a;
  r_.x = - r_.x;
  r_.y = - r_.y;
  return r_;
}

__host__ __device__ __forceinline__ cudfreal
operator- ( cudfreal const a, cudfreal const b )
{
  return CUWSUB ( a, b );
}

__host__ __device__ __forceinline__ cudfreal
operator- ( float const a, cudfreal const b )
{
  return CUwSUB ( a, b );
}

__host__ __device__ __forceinline__ cudfreal
operator- ( cudfreal const a, float const b )
{
  return CUwSUB ( a, b );
}

__host__ __device__ __forceinline__ void
operator-= ( cudfreal &a, cudfreal const b )
{
  a = ( a - b );
}

__host__ __device__ __forceinline__ void
operator-= ( cudfreal &a, float const b )
{
  a = ( a - b );
}

__host__ __device__ __forceinline__ cudfreal
operator* ( cudfreal const a, cudfreal const b )
{
  return CUWMUL ( a, b );
}

__host__ __device__ __forceinline__ cudfreal
operator* ( cudfreal const a, float const b )
{
  return CUwMUL ( a, b );
}

__host__ __device__ __forceinline__ cudfreal
operator* ( float const a, cudfreal const b )
{
  return CUwMUL ( a, b );
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( cudfreal &a, T const b )
{
  a = ( a * b );
}

__host__ __device__ __forceinline__ cudfreal
fma ( cudfreal const a, cudfreal const b, cudfreal const c )
{
  cudfreal const  t = (a * b) + c;
  return t;
}

__host__ __device__ __forceinline__ cudfreal
fma ( cudfreal const a, float const b, cudfreal const c )
{
  cudfreal const  t = (a * b) + c;
  return t;
}

__host__ __device__ __forceinline__ cudfreal
fma ( float const a, cudfreal const b, cudfreal const c )
{
  cudfreal const  t = (a * b) + c;
  return t;
}

__host__ __device__ __forceinline__ cudfreal
fma ( float const a, float const b, cudfreal const c )
{
  float const    ab  = a*b;
  cudfreal const ab_ = __cudfreal__( ab, fmaf(a, b, -ab) );
  cudfreal const t   = ab_ + c;
  return t;
}

__host__ __device__ __forceinline__ cudfreal
CUWDIV ( cudfreal const a, cudfreal const b )
{
  cudfreal const ZERO   = __cudfreal__( (float)0., (float)0. );
  cudfreal const ONE    = __cudfreal__( (float)1., (float)0. );
  cudfreal const MONE   = __cudfreal__( (float)-1., (float)0. );
  cudfreal const NAN_DD = __cudfreal__( (float)NAN, (float)NAN );

  if ( b == ZERO ) { return NAN_DD; }
  if ( a == ZERO ) { return ZERO; }
  if ( b == ONE  ) { return a; }
  if ( b == MONE ) { return -a; }

  /* A.H.Karp and P.Markstein:
   * High Precision Division and Square Root,
   * ATOMS, 23(4), 1997, p.561-589.
   *
   *  when x=Approx(a/b),
   *  y = b*x
   *  Y = y + x(b-a*y) = goodApprox(a/b)
   */
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = a;
  float const    xn     = a_.x / b_.x;
  cudfreal const yn     = b * xn;
  cudfreal const T      = a * yn;
  cudfreal       t      = b - T;
  t *= xn;
  cudfreal const Y      = yn + t;

  return Y;
}

__host__ __device__ __forceinline__ cudfreal
operator/ ( cudfreal const a, cudfreal const b )
{
  cudfreal const t = CUWDIV ( a, b );
  return t;
}

__host__ __device__ __forceinline__ cudfreal
operator/ ( cudfreal const a, float const b )
{
  cudfreal const c = { b, (float)0 };
  cudfreal const t = a / c;
  return t;
}

__host__ __device__ __forceinline__ cudfreal
operator/ ( cudfreal const a, int const b )
{
  float const c = (float)b;
  cudfreal const t = a / c;
  return t;
}

template < class T >
__host__ __device__ __forceinline__ void
operator/= ( cudfreal &a, const T b )
{
  a = ( a / b );
}


__host__ __device__ __forceinline__ void
add2 ( cudfreal const a1, cudfreal const b1, cudfreal &d1,
       cudfreal const a2, cudfreal const b2, cudfreal &d2 )
{
  cudfreal  t1,t2;
  CUWADD2 ( a1, b1, t1, a2, b2, t2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
sub2 ( cudfreal const a1, cudfreal const b1, cudfreal &d1,
       cudfreal const a2, cudfreal const b2, cudfreal &d2 )
{
  cudfreal  t1,t2;
  CUWSUB2 ( a1, b1, t1, a2, b2, t2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
mul2 ( cudfreal const a1, cudfreal const b1, cudfreal &d1,
       cudfreal const a2, cudfreal const b2, cudfreal &d2 )
{
  cudfreal  t1,t2;
  CUWMUL2 ( a1, b1, t1, a2, b2, t2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
fma2 ( cudfreal const a1, cudfreal const b1, cudfreal const c1, cudfreal &d1,
       cudfreal const a2, cudfreal const b2, cudfreal const c2, cudfreal &d2 )
{
  cudfreal  t1,t2;
  CUWMUL2 ( a1, b1, t1, a2, b2, t2 );
  CUWADD2 ( c1, t1, t1, c2, t2, t2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int
isnan ( cudfreal const a )
{
  cudfreal_raw const a_ = a;
  return (isnan(a_.x) || isnan(a_.y));
}

__host__ __device__ __forceinline__ int
isinf ( cudfreal const a )
{
  cudfreal_raw const a_ = a;
  return (isinf(a_.x) || isinf(a_.y));
}

__host__ __device__ __forceinline__ int
isfinite ( cudfreal const a )
{
  cudfreal_raw const a_ = a;
  return (isfinite(a_.x) && isfinite(a_.y));
}

__host__ __device__ __forceinline__ cudfreal
Abs ( cudfreal const a )
{
  cudfreal_raw const a_ = a;
  cudfreal_raw r_;
  r_.x = fabs(a_.x);
  r_.y = fabs(a_.y);
  return r_;
}

__host__ __device__ __forceinline__ cudfreal
Conj ( cudfreal const a )
{
  return a;
}


__host__ __device__ __forceinline__ cudfreal
Sqrt ( cudfreal const a )
{
  cudfreal const ZERO   = __cudfreal__( (float)0., (float)0. );
  cudfreal const NAN_DD = __cudfreal__( (float)NAN, (float)NAN );

  if ( a == ZERO ) { return a; };
  if ( a < ZERO ) { return NAN_DD; }

  /* A.H.Karp and P.Markstein:
   * High Precision Division and Square Root,
   * ATOMS, 23(4), 1997, p.561-589.
   *
   *  when x=Approx(1/sqrt(a)),
   *  y = a*x
   *  Y = y + (x/2)(a-y^2) = goodApprox(sqrt(a))
   */
  cudfreal_raw const a_ = a;
  float          xn     = (float)1. / sqrt(a_.x);
  cudfreal const yn     = a * xn;
  cudfreal const T      = yn * yn;
  cudfreal       t      = a - T;
  xn /= 2; t *= xn;
  cudfreal const Y      = yn + t;

  return Y;
}

__host__ __device__ __forceinline__ cudfreal
__choose__ ( bool const flag, cudfreal const a, cudfreal const b )
{
  cudfreal_raw const a_ = a;
  cudfreal_raw const b_ = b;
  cudfreal_raw r_;
  r_.x = __choose__( flag, a_.x, b_.x );
  r_.y = __choose__( flag, a_.y, b_.y );
  return r_;
}

#  endif
#  undef ASPEN_DFREAL_struct_body

#endif

