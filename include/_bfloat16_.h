#ifndef __ASPEN_BFLOAT16_H_INCLUDED
#  define	__ASPEN_BFLOAT16_H_INCLUDED		1

#  define scalar_t		bfloat16
#  define element_scalar_t	bfloat16

#  define	__isBF16__		(1)

#  include "aspen_type_macros.h"

#  else
#    if !__isBF16__
error
#    endif
#endif

