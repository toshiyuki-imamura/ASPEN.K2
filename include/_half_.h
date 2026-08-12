#ifndef __ASPEN_HALF_H_INCLUDED
#  define	__ASPEN_HALF_H_INCLUDED		1

#  define scalar_t		half
#  define element_scalar_t	half

#  define	__isHALF__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isHALF__
error
#    endif
#endif

