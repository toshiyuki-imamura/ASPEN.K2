#ifndef ASPEN_MAKE_CONST_H_INCLUDED
#  define	ASPEN_MAKE_CONST_H_INCLUDED	1

#  include "aspen_types.h"
#  include "aspen_istypes.h"

// const volatile acess ----------------------------------
#  if 0
static
__device__ uint const ASPEN_I32_CONST[2] = {0x00000000,0xffffffff};
#    define PTX_LOAD_ZERO(x)                            \
  "ld.global.cv.u32\t%"#x", [ASPEN_I32_CONST+0];\n\t"
#    define PTX_LOAD_MONE(x)                            \
  "ld.global.cv.u32\t%"#x", [ASPEN_I32_CONST+4];\n\t"
#  else
static
__device__ __constant__ uint ASPEN_I32_CONST[2] = {0x00000000,0xffffffff};
#    define PTX_LOAD_ZERO(x)                            \
  "ld.const.u32\t%"#x", [ASPEN_I32_CONST+0];\n\t"
#    define PTX_LOAD_MONE(x)                            \
  "ld.const.u32\t%"#x", [ASPEN_I32_CONST+4];\n\t"
#  endif

__forceinline__   __device__ uint _ZERO_ ( void )
{
  uint ret;
  asm volatile ( PTX_LOAD_ZERO(0) : "=r"(ret) );
  return ret;
}

__forceinline__   __device__ uint _MONE_ ( void )
{
  uint ret;
  asm volatile ( PTX_LOAD_MONE(0) : "=r"(ret) );
  return ret;
}

// generic ----------------------------------
template < class TYPE, class TYPE_ >
__forceinline__ __host__  __device__ TYPE
makeCONST ( TYPE_ const x )
{
  return static_cast<TYPE>(x);
}

template < class TYPE, class TYPE_ >
__forceinline__ __host__  __device__ TYPE
makeCONST ( TYPE_ const x, TYPE_ const y )
{
  return static_cast<TYPE>(x);
}
// generic ----------------------------------


// half ----------------------------------
#  if ASPEN_HALF_ENABLED
template < >
__forceinline__ __host__  __device__ half
makeCONST ( int const x )
{
  half y;
  y.val = x;
  return y;
}

template < >
__forceinline__ __host__  __device__ half
makeCONST ( float const x )
{
  half y;
  y.val = x;
  return y;
}

template < >
__forceinline__ __host__  __device__ half
makeCONST ( double const x )
{
  half y;
  y.val = x;
  return y;
}

#    if defined(__CUDA_ARCH__)
#      if CURRENT_GPU==600||CURRENT_GPU==700||CURRENT_GPU==750
#        if CUDA_VERSION>8000
template < >
__forceinline__ __host__  __device__ __half_raw
makeCONST ( int const x )
{
  half const y = makeCONST < half > ( x );
  __half_raw const z = y.val;
  return z;
}
#        endif
#      endif
#    endif

#  endif
// half ----------------------------------

// half_complex ----------------------------------
template < >
__forceinline__ __host__  __device__ cuHalfComplex
makeCONST ( int const x )
{
  half const y = makeCONST < half > ( x );
  half const z = makeCONST < half > ( 0 );
  __cuHalfComplex_raw__ t_;
  t_.x = y;
  t_.y = z;
  return t_;
}

template < >
__forceinline__ __host__  __device__ cuHalfComplex
makeCONST ( float const x )
{
  half const y = makeCONST < half > ( x );
  half const z = makeCONST < half > ( 0 );
  __cuHalfComplex_raw__ t_;
  t_.x = y;
  t_.y = z;
  return t_;
}

template < >
__forceinline__ __host__  __device__ cuHalfComplex
makeCONST ( double const x )
{
  half const y = makeCONST < half > ( x );
  half const z = makeCONST < half > ( 0 );
  __cuHalfComplex_raw__ t_;
  t_.x = y;
  t_.y = z;
  return t_;
}
// half_complex ----------------------------------


