#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Fri Nov 08 01:52:50  2024
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

if ( n >= 1 && n < 614 ) {
	BLK = 0;
} else
if ( n >= 614 && n < 764 ) {
	BLK = 5;
} else
if ( n >= 764 && n < 766 ) {
	BLK = 2;
} else
if ( n >= 766 && n < 900 ) {
	BLK = 4;
} else
if ( n >= 900 && n < 1584 ) {
	BLK = 5;
} else
if ( n >= 1584 && n < 1760 ) {
	BLK = 4;
} else
if ( n >= 1760 && n < 2702 ) {
	BLK = 2;
} else
if ( n >= 2702 && n < 4440 ) {
	BLK = 1;
} else
if ( n >= 4440 && n < 4453 ) {
	BLK = 2;
} else
if ( n >= 4453 && n < 6120 ) {
	BLK = 3;
} else
if ( n >= 6120 && n < 6346 ) {
	BLK = 1;
} else
if ( n >= 6346 && n < 6347 ) {
	BLK = 6;
} else
if ( n >= 6347 && n < 6944 ) {
	BLK = 3;
} else
if ( n >= 6944 && n < 7438 ) {
	BLK = 6;
} else
if ( n >= 7438 && n < 8446 ) {
	BLK = 3;
} else
if ( n >= 8446 && n < 10552 ) {
	BLK = 6;
} else
if ( n >= 10552 && n < 10803 ) {
	BLK = 3;
} else
if ( n >= 10803 && n < 10833 ) {
	BLK = 5;
} else
if ( n >= 10833 && n < 11383 ) {
	BLK = 6;
} else
if ( n >= 11383 && n < 11814 ) {
	BLK = 5;
} else
if ( n >= 11814 && n < 12394 ) {
	BLK = 6;
} else
if ( n >= 12394 && n < 12670 ) {
	BLK = 5;
} else
if ( n >= 12670 && n < 14008 ) {
	BLK = 6;
} else
if ( n >= 14008 && n < 14296 ) {
	BLK = 5;
} else
if ( n >= 14296 && n < 16301 ) {
	BLK = 6;
} else
if ( n >= 16301 && n < 18012 ) {
	BLK = 5;
} else
if ( n >= 18012 && n < 20111 ) {
	BLK = 6;
} else
if ( n >= 20111 && n < 20761 ) {
	BLK = 5;
} else
if ( n >= 20761 && n < 26175 ) {
	BLK = 6;
} else
if ( n >= 26175 && n < 26786 ) {
	BLK = 5;
} else
if ( n >= 26786 && n < 30281 ) {
	BLK = 6;
} else
if ( n >= 30281 && n < 31788 ) {
	BLK = 5;
} else
if ( n >= 31788 && n < 34907 ) {
	BLK = 6;
} else
if ( n >= 34907 && n < 37298 ) {
	BLK = 5;
} else
if ( n >= 37298 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
