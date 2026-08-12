#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Sat Nov 09 12:18:26  2024
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
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 10 ) {
	BLK = 2;
} else
if ( n >= 10 && n < 14 ) {
	BLK = 5;
} else
if ( n >= 14 && n < 18 ) {
	BLK = 6;
} else
if ( n >= 18 && n < 130 ) {
	BLK = 3;
} else
if ( n >= 130 && n < 220 ) {
	BLK = 4;
} else
if ( n >= 220 && n < 236 ) {
	BLK = 1;
} else
if ( n >= 236 && n < 291 ) {
	BLK = 3;
} else
if ( n >= 291 && n < 314 ) {
	BLK = 2;
} else
if ( n >= 314 && n < 378 ) {
	BLK = 4;
} else
if ( n >= 378 && n < 1000 ) {
	BLK = 3;
} else
if ( n >= 1000 && n < 1020 ) {
	BLK = 4;
} else
if ( n >= 1020 && n < 1267 ) {
	BLK = 0;
} else
if ( n >= 1267 && n < 1383 ) {
	BLK = 1;
} else
if ( n >= 1383 && n < 1506 ) {
	BLK = 4;
} else
if ( n >= 1506 && n < 2236 ) {
	BLK = 2;
} else
if ( n >= 2236 && n < 2269 ) {
	BLK = 4;
} else
if ( n >= 2269 && n < 2284 ) {
	BLK = 5;
} else
if ( n >= 2284 && n < 2580 ) {
	BLK = 0;
} else
if ( n >= 2580 && n < 3195 ) {
	BLK = 1;
} else
if ( n >= 3195 && n < 3554 ) {
	BLK = 2;
} else
if ( n >= 3554 && n < 2147483647 ) {
	BLK = 0;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 0;
} 

#endif
