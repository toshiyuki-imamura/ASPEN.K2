#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Sun Nov 10 05:41:46  2024
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
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 14 ) {
	BLK = 3;
} else
if ( n >= 14 && n < 18 ) {
	BLK = 4;
} else
if ( n >= 18 && n < 27 ) {
	BLK = 6;
} else
if ( n >= 27 && n < 381 ) {
	BLK = 1;
} else
if ( n >= 381 && n < 395 ) {
	BLK = 5;
} else
if ( n >= 395 && n < 398 ) {
	BLK = 1;
} else
if ( n >= 398 && n < 408 ) {
	BLK = 6;
} else
if ( n >= 408 && n < 419 ) {
	BLK = 5;
} else
if ( n >= 419 && n < 431 ) {
	BLK = 6;
} else
if ( n >= 431 && n < 501 ) {
	BLK = 1;
} else
if ( n >= 501 && n < 504 ) {
	BLK = 6;
} else
if ( n >= 504 && n < 519 ) {
	BLK = 0;
} else
if ( n >= 519 && n < 529 ) {
	BLK = 1;
} else
if ( n >= 529 && n < 536 ) {
	BLK = 6;
} else
if ( n >= 536 && n < 702 ) {
	BLK = 0;
} else
if ( n >= 702 && n < 1010 ) {
	BLK = 5;
} else
if ( n >= 1010 && n < 2122 ) {
	BLK = 1;
} else
if ( n >= 2122 && n < 2582 ) {
	BLK = 3;
} else
if ( n >= 2582 && n < 2764 ) {
	BLK = 1;
} else
if ( n >= 2764 && n < 3426 ) {
	BLK = 4;
} else
if ( n >= 3426 && n < 3964 ) {
	BLK = 1;
} else
if ( n >= 3964 && n < 4388 ) {
	BLK = 2;
} else
if ( n >= 4388 && n < 5058 ) {
	BLK = 1;
} else
if ( n >= 5058 && n < 6304 ) {
	BLK = 0;
} else
if ( n >= 6304 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
