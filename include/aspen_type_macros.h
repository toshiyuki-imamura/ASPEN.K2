#ifndef ASPEN_TYPE_MACROS_H_INCLUDED
#define ASPEN_TYPE_MACROS_H_INCLUDED  1

#if !defined(__isDD__)
#define __isDD__		(0)
#endif

#if !defined(__isDF__)
#define __isDF__		(0)
#endif

#if !defined(__isDOUBLE__)
#define __isDOUBLE__		(0)
#endif

#if !defined(__isFLOAT__)
#define __isFLOAT__		(0)
#endif

#if !defined(__isHALF__)
#define __isHALF__		(0)
#endif

#if !defined(__isDD_COMPLEX__)
#define __isDD_COMPLEX__	(0)
#endif

#if !defined(__isDF_COMPLEX__)
#define __isDF_COMPLEX__	(0)
#endif

#if !defined(__isDOUBLE_COMPLEX__)
#define __isDOUBLE_COMPLEX__	(0)
#endif

#if !defined(__isFLOAT_COMPLEX__)
#define __isFLOAT_COMPLEX__	(0)
#endif

#if !defined(__isHALF_COMPLEX__)
#define __isHALF_COMPLEX__	(0)
#endif

#if !defined(__isINT16__)
#define __isINT16__		(0)
#endif

#if !defined(__isINT32__)
#define __isINT32__		(0)
#endif

#if !defined(__isINT64__)
#define __isINT64__		(0)
#endif

#if !defined(__isINT128__)
#define __isINT128__		(0)
#endif

#if !defined(__isBF16__)
#define __isBF16__		(0)
#endif


#define	__isREAL__		(__isDOUBLE__ || __isFLOAT__ || __isHALF__ || __isDD__ || __isDF__ || __isBF16__)
#define	__isCOMPLEX__		(__isDOUBLE_COMPLEX__ || __isFLOAT_COMPLEX__ || __isHALF_COMPLEX__ || __isDD_COMPLEX__ || __isDF_COMPLEX__)
#define	__isINT__		(__isINT16__ || __isINT32__ || __isINT64__ || __isINT128__)

#define __isDD_FORMAT__		(__isDD__ || __isDD_COMPLEX__)
#define __isDF_FORMAT__		(__isDF__ || __isDF_COMPLEX__)
#define __isSD_FORMAT__		(__isDOUBLE__ || __isDOUBLE_COMPLEX__)
#define __isSF_FORMAT__		(__isFLOAT__ || __isFLOAT_COMPLEX__)
#define __isSH_FORMAT__		(__isHALF__ || __isHALF_COMPLEX__)

#define	__is16BIT_FORMAT__	(__isHALF__ || __isINT16__)
#define	__is32BIT_FORMAT__	(__isFLOAT__ || __isINT32__ || __isHALF_COMPLEX__ )
#define	__is64BIT_FORMAT__	(__isDOUBLE__ || __isDF__ || __isINT64__ || __isFLOAT_COMPLEX__ )
#define	__is128BIT_FORMAT__	(__isDD__ || __isINT128__ || __isDOUBLE_COMPLEX__ || __isDF_COMPLEX__ )
#define	__is256BIT_FORMAT__	(__isDD_COMPLEX__)

#define	__isCOMPOUND_FORMAT__	(__isDD_FORMAT__ || __isDF_FORMAT__ )

#define	__isSPLITTABLE_FORMAT__	( !(__isCOMPOUND_FORMAT__ || __isINT128__) )

#define	__isBUILTIN_FORMAT__	(__isDOUBLE__ || __isFLOAT__ || __isHALF__ || __isDOUBLE_COMPLEX__ || __isFLOAT_COMPLEX__ || __isHALF_COMPLEX__ || __isINT16__ || __isINT32__ || __isINT64__)

#endif
