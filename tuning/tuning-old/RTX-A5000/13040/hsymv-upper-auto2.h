#ifndef HSYMVU_AUTO2_H_INCLUDED
#define HSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVU
 Fri Sep 25 22:37:13  2026
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
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2488 ) {
	BLK = 0;
} else
if ( n >= 2488 && n < 3072 ) {
	BLK = 5;
} else
if ( n >= 3072 && n < 5108 ) {
	BLK = 4;
} else
if ( n >= 5108 && n < 13780 ) {
	BLK = 1;
} else
if ( n >= 13780 && n < 14388 ) {
	BLK = 2;
} else
if ( n >= 14388 && n < 16158 ) {
	BLK = 1;
} else
if ( n >= 16158 && n < 16525 ) {
	BLK = 2;
} else
if ( n >= 16525 && n < 17649 ) {
	BLK = 1;
} else
if ( n >= 17649 && n < 18736 ) {
	BLK = 2;
} else
if ( n >= 18736 && n < 28028 ) {
	BLK = 1;
} else
if ( n >= 28028 && n < 37619 ) {
	BLK = 2;
} else
if ( n >= 37619 && n < 38466 ) {
	BLK = 1;
} else
if ( n >= 38466 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
