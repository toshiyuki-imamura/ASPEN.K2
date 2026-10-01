#ifndef ASPEN_ATOMIC_H_INCLUDED
#  define ASPEN_ATOMIC_H_INCLUDED		1

#  include "aspen_types.h"

template < typename T_out, typename T_in >
__forceinline__ __device__ T_out const_binary_convert ( T_in const var )
{
  T_in  var_temporal = var;
  T_out const ret = *reinterpret_cast < T_out * >( &var_temporal );
  return ret;
}

//--------------------------------------------------------

static int constexpr	ATOMIC_RELAX		=  0;
static int constexpr 	ATOMIC_STRONG		= -1;

//--------------------------------------------------------
template < typename T >
struct binary_type {
  using type = typename std::conditional_t <
    sizeof(T) == 2, uint16_t, std::conditional_t <
      sizeof(T) == 4, uint32_t, std::conditional_t <
        sizeof(T) == 8, uint64_t, std::conditional_t <
          sizeof(T) == 16, int128, nullptr_t > > > >;
};
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicCAS ( uint16_t * address, uint16_t const sup, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicCAS ( uint32_t * address, uint32_t const sup, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicCAS ( uint64_t * address, uint64_t const sup, uint64_t const val );
__forceinline__ __device__ int128
atomicCAS ( int128 * address, int128 const sup, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicCAS_STRONG ( uint16_t * address, uint16_t const sup, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicCAS_STRONG ( uint32_t * address, uint32_t const sup, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicCAS_STRONG ( uint64_t * address, uint64_t const sup, uint64_t const val );
__forceinline__ __device__ int128
atomicCAS_STRONG ( int128 * address, int128 const sup, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicOr ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicOr ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicOr ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ int128
atomicOr ( int128 * address, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicOr_STRONG ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicOr_STRONG ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicOr_STRONG ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ int128
atomicOr_STRONG ( int128 * address, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicAnd ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicAnd ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicAnd ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ int128
atomicAnd ( int128 * address, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicAnd_STRONG ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicAnd_STRONG ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicAnd_STRONG ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ int128
atomicAnd_STRONG ( int128 * address, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicLoad ( uint16_t * address );
__forceinline__ __device__ uint32_t
atomicLoad ( uint32_t * address );
__forceinline__ __device__ uint64_t
atomicLoad ( uint64_t * address );
__forceinline__ __device__ int128
atomicLoad ( int128 * address );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicLoad_STRONG ( uint16_t * address );
__forceinline__ __device__ uint32_t
atomicLoad_STRONG ( uint32_t * address );
__forceinline__ __device__ uint64_t
atomicLoad_STRONG ( uint64_t * address );
__forceinline__ __device__ int128
atomicLoad_STRONG ( int128 * address );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicExch ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicExch ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicExch ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ int128
atomicExch ( int128 * address, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ uint16_t
atomicExch_STRONG ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ uint32_t
atomicExch_STRONG ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ uint64_t
atomicExch_STRONG ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ int128
atomicExch_STRONG ( int128 * address, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ void
atomicRed ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ void
atomicRed ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ void
atomicRed ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ void
atomicRed ( int128 * address, int128 const val );
//--------------------------------------------------------
__forceinline__ __device__ void
atomicRed_STRONG ( uint16_t * address, uint16_t const val );
__forceinline__ __device__ void
atomicRed_STRONG ( uint32_t * address, uint32_t const val );
__forceinline__ __device__ void
atomicRed_STRONG ( uint64_t * address, uint64_t const val );
__forceinline__ __device__ void
atomicRed_STRONG ( int128 * address, int128 const val );
//--------------------------------------------------------
template < int Op = ATOMIC_RELAX, typename T >
__forceinline__ __device__ T
__ATOMIC_CAS__ ( T * address, T const sup, T const val )
{
  using bin_type = typename binary_type < T > :: type;
  static_assert ( ! std::is_same < bin_type, nullptr_t >::value );

  bin_type * addr = reinterpret_cast < bin_type * > ( address );
  bin_type sup_ = const_binary_convert < bin_type > ( sup );
  bin_type val_ = const_binary_convert < bin_type > ( val );
  bin_type ret_ = makeCONST < bin_type > ( 0 );
  if constexpr ( Op == ATOMIC_RELAX ) {
    ret_ = atomicCAS ( addr, sup_, val_ );
  }
  if constexpr ( Op == ATOMIC_STRONG ) {
    ret_ = atomicCAS_STRONG ( addr, sup_, val_ );
  }
  T ret = const_binary_convert < T > ( ret_ );

  return ret;
}

template < int Op = ATOMIC_RELAX, typename T >
__forceinline__ __device__ T
__ATOMIC_OR__ ( T * address, T const val )
{
  using bin_type = typename binary_type < T > :: type;
  static_assert ( ! std::is_same < bin_type, nullptr_t >::value );

  bin_type * addr = reinterpret_cast < bin_type * > ( address );
  bin_type val_ = const_binary_convert < bin_type > ( val );
  bin_type ret_ = makeCONST < bin_type > ( 0 );
  if constexpr ( Op == ATOMIC_RELAX ) {
    ret_ = atomicOr ( addr, val_ );
  }
  if constexpr ( Op == ATOMIC_STRONG ) {
    ret_ = atomicOr_STRONG ( addr, val_ );
  }
  T ret = const_binary_convert < T > ( ret_ );

  return ret;
}

template < int Op = ATOMIC_RELAX, typename T >
__forceinline__ __device__ T
__ATOMIC_AND__ ( T * address, T const val )
{
  using bin_type = typename binary_type < T > :: type;
  static_assert ( ! std::is_same < bin_type, nullptr_t >::value );

  bin_type * addr = reinterpret_cast < bin_type * > ( address );
  bin_type val_ = const_binary_convert < bin_type > ( val );
  bin_type ret_ = makeCONST < bin_type > ( 0 );
  if constexpr ( Op == ATOMIC_RELAX ) {
    ret_ = atomicAnd ( addr, val_ );
  }
  if constexpr ( Op == ATOMIC_STRONG ) {
    ret_ = atomicAnd_STRONG ( addr, val_ );
  }
  T ret = const_binary_convert < T > ( ret_ );

  return ret;
}

template < int Op = ATOMIC_RELAX, typename T >
__forceinline__ __device__ T
__ATOMIC_LOAD__ ( T * address )
{
  using bin_type = typename binary_type < T > :: type;
  static_assert ( ! std::is_same < bin_type, nullptr_t >::value );

  bin_type * addr = reinterpret_cast < bin_type * > ( address );
  bin_type zero = makeCONST < bin_type > ( 0 );
  bin_type ret_ = makeCONST < bin_type > ( 0 );
  if constexpr ( Op == ATOMIC_RELAX ) {
    ret_ = atomicCAS ( addr, zero, zero );
  }
  if constexpr ( Op == ATOMIC_STRONG ) {
    ret_ = atomicCAS_STRONG ( addr, zero, zero );
  }
  T ret = const_binary_convert < T > ( ret_ );

  return ret;
}

template < int Op = ATOMIC_RELAX, typename T >
__forceinline__ __device__ T
__ATOMIC_EXCH__ ( T * address, T const val )
{
  using bin_type = typename binary_type < T > :: type;
  static_assert ( ! std::is_same < bin_type, nullptr_t >::value );

  bin_type * addr = reinterpret_cast < bin_type * > ( address );
  bin_type val_ = const_binary_convert < bin_type > ( val );
  bin_type ret_ = makeCONST < bin_type > ( 0 );
  if constexpr ( Op == ATOMIC_RELAX ) {
    ret_ = atomicExch ( addr, val_ );
  }
  if constexpr ( Op == ATOMIC_STRONG ) {
    ret_ = atomicExch_STRONG ( addr, val_ );
  }
  T ret = const_binary_convert < T > ( ret_ );

  return ret;
}

//--------------------------------------------------------
// CAS
//--------------------------------------------------------
#define	CAS_template(TYPE)                                      \
  __forceinline__ __device__ TYPE                               \
  atomicCAS ( TYPE * address, TYPE const sup, TYPE const val )  \
  {                                                             \
    return __ATOMIC_CAS__ < > ( address, sup, val );            \
  }
//--------------------------------------------------------
// uint16_t		//builtin :: atomicCAS(uint16_t*, uint16_t, uint16_t);
//  int16_t
__forceinline__ __device__ int16_t
atomicCAS ( int16_t * address, int16_t const sup, int16_t const val )
{
  int16_t ret;
  asm volatile ( "atom.cas.b16\t%0, [%1], %2, %3;"
                 : "=h"(ret) : "l"(address), "h"(sup), "h"(val) );
  return ret;
}
//  int16
CAS_template(int16)
// uint32_t		//builtin :: atomicCAS(uint*, uint, uint);
//  int32_t		//builtin :: atomicCAS(uint*, uint, uint);
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ uint64_t
atomicCAS ( uint64_t * address, uint64_t const sup, uint64_t const val )
{
  uint64_t ret;
  asm volatile ( "atom.cas.b64\t%0, [%1], %2, %3;"
                 : "=l"(ret) : "l"(address), "l"(sup), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicCAS ( int64_t * address, int64_t const sup, int64_t const val )
{
  int64_t ret;
  asm volatile ( "atom.cas.b64\t%0, [%1], %2, %3;"
                 : "=l"(ret) : "l"(address), "l"(sup), "l"(val) );
  return ret;
}
//  int64 == int64_t
//  int128
__forceinline__ __device__ int128
atomicCAS ( int128 * address, int128 const sup, int128 const val )
{
  int128 expected = sup;
#if ( __CUDA_ARCH__ >= 900 )
  int128 desired = val;
  bool status = __nv_atomic_compare_exchange (
                                              address, &expected, &desired,
                                              true, __NV_ATOMIC_RELAXED, __NV_ATOMIC_RELAXED, __NV_THREAD_SCOPE_SYSTEM );
#else
  assert( false );
#endif
  return expected;
}
//  half
CAS_template(half)
//  float		//builtin :: atomicCAS(float*, float, float);
//  double		//builtin :: atomicCAS(double*, double, double);
//  cudfreal
CAS_template(cudfreal)
//  cuddreal
CAS_template(cuddreal)
//  cuHalfComplex
CAS_template(cuHalfComplex)
//  cuFloatComplex
CAS_template(cuFloatComplex)
//  cuDoubleComplex
CAS_template(cuDoubleComplex)
//  cudfcomplex
CAS_template(cudfcomplex)
//  cuddcomplex
__forceinline__ __device__ cuddcomplex
atomicCAS ( cuddcomplex * address, cuddcomplex const sup, cuddcomplex const val )
{
  assert( false );
  return makeCONST<cuddcomplex>(0);
}
#undef	CAS_template


//--------------------------------------------------------
// CAS_STRONG
//--------------------------------------------------------
#define	CAS_STRONG_template(TYPE)                                       \
  __forceinline__ __device__ TYPE                                       \
  atomicCAS_STRONG ( TYPE * address, TYPE const sup, TYPE const val )   \
  {                                                                     \
    return __ATOMIC_CAS__ < ATOMIC_STRONG > ( address, sup, val );      \
  }
//--------------------------------------------------------
// uint16_t
__forceinline__ __device__ uint16_t
atomicCAS_STRONG ( uint16_t * address, uint16_t const sup, uint16_t const val )
{
  uint16_t ret;
  asm volatile ( "atom.acq_rel.cas.b16\t%0, [%1], %2, %3;"
                 : "=h"(ret) : "l"(address), "h"(sup), "h"(val) );
  return ret;
}
//  int16_t
__forceinline__ __device__ int16_t
atomicCAS_STRONG ( int16_t * address, int16_t const sup, int16_t const val )
{
  int16_t ret;
  asm volatile ( "atom.acq_rel.cas.b16\t%0, [%1], %2, %3;"
                 : "=h"(ret) : "l"(address), "h"(sup), "h"(val) );
  return ret;
}
//  int16
CAS_STRONG_template(int16)
// uint32_t
__forceinline__ __device__ uint32_t
atomicCAS_STRONG ( uint32_t * address, uint32_t const sup, uint32_t val )
{
  uint32_t ret;
  asm volatile ( "atom.acq_rel.cas.b32\t%0, [%1], %2, %3;"
                 : "=r"(ret) : "l"(address), "r"(sup), "r"(val) );
  return ret;
}
//  int32_t
__forceinline__ __device__ int32_t
atomicCAS_STRONG ( int32_t * address, int32_t const sup, int32_t val )
{
  int32_t ret;
  asm volatile ( "atom.acq_rel.cas.b32\t%0, [%1], %2, %3;"
                 : "=r"(ret) : "l"(address), "r"(sup), "r"(val) );
  return ret;
}
// uint64_t
__forceinline__ __device__ uint64_t
atomicCAS_STRONG ( uint64_t * address, uint64_t const sup, uint64_t val )
{
  uint64_t ret;
  asm volatile ( "atom.acq_rel.cas.b64\t%0, [%1], %2, %3;"
                 : "=l"(ret) : "l"(address), "l"(sup), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicCAS_STRONG ( int64_t * address, int64_t const sup, int64_t val )
{
  int64_t ret;
  asm volatile ( "atom.acq_rel.cas.b64\t%0, [%1], %2, %3;"
                 : "=l"(ret) : "l"(address), "l"(sup), "l"(val) );
  return ret;
}
//  int128
__forceinline__ __device__ int128
atomicCAS_STRONG ( int128 * address, int128 const sup, int128 const val )
{
  int128 expected = sup;
#if ( __CUDA_ARCH__ >= 900 )
  int128 desired = val;
  bool status = __nv_atomic_compare_exchange (
                                              address, &expected, &desired,
                                              true, __NV_ATOMIC_ACQ_REL, __NV_ATOMIC_ACQ_REL, __NV_THREAD_SCOPE_SYSTEM );
#else
  assert( false );
#endif
  return expected;
}
//  half
CAS_STRONG_template(half)
//  float
CAS_STRONG_template(float)
//  doublei
CAS_STRONG_template(double)
//  cudfreal
CAS_STRONG_template(cudfreal)
//  cuddreal
CAS_STRONG_template(cuddreal)
//  cuHalfComplex
CAS_STRONG_template(cuHalfComplex)
//  cuFloatComplex
CAS_STRONG_template(cuFloatComplex)
//  cuDoubleComplex
CAS_STRONG_template(cuDoubleComplex)
//  cudfcomplex
CAS_STRONG_template(cudfcomplex)
//  cuddcomplex
__forceinline__ __device__ cuddcomplex
atomicCAS_STRONG ( cuddcomplex * address, cuddcomplex const sup, cuddcomplex const val )
{
  assert( false );
  return makeCONST<cuddcomplex>(0);
}
#undef	CAS_STRONG_template


//--------------------------------------------------------
// OR
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomic_Or_loop ( T * address, T const val )
{
  T z = makeCONST < T > ( 0 );
  T ret = atomicCAS ( address, z, val );
  while ( 1 ) {
    T vv = ret | val;
    T rr = atomicCAS ( address, ret, vv );
    if ( rr == ret ) break;
    ret = rr;
  }
  return ret;
}
#define	Or_loop_template(TYPE)                  \
  __forceinline__ __device__ TYPE               \
  atomicOr ( TYPE * address, TYPE const val )   \
  {                                             \
    return atomic_Or_loop ( address, val );     \
  }
//--------------------------------------------------------
// uint16_t
Or_loop_template(uint16_t)
//  int16_t
Or_loop_template(int16_t)
//  int16
__forceinline__ __device__ int16
atomicOr ( int16 * address, int16 const val )
{
  uint16_t * addr = reinterpret_cast < uint16_t * > ( address );
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  uint16_t ret_ = atomicOr ( addr, val_ );
  int16 ret = const_binary_convert < int16 > ( ret_ );
  return ret;
}
// uint32_t	//builtin :: atomicOr(uint*, uint);
//  int32_t	//builtin :: atomicOr(int*, int);
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ uint64_t
atomicOr ( uint64_t * address, uint64_t const val )
{
  uint64_t ret;
  asm volatile ( "atom.or.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicOr ( int64_t * address, int64_t const val )
{
  int64_t ret;
  asm volatile ( "atom.or.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64 == int64_t
//  int128
Or_loop_template(int128)
#undef	Or_loop_template


//--------------------------------------------------------
// OR_STRONG
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomic_Or_STRONG_loop ( T * address, T const val )
{
  T z = makeCONST < T > ( 0 );
  T ret = atomicCAS_STRONG ( address, z, val );
  while ( 1 ) {
    T vv = ret | val;
    T rr = atomicCAS_STRONG ( address, ret, vv );
    if ( rr == ret ) break;
    ret = rr;
  }
  return ret;
}
#define	Or_loop_template(TYPE)                          \
  __forceinline__ __device__ TYPE                       \
  atomicOr_STRONG ( TYPE * address, TYPE const val )    \
  {                                                     \
    return atomic_Or_STRONG_loop ( address, val );      \
  }
//--------------------------------------------------------
// uint16_t
Or_loop_template(uint16_t)
//  int16_t
Or_loop_template(int16_t)
//  int16
__forceinline__ __device__ int16
atomicOr_STRONG ( int16 * address, int16 const val )
{
  uint16_t * addr = reinterpret_cast < uint16_t * > ( address );
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  uint16_t ret_ = atomicOr_STRONG (  addr, val_ );
  int16 ret = const_binary_convert < int16 > ( ret_ );
  return ret;
}
// uint32_t
__forceinline__ __device__ uint32_t
atomicOr_STRONG ( uint32_t * address, uint32_t const val )
{
  uint32_t ret;
  asm volatile ( "atom.acq_rel.or.b32\t%0, [%1], %2;"
                 : "=r"(ret) : "l"(address), "r"(val) );
  return ret;
}
//  int32_t
__forceinline__ __device__ int32_t
atomicOr_STRONG ( int32_t * address, int32_t const val )
{
  int32_t ret;
  asm volatile ( "atom.acq_rel.or.b32\t%0, [%1], %2;"
                 : "=r"(ret) : "l"(address), "r"(val) );
  return ret;
}
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ uint64_t
atomicOr_STRONG ( uint64_t * address, uint64_t const val )
{
  uint64_t ret;
  asm volatile ( "atom.acq_rel.or.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicOr_STRONG ( int64_t * address, int64_t const val )
{
  int64_t ret;
  asm volatile ( "atom.acq_rel.or.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64 == int64_t
//  int128
Or_loop_template(int128)
#undef Or_loop_template


//--------------------------------------------------------
// AND
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomic_And_loop ( T * address, T const val )
{
  T z = makeCONST < T > ( 0 );
  T ret = atomicCAS ( address, z, val );
  while ( 1 ) {
    T vv = ret & val;
    T rr = atomicCAS ( address, ret, vv );
    if ( rr == ret ) break;
    ret = rr;
  }
  return ret;
}
#define And_loop_template(TYPE)                 \
  __forceinline__ __device__ TYPE               \
  atomicAnd ( TYPE * address, TYPE const val )  \
  {                                             \
    return atomic_And_loop ( address, val );    \
  }
//--------------------------------------------------------
// uint16_t
And_loop_template(uint16_t)
//  int16_t
And_loop_template(int16_t)
//  int16
__forceinline__ __device__ int16
atomicAnd ( int16 * address, int16 const val )
{
  uint16_t * addr = reinterpret_cast < uint16_t * > ( address );
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  uint16_t ret_ = atomicAnd ( addr, val_ );
  int16 ret = const_binary_convert < int16 > ( ret_ );
  return ret;
}
// uint32_t     //builtin :: atomicOr(uint*, uint);
//  int32_t     //builtin :: atomicOr(int*, int);
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ uint64_t
atomicAnd ( uint64_t * address, uint64_t const val )
{
  uint64_t ret;
  asm volatile ( "atom.and.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicAnd ( int64_t * address, int64_t const val )
{
  int64_t ret;
  asm volatile ( "atom.and.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64 == int64_t
//  int128
And_loop_template(int128)
#undef  And_loop_template


//--------------------------------------------------------
// AND_STRONG
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomic_And_STRONG_loop ( T * address, T const val )
{
  T z = makeCONST < T > ( 0 );
  T ret = atomicCAS_STRONG ( address, z, val );
  while ( 1 ) {
    T vv = ret & val;
    T rr = atomicCAS_STRONG ( address, ret, vv );
    if ( rr == ret ) break;
    ret = rr;
  }
  return ret;
}
#define	And_loop_template(TYPE)                         \
  __forceinline__ __device__ TYPE                       \
  atomicAnd_STRONG ( TYPE * address, TYPE const val )   \
  {                                                     \
    return atomic_And_STRONG_loop ( address, val );     \
  }
//--------------------------------------------------------
// uint16_t
And_loop_template(uint16_t)
//  int16_t
And_loop_template(int16_t)
//  int16
__forceinline__ __device__ int16
atomicAnd_STRONG ( int16 * address, int16 const val )
{
  uint16_t * addr = reinterpret_cast < uint16_t * > ( address );
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  uint16_t ret_ = atomicAnd_STRONG (  addr, val_ );
  int16 ret = const_binary_convert < int16 > ( ret_ );
  return ret;
}
// uint32_t
__forceinline__ __device__ uint32_t
atomicAnd_STRONG ( uint32_t * address, uint32_t const val )
{
  uint32_t ret;
  asm volatile ( "atom.acq_rel.and.b32\t%0, [%1], %2;"
                 : "=r"(ret) : "l"(address), "r"(val) );
  return ret;
}
//  int32_t
__forceinline__ __device__ int32_t
atomicAnd_STRONG ( int32_t * address, int32_t const val )
{
  int32_t ret;
  asm volatile ( "atom.acq_rel.and.b32\t%0, [%1], %2;"
                 : "=r"(ret) : "l"(address), "r"(val) );
  return ret;
}
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ uint64_t
atomicAnd_STRONG ( uint64_t * address, uint64_t const val )
{
  uint64_t ret;
  asm volatile ( "atom.acq_rel.and.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicAnd_STRONG ( int64_t * address, int64_t const val )
{
  int64_t ret;
  asm volatile ( "atom.acq_rel.and.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64 == int64_t
//  int128
And_loop_template(int128)
#undef And_loop_template


//--------------------------------------------------------
// Load
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomicLoad ( T * address )
{
  return __ATOMIC_LOAD__ < > ( address );
}


//--------------------------------------------------------
// Load_STRONG
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomicLoad_STRONG ( T * address )
{
  return __ATOMIC_LOAD__ < ATOMIC_STRONG > ( address );
}


//--------------------------------------------------------
// Exch
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomic_Exch_loop ( T * address, T const val )
{
  T ret = makeCONST < T > ( 0 );
  while ( 1 ) {
    T rr = atomicCAS ( address, ret, val );
    if ( rr == ret ) break;
    ret = rr;
  }
  return ret;
}
#define	Exch_template(TYPE)                             \
  __forceinline__ __device__ TYPE                       \
  atomicExch ( TYPE * address, TYPE const val )         \
  {                                                     \
    return __ATOMIC_EXCH__ < > ( address, val );        \
  }
#define	Exch_loop_template(TYPE)                \
  __forceinline__ __device__ TYPE               \
  atomicExch ( TYPE * address, TYPE const val ) \
  {                                             \
    return atomic_Exch_loop ( address, val );   \
  }
//--------------------------------------------------------
// uint16_t
Exch_loop_template(uint16_t)
//  int16_t
Exch_loop_template(int16_t)
//  int16
Exch_template(int16)
// uint32_t		//builtin :: atomicExch(uint*, uint);
//  int32_t		//builtin :: atomicExch(uint*, uint);
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ uint64_t
atomicExch ( uint64_t * address, uint64_t const val )
{
  uint64_t ret;
  asm volatile ( "atom.exch.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicExch ( int64_t * address, int64_t const val )
{
  int64_t ret;
  asm volatile ( "atom.exch.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64 == int64_t
//  int128
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
Exch_loop_template(int128)
#endif
#if ( __CUDA_ARCH__ >= 900 )
__forceinline__ __device__ int128
atomicExch ( int128 * address, int128 const val )
{
  int128 value  = val;
  int128 ret;
  __nv_atomic_exchange (
                        address, &value, &ret,
                        __NV_ATOMIC_RELAXED, __NV_THREAD_SCOPE_SYSTEM );
  return ret;
}
#endif
//  half
Exch_template(half)
//  float		//builtin :: atomicExch(float*, float);
//  double
Exch_template(double)
//  cudfreal
Exch_template(cudfreal)
//  cuddreal
Exch_template(cuddreal)
//  cuHalfComplex
Exch_template(cuHalfComplex)
//  cuFloatComplex
Exch_template(cuFloatComplex)
//  cuDoubleComplex
Exch_template(cuDoubleComplex)
//  cudfcomplex
Exch_template(cudfcomplex)
//  cuddcomplex
__forceinline__ __device__ cuddcomplex
atomicExch ( cuddcomplex * address, cuddcomplex const val )
{
  assert( false );
  return makeCONST<cuddcomplex>(0);
}
#undef	Exch_template
#undef	Exch_loop_template


//--------------------------------------------------------
// Exch_STRONG
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ T
atomic_Exch_STRONG_loop ( T * address, T const val )
{
  T ret = makeCONST < T > ( 0 );
  while ( 1 ) {
    T rr = atomicCAS_STRONG ( address, ret, val );
    if ( rr == ret ) break;
    ret = rr;
  }
  return ret;
}
#define	Exch_template(TYPE)                                     \
  __forceinline__ __device__ TYPE                               \
  atomicExch_STRONG ( TYPE * address, TYPE const val )          \
  {                                                             \
    return __ATOMIC_EXCH__ < ATOMIC_STRONG > ( address, val );  \
  }
#define	Exch_loop_template(TYPE)                        \
  __forceinline__ __device__ TYPE                       \
  atomicExch_STRONG ( TYPE * address, TYPE const val )  \
  {                                                     \
    return atomic_Exch_STRONG_loop ( address, val );    \
  }
//--------------------------------------------------------
// uint16_t
Exch_loop_template(uint16_t)
//  int16_t
Exch_loop_template(int16_t)
//  int16
Exch_template(int16)
// uint32_t
__forceinline__ __device__ uint32_t
atomicExch_STRONG ( uint32_t * address, uint32_t const val )
{
  uint32_t ret;
  asm volatile ( "atom.acq_rel.exch.b32\t%0, [%1], %2;"
                 : "=r"(ret) : "l"(address), "r"(val) );
  return ret;
}
//  int32_t
__forceinline__ __device__ int32_t
atomicExch_STRONG ( int32_t * address, int32_t const val )
{
  int32_t ret;
  asm volatile ( "atom.acq_rel.exch.b32\t%0, [%1], %2;"
                 : "=r"(ret) : "l"(address), "r"(val) );
  return ret;
}
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ uint64_t
atomicExch_STRONG ( uint64_t * address, uint64_t const val )
{
  uint64_t ret;
  asm volatile ( "atom.acq_rel.exch.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64_t
__forceinline__ __device__ int64_t
atomicExch_STRONG ( int64_t * address, int64_t const val )
{
  int64_t ret;
  asm volatile ( "atom.acq_rel.exch.b64\t%0, [%1], %2;"
                 : "=l"(ret) : "l"(address), "l"(val) );
  return ret;
}
//  int64 == int64_t
//  int128
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
Exch_loop_template(int128)
#endif
#if ( __CUDA_ARCH__ >= 900 )
__forceinline__ __device__ int128
atomicExch_STRONG ( int128 * address, int128 const val )
{
  int128 value  = val;
  int128 ret;
  __nv_atomic_exchange (
                        address, &value, &ret,
                        __NV_ATOMIC_ACQ_REL, __NV_THREAD_SCOPE_SYSTEM );
  return ret;
}
#endif
//  half
Exch_template(half)
//  float
Exch_template(float)
//  double
Exch_template(double)
//  cudfreal
Exch_template(cudfreal)
//  cuddreal
Exch_template(cuddreal)
//  cuHalfComplex
Exch_template(cuHalfComplex)
//  cuFloatComplex
Exch_template(cuFloatComplex)
//  cuDoubleComplex
Exch_template(cuDoubleComplex)
//  cudfcomplex
Exch_template(cudfcomplex)
//  cuddcomplex
__forceinline__ __device__ cuddcomplex
atomicExch_STRONG ( cuddcomplex * address, cuddcomplex const val )
{
  assert( false );
  return makeCONST<cuddcomplex>(0);
}
#undef	Exch_template
#undef	Exch_loop_template


//--------------------------------------------------------
// Red
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ void
atomic_Red_loop ( T * address, T const val )
{
  T z = makeCONST < T > ( 0 );
  T ret = atomicCAS ( address, z, val );
  if ( ret == z ) return;
  while ( 1 ) {
    T vv = ret + val;
    T rr = atomicCAS ( address, ret, vv );
    if ( ret == rr ) break;
    ret = rr;
  }
}
#define	Red_loop_template(TYPE)                 \
  __forceinline__ __device__ void               \
  atomicRed ( TYPE * address, TYPE const val )  \
  {                                             \
    atomic_Red_loop ( address, val );           \
  }
//--------------------------------------------------------
// uint16_t
Red_loop_template(uint16_t)
//  int16_t
Red_loop_template(int16_t)
//  int16
__forceinline__ __device__ void
atomicRed ( int16 * address, int16 const val )
{
  uint16_t * addr = reinterpret_cast < uint16_t * > ( address );
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  atomicRed ( addr, val_ );
}
// uint32_t
__forceinline__ __device__ void
atomicRed ( uint32_t * address, uint32_t const val )
{
  asm volatile ( "red.add.u32\t[%0], %1;"
                 : : "l"(address), "r"(val) );
}
//  int32_t
__forceinline__ __device__ void
atomicRed ( int32_t * address, int32_t const val )
{
  asm volatile ( "red.add.u32\t[%0], %1;"
                 : : "l"(address), "r"(val) );
}
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ void
atomicRed ( uint64_t * address, uint64_t const val )
{
  asm volatile ( "red.add.u64\t[%0], %1;"
                 : : "l"(address), "l"(val) );
}
//  int64_t
__forceinline__ __device__ void
atomicRed ( int64_t * address, int64_t const val )
{
  asm volatile ( "red.add.u64\t[%0], %1;"
                 : : "l"(address), "l"(val) );
}
//  int64 == int64_t
//  int128
Red_loop_template(int128)
// half
__forceinline__ __device__ void
atomicRed ( half * address, half const val )
{
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  asm volatile ( "{\t.reg.f16\t%tmp;\n\t"
                 "atom.add.noftz.f16\t%tmp, [%0], %1;\n\t"
                 "}"
                 : : "l"(address), "h"(val_) );
}
// float
__forceinline__ __device__ void
atomicRed ( float * address, float const val )
{
  asm volatile ( "red.add.f32\t[%0], %1;"
                 : : "l"(address), "f"(val) );
}
// double
__forceinline__ __device__ void
atomicRed ( double * address, double const val )
{
  asm volatile ( "red.add.f64\t[%0], %1;"
                 : : "l"(address), "d"(val) );
}
// cudfreal
Red_loop_template(cudfreal)
// cuddreal
Red_loop_template(cuddreal)
// cuHalfComplex
Red_loop_template(cuHalfComplex)
// cuFloatComplex
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
Red_loop_template(cuFloatComplex)
#endif
#if ( __CUDA_ARCH__ >= 900 )
__forceinline__ __device__ void
atomicRed ( cuFloatComplex * address, cuFloatComplex const val )
{
  asm volatile ( "red.add.v2.f32\t[%0], {%1,%2};"
                 : : "l"(address), "f"(val.x),"f"(val.y) );
}
#endif
// cuDoubleComplex
Red_loop_template(cuDoubleComplex)
// cudfcomplex
Red_loop_template(cudfcomplex)
// cuddcomplex
__forceinline__ __device__ void
atomicRed ( cuddcomplex * address, cuddcomplex const val )
{
  assert( false );
}
#undef	Red_loop_template


//--------------------------------------------------------
// Red_STRONG
//--------------------------------------------------------
template < typename T >
__forceinline__ __device__ void
atomic_Red_STRONG_loop ( T * address, T const val )
{
  T z = makeCONST < T > ( 0 );
  T ret = atomicCAS_STRONG ( address, z, val );
  if ( ret == z ) return;
  while ( 1 ) {
    T vv = ret + val;
    T rr = atomicCAS_STRONG ( address, ret, vv );
    if ( ret == rr ) break;
    ret = rr;
  }
}
#define	Red_loop_template(TYPE)                         \
  __forceinline__ __device__ void                       \
  atomicRed_STRONG ( TYPE * address, TYPE const val )   \
  {                                                     \
    atomic_Red_STRONG_loop ( address, val );            \
  }
//--------------------------------------------------------
// uint16_t
Red_loop_template(uint16_t)
//  int16_t
Red_loop_template(int16_t)
//  int16
__forceinline__ __device__ void
atomicRed_STRONG ( int16 * address, int16 const val )
{
  uint16_t * addr = reinterpret_cast < uint16_t * > ( address );
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  atomicRed_STRONG ( addr, val_ );
}
// uint32_t
__forceinline__ __device__ void
atomicRed_STRONG ( uint32_t * address, uint32_t const val )
{
  asm volatile ( "red.release.add.u32\t[%0], %1;"
                 : : "l"(address), "r"(val) );
}
//  int32_t
__forceinline__ __device__ void
atomicRed_STRONG ( int32_t * address, int32_t const val )
{
  asm volatile ( "red.release.add.s32\t[%0], %1;"
                 : : "l"(address), "r"(val) );
}
//  int32 == int32_t
// uint64_t
__forceinline__ __device__ void
atomicRed_STRONG ( uint64_t * address, uint64_t const val )
{
  asm volatile ( "red.release.add.u64\t[%0], %1;"
                 : : "l"(address), "l"(val) );
}
//  int64_t
__forceinline__ __device__ void
atomicRed_STRONG ( int64_t * address, int64_t const val )
{
  asm volatile ( "red.release.add.u64\t[%0], %1;"
                 : : "l"(address), "l"(val) );
}
//  int64 == int64_t
//  int128
Red_loop_template(int128)
// half
__forceinline__ __device__ void
atomicRed_STRONG ( half * address, half const val )
{
  uint16_t val_ = const_binary_convert < uint16_t > ( val );
  asm volatile ( "{\t.reg.f16\t%tmp;\n\t"
                 "atom.acq_rel.add.noftz.f16\t%tmp, [%0], %1;\n\t"
                 "}"
               : : "l"(address), "h"(val_) );
}
// floati
__forceinline__ __device__ void
atomicRed_STRONG ( float * address, float const val )
{
  asm volatile ( "red.release.add.f32\t[%0], %1;"
                 : : "l"(address), "f"(val) );
}
// double
__forceinline__ __device__ void
atomicRed_STRONG ( double * address, double const val )
{
  asm volatile ( "red.release.add.f64\t[%0], %1;"
                 : : "l"(address), "d"(val) );
}
// cudfreal
Red_loop_template(cudfreal)
// cuddreal
Red_loop_template(cuddreal)
// cuHalfComplex
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
Red_loop_template(cuHalfComplex)
#endif
#if ( __CUDA_ARCH__ >= 900 )
__forceinline__ __device__ void
atomicRed_STRONG ( cuHalfComplex * address, cuHalfComplex const val )
{
  cuHalfComplex_raw val_ = val;
  uint16_t val_x = const_binary_convert < uint16_t > ( val_.x );
  uint16_t val_y = const_binary_convert < uint16_t > ( val_.y );
  asm volatile ( "red.release.add.noftz.v2.f16\t[%0], {%1,%2};"
                 : : "l"(address), "h"(val_x),"h"(val_y) );
}
#endif
// cuFloatComplex
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
Red_loop_template(cuFloatComplex)
#endif
#if ( __CUDA_ARCH__ >= 900 )
__forceinline__ __device__ void
atomicRed_STRONG ( cuFloatComplex * address, cuFloatComplex const val )
{
  asm volatile ( "red.release.add.v2.f32\t[%0], {%1,%2};"
                 : : "l"(address), "f"(val.x),"f"(val.y) );
}
#endif
// cuDoubleComplex
Red_loop_template(cuDoubleComplex)
// cudfcomplex
Red_loop_template(cudfcomplex)
// cuddcomplex
__forceinline__ __device__ void
atomicRed_STRONG ( cuddcomplex * address, cuddcomplex const val )
{
  assert( false );
}
#undef	Red_loop_template


//--------------------------------------------------------
// Red_SPLIT
//--------------------------------------------------------
#define	Red_template(TYPE)                              \
  __forceinline__ __device__ void                       \
  atomicRed_SPLIT ( TYPE * address, TYPE const val )   \
  {                                                     \
    atomicRed ( address, val );                         \
  }
// uint16_t
Red_template(uint16_t)
// int16_t
Red_template(int16_t)
// int16
Red_template(int16)
// uint32_t
Red_template(uint32_t)
// int32_t
Red_template(int32_t)
// uint64_t
Red_template(uint64_t)
// int64_t
Red_template(int64_t)
// int128
Red_template(int128)
// half
Red_template(half)
// float
Red_template(float)
// double
Red_template(double)
// cudfreal
__forceinline__ __device__ void
atomicRed_SPLIT ( cudfreal * address, cudfreal const val )
{
  assert( false );
}
// cuddreal
__forceinline__ __device__ void
atomicRed_SPLIT ( cuddreal * address, cuddreal const val )
{
  assert( false );
}
// cuHalfComplex
__forceinline__ __device__ void
atomicRed_SPLIT ( cuHalfComplex * address, cuHalfComplex const val )
{
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
  cuHalfComplex_raw * addr = reinterpret_cast < cuHalfComplex_raw * >( address );
  cuHalfComplex_raw val_ = val;
  atomicRed ( & addr->x, val_.x );
  atomicRed ( & addr->y, val_.y );
#endif
#if ( __CUDA_ARCH__ >= 900 )
  cuHalfComplex_raw val_ = val;
  uint16_t val_x = const_binary_convert < uint16_t > ( val_.x );
  uint16_t val_y = const_binary_convert < uint16_t > ( val_.y );
  asm volatile ( "red.add.noftz.v2.f16\t[%0], {%1,%2};"
                 : : "l"(address), "h"(val_x), "h"(val_y) );
#endif
}
// cuFloatComplex
__forceinline__ __device__ void
atomicRed_SPLIT ( cuFloatComplex * address, cuFloatComplex const val )
{
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
  atomicRed ( & address->x, val.x );
  atomicRed ( & address->y, val.y );
#endif
#if ( __CUDA_ARCH__ >= 900 )
  asm volatile ( "red.add.v2.f32\t[%0], {%1,%2};"
                 : : "l"(address), "f"(val.x),"f"(val.y) );
#endif
}
// cuDoubleComplex
__forceinline__ __device__ void
atomicRed_SPLIT ( cuDoubleComplex * address, cuDoubleComplex const val )
{
  atomicRed ( & address->x, val.x );
  atomicRed ( & address->y, val.y );
}
// cudfcomplex
__forceinline__ __device__ void
atomicRed_SPLIT ( cudfcomplex * address, cudfcomplex const val )
{
  cudfcomplex_raw * addr = reinterpret_cast < cudfcomplex_raw * >( address );
  cudfcomplex_raw val_ = val;
  atomicRed ( & addr->x, val_.x );
  atomicRed ( & addr->y, val_.y );
}
// cuddcomplex
__forceinline__ __device__ void
atomicRed_SPLIT ( cuddcomplex * address, cuddcomplex const val )
{
  cuddcomplex_raw * addr = reinterpret_cast < cuddcomplex_raw * >( address );
  cuddcomplex_raw val_ = val;
  atomicRed ( & addr->x, val_.x );
  atomicRed ( & addr->y, val_.y );
}
#undef	Red_template


//--------------------------------------------------------
// Red_SPLIT_STRONG
//--------------------------------------------------------
#define	Red_template(TYPE)                              \
  __forceinline__ __device__ void                       \
  atomicRed_SPLIT_STRONG ( TYPE * address, TYPE const val )     \
  {                                                     \
    atomicRed_STRONG ( address, val );                  \
  }
// uint16_t
Red_template(uint16_t)
// int16_t
Red_template(int16_t)
// int16
Red_template(int16)
// uint32_t
Red_template(uint32_t)
// int32_t
Red_template(int32_t)
// uint64_t
Red_template(uint64_t)
// int64_t
Red_template(int64_t)
// int128
Red_template(int128)
// half
Red_template(half)
// float
Red_template(float)
// double
Red_template(double)
// cudfreal
__forceinline__ __device__ void
atomicRed_SPLIT_STRONG ( cudfreal * address, cudfreal const val )
{
  assert( false );
}
// cuddreal
__forceinline__ __device__ void
atomicRed_SPLIT_STRONG ( cuddreal * address, cuddreal const val )
{
  assert( false );
}
// cuHalfComplex
__forceinline__ __device__ void
atomicRed_SPLIT_STRONG ( cuHalfComplex * address, cuHalfComplex const val )
{
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
  cuHalfComplex_raw * addr = reinterpret_cast < cuHalfComplex_raw * >( address );
  cuHalfComplex_raw val_ = val;
  atomicRed        ( & addr->x, val_.x );
  atomicRed_STRONG ( & addr->y, val_.y );
#endif
#if ( __CUDA_ARCH__ >= 900 )
  cuHalfComplex_raw val_ = val;
  uint16_t val_x = const_binary_convert < uint16_t > ( val_.x );
  uint16_t val_y = const_binary_convert < uint16_t > ( val_.y );
  asm volatile ( "red.release.add.noftz.v2.f16\t[%0], {%1,%2};"
                 : : "l"(address), "h"(val_x),"h"(val_y) );
#endif
}
// cuFloatComplex
__forceinline__ __device__ void
atomicRed_SPLIT_STRONG ( cuFloatComplex * address, cuFloatComplex const val )
{
#if ( __CUDA_ARCH__ >= 800 ) && ( __CUDA_ARCH__ < 900 )
  atomicRed        ( & address->x, val.x );
  atomicRed_STRONG ( & address->y, val.y );
#endif
#if ( __CUDA_ARCH__ >= 900 )
  asm volatile ( "red.release.add.v2.f32\t[%0], {%1,%2};"
                 : : "l"(address), "f"(val.x),"f"(val.y) );
#endif
}
// cuDoubleComplex
__forceinline__ __device__ void
atomicRed_SPLIT_STRONG ( cuDoubleComplex * address, cuDoubleComplex const val )
{
  atomicRed        ( & address->x, val.x );
  atomicRed_STRONG ( & address->y, val.y );
}
// cudfcomplex
__forceinline__ __device__ void
atomicRed_SPLIT_STRONG ( cudfcomplex * address, cudfcomplex const val )
{
  cudfcomplex_raw * addr = reinterpret_cast < cudfcomplex_raw * >( address );
  cudfcomplex_raw val_ = val;
  atomicRed        ( & addr->x, val_.x );
  atomicRed_STRONG ( & addr->y, val_.y );
}
// cuddcomplex
__forceinline__ __device__ void
atomicRed_SPLIT_STRONG ( cuddcomplex * address, cuddcomplex const val )
{
  cuddcomplex_raw * addr = reinterpret_cast < cuddcomplex_raw * >( address );
  cuddcomplex_raw val_ = val;
  atomicRed        ( & addr->x, val_.x );
  atomicRed_STRONG ( & addr->y, val_.y );
}
#undef	Red_template


#endif

