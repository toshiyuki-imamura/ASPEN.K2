#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Mon Sep 28 19:04:46  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 1;
} else
if ( n >= 2 && n < 688 ) {
	BLK = 4;
} else
if ( n >= 688 && n < 3229 ) {
	BLK = 2;
} else
if ( n >= 3229 && n < 3288 ) {
	BLK = 5;
} else
if ( n >= 3288 && n < 4712 ) {
	BLK = 1;
} else
if ( n >= 4712 && n < 5817 ) {
	BLK = 2;
} else
if ( n >= 5817 && n < 5835 ) {
	BLK = 5;
} else
if ( n >= 5835 && n < 7343 ) {
	BLK = 1;
} else
if ( n >= 7343 && n < 8043 ) {
	BLK = 3;
} else
if ( n >= 8043 && n < 14604 ) {
	BLK = 1;
} else
if ( n >= 14604 && n < 15701 ) {
	BLK = 3;
} else
if ( n >= 15701 && n < 22056 ) {
	BLK = 1;
} else
if ( n >= 22056 && n < 23989 ) {
	BLK = 3;
} else
if ( n >= 23989 && n < 29102 ) {
	BLK = 1;
} else
if ( n >= 29102 && n < 31041 ) {
	BLK = 3;
} else
if ( n >= 31041 && n < 34936 ) {
	BLK = 1;
} else
if ( n >= 34936 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
