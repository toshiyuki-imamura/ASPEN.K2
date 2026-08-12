#ifndef	__ASPEN_FLOAT_COMPLEX_H_INCLUDED
#  define	__ASPEN_FLOAT_COMPLEX_H_INCLUDED	1

#  include "aspen_complex.h"

#  define scalar_t		cuFloatComplex
#  define element_scalar_t	float

#  define	__isFLOAT_COMPLEX__	(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isFLOAT_COMPLEX__
error
#    endif
#endif

