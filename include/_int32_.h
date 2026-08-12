#ifndef __ASPEN_INT32_H_INCLUDED
#  define	__ASPEN_INT32_H_INCLUDED		1

#  define scalar_t		int32
#  define element_scalar_t	int32

#  define __isINT32__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isINT32__
error
#    endif
#endif

