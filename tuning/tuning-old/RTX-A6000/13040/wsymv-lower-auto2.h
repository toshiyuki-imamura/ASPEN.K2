#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Sun Sep 27 07:51:57  2026
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

if ( n >= 1 && n < 5 ) {
	BLK = 2;
} else
if ( n >= 5 && n < 8 ) {
	BLK = 5;
} else
if ( n >= 8 && n < 12 ) {
	BLK = 3;
} else
if ( n >= 12 && n < 26 ) {
	BLK = 2;
} else
if ( n >= 26 && n < 27 ) {
	BLK = 1;
} else
if ( n >= 27 && n < 287 ) {
	BLK = 5;
} else
if ( n >= 287 && n < 3392 ) {
	BLK = 3;
} else
if ( n >= 3392 && n < 5179 ) {
	BLK = 2;
} else
if ( n >= 5179 && n < 6580 ) {
	BLK = 1;
} else
if ( n >= 6580 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
