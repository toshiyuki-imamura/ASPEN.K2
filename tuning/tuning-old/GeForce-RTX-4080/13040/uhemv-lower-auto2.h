#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Thu Sep 24 18:07:24  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 4 ) {
	BLK = 4;
} else
if ( n >= 4 && n < 6 ) {
	BLK = 3;
} else
if ( n >= 6 && n < 20 ) {
	BLK = 1;
} else
if ( n >= 20 && n < 620 ) {
	BLK = 5;
} else
if ( n >= 620 && n < 2398 ) {
	BLK = 4;
} else
if ( n >= 2398 && n < 3022 ) {
	BLK = 2;
} else
if ( n >= 3022 && n < 3171 ) {
	BLK = 3;
} else
if ( n >= 3171 && n < 3206 ) {
	BLK = 1;
} else
if ( n >= 3206 && n < 3214 ) {
	BLK = 2;
} else
if ( n >= 3214 && n < 3215 ) {
	BLK = 1;
} else
if ( n >= 3215 && n < 3216 ) {
	BLK = 3;
} else
if ( n >= 3216 && n < 3234 ) {
	BLK = 2;
} else
if ( n >= 3234 && n < 3237 ) {
	BLK = 3;
} else
if ( n >= 3237 && n < 3238 ) {
	BLK = 1;
} else
if ( n >= 3238 && n < 3241 ) {
	BLK = 2;
} else
if ( n >= 3241 && n < 3251 ) {
	BLK = 3;
} else
if ( n >= 3251 && n < 3265 ) {
	BLK = 1;
} else
if ( n >= 3265 && n < 3266 ) {
	BLK = 2;
} else
if ( n >= 3266 && n < 3269 ) {
	BLK = 3;
} else
if ( n >= 3269 && n < 3275 ) {
	BLK = 1;
} else
if ( n >= 3275 && n < 3276 ) {
	BLK = 3;
} else
if ( n >= 3276 && n < 3281 ) {
	BLK = 2;
} else
if ( n >= 3281 && n < 3282 ) {
	BLK = 3;
} else
if ( n >= 3282 && n < 3290 ) {
	BLK = 1;
} else
if ( n >= 3290 && n < 3359 ) {
	BLK = 2;
} else
if ( n >= 3359 && n < 3373 ) {
	BLK = 1;
} else
if ( n >= 3373 && n < 3374 ) {
	BLK = 3;
} else
if ( n >= 3374 && n < 3381 ) {
	BLK = 2;
} else
if ( n >= 3381 && n < 3391 ) {
	BLK = 1;
} else
if ( n >= 3391 && n < 3395 ) {
	BLK = 3;
} else
if ( n >= 3395 && n < 3396 ) {
	BLK = 2;
} else
if ( n >= 3396 && n < 3400 ) {
	BLK = 1;
} else
if ( n >= 3400 && n < 3405 ) {
	BLK = 3;
} else
if ( n >= 3405 && n < 3408 ) {
	BLK = 2;
} else
if ( n >= 3408 && n < 3420 ) {
	BLK = 1;
} else
if ( n >= 3420 && n < 3421 ) {
	BLK = 2;
} else
if ( n >= 3421 && n < 3422 ) {
	BLK = 3;
} else
if ( n >= 3422 && n < 3437 ) {
	BLK = 1;
} else
if ( n >= 3437 && n < 3438 ) {
	BLK = 3;
} else
if ( n >= 3438 && n < 3439 ) {
	BLK = 2;
} else
if ( n >= 3439 && n < 3442 ) {
	BLK = 1;
} else
if ( n >= 3442 && n < 3444 ) {
	BLK = 3;
} else
if ( n >= 3444 && n < 3452 ) {
	BLK = 2;
} else
if ( n >= 3452 && n < 3523 ) {
	BLK = 3;
} else
if ( n >= 3523 && n < 3524 ) {
	BLK = 1;
} else
if ( n >= 3524 && n < 3525 ) {
	BLK = 2;
} else
if ( n >= 3525 && n < 4147 ) {
	BLK = 3;
} else
if ( n >= 4147 && n < 4625 ) {
	BLK = 1;
} else
if ( n >= 4625 && n < 4629 ) {
	BLK = 4;
} else
if ( n >= 4629 && n < 4640 ) {
	BLK = 3;
} else
if ( n >= 4640 && n < 4671 ) {
	BLK = 2;
} else
if ( n >= 4671 && n < 4681 ) {
	BLK = 3;
} else
if ( n >= 4681 && n < 4724 ) {
	BLK = 4;
} else
if ( n >= 4724 && n < 5070 ) {
	BLK = 2;
} else
if ( n >= 5070 && n < 5863 ) {
	BLK = 3;
} else
if ( n >= 5863 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
