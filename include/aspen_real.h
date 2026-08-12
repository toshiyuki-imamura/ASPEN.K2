#ifndef ASPEN_REAL_H_INCLUDED
#  define ASPEN_REAL_H_INCLUDED		1

// ...


#  ifdef __cplusplus

// for float

__host__ __device__ __forceinline__ float
__add ( float const a,  float const b )
{
#    ifdef __CUDA_ARCH__
  return __fadd_rn ( a, b );
#    else
  float const t = (a + b);
  return  t;
#    endif
}

__host__ __device__ __forceinline__ void
add2 ( float const a1, float const b1, float &d1,
       float const a2, float const b2, float &d2 )
{
  float const t1 = __add( a1, b1 );
  float const t2 = __add( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ float
__sub ( float const a,  float const b )
{
#    ifdef __CUDA_ARCH__
  return __fsub_rn ( a, b );
#    else
  float const t = (a - b);
  return  t;
#    endif
}

__host__ __device__ __forceinline__ void
sub2 ( float const a1, float const b1, float &d1,
       float const a2, float const b2, float &d2 )
{
  float const t1 = __sub( a1, b1 );
  float const t2 = __sub( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ float
__mul ( float const a,  float const b )
{
#    ifdef __CUDA_ARCH__
  return __fmul_rn ( a, b );
#    else
  float const t = (a * b);
  return  t;
#    endif
}

__host__ __device__ __forceinline__ void
mul2 ( float const a1, float const b1, float &d1,
       float const a2, float const b2, float &d2 )
{
  float const t1 = __mul( a1, b1 );
  float const t2 = __mul( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
fma2 ( float const a1, float const b1, float const c1, float &d1,
       float const a2, float const b2, float const c2, float &d2 )
{
  float const t1 = fma( a1, b1, c1 );
  float const t2 = fma( a2, b2, c2 );
  d1 = t1; d2 = t2;
}

#    if !defined(__CUDA_ARCH__)
#      if __GNUC__ < 6
__host__ __device__ __forceinline__ int
isfinite ( float const a )
{
  union {
    float f;
    unsigned int  u;
  } x;
  x.f = a;
  x.u &= 0x7f800000;
  return (x.u != 0x7f800000);
}
#      endif
#    endif

__host__ __device__ __forceinline__ float
Abs ( float const a )
{
  return (fabsf(a));
}

__host__ __device__ __forceinline__ float
Conj ( float const a )
{
  return (a);
}

__host__ __device__ __forceinline__ float
__choose__ ( bool const flag, float const a, float const b )
{
  return (flag ? a : b);
}

// for double

__host__ __device__ __forceinline__ double
__add ( double const a,  double const b )
{
#    ifdef __CUDA_ARCH__
  return __dadd_rn ( a, b );
#    else
  double const t = (a + b);
  return  t;
#    endif
}

__host__ __device__ __forceinline__ void
add2 ( double const a1, double const b1, double &d1,
       double const a2, double const b2, double &d2 )
{
  double const t1 = __add( a1, b1 );
  double const t2 = __add( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ double
__sub ( double const a,  double const b )
{
#    ifdef __CUDA_ARCH__
  return __dsub_rn ( a, b );
#    else
  double const t = (a - b);
  return  t;
#    endif
}

__host__ __device__ __forceinline__ void
sub2 ( double const a1, double const b1, double &d1,
       double const a2, double const b2, double &d2 )
{
  double const t1 = __sub( a1, b1 );
  double const t2 = __sub( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ double
__mul ( double const a,  double const b )
{
#    ifdef __CUDA_ARCH__
  return __dmul_rn ( a, b );
#    else
  double const t = (a * b);
  return  t;
#    endif
}

__host__ __device__ __forceinline__ void
mul2 ( double const a1, double const b1, double &d1,
       double const a2, double const b2, double &d2 )
{
  double const t1 = __mul( a1, b1 );
  double const t2 = __mul( a2, b2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
fma2 ( double const a1, double const b1, double const c1, double &d1,
       double const a2, double const b2, double const c2, double &d2 )
{
  double const t1 = fma( a1, b1, c1 );
  double const t2 = fma( a2, b2, c2 );
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ double
Abs ( double const a )
{
  return (fabs(a));
}

__host__ __device__ __forceinline__ double
Conj ( double const a )
{
  return (a);
}

__host__ __device__ __forceinline__ double
__choose__ ( bool const flag, double const a, double const b )
{
  return (flag ? a : b);
}

#  endif

#endif

