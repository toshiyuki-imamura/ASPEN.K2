#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Thu Aug 06 00:02:45  2026
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
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5012 ) {
	BLK = 0;
} else
if ( n >= 5012 && n < 31863 ) {
	BLK = 2;
} else
if ( n >= 31863 && n < 33627 ) {
	BLK = 4;
} else
if ( n >= 33627 && n < 34521 ) {
	BLK = 2;
} else
if ( n >= 34521 && n < 36646 ) {
	BLK = 4;
} else
if ( n >= 36646 && n < 38532 ) {
	BLK = 2;
} else
if ( n >= 38532 && n < 39094 ) {
	BLK = 3;
} else
if ( n >= 39094 && n < 40764 ) {
	BLK = 4;
} else
if ( n >= 40764 && n < 43974 ) {
	BLK = 2;
} else
if ( n >= 43974 && n < 48388 ) {
	BLK = 4;
} else
if ( n >= 48388 && n < 50770 ) {
	BLK = 2;
} else
if ( n >= 50770 && n < 59171 ) {
	BLK = 4;
} else
if ( n >= 59171 && n < 59708 ) {
	BLK = 3;
} else
if ( n >= 59708 && n < 89030 ) {
	BLK = 4;
} else
if ( n >= 89030 && n < 90539 ) {
	BLK = 3;
} else
if ( n >= 90539 && n < 98872 ) {
	BLK = 4;
} else
if ( n >= 98872 && n < 101716 ) {
	BLK = 3;
} else
if ( n >= 101716 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
