#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Wed Aug 05 19:46:32  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 3;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 5;
} else
if ( n >= 3 && n < 6 ) {
	BLK = 1;
} else
if ( n >= 6 && n < 356 ) {
	BLK = 3;
} else
if ( n >= 356 && n < 382 ) {
	BLK = 5;
} else
if ( n >= 382 && n < 383 ) {
	BLK = 4;
} else
if ( n >= 383 && n < 384 ) {
	BLK = 3;
} else
if ( n >= 384 && n < 388 ) {
	BLK = 5;
} else
if ( n >= 388 && n < 389 ) {
	BLK = 4;
} else
if ( n >= 389 && n < 416 ) {
	BLK = 3;
} else
if ( n >= 416 && n < 417 ) {
	BLK = 4;
} else
if ( n >= 417 && n < 418 ) {
	BLK = 2;
} else
if ( n >= 418 && n < 420 ) {
	BLK = 3;
} else
if ( n >= 420 && n < 421 ) {
	BLK = 4;
} else
if ( n >= 421 && n < 422 ) {
	BLK = 5;
} else
if ( n >= 422 && n < 444 ) {
	BLK = 3;
} else
if ( n >= 444 && n < 445 ) {
	BLK = 2;
} else
if ( n >= 445 && n < 447 ) {
	BLK = 5;
} else
if ( n >= 447 && n < 1720 ) {
	BLK = 3;
} else
if ( n >= 1720 && n < 6862 ) {
	BLK = 2;
} else
if ( n >= 6862 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
