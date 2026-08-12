#ifndef KHEMVU_AUTO2_H_INCLUDED
#define KHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVU
 Thu Aug 06 15:33:07  2026
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
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 4091 ) {
	BLK = 0;
} else
if ( n >= 4091 && n < 4131 ) {
	BLK = 1;
} else
if ( n >= 4131 && n < 4159 ) {
	BLK = 5;
} else
if ( n >= 4159 && n < 4170 ) {
	BLK = 0;
} else
if ( n >= 4170 && n < 4195 ) {
	BLK = 1;
} else
if ( n >= 4195 && n < 4231 ) {
	BLK = 5;
} else
if ( n >= 4231 && n < 4324 ) {
	BLK = 1;
} else
if ( n >= 4324 && n < 6300 ) {
	BLK = 5;
} else
if ( n >= 6300 && n < 27056 ) {
	BLK = 4;
} else
if ( n >= 27056 && n < 27850 ) {
	BLK = 2;
} else
if ( n >= 27850 && n < 29128 ) {
	BLK = 4;
} else
if ( n >= 29128 && n < 31089 ) {
	BLK = 2;
} else
if ( n >= 31089 && n < 31626 ) {
	BLK = 4;
} else
if ( n >= 31626 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
