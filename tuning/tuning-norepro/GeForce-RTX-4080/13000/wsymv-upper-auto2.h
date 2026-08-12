#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Sun Oct 19 21:55:57  2025
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 8 ) {
	BLK = 3;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 5;
} else
if ( n >= 9 && n < 14 ) {
	BLK = 2;
} else
if ( n >= 14 && n < 22 ) {
	BLK = 3;
} else
if ( n >= 22 && n < 474 ) {
	BLK = 5;
} else
if ( n >= 474 && n < 478 ) {
	BLK = 4;
} else
if ( n >= 478 && n < 479 ) {
	BLK = 2;
} else
if ( n >= 479 && n < 482 ) {
	BLK = 5;
} else
if ( n >= 482 && n < 712 ) {
	BLK = 4;
} else
if ( n >= 712 && n < 1583 ) {
	BLK = 1;
} else
if ( n >= 1583 && n < 2787 ) {
	BLK = 2;
} else
if ( n >= 2787 && n < 3970 ) {
	BLK = 3;
} else
if ( n >= 3970 && n < 22735 ) {
	BLK = 6;
} else
if ( n >= 22735 && n < 23078 ) {
	BLK = 0;
} else
if ( n >= 23078 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
