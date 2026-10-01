#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Wed Sep 23 12:03:47  2026
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
MAXmem= 16800759808
// capacity of the work area reserved on the GPU
WORK= 2539520
// for double or cuFloatComplex or int64
MAXDIM= 43535
// for float or cuHalfComplex or int32
MAXDIM2= 61568
// for cuDoubleComplex or DD or int128
MAXDIM3= 30784
// for DD-Complex
MAXDIM4= 21767
// for half or int16
MAXDIM5= 87070
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
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

if ( n >= 1 && n < 8 ) {
	BLK = 5;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 10 ) {
	BLK = 3;
} else
if ( n >= 10 && n < 25 ) {
	BLK = 5;
} else
if ( n >= 25 && n < 29 ) {
	BLK = 2;
} else
if ( n >= 29 && n < 30 ) {
	BLK = 1;
} else
if ( n >= 30 && n < 3491 ) {
	BLK = 3;
} else
if ( n >= 3491 && n < 3638 ) {
	BLK = 4;
} else
if ( n >= 3638 && n < 3642 ) {
	BLK = 2;
} else
if ( n >= 3642 && n < 3664 ) {
	BLK = 1;
} else
if ( n >= 3664 && n < 3712 ) {
	BLK = 3;
} else
if ( n >= 3712 && n < 3984 ) {
	BLK = 2;
} else
if ( n >= 3984 && n < 4001 ) {
	BLK = 1;
} else
if ( n >= 4001 && n < 4003 ) {
	BLK = 4;
} else
if ( n >= 4003 && n < 7094 ) {
	BLK = 2;
} else
if ( n >= 7094 && n < 7148 ) {
	BLK = 1;
} else
if ( n >= 7148 && n < 8122 ) {
	BLK = 5;
} else
if ( n >= 8122 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
