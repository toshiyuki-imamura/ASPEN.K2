#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Sat Sep 26 21:59:08  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 16 ) {
	BLK = 4;
} else
if ( n >= 16 && n < 18 ) {
	BLK = 1;
} else
if ( n >= 18 && n < 19 ) {
	BLK = 5;
} else
if ( n >= 19 && n < 20 ) {
	BLK = 4;
} else
if ( n >= 20 && n < 528 ) {
	BLK = 3;
} else
if ( n >= 528 && n < 2432 ) {
	BLK = 2;
} else
if ( n >= 2432 && n < 5590 ) {
	BLK = 1;
} else
if ( n >= 5590 && n < 5875 ) {
	BLK = 5;
} else
if ( n >= 5875 && n < 6435 ) {
	BLK = 4;
} else
if ( n >= 6435 && n < 11890 ) {
	BLK = 1;
} else
if ( n >= 11890 && n < 12614 ) {
	BLK = 4;
} else
if ( n >= 12614 && n < 17535 ) {
	BLK = 1;
} else
if ( n >= 17535 && n < 18939 ) {
	BLK = 4;
} else
if ( n >= 18939 && n < 23185 ) {
	BLK = 1;
} else
if ( n >= 23185 && n < 25643 ) {
	BLK = 4;
} else
if ( n >= 25643 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
