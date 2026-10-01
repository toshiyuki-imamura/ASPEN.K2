#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Wed Sep 23 21:34:06  2026
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
MAXmem= 16800759808
// capacity of the work area reserved on the GPU
WORK= 2539520
// for double or cuFloatComplex or int64
MAXDIM= 43535
// for float or cuHalfComplex or int32
MAXDIM2= 61568
// for cuDoubleComplex or DD or int128
MAXDIM3= 30784
// for DD-Complex
MAXDIM4= 21767
// for half or int16
MAXDIM5= 87070
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 890
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

if ( n >= 1 && n < 2 ) {
	BLK = 4;
} else
if ( n >= 2 && n < 32 ) {
	BLK = 2;
} else
if ( n >= 32 && n < 33 ) {
	BLK = 4;
} else
if ( n >= 33 && n < 38 ) {
	BLK = 5;
} else
if ( n >= 38 && n < 2593 ) {
	BLK = 0;
} else
if ( n >= 2593 && n < 2680 ) {
	BLK = 2;
} else
if ( n >= 2680 && n < 4623 ) {
	BLK = 3;
} else
if ( n >= 4623 && n < 5815 ) {
	BLK = 1;
} else
if ( n >= 5815 && n < 9185 ) {
	BLK = 4;
} else
if ( n >= 9185 && n < 10439 ) {
	BLK = 1;
} else
if ( n >= 10439 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
