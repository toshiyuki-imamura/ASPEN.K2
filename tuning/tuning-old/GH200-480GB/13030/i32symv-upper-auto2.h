#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Wed Sep 30 01:04:51  2026
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

if ( n >= 1 && n < 4778 ) {
	BLK = 0;
} else
if ( n >= 4778 && n < 4800 ) {
	BLK = 1;
} else
if ( n >= 4800 && n < 4814 ) {
	BLK = 0;
} else
if ( n >= 4814 && n < 4816 ) {
	BLK = 2;
} else
if ( n >= 4816 && n < 4875 ) {
	BLK = 1;
} else
if ( n >= 4875 && n < 4987 ) {
	BLK = 0;
} else
if ( n >= 4987 && n < 5241 ) {
	BLK = 4;
} else
if ( n >= 5241 && n < 13485 ) {
	BLK = 1;
} else
if ( n >= 13485 && n < 29653 ) {
	BLK = 4;
} else
if ( n >= 29653 && n < 30425 ) {
	BLK = 3;
} else
if ( n >= 30425 && n < 32790 ) {
	BLK = 4;
} else
if ( n >= 32790 && n < 33307 ) {
	BLK = 3;
} else
if ( n >= 33307 && n < 34993 ) {
	BLK = 1;
} else
if ( n >= 34993 && n < 36426 ) {
	BLK = 3;
} else
if ( n >= 36426 && n < 37820 ) {
	BLK = 4;
} else
if ( n >= 37820 && n < 38477 ) {
	BLK = 1;
} else
if ( n >= 38477 && n < 40858 ) {
	BLK = 3;
} else
if ( n >= 40858 && n < 42008 ) {
	BLK = 4;
} else
if ( n >= 42008 && n < 42888 ) {
	BLK = 3;
} else
if ( n >= 42888 && n < 44185 ) {
	BLK = 1;
} else
if ( n >= 44185 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
