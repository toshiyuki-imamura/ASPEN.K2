#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Wed Jul 22 09:27:23  2026
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

if ( n >= 1 && n < 1949 ) {
	BLK = 0;
} else
if ( n >= 1949 && n < 1987 ) {
	BLK = 2;
} else
if ( n >= 1987 && n < 1988 ) {
	BLK = 3;
} else
if ( n >= 1988 && n < 2010 ) {
	BLK = 0;
} else
if ( n >= 2010 && n < 2012 ) {
	BLK = 2;
} else
if ( n >= 2012 && n < 2019 ) {
	BLK = 3;
} else
if ( n >= 2019 && n < 2021 ) {
	BLK = 2;
} else
if ( n >= 2021 && n < 2022 ) {
	BLK = 0;
} else
if ( n >= 2022 && n < 2023 ) {
	BLK = 3;
} else
if ( n >= 2023 && n < 2032 ) {
	BLK = 2;
} else
if ( n >= 2032 && n < 2047 ) {
	BLK = 3;
} else
if ( n >= 2047 && n < 2051 ) {
	BLK = 2;
} else
if ( n >= 2051 && n < 2052 ) {
	BLK = 0;
} else
if ( n >= 2052 && n < 2053 ) {
	BLK = 1;
} else
if ( n >= 2053 && n < 2085 ) {
	BLK = 3;
} else
if ( n >= 2085 && n < 2140 ) {
	BLK = 2;
} else
if ( n >= 2140 && n < 2141 ) {
	BLK = 0;
} else
if ( n >= 2141 && n < 2563 ) {
	BLK = 3;
} else
if ( n >= 2563 && n < 2565 ) {
	BLK = 2;
} else
if ( n >= 2565 && n < 2566 ) {
	BLK = 1;
} else
if ( n >= 2566 && n < 2567 ) {
	BLK = 3;
} else
if ( n >= 2567 && n < 2588 ) {
	BLK = 2;
} else
if ( n >= 2588 && n < 2589 ) {
	BLK = 1;
} else
if ( n >= 2589 && n < 2594 ) {
	BLK = 3;
} else
if ( n >= 2594 && n < 3257 ) {
	BLK = 2;
} else
if ( n >= 3257 && n < 6356 ) {
	BLK = 1;
} else
if ( n >= 6356 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
