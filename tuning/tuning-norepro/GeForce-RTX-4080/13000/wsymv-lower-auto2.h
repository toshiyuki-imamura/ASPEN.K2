#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Fri Oct 24 13:50:48  2025
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16715563008
// capacity of the work area reserved on the GPU
WORK= 506368
// for double or cuFloatComplex or int64
MAXDIM= 43424
// for float or cuHalfComplex or int32
MAXDIM2= 61412
// for cuDoubleComplex or DD or int128
MAXDIM3= 30706
// for DD-Complex
MAXDIM4= 21712
// for half or int16
MAXDIM5= 86849
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 7 ) {
	BLK = 3;
} else
if ( n >= 7 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 13 ) {
	BLK = 5;
} else
if ( n >= 13 && n < 18 ) {
	BLK = 4;
} else
if ( n >= 18 && n < 391 ) {
	BLK = 6;
} else
if ( n >= 391 && n < 888 ) {
	BLK = 2;
} else
if ( n >= 888 && n < 889 ) {
	BLK = 5;
} else
if ( n >= 889 && n < 892 ) {
	BLK = 1;
} else
if ( n >= 892 && n < 1356 ) {
	BLK = 2;
} else
if ( n >= 1356 && n < 1578 ) {
	BLK = 5;
} else
if ( n >= 1578 && n < 2040 ) {
	BLK = 1;
} else
if ( n >= 2040 && n < 2635 ) {
	BLK = 4;
} else
if ( n >= 2635 && n < 3685 ) {
	BLK = 1;
} else
if ( n >= 3685 && n < 5536 ) {
	BLK = 3;
} else
if ( n >= 5536 && n < 6871 ) {
	BLK = 1;
} else
if ( n >= 6871 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