// cuddreal ----------------------------------
template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( int const x )
{
  return __cuddreal__( static_cast<double>(x), static_cast<double>(0) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( float const x )
{
  return __cuddreal__( static_cast<double>(x), static_cast<double>(0) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( double const x )
{
  return __cuddreal__( static_cast<double>(x), static_cast<double>(0) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( cuFloatComplex const x )
{
  return __cuddreal__( static_cast<double>(x.x), static_cast<double>(0) );
}
template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( cuDoubleComplex const x )
{
  return __cuddreal__( static_cast<double>(x.x), static_cast<double>(0) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( int const hi, int const err )
{
  return __cuddreal__( static_cast<double>(hi), static_cast<double>(err) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( float const hi, float const err )
{
  return __cuddreal__( static_cast<double>(hi), static_cast<double>(err) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
makeCONST ( double const hi, double const err )
{
  return __cuddreal__( static_cast<double>(hi), static_cast<double>(err) );
}
// cuddreal ----------------------------------


// cudfreal ----------------------------------
template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( int const x )
{
  return __cudfreal__( static_cast<float>(x), static_cast<float>(0) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( float const x )
{
  return __cudfreal__( static_cast<float>(x), static_cast<float>(0) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( double const x )
{
  return __cudfreal__( static_cast<float>(x), static_cast<float>(0) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( cuFloatComplex const x )
{
  return __cudfreal__( static_cast<float>(x.x), static_cast<float>(0) );
}
template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( cuDoubleComplex const x )
{
  return __cudfreal__( static_cast<float>(x.x), static_cast<float>(0) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( int const hi, int const err )
{
  return __cudfreal__( static_cast<float>(hi), static_cast<float>(err) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( float const hi, float const err )
{
  return __cudfreal__( static_cast<float>(hi), static_cast<float>(err) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
makeCONST ( double const hi, double const err )
{
  return __cudfreal__( static_cast<float>(hi), static_cast<float>(err) );
}
// cuddreal ----------------------------------


// cuFloatComplex ----------------------------------
template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( int const x )
{
  return (cuFloatComplex){ static_cast<float>(x), static_cast<float>(0) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( float const x )
{
  return (cuFloatComplex){ static_cast<float>(x), static_cast<float>(0) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( double const x )
{
  return (cuFloatComplex){ static_cast<float>(x), static_cast<float>(0) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( cuddreal const x )
{
  cuddreal_raw x_ = x;
  return (cuFloatComplex){ static_cast<float>(x_.x), static_cast<float>(0) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( cuDoubleComplex const x )
{
  return (cuFloatComplex){ static_cast<float>(x.x), static_cast<float>(x.y) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( cuddcomplex const x )
{
  cuddcomplex_raw x_  = x;
  cuddreal_raw x_x = x_.x;
  cuddreal_raw x_y = x_.y;
  return (cuFloatComplex){ static_cast<float>(x_x.x), static_cast<float>(x_y.x) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( int const x, int const y )
{
  return (cuFloatComplex){ static_cast<float>(x), static_cast<float>(y) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( float const x, float const y )
{
  return (cuFloatComplex){ static_cast<float>(x), static_cast<float>(y) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( double const x, double const y )
{
  return (cuFloatComplex){ static_cast<float>(x), static_cast<float>(y) };
}

template < >
__forceinline__ __host__  __device__ cuFloatComplex
makeCONST ( cuddreal const x, cuddreal const y )
{
  cuddreal_raw x_ = x;
  cuddreal_raw y_ = y;
  return (cuFloatComplex){ static_cast<float>(x_.x), static_cast<float>(y_.x) };
}
// cuFloatComplex ----------------------------------


// cuDoubleComplex ----------------------------------
template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( int const x )
{
  return (cuDoubleComplex){ static_cast<double>(x), static_cast<double>(0) };
}

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( float const x )
{
  return (cuDoubleComplex){ static_cast<double>(x), static_cast<double>(0) };
}

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( double const x )
{
  return (cuDoubleComplex){ static_cast<double>(x), static_cast<double>(0) };
}

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( cuddreal const x )
{
  cuddreal_raw x_ = x;
  return (cuDoubleComplex){ static_cast<double>(x_.x), static_cast<double>(0) };
}

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( cuFloatComplex const x )
{
  return (cuDoubleComplex){ static_cast<double>(x.x), static_cast<double>(x.y) };
}

#  if 1
template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( cuddcomplex const x )
{
  cuddcomplex_raw x_  = x;
  cuddreal_raw x_x = x_.x;
  cuddreal_raw x_y = x_.y;
  return (cuDoubleComplex){ static_cast<double>(x_x.x), static_cast<double>(x_y.x) };
}
#  endif

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( int const x, int const y )
{
  return (cuDoubleComplex){ static_cast<double>(x), static_cast<double>(y) };
}

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( float const x, float const y )
{
  return (cuDoubleComplex){ static_cast<double>(x), static_cast<double>(y) };
}

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( double const x, double const y )
{
  return (cuDoubleComplex){ static_cast<double>(x), static_cast<double>(y) };
}

template < >
__forceinline__ __host__  __device__ cuDoubleComplex
makeCONST ( cuddreal const x, cuddreal const y )
{
  cuddreal_raw x_ = x;
  cuddreal_raw y_ = y;
  return (cuDoubleComplex){ static_cast<double>(x_.x), static_cast<double>(y_.x) };
}
// cuDoubleComplex ----------------------------------


// cuddcomplex ----------------------------------
template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( int const x )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x) ), __cuddreal__( static_cast<double>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( float const x )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x) ), __cuddreal__( static_cast<double>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( double const x )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x) ), __cuddreal__( static_cast<double>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( cuddreal const x )
{
  return __cuddcomplex__( x, __cuddreal__( static_cast<double>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( cuFloatComplex const x )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x.x) ), __cuddreal__( static_cast<double>(x.y) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( cuDoubleComplex const x )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x.x) ), __cuddreal__( static_cast<double>(x.y) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( int const x, int const y )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x) ), __cuddreal__( static_cast<double>(y) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( float const x, float const y )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x) ), __cuddreal__( static_cast<double>(y) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( double const x, double const y )
{
  return __cuddcomplex__( __cuddreal__( static_cast<double>(x) ), __cuddreal__( static_cast<double>(y) ) );
}

template < >
__forceinline__ __host__  __device__ cuddcomplex
makeCONST ( cuddreal const x, cuddreal const y )
{
  return __cuddcomplex__( x, y );
}
// cuddcomplex ----------------------------------


// cudfcomplex ----------------------------------
template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( int const x )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x) ), __cuddreal__( static_cast<float>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( float const x )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x) ), __cuddreal__( static_cast<float>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( double const x )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x) ), __cuddreal__( static_cast<float>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( cuddreal const x )
{
  cuddreal_raw const x_ = x;
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x_.x), static_cast<float>(x_.y) ), __cudfreal__( static_cast<float>(0) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( cuFloatComplex const x )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x.x) ), __cudfreal__( static_cast<float>(x.y) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( cuDoubleComplex const x )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x.x) ), __cudfreal__( static_cast<float>(x.y) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( int const x, int const y )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x) ), __cudfreal__( static_cast<float>(y) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( float const x, float const y )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x) ), __cudfreal__( static_cast<float>(y) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( double const x, double const y )
{
  return __cudfcomplex__( __cudfreal__( static_cast<float>(x) ), __cudfreal__( static_cast<float>(y) ) );
}

template < >
__forceinline__ __host__  __device__ cudfcomplex
makeCONST ( cuddreal const x, cuddreal const y )
{
  return __cudfcomplex__( x, y );
}
// cudfcomplex ----------------------------------


// int16 ----------------------------------
template < >
__forceinline__ __host__  __device__ int16
makeCONST ( int const x )
{
  return __int16__t_( static_cast<int16_t>(x) );
}
// int16 ----------------------------------


// int128 ----------------------------------
template < >
__forceinline__ __host__  __device__ int128
makeCONST ( int const x )
{
  int128 const t = (int128)(x);
  return t;
}
// int128 ----------------------------------


#if 0
// bfloat16 ----------------------------------
template < >
__forceinline__ __host__  __device__ bfloat16
makeCONST ( int const x )
{
  union {
    unsigned short x[2];
    float y;
  } u;
  u.y = static_cast<float>(x);
  bfloat16 t; t.x = u.x[1];
  return t;
}
template < >
__forceinline__ __host__  __device__ bfloat16
makeCONST ( float const x )
{
  union {
    unsigned short x[2];
    float y;
  } u;
  u.y = static_cast<float>(x);
  bfloat16 t; t.x = u.x[1];
  return t;
}
template < >
__forceinline__ __host__  __device__ bfloat16
makeCONST ( double const x )
{
  union {
    unsigned short x[2];
    float y;
  } u;
  u.y = static_cast<float>(x);
  bfloat16 t; t.x = u.x[1];
  return t;
}
// bfloat16 ----------------------------------
#endif

template < class TYPE >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( TYPE &b )
{ ; }

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( half &b )
{
#  if defined(__CUDA_ARCH__)
  __half_raw c = b.val;
  asm volatile ( "// const volatile" :: "h"(c.x) );
  b.val = c;
#  else
  half c = b;
  asm volatile ( "// const volatile" :: "h"(c.val) );
  b = c;
#  endif
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( float &b )
{
  asm volatile ( "// const volatile" :: "f"(b) );
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( double &b )
{
  asm volatile ( "// const volatile" :: "d"(b) );
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( cuddreal &b )
{
  cuddreal_raw c = b;
  makeCONST_volatile_sub ( c.x );
  makeCONST_volatile_sub ( c.y );
  b = c;
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( cuFloatComplex &b )
{
  makeCONST_volatile_sub ( b.x );
  makeCONST_volatile_sub ( b.y );
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( cuDoubleComplex &b )
{
  makeCONST_volatile_sub ( b.x );
  makeCONST_volatile_sub ( b.y );
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( cuddcomplex &b )
{
  cuddcomplex_raw c = b;
  makeCONST_volatile_sub ( c.x );
  makeCONST_volatile_sub ( c.y );
  b = c;
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( int16 &b )
{
  int16_raw c = b;
  asm volatile ( "// const volatile" :: "h"(c.x) );
  b = c;
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( int32 &b )
{
  asm volatile ( "// const volatile" :: "r"(b) );
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( int64 &b )
{
  asm volatile ( "// const volatile" :: "l"(b) );
}

template < >
__forceinline__ __host__  __device__ void
makeCONST_volatile_sub ( int128 &b )
{
  int64 * b_ = (int64 *)&b;
  makeCONST_volatile_sub ( b_[0] );
  makeCONST_volatile_sub ( b_[1] );
}

template < class TYPE >
__forceinline__ __host__  __device__ TYPE
makeCONST_volatile ( int const x )
{
  TYPE b = makeCONST < TYPE > ( x );
  b = *(reinterpret_cast<TYPE*>(&b));
  makeCONST_volatile_sub ( b );
  return b;
}

// normalization ----------------------------------
template < class TYPE >
__forceinline__ __host__  __device__ TYPE
Normalize ( double const h, double const l )
{ TYPE r; return r; }

template < class TYPE >
__forceinline__ __host__  __device__ TYPE
Normalize ( int const h, int const l )
{ TYPE r; return r; }

template < class TYPE >
__forceinline__ __host__  __device__ TYPE
Normalize ( float const h, float const l )
{ TYPE r; return r; }

template < class TYPE >
__forceinline__ __host__  __device__ TYPE
Normalize ( TYPE const x )
{ TYPE r; return r; }


template < >
__forceinline__ __host__  __device__ cuddreal
Normalize < cuddreal > ( double const h, double const l )
{
  double hi = h, lo = l;
  hi += l;
  double const d = hi - h;
  cuddreal const t = __cuddreal__( static_cast<double>(h+lo), static_cast<double>(lo-d) );
  return t;
}

template < >
__forceinline__ __host__  __device__ cuddreal
Normalize < cuddreal > ( int const h, int const l )
{
  return Normalize < cuddreal > ( static_cast<double>(h), static_cast<double>(l) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
Normalize < cuddreal > ( float const h, float const l )
{
  return Normalize < cuddreal > ( static_cast<double>(h), static_cast<double>(l) );
}

template < >
__forceinline__ __host__  __device__ cuddreal
Normalize < cuddreal > ( cuddreal const x )
{
  cuddreal_raw x_ = x;
  return Normalize < cuddreal > ( static_cast<double>(x_.x), static_cast<double>(x_.y) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
Normalize < cudfreal > ( float const h, float const l )
{
  float hi = h, lo = l;
  hi += l;
  float d = hi - h;
  cudfreal const t = __cudfreal__( static_cast<float>(h+lo), static_cast<float>(lo-d) );
  return t;
}

template < >
__forceinline__ __host__  __device__ cudfreal
Normalize < cudfreal > ( int const h, int const l )
{
  return Normalize < cudfreal > ( static_cast<float>(h), static_cast<float>(l) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
Normalize < cudfreal > ( double const h, double const l )
{
  return Normalize < cudfreal > ( static_cast<float>(h), static_cast<float>(l) );
}

template < >
__forceinline__ __host__  __device__ cudfreal
Normalize < cudfreal > ( cudfreal const x )
{
  cudfreal_raw x_ = x;
  return Normalize < cudfreal > ( static_cast<double>(x_.x), static_cast<double>(x_.y) );
}
// normalization ----------------------------------


// zerofy ----------------------------------
template < class TYPE >
__forceinline__ __host__  __device__ void
zerofy ( TYPE &x )
{ x = makeCONST<TYPE>(0); }

#  if defined(__CUDA_ARCH__)
#    if ASPEN_HALF_ENABLED
#      if CUDA_VERSION>8000
__forceinline__ __host__  __device__ void
zerofy ( __half_raw &x_ )
{
  asm volatile ( "mov.b16\t%0, 0;" : "=h"(x_.x));
}
#      endif

template < >
__forceinline__ __host__  __device__ void
zerofy ( half &x )
{
#      if CUDA_VERSION==8000
  __half_raw x_;
  asm volatile ( "mov.b16\t%0, 0;" : "=h"(x_.x));
  x = x_;
#      else
  zerofy ( x );
#      endif
}
#    endif
#  endif

template < >
__forceinline__ __host__  __device__ void
zerofy ( float &x )
{
  asm volatile ( "mov.b32\t%0, 0;" : "=f"(x) );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( double &x )
{
  asm volatile ( "mov.b64\t%0, 0;" : "=d"(x) );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( cudfreal &x )
{
  float zero;
  zerofy( zero );
  x = __cudfreal__( zero, zero );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( cuddreal &x )
{
  double zero;
  zerofy( zero );
  x = __cuddreal__( zero, zero );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( cuFloatComplex &x )
{
  zerofy( x.x ); zerofy( x.y );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( cuDoubleComplex &x )
{
  zerofy( x.x ); zerofy( x.y );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( cudfcomplex &x )
{
  cudfreal zero;
  zerofy( zero );
  x = __cudfcomplex__( zero, zero );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( cuddcomplex &x )
{
  cuddreal zero;
  zerofy( zero );
  x = __cuddcomplex__( zero, zero );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( int16 &x )
{
  int16_t xx;
  asm volatile ( "mov.b16 %0, 0;" : "=h"(xx) );
  x = xx;
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( int32 &x )
{
  asm volatile ( "mov.b32 %0, 0;" : "=r"(x) );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( int64 &x )
{
  asm volatile ( "mov.b64 %0, 0;" : "=l"(x) );
}

template < >
__forceinline__ __host__  __device__ void
zerofy ( int128 &x )
{
  uint64_t c;
  asm volatile ( "mov.b64 %0, 0;" : "=l"(c) );
  uint64_t *x_ = (uint64_t*)&x;
  x_[0] = x_[1] = c;
}

#if 0
template < >
__forceinline__ __host__  __device__ void
zerofy ( bfloat16 &x )
{
  asm volatile ( "mov.b16 %0,0;" : "=h"(x.x) );
}
#endif

template < class TYPE >
__forceinline__ __host__  __device__ TYPE
zerofy ( void )
{ TYPE y; zerofy( y ); return y; }
// const_zero ----------------------------------

#endif

