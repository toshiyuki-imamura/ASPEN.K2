#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Wed Jul 29 15:22:59  2026
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
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 16 ) {
	BLK = 4;
} else
if ( n >= 16 && n < 21 ) {
	BLK = 2;
} else
if ( n >= 21 && n < 372 ) {
	BLK = 3;
} else
if ( n >= 372 && n < 383 ) {
	BLK = 5;
} else
if ( n >= 383 && n < 384 ) {
	BLK = 4;
} else
if ( n >= 384 && n < 406 ) {
	BLK = 3;
} else
if ( n >= 406 && n < 862 ) {
	BLK = 5;
} else
if ( n >= 862 && n < 863 ) {
	BLK = 3;
} else
if ( n >= 863 && n < 1119 ) {
	BLK = 4;
} else
if ( n >= 1119 && n < 1997 ) {
	BLK = 3;
} else
if ( n >= 1997 && n < 2117 ) {
	BLK = 4;
} else
if ( n >= 2117 && n < 2118 ) {
	BLK = 3;
} else
if ( n >= 2118 && n < 2119 ) {
	BLK = 1;
} else
if ( n >= 2119 && n < 2125 ) {
	BLK = 4;
} else
if ( n >= 2125 && n < 2126 ) {
	BLK = 3;
} else
if ( n >= 2126 && n < 2127 ) {
	BLK = 1;
} else
if ( n >= 2127 && n < 2169 ) {
	BLK = 4;
} else
if ( n >= 2169 && n < 2206 ) {
	BLK = 3;
} else
if ( n >= 2206 && n < 2255 ) {
	BLK = 1;
} else
if ( n >= 2255 && n < 2256 ) {
	BLK = 4;
} else
if ( n >= 2256 && n < 2258 ) {
	BLK = 3;
} else
if ( n >= 2258 && n < 2259 ) {
	BLK = 1;
} else
if ( n >= 2259 && n < 2260 ) {
	BLK = 4;
} else
if ( n >= 2260 && n < 2262 ) {
	BLK = 3;
} else
if ( n >= 2262 && n < 2265 ) {
	BLK = 1;
} else
if ( n >= 2265 && n < 2269 ) {
	BLK = 3;
} else
if ( n >= 2269 && n < 2272 ) {
	BLK = 4;
} else
if ( n >= 2272 && n < 2287 ) {
	BLK = 3;
} else
if ( n >= 2287 && n < 2289 ) {
	BLK = 1;
} else
if ( n >= 2289 && n < 2290 ) {
	BLK = 4;
} else
if ( n >= 2290 && n < 2294 ) {
	BLK = 3;
} else
if ( n >= 2294 && n < 2295 ) {
	BLK = 1;
} else
if ( n >= 2295 && n < 2298 ) {
	BLK = 4;
} else
if ( n >= 2298 && n < 2303 ) {
	BLK = 3;
} else
if ( n >= 2303 && n < 2304 ) {
	BLK = 4;
} else
if ( n >= 2304 && n < 11872 ) {
	BLK = 1;
} else
if ( n >= 11872 && n < 12290 ) {
	BLK = 2;
} else
if ( n >= 12290 && n < 14878 ) {
	BLK = 1;
} else
if ( n >= 14878 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
