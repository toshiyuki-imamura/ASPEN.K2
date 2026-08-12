#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Wed Nov 06 03:05:54  2024
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 23 ) {
	BLK = 3;
} else
if ( n >= 23 && n < 24 ) {
	BLK = 0;
} else
if ( n >= 24 && n < 25 ) {
	BLK = 4;
} else
if ( n >= 25 && n < 32 ) {
	BLK = 3;
} else
if ( n >= 32 && n < 762 ) {
	BLK = 0;
} else
if ( n >= 762 && n < 844 ) {
	BLK = 1;
} else
if ( n >= 844 && n < 845 ) {
	BLK = 3;
} else
if ( n >= 845 && n < 848 ) {
	BLK = 0;
} else
if ( n >= 848 && n < 2889 ) {
	BLK = 1;
} else
if ( n >= 2889 && n < 3728 ) {
	BLK = 3;
} else
if ( n >= 3728 && n < 9510 ) {
	BLK = 2;
} else
if ( n >= 9510 && n < 9622 ) {
	BLK = 5;
} else
if ( n >= 9622 && n < 9676 ) {
	BLK = 1;
} else
if ( n >= 9676 && n < 9934 ) {
	BLK = 2;
} else
if ( n >= 9934 && n < 10196 ) {
	BLK = 1;
} else
if ( n >= 10196 && n < 10234 ) {
	BLK = 5;
} else
if ( n >= 10234 && n < 13524 ) {
	BLK = 2;
} else
if ( n >= 13524 && n < 13843 ) {
	BLK = 5;
} else
if ( n >= 13843 && n < 14122 ) {
	BLK = 2;
} else
if ( n >= 14122 && n < 14194 ) {
	BLK = 1;
} else
if ( n >= 14194 && n < 15947 ) {
	BLK = 5;
} else
if ( n >= 15947 && n < 16554 ) {
	BLK = 2;
} else
if ( n >= 16554 && n < 17133 ) {
	BLK = 1;
} else
if ( n >= 17133 && n < 17869 ) {
	BLK = 2;
} else
if ( n >= 17869 && n < 20236 ) {
	BLK = 5;
} else
if ( n >= 20236 && n < 20702 ) {
	BLK = 2;
} else
if ( n >= 20702 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
