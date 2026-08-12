#ifndef ASPEN_TEXTURE_H_INCLUDED
#  define ASPEN_TEXTURE_H_INCLUDED		1

#  if CUDA_VERSION<12000

// this header will be deprecated in future versions
// definition for Texture memory

#    if __isDD__
#      define	DEF_TEXTURE( Tex_x, X_, ... )           \
  texture < uint4, 1 > Tex_x;                           \
  __forceinline__ __device__ scalar_t                   \
  X_ ( int const i )                                    \
  {                                                     \
    uint4 const v = tex1Dfetch ( Tex_x, i );            \
    double const wx = __hiloint2double ( v.y, v.x );    \
    double const wy = __hiloint2double ( v.w, v.z );    \
    cuddreal const V = { wx, wy };                      \
    return V;                                           \
  }
#    endif

#    if __isDOUBLE__
#      define	DEF_TEXTURE( Tex_x, X_, ... )           \
  texture < uint2, 1 > Tex_x;                           \
  __forceinline__ __device__ scalar_t                   \
  X_ ( int const i )                                    \
  {                                                     \
    uint2 const v = tex1Dfetch ( Tex_x, i );            \
    double const V = __hiloint2double ( v.y, v.x );     \
    return V;                                           \
  }
#    endif

#    if __isFLOAT__
#      define	DEF_TEXTURE( Tex_x, X_, ... )   \
  texture < float, 1 > Tex_x;                   \
  __forceinline__ __device__ scalar_t           \
  X_ ( int const i )                            \
  {                                             \
    float const v = tex1Dfetch ( Tex_x, i );    \
    return (scalar_t) v;                        \
  }
#    endif

#    if __isDD_COMPLEX__
#      define	DEF_TEXTURE( Tex_x, X_, ... )           \
  texture < uint4, 1 > Tex_x;                           \
  __forceinline__ __device__ scalar_t                   \
  X_ ( int const i )                                    \
  {                                                     \
    uint4 const v1 = tex1Dfetch ( Tex_x, i*2 );         \
    double const w1x = __hiloint2double ( v1.y, v1.x ); \
    double const w1y = __hiloint2double ( v1.w, v1.z ); \
    cuddreal const V1 = { w1x, w1y };                   \
    uint4 const v2 = tex1Dfetch ( Tex_x, i*2+1 );       \
    double const w2x = __hiloint2double ( v2.y, v2.x ); \
    double const w2y = __hiloint2double ( v2.w, v2.z ); \
    cuddreal const V2 = { w2x, w2y };                   \
    cuuddcomplex const V = { V1, V2 };                  \
    return V;                                           \
  }
#    endif

#    if __isDOUBLE_COMPLEX__
#      define	DEF_TEXTURE( Tex_x, X_, ... )           \
  texture < uint4, 1 > Tex_x;                           \
  __forceinline__ __device__ scalar_t                   \
  X_ ( int const i )                                    \
  {                                                     \
    uint4 const v = tex1Dfetch ( Tex_x, i );            \
    double const wx = __hiloint2double ( v.y, v.x );    \
    double const wy = __hiloint2double ( v.w, v.z );    \
    cuDoubleComplex const V = { wx, wy };               \
    return V;                                           \
  }
#    endif

#    if __isFLOAT_COMPLEX__
#      define	DEF_TEXTURE( Tex_x, X_, ... )   \
  texture < float2, 1 > Tex_x;                  \
  __forceinline__ __device__ scalar_t           \
  X_ ( int const i )                            \
  {                                             \
    float2 const v = tex1Dfetch ( Tex_x, i );   \
    cuFloatComplex const V = { v.x, v.y };      \
    return V;                                   \
  }
#    endif


#    if __isDD__
#      define	SETUP_TEXTURE( Tex_x, x, n, offsetX, ... )		\
  _MACRO_BLOCK_ (							\
                 cudaError_t err;                                       \
                 err = cudaBindTexture (                                \
                                        &offsetX, Tex_x,                \
                                        (int4 *)x,                      \
                                        (n)*sizeof( scalar_t ) );       \
                 if ( err != cudaSuccess ) {                            \
                   printf ( "cannot bind to texture :: %d \n", err );   \
                   return;                                              \
                 }                                                      \
                 offsetX /= sizeof( x[0] );                             \
                                                                        )
#    endif

#    if __isDOUBLE__
#      define	SETUP_TEXTURE( Tex_x, x, n, offsetX, ... )		\
  _MACRO_BLOCK_ (							\
                 cudaError_t err;                                       \
                 err = cudaBindTexture (                                \
                                        &offsetX, Tex_x,                \
                                        (int2 *)x,                      \
                                        (n)*sizeof( scalar_t ) );       \
                 if ( err != cudaSuccess ) {                            \
                   printf ( "cannot bind to texture :: %d \n", err );   \
                   return;                                              \
                 }                                                      \
                 offsetX /= sizeof( x[0] );                             \
                                                                        )
#    endif

#    if __isFLOAT__
#      define	SETUP_TEXTURE( Tex_x, x, n, offsetX, ... )		\
  _MACRO_BLOCK_ (							\
                 cudaError_t err;                                       \
                 err = cudaBindTexture(                                 \
                                       &offsetX, Tex_x,                 \
                                       (float *)x,                      \
                                       (n)*sizeof( scalar_t ) );        \
                 if ( err != cudaSuccess ) {                            \
                   printf ( "cannot bind to texture :: %d \n", err );   \
                   return;                                              \
                 }                                                      \
                 offsetX /= sizeof( x[0] );                             \
                                                                        )
#    endif

#    if __isDD_COMPLEX__
#      define	SETUP_TEXTURE( Tex_x, x, n, offsetX, ... )		\
  _MACRO_BLOCK_ (                                                       \
                 cudaError_t err;                                       \
                 err = cudaBindTexture (                                \
                                        &offsetX, Tex_x,                \
                                        (int4 *)x,                      \
                                        (n)*sizeof( scalar_t ) );       \
                 if ( err != cudaSuccess ) {                            \
                   printf ( "cannot bind to texture :: %d \n", err );   \
                   return;                                              \
                 }                                                      \
                 offsetX /= (sizeof( x[0] )/2);                         \
                                                                        )
#    endif

#    if __isDOUBLE_COMPLEX__
#      define	SETUP_TEXTURE( Tex_x, x, n, offsetX, ... )		\
  _MACRO_BLOCK_ (                                                       \
                 cudaError_t err;                                       \
                 err = cudaBindTexture (                                \
                                        &offsetX, Tex_x,                \
                                        (int4 *)x,                      \
                                        (n)*sizeof( scalar_t ) );       \
                 if ( err != cudaSuccess ) {                            \
                   printf ( "cannot bind to texture :: %d \n", err );   \
                   return;                                              \
                 }                                                      \
                 offsetX /= sizeof( x[0] );                             \
                                                                        )
#    endif

#    if __isFLOAT_COMPLEX__
#      define	SETUP_TEXTURE( Tex_x, x, n, offsetX, ... )		\
  _MACRO_BLOCK_ (							\
                 cudaError_t err;                                       \
                 err = cudaBindTexture(                                 \
                                       &offsetX, Tex_x,                 \
                                       (float2 *)x,                     \
                                       (n)*sizeof( scalar_t ) );        \
                 if ( err != cudaSuccess ) {                            \
                   printf ( "cannot bind to texture :: %d \n", err );   \
                   return;                                              \
                 }                                                      \
                 offsetX /= sizeof( x[0] );                             \
                                                                        )
#    endif

#  endif
#endif

