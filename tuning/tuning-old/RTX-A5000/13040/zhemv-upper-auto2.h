#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Sat Sep 26 23:42:50  2026
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

if ( n >= 1 && n < 7 ) {
	BLK = 1;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 4;
} else
if ( n >= 8 && n < 13 ) {
	BLK = 5;
} else
if ( n >= 13 && n < 17 ) {
	BLK = 3;
} else
if ( n >= 17 && n < 18 ) {
	BLK = 4;
} else
if ( n >= 18 && n < 32 ) {
	BLK = 5;
} else
if ( n >= 32 && n < 340 ) {
	BLK = 3;
} else
if ( n >= 340 && n < 411 ) {
	BLK = 1;
} else
if ( n >= 411 && n < 1280 ) {
	BLK = 3;
} else
if ( n >= 1280 && n < 1471 ) {
	BLK = 4;
} else
if ( n >= 1471 && n < 2048 ) {
	BLK = 5;
} else
if ( n >= 2048 && n < 8092 ) {
	BLK = 1;
} else
if ( n >= 8092 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
