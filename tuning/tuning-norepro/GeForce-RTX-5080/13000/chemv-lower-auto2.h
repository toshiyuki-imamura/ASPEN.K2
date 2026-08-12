#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Sun Nov 10 13:28:08  2024
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

if ( n >= 1 && n < 904 ) {
	BLK = 0;
} else
if ( n >= 904 && n < 998 ) {
	BLK = 3;
} else
if ( n >= 998 && n < 1780 ) {
	BLK = 6;
} else
if ( n >= 1780 && n < 1989 ) {
	BLK = 4;
} else
if ( n >= 1989 && n < 2051 ) {
	BLK = 1;
} else
if ( n >= 2051 && n < 2059 ) {
	BLK = 2;
} else
if ( n >= 2059 && n < 2503 ) {
	BLK = 4;
} else
if ( n >= 2503 && n < 3259 ) {
	BLK = 1;
} else
if ( n >= 3259 && n < 3481 ) {
	BLK = 6;
} else
if ( n >= 3481 && n < 3834 ) {
	BLK = 1;
} else
if ( n >= 3834 && n < 4093 ) {
	BLK = 2;
} else
if ( n >= 4093 && n < 4113 ) {
	BLK = 4;
} else
if ( n >= 4113 && n < 4160 ) {
	BLK = 5;
} else
if ( n >= 4160 && n < 4828 ) {
	BLK = 2;
} else
if ( n >= 4828 && n < 4945 ) {
	BLK = 1;
} else
if ( n >= 4945 && n < 4968 ) {
	BLK = 5;
} else
if ( n >= 4968 && n < 6131 ) {
	BLK = 2;
} else
if ( n >= 6131 && n < 7148 ) {
	BLK = 5;
} else
if ( n >= 7148 && n < 8411 ) {
	BLK = 2;
} else
if ( n >= 8411 && n < 8808 ) {
	BLK = 5;
} else
if ( n >= 8808 && n < 9707 ) {
	BLK = 2;
} else
if ( n >= 9707 && n < 11610 ) {
	BLK = 5;
} else
if ( n >= 11610 && n < 12046 ) {
	BLK = 2;
} else
if ( n >= 12046 && n < 18560 ) {
	BLK = 5;
} else
if ( n >= 18560 && n < 19333 ) {
	BLK = 2;
} else
if ( n >= 19333 && n < 20621 ) {
	BLK = 5;
} else
if ( n >= 20621 && n < 21959 ) {
	BLK = 2;
} else
if ( n >= 21959 && n < 23526 ) {
	BLK = 5;
} else
if ( n >= 23526 && n < 25186 ) {
	BLK = 2;
} else
if ( n >= 25186 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
