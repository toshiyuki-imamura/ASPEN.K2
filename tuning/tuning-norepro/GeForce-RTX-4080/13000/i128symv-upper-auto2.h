#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Tue Oct 21 23:00:14  2025
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

if ( n >= 1 && n < 2 ) {
	BLK = 1;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 3;
} else
if ( n >= 3 && n < 34 ) {
	BLK = 2;
} else
if ( n >= 34 && n < 65 ) {
	BLK = 3;
} else
if ( n >= 65 && n < 68 ) {
	BLK = 2;
} else
if ( n >= 68 && n < 364 ) {
	BLK = 1;
} else
if ( n >= 364 && n < 365 ) {
	BLK = 2;
} else
if ( n >= 365 && n < 371 ) {
	BLK = 3;
} else
if ( n >= 371 && n < 390 ) {
	BLK = 1;
} else
if ( n >= 390 && n < 407 ) {
	BLK = 3;
} else
if ( n >= 407 && n < 418 ) {
	BLK = 1;
} else
if ( n >= 418 && n < 419 ) {
	BLK = 2;
} else
if ( n >= 419 && n < 432 ) {
	BLK = 3;
} else
if ( n >= 432 && n < 436 ) {
	BLK = 2;
} else
if ( n >= 436 && n < 448 ) {
	BLK = 1;
} else
if ( n >= 448 && n < 450 ) {
	BLK = 3;
} else
if ( n >= 450 && n < 452 ) {
	BLK = 2;
} else
if ( n >= 452 && n < 565 ) {
	BLK = 1;
} else
if ( n >= 565 && n < 592 ) {
	BLK = 2;
} else
if ( n >= 592 && n < 599 ) {
	BLK = 3;
} else
if ( n >= 599 && n < 684 ) {
	BLK = 1;
} else
if ( n >= 684 && n < 1368 ) {
	BLK = 2;
} else
if ( n >= 1368 && n < 4366 ) {
	BLK = 1;
} else
if ( n >= 4366 && n < 5921 ) {
	BLK = 4;
} else
if ( n >= 5921 && n < 8966 ) {
	BLK = 5;
} else
if ( n >= 8966 && n < 9425 ) {
	BLK = 6;
} else
if ( n >= 9425 && n < 10132 ) {
	BLK = 5;
} else
if ( n >= 10132 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
