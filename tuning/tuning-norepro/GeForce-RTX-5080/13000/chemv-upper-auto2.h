#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Sat Nov 09 20:17:35  2024
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
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 984 ) {
	BLK = 0;
} else
if ( n >= 984 && n < 1214 ) {
	BLK = 5;
} else
if ( n >= 1214 && n < 4811 ) {
	BLK = 2;
} else
if ( n >= 4811 && n < 5827 ) {
	BLK = 1;
} else
if ( n >= 5827 && n < 7532 ) {
	BLK = 2;
} else
if ( n >= 7532 && n < 7958 ) {
	BLK = 1;
} else
if ( n >= 7958 && n < 8085 ) {
	BLK = 6;
} else
if ( n >= 8085 && n < 8220 ) {
	BLK = 2;
} else
if ( n >= 8220 && n < 8433 ) {
	BLK = 1;
} else
if ( n >= 8433 && n < 8696 ) {
	BLK = 6;
} else
if ( n >= 8696 && n < 9656 ) {
	BLK = 2;
} else
if ( n >= 9656 && n < 11707 ) {
	BLK = 6;
} else
if ( n >= 11707 && n < 11819 ) {
	BLK = 1;
} else
if ( n >= 11819 && n < 11881 ) {
	BLK = 4;
} else
if ( n >= 11881 && n < 12487 ) {
	BLK = 6;
} else
if ( n >= 12487 && n < 12777 ) {
	BLK = 2;
} else
if ( n >= 12777 && n < 20681 ) {
	BLK = 6;
} else
if ( n >= 20681 && n < 21782 ) {
	BLK = 2;
} else
if ( n >= 21782 && n < 23670 ) {
	BLK = 6;
} else
if ( n >= 23670 && n < 24351 ) {
	BLK = 2;
} else
if ( n >= 24351 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
