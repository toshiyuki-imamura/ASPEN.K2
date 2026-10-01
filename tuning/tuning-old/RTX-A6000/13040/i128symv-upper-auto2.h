#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Sat Sep 26 13:35:17  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2 ) {
	BLK = 1;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 4;
} else
if ( n >= 3 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 5;
} else
if ( n >= 9 && n < 15 ) {
	BLK = 1;
} else
if ( n >= 15 && n < 24 ) {
	BLK = 4;
} else
if ( n >= 24 && n < 49 ) {
	BLK = 5;
} else
if ( n >= 49 && n < 50 ) {
	BLK = 4;
} else
if ( n >= 50 && n < 256 ) {
	BLK = 0;
} else
if ( n >= 256 && n < 268 ) {
	BLK = 5;
} else
if ( n >= 268 && n < 426 ) {
	BLK = 3;
} else
if ( n >= 426 && n < 533 ) {
	BLK = 0;
} else
if ( n >= 533 && n < 534 ) {
	BLK = 4;
} else
if ( n >= 534 && n < 552 ) {
	BLK = 3;
} else
if ( n >= 552 && n < 570 ) {
	BLK = 0;
} else
if ( n >= 570 && n < 579 ) {
	BLK = 4;
} else
if ( n >= 579 && n < 580 ) {
	BLK = 0;
} else
if ( n >= 580 && n < 592 ) {
	BLK = 3;
} else
if ( n >= 592 && n < 595 ) {
	BLK = 0;
} else
if ( n >= 595 && n < 755 ) {
	BLK = 3;
} else
if ( n >= 755 && n < 777 ) {
	BLK = 4;
} else
if ( n >= 777 && n < 778 ) {
	BLK = 0;
} else
if ( n >= 778 && n < 779 ) {
	BLK = 3;
} else
if ( n >= 779 && n < 780 ) {
	BLK = 2;
} else
if ( n >= 780 && n < 781 ) {
	BLK = 0;
} else
if ( n >= 781 && n < 796 ) {
	BLK = 3;
} else
if ( n >= 796 && n < 797 ) {
	BLK = 0;
} else
if ( n >= 797 && n < 799 ) {
	BLK = 4;
} else
if ( n >= 799 && n < 800 ) {
	BLK = 2;
} else
if ( n >= 800 && n < 820 ) {
	BLK = 3;
} else
if ( n >= 820 && n < 827 ) {
	BLK = 0;
} else
if ( n >= 827 && n < 1527 ) {
	BLK = 3;
} else
if ( n >= 1527 && n < 5663 ) {
	BLK = 2;
} else
if ( n >= 5663 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
