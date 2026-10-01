#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Tue Sep 29 04:09:53  2026
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

if ( n >= 1 && n < 530 ) {
	BLK = 0;
} else
if ( n >= 530 && n < 531 ) {
	BLK = 3;
} else
if ( n >= 531 && n < 532 ) {
	BLK = 5;
} else
if ( n >= 532 && n < 1517 ) {
	BLK = 0;
} else
if ( n >= 1517 && n < 2468 ) {
	BLK = 3;
} else
if ( n >= 2468 && n < 2469 ) {
	BLK = 1;
} else
if ( n >= 2469 && n < 2479 ) {
	BLK = 2;
} else
if ( n >= 2479 && n < 2721 ) {
	BLK = 3;
} else
if ( n >= 2721 && n < 2722 ) {
	BLK = 2;
} else
if ( n >= 2722 && n < 2723 ) {
	BLK = 1;
} else
if ( n >= 2723 && n < 3024 ) {
	BLK = 3;
} else
if ( n >= 3024 && n < 5858 ) {
	BLK = 2;
} else
if ( n >= 5858 && n < 6482 ) {
	BLK = 3;
} else
if ( n >= 6482 && n < 6572 ) {
	BLK = 2;
} else
if ( n >= 6572 && n < 6576 ) {
	BLK = 1;
} else
if ( n >= 6576 && n < 6686 ) {
	BLK = 3;
} else
if ( n >= 6686 && n < 9400 ) {
	BLK = 2;
} else
if ( n >= 9400 && n < 50803 ) {
	BLK = 1;
} else
if ( n >= 50803 && n < 52148 ) {
	BLK = 4;
} else
if ( n >= 52148 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
