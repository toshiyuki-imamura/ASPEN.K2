#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Sun Sep 27 03:02:40  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2612 ) {
	BLK = 0;
} else
if ( n >= 2612 && n < 2613 ) {
	BLK = 1;
} else
if ( n >= 2613 && n < 2614 ) {
	BLK = 4;
} else
if ( n >= 2614 && n < 2785 ) {
	BLK = 0;
} else
if ( n >= 2785 && n < 2786 ) {
	BLK = 1;
} else
if ( n >= 2786 && n < 2791 ) {
	BLK = 4;
} else
if ( n >= 2791 && n < 2809 ) {
	BLK = 0;
} else
if ( n >= 2809 && n < 2810 ) {
	BLK = 1;
} else
if ( n >= 2810 && n < 2811 ) {
	BLK = 4;
} else
if ( n >= 2811 && n < 2928 ) {
	BLK = 0;
} else
if ( n >= 2928 && n < 2929 ) {
	BLK = 1;
} else
if ( n >= 2929 && n < 2930 ) {
	BLK = 4;
} else
if ( n >= 2930 && n < 2936 ) {
	BLK = 0;
} else
if ( n >= 2936 && n < 22285 ) {
	BLK = 1;
} else
if ( n >= 22285 && n < 22650 ) {
	BLK = 4;
} else
if ( n >= 22650 && n < 29538 ) {
	BLK = 1;
} else
if ( n >= 29538 && n < 41771 ) {
	BLK = 4;
} else
if ( n >= 41771 && n < 42640 ) {
	BLK = 3;
} else
if ( n >= 42640 && n < 43986 ) {
	BLK = 4;
} else
if ( n >= 43986 && n < 51629 ) {
	BLK = 3;
} else
if ( n >= 51629 && n < 55583 ) {
	BLK = 1;
} else
if ( n >= 55583 && n < 57650 ) {
	BLK = 3;
} else
if ( n >= 57650 && n < 62437 ) {
	BLK = 1;
} else
if ( n >= 62437 && n < 64512 ) {
	BLK = 3;
} else
if ( n >= 64512 && n < 67947 ) {
	BLK = 1;
} else
if ( n >= 67947 && n < 78482 ) {
	BLK = 3;
} else
if ( n >= 78482 && n < 81141 ) {
	BLK = 1;
} else
if ( n >= 81141 && n < 84337 ) {
	BLK = 3;
} else
if ( n >= 84337 && n < 88991 ) {
	BLK = 1;
} else
if ( n >= 88991 && n < 93069 ) {
	BLK = 3;
} else
if ( n >= 93069 && n < 94713 ) {
	BLK = 1;
} else
if ( n >= 94713 && n < 125378 ) {
	BLK = 3;
} else
if ( n >= 125378 && n < 135358 ) {
	BLK = 1;
} else
if ( n >= 135358 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
