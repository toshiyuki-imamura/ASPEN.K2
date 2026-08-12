#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Mon Oct 13 12:19:30  2025
 Host on shannon.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16605855744
// capacity of the work area reserved on the GPU
WORK= 504832
// for double or cuFloatComplex or int64
MAXDIM= 43282
// for float or cuHalfComplex or int32
MAXDIM2= 61210
// for cuDoubleComplex or DD or int128
MAXDIM3= 30605
// for DD-Complex
MAXDIM4= 21641
// for half or int16
MAXDIM5= 86564
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 1200
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 14 ) {
	BLK = 0;
} else
if ( n >= 14 && n < 15 ) {
	BLK = 1;
} else
if ( n >= 15 && n < 21 ) {
	BLK = 6;
} else
if ( n >= 21 && n < 26 ) {
	BLK = 3;
} else
if ( n >= 26 && n < 135 ) {
	BLK = 0;
} else
if ( n >= 135 && n < 2004 ) {
	BLK = 2;
} else
if ( n >= 2004 && n < 3018 ) {
	BLK = 3;
} else
if ( n >= 3018 && n < 11022 ) {
	BLK = 1;
} else
if ( n >= 11022 && n < 11461 ) {
	BLK = 6;
} else
if ( n >= 11461 && n < 11918 ) {
	BLK = 1;
} else
if ( n >= 11918 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
