#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Tue Sep 29 13:50:54  2026
 Host on pascal.r-ccs27.riken.jp
 Device is RTX-A6000
****************************************/-->
// device name
DEVICE= RTX-A6000
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 50949160960
// capacity of the work area reserved on the GPU
WORK= 4423680
// for double or cuFloatComplex or int64
MAXDIM= 75813
// for float or cuHalfComplex or int32
MAXDIM2= 107216
// for cuDoubleComplex or DD or int128
MAXDIM3= 53608
// for DD-Complex
MAXDIM4= 37906
// for half or int16
MAXDIM5= 151627
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

if ( n >= 1 && n < 8 ) {
	BLK = 4;
} else
if ( n >= 8 && n < 20 ) {
	BLK = 1;
} else
if ( n >= 20 && n < 688 ) {
	BLK = 2;
} else
if ( n >= 688 && n < 1192 ) {
	BLK = 4;
} else
if ( n >= 1192 && n < 2911 ) {
	BLK = 2;
} else
if ( n >= 2911 && n < 3247 ) {
	BLK = 4;
} else
if ( n >= 3247 && n < 4790 ) {
	BLK = 1;
} else
if ( n >= 4790 && n < 4948 ) {
	BLK = 4;
} else
if ( n >= 4948 && n < 5345 ) {
	BLK = 2;
} else
if ( n >= 5345 && n < 5431 ) {
	BLK = 4;
} else
if ( n >= 5431 && n < 5446 ) {
	BLK = 1;
} else
if ( n >= 5446 && n < 5470 ) {
	BLK = 5;
} else
if ( n >= 5470 && n < 5503 ) {
	BLK = 2;
} else
if ( n >= 5503 && n < 5542 ) {
	BLK = 1;
} else
if ( n >= 5542 && n < 5589 ) {
	BLK = 5;
} else
if ( n >= 5589 && n < 5676 ) {
	BLK = 4;
} else
if ( n >= 5676 && n < 5722 ) {
	BLK = 5;
} else
if ( n >= 5722 && n < 5729 ) {
	BLK = 1;
} else
if ( n >= 5729 && n < 5732 ) {
	BLK = 2;
} else
if ( n >= 5732 && n < 5742 ) {
	BLK = 4;
} else
if ( n >= 5742 && n < 5788 ) {
	BLK = 5;
} else
if ( n >= 5788 && n < 5794 ) {
	BLK = 2;
} else
if ( n >= 5794 && n < 7323 ) {
	BLK = 1;
} else
if ( n >= 7323 && n < 7999 ) {
	BLK = 3;
} else
if ( n >= 7999 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
