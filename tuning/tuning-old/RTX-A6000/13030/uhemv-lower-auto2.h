#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Wed Jul 29 10:03:07  2026
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

if ( n >= 1 && n < 95 ) {
	BLK = 1;
} else
if ( n >= 95 && n < 3008 ) {
	BLK = 3;
} else
if ( n >= 3008 && n < 3487 ) {
	BLK = 2;
} else
if ( n >= 3487 && n < 3488 ) {
	BLK = 3;
} else
if ( n >= 3488 && n < 3500 ) {
	BLK = 1;
} else
if ( n >= 3500 && n < 3517 ) {
	BLK = 2;
} else
if ( n >= 3517 && n < 6983 ) {
	BLK = 1;
} else
if ( n >= 6983 && n < 34400 ) {
	BLK = 2;
} else
if ( n >= 34400 && n < 34781 ) {
	BLK = 1;
} else
if ( n >= 34781 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
