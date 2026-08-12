#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Sat Jun 20 14:20:23  2026
 Host on ar11n06-m.ai.r-ccs.riken.jp
 Device is GB200
****************************************/-->
// device name
DEVICE= GB200
// the number of multi-processors
MP= 152
// compute-compatibility generation
CG= 1000
// capacity of the global memory or host memory
MAXmem= 197555425280
// capacity of the work area reserved on the GPU
WORK= 13067520
// for double or cuFloatComplex or int64
MAXDIM= 149287
// for float or cuHalfComplex or int32
MAXDIM2= 211124
// for cuDoubleComplex or DD or int128
MAXDIM3= 105562
// for DD-Complex
MAXDIM4= 74643
// for half or int16
MAXDIM5= 298574
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1000
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2749 ) {
	BLK = 1;
} else
if ( n >= 2749 && n < 5314 ) {
	BLK = 2;
} else
if ( n >= 5314 && n < 7686 ) {
	BLK = 1;
} else
if ( n >= 7686 && n < 9858 ) {
	BLK = 2;
} else
if ( n >= 9858 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
