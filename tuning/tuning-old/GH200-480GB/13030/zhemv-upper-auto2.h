#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Wed Sep 30 12:25:38  2026
 Host on qc-gh200-02.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 102123945984
// capacity of the work area reserved on the GPU
WORK= 8140288
// for double or cuFloatComplex or int64
MAXDIM= 107335
// for float or cuHalfComplex or int32
MAXDIM2= 151794
// for cuDoubleComplex or DD or int128
MAXDIM3= 75897
// for DD-Complex
MAXDIM4= 53667
// for half or int16
MAXDIM5= 214670
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
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

if ( n >= 1 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 12 ) {
	BLK = 2;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 4;
} else
if ( n >= 13 && n < 16 ) {
	BLK = 5;
} else
if ( n >= 16 && n < 17 ) {
	BLK = 3;
} else
if ( n >= 17 && n < 24 ) {
	BLK = 2;
} else
if ( n >= 24 && n < 34 ) {
	BLK = 1;
} else
if ( n >= 34 && n < 898 ) {
	BLK = 4;
} else
if ( n >= 898 && n < 949 ) {
	BLK = 2;
} else
if ( n >= 949 && n < 952 ) {
	BLK = 1;
} else
if ( n >= 952 && n < 3960 ) {
	BLK = 2;
} else
if ( n >= 3960 && n < 5417 ) {
	BLK = 1;
} else
if ( n >= 5417 && n < 8818 ) {
	BLK = 3;
} else
if ( n >= 8818 && n < 19427 ) {
	BLK = 1;
} else
if ( n >= 19427 && n < 22123 ) {
	BLK = 5;
} else
if ( n >= 22123 && n < 22768 ) {
	BLK = 1;
} else
if ( n >= 22768 && n < 23915 ) {
	BLK = 5;
} else
if ( n >= 23915 && n < 24205 ) {
	BLK = 1;
} else
if ( n >= 24205 && n < 25004 ) {
	BLK = 5;
} else
if ( n >= 25004 && n < 25555 ) {
	BLK = 1;
} else
if ( n >= 25555 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
