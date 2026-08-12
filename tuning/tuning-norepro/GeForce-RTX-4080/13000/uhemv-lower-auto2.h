#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Thu Oct 30 10:42:33  2025
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 6 ) {
	BLK = 3;
} else
if ( n >= 6 && n < 7 ) {
	BLK = 2;
} else
if ( n >= 7 && n < 14 ) {
	BLK = 4;
} else
if ( n >= 14 && n < 475 ) {
	BLK = 5;
} else
if ( n >= 475 && n < 1224 ) {
	BLK = 1;
} else
if ( n >= 1224 && n < 1957 ) {
	BLK = 2;
} else
if ( n >= 1957 && n < 2543 ) {
	BLK = 4;
} else
if ( n >= 2543 && n < 2877 ) {
	BLK = 2;
} else
if ( n >= 2877 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
