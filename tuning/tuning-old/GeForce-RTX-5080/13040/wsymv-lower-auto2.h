#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Sat Sep 26 13:05:05  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 1200
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 8 ) {
	BLK = 1;
} else
if ( n >= 8 && n < 12 ) {
	BLK = 3;
} else
if ( n >= 12 && n < 24 ) {
	BLK = 4;
} else
if ( n >= 24 && n < 30 ) {
	BLK = 2;
} else
if ( n >= 30 && n < 311 ) {
	BLK = 5;
} else
if ( n >= 311 && n < 6564 ) {
	BLK = 1;
} else
if ( n >= 6564 && n < 6611 ) {
	BLK = 4;
} else
if ( n >= 6611 && n < 6613 ) {
	BLK = 3;
} else
if ( n >= 6613 && n < 8380 ) {
	BLK = 1;
} else
if ( n >= 8380 && n < 8758 ) {
	BLK = 4;
} else
if ( n >= 8758 && n < 9209 ) {
	BLK = 2;
} else
if ( n >= 9209 && n < 10715 ) {
	BLK = 4;
} else
if ( n >= 10715 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
