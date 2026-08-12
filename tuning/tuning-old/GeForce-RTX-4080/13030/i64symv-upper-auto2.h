#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Tue Jul 28 01:53:02  2026
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
MAXmem= 16743747584
// capacity of the work area reserved on the GPU
WORK= 2534400
// for double or cuFloatComplex or int64
MAXDIM= 43461
// for float or cuHalfComplex or int32
MAXDIM2= 61463
// for cuDoubleComplex or DD or int128
MAXDIM3= 30731
// for DD-Complex
MAXDIM4= 21730
// for half or int16
MAXDIM5= 86923
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 10 ) {
	BLK = 0;
} else
if ( n >= 10 && n < 13 ) {
	BLK = 3;
} else
if ( n >= 13 && n < 56 ) {
	BLK = 0;
} else
if ( n >= 56 && n < 58 ) {
	BLK = 3;
} else
if ( n >= 58 && n < 59 ) {
	BLK = 1;
} else
if ( n >= 59 && n < 60 ) {
	BLK = 0;
} else
if ( n >= 60 && n < 129 ) {
	BLK = 3;
} else
if ( n >= 129 && n < 139 ) {
	BLK = 0;
} else
if ( n >= 139 && n < 142 ) {
	BLK = 1;
} else
if ( n >= 142 && n < 148 ) {
	BLK = 3;
} else
if ( n >= 148 && n < 156 ) {
	BLK = 0;
} else
if ( n >= 156 && n < 157 ) {
	BLK = 2;
} else
if ( n >= 157 && n < 159 ) {
	BLK = 3;
} else
if ( n >= 159 && n < 259 ) {
	BLK = 0;
} else
if ( n >= 259 && n < 260 ) {
	BLK = 3;
} else
if ( n >= 260 && n < 261 ) {
	BLK = 2;
} else
if ( n >= 261 && n < 270 ) {
	BLK = 0;
} else
if ( n >= 270 && n < 271 ) {
	BLK = 3;
} else
if ( n >= 271 && n < 272 ) {
	BLK = 1;
} else
if ( n >= 272 && n < 409 ) {
	BLK = 0;
} else
if ( n >= 409 && n < 410 ) {
	BLK = 1;
} else
if ( n >= 410 && n < 746 ) {
	BLK = 3;
} else
if ( n >= 746 && n < 1830 ) {
	BLK = 0;
} else
if ( n >= 1830 && n < 1831 ) {
	BLK = 1;
} else
if ( n >= 1831 && n < 1832 ) {
	BLK = 3;
} else
if ( n >= 1832 && n < 1918 ) {
	BLK = 0;
} else
if ( n >= 1918 && n < 1919 ) {
	BLK = 3;
} else
if ( n >= 1919 && n < 1920 ) {
	BLK = 1;
} else
if ( n >= 1920 && n < 1935 ) {
	BLK = 0;
} else
if ( n >= 1935 && n < 1937 ) {
	BLK = 3;
} else
if ( n >= 1937 && n < 1938 ) {
	BLK = 1;
} else
if ( n >= 1938 && n < 1969 ) {
	BLK = 0;
} else
if ( n >= 1969 && n < 1970 ) {
	BLK = 1;
} else
if ( n >= 1970 && n < 1985 ) {
	BLK = 3;
} else
if ( n >= 1985 && n < 2047 ) {
	BLK = 0;
} else
if ( n >= 2047 && n < 2491 ) {
	BLK = 1;
} else
if ( n >= 2491 && n < 2492 ) {
	BLK = 2;
} else
if ( n >= 2492 && n < 2534 ) {
	BLK = 0;
} else
if ( n >= 2534 && n < 2628 ) {
	BLK = 1;
} else
if ( n >= 2628 && n < 2629 ) {
	BLK = 2;
} else
if ( n >= 2629 && n < 2804 ) {
	BLK = 0;
} else
if ( n >= 2804 && n < 2821 ) {
	BLK = 1;
} else
if ( n >= 2821 && n < 2822 ) {
	BLK = 2;
} else
if ( n >= 2822 && n < 2836 ) {
	BLK = 0;
} else
if ( n >= 2836 && n < 10715 ) {
	BLK = 1;
} else
if ( n >= 10715 && n < 36668 ) {
	BLK = 2;
} else
if ( n >= 36668 && n < 37290 ) {
	BLK = 3;
} else
if ( n >= 37290 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
