#ifndef ASPEN_DDREAL_H_INCLUDED
#  define ASPEN_DDREAL_H_INCLUDED		1

#  include <stdint.h>
#  include <cuComplex.h>
#  include "aspen_real.h"

#  define ASPEN_DDREAL_struct_body              \
  double x; double y

typedef struct __align__(16) {
  ASPEN_DDREAL_struct_body;
} __cuddreal_raw__;

#  ifndef __cplusplus

typedef	__cuddreal_raw__	cuddreal_raw;
typedef	__cuddreal_raw__	cuddreal;

#  else

struct __align__(16) __cuddreal__
{
 private:
  ASPEN_DDREAL_struct_body;
 public:
#    if __cplusplus >= 201103L
  __cuddreal__() = default;
#    else
  __host__ __device__ __forceinline__
    __cuddreal__() { }
#    endif
  __host__ __device__ __forceinline__
    __cuddreal__( __cuddreal_raw__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __cuddreal__ &operator= ( __cuddreal_raw__ const &h ) { x = h.x; y = h.y; return *this; }
  __host__ __device__ __forceinline__
    __cuddreal__ &operator= ( volatile __cuddreal_raw__ const &h ) { x = h.x; y = h.y; return *this; }
  __host__ __device__ __forceinline__
    operator __cuddreal_raw__() const { __cuddreal_raw__ h; h.x = x; h.y = y; return h; }

  __host__ __device__ __forceinline__
    __cuddreal__( double const hi, double const err ) { x = hi; y = err; }
  __host__ __device__ __forceinline__
    __cuddreal__( double const hi ) { x = hi; y = (double)0.; }

  __host__ __device__ __forceinline__
    __cuddreal__( __cuddreal__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __cuddreal__( volatile __cuddreal__ const &h ) { x = h.x; y = h.y; }

  template < class T >
    __host__ __device__ __forceinline__
    operator T( ) const {
    return (T)(x);
  }

  __host__ __device__ __forceinline__
    __cuddreal_raw__ * raw( void ) { return reinterpret_cast<__cuddreal_raw__*>(this); }

  __host__ __device__ __forceinline__
    double hi( void ) const {
    return x;
  }
  __host__ __device__ __forceinline__
    double err( void ) const {
    return y;
  }
  __host__ __device__ __forceinline__
    double hi( double const x ) {
    this->x = x; return x;
  }
  __host__ __device__ __forceinline__
    double err( double const y ) {
    this->y = y; return y;
  }
};

typedef	struct __cuddreal__		cuddreal;
typedef	       __cuddreal_raw__		cuddreal_raw;


#    if GPU_ARCH>300
__device__ __forceinline__ cuddreal
__ldg ( cuddreal const * a )
{
  cuddreal * aa = (cuddreal *)a;
  double2 const * p = (reinterpret_cast<double2 *>(aa));
  double2 b = __ldg( p );
  cuddreal_raw const c = *(reinterpret_cast<cuddreal_raw *>(&b));
  return c;
}
#    endif


__host__ __device__ __forceinline__ bool
operator== ( cuddreal const a, cuddreal const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  bool const ret = ((a_.x == b_.x) && (a_.y == b_.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator== ( double const a, cuddreal const b )
{
  cuddreal const c = __cuddreal__( a, (double)0. );
  return (c == b);
}

__host__ __device__ __forceinline__ bool
operator== ( cuddreal const a, double const b )
{
  return (b == a);
}

__host__ __device__ __forceinline__ bool
operator!= ( cuddreal const a, cuddreal const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  bool const ret = ((a_.x != b_.x) || (a_.y != b_.y)) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( double const a, cuddreal const b )
{
  cuddreal const c = __cuddreal__( a, (double)0. );
  return (c != b);
}

__host__ __device__ __forceinline__ bool
operator!= ( cuddreal const a, double const b )
{
  return (b != a);
}

__host__ __device__ __forceinline__ bool
operator< ( cuddreal const a, cuddreal const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  bool ret;
  if ( a_.x == b_.x ) {
    ret = (a_.y < b_.y) ? true : false;
  } else {
    ret = (a_.x < b_.x) ? true : false;
  }
  return ret;
}

__host__ __device__ __forceinline__ bool
operator< ( double const a, cuddreal const b )
{
  cuddreal const c = __cuddreal__( a, (double)0. );
  return (c < b);
}

__host__ __device__ __forceinline__ bool
operator< ( cuddreal const a, double const b )
{
  cuddreal const c = __cuddreal__( b, (double)0. );
  return (a < c);
}

__host__ __device__ __forceinline__ bool
operator> ( cuddreal const a, cuddreal const b )
{
  return (b < a);
}

__host__ __device__ __forceinline__ bool
operator> ( double const a, cuddreal const b )
{
  return (b < a);
}

__host__ __device__ __forceinline__ bool
operator> ( cuddreal const a, double const b )
{
  return (b < a);
}

__host__ __device__ __forceinline__ bool
operator<= ( cuddreal const a, cuddreal const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  bool ret;
  if ( a_.x == b_.x ) {
    ret = (a_.y <= b_.y) ? true : false;
  } else {
    ret = (a_.x < b_.x) ? true : false;
  }
  return ret;
}

__host__ __device__ __forceinline__ bool
operator<= ( double const a, cuddreal const b )
{
  cuddreal const c = __cuddreal__( a, (double)0. );
  return (c <= b);
}

__host__ __device__ __forceinline__ bool
operator<= ( cuddreal const a, double const b )
{
  cuddreal const c = __cuddreal__( b, (double)0. );
  return (a <= c);
}

__host__ __device__ __forceinline__ bool
operator>= ( cuddreal const a, cuddreal const b )
{
  return (b <= a);
}

__host__ __device__ __forceinline__ bool
operator>= ( double const a, cuddreal const b )
{
  return (b <= a);
}

__host__ __device__ __forceinline__ bool
operator>= ( cuddreal const a, double const b )
{
  return (b <= a);
}


__host__ __device__ __forceinline__ double
__fmad ( double const a,  double const b, double const c )
{
  return  fma ( a, b, c );
}


__host__ __device__ __forceinline__ void
cuTwoSum ( double const a, double const b, double &s, double &e )
{
  double const  S = __add ( a, b );
  double const  u = __sub ( S, a );
  double const  v = __sub ( S, u );
  double const  p = __sub ( a, v );
  double const  q = __sub ( b, u );
  double const  E = __add ( p, q );
  s = S; e = E;
}

__host__ __device__ __forceinline__ void
cuTwoSum2 ( double const a1, double const b1, double &s1, double &e1,
            double const a2, double const b2, double &s2, double &e2 )
{
  double const  S1 = __add ( a1, b1 );
  double const  S2 = __add ( a2, b2 );
  double const  u1 = __sub ( S1, a1 );
  double const  u2 = __sub ( S2, a2 );
  double const  v1 = __sub ( S1, u1 );
  double const  v2 = __sub ( S2, u2 );
  double const  p1 = __sub ( a1, v1 );
  double const  p2 = __sub ( a2, v2 );
  double const  q1 = __sub ( b1, u1 );
  double const  q2 = __sub ( b2, u2 );
  double const  E1 = __add ( p1, q1 );
  double const  E2 = __add ( p2, q2 );
  s1 = S1; e1 = E1;
  s2 = S2; e2 = E2;
}

__host__ __device__ __forceinline__ void
cuQuickTwoSum ( double const a, double const b, double &s, double &e )
{
  double const  S = __add ( a, b );
  double const  v = __sub ( S, a );
  double const  E = __sub ( b, v );
  s = S; e = E;
}

__host__ __device__ __forceinline__ void
cuQuickTwoSum2 ( double const a1, double const b1, double &s1, double &e1,
                 double const a2, double const b2, double &s2, double &e2 )
{
  double const  S1 = __add ( a1, b1 );
  double const  S2 = __add ( a2, b2 );
  double const  v1 = __sub ( S1, a1 );
  double const  v2 = __sub ( S2, a2 );
  double const  E1 = __sub ( b1, v1 );
  double const  E2 = __sub ( b2, v2 );
  s1 = S1; e1 = E1;
  s2 = S2; e2 = E2;
}

__host__ __device__ __forceinline__ void
cuTwoProdFMA ( double const a, double const b, double &s, double &e )
{
  double const  S = __mul ( a, b );
  double const  E = __fmad ( a, b, -S );
  s = S; e = E;
}

__host__ __device__ __forceinline__ cuddreal
CUWADD ( cuddreal const a, cuddreal const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  cuddreal_raw t_, c_;
  cuTwoSum ( a_.x, b_.x, t_.x, t_.y );
  double const  r = __add ( a_.y, b_.y );
  t_.y = __add ( t_.y, r );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cuddreal
CUwADD ( double const a, cuddreal const b )
{
  cuddreal_raw const b_ = b;
  cuddreal_raw t_, c_;
  cuTwoSum ( a, b_.x, t_.x, t_.y );
  t_.y = __add ( t_.y, b_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cuddreal
CUwADD ( cuddreal const a, double const b )
{
#    if 0
  cuddreal_raw const a_ = a;
  cuddreal_raw t_, c_;
  cuTwoSum ( a_.x, b, t_.x, t_.y );
  t_.y = __add ( t_.y, a_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
#    else
  return CUwADD ( b, a );
#    endif
}

__host__ __device__ __forceinline__ void
CUWADD2 ( cuddreal const a1, cuddreal const b1, cuddreal &d1,
          cuddreal const a2, cuddreal const b2, cuddreal &d2 )
{
  cuddreal_raw const a1_ = a1;
  cuddreal_raw const a2_ = a2;
  cuddreal_raw const b1_ = b1;
  cuddreal_raw const b2_ = b2;
  cuddreal_raw t1_,t2_, c1_,c2_;
  cuTwoSum2 ( a1_.x, b1_.x, t1_.x, t1_.y,
              a2_.x, b2_.x, t2_.x, t2_.y );
  double const  r1 = __add ( a1_.y, b1_.y );
  double const  r2 = __add ( a2_.y, b2_.y );
  t1_.y = __add ( t1_.y, r1 );
  t2_.y = __add ( t2_.y, r2 );
  cuQuickTwoSum2 ( t1_.x, t1_.y, c1_.x, c1_.y,
                   t2_.x, t2_.y, c2_.x, c2_.y );
  d1    = c1_;
  d2    = c2_;
}

__host__ __device__ __forceinline__ cuddreal
CUWSUB ( cuddreal const a, cuddreal const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  cuddreal_raw t_, c_;
  cuTwoSum ( a_.x, -b_.x, t_.x, t_.y );
  double const  r = __sub ( a_.y, b_.y );
  t_.y = __add ( t_.y, r );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cuddreal
CUwSUB ( double const a, cuddreal const b )
{
  cuddreal_raw const b_ = b;
  cuddreal_raw t_, c_;
  cuTwoSum ( a, -b_.x, t_.x, t_.y );
  t_.y = __sub ( t_.y, b_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ cuddreal
CUwSUB ( cuddreal const a, double const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw t_, c_;
  cuTwoSum ( a_.x, -b, t_.x, t_.y );
  t_.y = __add ( t_.y, a_.y );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
}

__host__ __device__ __forceinline__ void
CUWSUB2 ( cuddreal const a1, cuddreal const b1, cuddreal &d1,
          cuddreal const a2, cuddreal const b2, cuddreal &d2 )
{
  cuddreal_raw const a1_ = a1;
  cuddreal_raw const a2_ = a2;
  cuddreal_raw const b1_ = b1;
  cuddreal_raw const b2_ = b2;
  cuddreal_raw t1_,t2_, c1_,c2_;
  cuTwoSum ( a1_.x, -b1_.x, t1_.x, t1_.y );
  cuTwoSum ( a2_.x, -b2_.x, t2_.x, t2_.y );
  double const  r1 = __sub ( a1_.y, b1_.y );
  double const  r2 = __sub ( a2_.y, b2_.y );
  t1_.y = __add ( t1_.y, r1 );
  t2_.y = __add ( t2_.y, r2 );
  cuQuickTwoSum ( t1_.x, t1_.y, c1_.x, c1_.y );
  cuQuickTwoSum ( t2_.x, t2_.y, c2_.x, c2_.y );
  d1    = c1_;
  d2    = c2_;
}

__host__ __device__ __forceinline__ cuddreal
CUWMUL ( cuddreal const a, cuddreal const b )
{
#    if 0
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  double t, e;
  cuddreal_raw c_;
  cuTwoProdFMA ( a_.x, b_.x, t, e ); // 3
  e = __add ( e, __add( __mul( a_.x, b_.y ), __mul( a_.y, b_.x ) ) ); // 4
  cuQuickTwoSum ( t, e, c_.x, c_.y ); // 3
  return c_;
#    else
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  double s, t, d, e;
  cuddreal_raw t_, c_;

  cuTwoProdFMA ( a_.x, b_.y, s, e ); // 3
  t    = __fmad ( a_.y, b_.x, e ); // 1
  d    = __add ( t, s ); // 1
  cuTwoProdFMA ( a_.x, b_.x, t_.x, e ); // 3
  t_.y = __add ( e, d ); // 1
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y ); // 3
  return c_;
#    endif
}

__host__ __device__ __forceinline__ cuddreal
CUwMUL ( double const a, cuddreal const b )
{
  cuddreal_raw const b_ = b;
  cuddreal_raw t_, c_;
#    if 0
  double t, e;
  t    = __mul ( a, b_.y );
  t_.x = __fmad ( a, b_.x, t );
  e    = __fmad ( a, b_.x, -t_.x );
  t_.y = __add ( e, t );
#    else
  double e;
  cuTwoProdFMA ( a, b_.x, t_.x, e ); // 3
  t_.y = __fmad ( a, b_.y, e ); // 1
#    endif

  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y ); // 3
  return c_;
}

__host__ __device__ __forceinline__ cuddreal
CUwMUL ( cuddreal const a, double const b )
{
#    if 0
  cuddreal_raw const a_ = a;
  double t, e;
  cuddreal_raw t_, c_;
  t    = __mul ( a_.y, b );
  t_.x = __fmad ( a_.x, b, t );
  e    = __fmad ( a_.x, b, -t_.x );
  t_.y = __add ( e, t );
  cuQuickTwoSum ( t_.x, t_.y, c_.x, c_.y );
  return c_;
#    else
  return CUwMUL ( b, a );
#    endif
}

__host__ __device__ __forceinline__ void
CUWMUL2 ( cuddreal const a1, cuddreal const b1, cuddreal &c1,
          cuddreal const a2, cuddreal const b2, cuddreal &c2 )
{
  cuddreal_raw const a1_ = a1;
  cuddreal_raw const a2_ = a2;
  cuddreal_raw const b1_ = b1;
  cuddreal_raw const b2_ = b2;
  double s1,s2, t1,t2;
  double d1,d2, e1,e2;
  cuddreal_raw t1_,t2_,c1_,c2_;

  cuTwoProdFMA ( a1_.x, b1_.y, s1, e1 ); // 3
  cuTwoProdFMA ( a2_.x, b2_.y, s2, e2 ); // 3
  t1   = __fmad ( a1_.y, b1_.x, e1 ); // 1
  t2   = __fmad ( a2_.y, b2_.x, e2 ); // 1
  d1   = __add ( t1, s1 ); // 1
  d2   = __add ( t2, s2 ); // 1
  cuTwoProdFMA ( a1_.x, b1_.x, t1_.x, e1 ); // 3
  cuTwoProdFMA ( a2_.x, b2_.x, t2_.x, e2 ); // 3

  t1_.y = __add ( e1, d1 ); // 1
  t2_.y = __add ( e2, d2 ); // 1

  cuQuickTwoSum ( t1_.x, t1_.y, c1_.x, c1_.y ); // 3
  cuQuickTwoSum ( t2_.x, t2_.y, c2_.x, c2_.y ); // 3
  c1    = c1_;
  c2    = c2_;
}


__host__ __device__ __forceinline__ cuddreal
operator+ ( cuddreal const a )
{
  return a;
}

__host__ __device__ __forceinline__ cuddreal
operator+ ( cuddreal const a, cuddreal const b )
{
  return CUWADD ( a, b );
}

__host__ __device__ __forceinline__ cuddreal
operator+ ( double const a, cuddreal const b )
{
  return CUwADD ( a, b );
}

__host__ __device__ __forceinline__ cuddreal
operator+ ( cuddreal const a, double const b )
{
  return CUwADD ( a, b );
}

template < class T >
__host__ __device__ __forceinline__ void
operator+= ( cuddreal &a, const T b )
{
  a = ( a + b );
}

__host__ __device__ __forceinline__ cuddreal
operator- ( cuddreal const a )
{
  cuddreal_raw r_ = a;
  r_.x = - r_.x;
  r_.y = - r_.y;
  return r_;
}

__host__ __device__ __forceinline__ cuddreal
operator- ( cuddreal const a, cuddreal const b )
{
  return CUWSUB ( a, b );
}

__host__ __device__ __forceinline__ cuddreal
operator- ( double const a, cuddreal const b )
{
  return CUwSUB ( a, b );
}

__host__ __device__ __forceinline__ cuddreal
operator- ( cuddreal const a, double const b )
{
  return CUwSUB ( a, b );
}

__host__ __device__ __forceinline__ void
operator-= ( cuddreal &a, cuddreal const b )
{
  a = ( a - b );
}

__host__ __device__ __forceinline__ void
operator-= ( cuddreal &a, double const b )
{
  a = ( a - b );
}

__host__ __device__ __forceinline__ cuddreal
operator* ( cuddreal const a, cuddreal const b )
{
  return CUWMUL ( a, b );
}

__host__ __device__ __forceinline__ cuddreal
operator* ( cuddreal const a, double const b )
{
  return CUwMUL ( a, b );
}

__host__ __device__ __forceinline__ cuddreal
operator* ( double const a, cuddreal const b )
{
  double const a_ = a;
  cuddreal const b_ = b;
  return ( b_ * a_ );
}

__host__ __device__ __forceinline__ cuddreal
operator* ( cuddreal const a, int const b )
{
  double const c = (double)b;
  return ( a * c );
}

__host__ __device__ __forceinline__ cuddreal
operator* ( int const a, cuddreal const b )
{
  int const a_ = a;
  cuddreal const b_ = b;
  return ( b_ * a_ );
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( cuddreal &a, T const b )
{
  a = ( a * b );
}

__host__ __device__ __forceinline__ cuddreal
fma ( cuddreal const a, cuddreal const b, cuddreal const c )
{
  // this fma does not perform in the sense of Fused Multiply-and-Add
  // just work on a simple MADD = Multiply and Add with a dd sense.
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  double s, t, d, e;
  cuddreal_raw t_, c_;

  cuTwoProdFMA ( a_.x, b_.y, s, e );    // a.x*b.y = [s,e] // 3
  t    = __fmad ( a_.y, b_.x, e );      // [a.y*b.x] + e -> t // 1
  d    = __add ( t, s );                // t + s -> d // 1
  cuTwoProdFMA ( a_.x, b_.x, t_.x, e ); // a.x*b.x = [t_.x,e] // 3
  t_.y = __add ( e, d );                // e + d -> t_.y // 1

  c_ = t_ + c; // [t_.x, t_y] + [c.x,c.y] -> [c_.x,c_.y]
  return c_;
}

__host__ __device__ __forceinline__ cuddreal
fma ( cuddreal const a, double const b, cuddreal const c )
{
  cuddreal const  t = (a * b) + c;
  return t;
}

__host__ __device__ __forceinline__ cuddreal
fma ( double const a, cuddreal const b, cuddreal const c )
{
  cuddreal const  t = (a * b) + c;
  return t;
}

__host__ __device__ __forceinline__ cuddreal
fma ( double const a, double const b, cuddreal const c )
{
  double const    ab  = a*b;
  cuddreal const  ab_ = __cuddreal__( ab, fma(a, b, -ab) );
  cuddreal const  t   = ab_ + c;
  return t;
}

__host__ __device__ __forceinline__ cuddreal
CUWDIV ( cuddreal const a, cuddreal const b )
{
  cuddreal const ZERO   = __cuddreal__( (double)0., (double)0. );
  cuddreal const ONE    = __cuddreal__( (double)1., (double)0. );
  cuddreal const MONE   = __cuddreal__( (double)-1., (double)0. );
  cuddreal const NAN_DD = __cuddreal__( (double)NAN, (double)NAN );

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
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = a;
  double const   xn     = a_.x / b_.x;
  cuddreal const yn     = b * xn;
  cuddreal const T      = a * yn;
  cuddreal       t      = b - T;
  t *= xn;
  cuddreal const Y      = yn + t;

  return Y;
}

__host__ __device__ __forceinline__ cuddreal
operator/ ( cuddreal const a, cuddreal const b )
{
  cuddreal const t = CUWDIV ( a, b );
  return t;
}

__host__ __device__ __forceinline__ cuddreal
operator/ ( cuddreal const a, double const b )
{
  cuddreal const c = { b, (double)0 };
  cuddreal const t = a / c;
  return t;
}

__host__ __device__ __forceinline__ cuddreal
operator/ ( cuddreal const a, int const b )
{
  double const c = (double)b;
  cuddreal const t = a / c;
  return t;
}

template < class T >
__host__ __device__ __forceinline__ void
operator/= ( cuddreal &a, const T b )
{
  a = ( a / b );
}

__host__ __device__ __forceinline__ void
add2 ( cuddreal const a1, cuddreal const b1, cuddreal &d1,
       cuddreal const a2, cuddreal const b2, cuddreal &d2 )
{
  cuddreal  t1,t2;
  CUWADD2 ( a1, b1, t1, a2, b2, t2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
sub2 ( cuddreal const a1, cuddreal const b1, cuddreal &d1,
       cuddreal const a2, cuddreal const b2, cuddreal &d2 )
{
  cuddreal  t1,t2;
  CUWSUB2 ( a1, b1, t1, a2, b2, t2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
mul2 ( cuddreal const a1, cuddreal const b1, cuddreal &d1,
       cuddreal const a2, cuddreal const b2, cuddreal &d2 )
{
  cuddreal  t1,t2;
  CUWMUL2 ( a1, b1, t1, a2, b2, t2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
fma2 ( cuddreal const a1, cuddreal const b1, cuddreal const c1, cuddreal &d1,
       cuddreal const a2, cuddreal const b2, cuddreal const c2, cuddreal &d2 )
{
#    if 0
  cuddreal  t1,t2;
  CUWMUL2 ( a1, b1, t1, a2, b2, t2 );
  CUWADD2 ( c1, t1, t1, c2, t2, t2 );
  d1 = t1; d2 = t2;
#    else
  cuddreal_raw const a1_ = a1;
  cuddreal_raw const b1_ = b1;
  cuddreal_raw const a2_ = a2;
  cuddreal_raw const b2_ = b2;
  double s1, t1, f1, e1;
  double s2, t2, f2, e2;
  cuddreal_raw t1_, c1_;
  cuddreal_raw t2_, c2_;

  cuTwoProdFMA ( a1_.x, b1_.y, s1, e1 ); // 3
  cuTwoProdFMA ( a2_.x, b2_.y, s2, e2 ); // 3
  t1    = __fmad ( a1_.y, b1_.x, e1 ); // 1
  t2    = __fmad ( a2_.y, b2_.x, e2 ); // 1
  f1    = __add ( t1, s1 ); // 1
  f2    = __add ( t2, s2 ); // 1
  cuTwoProdFMA ( a1_.x, b1_.x, t1_.x, e1 ); // 3
  cuTwoProdFMA ( a2_.x, b2_.x, t2_.x, e2 ); // 3
  t1_.y = __add ( e1, f1 ); // 1
  t2_.y = __add ( e2, f2 ); // 1

  c1_ = t1_ + c1;
  c2_ = t2_ + c2;

  d1 = c1_;
  d2 = c2_;
#    endif
}

__host__ __device__ __forceinline__ int
isnan ( cuddreal const a )
{
  cuddreal_raw const a_ = a;
  return (isnan(a_.x) || isnan(a_.y));
}

__host__ __device__ __forceinline__ int
isinf ( cuddreal const a )
{
  cuddreal_raw const a_ = a;
  return (isinf(a_.x) || isinf(a_.y));
}

__host__ __device__ __forceinline__ int
isfinite ( cuddreal const a )
{
  cuddreal_raw const a_ = a;
#    if defined(__CUDA_ARCH__)
  uint32_t const mask = 0x7ff00000;
  uint32_t const b1 = __double2hiint( a_.x );
  uint32_t const b2 = __double2hiint( a_.y );
  return ( (b1 & mask) != mask && (b2 & mask) != mask );
#    else
  return (isfinite(a_.x) && isfinite(a_.y));
#    endif
}

__host__ __device__ __forceinline__ cuddreal
Abs ( cuddreal const a )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw r_;
  r_.x = fabs(a_.x);
  r_.y = fabs(a_.y);
  return r_;
}

__host__ __device__ __forceinline__ cuddreal
Conj ( cuddreal const a )
{
  return a;
}


__host__ __device__ __forceinline__ cuddreal
Sqrt ( cuddreal const a )
{
  cuddreal const ZERO   = __cuddreal__( (double)0., (double)0. );
  cuddreal const NAN_DD = __cuddreal__( (double)NAN, (double)NAN );

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
  cuddreal_raw const a_ = a;
  double         xn     = (double)1. / sqrt(a_.x);
  cuddreal const yn     = a * xn;
  cuddreal const T      = yn * yn;
  cuddreal       t      = a - T;
  xn /= 2; t *= xn;
  cuddreal const Y      = yn + t;

  return Y;
}

__host__ __device__ __forceinline__ cuddreal
__choose__ ( bool const flag, cuddreal const a, cuddreal const b )
{
  cuddreal_raw const a_ = a;
  cuddreal_raw const b_ = b;
  cuddreal_raw r_;
  r_.x = __choose__( flag, a_.x, b_.x );
  r_.y = __choose__( flag, a_.y, b_.y );
  return r_;
}

#  endif
#  undef ASPEN_DDREAL_struct_body

#endif

