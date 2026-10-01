#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Sat Sep 26 03:59:30  2026
 Host on fermat.r-ccs27.riken.jp
 Device is RTX-A5000
****************************************/-->
// device name
DEVICE= RTX-A5000
// the number of multi-processors
MP= 64
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 25327001600
// capacity of the work area reserved on the GPU
WORK= 3118080
// for double or cuFloatComplex or int64
MAXDIM= 53452
// for float or cuHalfComplex or int32
MAXDIM2= 75593
// for cuDoubleComplex or DD or int128
MAXDIM3= 37796
// for DD-Complex
MAXDIM4= 26726
// for half or int16
MAXDIM5= 106905
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

if ( n >= 1 && n < 1056 ) {
	BLK = 0;
} else
if ( n >= 1056 && n < 1094 ) {
	BLK = 5;
} else
if ( n >= 1094 && n < 1101 ) {
	BLK = 1;
} else
if ( n >= 1101 && n < 1117 ) {
	BLK = 5;
} else
if ( n >= 1117 && n < 1118 ) {
	BLK = 0;
} else
if ( n >= 1118 && n < 1137 ) {
	BLK = 1;
} else
if ( n >= 1137 && n < 1138 ) {
	BLK = 2;
} else
if ( n >= 1138 && n < 1156 ) {
	BLK = 5;
} else
if ( n >= 1156 && n < 1169 ) {
	BLK = 1;
} else
if ( n >= 1169 && n < 1172 ) {
	BLK = 0;
} else
if ( n >= 1172 && n < 1315 ) {
	BLK = 1;
} else
if ( n >= 1315 && n < 1741 ) {
	BLK = 5;
} else
if ( n >= 1741 && n < 1782 ) {
	BLK = 0;
} else
if ( n >= 1782 && n < 1783 ) {
	BLK = 5;
} else
if ( n >= 1783 && n < 3464 ) {
	BLK = 1;
} else
if ( n >= 3464 && n < 3476 ) {
	BLK = 3;
} else
if ( n >= 3476 && n < 3477 ) {
	BLK = 1;
} else
if ( n >= 3477 && n < 3478 ) {
	BLK = 4;
} else
if ( n >= 3478 && n < 3484 ) {
	BLK = 3;
} else
if ( n >= 3484 && n < 3540 ) {
	BLK = 1;
} else
if ( n >= 3540 && n < 3541 ) {
	BLK = 3;
} else
if ( n >= 3541 && n < 3542 ) {
	BLK = 4;
} else
if ( n >= 3542 && n < 3791 ) {
	BLK = 1;
} else
if ( n >= 3791 && n < 3792 ) {
	BLK = 2;
} else
if ( n >= 3792 && n < 3942 ) {
	BLK = 3;
} else
if ( n >= 3942 && n < 24127 ) {
	BLK = 1;
} else
if ( n >= 24127 && n < 26293 ) {
	BLK = 3;
} else
if ( n >= 26293 && n < 27050 ) {
	BLK = 1;
} else
if ( n >= 27050 && n < 28402 ) {
	BLK = 3;
} else
if ( n >= 28402 && n < 29124 ) {
	BLK = 1;
} else
if ( n >= 29124 && n < 30829 ) {
	BLK = 3;
} else
if ( n >= 30829 && n < 32201 ) {
	BLK = 1;
} else
if ( n >= 32201 && n < 32920 ) {
	BLK = 3;
} else
if ( n >= 32920 && n < 34426 ) {
	BLK = 1;
} else
if ( n >= 34426 && n < 35828 ) {
	BLK = 3;
} else
if ( n >= 35828 && n < 37918 ) {
	BLK = 1;
} else
if ( n >= 37918 && n < 43901 ) {
	BLK = 3;
} else
if ( n >= 43901 && n < 46924 ) {
	BLK = 1;
} else
if ( n >= 46924 && n < 50784 ) {
	BLK = 3;
} else
if ( n >= 50784 && n < 54155 ) {
	BLK = 1;
} else
if ( n >= 54155 && n < 67550 ) {
	BLK = 3;
} else
if ( n >= 67550 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
