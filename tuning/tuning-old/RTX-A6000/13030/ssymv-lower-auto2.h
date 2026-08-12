#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Sun Jul 26 08:44:39  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1986 ) {
	BLK = 0;
} else
if ( n >= 1986 && n < 1987 ) {
	BLK = 2;
} else
if ( n >= 1987 && n < 2009 ) {
	BLK = 1;
} else
if ( n >= 2009 && n < 2011 ) {
	BLK = 0;
} else
if ( n >= 2011 && n < 2012 ) {
	BLK = 2;
} else
if ( n >= 2012 && n < 2029 ) {
	BLK = 1;
} else
if ( n >= 2029 && n < 2030 ) {
	BLK = 3;
} else
if ( n >= 2030 && n < 2070 ) {
	BLK = 0;
} else
if ( n >= 2070 && n < 2212 ) {
	BLK = 1;
} else
if ( n >= 2212 && n < 2213 ) {
	BLK = 0;
} else
if ( n >= 2213 && n < 2217 ) {
	BLK = 3;
} else
if ( n >= 2217 && n < 2267 ) {
	BLK = 1;
} else
if ( n >= 2267 && n < 2268 ) {
	BLK = 3;
} else
if ( n >= 2268 && n < 2269 ) {
	BLK = 2;
} else
if ( n >= 2269 && n < 2273 ) {
	BLK = 1;
} else
if ( n >= 2273 && n < 2274 ) {
	BLK = 0;
} else
if ( n >= 2274 && n < 2275 ) {
	BLK = 2;
} else
if ( n >= 2275 && n < 2286 ) {
	BLK = 3;
} else
if ( n >= 2286 && n < 2291 ) {
	BLK = 1;
} else
if ( n >= 2291 && n < 2292 ) {
	BLK = 2;
} else
if ( n >= 2292 && n < 2293 ) {
	BLK = 3;
} else
if ( n >= 2293 && n < 2468 ) {
	BLK = 1;
} else
if ( n >= 2468 && n < 2469 ) {
	BLK = 3;
} else
if ( n >= 2469 && n < 2470 ) {
	BLK = 2;
} else
if ( n >= 2470 && n < 2476 ) {
	BLK = 1;
} else
if ( n >= 2476 && n < 2477 ) {
	BLK = 2;
} else
if ( n >= 2477 && n < 2478 ) {
	BLK = 3;
} else
if ( n >= 2478 && n < 2487 ) {
	BLK = 1;
} else
if ( n >= 2487 && n < 2488 ) {
	BLK = 2;
} else
if ( n >= 2488 && n < 2504 ) {
	BLK = 3;
} else
if ( n >= 2504 && n < 2505 ) {
	BLK = 2;
} else
if ( n >= 2505 && n < 2546 ) {
	BLK = 1;
} else
if ( n >= 2546 && n < 2547 ) {
	BLK = 3;
} else
if ( n >= 2547 && n < 2548 ) {
	BLK = 2;
} else
if ( n >= 2548 && n < 2623 ) {
	BLK = 1;
} else
if ( n >= 2623 && n < 2624 ) {
	BLK = 2;
} else
if ( n >= 2624 && n < 2633 ) {
	BLK = 3;
} else
if ( n >= 2633 && n < 2683 ) {
	BLK = 1;
} else
if ( n >= 2683 && n < 2684 ) {
	BLK = 3;
} else
if ( n >= 2684 && n < 2685 ) {
	BLK = 2;
} else
if ( n >= 2685 && n < 16391 ) {
	BLK = 1;
} else
if ( n >= 16391 && n < 18506 ) {
	BLK = 3;
} else
if ( n >= 18506 && n < 19252 ) {
	BLK = 1;
} else
if ( n >= 19252 && n < 22467 ) {
	BLK = 3;
} else
if ( n >= 22467 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
