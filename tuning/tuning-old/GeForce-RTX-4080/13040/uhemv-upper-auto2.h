#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Thu Sep 24 07:47:04  2026
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

if ( n >= 1 && n < 4 ) {
	BLK = 4;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 5;
} else
if ( n >= 5 && n < 20 ) {
	BLK = 1;
} else
if ( n >= 20 && n < 620 ) {
	BLK = 4;
} else
if ( n >= 620 && n < 1239 ) {
	BLK = 3;
} else
if ( n >= 1239 && n < 1537 ) {
	BLK = 5;
} else
if ( n >= 1537 && n < 1561 ) {
	BLK = 3;
} else
if ( n >= 1561 && n < 1693 ) {
	BLK = 4;
} else
if ( n >= 1693 && n < 2683 ) {
	BLK = 5;
} else
if ( n >= 2683 && n < 3007 ) {
	BLK = 3;
} else
if ( n >= 3007 && n < 3905 ) {
	BLK = 2;
} else
if ( n >= 3905 && n < 4346 ) {
	BLK = 1;
} else
if ( n >= 4346 && n < 4348 ) {
	BLK = 3;
} else
if ( n >= 4348 && n < 4385 ) {
	BLK = 2;
} else
if ( n >= 4385 && n < 4679 ) {
	BLK = 1;
} else
if ( n >= 4679 && n < 5337 ) {
	BLK = 3;
} else
if ( n >= 5337 && n < 6319 ) {
	BLK = 2;
} else
if ( n >= 6319 && n < 8710 ) {
	BLK = 1;
} else
if ( n >= 8710 && n < 9404 ) {
	BLK = 2;
} else
if ( n >= 9404 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
