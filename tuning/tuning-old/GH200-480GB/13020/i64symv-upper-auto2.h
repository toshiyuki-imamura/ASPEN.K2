#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Wed Aug 05 22:03:20  2026
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3292 ) {
	BLK = 0;
} else
if ( n >= 3292 && n < 5082 ) {
	BLK = 2;
} else
if ( n >= 5082 && n < 10485 ) {
	BLK = 1;
} else
if ( n >= 10485 && n < 15660 ) {
	BLK = 4;
} else
if ( n >= 15660 && n < 15970 ) {
	BLK = 1;
} else
if ( n >= 15970 && n < 17564 ) {
	BLK = 4;
} else
if ( n >= 17564 && n < 17805 ) {
	BLK = 1;
} else
if ( n >= 17805 && n < 17875 ) {
	BLK = 3;
} else
if ( n >= 17875 && n < 20011 ) {
	BLK = 4;
} else
if ( n >= 20011 && n < 20541 ) {
	BLK = 1;
} else
if ( n >= 20541 && n < 23040 ) {
	BLK = 4;
} else
if ( n >= 23040 && n < 23670 ) {
	BLK = 1;
} else
if ( n >= 23670 && n < 25960 ) {
	BLK = 4;
} else
if ( n >= 25960 && n < 26485 ) {
	BLK = 1;
} else
if ( n >= 26485 && n < 33523 ) {
	BLK = 4;
} else
if ( n >= 33523 && n < 34477 ) {
	BLK = 1;
} else
if ( n >= 34477 && n < 92191 ) {
	BLK = 4;
} else
if ( n >= 92191 && n < 97723 ) {
	BLK = 1;
} else
if ( n >= 97723 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
