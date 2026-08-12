#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Tue Oct 28 17:03:05  2025
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16715563008
// capacity of the work area reserved on the GPU
WORK= 506368
// for double or cuFloatComplex or int64
MAXDIM= 43424
// for float or cuHalfComplex or int32
MAXDIM2= 61412
// for cuDoubleComplex or DD or int128
MAXDIM3= 30706
// for DD-Complex
MAXDIM4= 21712
// for half or int16
MAXDIM5= 86849
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 7 ) {
	BLK = 1;
} else
if ( n >= 7 && n < 11 ) {
	BLK = 2;
} else
if ( n >= 11 && n < 240 ) {
	BLK = 4;
} else
if ( n >= 240 && n < 344 ) {
	BLK = 6;
} else
if ( n >= 344 && n < 369 ) {
	BLK = 1;
} else
if ( n >= 369 && n < 494 ) {
	BLK = 4;
} else
if ( n >= 494 && n < 1003 ) {
	BLK = 2;
} else
if ( n >= 1003 && n < 1882 ) {
	BLK = 3;
} else
if ( n >= 1882 && n < 2398 ) {
	BLK = 1;
} else
if ( n >= 2398 && n < 2508 ) {
	BLK = 3;
} else
if ( n >= 2508 && n < 3071 ) {
	BLK = 5;
} else
if ( n >= 3071 && n < 3941 ) {
	BLK = 1;
} else
if ( n >= 3941 && n < 5314 ) {
	BLK = 5;
} else
if ( n >= 5314 && n < 6019 ) {
	BLK = 1;
} else
if ( n >= 6019 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
