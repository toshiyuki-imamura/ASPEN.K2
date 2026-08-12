#ifndef ASPEN_INT16_H_INCLUDED
#  define ASPEN_INT16_H_INCLUDED		1

#  include <stdint.h>

#  define ASPEN_INT16_struct_body               \
  int16_t x
#  define ASPEN_INT16v2_struct_body             \
  __int16_raw__ x; __int16_raw__ y

typedef struct __align__(2) {
  ASPEN_INT16_struct_body;
} __int16_raw__;

typedef union __align__(4) {
  uint32_t r;
  struct { ASPEN_INT16v2_struct_body; };
} __int16v2_raw__;

#  ifndef __cplusplus

typedef	__int16_raw__	int16;

#  else

struct __align__(2) __int16__t_
{
 private:
  ASPEN_INT16_struct_body;
 public:
#    if __cplusplus >= 201103L
  __int16__t_() = default;
#    else
  __host__ __device__ __forceinline__
    __int16__t_() { }
#    endif
  __host__ __device__ __forceinline__
    __int16__t_( __int16_raw__ const &h ) { x = h.x; }
  __host__ __device__ __forceinline__
    __int16__t_ &operator= ( __int16_raw__ const &h ) { x = h.x; return *this; }
  __host__ __device__ __forceinline__
    operator __int16_raw__() const { __int16_raw__ h; h.x = x; return h; }

  __host__ __device__ __forceinline__
    __int16__t_( int16_t const val ) { x = val; }
  __host__ __device__ __forceinline__
    __int16__t_ &operator= ( int16_t const &h ) { x = h; return *this; }
  __host__ __device__ __forceinline__
    operator int16_t() const { int16_t h; h = x; return h; }

  __host__ __device__ __forceinline__
    __int16_raw__ * raw( void ) { return reinterpret_cast<__int16_raw__*>(this); }
  
  template < class T >
    __host__ __device__ __forceinline__
    operator T() const {
    return (T)x;
  }

  __host__ __device__ __forceinline__
    int16_t val( void ) const { return x; }

  __host__ __device__ __forceinline__
    int16_t val( int16_t const x) { this->x = x; return x; }
};

struct __align__(4) __int16v2__t_
{
 private:
  union {
    uint32_t r;
    struct { ASPEN_INT16v2_struct_body; };
  };
 public:
#    if __cplusplus >= 201103L
  __int16v2__t_() = default;
#    else
  __host__ __device__ __forceinline__
    __int16v2__t_() { }
#    endif
  __host__ __device__ __forceinline__
    __int16v2__t_( __int16v2_raw__ const &h ) { x = h.x; y = h.y; }
  __host__ __device__ __forceinline__
    __int16v2__t_ &operator= ( __int16v2_raw__ const &h ) { x = h.x; return *this; }
  __host__ __device__ __forceinline__
    operator __int16v2_raw__() const { __int16v2_raw__ h; h.x = x; h.y = y; return h; }

  __host__ __device__ __forceinline__
    __int16v2__t_( __int16__t_ const &a, __int16__t_ const &b ) { x = a; y = b; }
  __host__ __device__ __forceinline__
    __int16v2__t_( int16_t const &a, int16_t const &b ) { x.x = a; y.x = b; }

};

typedef struct __int16__t_	int16;
typedef        __int16_raw__	int16_raw;
typedef struct __int16v2__t_	int16v2;
typedef        __int16v2_raw__	int16v2_raw;


#    if GPU_ARCH>300
__device__ __forceinline__ int16
__ldg ( int16 const * a )
{
  int16 * aa = (int16 *)a;
  int16_t * p = (reinterpret_cast<int16_t *>(aa));
  int16_t const b = __ldg( p );
  return b;
}

__device__ __forceinline__ int16v2
__ldg ( int16v2 const * a )
{
  int16v2 * aa = (int16v2 *)a;
  uint32_t * p = (reinterpret_cast<uint32_t *>(aa));
  uint32_t b = __ldg( p );
  int16v2 bb = *(reinterpret_cast<int16v2 *>(&b));
  return bb;
}
#    endif

