#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Sun Oct 26 14:32:03  2025
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
	BLK = 2;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 5;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 6;
} else
if ( n >= 4 && n < 6 ) {
	BLK = 2;
} else
if ( n >= 6 && n < 9 ) {
	BLK = 5;
} else
if ( n >= 9 && n < 12 ) {
	BLK = 1;
} else
if ( n >= 12 && n < 14 ) {
	BLK = 2;
} else
if ( n >= 14 && n < 15 ) {
	BLK = 6;
} else
if ( n >= 15 && n < 18 ) {
	BLK = 3;
} else
if ( n >= 18 && n < 22 ) {
	BLK = 5;
} else
if ( n >= 22 && n < 26 ) {
	BLK = 1;
} else
if ( n >= 26 && n < 34 ) {
	BLK = 3;
} else
if ( n >= 34 && n < 385 ) {
	BLK = 4;
} else
if ( n >= 385 && n < 386 ) {
	BLK = 1;
} else
if ( n >= 386 && n < 394 ) {
	BLK = 5;
} else
if ( n >= 394 && n < 438 ) {
	BLK = 1;
} else
if ( n >= 438 && n < 468 ) {
	BLK = 5;
} else
if ( n >= 468 && n < 479 ) {
	BLK = 4;
} else
if ( n >= 479 && n < 519 ) {
	BLK = 1;
} else
if ( n >= 519 && n < 520 ) {
	BLK = 4;
} else
if ( n >= 520 && n < 524 ) {
	BLK = 3;
} else
if ( n >= 524 && n < 616 ) {
	BLK = 5;
} else
if ( n >= 616 && n < 619 ) {
	BLK = 3;
} else
if ( n >= 619 && n < 624 ) {
	BLK = 1;
} else
if ( n >= 624 && n < 626 ) {
	BLK = 5;
} else
if ( n >= 626 && n < 630 ) {
	BLK = 3;
} else
if ( n >= 630 && n < 724 ) {
	BLK = 1;
} else
if ( n >= 724 && n < 729 ) {
	BLK = 3;
} else
if ( n >= 729 && n < 738 ) {
	BLK = 5;
} else
if ( n >= 738 && n < 768 ) {
	BLK = 1;
} else
if ( n >= 768 && n < 1367 ) {
	BLK = 3;
} else
if ( n >= 1367 && n < 2888 ) {
	BLK = 1;
} else
if ( n >= 2888 && n < 4466 ) {
	BLK = 2;
} else
if ( n >= 4466 && n < 4653 ) {
	BLK = 1;
} else
if ( n >= 4653 && n < 8711 ) {
	BLK = 6;
} else
if ( n >= 8711 && n < 9061 ) {
	BLK = 2;
} else
if ( n >= 9061 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
