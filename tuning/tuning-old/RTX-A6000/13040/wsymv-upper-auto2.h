#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Fri Sep 25 20:15:19  2026
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

if ( n >= 1 && n < 27 ) {
	BLK = 3;
} else
if ( n >= 27 && n < 251 ) {
	BLK = 5;
} else
if ( n >= 251 && n < 3453 ) {
	BLK = 2;
} else
if ( n >= 3453 && n < 4904 ) {
	BLK = 1;
} else
if ( n >= 4904 && n < 6402 ) {
	BLK = 3;
} else
if ( n >= 6402 && n < 10038 ) {
	BLK = 1;
} else
if ( n >= 10038 && n < 10633 ) {
	BLK = 3;
} else
if ( n >= 10633 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
