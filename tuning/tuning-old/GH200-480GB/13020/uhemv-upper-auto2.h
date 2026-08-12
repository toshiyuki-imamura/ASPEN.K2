#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Thu Aug 06 10:04:47  2026
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

if ( n >= 1 && n < 486 ) {
	BLK = 0;
} else
if ( n >= 486 && n < 1580 ) {
	BLK = 4;
} else
if ( n >= 1580 && n < 3385 ) {
	BLK = 2;
} else
if ( n >= 3385 && n < 4301 ) {
	BLK = 1;
} else
if ( n >= 4301 && n < 4388 ) {
	BLK = 3;
} else
if ( n >= 4388 && n < 4390 ) {
	BLK = 1;
} else
if ( n >= 4390 && n < 4392 ) {
	BLK = 2;
} else
if ( n >= 4392 && n < 4479 ) {
	BLK = 3;
} else
if ( n >= 4479 && n < 4553 ) {
	BLK = 1;
} else
if ( n >= 4553 && n < 4560 ) {
	BLK = 2;
} else
if ( n >= 4560 && n < 4598 ) {
	BLK = 3;
} else
if ( n >= 4598 && n < 4732 ) {
	BLK = 1;
} else
if ( n >= 4732 && n < 4736 ) {
	BLK = 3;
} else
if ( n >= 4736 && n < 4756 ) {
	BLK = 2;
} else
if ( n >= 4756 && n < 6285 ) {
	BLK = 1;
} else
if ( n >= 6285 && n < 6619 ) {
	BLK = 3;
} else
if ( n >= 6619 && n < 48248 ) {
	BLK = 1;
} else
if ( n >= 48248 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
