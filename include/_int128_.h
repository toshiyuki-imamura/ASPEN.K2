#ifndef __ASPEN_INT128_H_INCLUDED
#  define	__ASPEN_INT128_H_INCLUDED		1

#  define scalar_t		int128
#  define element_scalar_t	int128

#  define __isINT128__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isINT128__
error
#    endif
#endif

