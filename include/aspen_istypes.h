#ifndef ASPEN_ISTYPES_H_INCLUDED
#  define ASPEN_ISTYPES_H_INCLUDED	1

#  include "aspen_types.h"


template < typename TYPE1, typename TYPE2 >
struct __TypeCompare__
{
  __host__ __device__ static bool
  TypeCompare ( void ) { return false; }
};

template < typename TYPE >
struct __TypeCompare__ < TYPE, TYPE >
{
  __host__ __device__ static bool
  TypeCompare ( void ) { return true; }
};


template < class TYPE1, class TYPE2 >
__forceinline__ __host__ __device__ bool
TypeCompare ( void )
{
  return __TypeCompare__ < TYPE1, TYPE2 > :: TypeCompare( );
#  if 0
  return std :: is_same  < TYPE1, TYPE2 > :: value;
#  endif
}


template < class TYPE >
__forceinline__ __host__ __device__ bool
isDD ( void ) { return TypeCompare < TYPE, cuddreal > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isDF ( void ) { return TypeCompare < TYPE, cudfreal > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isDouble ( void ) { return TypeCompare < TYPE, double > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isFloat ( void ) { return TypeCompare < TYPE, float > ( ); }

#  if defined(half)
template < class TYPE >
__forceinline__ __host__ __device__ bool
isHalf ( void ) { return TypeCompare < TYPE, half > ( ); }
#  endif

template < class TYPE >
__forceinline__ __host__ __device__ bool
isDDComplex ( void ) { return TypeCompare < TYPE, cuddcomplex > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isDFComplex ( void ) { return TypeCompare < TYPE, cudfcomplex > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isDoubleComplex ( void ) { return TypeCompare < TYPE, cuDoubleComplex > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isFloatComplex ( void ) { return TypeCompare < TYPE, cuFloatComplex > ( ); }

#  if defined(half)
template < class TYPE >
__forceinline__ __host__ __device__ bool
isHalfComplex ( void ) { return TypeCompare < TYPE, cuHalfComplex > ( ); }
#  endif

template < class TYPE >
__forceinline__ __host__ __device__ bool
isInt16 ( void ) { return TypeCompare < TYPE, int16 > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isInt32 ( void ) { return TypeCompare < TYPE, int32 > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isInt64 ( void ) { return TypeCompare < TYPE, int64 > ( ); }

template < class TYPE >
__forceinline__ __host__ __device__ bool
isInt128 ( void ) { return TypeCompare < TYPE, int128 > ( ); }


//< -- Complex : DDComplex or DoubleComplex or FloatComplex --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isComplex ( void ) {
  return ( isDDComplex<TYPE>() || isDoubleComplex<TYPE>()
           || isFloatComplex<TYPE>()
#  if defined(half)
	   || isHalfComplex<TYPE>()
#  endif
           );
}
//  -- Complex : DDComplex or DoubleComplex or FloatComplex -- >


//< -- Real : DD or Double or Float --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isReal ( void ) {
  return ( isDD<TYPE>() || isDouble<TYPE>() || isFloat<TYPE>() );
}
//< -- Real : DD or Double or Float --


//< -- Int : Int16 or Int32 or Int64 --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isInt ( void ) {
  return ( isInt16<TYPE>() || isInt32<TYPE>()
           || isInt64<TYPE>() || isInt128<TYPE>() );
}
//< -- Int : Int16 or Int32 or Int64 --


//< -- DoubleDouble Format : DD or DDComplex --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isDDFormat ( void ) {
  return ( isDD<TYPE>() || isDDComplex<TYPE>() );
}
//  -- DoubleDouble Format : DD or DDComplex -- >


//< -- SingleDouble Format : Double or DoubleComplex --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isSDFormat ( void ) {
  return ( isDouble<TYPE>() || isDoubleComplex<TYPE>() );
}
//  -- SingleDouble Format : Double or DoubleComplex -- >


//< -- DoubleFloat Format : DF or DFComplex --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isDFFormat ( void ) {
  return ( isDF<TYPE>() || isDFComplex<TYPE>() );
}
//  -- DoubleFloat Format : DF or DFComplex -- >


//< -- SingleFloat Format : Float or FloatComplex --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isSFFormat ( void ) {
  return ( isFloat<TYPE>() || isFloatComplex<TYPE>() );
}
//  -- SingleFloat Format : Float or FloatComplex -- >


#if defined(half)
//< -- DoubleHalf Format : DH --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isDHFormat ( void ) {
  // not yet supported
  return ( false );
}
//  -- DoubleHalf Format : DH -- >


//< -- SingleHalf Format : Half --
template < class TYPE >
__forceinline__ __host__ __device__ bool
isSHFormat ( void ) {
#    if 0
  return ( isHalf<TYPE>() );
  // not yet supported
#    endif
  return ( isHalf<TYPE>()
#    if defined(half)
           || isHalfComplex<TYPE>()
#    endif
           );
}
//  -- SingleHalf Format : Half -- >
#  endif

#endif

