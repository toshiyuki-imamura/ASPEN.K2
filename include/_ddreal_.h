#ifndef __ASPEN_DDREAL_H_INCLUDED
#  define __ASPEN_DDREAL_H_INCLUDED		1

#  define scalar_t		cuddreal
#  define element_scalar_t	cuddreal

#  define __isDD__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isDD__
error
#    endif
#endif
