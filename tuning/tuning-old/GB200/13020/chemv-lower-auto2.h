#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Thu Jun 25 05:22:50  2026
 Host on ar09n01-m.ai.r-ccs.riken.jp
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

if ( n >= 1 && n < 1015 ) {
	BLK = 0;
} else
if ( n >= 1015 && n < 1016 ) {
	BLK = 1;
} else
if ( n >= 1016 && n < 1017 ) {
	BLK = 2;
} else
if ( n >= 1017 && n < 1038 ) {
	BLK = 0;
} else
if ( n >= 1038 && n < 1039 ) {
	BLK = 2;
} else
if ( n >= 1039 && n < 1047 ) {
	BLK = 1;
} else
if ( n >= 1047 && n < 1518 ) {
	BLK = 0;
} else
if ( n >= 1518 && n < 1553 ) {
	BLK = 1;
} else
if ( n >= 1553 && n < 1563 ) {
	BLK = 2;
} else
if ( n >= 1563 && n < 1583 ) {
	BLK = 1;
} else
if ( n >= 1583 && n < 1634 ) {
	BLK = 0;
} else
if ( n >= 1634 && n < 1635 ) {
	BLK = 2;
} else
if ( n >= 1635 && n < 1640 ) {
	BLK = 1;
} else
if ( n >= 1640 && n < 1644 ) {
	BLK = 2;
} else
if ( n >= 1644 && n < 1645 ) {
	BLK = 1;
} else
if ( n >= 1645 && n < 4533 ) {
	BLK = 0;
} else
if ( n >= 4533 && n < 9014 ) {
	BLK = 1;
} else
if ( n >= 9014 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
