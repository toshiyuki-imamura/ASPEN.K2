#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Wed Aug 05 12:01:13  2026
 Host on qc-gh200-01.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 101997334528
// capacity of the work area reserved on the GPU
WORK= 8136960
// for double or cuFloatComplex or int64
MAXDIM= 107268
// for float or cuHalfComplex or int32
MAXDIM2= 151700
// for cuDoubleComplex or DD or int128
MAXDIM3= 75850
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214537
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 900
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

if ( n >= 1 && n < 2148 ) {
	BLK = 0;
} else
if ( n >= 2148 && n < 2491 ) {
	BLK = 5;
} else
if ( n >= 2491 && n < 2769 ) {
	BLK = 1;
} else
if ( n >= 2769 && n < 3479 ) {
	BLK = 5;
} else
if ( n >= 3479 && n < 3521 ) {
	BLK = 2;
} else
if ( n >= 3521 && n < 3528 ) {
	BLK = 5;
} else
if ( n >= 3528 && n < 3551 ) {
	BLK = 3;
} else
if ( n >= 3551 && n < 3556 ) {
	BLK = 5;
} else
if ( n >= 3556 && n < 5084 ) {
	BLK = 2;
} else
if ( n >= 5084 && n < 15035 ) {
	BLK = 4;
} else
if ( n >= 15035 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
