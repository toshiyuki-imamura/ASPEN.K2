#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Sat Sep 26 11:30:53  2026
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

if ( n >= 1 && n < 2555 ) {
	BLK = 0;
} else
if ( n >= 2555 && n < 3520 ) {
	BLK = 5;
} else
if ( n >= 3520 && n < 3584 ) {
	BLK = 2;
} else
if ( n >= 3584 && n < 3585 ) {
	BLK = 3;
} else
if ( n >= 3585 && n < 3608 ) {
	BLK = 1;
} else
if ( n >= 3608 && n < 3610 ) {
	BLK = 2;
} else
if ( n >= 3610 && n < 3611 ) {
	BLK = 3;
} else
if ( n >= 3611 && n < 3969 ) {
	BLK = 1;
} else
if ( n >= 3969 && n < 6872 ) {
	BLK = 2;
} else
if ( n >= 6872 && n < 7748 ) {
	BLK = 3;
} else
if ( n >= 7748 && n < 7921 ) {
	BLK = 2;
} else
if ( n >= 7921 && n < 8324 ) {
	BLK = 1;
} else
if ( n >= 8324 && n < 8391 ) {
	BLK = 3;
} else
if ( n >= 8391 && n < 9084 ) {
	BLK = 2;
} else
if ( n >= 9084 && n < 9858 ) {
	BLK = 1;
} else
if ( n >= 9858 && n < 10694 ) {
	BLK = 3;
} else
if ( n >= 10694 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
