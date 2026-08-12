#ifndef ASPEN_LDST_H_INCLUDED
#define ASPEN_LDST_H_INCLUDED           1

#include "aspen_types.h"
#include "aspen_shmem.h"
#include "aspen_const.h"

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Volatile ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Volatile ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.volatile.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Volatile ( double const * __restrict__ const addr__ )
{
  double volatile * addr = (double *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ float
Load_Volatile ( float const * __restrict__ const addr__ )
{
  float volatile * addr = (float *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Volatile ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.volatile.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.volatile.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Volatile ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.volatile.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Volatile ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.volatile.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Volatile ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.volatile.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Volatile ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.volatile.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Volatile ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.volatile.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Volatile ( int64 const * __restrict__ const addr__ )
{
  int64 volatile * addr = (int64 *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ int32
Load_Volatile ( int32 const * __restrict__ const addr__ )
{
  int32 volatile * addr = (int32 *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ int16
Load_Volatile ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.volatile.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_CG ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_CG ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_CG ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.cg.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_CG ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.cg.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_CG ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_CG ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_CG ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.cg.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_CG ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.cg.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_CG ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.cg.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_CG ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.cg.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_CG ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.cg.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_CG ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.cg.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_CG ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.cg.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_CV ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_CV ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_CV ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.cv.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_CV ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.cv.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_CV ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_CV ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_CV ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.cv.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_CV ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.cv.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_CV ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.cv.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_CV ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.cv.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_CV ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.cv.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_CV ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.cv.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_CV ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.cv.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_LU ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_LU ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_LU ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.lu.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_LU ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.lu.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_LU ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_LU ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_LU ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.lu.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_LU ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.lu.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_LU ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.lu.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_LU ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.lu.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_LU ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.lu.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_LU ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.lu.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_LU ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.lu.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_CS ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_CS ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_CS ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.cs.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_CS ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.cs.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_CS ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_CS ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_CS ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.cs.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_CS ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.cs.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_CS ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.cs.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_CS ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.cs.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_CS ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.cs.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_CS ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.cs.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_CS ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.cs.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Global ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Global ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.global.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Global ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.global.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Global ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Global ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Global ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.global.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Global ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.global.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Global ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.global.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Global ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.global.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Global ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.global.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Global ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.global.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Global ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.global.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Volatile_Global ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Volatile_Global ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.volatile.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Volatile_Global ( double const * __restrict__ const addr__ )
{
  double volatile * addr = (double *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ float
Load_Volatile_Global ( float const * __restrict__ const addr__ )
{
  float volatile * addr = (float *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Volatile_Global ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.volatile.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.volatile.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Volatile_Global ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.volatile.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Volatile_Global ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.volatile.global.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Volatile_Global ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.volatile.global.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Volatile_Global ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.volatile.global.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Volatile_Global ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.volatile.global.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Volatile_Global ( int64 const * __restrict__ const addr__ )
{
  int64 volatile * addr = (int64 *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ int32
Load_Volatile_Global ( int32 const * __restrict__ const addr__ )
{
  int32 volatile * addr = (int32 *)addr__;
  return *addr;
}

template < >
__forceinline__ __device__ int16
Load_Volatile_Global ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.volatile.global.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global_CG ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Global_CG ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Global_CG ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.global.cg.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Global_CG ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.global.cg.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Global_CG ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.global.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.global.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Global_CG ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.cg.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Global_CG ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.global.cg.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Global_CG ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.global.cg.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Global_CG ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.global.cg.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Global_CG ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.global.cg.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Global_CG ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.global.cg.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Global_CG ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.global.cg.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Global_CG ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.global.cg.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global_CV ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Global_CV ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Global_CV ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.global.cv.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Global_CV ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.global.cv.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Global_CV ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.global.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.global.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Global_CV ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.cv.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Global_CV ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.global.cv.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Global_CV ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.global.cv.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Global_CV ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.global.cv.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Global_CV ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.global.cv.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Global_CV ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.global.cv.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Global_CV ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.global.cv.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Global_CV ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.global.cv.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global_LU ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Global_LU ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Global_LU ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.global.lu.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Global_LU ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.global.lu.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Global_LU ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.global.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.global.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Global_LU ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.lu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Global_LU ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.global.lu.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Global_LU ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.global.lu.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Global_LU ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.global.lu.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Global_LU ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.global.lu.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Global_LU ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.global.lu.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Global_LU ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.global.lu.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Global_LU ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.global.lu.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global_CS ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Global_CS ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Global_CS ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.global.cs.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Global_CS ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.global.cs.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Global_CS ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.global.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.global.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Global_CS ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.cs.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Global_CS ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.global.cs.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Global_CS ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.global.cs.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Global_CS ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.global.cs.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Global_CS ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.global.cs.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Global_CS ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.global.cs.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Global_CS ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.global.cs.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Global_CS ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.global.cs.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global_NC ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Global_NC ( cuddreal const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.nc.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;
}

template < >
__forceinline__ __device__ double
Load_Global_NC ( double const * __restrict__ const addr__ )
{
  double u;
  asm volatile ( "ld.global.nc.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Global_NC ( float const * __restrict__ const addr__ )
{
  float u;
  asm volatile ( "ld.global.nc.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Global_NC ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.global.nc.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.global.nc.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;
}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Global_NC ( cuDoubleComplex const * __restrict__ const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.global.nc.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Global_NC ( cuFloatComplex const * __restrict__ const addr__ )
{
  struct { float sx; float sy; } u;
  asm volatile ( "ld.global.nc.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Global_NC ( cuHalfComplex const * __restrict__ const addr__ )
{
  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.global.nc.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;
}

template < >
__forceinline__ __device__ half
Load_Global_NC ( half const * __restrict__ const addr__ )
{
  ushort u;
  asm volatile ( "ld.global.nc.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Global_NC ( int128 const * __restrict__ const addr__ )
{
  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.global.nc.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int64
Load_Global_NC ( int64 const * __restrict__ const addr__ )
{
  int64_t u;
  asm volatile ( "ld.global.nc.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Global_NC ( int32 const * __restrict__ const addr__ )
{
  int32_t u;
  asm volatile ( "ld.global.nc.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Global_NC ( int16 const * __restrict__ const addr__ )
{
  int16_t u;
  asm volatile ( "ld.global.nc.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Relaxed ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddreal
Load_Relaxed ( cuddreal const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.relaxed.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ double
Load_Relaxed ( double const * __restrict__ const addr__ )
{

  double u;
  asm volatile ( "ld.relaxed.gpu.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ float
Load_Relaxed ( float const * __restrict__ const addr__ )
{

  float u;
  asm volatile ( "ld.relaxed.gpu.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddcomplex
Load_Relaxed ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.relaxed.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.relaxed.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuDoubleComplex
Load_Relaxed ( cuDoubleComplex const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.relaxed.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuFloatComplex
Load_Relaxed ( cuFloatComplex const * __restrict__ const addr__ )
{

  struct { float sx; float sy; } u;
  asm volatile ( "ld.relaxed.gpu.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuHalfComplex
Load_Relaxed ( cuHalfComplex const * __restrict__ const addr__ )
{

  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.relaxed.gpu.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ half
Load_Relaxed ( half const * __restrict__ const addr__ )
{

  ushort u;
  asm volatile ( "ld.relaxed.gpu.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int128
Load_Relaxed ( int128 const * __restrict__ const addr__ )
{

  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.relaxed.gpu.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int64
Load_Relaxed ( int64 const * __restrict__ const addr__ )
{

  int64_t u;
  asm volatile ( "ld.relaxed.gpu.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int32
Load_Relaxed ( int32 const * __restrict__ const addr__ )
{

  int32_t u;
  asm volatile ( "ld.relaxed.gpu.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int16
Load_Relaxed ( int16 const * __restrict__ const addr__ )
{

  int16_t u;
  asm volatile ( "ld.relaxed.gpu.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Acquire ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddreal
Load_Acquire ( cuddreal const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.acquire.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ double
Load_Acquire ( double const * __restrict__ const addr__ )
{

  double u;
  asm volatile ( "ld.acquire.gpu.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ float
Load_Acquire ( float const * __restrict__ const addr__ )
{

  float u;
  asm volatile ( "ld.acquire.gpu.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddcomplex
Load_Acquire ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.acquire.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.acquire.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuDoubleComplex
Load_Acquire ( cuDoubleComplex const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.acquire.gpu.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuFloatComplex
Load_Acquire ( cuFloatComplex const * __restrict__ const addr__ )
{

  struct { float sx; float sy; } u;
  asm volatile ( "ld.acquire.gpu.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuHalfComplex
Load_Acquire ( cuHalfComplex const * __restrict__ const addr__ )
{

  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.acquire.gpu.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ half
Load_Acquire ( half const * __restrict__ const addr__ )
{

  ushort u;
  asm volatile ( "ld.acquire.gpu.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int128
Load_Acquire ( int128 const * __restrict__ const addr__ )
{

  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.acquire.gpu.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int64
Load_Acquire ( int64 const * __restrict__ const addr__ )
{

  int64_t u;
  asm volatile ( "ld.acquire.gpu.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int32
Load_Acquire ( int32 const * __restrict__ const addr__ )
{

  int32_t u;
  asm volatile ( "ld.acquire.gpu.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int16
Load_Acquire ( int16 const * __restrict__ const addr__ )
{

  int16_t u;
  asm volatile ( "ld.acquire.gpu.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Relaxed_Global ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddreal
Load_Relaxed_Global ( cuddreal const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.relaxed.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ double
Load_Relaxed_Global ( double const * __restrict__ const addr__ )
{

  double u;
  asm volatile ( "ld.relaxed.gpu.global.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ float
Load_Relaxed_Global ( float const * __restrict__ const addr__ )
{

  float u;
  asm volatile ( "ld.relaxed.gpu.global.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddcomplex
Load_Relaxed_Global ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.relaxed.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.relaxed.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuDoubleComplex
Load_Relaxed_Global ( cuDoubleComplex const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.relaxed.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuFloatComplex
Load_Relaxed_Global ( cuFloatComplex const * __restrict__ const addr__ )
{

  struct { float sx; float sy; } u;
  asm volatile ( "ld.relaxed.gpu.global.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuHalfComplex
Load_Relaxed_Global ( cuHalfComplex const * __restrict__ const addr__ )
{

  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.relaxed.gpu.global.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ half
Load_Relaxed_Global ( half const * __restrict__ const addr__ )
{

  ushort u;
  asm volatile ( "ld.relaxed.gpu.global.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int128
Load_Relaxed_Global ( int128 const * __restrict__ const addr__ )
{

  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.relaxed.gpu.global.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int64
Load_Relaxed_Global ( int64 const * __restrict__ const addr__ )
{

  int64_t u;
  asm volatile ( "ld.relaxed.gpu.global.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int32
Load_Relaxed_Global ( int32 const * __restrict__ const addr__ )
{

  int32_t u;
  asm volatile ( "ld.relaxed.gpu.global.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int16
Load_Relaxed_Global ( int16 const * __restrict__ const addr__ )
{

  int16_t u;
  asm volatile ( "ld.relaxed.gpu.global.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Acquire_Global ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddreal
Load_Acquire_Global ( cuddreal const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.acquire.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ double
Load_Acquire_Global ( double const * __restrict__ const addr__ )
{

  double u;
  asm volatile ( "ld.acquire.gpu.global.b64 %0, [%1];"
                 : "=d"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ float
Load_Acquire_Global ( float const * __restrict__ const addr__ )
{

  float u;
  asm volatile ( "ld.acquire.gpu.global.b32 %0, [%1];"
                 : "=f"(u) : "l"(addr__) );
  return u;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuddcomplex
Load_Acquire_Global ( cuddcomplex const * __restrict__ const addr__ )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double sx; double sy; } v_type;
  cuddcomplex * addr_ = (cuddcomplex *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld.acquire.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<cuddreal *>(&u));
  asm volatile ( "ld.acquire.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<cuddreal *>(&v));
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuDoubleComplex
Load_Acquire_Global ( cuDoubleComplex const * __restrict__ const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.acquire.gpu.global.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "l"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuFloatComplex
Load_Acquire_Global ( cuFloatComplex const * __restrict__ const addr__ )
{

  struct { float sx; float sy; } u;
  asm volatile ( "ld.acquire.gpu.global.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "l"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ cuHalfComplex
Load_Acquire_Global ( cuHalfComplex const * __restrict__ const addr__ )
{

  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.acquire.gpu.global.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "l"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ half
Load_Acquire_Global ( half const * __restrict__ const addr__ )
{

  ushort u;
  asm volatile ( "ld.acquire.gpu.global.b16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int128
Load_Acquire_Global ( int128 const * __restrict__ const addr__ )
{

  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.acquire.gpu.global.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "l"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int64
Load_Acquire_Global ( int64 const * __restrict__ const addr__ )
{

  int64_t u;
  asm volatile ( "ld.acquire.gpu.global.u64 %0, [%1];"
                 : "=l"(u) : "l"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int32
Load_Acquire_Global ( int32 const * __restrict__ const addr__ )
{

  int32_t u;
  asm volatile ( "ld.acquire.gpu.global.u32 %0, [%1];"
                 : "=r"(u) : "l"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ int16
Load_Acquire_Global ( int16 const * __restrict__ const addr__ )
{

  int16_t u;
  asm volatile ( "ld.acquire.gpu.global.u16 %0, [%1];"
                 : "=h"(u) : "l"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Volatile ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Volatile ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.volatile.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.volatile.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.volatile.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.volatile.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_Volatile ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.volatile.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.volatile.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.volatile.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.volatile.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_CG ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_CG ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cg.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CG ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.cg.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CG ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.cg.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CG ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.cg.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.cg.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_CG ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cg.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CG ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cg.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CG ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cg.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CG ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.cg.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CG ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cg.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CG ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.cg.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CG ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.cg.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CG ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.cg.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_WB ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_WB ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wb.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WB ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.wb.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WB ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.wb.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WB ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.wb.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.wb.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_WB ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wb.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WB ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wb.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WB ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wb.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WB ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.wb.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WB ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wb.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WB ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.wb.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WB ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.wb.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WB ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.wb.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_CS ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_CS ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cs.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CS ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.cs.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CS ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.cs.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CS ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.cs.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.cs.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_CS ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cs.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CS ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cs.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CS ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cs.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CS ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.cs.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CS ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.cs.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_CS ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.cs.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CS ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.cs.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_CS ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.cs.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_WT ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_WT ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wt.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WT ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.wt.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WT ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.wt.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WT ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.wt.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.wt.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_WT ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wt.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WT ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wt.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WT ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wt.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WT ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.wt.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WT ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.wt.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_WT ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.wt.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WT ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.wt.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_WT ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.wt.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Global ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Global ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.global.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.global.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_Global ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.global.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.global.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.global.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.global.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Volatile_Global ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.volatile.global.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.volatile.global.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.volatile.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.volatile.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.global.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.global.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.volatile.global.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.global.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.volatile.global.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.volatile.global.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Global ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.volatile.global.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Global_CG ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Global_CG ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cg.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CG ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.global.cg.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CG ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.global.cg.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CG ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.global.cg.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.global.cg.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_Global_CG ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cg.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CG ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cg.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CG ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cg.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CG ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.global.cg.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CG ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cg.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CG ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.global.cg.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CG ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.global.cg.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CG ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.global.cg.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Global_WB ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Global_WB ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wb.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WB ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.global.wb.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WB ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.global.wb.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WB ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.global.wb.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.global.wb.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_Global_WB ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wb.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WB ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wb.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WB ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wb.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WB ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.global.wb.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WB ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wb.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WB ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.global.wb.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WB ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.global.wb.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WB ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.global.wb.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Global_CS ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Global_CS ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cs.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CS ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.global.cs.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CS ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.global.cs.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CS ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.global.cs.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.global.cs.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_Global_CS ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cs.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CS ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cs.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CS ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cs.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CS ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.global.cs.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CS ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.cs.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_CS ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.global.cs.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CS ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.global.cs.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_CS ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.global.cs.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Global_WT ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Global_WT ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wt.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WT ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.global.wt.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WT ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.global.wt.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WT ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.global.wt.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.global.wt.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}

template < >
__forceinline__ __device__ void
Store_Global_WT ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wt.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WT ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wt.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WT ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wt.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WT ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.global.wt.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WT ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.global.wt.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Global_WT ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.global.wt.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WT ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.global.wt.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Global_WT ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.global.wt.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ void
Store_Release ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.release.gpu.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.release.gpu.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.release.gpu.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.release.gpu.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.release.gpu.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.release.gpu.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.release.gpu.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.release.gpu.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ void
Store_Relaxed ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.relaxed.gpu.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.relaxed.gpu.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.relaxed.gpu.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.relaxed.gpu.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.relaxed.gpu.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.relaxed.gpu.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.relaxed.gpu.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.relaxed.gpu.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ void
Store_Release_Global ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.release.gpu.global.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.release.gpu.global.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.release.gpu.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.release.gpu.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.global.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.global.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.release.gpu.global.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.release.gpu.global.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.release.gpu.global.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.release.gpu.global.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Release_Global ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.release.gpu.global.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ void
Store_Relaxed_Global ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( cuddreal * __restrict__ const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( double * __restrict__ const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.b64 [%1], %0;"
                 : : "d"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( float * __restrict__ const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.b32 [%1], %0;"
                 : : "f"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( cuddcomplex * __restrict__ const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.relaxed.gpu.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st.relaxed.gpu.global.v2.f64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "l"(&addr___->y) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( cuDoubleComplex * __restrict__ const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( cuFloatComplex * __restrict__ const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( cuHalfComplex * __restrict__ const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( half * __restrict__ const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.b16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( int128 * __restrict__ const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "l"(addr__) );

}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( int64 * __restrict__ const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.u64 [%1], %0;"
                 : : "l"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( int32 * __restrict__ const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.u32 [%1], %0;"
                 : : "r"(t), "l"(addr__) );
}
#endif

#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store_Relaxed_Global ( int16 * __restrict__ const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.relaxed.gpu.global.u16 [%1], %0;"
                 : : "h"(t), "l"(addr__) );
}
#endif

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Shared ( SHMEM_addr_t const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Shared ( SHMEM_addr_t const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "r"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;

}

template < >
__forceinline__ __device__ double
Load_Shared ( SHMEM_addr_t const addr__ )
{

  double u;
  asm volatile ( "ld.shared.b64 %0, [%1];"
                 : "=d"(u) : "r"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Shared ( SHMEM_addr_t const addr__ )
{

  float u;
  asm volatile ( "ld.shared.b32 %0, [%1];"
                 : "=f"(u) : "r"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Shared ( SHMEM_addr_t const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "r"(addr__) );
  cuddreal const tx = *(reinterpret_cast<cuddreal *>(&u));
  struct { double sx; double sy; } v;
  SHMEM_addr_t const bddr__ = addr__ + sizeof(cuddreal);
  asm volatile ( "ld.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "r"(bddr__) );
  cuddreal const ty = *(reinterpret_cast<cuddreal *>(&v));
  struct { cuddreal tx; cuddreal ty; } w = { tx, ty };
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;

}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Shared ( SHMEM_addr_t const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "r"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;

}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Shared ( SHMEM_addr_t const addr__ )
{

  struct { float sx; float sy; } u;
  asm volatile ( "ld.shared.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "r"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;

}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Shared ( SHMEM_addr_t const addr__ )
{

  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.shared.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "r"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;

}

template < >
__forceinline__ __device__ half
Load_Shared ( SHMEM_addr_t const addr__ )
{

  ushort u;
  asm volatile ( "ld.shared.b16 %0, [%1];"
                 : "=h"(u) : "r"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Shared ( SHMEM_addr_t const addr__ )
{

  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.shared.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "r"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;

}

template < >
__forceinline__ __device__ int64
Load_Shared ( SHMEM_addr_t const addr__ )
{

  int64_t u;
  asm volatile ( "ld.shared.u64 %0, [%1];"
                 : "=l"(u) : "r"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Shared ( SHMEM_addr_t const addr__ )
{

  int32_t u;
  asm volatile ( "ld.shared.u32 %0, [%1];"
                 : "=r"(u) : "r"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Shared ( SHMEM_addr_t const addr__ )
{

  int16_t u;
  asm volatile ( "ld.shared.u16 %0, [%1];"
                 : "=h"(u) : "r"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.shared.b64 [%1], %0;"
                 : : "d"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.shared.b32 [%1], %0;"
                 : : "f"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "r"(addr__) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  SHMEM_addr_t const bddr__ = addr__ + sizeof(cuddreal);
  asm volatile ( "st.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "r"(bddr__) );

}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.shared.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.shared.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.shared.b16 [%1], %0;"
                 : : "h"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.shared.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.shared.u64 [%1], %0;"
                 : : "l"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.shared.u32 [%1], %0;"
                 : : "r"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Shared ( SHMEM_addr_t const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.shared.u16 [%1], %0;"
                 : : "h"(t), "r"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{ return makeCONST <TYPE> (0); }

template < >
__forceinline__ __device__ cuddreal
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.volatile.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "r"(addr__) );
  cuddreal const t = *(reinterpret_cast<cuddreal *>(&u));
  return t;

}

template < >
__forceinline__ __device__ double
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  double u;
  asm volatile ( "ld.volatile.shared.b64 %0, [%1];"
                 : "=d"(u) : "r"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ float
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  float u;
  asm volatile ( "ld.volatile.shared.b32 %0, [%1];"
                 : "=f"(u) : "r"(addr__) );
  return u;
}

template < >
__forceinline__ __device__ cuddcomplex
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{
  struct { double sx; double sy; } u;
  asm volatile ( "ld.volatile.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "r"(addr__) );
  cuddreal const tx = *(reinterpret_cast<cuddreal *>(&u));
  struct { double sx; double sy; } v;
  SHMEM_addr_t const bddr__ = addr__ + sizeof(cuddreal);
  asm volatile ( "ld.volatile.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(v.sx), "=d"(v.sy) : "r"(bddr__) );
  cuddreal const ty = *(reinterpret_cast<cuddreal *>(&v));
  struct { cuddreal tx; cuddreal ty; } w = { tx, ty };
  cuddcomplex const t = *(reinterpret_cast<cuddcomplex *>(&w));
  return t;

}

template < >
__forceinline__ __device__ cuDoubleComplex
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  struct { double sx; double sy; } u;
  asm volatile ( "ld.volatile.shared.v2.b64 {%0,%1}, [%2];"
                 : "=d"(u.sx), "=d"(u.sy) : "r"(addr__) );
  cuDoubleComplex const t = *(reinterpret_cast<cuDoubleComplex *>(&u));
  return t;

}

template < >
__forceinline__ __device__ cuFloatComplex
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  struct { float sx; float sy; } u;
  asm volatile ( "ld.volatile.shared.v2.b32 {%0,%1}, [%2];"
                 : "=f"(u.sx), "=f"(u.sy) : "r"(addr__) );
  cuFloatComplex const t = *(reinterpret_cast<cuFloatComplex *>(&u));
  return t;

}

template < >
__forceinline__ __device__ cuHalfComplex
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  struct { ushort sx; ushort sy; } u;
  asm volatile ( "ld.volatile.shared.v2.b16 {%0,%1}, [%2];"
                 : "=h"(u.sx), "=h"(u.sy) : "r"(addr__) );
  cuHalfComplex const t = *(reinterpret_cast<cuHalfComplex *>(&u));
  return t;

}

template < >
__forceinline__ __device__ half
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  ushort u;
  asm volatile ( "ld.volatile.shared.b16 %0, [%1];"
                 : "=h"(u) : "r"(addr__) );
  half const t = *(reinterpret_cast<half *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int128
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  struct { uint64_t sx; uint64_t sy; } u;
  asm volatile ( "ld.volatile.shared.v2.u64 {%0,%1}, [%2];"
                 : "=l"(u.sx), "=l"(u.sy) : "r"(addr__) );
  int128 const t = *(reinterpret_cast<int128 *>(&u));
  return t;

}

template < >
__forceinline__ __device__ int64
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  int64_t u;
  asm volatile ( "ld.volatile.shared.u64 %0, [%1];"
                 : "=l"(u) : "r"(addr__) );
  int64 const t = *(reinterpret_cast<int64 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int32
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  int32_t u;
  asm volatile ( "ld.volatile.shared.u32 %0, [%1];"
                 : "=r"(u) : "r"(addr__) );
  int32 const t = *(reinterpret_cast<int32 *>(&u));
  return t;
}

template < >
__forceinline__ __device__ int16
Load_Volatile_Shared ( SHMEM_addr_t const addr__ )
{

  int16_t u;
  asm volatile ( "ld.volatile.shared.u16 %0, [%1];"
                 : "=h"(u) : "r"(addr__) );
  int16 const t = *(reinterpret_cast<int16 *>(&u));
  return t;
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, TYPE const s )
{ ; }

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, cuddreal const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuddreal ss = static_cast<cuddreal>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, double const s )
{

  double ss = static_cast<double>(s);
  double t = *(reinterpret_cast<double *>(&ss));
  asm volatile ( "st.volatile.shared.b64 [%1], %0;"
                 : : "d"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, float const s )
{

  float ss = static_cast<float>(s);
  float t = *(reinterpret_cast<float *>(&ss));
  asm volatile ( "st.volatile.shared.b32 [%1], %0;"
                 : : "f"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, cuddcomplex const s )
{
  typedef struct { cuddreal x; cuddreal y; } u_type;
  typedef struct { double x; double y; } v_type;
  cuddcomplex ss = static_cast<cuddcomplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st.volatile.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(v1.x), "d"(v1.y), "r"(addr__) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  SHMEM_addr_t const bddr__ = addr__ + sizeof(cuddreal);
  asm volatile ( "st.volatile.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(v2.x), "d"(v2.y), "r"(bddr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, cuDoubleComplex const s )
{

  typedef struct { double sx; double sy; } u_type;
  cuDoubleComplex ss = static_cast<cuDoubleComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.shared.v2.b64 [%2], {%0,%1};"
                 : : "d"(u.sx), "d"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, cuFloatComplex const s )
{

  typedef struct { float sx; float sy; } u_type;
  cuFloatComplex ss = static_cast<cuFloatComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.shared.v2.b32 [%2], {%0,%1};"
                 : : "f"(u.sx), "f"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, cuHalfComplex const s )
{

  typedef struct { ushort sx; ushort sy; } u_type;
  cuHalfComplex ss = static_cast<cuHalfComplex>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.shared.v2.b16 [%2], {%0,%1};"
                 : : "h"(u.sx), "h"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, half const s )
{

  half ss = static_cast<half>(s);
  ushort t = *(reinterpret_cast<ushort *>(&ss));
  asm volatile ( "st.volatile.shared.b16 [%1], %0;"
                 : : "h"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, int128 const s )
{

  typedef struct { uint64_t sx; uint64_t sy; } u_type;
  int128 ss = static_cast<int128>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st.volatile.shared.v2.u64 [%2], {%0,%1};"
                 : : "l"(u.sx), "l"(u.sy), "r"(addr__) );

}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, int64 const s )
{

  int64 ss = static_cast<int64>(s);
  int64_t t = *(reinterpret_cast<int64_t *>(&ss));
  asm volatile ( "st.volatile.shared.u64 [%1], %0;"
                 : : "l"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, int32 const s )
{

  int32 ss = static_cast<int32>(s);
  int32_t t = *(reinterpret_cast<int32_t *>(&ss));
  asm volatile ( "st.volatile.shared.u32 [%1], %0;"
                 : : "r"(t), "r"(addr__) );
}

template < >
__forceinline__ __device__ void
Store_Volatile_Shared ( SHMEM_addr_t const addr__, int16 const s )
{

  int16 ss = static_cast<int16>(s);
  int16_t t = *(reinterpret_cast<int16_t *>(&ss));
  asm volatile ( "st.volatile.shared.u16 [%1], %0;"
                 : : "h"(t), "r"(addr__) );
}

// ---------------------------------------------------------

// ---------------------------------------------------------
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global_with_Confirm( TYPE * addr__ )
{
  return Load_Acquire_Global ( addr__ );
}

template < class TYPE >
__forceinline__ __device__ void
Store_Global_with_Confirm_sub( TYPE * addr__, TYPE const s )
{
  Store_Global ( addr__, s );
  __threadfence ( );
#pragma unroll 1
  while ( true ) {
    __nanosleep__(0);
    if ( s == Load_Global_CV ( addr__ ) ) break;
  }
}

template < class TYPE >
__forceinline__ __device__ void
Store_Global_with_Confirm( TYPE * addr__, TYPE const s )
{
  TYPE ss = (TYPE)s;
  switch ( 8 * sizeof(TYPE) ) {
  case 16:
    {
      int16 t = *(reinterpret_cast<int16 *>(&ss));
      int16 * addr_ = (reinterpret_cast<int16 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 32:
    {
      int32 t = *(reinterpret_cast<int32 *>(&ss));
      int32 * addr_ = (reinterpret_cast<int32 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 64:
    {
      int64 t = *(reinterpret_cast<int64 *>(&ss));
      int64 * addr_ = (reinterpret_cast<int64 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 128:
    {
      int128 t = *(reinterpret_cast<int128 *>(&ss));
      int128 * addr_ = (reinterpret_cast<int128 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 256:
    {
      typedef struct { int128 sx; int128 sy; } u_type;
      u_type u = *(reinterpret_cast<u_type *>(&ss));
      u_type * addr_ = (reinterpret_cast<u_type *>(addr__));
      Store_Global_with_Confirm_sub ( &addr_->sx, u.sx );
      Store_Global_with_Confirm_sub ( &addr_->sy, u.sy );
    }
    break;
  }
}

// ---------------------------------------------------------
 
// ---------------------------------------------------------

#define	__PROXY_SHMEM_DECL__(...)	extern __shared__ int __shmem[]

__PROXY_SHMEM_DECL__();

__forceinline__ __device__ unsigned int
shared_memory_size_per_block( void )
{
  unsigned int ret;
  asm volatile ( "mov.s32 %0, %dynamic_smem_size;" : "=r"(ret) );
  return ret;
}

__forceinline__ __device__ SHMEM_addr_t
shared_memory_raw_proxy_root( void )
{
  SHMEM_addr_t ret;
  asm volatile ( "mov.u32 %0, __shmem;" : "=r"(ret) );
  return ret;
}

template < class TYPE >
__forceinline__ __device__ TYPE *
shared_memory_proxy_root( void )
{
  return reinterpret_cast<TYPE *>(__shmem);
}

template < class TYPE >
__forceinline__ __device__ SHMEM_addr_t
shared_memory_raw_proxy( int const offset )
{
  return shared_memory_raw_proxy_root ( ) + sizeof(TYPE) * offset;
}

template < class TYPE >
__forceinline__ __device__ TYPE *
shared_memory_proxy( void )
{
  int * ret = shared_memory_proxy_root < int > ( );
  return reinterpret_cast<TYPE *>(ret);
}

template < class TYPE >
__forceinline__ __device__ TYPE *
shared_memory_proxy( int const offset )
{
  return shared_memory_proxy <TYPE> ( ) + offset;
}

#if 0
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Shared_from_BASE ( int const offset )
{
  TYPE * shmem = shared_memory_proxy < TYPE > ( offset );
  return *shmem;
}

template < class TYPE >
__forceinline__ __device__ TYPE
Load_Volatile_Shared_from_BASE ( int const offset )
{
  SHMEM_addr_t const shmem = shared_memory_raw_proxy < TYPE > ( offset );
  return Load_Volatile_Shared < TYPE > ( shmem );
}

template < class TYPE >
__forceinline__ __device__ void
Store_Shared_from_BASE ( int const offset, TYPE const x )
{
  TYPE * shmem = shared_memory_proxy < TYPE > ( offset );
  *shmem = x;
}

template < class TYPE >
__forceinline__ __device__ void
Store_Volatile_Shared_from_BASE ( int const offset, TYPE const x )
{
  SHMEM_addr_t const shmem = shared_memory_raw_proxy < TYPE > ( offset );
  Store_Volatile_Shared ( shmem, x );
}
#endif
// ---------------------------------------------------------

// ---------------------------------------------------------
__forceinline__ __device__ void *
convert_addr_to_global ( void const * __restrict__ const addr__ )
{
  unsigned long long int  global_addr;
  asm volatile ( "cvta.to.global.u64 %0, %1;"
                 : "=l"(global_addr) : "l"(addr__) );
  return (void *)global_addr;
}

__forceinline__ __device__ SHMEM_addr_t
convert_addr_to_shared ( void const * __restrict__ const addr__ )
{
  SHMEM_addr_t  shared_addr;
  asm volatile ( "{\n\t"
                 ".reg .u32 %temp;\n\t"
                 "cvt.u32.u64 %temp, %1;\n\t"
                 "cvta.to.shared.u32 %0, %temp;\n\t"
                 "}"
                 : "=r"(shared_addr) : "l"(addr__) );
  return shared_addr;
}

__forceinline__ __device__ void
prefetch_L1 ( void const * __restrict__ const addr__ )
{
  unsigned long long int const addr = (unsigned long long int) addr__;
  asm volatile ( "prefetch.global.L1 [%0];"
                 : : "l"(addr) );
}

__forceinline__ __device__ void
prefetch_L2 ( void const * __restrict__ const addr__ )
{
  unsigned long long int const addr = (unsigned long long int) addr__;
  asm volatile ( "prefetch.global.L2 [%0];"
                 : : "l"(addr) );
}
// ---------------------------------------------------------

#endif
