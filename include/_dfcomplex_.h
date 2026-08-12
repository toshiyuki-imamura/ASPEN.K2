#ifndef __ASPEN_DFCOMPLEX_H_INCLUDED
#  define __ASPEN_DFCOMPLEX_H_INCLUDED	1

#  include "aspen_dfcomplex.h"

#  define scalar_t		cudfcomplex
#  define element_scalar_t	cudfreal

#  define __isDF_COMPLEX__	(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isDF_COMPLEX__
error
#    endif
#endif
