#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Wed Sep 30 11:18:40  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 19 ) {
	BLK = 1;
} else
if ( n >= 19 && n < 372 ) {
	BLK = 0;
} else
if ( n >= 372 && n < 384 ) {
	BLK = 4;
} else
if ( n >= 384 && n < 441 ) {
	BLK = 3;
} else
if ( n >= 441 && n < 470 ) {
	BLK = 1;
} else
if ( n >= 470 && n < 480 ) {
	BLK = 4;
} else
if ( n >= 480 && n < 491 ) {
	BLK = 0;
} else
if ( n >= 491 && n < 507 ) {
	BLK = 1;
} else
if ( n >= 507 && n < 511 ) {
	BLK = 4;
} else
if ( n >= 511 && n < 512 ) {
	BLK = 3;
} else
if ( n >= 512 && n < 531 ) {
	BLK = 1;
} else
if ( n >= 531 && n < 976 ) {
	BLK = 3;
} else
if ( n >= 976 && n < 1349 ) {
	BLK = 1;
} else
if ( n >= 1349 && n < 1366 ) {
	BLK = 3;
} else
if ( n >= 1366 && n < 1368 ) {
	BLK = 4;
} else
if ( n >= 1368 && n < 1376 ) {
	BLK = 1;
} else
if ( n >= 1376 && n < 2185 ) {
	BLK = 3;
} else
if ( n >= 2185 && n < 4196 ) {
	BLK = 1;
} else
if ( n >= 4196 && n < 4927 ) {
	BLK = 2;
} else
if ( n >= 4927 && n < 5992 ) {
	BLK = 1;
} else
if ( n >= 5992 && n < 6580 ) {
	BLK = 2;
} else
if ( n >= 6580 && n < 48452 ) {
	BLK = 1;
} else
if ( n >= 48452 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
