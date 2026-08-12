#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Tue Nov 05 15:20:42  2024
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-GTX-1080
****************************************/-->
// device name
DEVICE= GeForce-GTX-1080
// the number of multi-processors
MP= 20
// compute-compatibility generation
CG= 610
// capacity of the global memory or host memory
MAXmem= 8497229824
// capacity of the work area reserved on the GPU
WORK= 360960
// for double or cuFloatComplex or int64
MAXDIM= 30961
// for float or cuHalfComplex or int32
MAXDIM2= 43785
// for cuDoubleComplex or DD or int128
MAXDIM3= 21892
// for DD-Complex
MAXDIM4= 15480
// for half or int16
MAXDIM5= 61922
// cuda version
CUDA= 12060
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 610
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 18 ) {
	BLK = 3;
} else
if ( n >= 18 && n < 23 ) {
	BLK = 5;
} else
if ( n >= 23 && n < 139 ) {
	BLK = 0;
} else
if ( n >= 139 && n < 140 ) {
	BLK = 2;
} else
if ( n >= 140 && n < 142 ) {
	BLK = 3;
} else
if ( n >= 142 && n < 146 ) {
	BLK = 0;
} else
if ( n >= 146 && n < 159 ) {
	BLK = 3;
} else
if ( n >= 159 && n < 281 ) {
	BLK = 2;
} else
if ( n >= 281 && n < 334 ) {
	BLK = 1;
} else
if ( n >= 334 && n < 338 ) {
	BLK = 2;
} else
if ( n >= 338 && n < 342 ) {
	BLK = 1;
} else
if ( n >= 342 && n < 344 ) {
	BLK = 0;
} else
if ( n >= 344 && n < 354 ) {
	BLK = 2;
} else
if ( n >= 354 && n < 355 ) {
	BLK = 0;
} else
if ( n >= 355 && n < 356 ) {
	BLK = 1;
} else
if ( n >= 356 && n < 358 ) {
	BLK = 6;
} else
if ( n >= 358 && n < 361 ) {
	BLK = 0;
} else
if ( n >= 361 && n < 366 ) {
	BLK = 1;
} else
if ( n >= 366 && n < 368 ) {
	BLK = 6;
} else
if ( n >= 368 && n < 398 ) {
	BLK = 2;
} else
if ( n >= 398 && n < 406 ) {
	BLK = 6;
} else
if ( n >= 406 && n < 636 ) {
	BLK = 0;
} else
if ( n >= 636 && n < 940 ) {
	BLK = 2;
} else
if ( n >= 940 && n < 1713 ) {
	BLK = 3;
} else
if ( n >= 1713 && n < 1928 ) {
	BLK = 1;
} else
if ( n >= 1928 && n < 3918 ) {
	BLK = 0;
} else
if ( n >= 3918 && n < 4252 ) {
	BLK = 1;
} else
if ( n >= 4252 && n < 2147483647 ) {
	BLK = 0;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 0;
} 

#endif
