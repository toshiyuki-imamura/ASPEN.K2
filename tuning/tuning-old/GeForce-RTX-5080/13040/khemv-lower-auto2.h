#ifndef KHEMVL_AUTO2_H_INCLUDED
#define KHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVL
 Mon Sep 28 00:41:13  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 1200
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

if ( n >= 1 && n < 243 ) {
	BLK = 0;
} else
if ( n >= 243 && n < 248 ) {
	BLK = 4;
} else
if ( n >= 248 && n < 262 ) {
	BLK = 2;
} else
if ( n >= 262 && n < 264 ) {
	BLK = 4;
} else
if ( n >= 264 && n < 296 ) {
	BLK = 0;
} else
if ( n >= 296 && n < 299 ) {
	BLK = 4;
} else
if ( n >= 299 && n < 300 ) {
	BLK = 2;
} else
if ( n >= 300 && n < 364 ) {
	BLK = 0;
} else
if ( n >= 364 && n < 365 ) {
	BLK = 4;
} else
if ( n >= 365 && n < 367 ) {
	BLK = 2;
} else
if ( n >= 367 && n < 1961 ) {
	BLK = 0;
} else
if ( n >= 1961 && n < 1966 ) {
	BLK = 2;
} else
if ( n >= 1966 && n < 2302 ) {
	BLK = 0;
} else
if ( n >= 2302 && n < 2303 ) {
	BLK = 5;
} else
if ( n >= 2303 && n < 2304 ) {
	BLK = 1;
} else
if ( n >= 2304 && n < 2305 ) {
	BLK = 0;
} else
if ( n >= 2305 && n < 2310 ) {
	BLK = 5;
} else
if ( n >= 2310 && n < 2311 ) {
	BLK = 0;
} else
if ( n >= 2311 && n < 2313 ) {
	BLK = 1;
} else
if ( n >= 2313 && n < 2314 ) {
	BLK = 5;
} else
if ( n >= 2314 && n < 2347 ) {
	BLK = 0;
} else
if ( n >= 2347 && n < 2348 ) {
	BLK = 5;
} else
if ( n >= 2348 && n < 2349 ) {
	BLK = 1;
} else
if ( n >= 2349 && n < 4022 ) {
	BLK = 0;
} else
if ( n >= 4022 && n < 8193 ) {
	BLK = 1;
} else
if ( n >= 8193 && n < 9117 ) {
	BLK = 5;
} else
if ( n >= 9117 && n < 12159 ) {
	BLK = 2;
} else
if ( n >= 12159 && n < 16704 ) {
	BLK = 4;
} else
if ( n >= 16704 && n < 16894 ) {
	BLK = 2;
} else
if ( n >= 16894 && n < 20144 ) {
	BLK = 3;
} else
if ( n >= 20144 && n < 20612 ) {
	BLK = 2;
} else
if ( n >= 20612 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
