#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Mon Sep 28 14:33:58  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2167 ) {
	BLK = 0;
} else
if ( n >= 2167 && n < 2223 ) {
	BLK = 2;
} else
if ( n >= 2223 && n < 3519 ) {
	BLK = 0;
} else
if ( n >= 3519 && n < 3551 ) {
	BLK = 5;
} else
if ( n >= 3551 && n < 3552 ) {
	BLK = 0;
} else
if ( n >= 3552 && n < 19670 ) {
	BLK = 1;
} else
if ( n >= 19670 && n < 20004 ) {
	BLK = 3;
} else
if ( n >= 20004 && n < 20861 ) {
	BLK = 1;
} else
if ( n >= 20861 && n < 21651 ) {
	BLK = 3;
} else
if ( n >= 21651 && n < 25494 ) {
	BLK = 1;
} else
if ( n >= 25494 && n < 51787 ) {
	BLK = 3;
} else
if ( n >= 51787 && n < 55432 ) {
	BLK = 1;
} else
if ( n >= 55432 && n < 57611 ) {
	BLK = 3;
} else
if ( n >= 57611 && n < 62137 ) {
	BLK = 1;
} else
if ( n >= 62137 && n < 64395 ) {
	BLK = 3;
} else
if ( n >= 64395 && n < 67744 ) {
	BLK = 1;
} else
if ( n >= 67744 && n < 78908 ) {
	BLK = 3;
} else
if ( n >= 78908 && n < 81065 ) {
	BLK = 1;
} else
if ( n >= 81065 && n < 84746 ) {
	BLK = 3;
} else
if ( n >= 84746 && n < 89116 ) {
	BLK = 1;
} else
if ( n >= 89116 && n < 92560 ) {
	BLK = 3;
} else
if ( n >= 92560 && n < 95239 ) {
	BLK = 1;
} else
if ( n >= 95239 && n < 115710 ) {
	BLK = 3;
} else
if ( n >= 115710 && n < 116732 ) {
	BLK = 1;
} else
if ( n >= 116732 && n < 123964 ) {
	BLK = 3;
} else
if ( n >= 123964 && n < 133900 ) {
	BLK = 1;
} else
if ( n >= 133900 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
