#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Sat Sep 26 18:19:33  2026
 Host on fermat.r-ccs27.riken.jp
 Device is RTX-A5000
****************************************/-->
// device name
DEVICE= RTX-A5000
// the number of multi-processors
MP= 64
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 25327001600
// capacity of the work area reserved on the GPU
WORK= 3118080
// for double or cuFloatComplex or int64
MAXDIM= 53452
// for float or cuHalfComplex or int32
MAXDIM2= 75593
// for cuDoubleComplex or DD or int128
MAXDIM3= 37796
// for DD-Complex
MAXDIM4= 26726
// for half or int16
MAXDIM5= 106905
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2238 ) {
	BLK = 0;
} else
if ( n >= 2238 && n < 2937 ) {
	BLK = 5;
} else
if ( n >= 2937 && n < 12564 ) {
	BLK = 1;
} else
if ( n >= 12564 && n < 18050 ) {
	BLK = 4;
} else
if ( n >= 18050 && n < 18321 ) {
	BLK = 3;
} else
if ( n >= 18321 && n < 24608 ) {
	BLK = 4;
} else
if ( n >= 24608 && n < 25174 ) {
	BLK = 1;
} else
if ( n >= 25174 && n < 27165 ) {
	BLK = 4;
} else
if ( n >= 27165 && n < 28198 ) {
	BLK = 1;
} else
if ( n >= 28198 && n < 34718 ) {
	BLK = 4;
} else
if ( n >= 34718 && n < 35634 ) {
	BLK = 1;
} else
if ( n >= 35634 && n < 47427 ) {
	BLK = 4;
} else
if ( n >= 47427 && n < 49920 ) {
	BLK = 1;
} else
if ( n >= 49920 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
