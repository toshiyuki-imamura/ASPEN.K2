#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Wed Nov 06 19:10:50  2024
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-GTX-1080
****************************************/-->
// device name
DEVICE= GeForce-GTX-1080
// the number of multi-processors
MP= 20
// compute-compatibility generation
CG= 610
// capacity of the global memory or host memory
MAXmem= 8497229824
// capacity of the work area reserved on the GPU
WORK= 360960
// for double or cuFloatComplex or int64
MAXDIM= 30961
// for float or cuHalfComplex or int32
MAXDIM2= 43785
// for cuDoubleComplex or DD or int128
MAXDIM3= 21892
// for DD-Complex
MAXDIM4= 15480
// for half or int16
MAXDIM5= 61922
// cuda version
CUDA= 12060
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 610
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2 ) {
	BLK = 0;
} else
if ( n >= 2 && n < 4 ) {
	BLK = 1;
} else
if ( n >= 4 && n < 6 ) {
	BLK = 2;
} else
if ( n >= 6 && n < 14 ) {
	BLK = 0;
} else
if ( n >= 14 && n < 15 ) {
	BLK = 5;
} else
if ( n >= 15 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 20 ) {
	BLK = 1;
} else
if ( n >= 20 && n < 24 ) {
	BLK = 5;
} else
if ( n >= 24 && n < 883 ) {
	BLK = 0;
} else
if ( n >= 883 && n < 902 ) {
	BLK = 1;
} else
if ( n >= 902 && n < 921 ) {
	BLK = 0;
} else
if ( n >= 921 && n < 930 ) {
	BLK = 2;
} else
if ( n >= 930 && n < 934 ) {
	BLK = 0;
} else
if ( n >= 934 && n < 1072 ) {
	BLK = 1;
} else
if ( n >= 1072 && n < 1074 ) {
	BLK = 3;
} else
if ( n >= 1074 && n < 2335 ) {
	BLK = 2;
} else
if ( n >= 2335 && n < 4161 ) {
	BLK = 1;
} else
if ( n >= 4161 && n < 4178 ) {
	BLK = 2;
} else
if ( n >= 4178 && n < 4217 ) {
	BLK = 6;
} else
if ( n >= 4217 && n < 9082 ) {
	BLK = 1;
} else
if ( n >= 9082 && n < 9123 ) {
	BLK = 2;
} else
if ( n >= 9123 && n < 9303 ) {
	BLK = 5;
} else
if ( n >= 9303 && n < 9682 ) {
	BLK = 1;
} else
if ( n >= 9682 && n < 10430 ) {
	BLK = 5;
} else
if ( n >= 10430 && n < 12375 ) {
	BLK = 6;
} else
if ( n >= 12375 && n < 12666 ) {
	BLK = 1;
} else
if ( n >= 12666 && n < 12987 ) {
	BLK = 6;
} else
if ( n >= 12987 && n < 13256 ) {
	BLK = 5;
} else
if ( n >= 13256 && n < 13837 ) {
	BLK = 6;
} else
if ( n >= 13837 && n < 14651 ) {
	BLK = 5;
} else
if ( n >= 14651 && n < 15359 ) {
	BLK = 6;
} else
if ( n >= 15359 && n < 18128 ) {
	BLK = 5;
} else
if ( n >= 18128 && n < 18434 ) {
	BLK = 6;
} else
if ( n >= 18434 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
