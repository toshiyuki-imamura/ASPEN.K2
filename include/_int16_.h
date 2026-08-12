#ifndef __ASPEN_INT16_H_INCLUDED
#  define	__ASPEN_INT16_H_INCLUDED		1

#  define scalar_t		int16
#  define element_scalar_t	int16

#  define __isINT16__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isINT16__
error
#    endif
#endif

