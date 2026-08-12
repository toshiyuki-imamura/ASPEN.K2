#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Sun Oct 26 04:17:20  2025
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16715563008
// capacity of the work area reserved on the GPU
WORK= 506368
// for double or cuFloatComplex or int64
MAXDIM= 43424
// for float or cuHalfComplex or int32
MAXDIM2= 61412
// for cuDoubleComplex or DD or int128
MAXDIM3= 30706
// for DD-Complex
MAXDIM4= 21712
// for half or int16
MAXDIM5= 86849
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_3	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 7920 ) {
	BLK = 0;
} else
if ( n >= 7920 && n < 12074 ) {
	BLK = 3;
} else
if ( n >= 12074 && n < 16332 ) {
	BLK = 6;
} else
if ( n >= 16332 && n < 31314 ) {
	BLK = 5;
} else
if ( n >= 31314 && n < 33457 ) {
	BLK = 6;
} else
if ( n >= 33457 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
