#ifndef KHEMVL_AUTO2_H_INCLUDED
#define KHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVL
 Thu Jul 30 05:11:57  2026
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
MAXmem= 50892406784
// capacity of the work area reserved on the GPU
WORK= 4421120
// for double or cuFloatComplex or int64
MAXDIM= 75771
// for float or cuHalfComplex or int32
MAXDIM2= 107156
// for cuDoubleComplex or DD or int128
MAXDIM3= 53578
// for DD-Complex
MAXDIM4= 37885
// for half or int16
MAXDIM5= 151542
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
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

if ( n >= 1 && n < 1885 ) {
	BLK = 0;
} else
if ( n >= 1885 && n < 2518 ) {
	BLK = 5;
} else
if ( n >= 2518 && n < 3522 ) {
	BLK = 3;
} else
if ( n >= 3522 && n < 3523 ) {
	BLK = 2;
} else
if ( n >= 3523 && n < 3524 ) {
	BLK = 4;
} else
if ( n >= 3524 && n < 3527 ) {
	BLK = 3;
} else
if ( n >= 3527 && n < 6011 ) {
	BLK = 2;
} else
if ( n >= 6011 && n < 6035 ) {
	BLK = 4;
} else
if ( n >= 6035 && n < 6039 ) {
	BLK = 3;
} else
if ( n >= 6039 && n < 9800 ) {
	BLK = 2;
} else
if ( n >= 9800 && n < 9814 ) {
	BLK = 3;
} else
if ( n >= 9814 && n < 9851 ) {
	BLK = 4;
} else
if ( n >= 9851 && n < 13743 ) {
	BLK = 2;
} else
if ( n >= 13743 && n < 18035 ) {
	BLK = 3;
} else
if ( n >= 18035 && n < 18070 ) {
	BLK = 2;
} else
if ( n >= 18070 && n < 18308 ) {
	BLK = 4;
} else
if ( n >= 18308 && n < 19511 ) {
	BLK = 3;
} else
if ( n >= 19511 && n < 19931 ) {
	BLK = 1;
} else
if ( n >= 19931 && n < 20234 ) {
	BLK = 3;
} else
if ( n >= 20234 && n < 25351 ) {
	BLK = 1;
} else
if ( n >= 25351 && n < 26058 ) {
	BLK = 3;
} else
if ( n >= 26058 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
