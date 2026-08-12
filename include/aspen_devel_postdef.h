#include "aspen_devel.h"

#ifndef ASPEN_DEVEL_POSTDEF_H_INCLUDED
#define ASPEN_DEVEL_POSTDEF_H_INCLUDED	1

/* macro switch for special prefix and functions */


#ifndef USE_VOLATILE
#  define	USE_VOLATILE	0
#endif
#if	USE_VOLATILE
#  define	__VOLATILE__	volatile
#else
#  define	__VOLATILE__	/* nothing to do */
#endif


#ifndef USE_RESTRICT
#  define	USE_RESTRICT	0
#endif
#if	USE_RESTRICT
#  define	__RESTRICT__	__restrict__
#else
#  define	__RESTRICT__	/* nothing to do */
#endif


#ifndef USE_LDG
#  define	USE_LDG		0
#endif
#if	USE_LDG
#  define	__LDG__(x)	__ldg(x)
#else
#  define	__LDG__(x)	(*(x))
#endif


#ifndef USE_INLINE
#  define	USE_INLINE	0
#endif
#if	USE_INLINE
#  define	__INLINE__	__forceinline__
#else
#  define	__INLINE__	__noinline__
#endif


#endif

