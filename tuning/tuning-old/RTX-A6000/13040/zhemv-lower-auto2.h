#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Tue Sep 29 18:02:28  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 32 ) {
	BLK = 3;
} else
if ( n >= 32 && n < 770 ) {
	BLK = 2;
} else
if ( n >= 770 && n < 793 ) {
	BLK = 3;
} else
if ( n >= 793 && n < 794 ) {
	BLK = 2;
} else
if ( n >= 794 && n < 795 ) {
	BLK = 1;
} else
if ( n >= 795 && n < 800 ) {
	BLK = 3;
} else
if ( n >= 800 && n < 819 ) {
	BLK = 2;
} else
if ( n >= 819 && n < 820 ) {
	BLK = 5;
} else
if ( n >= 820 && n < 827 ) {
	BLK = 1;
} else
if ( n >= 827 && n < 831 ) {
	BLK = 2;
} else
if ( n >= 831 && n < 864 ) {
	BLK = 5;
} else
if ( n >= 864 && n < 944 ) {
	BLK = 1;
} else
if ( n >= 944 && n < 988 ) {
	BLK = 5;
} else
if ( n >= 988 && n < 1032 ) {
	BLK = 1;
} else
if ( n >= 1032 && n < 1056 ) {
	BLK = 3;
} else
if ( n >= 1056 && n < 1548 ) {
	BLK = 2;
} else
if ( n >= 1548 && n < 2688 ) {
	BLK = 3;
} else
if ( n >= 2688 && n < 2690 ) {
	BLK = 1;
} else
if ( n >= 2690 && n < 2691 ) {
	BLK = 5;
} else
if ( n >= 2691 && n < 2697 ) {
	BLK = 3;
} else
if ( n >= 2697 && n < 2698 ) {
	BLK = 5;
} else
if ( n >= 2698 && n < 2699 ) {
	BLK = 1;
} else
if ( n >= 2699 && n < 2723 ) {
	BLK = 3;
} else
if ( n >= 2723 && n < 2746 ) {
	BLK = 1;
} else
if ( n >= 2746 && n < 2747 ) {
	BLK = 3;
} else
if ( n >= 2747 && n < 3213 ) {
	BLK = 5;
} else
if ( n >= 3213 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