__host__ __device__ __forceinline__ bool
operator== ( int16 const a, int16 const b )
{
  int16_t a_ = a;
  int16_t b_ = b;
  bool const ret = (a_ == b_) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( int16 const a, int16 const b )
{
  int16_t a_ = a;
  int16_t b_ = b;
  bool const ret = (a_ != b_) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator< ( int16 const a, int16 const b )
{
  int16_t a_ = a;
  int16_t b_ = b;
  bool const ret = (a_ < b_) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator> ( int16 const a, int16 const b )
{
  int16_t a_ = a;
  int16_t b_ = b;
  bool const ret = (a_ > b_) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator<= ( int16 const a, int16 const b )
{
  int16_t a_ = a;
  int16_t b_ = b;
  bool const ret = (a_ < b_) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator>= ( int16 const a, int16 const b )
{
  int16_t a_ = a;
  int16_t b_ = b;
  bool const ret = (a_ >= b_) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ int16
__add ( int16 const a,  int16 const b )
{
  int16_t  a_ = a;
  int16_t  b_ = b;
  int16_t  t_;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "add.s16\t%0, %1, %2;"
                 : "=h"(t_) : "h"(a_), "h"(b_) );
#    else
  t_ = a_ + b_;
#    endif
  return  t_;
}

__host__ __device__ __forceinline__ int16v2
__add ( int16v2 const a,  int16v2 const b )
{
  int16v2_raw  a_ = a;
  int16v2_raw  b_ = b;
  int16v2_raw  t_;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "vadd2.s32.s32.s32\t%0, %1, %2, %0;"
                 : "=r"(t_.r) : "r"(a_.r), "r"(b_.r) );
#    else
  t_.x = __add( a_.x, b_.x );
  t_.y = __add( a_.y, b_.y );
#    endif
  return  t_;
}

__host__ __device__ __forceinline__ int16
operator+ ( int16 const a )
{
  return a;
}

__host__ __device__ __forceinline__ int16v2
operator+ ( int16v2 const a )
{
  return a;
}

__host__ __device__ __forceinline__ int16
operator+ ( int16 const a, int16 const b )
{
  return __add ( a, b );
}

__host__ __device__ __forceinline__ int16v2
operator+ ( int16v2 const a, int16v2 const b )
{
  return __add ( a, b );
}

__host__ __device__ __forceinline__ void
operator+= ( int16 & a, int16 const b )
{
  a = __add ( a, b );
}

__host__ __device__ __forceinline__ void
operator+= ( int16v2 & a, int16v2 const b )
{
  a = __add ( a, b );
}

__host__ __device__ __forceinline__ void
add2 ( int16 const a1, int16 const b1, int16 &d1,
       int16 const a2, int16 const b2, int16 &d2 )
{
  int16 const t1 = __add( a1, b1 );
  int16 const t2 = __add( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int16
__sub ( int16 const a,  int16 const b )
{
  int16_t  a_ = a;
  int16_t  b_ = b;
  int16_t  t_;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "sub.s16\t%0, %1, %2;"
                 : "=h"(t_) : "h"(a_), "h"(b_) );
#    else
  t_ = a_ - b_;
#    endif
  return  t_;
}

__host__ __device__ __forceinline__ int16
operator- ( int16 const a )
{
  int16_t a_ = a;
  int16_t t_;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "neg.s16\t%0, %1;"
                 : "=h"(t_) : "h"(a_) );
#    else
  t_ = -a_;
#    endif
  return t_;
}

__host__ __device__ __forceinline__ int16
operator- ( int16 const a, int16 const b )
{
  return __sub ( a, b );
}

__host__ __device__ __forceinline__ void
operator-= (  int16 & a, int16 const b )
{
  a = __sub ( a, b );
}

__host__ __device__ __forceinline__ void
sub2 ( int16 const a1, int16 const b1, int16 &d1,
       int16 const a2, int16 const b2, int16 &d2 )
{
  int16 const t1 = __sub( a1, b1 );
  int16 const t2 = __sub( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int16
__mul ( int16 const a,  int16 const b )
{
  int16_t  a_ = a;
  int16_t  b_ = b;
  int16_t  t_;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "mul.lo.s16\t%0, %1, %2;"
                 : "=h"(t_) : "h"(a_), "h"(b_) );
#    else
  t_ = a_ * b_;
#    endif
  return  t_;
}

__host__ __device__ __forceinline__ int16
operator* ( int16 const a, int16 const b )
{
  return __mul ( a, b );
}

__host__ __device__ __forceinline__ void
operator*= (  int16 & a, int16 const b )
{
  a = __mul ( a, b );
}

__host__ __device__ __forceinline__ void
mul2 ( int16 const a1, int16 const b1, int16 &d1,
       int16 const a2, int16 const b2, int16 &d2 )
{
  int16 const t1 = __mul( a1, b1 );
  int16 const t2 = __mul( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int16
fma ( int16 const a, int16 const b, int16 const c )
{
  int16_t  a_ = a;
  int16_t  b_ = b;
  int16_t  c_ = c;
  int16_t  t_;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "mad.lo.s16\t%0, %1, %2, %3;"
                 : "=h"(t_) : "h"(a_), "h"(b_), "h"(c_) );
#    else
  t_ = (a_ * b_) + c_;
#    endif
  return  t_;
}

__host__ __device__ __forceinline__ void
fma2 ( int16 const a1, int16 const b1, int16 const c1, int16 &d1,
       int16 const a2, int16 const b2, int16 const c2, int16 &d2 )
{
  int16 const t1 = fma( a1, b1, c1 );
  int16 const t2 = fma( a2, b2, c2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int
isnan ( int16 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isinf ( int16 const a )
{
  return false;
}

__host__ __device__ __forceinline__ int
isfinite ( int16 const a )
{
  return true;
}

__host__ __device__ __forceinline__ int16
Abs ( int16 const a )
{
  int16_t  t_ = a;
#    if defined(__CUDA_ARCH__)
  asm volatile ( "abs.s16\t%0, %0;"
                 : "+h"(t_) );
#    else
  t_ = ( t_ >= 0 ? t_ : -t_ );
#    endif
  return  t_;
}

__host__ __device__ __forceinline__ int16
Conj ( int16 const a )
{
  return ( a );
}

__host__ __device__ __forceinline__ int16
__choose__ ( bool const flag, int16 const a, int16 const b )
{
  int16 aa = a, bb = b;
  uint16_t ra = *(reinterpret_cast<uint16_t *>(&aa));
  uint16_t rb = *(reinterpret_cast<uint16_t *>(&bb));
  uint16_t r  = ( flag ? ra : rb );
  return *(reinterpret_cast<int16 *>(&r));
}

__host__ __device__ __forceinline__ int16v2
__choose__ ( bool const flag, int16v2 const a, int16v2 const b )
{
  int16v2 aa = a, bb = b;
  uint32_t ra = *(reinterpret_cast<uint32_t *>(&aa));
  uint32_t rb = *(reinterpret_cast<uint32_t *>(&bb));
  uint32_t r  = ( flag ? ra : rb );
  return *(reinterpret_cast<int16v2 *>(&r));
}

#  endif
#  undef ASPEN_INT16_struct_body
#  undef ASPEN_INT16v2_struct_body

#endif

