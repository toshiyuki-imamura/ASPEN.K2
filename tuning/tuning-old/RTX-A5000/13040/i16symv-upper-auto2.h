#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Sat Sep 26 05:39:58  2026
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2520 ) {
	BLK = 0;
} else
if ( n >= 2520 && n < 2522 ) {
	BLK = 3;
} else
if ( n >= 2522 && n < 2546 ) {
	BLK = 4;
} else
if ( n >= 2546 && n < 2547 ) {
	BLK = 3;
} else
if ( n >= 2547 && n < 2560 ) {
	BLK = 0;
} else
if ( n >= 2560 && n < 2622 ) {
	BLK = 4;
} else
if ( n >= 2622 && n < 2652 ) {
	BLK = 3;
} else
if ( n >= 2652 && n < 2654 ) {
	BLK = 4;
} else
if ( n >= 2654 && n < 2663 ) {
	BLK = 0;
} else
if ( n >= 2663 && n < 4491 ) {
	BLK = 3;
} else
if ( n >= 4491 && n < 20243 ) {
	BLK = 1;
} else
if ( n >= 20243 && n < 20548 ) {
	BLK = 2;
} else
if ( n >= 20548 && n < 21380 ) {
	BLK = 1;
} else
if ( n >= 21380 && n < 29013 ) {
	BLK = 2;
} else
if ( n >= 29013 && n < 29501 ) {
	BLK = 1;
} else
if ( n >= 29501 && n < 61069 ) {
	BLK = 2;
} else
if ( n >= 61069 && n < 62453 ) {
	BLK = 1;
} else
if ( n >= 62453 && n < 68284 ) {
	BLK = 2;
} else
if ( n >= 68284 && n < 71029 ) {
	BLK = 1;
} else
if ( n >= 71029 && n < 77319 ) {
	BLK = 2;
} else
if ( n >= 77319 && n < 78477 ) {
	BLK = 1;
} else
if ( n >= 78477 && n < 83294 ) {
	BLK = 2;
} else
if ( n >= 83294 && n < 86097 ) {
	BLK = 1;
} else
if ( n >= 86097 && n < 92593 ) {
	BLK = 2;
} else
if ( n >= 92593 && n < 98250 ) {
	BLK = 1;
} else
if ( n >= 98250 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
