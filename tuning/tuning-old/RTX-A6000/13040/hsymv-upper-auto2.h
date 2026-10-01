#ifndef HSYMVU_AUTO2_H_INCLUDED
#define HSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVU
 Sat Sep 26 09:31:44  2026
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
MAXmem= 50949160960
// capacity of the work area reserved on the GPU
WORK= 4423680
// for double or cuFloatComplex or int64
MAXDIM= 75813
// for float or cuHalfComplex or int32
MAXDIM2= 107216
// for cuDoubleComplex or DD or int128
MAXDIM3= 53608
// for DD-Complex
MAXDIM4= 37906
// for half or int16
MAXDIM5= 151627
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2212 ) {
	BLK = 0;
} else
if ( n >= 2212 && n < 2213 ) {
	BLK = 5;
} else
if ( n >= 2213 && n < 2219 ) {
	BLK = 3;
} else
if ( n >= 2219 && n < 2245 ) {
	BLK = 0;
} else
if ( n >= 2245 && n < 2246 ) {
	BLK = 3;
} else
if ( n >= 2246 && n < 2247 ) {
	BLK = 5;
} else
if ( n >= 2247 && n < 2286 ) {
	BLK = 0;
} else
if ( n >= 2286 && n < 2287 ) {
	BLK = 3;
} else
if ( n >= 2287 && n < 2289 ) {
	BLK = 5;
} else
if ( n >= 2289 && n < 2295 ) {
	BLK = 0;
} else
if ( n >= 2295 && n < 2298 ) {
	BLK = 5;
} else
if ( n >= 2298 && n < 2299 ) {
	BLK = 3;
} else
if ( n >= 2299 && n < 2301 ) {
	BLK = 0;
} else
if ( n >= 2301 && n < 2304 ) {
	BLK = 5;
} else
if ( n >= 2304 && n < 2324 ) {
	BLK = 3;
} else
if ( n >= 2324 && n < 2325 ) {
	BLK = 0;
} else
if ( n >= 2325 && n < 2334 ) {
	BLK = 5;
} else
if ( n >= 2334 && n < 2342 ) {
	BLK = 0;
} else
if ( n >= 2342 && n < 2343 ) {
	BLK = 5;
} else
if ( n >= 2343 && n < 2346 ) {
	BLK = 3;
} else
if ( n >= 2346 && n < 2352 ) {
	BLK = 0;
} else
if ( n >= 2352 && n < 2353 ) {
	BLK = 3;
} else
if ( n >= 2353 && n < 2354 ) {
	BLK = 5;
} else
if ( n >= 2354 && n < 2359 ) {
	BLK = 0;
} else
if ( n >= 2359 && n < 2360 ) {
	BLK = 5;
} else
if ( n >= 2360 && n < 2363 ) {
	BLK = 3;
} else
if ( n >= 2363 && n < 2375 ) {
	BLK = 0;
} else
if ( n >= 2375 && n < 2386 ) {
	BLK = 3;
} else
if ( n >= 2386 && n < 2388 ) {
	BLK = 0;
} else
if ( n >= 2388 && n < 2389 ) {
	BLK = 5;
} else
if ( n >= 2389 && n < 2400 ) {
	BLK = 3;
} else
if ( n >= 2400 && n < 2415 ) {
	BLK = 5;
} else
if ( n >= 2415 && n < 2424 ) {
	BLK = 0;
} else
if ( n >= 2424 && n < 2425 ) {
	BLK = 3;
} else
if ( n >= 2425 && n < 2430 ) {
	BLK = 5;
} else
if ( n >= 2430 && n < 2437 ) {
	BLK = 0;
} else
if ( n >= 2437 && n < 2441 ) {
	BLK = 3;
} else
if ( n >= 2441 && n < 2478 ) {
	BLK = 0;
} else
if ( n >= 2478 && n < 2479 ) {
	BLK = 5;
} else
if ( n >= 2479 && n < 2483 ) {
	BLK = 3;
} else
if ( n >= 2483 && n < 2862 ) {
	BLK = 0;
} else
if ( n >= 2862 && n < 6218 ) {
	BLK = 3;
} else
if ( n >= 6218 && n < 37413 ) {
	BLK = 2;
} else
if ( n >= 37413 && n < 41651 ) {
	BLK = 4;
} else
if ( n >= 41651 && n < 43589 ) {
	BLK = 2;
} else
if ( n >= 43589 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
