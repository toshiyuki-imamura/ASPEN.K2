#ifndef __ASPEN_DOUBLE_H_INCLUDED
#  define	__ASPEN_DOUBLE_H_INCLUDED		1

#  define scalar_t		double
#  define element_scalar_t	double

#  define __isDOUBLE__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isDOUBLE__
error
#    endif
#endif

