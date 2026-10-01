#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Thu Sep 24 23:20:12  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1202 ) {
	BLK = 0;
} else
if ( n >= 1202 && n < 1243 ) {
	BLK = 3;
} else
if ( n >= 1243 && n < 1252 ) {
	BLK = 5;
} else
if ( n >= 1252 && n < 1253 ) {
	BLK = 4;
} else
if ( n >= 1253 && n < 1254 ) {
	BLK = 0;
} else
if ( n >= 1254 && n < 1255 ) {
	BLK = 5;
} else
if ( n >= 1255 && n < 1260 ) {
	BLK = 4;
} else
if ( n >= 1260 && n < 1266 ) {
	BLK = 0;
} else
if ( n >= 1266 && n < 1274 ) {
	BLK = 4;
} else
if ( n >= 1274 && n < 1471 ) {
	BLK = 0;
} else
if ( n >= 1471 && n < 1472 ) {
	BLK = 1;
} else
if ( n >= 1472 && n < 1530 ) {
	BLK = 4;
} else
if ( n >= 1530 && n < 1531 ) {
	BLK = 0;
} else
if ( n >= 1531 && n < 1532 ) {
	BLK = 1;
} else
if ( n >= 1532 && n < 2578 ) {
	BLK = 4;
} else
if ( n >= 2578 && n < 3648 ) {
	BLK = 1;
} else
if ( n >= 3648 && n < 4154 ) {
	BLK = 0;
} else
if ( n >= 4154 && n < 6367 ) {
	BLK = 1;
} else
if ( n >= 6367 && n < 8275 ) {
	BLK = 4;
} else
if ( n >= 8275 && n < 14112 ) {
	BLK = 3;
} else
if ( n >= 14112 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
