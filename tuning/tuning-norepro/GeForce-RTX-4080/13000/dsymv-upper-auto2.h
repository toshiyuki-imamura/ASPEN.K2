#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Sat Nov 01 19:25:54  2025
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 15 ) {
	BLK = 0;
} else
if ( n >= 15 && n < 20 ) {
	BLK = 2;
} else
if ( n >= 20 && n < 22 ) {
	BLK = 1;
} else
if ( n >= 22 && n < 239 ) {
	BLK = 0;
} else
if ( n >= 239 && n < 437 ) {
	BLK = 5;
} else
if ( n >= 437 && n < 440 ) {
	BLK = 6;
} else
if ( n >= 440 && n < 444 ) {
	BLK = 4;
} else
if ( n >= 444 && n < 519 ) {
	BLK = 5;
} else
if ( n >= 519 && n < 582 ) {
	BLK = 4;
} else
if ( n >= 582 && n < 585 ) {
	BLK = 3;
} else
if ( n >= 585 && n < 588 ) {
	BLK = 6;
} else
if ( n >= 588 && n < 899 ) {
	BLK = 4;
} else
if ( n >= 899 && n < 902 ) {
	BLK = 6;
} else
if ( n >= 902 && n < 1544 ) {
	BLK = 3;
} else
if ( n >= 1544 && n < 1622 ) {
	BLK = 2;
} else
if ( n >= 1622 && n < 2358 ) {
	BLK = 1;
} else
if ( n >= 2358 && n < 3603 ) {
	BLK = 2;
} else
if ( n >= 3603 && n < 6294 ) {
	BLK = 1;
} else
if ( n >= 6294 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
