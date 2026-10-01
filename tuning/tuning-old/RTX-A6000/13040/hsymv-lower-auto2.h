#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Sun Sep 27 20:57:54  2026
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3571 ) {
	BLK = 0;
} else
if ( n >= 3571 && n < 4031 ) {
	BLK = 3;
} else
if ( n >= 4031 && n < 5366 ) {
	BLK = 4;
} else
if ( n >= 5366 && n < 37533 ) {
	BLK = 1;
} else
if ( n >= 37533 && n < 41893 ) {
	BLK = 2;
} else
if ( n >= 41893 && n < 42597 ) {
	BLK = 1;
} else
if ( n >= 42597 && n < 80190 ) {
	BLK = 2;
} else
if ( n >= 80190 && n < 81120 ) {
	BLK = 4;
} else
if ( n >= 81120 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
