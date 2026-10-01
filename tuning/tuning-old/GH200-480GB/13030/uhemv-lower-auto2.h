#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Wed Sep 30 16:05:19  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2 ) {
	BLK = 4;
} else
if ( n >= 2 && n < 5 ) {
	BLK = 1;
} else
if ( n >= 5 && n < 7 ) {
	BLK = 3;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 10 ) {
	BLK = 1;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 24 ) {
	BLK = 2;
} else
if ( n >= 24 && n < 497 ) {
	BLK = 0;
} else
if ( n >= 497 && n < 504 ) {
	BLK = 5;
} else
if ( n >= 504 && n < 511 ) {
	BLK = 3;
} else
if ( n >= 511 && n < 512 ) {
	BLK = 2;
} else
if ( n >= 512 && n < 575 ) {
	BLK = 0;
} else
if ( n >= 575 && n < 576 ) {
	BLK = 2;
} else
if ( n >= 576 && n < 601 ) {
	BLK = 3;
} else
if ( n >= 601 && n < 630 ) {
	BLK = 0;
} else
if ( n >= 630 && n < 631 ) {
	BLK = 5;
} else
if ( n >= 631 && n < 632 ) {
	BLK = 3;
} else
if ( n >= 632 && n < 633 ) {
	BLK = 0;
} else
if ( n >= 633 && n < 3520 ) {
	BLK = 2;
} else
if ( n >= 3520 && n < 3552 ) {
	BLK = 3;
} else
if ( n >= 3552 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
