#ifndef ASPEN_HALF_H_INCLUDED
#  define ASPEN_HALF_H_INCLUDED	1

#  include <cuda.h>

#  if !defined(__CUDA_ARCH__)
#    define	half	__half__
#    ifdef __cplusplus
#      include <half.hpp>
#    endif
#    undef half
#  endif

#  if defined(ASPEN_HALF_ENABLED)
#    undef ASPEN_HALF_ENABLED
#  endif

#  if defined(__CUDA_ARCH__)
#    include <cuda.h>
#    if defined(CURRENT_GPU)
#      if CURRENT_GPU==530 ||                   \
  CURRENT_GPU==600 || CURRENT_GPU==620 ||       \
  CURRENT_GPU==700 || CURRENT_GPU==750 ||       \
  CURRENT_GPU==800 || CURRENT_GPU==860 ||	\
  CURRENT_GPU==890 ||                           \
  CURRENT_GPU==900 ||                           \
  CURRENT_GPU==1000 ||                          \
  CURRENT_GPU==1200
#        if CUDA_VERSION>7000
#          define ASPEN_HALF_ENABLED	1
#        else
#          define ASPEN_HALF_ENABLED	0
#        endif
#      else
#        if CURRENT_GPU==610 && CUDA_VERSION>11000
#          define ASPEN_HALF_ENABLED	1
#        else
#          define ASPEN_HALF_ENABLED	0
#        endif
#      endif
#    else
#      define ASPEN_HALF_ENABLED	0
#    endif
#  else
#    define ASPEN_HALF_ENABLED	1
#  endif

#  if ASPEN_HALF_ENABLED
#    include <cuda_fp16.h>
//
//  special macro definition for host side
//  
#    ifdef __cplusplus
struct __align__(2) __halfreal__
{
 public:
  union {
#      if defined(__CUDA_ARCH__)
    __half			val;
#      else
    half_float::__half__	val;
#      endif
    short 			raw;
  };

  __host__ __device__ __forceinline__
    __halfreal__() { }

  __host__ __device__ __forceinline__
    __halfreal__(__halfreal__ const &a) { val = a.val; }

  __host__ __device__ __forceinline__
    __halfreal__(int const &a) {
#      if defined(__CUDA_ARCH__)
    val = (__half)a;
#      else
    val = (half_float::__half__)a;
#      endif
  }

  template < class T >
    __host__ __device__ __forceinline__
    operator T() const { return (T)(val); }
};

struct __align__(4) __halfrealv2__
{
  struct __halfreal__ x;
  struct __halfreal__ y;

  __host__ __device__ __forceinline__
    __halfrealv2__() { x.raw = y.raw = 0; }

  __host__ __device__ __forceinline__
    __halfrealv2__(__halfreal__ const &a, __halfreal__ const &b) { x = a; y = b; }
};

typedef struct __halfreal__	__half__;
typedef struct __halfrealv2__	__halfv2__;

#    else
struct __align__(2) __halfreal__
{
  union {
#      if defined(__CUDA_ARCH__)
    __half			val;
#      else
    short			val;
#      endif
    short 			raw;
  };
};

struct __align__(4) __halfrealv2__
{
  struct __halfreal__ x;
  struct __halfreal__ y;
};

#      if defined(__CUDA_ARCH__)
typedef	__half_raw	__half__;
#      else
typedef	short		__half__;
#      endif

#    endif


#    define	half	__half__
#    define	half2	__halfv2__


#    ifdef __cplusplus

__host__ __device__ __forceinline__ float
half2float ( half const a )
{
  float r;
  r = (float)a.val;
  return r;
}

__host__ __device__ __forceinline__ half
float2half ( float const a )
{
  half r;
#      if defined(__CUDA_ARCH__)
  r.val = (__half)a;
#      else
  r.val = (half_float::__half__)a;
#      endif
  return r;
}

#      if defined(__CUDA_ARCH__)
__device__ __forceinline__ half2
__ldg ( half2 const * a )
{
  half2 * aa = (half2 *)a;
  uint32_t * p = (reinterpret_cast<uint32_t *>(aa));
  uint32_t b = __ldg( p );
  half2 bb = *(reinterpret_cast<half2 *>(&b));
  return bb;
}
#      endif

__host__ __device__ __forceinline__ bool
operator== ( half const a, half const b )
{
  half aa = a;
  half bb = b;
  unsigned short  u = *(reinterpret_cast<unsigned short *>(&(aa)));
  unsigned short  v = *(reinterpret_cast<unsigned short *>(&(bb)));
  return ( u == v );
}

__host__ __device__ __forceinline__ bool
operator!= ( half const a, half const b )
{
  half aa = a;
  half bb = b;
  unsigned short  u = *(reinterpret_cast<unsigned short *>(&(aa)));
  unsigned short  v = *(reinterpret_cast<unsigned short *>(&(bb)));
  return ( u != v );
}

__host__ __device__ __forceinline__ bool
operator< ( half const a, half const b )
{
  return a.val < b.val;
}

__host__ __device__ __forceinline__ bool
operator<= ( half const a, half const b )
{
  return a.val <= b.val;
}

