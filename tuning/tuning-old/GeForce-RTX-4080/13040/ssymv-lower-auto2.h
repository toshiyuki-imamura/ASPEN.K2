#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Wed Sep 23 17:28:34  2026
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
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1537 ) {
	BLK = 0;
} else
if ( n >= 1537 && n < 1541 ) {
	BLK = 1;
} else
if ( n >= 1541 && n < 1544 ) {
	BLK = 0;
} else
if ( n >= 1544 && n < 1546 ) {
	BLK = 1;
} else
if ( n >= 1546 && n < 1976 ) {
	BLK = 2;
} else
if ( n >= 1976 && n < 2052 ) {
	BLK = 1;
} else
if ( n >= 2052 && n < 5968 ) {
	BLK = 0;
} else
if ( n >= 5968 && n < 5983 ) {
	BLK = 1;
} else
if ( n >= 5983 && n < 5996 ) {
	BLK = 2;
} else
if ( n >= 5996 && n < 6020 ) {
	BLK = 0;
} else
if ( n >= 6020 && n < 6107 ) {
	BLK = 1;
} else
if ( n >= 6107 && n < 6373 ) {
	BLK = 2;
} else
if ( n >= 6373 && n < 11460 ) {
	BLK = 4;
} else
if ( n >= 11460 && n < 14842 ) {
	BLK = 2;
} else
if ( n >= 14842 && n < 16859 ) {
	BLK = 1;
} else
if ( n >= 16859 && n < 18952 ) {
	BLK = 2;
} else
if ( n >= 18952 && n < 19214 ) {
	BLK = 1;
} else
if ( n >= 19214 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
