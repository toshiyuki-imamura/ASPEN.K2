#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Wed Aug 05 15:08:27  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 10065 ) {
	BLK = 0;
} else
if ( n >= 10065 && n < 11241 ) {
	BLK = 4;
} else
if ( n >= 11241 && n < 28218 ) {
	BLK = 3;
} else
if ( n >= 28218 && n < 29561 ) {
	BLK = 5;
} else
if ( n >= 29561 && n < 30752 ) {
	BLK = 3;
} else
if ( n >= 30752 && n < 31971 ) {
	BLK = 5;
} else
if ( n >= 31971 && n < 34884 ) {
	BLK = 3;
} else
if ( n >= 34884 && n < 35485 ) {
	BLK = 5;
} else
if ( n >= 35485 && n < 37012 ) {
	BLK = 3;
} else
if ( n >= 37012 && n < 37960 ) {
	BLK = 5;
} else
if ( n >= 37960 && n < 170344 ) {
	BLK = 3;
} else
if ( n >= 170344 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
