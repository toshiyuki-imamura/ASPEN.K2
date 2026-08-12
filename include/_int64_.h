#ifndef __ASPEN_INT64_H_INCLUDED
#  define	__ASPEN_INT64_H_INCLUDED		1

#  define scalar_t		int64
#  define element_scalar_t	int64

#  define __isINT64__		(1)

#  include "aspen_type_macros.h"

#else
#  if !__isINT64__
error
#  endif
#endif