__host__ __device__ __forceinline__ bool
operator> ( half const a, half const b )
{
  return a.val > b.val;
}

__host__ __device__ __forceinline__ bool
operator>= ( half const a, half const b )
{
  return a.val >= b.val;
}

__host__ __device__ __forceinline__ half
operator+ ( half const a )
{
  return a;
}

__host__ __device__ __forceinline__ half
operator+ ( half const a,  half const b )
{
  half r;
#      if defined(__CUDA_ARCH__)
  r.val = __hadd (a.val, b.val);
#      else
  r.val = (a.val + b.val);
#      endif
  return r;
}

__host__ __device__ __forceinline__ void
operator+= ( half &a,  half const b )
{
  a = ( a + b );
}

__host__ __device__ __forceinline__ void
operator+= ( half2 &a,  half2 const b )
{
#      if defined(__CUDA_ARCH__)
  half2 bb = b;
  __half2 a_ = *(reinterpret_cast<__half2 *>(&(a)));
  __half2 b_ = *(reinterpret_cast<__half2 *>(&(bb)));
  a_ += b_;
  a = *(reinterpret_cast<half2 *>(&(a_)));
#      else
  a.x = a.x + b.x;
  a.y = a.y + b.y;
#      endif
}

__host__ __device__ __forceinline__ half
operator- ( half const a )
{
  half r;
#      if defined(__CUDA_ARCH__)
  r.val = __hneg (a.val);
#      else
  r.val = - (a.val);
#      endif
  return r;
}

__host__ __device__ __forceinline__ half
operator- ( half const a,  half const b )
{
  half r;
#      if defined(__CUDA_ARCH__)
  r.val = __hsub (a.val, b.val);
#      else
  r.val = (a.val - b.val);
#      endif
  return r;
}

__host__ __device__ __forceinline__ void
operator-= ( half &a,  half const  b)
{
  a = ( a - b );
}

__host__ __device__ __forceinline__ half
operator* ( half const a,  half const b )
{
  half r;
#      if defined(__CUDA_ARCH__)
  r.val = __hmul (a.val, b.val);
#      else
  r.val = (a.val * b.val);
#      endif
  return r;
}

__host__ __device__ __forceinline__ half
operator* ( half const a,  int const b )
{
  half const c = (half)b;
  return ( a * c );
}

__host__ __device__ __forceinline__ half
operator* ( int const a,  half const b )
{
  return ( b * a );
}

template < class T >
__host__ __device__ __forceinline__ void
operator*= ( half &a,  T const b )
{
  a = ( a * b );
}

#      if defined(__CUDA_ARCH__)
#        if CUDA_VERSION>=9000
#          define	hdiv	__hdiv
#        endif
#      endif

__host__ __device__ __forceinline__ half
operator/ ( half const a,  half const b )
{
  half r;
#      if defined(__CUDA_ARCH__)
  r.val = hdiv (a.val, b.val);
#      else
  r.val = (a.val / b.val);
#      endif
  return r;
}

__host__ __device__ __forceinline__ half
operator/ ( half const a,  int const b )
{
  half const c = (half)b;
  return ( a / c );
}

template < class T >
__device__ __host__ __forceinline__ void
operator/= ( half &a,  T const b )
{
  a = ( a / b );
}

__device__ __host__ __forceinline__ half
fma( half const a,  half const b, half const c )
{
  half r;
#      if defined(__CUDA_ARCH__)
  r.val = __hfma (a.val, b.val, c.val);
#      else
  r = (half)half_float::fma( a, b, c );
#      endif
  return r;
}

__device__ __host__ __forceinline__ void
fma2( half const a1,  half const b1, half const c1, half &d1,
      half const a2,  half const b2, half const c2, half &d2 )
{
  d1 = fma (a1, b1, c1);
  d2 = fma (a2, b2, c2);
}

__host__ __device__ __forceinline__ half
Conj( half const a )
{
  return  a;
}

__host__ __device__ __forceinline__ half
Abs( half const a )
{
  half aa = a;
  ushort  u = *(reinterpret_cast<ushort *>(&(aa)));
  u &=0x7fff;
  return *(reinterpret_cast<half *>(&(u)));
}

__host__ __device__ __forceinline__ half
__choose__( const bool flag,  half const a, half const b )
{
  half aa = a, bb = b;
  ushort  u = *(reinterpret_cast<ushort *>(&(aa)));
  ushort  v = *(reinterpret_cast<ushort *>(&(bb)));
  ushort  r = (flag ? u : v);
  return  *(reinterpret_cast<half *>(&(r)));
}

__host__ __device__ __forceinline__ half2
__choose__( const bool flag,  half2 const a, half2 const b )
{
  half2 aa = a, bb = b;
  uint u = *(reinterpret_cast<uint *>(&(aa)));
  uint v = *(reinterpret_cast<uint *>(&(bb)));
  uint r = (flag ? u : v);
  return  *(reinterpret_cast<half2 *>(&(r)));
}

__host__ __device__ __forceinline__ int
isfinite( half const a ) {
  half aa = a;
  unsigned short  u = *(reinterpret_cast<unsigned short *>(&(aa)));
  u &= 0x7e00;
  return (u != 0x7e00);
}

#    endif

#  endif

#endif

