#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Sun Jun 21 17:06:57  2026
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

if ( n >= 1 && n < 2658 ) {
	BLK = 2;
} else
if ( n >= 2658 && n < 16034 ) {
	BLK = 1;
} else
if ( n >= 16034 && n < 16612 ) {
	BLK = 2;
} else
if ( n >= 16612 && n < 18113 ) {
	BLK = 1;
} else
if ( n >= 18113 && n < 18914 ) {
	BLK = 2;
} else
if ( n >= 18914 && n < 19393 ) {
	BLK = 1;
} else
if ( n >= 19393 && n < 19706 ) {
	BLK = 2;
} else
if ( n >= 19706 && n < 19983 ) {
	BLK = 1;
} else
if ( n >= 19983 && n < 20249 ) {
	BLK = 2;
} else
if ( n >= 20249 && n < 20598 ) {
	BLK = 1;
} else
if ( n >= 20598 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
