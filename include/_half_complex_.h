#ifndef	__ASPEN_HALF_COMPLEX_H_INCLUDED
#  define	__ASPEN_HALF_COMPLEX_H_INCLUDED	1

#  include "aspen_half_complex.h"

#  define scalar_t		cuHalfComplex
#  define element_scalar_t	half

#  define	__isHALF_COMPLEX__	(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isHALF_COMPLEX__
error
#    endif
#endif

