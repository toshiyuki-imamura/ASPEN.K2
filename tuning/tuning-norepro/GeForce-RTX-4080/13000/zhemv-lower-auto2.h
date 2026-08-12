#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Thu Oct 30 20:41:14  2025
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
#define	KERNEL_6	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 8 ) {
	BLK = 4;
} else
if ( n >= 8 && n < 10 ) {
	BLK = 2;
} else
if ( n >= 10 && n < 28 ) {
	BLK = 3;
} else
if ( n >= 28 && n < 29 ) {
	BLK = 2;
} else
if ( n >= 29 && n < 38 ) {
	BLK = 4;
} else
if ( n >= 38 && n < 371 ) {
	BLK = 5;
} else
if ( n >= 371 && n < 999 ) {
	BLK = 1;
} else
if ( n >= 999 && n < 1537 ) {
	BLK = 3;
} else
if ( n >= 1537 && n < 1966 ) {
	BLK = 2;
} else
if ( n >= 1966 && n < 2155 ) {
	BLK = 3;
} else
if ( n >= 2155 && n < 2666 ) {
	BLK = 6;
} else
if ( n >= 2666 && n < 2756 ) {
	BLK = 3;
} else
if ( n >= 2756 && n < 3677 ) {
	BLK = 2;
} else
if ( n >= 3677 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
