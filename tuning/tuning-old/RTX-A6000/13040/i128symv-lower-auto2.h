#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Mon Sep 28 00:57:29  2026
 Host on pascal.r-ccs27.riken.jp
 Device is RTX-A6000
****************************************/-->
// device name
DEVICE= RTX-A6000
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 50949160960
// capacity of the work area reserved on the GPU
WORK= 4423680
// for double or cuFloatComplex or int64
MAXDIM= 75813
// for float or cuHalfComplex or int32
MAXDIM2= 107216
// for cuDoubleComplex or DD or int128
MAXDIM3= 53608
// for DD-Complex
MAXDIM4= 37906
// for half or int16
MAXDIM5= 151627
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 16 ) {
	BLK = 4;
} else
if ( n >= 16 && n < 32 ) {
	BLK = 1;
} else
if ( n >= 32 && n < 58 ) {
	BLK = 3;
} else
if ( n >= 58 && n < 59 ) {
	BLK = 1;
} else
if ( n >= 59 && n < 707 ) {
	BLK = 0;
} else
if ( n >= 707 && n < 708 ) {
	BLK = 5;
} else
if ( n >= 708 && n < 712 ) {
	BLK = 3;
} else
if ( n >= 712 && n < 713 ) {
	BLK = 5;
} else
if ( n >= 713 && n < 766 ) {
	BLK = 0;
} else
if ( n >= 766 && n < 767 ) {
	BLK = 3;
} else
if ( n >= 767 && n < 779 ) {
	BLK = 5;
} else
if ( n >= 779 && n < 813 ) {
	BLK = 0;
} else
if ( n >= 813 && n < 819 ) {
	BLK = 5;
} else
if ( n >= 819 && n < 1068 ) {
	BLK = 0;
} else
if ( n >= 1068 && n < 1277 ) {
	BLK = 5;
} else
if ( n >= 1277 && n < 1298 ) {
	BLK = 2;
} else
if ( n >= 1298 && n < 1299 ) {
	BLK = 3;
} else
if ( n >= 1299 && n < 1300 ) {
	BLK = 5;
} else
if ( n >= 1300 && n < 3971 ) {
	BLK = 2;
} else
if ( n >= 3971 && n < 9130 ) {
	BLK = 4;
} else
if ( n >= 9130 && n < 9144 ) {
	BLK = 3;
} else
if ( n >= 9144 && n < 9165 ) {
	BLK = 2;
} else
if ( n >= 9165 && n < 45961 ) {
	BLK = 4;
} else
if ( n >= 45961 && n < 47574 ) {
	BLK = 1;
} else
if ( n >= 47574 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
