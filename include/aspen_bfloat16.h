#ifndef ASPEN_BFLOAT16_H_INCLUDED
#  define ASPEN_BFLOAT16_H_INCLUDED		1

#  ifdef __cplusplus

struct __align__(4) __bfloat16__t_
{
 public:
  unsigned short x;
 public:
  __host__ __device__ __forceinline__
    operator float() const {
#    if defined(__CUDA_ARCH__)
    float t;
    unsigned short zero = 0;
    asm volatile ( "mov.b32 %0, {%1, %2};"
                   : "=f"(t) : "h"(zero), "h"(x) );
    return t;
#    else
    union {
      unsigned short x[2];
      float y;
    } u;
    u.x[1] = x; u.x[0] = 0;
    return u.y;
#    endif
  }
 public:
  __host__ __device__ __forceinline__
    operator double() const {
    return (double)((float)*this);
  }
};

typedef	struct __bfloat16__t_	bfloat16;


#    ifdef __cplusplus

#      if GPU_ARCH>300
__device__ __forceinline__ bfloat16
__ldg ( bfloat16 const * __restrict__ const a )
{
  bfloat16 t; t.x = __ldg( &(a->x) );
  return t;
}
#      endif

__host__ __device__ __forceinline__ bfloat16
__f32tobf16__( float const p )
{
#      if defined(__CUDA_ARCH__)
  bfloat16 t;
  asm volatile ( "{ .reg.b16 %temp; mov.b32 {%temp, %0}, %1; }"
                 : "=h"(t.x) : "f"(p) );
#      else
  union {
    unsigned short x[2];
    float y;
  } u;
  u.y = p;
  bfloat16 t;
  t.x = u.x[1];
#      endif
  return t;
}

__host__ __device__ __forceinline__ float
__bf16tof32__( bfloat16 const p )
{
  return (float)p;
}


__host__ __device__ __forceinline__ bool
operator== ( bfloat16 const a, bfloat16 const b )
{
  bool const ret = (a.x == b.x) ? true : false;
  return ret;
}

__host__ __device__ __forceinline__ bool
operator!= ( bfloat16 const a, bfloat16 const b )
{
  bool const ret = (a.x != b.x) ? true : false;
  return ret;
}


__host__ __device__ __forceinline__ bfloat16
operator+ ( bfloat16 const a )
{
  return (a);
}

__host__ __device__ __forceinline__ bfloat16
operator+ ( bfloat16 const a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 + u1 );
  return t;
}

__host__ __device__ __forceinline__ void
operator+= ( bfloat16 &a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 + u1 );
  a.x = t.x;
}

__host__ __device__ __forceinline__ bfloat16
operator- ( bfloat16 const a )
{
  float const u0 = __bf16tof32__( a );
  bfloat16 const t = __f32tobf16__( -u0 );
  return t;
}

__host__ __device__ __forceinline__ bfloat16
operator- ( bfloat16 const a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 - u1 );
  return t;
}

__host__ __device__ __forceinline__ void
operator-= ( bfloat16 &a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 - u1 );
  a.x = t.x;
}

__host__ __device__ __forceinline__ bfloat16
operator* ( bfloat16 const a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 * u1 );
  return t;
}

__host__ __device__ __forceinline__ void
operator*= ( bfloat16 &a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 * u1 );
  a.x = t.x;
}

__host__ __device__ __forceinline__ bfloat16
fma ( bfloat16 const a, bfloat16 const b, bfloat16 const c )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  float const u2 = __bf16tof32__( c );
  bfloat16 const t = __f32tobf16__( fmaf(u0, u1, u2) );
  return t;
}

__host__ __device__ __forceinline__ bfloat16
operator/ ( bfloat16 const a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 / u1 );
  return t;
}

__host__ __device__ __forceinline__ void
operator/= ( bfloat16 &a, bfloat16 const b )
{
  float const u0 = __bf16tof32__( a );
  float const u1 = __bf16tof32__( b );
  bfloat16 const t = __f32tobf16__( u0 / u1 );
  a.x = t.x;
}


__host__ __device__ __forceinline__ void
add2 ( bfloat16 const a1, bfloat16 const b1, bfloat16 &d1,
       bfloat16 const a2, bfloat16 const b2, bfloat16 &d2 )
{
  bfloat16 const t1 = a1 + b1;
  bfloat16 const t2 = a2 + b2;
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
sub2 ( bfloat16 const a1, bfloat16 const b1, bfloat16 &d1,
       bfloat16 const a2, bfloat16 const b2, bfloat16 &d2 )
{
  bfloat16 const t1 = a1 - b1;
  bfloat16 const t2 = a2 - b2;
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
mul2 ( bfloat16 const a1, bfloat16 const b1, bfloat16 &d1,
       bfloat16 const a2, bfloat16 const b2, bfloat16 &d2 )
{
  bfloat16 const t1 = a1 * b1;
  bfloat16 const t2 = a2 * b2;
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ void
fma2 ( bfloat16 const a1, bfloat16 const b1, bfloat16 const c1, bfloat16 &d1,
       bfloat16 const a2, bfloat16 const b2, bfloat16 const c2, bfloat16 &d2 )
{
  bfloat16 const t1 = fma(a1, b1, c1);
  bfloat16 const t2 = fma(a2, b2, c2);
  d1 = t1; d2 = t2;
}

__host__ __device__ __forceinline__ int
isnan ( bfloat16 const a )
{
  float const u0 = __bf16tof32__( a );
  return isnan( u0 );
}

__host__ __device__ __forceinline__ int
isinf ( bfloat16 const a )
{
  float const u0 = __bf16tof32__( a );
  return isinf( u0 );
}

__host__ __device__ __forceinline__ int
isfinite ( bfloat16 const a )
{
  float const u0 = __bf16tof32__( a );
  return isfinite( u0 );
}

__host__ __device__ __forceinline__ bfloat16
Abs ( bfloat16 const a )
{
  float const u0 = __bf16tof32__( a );
  bfloat16 const t = __f32tobf16__( fabs(u0) );
  return t;
}

__host__ __device__ __forceinline__ bfloat16
Conj ( bfloat16 const a )
{
  return a;
}

__host__ __device__ __forceinline__ bfloat16
__choose__ ( bool const flag, bfloat16 const a, bfloat16 const b )
{
  bfloat16 t; t.x = ( flag ? a.x : b.x );
  return t;
}

__forceinline__ __device__ bfloat16
__choose__( int const cond, bfloat16 const case_pos, bfloat16 const case_neg )
{
  bfloat16 r;
  asm volatile ( "slct.b16.s32\t%0, %1, %2, %3;"
                 : "=h"(r.x) : "h"(case_pos.x), "h"(case_neg.x), "r"(cond) );
  return r;
}

#    endif

#  else

typedef struct __align__(4) {
  int16_t x;
} __bfloat16_raw__;

typedef __bfloat16_raw__	bfloat16;

#  endif

#endif

