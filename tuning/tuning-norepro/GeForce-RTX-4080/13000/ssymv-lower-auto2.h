#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Sat Oct 25 15:02:05  2025
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
#define	KERNEL_2	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5517 ) {
	BLK = 0;
} else
if ( n >= 5517 && n < 6013 ) {
	BLK = 6;
} else
if ( n >= 6013 && n < 7498 ) {
	BLK = 5;
} else
if ( n >= 7498 && n < 8764 ) {
	BLK = 6;
} else
if ( n >= 8764 && n < 9057 ) {
	BLK = 5;
} else
if ( n >= 9057 && n < 9659 ) {
	BLK = 6;
} else
if ( n >= 9659 && n < 9928 ) {
	BLK = 5;
} else
if ( n >= 9928 && n < 10249 ) {
	BLK = 6;
} else
if ( n >= 10249 && n < 10662 ) {
	BLK = 5;
} else
if ( n >= 10662 && n < 11396 ) {
	BLK = 6;
} else
if ( n >= 11396 && n < 17275 ) {
	BLK = 2;
} else
if ( n >= 17275 && n < 20368 ) {
	BLK = 6;
} else
if ( n >= 20368 && n < 20713 ) {
	BLK = 5;
} else
if ( n >= 20713 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
