#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Mon Jul 27 19:54:13  2026
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

if ( n >= 1 && n < 1827 ) {
	BLK = 0;
} else
if ( n >= 1827 && n < 1828 ) {
	BLK = 1;
} else
if ( n >= 1828 && n < 1830 ) {
	BLK = 3;
} else
if ( n >= 1830 && n < 1864 ) {
	BLK = 0;
} else
if ( n >= 1864 && n < 2114 ) {
	BLK = 2;
} else
if ( n >= 2114 && n < 2163 ) {
	BLK = 0;
} else
if ( n >= 2163 && n < 2178 ) {
	BLK = 2;
} else
if ( n >= 2178 && n < 2179 ) {
	BLK = 0;
} else
if ( n >= 2179 && n < 2249 ) {
	BLK = 3;
} else
if ( n >= 2249 && n < 2374 ) {
	BLK = 2;
} else
if ( n >= 2374 && n < 2392 ) {
	BLK = 3;
} else
if ( n >= 2392 && n < 2393 ) {
	BLK = 1;
} else
if ( n >= 2393 && n < 2761 ) {
	BLK = 2;
} else
if ( n >= 2761 && n < 2762 ) {
	BLK = 1;
} else
if ( n >= 2762 && n < 3184 ) {
	BLK = 3;
} else
if ( n >= 3184 && n < 3198 ) {
	BLK = 1;
} else
if ( n >= 3198 && n < 3780 ) {
	BLK = 3;
} else
if ( n >= 3780 && n < 3781 ) {
	BLK = 2;
} else
if ( n >= 3781 && n < 3782 ) {
	BLK = 1;
} else
if ( n >= 3782 && n < 5118 ) {
	BLK = 3;
} else
if ( n >= 5118 && n < 11166 ) {
	BLK = 2;
} else
if ( n >= 11166 && n < 11444 ) {
	BLK = 1;
} else
if ( n >= 11444 && n < 11478 ) {
	BLK = 3;
} else
if ( n >= 11478 && n < 11615 ) {
	BLK = 2;
} else
if ( n >= 11615 && n < 11871 ) {
	BLK = 1;
} else
if ( n >= 11871 && n < 11912 ) {
	BLK = 3;
} else
if ( n >= 11912 && n < 12020 ) {
	BLK = 2;
} else
if ( n >= 12020 && n < 12347 ) {
	BLK = 1;
} else
if ( n >= 12347 && n < 12361 ) {
	BLK = 3;
} else
if ( n >= 12361 && n < 12653 ) {
	BLK = 2;
} else
if ( n >= 12653 && n < 26227 ) {
	BLK = 1;
} else
if ( n >= 26227 && n < 29648 ) {
	BLK = 2;
} else
if ( n >= 29648 && n < 30555 ) {
	BLK = 1;
} else
if ( n >= 30555 && n < 31593 ) {
	BLK = 2;
} else
if ( n >= 31593 && n < 32476 ) {
	BLK = 1;
} else
if ( n >= 32476 && n < 36187 ) {
	BLK = 2;
} else
if ( n >= 36187 && n < 38241 ) {
	BLK = 1;
} else
if ( n >= 38241 && n < 44893 ) {
	BLK = 2;
} else
if ( n >= 44893 && n < 46210 ) {
	BLK = 1;
} else
if ( n >= 46210 && n < 48531 ) {
	BLK = 2;
} else
if ( n >= 48531 && n < 50480 ) {
	BLK = 1;
} else
if ( n >= 50480 && n < 59402 ) {
	BLK = 2;
} else
if ( n >= 59402 && n < 61098 ) {
	BLK = 1;
} else
if ( n >= 61098 && n < 68579 ) {
	BLK = 2;
} else
if ( n >= 68579 && n < 76740 ) {
	BLK = 1;
} else
if ( n >= 76740 && n < 78216 ) {
	BLK = 2;
} else
if ( n >= 78216 && n < 80474 ) {
	BLK = 1;
} else
if ( n >= 80474 && n < 89973 ) {
	BLK = 2;
} else
if ( n >= 89973 && n < 94954 ) {
	BLK = 1;
} else
if ( n >= 94954 && n < 101385 ) {
	BLK = 2;
} else
if ( n >= 101385 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
