#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Thu Nov 07 02:22:29  2024
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

if ( n >= 1 && n < 759 ) {
	BLK = 0;
} else
if ( n >= 759 && n < 1793 ) {
	BLK = 1;
} else
if ( n >= 1793 && n < 3368 ) {
	BLK = 2;
} else
if ( n >= 3368 && n < 3719 ) {
	BLK = 3;
} else
if ( n >= 3719 && n < 4081 ) {
	BLK = 2;
} else
if ( n >= 4081 && n < 4084 ) {
	BLK = 5;
} else
if ( n >= 4084 && n < 4173 ) {
	BLK = 3;
} else
if ( n >= 4173 && n < 6869 ) {
	BLK = 2;
} else
if ( n >= 6869 && n < 7486 ) {
	BLK = 4;
} else
if ( n >= 7486 && n < 7574 ) {
	BLK = 1;
} else
if ( n >= 7574 && n < 8066 ) {
	BLK = 2;
} else
if ( n >= 8066 && n < 11193 ) {
	BLK = 4;
} else
if ( n >= 11193 && n < 11450 ) {
	BLK = 5;
} else
if ( n >= 11450 && n < 11668 ) {
	BLK = 4;
} else
if ( n >= 11668 && n < 12098 ) {
	BLK = 2;
} else
if ( n >= 12098 && n < 12116 ) {
	BLK = 6;
} else
if ( n >= 12116 && n < 12298 ) {
	BLK = 4;
} else
if ( n >= 12298 && n < 12618 ) {
	BLK = 1;
} else
if ( n >= 12618 && n < 12627 ) {
	BLK = 4;
} else
if ( n >= 12627 && n < 14179 ) {
	BLK = 5;
} else
if ( n >= 14179 && n < 14475 ) {
	BLK = 1;
} else
if ( n >= 14475 && n < 17410 ) {
	BLK = 5;
} else
if ( n >= 17410 && n < 17701 ) {
	BLK = 1;
} else
if ( n >= 17701 && n < 20229 ) {
	BLK = 5;
} else
if ( n >= 20229 && n < 20603 ) {
	BLK = 1;
} else
if ( n >= 20603 && n < 22344 ) {
	BLK = 5;
} else
if ( n >= 22344 && n < 23234 ) {
	BLK = 1;
} else
if ( n >= 23234 && n < 24453 ) {
	BLK = 5;
} else
if ( n >= 24453 && n < 25674 ) {
	BLK = 1;
} else
if ( n >= 25674 && n < 30331 ) {
	BLK = 5;
} else
if ( n >= 30331 && n < 31885 ) {
	BLK = 1;
} else
if ( n >= 31885 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
