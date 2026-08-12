#ifndef __ASPEN_FLOAT_H_INCLUDED
#  define	__ASPEN_FLOAT_H_INCLUDED		1

#  define scalar_t		float
#  define element_scalar_t	float

#  define	__isFLOAT__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isFLOAT__
error
#    endif
#endif

