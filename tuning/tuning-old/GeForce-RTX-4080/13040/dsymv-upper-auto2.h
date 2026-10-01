#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Tue Sep 22 18:57:06  2026
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

if ( n >= 1 && n < 8 ) {
	BLK = 0;
} else
if ( n >= 8 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 18 ) {
	BLK = 1;
} else
if ( n >= 18 && n < 20 ) {
	BLK = 4;
} else
if ( n >= 20 && n < 21 ) {
	BLK = 5;
} else
if ( n >= 21 && n < 32 ) {
	BLK = 1;
} else
if ( n >= 32 && n < 905 ) {
	BLK = 0;
} else
if ( n >= 905 && n < 1030 ) {
	BLK = 5;
} else
if ( n >= 1030 && n < 1031 ) {
	BLK = 4;
} else
if ( n >= 1031 && n < 1081 ) {
	BLK = 3;
} else
if ( n >= 1081 && n < 2052 ) {
	BLK = 5;
} else
if ( n >= 2052 && n < 2814 ) {
	BLK = 1;
} else
if ( n >= 2814 && n < 3158 ) {
	BLK = 4;
} else
if ( n >= 3158 && n < 3168 ) {
	BLK = 2;
} else
if ( n >= 3168 && n < 3191 ) {
	BLK = 4;
} else
if ( n >= 3191 && n < 3193 ) {
	BLK = 1;
} else
if ( n >= 3193 && n < 3194 ) {
	BLK = 2;
} else
if ( n >= 3194 && n < 3225 ) {
	BLK = 4;
} else
if ( n >= 3225 && n < 3232 ) {
	BLK = 2;
} else
if ( n >= 3232 && n < 3281 ) {
	BLK = 4;
} else
if ( n >= 3281 && n < 3287 ) {
	BLK = 2;
} else
if ( n >= 3287 && n < 3289 ) {
	BLK = 4;
} else
if ( n >= 3289 && n < 3292 ) {
	BLK = 1;
} else
if ( n >= 3292 && n < 3294 ) {
	BLK = 4;
} else
if ( n >= 3294 && n < 3299 ) {
	BLK = 2;
} else
if ( n >= 3299 && n < 3301 ) {
	BLK = 1;
} else
if ( n >= 3301 && n < 3302 ) {
	BLK = 4;
} else
if ( n >= 3302 && n < 3309 ) {
	BLK = 2;
} else
if ( n >= 3309 && n < 3310 ) {
	BLK = 1;
} else
if ( n >= 3310 && n < 3311 ) {
	BLK = 4;
} else
if ( n >= 3311 && n < 3317 ) {
	BLK = 2;
} else
if ( n >= 3317 && n < 3318 ) {
	BLK = 4;
} else
if ( n >= 3318 && n < 3320 ) {
	BLK = 1;
} else
if ( n >= 3320 && n < 3335 ) {
	BLK = 2;
} else
if ( n >= 3335 && n < 3336 ) {
	BLK = 1;
} else
if ( n >= 3336 && n < 3346 ) {
	BLK = 4;
} else
if ( n >= 3346 && n < 3352 ) {
	BLK = 1;
} else
if ( n >= 3352 && n < 3356 ) {
	BLK = 4;
} else
if ( n >= 3356 && n < 3408 ) {
	BLK = 2;
} else
if ( n >= 3408 && n < 3409 ) {
	BLK = 1;
} else
if ( n >= 3409 && n < 3432 ) {
	BLK = 4;
} else
if ( n >= 3432 && n < 3961 ) {
	BLK = 2;
} else
if ( n >= 3961 && n < 4080 ) {
	BLK = 1;
} else
if ( n >= 4080 && n < 4218 ) {
	BLK = 4;
} else
if ( n >= 4218 && n < 6494 ) {
	BLK = 3;
} else
if ( n >= 6494 && n < 7810 ) {
	BLK = 4;
} else
if ( n >= 7810 && n < 16576 ) {
	BLK = 1;
} else
if ( n >= 16576 && n < 17622 ) {
	BLK = 2;
} else
if ( n >= 17622 && n < 17948 ) {
	BLK = 1;
} else
if ( n >= 17948 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
