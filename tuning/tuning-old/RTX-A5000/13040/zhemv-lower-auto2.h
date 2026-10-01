#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Sun Sep 27 07:20:47  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 5;
} else
if ( n >= 2 && n < 5 ) {
	BLK = 1;
} else
if ( n >= 5 && n < 9 ) {
	BLK = 2;
} else
if ( n >= 9 && n < 10 ) {
	BLK = 1;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 5;
} else
if ( n >= 11 && n < 15 ) {
	BLK = 4;
} else
if ( n >= 15 && n < 17 ) {
	BLK = 2;
} else
if ( n >= 17 && n < 22 ) {
	BLK = 5;
} else
if ( n >= 22 && n < 23 ) {
	BLK = 2;
} else
if ( n >= 23 && n < 30 ) {
	BLK = 4;
} else
if ( n >= 30 && n < 1056 ) {
	BLK = 3;
} else
if ( n >= 1056 && n < 1375 ) {
	BLK = 5;
} else
if ( n >= 1375 && n < 1380 ) {
	BLK = 4;
} else
if ( n >= 1380 && n < 1383 ) {
	BLK = 5;
} else
if ( n >= 1383 && n < 1386 ) {
	BLK = 2;
} else
if ( n >= 1386 && n < 1395 ) {
	BLK = 4;
} else
if ( n >= 1395 && n < 1396 ) {
	BLK = 5;
} else
if ( n >= 1396 && n < 1403 ) {
	BLK = 2;
} else
if ( n >= 1403 && n < 1404 ) {
	BLK = 5;
} else
if ( n >= 1404 && n < 2048 ) {
	BLK = 4;
} else
if ( n >= 2048 && n < 2871 ) {
	BLK = 1;
} else
if ( n >= 2871 && n < 3722 ) {
	BLK = 2;
} else
if ( n >= 3722 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
