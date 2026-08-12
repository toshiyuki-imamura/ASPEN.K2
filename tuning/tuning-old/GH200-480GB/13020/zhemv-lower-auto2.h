#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Thu Aug 06 18:31:09  2026
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

if ( n >= 1 && n < 13 ) {
	BLK = 2;
} else
if ( n >= 13 && n < 20 ) {
	BLK = 4;
} else
if ( n >= 20 && n < 25 ) {
	BLK = 5;
} else
if ( n >= 25 && n < 42 ) {
	BLK = 2;
} else
if ( n >= 42 && n < 49 ) {
	BLK = 4;
} else
if ( n >= 49 && n < 50 ) {
	BLK = 2;
} else
if ( n >= 50 && n < 51 ) {
	BLK = 3;
} else
if ( n >= 51 && n < 53 ) {
	BLK = 4;
} else
if ( n >= 53 && n < 54 ) {
	BLK = 2;
} else
if ( n >= 54 && n < 55 ) {
	BLK = 3;
} else
if ( n >= 55 && n < 56 ) {
	BLK = 4;
} else
if ( n >= 56 && n < 57 ) {
	BLK = 2;
} else
if ( n >= 57 && n < 58 ) {
	BLK = 3;
} else
if ( n >= 58 && n < 60 ) {
	BLK = 4;
} else
if ( n >= 60 && n < 196 ) {
	BLK = 2;
} else
if ( n >= 196 && n < 507 ) {
	BLK = 3;
} else
if ( n >= 507 && n < 508 ) {
	BLK = 4;
} else
if ( n >= 508 && n < 573 ) {
	BLK = 2;
} else
if ( n >= 573 && n < 600 ) {
	BLK = 3;
} else
if ( n >= 600 && n < 640 ) {
	BLK = 4;
} else
if ( n >= 640 && n < 662 ) {
	BLK = 3;
} else
if ( n >= 662 && n < 670 ) {
	BLK = 4;
} else
if ( n >= 670 && n < 671 ) {
	BLK = 2;
} else
if ( n >= 671 && n < 714 ) {
	BLK = 3;
} else
if ( n >= 714 && n < 717 ) {
	BLK = 4;
} else
if ( n >= 717 && n < 768 ) {
	BLK = 3;
} else
if ( n >= 768 && n < 769 ) {
	BLK = 4;
} else
if ( n >= 769 && n < 823 ) {
	BLK = 2;
} else
if ( n >= 823 && n < 2369 ) {
	BLK = 4;
} else
if ( n >= 2369 && n < 4954 ) {
	BLK = 2;
} else
if ( n >= 4954 && n < 5484 ) {
	BLK = 5;
} else
if ( n >= 5484 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
