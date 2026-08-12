#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Mon Jun 22 00:13:06  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 271 ) {
	BLK = 0;
} else
if ( n >= 271 && n < 274 ) {
	BLK = 2;
} else
if ( n >= 274 && n < 665 ) {
	BLK = 0;
} else
if ( n >= 665 && n < 666 ) {
	BLK = 2;
} else
if ( n >= 666 && n < 667 ) {
	BLK = 1;
} else
if ( n >= 667 && n < 810 ) {
	BLK = 0;
} else
if ( n >= 810 && n < 811 ) {
	BLK = 1;
} else
if ( n >= 811 && n < 823 ) {
	BLK = 2;
} else
if ( n >= 823 && n < 936 ) {
	BLK = 0;
} else
if ( n >= 936 && n < 937 ) {
	BLK = 1;
} else
if ( n >= 937 && n < 946 ) {
	BLK = 2;
} else
if ( n >= 946 && n < 947 ) {
	BLK = 1;
} else
if ( n >= 947 && n < 1101 ) {
	BLK = 0;
} else
if ( n >= 1101 && n < 1102 ) {
	BLK = 1;
} else
if ( n >= 1102 && n < 1124 ) {
	BLK = 2;
} else
if ( n >= 1124 && n < 4670 ) {
	BLK = 0;
} else
if ( n >= 4670 && n < 4675 ) {
	BLK = 1;
} else
if ( n >= 4675 && n < 4679 ) {
	BLK = 2;
} else
if ( n >= 4679 && n < 5185 ) {
	BLK = 0;
} else
if ( n >= 5185 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
