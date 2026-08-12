#ifndef __ASPEN_DFREAL_H_INCLUDED
#  define __ASPEN_DFREAL_H_INCLUDED		1

#  include "aspen_dfreal.h"

#  define scalar_t		cudfreal
#  define element_scalar_t	cudfreal

#  define __isDF__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isDF__
error
#    endif
#endif
