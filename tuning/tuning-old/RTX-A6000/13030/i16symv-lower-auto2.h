#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Tue Jul 28 03:06:29  2026
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

if ( n >= 1 && n < 2049 ) {
	BLK = 0;
} else
if ( n >= 2049 && n < 2490 ) {
	BLK = 3;
} else
if ( n >= 2490 && n < 2502 ) {
	BLK = 0;
} else
if ( n >= 2502 && n < 2527 ) {
	BLK = 3;
} else
if ( n >= 2527 && n < 4224 ) {
	BLK = 1;
} else
if ( n >= 4224 && n < 5550 ) {
	BLK = 3;
} else
if ( n >= 5550 && n < 41328 ) {
	BLK = 1;
} else
if ( n >= 41328 && n < 51335 ) {
	BLK = 2;
} else
if ( n >= 51335 && n < 54537 ) {
	BLK = 3;
} else
if ( n >= 54537 && n < 60118 ) {
	BLK = 2;
} else
if ( n >= 60118 && n < 71620 ) {
	BLK = 3;
} else
if ( n >= 71620 && n < 76984 ) {
	BLK = 2;
} else
if ( n >= 76984 && n < 80288 ) {
	BLK = 3;
} else
if ( n >= 80288 && n < 86624 ) {
	BLK = 2;
} else
if ( n >= 86624 && n < 95238 ) {
	BLK = 3;
} else
if ( n >= 95238 && n < 106440 ) {
	BLK = 2;
} else
if ( n >= 106440 && n < 107864 ) {
	BLK = 3;
} else
if ( n >= 107864 && n < 115965 ) {
	BLK = 2;
} else
if ( n >= 115965 && n < 122889 ) {
	BLK = 3;
} else
if ( n >= 122889 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
