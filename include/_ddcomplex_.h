#ifndef __ASPEN_DDCOMPLEX_H_INCLUDED
#  define __ASPEN_DDCOMPLEX_H_INCLUDED	1

#  define scalar_t		cuddcomplex
#  define element_scalar_t	cuddreal

#  define __isDD_COMPLEX__	(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isDD_COMPLEX__
error
#    endif
#endif
