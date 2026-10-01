#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Wed Sep 23 07:17:36  2026
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
MAXmem= 16800759808
// capacity of the work area reserved on the GPU
WORK= 2539520
// for double or cuFloatComplex or int64
MAXDIM= 43535
// for float or cuHalfComplex or int32
MAXDIM2= 61568
// for cuDoubleComplex or DD or int128
MAXDIM3= 30784
// for DD-Complex
MAXDIM4= 21767
// for half or int16
MAXDIM5= 87070
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 335 ) {
	BLK = 0;
} else
if ( n >= 335 && n < 337 ) {
	BLK = 3;
} else
if ( n >= 337 && n < 1087 ) {
	BLK = 1;
} else
if ( n >= 1087 && n < 1104 ) {
	BLK = 0;
} else
if ( n >= 1104 && n < 1731 ) {
	BLK = 1;
} else
if ( n >= 1731 && n < 1732 ) {
	BLK = 4;
} else
if ( n >= 1732 && n < 1774 ) {
	BLK = 2;
} else
if ( n >= 1774 && n < 1776 ) {
	BLK = 1;
} else
if ( n >= 1776 && n < 1777 ) {
	BLK = 4;
} else
if ( n >= 1777 && n < 1786 ) {
	BLK = 2;
} else
if ( n >= 1786 && n < 1787 ) {
	BLK = 1;
} else
if ( n >= 1787 && n < 1788 ) {
	BLK = 4;
} else
if ( n >= 1788 && n < 1827 ) {
	BLK = 2;
} else
if ( n >= 1827 && n < 1885 ) {
	BLK = 1;
} else
if ( n >= 1885 && n < 1886 ) {
	BLK = 2;
} else
if ( n >= 1886 && n < 1887 ) {
	BLK = 4;
} else
if ( n >= 1887 && n < 1898 ) {
	BLK = 1;
} else
if ( n >= 1898 && n < 1983 ) {
	BLK = 2;
} else
if ( n >= 1983 && n < 1984 ) {
	BLK = 4;
} else
if ( n >= 1984 && n < 1986 ) {
	BLK = 1;
} else
if ( n >= 1986 && n < 2101 ) {
	BLK = 2;
} else
if ( n >= 2101 && n < 2102 ) {
	BLK = 4;
} else
if ( n >= 2102 && n < 2197 ) {
	BLK = 1;
} else
if ( n >= 2197 && n < 2900 ) {
	BLK = 2;
} else
if ( n >= 2900 && n < 2901 ) {
	BLK = 5;
} else
if ( n >= 2901 && n < 2909 ) {
	BLK = 4;
} else
if ( n >= 2909 && n < 3143 ) {
	BLK = 2;
} else
if ( n >= 3143 && n < 3170 ) {
	BLK = 4;
} else
if ( n >= 3170 && n < 3171 ) {
	BLK = 2;
} else
if ( n >= 3171 && n < 3174 ) {
	BLK = 5;
} else
if ( n >= 3174 && n < 3191 ) {
	BLK = 2;
} else
if ( n >= 3191 && n < 3192 ) {
	BLK = 5;
} else
if ( n >= 3192 && n < 3193 ) {
	BLK = 4;
} else
if ( n >= 3193 && n < 3214 ) {
	BLK = 2;
} else
if ( n >= 3214 && n < 3221 ) {
	BLK = 4;
} else
if ( n >= 3221 && n < 3251 ) {
	BLK = 2;
} else
if ( n >= 3251 && n < 3252 ) {
	BLK = 5;
} else
if ( n >= 3252 && n < 3257 ) {
	BLK = 4;
} else
if ( n >= 3257 && n < 3258 ) {
	BLK = 2;
} else
if ( n >= 3258 && n < 3264 ) {
	BLK = 5;
} else
if ( n >= 3264 && n < 3286 ) {
	BLK = 2;
} else
if ( n >= 3286 && n < 3290 ) {
	BLK = 4;
} else
if ( n >= 3290 && n < 3301 ) {
	BLK = 5;
} else
if ( n >= 3301 && n < 3302 ) {
	BLK = 2;
} else
if ( n >= 3302 && n < 3303 ) {
	BLK = 4;
} else
if ( n >= 3303 && n < 3305 ) {
	BLK = 5;
} else
if ( n >= 3305 && n < 3310 ) {
	BLK = 2;
} else
if ( n >= 3310 && n < 3317 ) {
	BLK = 5;
} else
if ( n >= 3317 && n < 3318 ) {
	BLK = 4;
} else
if ( n >= 3318 && n < 3358 ) {
	BLK = 2;
} else
if ( n >= 3358 && n < 3359 ) {
	BLK = 4;
} else
if ( n >= 3359 && n < 3393 ) {
	BLK = 5;
} else
if ( n >= 3393 && n < 3400 ) {
	BLK = 2;
} else
if ( n >= 3400 && n < 3415 ) {
	BLK = 5;
} else
if ( n >= 3415 && n < 3422 ) {
	BLK = 2;
} else
if ( n >= 3422 && n < 3423 ) {
	BLK = 5;
} else
if ( n >= 3423 && n < 3428 ) {
	BLK = 4;
} else
if ( n >= 3428 && n < 3448 ) {
	BLK = 5;
} else
if ( n >= 3448 && n < 3450 ) {
	BLK = 2;
} else
if ( n >= 3450 && n < 3451 ) {
	BLK = 4;
} else
if ( n >= 3451 && n < 3458 ) {
	BLK = 5;
} else
if ( n >= 3458 && n < 3459 ) {
	BLK = 2;
} else
if ( n >= 3459 && n < 3460 ) {
	BLK = 4;
} else
if ( n >= 3460 && n < 3469 ) {
	BLK = 5;
} else
if ( n >= 3469 && n < 3472 ) {
	BLK = 4;
} else
if ( n >= 3472 && n < 3481 ) {
	BLK = 2;
} else
if ( n >= 3481 && n < 3509 ) {
	BLK = 5;
} else
if ( n >= 3509 && n < 3510 ) {
	BLK = 2;
} else
if ( n >= 3510 && n < 3517 ) {
	BLK = 4;
} else
if ( n >= 3517 && n < 3540 ) {
	BLK = 5;
} else
if ( n >= 3540 && n < 3605 ) {
	BLK = 4;
} else
if ( n >= 3605 && n < 3769 ) {
	BLK = 5;
} else
if ( n >= 3769 && n < 3809 ) {
	BLK = 4;
} else
if ( n >= 3809 && n < 3810 ) {
	BLK = 2;
} else
if ( n >= 3810 && n < 3814 ) {
	BLK = 5;
} else
if ( n >= 3814 && n < 3835 ) {
	BLK = 4;
} else
if ( n >= 3835 && n < 3836 ) {
	BLK = 5;
} else
if ( n >= 3836 && n < 3837 ) {
	BLK = 2;
} else
if ( n >= 3837 && n < 5666 ) {
	BLK = 4;
} else
if ( n >= 5666 && n < 6470 ) {
	BLK = 0;
} else
if ( n >= 6470 && n < 11997 ) {
	BLK = 3;
} else
if ( n >= 11997 && n < 13610 ) {
	BLK = 1;
} else
if ( n >= 13610 && n < 17382 ) {
	BLK = 2;
} else
if ( n >= 17382 && n < 17669 ) {
	BLK = 1;
} else
if ( n >= 17669 && n < 19277 ) {
	BLK = 2;
} else
if ( n >= 19277 && n < 19953 ) {
	BLK = 1;
} else
if ( n >= 19953 && n < 20559 ) {
	BLK = 2;
} else
if ( n >= 20559 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
