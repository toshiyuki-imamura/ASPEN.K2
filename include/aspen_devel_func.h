#ifndef ASPEN_DEVEL_FUNC_H_INCLUDED
#define ASPEN_DEVEL_FUNC_H_INCLUDED	1

#include "aspen_types.h"


#define SYMV_args(TYPE, ...)			\
  ( int const blk,				\
    int const n,				\
    TYPE const * a, int const lda,		\
    TYPE const * x, int const incx,		\
    TYPE * y, int const incy,			\
    TYPE const alpha, TYPE const beta )

#define	DECL(P, FUN, TYPE, ...)                                         \
  extern "C" void API(P##FUN##MVu) SYMV_args(TYPE);                     \
  extern "C" void API(P##FUN##MVl) SYMV_args(TYPE);                     \
  extern "C" void API_private(P##FUN##MVu_STUB) SYMV_args(TYPE);        \
  extern "C" void API_private(P##FUN##MVl_STUB) SYMV_args(TYPE);

DECL(W,SY,cuddreal)
DECL(D,SY,double)
DECL(S,SY,float)
DECL(H,SY,half)
DECL(U,HE,cuddcomplex)
DECL(Z,HE,cuDoubleComplex)
DECL(C,HE,cuFloatComplex)
DECL(K,HE,cuHalfComplex)
DECL(I128,SY,int128)
DECL(I64,SY,int64)
DECL(I32,SY,int32)
DECL(I16,SY,int16)

#undef DECL
#undef SYMV_args


#define SYMV_small_args(TYPE, ...)		\
  ( int const n,				\
    TYPE const alpha,                           \
    TYPE const * a, int const lda,		\
    TYPE const * x, int const incx,		\
    TYPE const beta,                            \
    TYPE * y, int const incy )

#define	DECL(P, FUN, TYPE, ...)                                 \
  extern "C" void P##FUN##mv_upper_small SYMV_small_args(TYPE); \
  extern "C" void P##FUN##mv_lower_small SYMV_small_args(TYPE);

DECL(w,sy,cuddreal)
DECL(d,sy,double)
DECL(s,sy,float)
DECL(h,sy,half)
DECL(u,he,cuddcomplex)
DECL(z,he,cuDoubleComplex)
DECL(c,he,cuFloatComplex)
DECL(k,he,cuHalfComplex)
DECL(i128,sy,int128)
DECL(i64,sy,int64)
DECL(i32,sy,int32)
DECL(i16,sy,int16)

#undef DECL
#undef SYMV_small_args

#endif

