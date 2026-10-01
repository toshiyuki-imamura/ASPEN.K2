#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Sun Sep 27 01:40:45  2026
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
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1221 ) {
	BLK = 0;
} else
if ( n >= 1221 && n < 1222 ) {
	BLK = 2;
} else
if ( n >= 1222 && n < 1259 ) {
	BLK = 3;
} else
if ( n >= 1259 && n < 1403 ) {
	BLK = 2;
} else
if ( n >= 1403 && n < 1413 ) {
	BLK = 0;
} else
if ( n >= 1413 && n < 1414 ) {
	BLK = 1;
} else
if ( n >= 1414 && n < 1431 ) {
	BLK = 2;
} else
if ( n >= 1431 && n < 1432 ) {
	BLK = 1;
} else
if ( n >= 1432 && n < 1435 ) {
	BLK = 0;
} else
if ( n >= 1435 && n < 1439 ) {
	BLK = 2;
} else
if ( n >= 1439 && n < 1440 ) {
	BLK = 1;
} else
if ( n >= 1440 && n < 1441 ) {
	BLK = 0;
} else
if ( n >= 1441 && n < 1565 ) {
	BLK = 5;
} else
if ( n >= 1565 && n < 2688 ) {
	BLK = 2;
} else
if ( n >= 2688 && n < 3332 ) {
	BLK = 5;
} else
if ( n >= 3332 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
