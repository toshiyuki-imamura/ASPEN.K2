#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Sat Jul 25 05:41:33  2026
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

if ( n >= 1 && n < 2 ) {
	BLK = 3;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 1;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 2;
} else
if ( n >= 4 && n < 9 ) {
	BLK = 3;
} else
if ( n >= 9 && n < 13 ) {
	BLK = 0;
} else
if ( n >= 13 && n < 16 ) {
	BLK = 3;
} else
if ( n >= 16 && n < 4289 ) {
	BLK = 2;
} else
if ( n >= 4289 && n < 11551 ) {
	BLK = 1;
} else
if ( n >= 11551 && n < 15019 ) {
	BLK = 3;
} else
if ( n >= 15019 && n < 15407 ) {
	BLK = 1;
} else
if ( n >= 15407 && n < 19191 ) {
	BLK = 3;
} else
if ( n >= 19191 && n < 19498 ) {
	BLK = 1;
} else
if ( n >= 19498 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
