#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Wed Aug 05 02:50:06  2026
 Host on qc-gh200-04.cloud.r-ccs.riken.jp
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

if ( n >= 1 && n < 2560 ) {
	BLK = 0;
} else
if ( n >= 2560 && n < 2561 ) {
	BLK = 1;
} else
if ( n >= 2561 && n < 2562 ) {
	BLK = 5;
} else
if ( n >= 2562 && n < 2564 ) {
	BLK = 0;
} else
if ( n >= 2564 && n < 2565 ) {
	BLK = 1;
} else
if ( n >= 2565 && n < 2578 ) {
	BLK = 5;
} else
if ( n >= 2578 && n < 4292 ) {
	BLK = 0;
} else
if ( n >= 4292 && n < 4745 ) {
	BLK = 5;
} else
if ( n >= 4745 && n < 6182 ) {
	BLK = 4;
} else
if ( n >= 6182 && n < 91844 ) {
	BLK = 3;
} else
if ( n >= 91844 && n < 96781 ) {
	BLK = 2;
} else
if ( n >= 96781 && n < 132209 ) {
	BLK = 3;
} else
if ( n >= 132209 && n < 141197 ) {
	BLK = 2;
} else
if ( n >= 141197 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
