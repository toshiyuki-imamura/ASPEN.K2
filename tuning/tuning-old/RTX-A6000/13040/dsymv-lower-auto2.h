#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Sun Sep 27 12:28:06  2026
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
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 7 ) {
	BLK = 0;
} else
if ( n >= 7 && n < 10 ) {
	BLK = 5;
} else
if ( n >= 10 && n < 18 ) {
	BLK = 1;
} else
if ( n >= 18 && n < 30 ) {
	BLK = 3;
} else
if ( n >= 30 && n < 42 ) {
	BLK = 2;
} else
if ( n >= 42 && n < 192 ) {
	BLK = 5;
} else
if ( n >= 192 && n < 1577 ) {
	BLK = 0;
} else
if ( n >= 1577 && n < 2272 ) {
	BLK = 3;
} else
if ( n >= 2272 && n < 7406 ) {
	BLK = 2;
} else
if ( n >= 7406 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
