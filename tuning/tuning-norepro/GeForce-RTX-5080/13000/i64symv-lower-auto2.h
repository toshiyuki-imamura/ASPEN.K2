#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Fri Nov 08 18:40:35  2024
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

if ( n >= 1 && n < 16 ) {
	BLK = 0;
} else
if ( n >= 16 && n < 18 ) {
	BLK = 6;
} else
if ( n >= 18 && n < 20 ) {
	BLK = 4;
} else
if ( n >= 20 && n < 802 ) {
	BLK = 0;
} else
if ( n >= 802 && n < 816 ) {
	BLK = 2;
} else
if ( n >= 816 && n < 818 ) {
	BLK = 4;
} else
if ( n >= 818 && n < 833 ) {
	BLK = 0;
} else
if ( n >= 833 && n < 880 ) {
	BLK = 2;
} else
if ( n >= 880 && n < 882 ) {
	BLK = 0;
} else
if ( n >= 882 && n < 1747 ) {
	BLK = 4;
} else
if ( n >= 1747 && n < 2385 ) {
	BLK = 1;
} else
if ( n >= 2385 && n < 3463 ) {
	BLK = 4;
} else
if ( n >= 3463 && n < 3837 ) {
	BLK = 3;
} else
if ( n >= 3837 && n < 4154 ) {
	BLK = 1;
} else
if ( n >= 4154 && n < 4216 ) {
	BLK = 5;
} else
if ( n >= 4216 && n < 5366 ) {
	BLK = 4;
} else
if ( n >= 5366 && n < 5995 ) {
	BLK = 3;
} else
if ( n >= 5995 && n < 6612 ) {
	BLK = 4;
} else
if ( n >= 6612 && n < 7056 ) {
	BLK = 6;
} else
if ( n >= 7056 && n < 7290 ) {
	BLK = 4;
} else
if ( n >= 7290 && n < 7653 ) {
	BLK = 3;
} else
if ( n >= 7653 && n < 8005 ) {
	BLK = 6;
} else
if ( n >= 8005 && n < 9694 ) {
	BLK = 4;
} else
if ( n >= 9694 && n < 10480 ) {
	BLK = 6;
} else
if ( n >= 10480 && n < 11994 ) {
	BLK = 4;
} else
if ( n >= 11994 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
