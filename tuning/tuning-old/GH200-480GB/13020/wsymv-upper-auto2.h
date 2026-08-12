#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Tue Aug 04 22:46:28  2026
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2288 ) {
	BLK = 0;
} else
if ( n >= 2288 && n < 4713 ) {
	BLK = 2;
} else
if ( n >= 4713 && n < 15745 ) {
	BLK = 1;
} else
if ( n >= 15745 && n < 16063 ) {
	BLK = 3;
} else
if ( n >= 16063 && n < 19774 ) {
	BLK = 1;
} else
if ( n >= 19774 && n < 20804 ) {
	BLK = 3;
} else
if ( n >= 20804 && n < 21662 ) {
	BLK = 1;
} else
if ( n >= 21662 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
