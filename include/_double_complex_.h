#ifndef __ASPEN_DOUBLE_COMPLEX_H_INCLUDED
#  define	__ASPEN_DOUBLE_COMPLEX_H_INCLUDED		1

#  include "aspen_complex.h"

#  define scalar_t		cuDoubleComplex
#  define element_scalar_t	double

#  define __isDOUBLE_COMPLEX__	(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isDOUBLE_COMPLEX__
error
#    endif
#endif
