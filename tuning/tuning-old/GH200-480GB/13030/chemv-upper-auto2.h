#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Wed Sep 30 13:49:35  2026
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2916 ) {
	BLK = 0;
} else
if ( n >= 2916 && n < 3505 ) {
	BLK = 3;
} else
if ( n >= 3505 && n < 4158 ) {
	BLK = 0;
} else
if ( n >= 4158 && n < 4165 ) {
	BLK = 3;
} else
if ( n >= 4165 && n < 4171 ) {
	BLK = 1;
} else
if ( n >= 4171 && n < 4176 ) {
	BLK = 0;
} else
if ( n >= 4176 && n < 4181 ) {
	BLK = 3;
} else
if ( n >= 4181 && n < 7761 ) {
	BLK = 1;
} else
if ( n >= 7761 && n < 17157 ) {
	BLK = 2;
} else
if ( n >= 17157 && n < 17521 ) {
	BLK = 1;
} else
if ( n >= 17521 && n < 18709 ) {
	BLK = 2;
} else
if ( n >= 18709 && n < 19392 ) {
	BLK = 1;
} else
if ( n >= 19392 && n < 19972 ) {
	BLK = 2;
} else
if ( n >= 19972 && n < 20250 ) {
	BLK = 1;
} else
if ( n >= 20250 && n < 20513 ) {
	BLK = 2;
} else
if ( n >= 20513 && n < 20864 ) {
	BLK = 1;
} else
if ( n >= 20864 && n < 21587 ) {
	BLK = 2;
} else
if ( n >= 21587 && n < 21978 ) {
	BLK = 1;
} else
if ( n >= 21978 && n < 22542 ) {
	BLK = 2;
} else
if ( n >= 22542 && n < 23451 ) {
	BLK = 1;
} else
if ( n >= 23451 && n < 24292 ) {
	BLK = 2;
} else
if ( n >= 24292 && n < 24790 ) {
	BLK = 1;
} else
if ( n >= 24790 && n < 25617 ) {
	BLK = 2;
} else
if ( n >= 25617 && n < 27845 ) {
	BLK = 1;
} else
if ( n >= 27845 && n < 29351 ) {
	BLK = 2;
} else
if ( n >= 29351 && n < 34439 ) {
	BLK = 1;
} else
if ( n >= 34439 && n < 35503 ) {
	BLK = 2;
} else
if ( n >= 35503 && n < 37471 ) {
	BLK = 1;
} else
if ( n >= 37471 && n < 37805 ) {
	BLK = 2;
} else
if ( n >= 37805 && n < 49930 ) {
	BLK = 1;
} else
if ( n >= 49930 && n < 51816 ) {
	BLK = 2;
} else
if ( n >= 51816 && n < 94473 ) {
	BLK = 1;
} else
if ( n >= 94473 && n < 99637 ) {
	BLK = 2;
} else
if ( n >= 99637 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
