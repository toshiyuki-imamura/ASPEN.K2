#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Tue Sep 29 17:26:57  2026
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
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 8 ) {
	BLK = 4;
} else
if ( n >= 8 && n < 24 ) {
	BLK = 2;
} else
if ( n >= 24 && n < 2544 ) {
	BLK = 0;
} else
if ( n >= 2544 && n < 3299 ) {
	BLK = 1;
} else
if ( n >= 3299 && n < 3302 ) {
	BLK = 4;
} else
if ( n >= 3302 && n < 3307 ) {
	BLK = 2;
} else
if ( n >= 3307 && n < 3309 ) {
	BLK = 4;
} else
if ( n >= 3309 && n < 3310 ) {
	BLK = 1;
} else
if ( n >= 3310 && n < 3317 ) {
	BLK = 2;
} else
if ( n >= 3317 && n < 3327 ) {
	BLK = 4;
} else
if ( n >= 3327 && n < 3339 ) {
	BLK = 2;
} else
if ( n >= 3339 && n < 3558 ) {
	BLK = 1;
} else
if ( n >= 3558 && n < 3560 ) {
	BLK = 2;
} else
if ( n >= 3560 && n < 3562 ) {
	BLK = 4;
} else
if ( n >= 3562 && n < 6107 ) {
	BLK = 1;
} else
if ( n >= 6107 && n < 8282 ) {
	BLK = 2;
} else
if ( n >= 8282 && n < 9336 ) {
	BLK = 1;
} else
if ( n >= 9336 && n < 10547 ) {
	BLK = 2;
} else
if ( n >= 10547 && n < 11576 ) {
	BLK = 1;
} else
if ( n >= 11576 && n < 12580 ) {
	BLK = 2;
} else
if ( n >= 12580 && n < 14449 ) {
	BLK = 1;
} else
if ( n >= 14449 && n < 14748 ) {
	BLK = 2;
} else
if ( n >= 14748 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
