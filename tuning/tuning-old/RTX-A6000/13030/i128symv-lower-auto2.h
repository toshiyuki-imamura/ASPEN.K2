#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Mon Jul 27 02:12:57  2026
 Host on pascal.r-ccs27.riken.jp
 Device is RTX-A6000
****************************************/-->
// device name
DEVICE= RTX-A6000
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 50892406784
// capacity of the work area reserved on the GPU
WORK= 4421120
// for double or cuFloatComplex or int64
MAXDIM= 75771
// for float or cuHalfComplex or int32
MAXDIM2= 107156
// for cuDoubleComplex or DD or int128
MAXDIM3= 53578
// for DD-Complex
MAXDIM4= 37885
// for half or int16
MAXDIM5= 151542
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 2;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 1;
} else
if ( n >= 3 && n < 6 ) {
	BLK = 3;
} else
if ( n >= 6 && n < 25 ) {
	BLK = 1;
} else
if ( n >= 25 && n < 29 ) {
	BLK = 2;
} else
if ( n >= 29 && n < 30 ) {
	BLK = 3;
} else
if ( n >= 30 && n < 40 ) {
	BLK = 1;
} else
if ( n >= 40 && n < 41 ) {
	BLK = 3;
} else
if ( n >= 41 && n < 70 ) {
	BLK = 2;
} else
if ( n >= 70 && n < 79 ) {
	BLK = 3;
} else
if ( n >= 79 && n < 83 ) {
	BLK = 1;
} else
if ( n >= 83 && n < 130 ) {
	BLK = 2;
} else
if ( n >= 130 && n < 143 ) {
	BLK = 3;
} else
if ( n >= 143 && n < 144 ) {
	BLK = 1;
} else
if ( n >= 144 && n < 145 ) {
	BLK = 2;
} else
if ( n >= 145 && n < 160 ) {
	BLK = 3;
} else
if ( n >= 160 && n < 174 ) {
	BLK = 2;
} else
if ( n >= 174 && n < 178 ) {
	BLK = 1;
} else
if ( n >= 178 && n < 181 ) {
	BLK = 3;
} else
if ( n >= 181 && n < 183 ) {
	BLK = 2;
} else
if ( n >= 183 && n < 184 ) {
	BLK = 1;
} else
if ( n >= 184 && n < 185 ) {
	BLK = 3;
} else
if ( n >= 185 && n < 186 ) {
	BLK = 2;
} else
if ( n >= 186 && n < 187 ) {
	BLK = 1;
} else
if ( n >= 187 && n < 188 ) {
	BLK = 3;
} else
if ( n >= 188 && n < 261 ) {
	BLK = 2;
} else
if ( n >= 261 && n < 324 ) {
	BLK = 3;
} else
if ( n >= 324 && n < 327 ) {
	BLK = 1;
} else
if ( n >= 327 && n < 331 ) {
	BLK = 2;
} else
if ( n >= 331 && n < 332 ) {
	BLK = 3;
} else
if ( n >= 332 && n < 355 ) {
	BLK = 1;
} else
if ( n >= 355 && n < 361 ) {
	BLK = 2;
} else
if ( n >= 361 && n < 367 ) {
	BLK = 1;
} else
if ( n >= 367 && n < 369 ) {
	BLK = 2;
} else
if ( n >= 369 && n < 382 ) {
	BLK = 3;
} else
if ( n >= 382 && n < 383 ) {
	BLK = 1;
} else
if ( n >= 383 && n < 414 ) {
	BLK = 2;
} else
if ( n >= 414 && n < 419 ) {
	BLK = 3;
} else
if ( n >= 419 && n < 421 ) {
	BLK = 2;
} else
if ( n >= 421 && n < 422 ) {
	BLK = 1;
} else
if ( n >= 422 && n < 488 ) {
	BLK = 3;
} else
if ( n >= 488 && n < 489 ) {
	BLK = 1;
} else
if ( n >= 489 && n < 510 ) {
	BLK = 2;
} else
if ( n >= 510 && n < 931 ) {
	BLK = 3;
} else
if ( n >= 931 && n < 1278 ) {
	BLK = 2;
} else
if ( n >= 1278 && n < 3407 ) {
	BLK = 3;
} else
if ( n >= 3407 && n < 3408 ) {
	BLK = 1;
} else
if ( n >= 3408 && n < 3537 ) {
	BLK = 2;
} else
if ( n >= 3537 && n < 3876 ) {
	BLK = 3;
} else
if ( n >= 3876 && n < 3878 ) {
	BLK = 1;
} else
if ( n >= 3878 && n < 3879 ) {
	BLK = 2;
} else
if ( n >= 3879 && n < 3953 ) {
	BLK = 3;
} else
if ( n >= 3953 && n < 3954 ) {
	BLK = 2;
} else
if ( n >= 3954 && n < 4582 ) {
	BLK = 1;
} else
if ( n >= 4582 && n < 4584 ) {
	BLK = 3;
} else
if ( n >= 4584 && n < 4590 ) {
	BLK = 2;
} else
if ( n >= 4590 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
