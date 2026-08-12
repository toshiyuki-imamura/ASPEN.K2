#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Thu Nov 13 04:09:37  2025
 Host on shannon.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16585474048
// capacity of the work area reserved on the GPU
WORK= 504832
// for double or cuFloatComplex or int64
MAXDIM= 43255
// for float or cuHalfComplex or int32
MAXDIM2= 61172
// for cuDoubleComplex or DD or int128
MAXDIM3= 30586
// for DD-Complex
MAXDIM4= 21627
// for half or int16
MAXDIM5= 86511
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 1200
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 2;
} else
if ( n >= 2 && n < 4 ) {
	BLK = 5;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 3;
} else
if ( n >= 5 && n < 12 ) {
	BLK = 2;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 1;
} else
if ( n >= 13 && n < 16 ) {
	BLK = 5;
} else
if ( n >= 16 && n < 19 ) {
	BLK = 2;
} else
if ( n >= 19 && n < 20 ) {
	BLK = 1;
} else
if ( n >= 20 && n < 22 ) {
	BLK = 4;
} else
if ( n >= 22 && n < 24 ) {
	BLK = 2;
} else
if ( n >= 24 && n < 528 ) {
	BLK = 3;
} else
if ( n >= 528 && n < 707 ) {
	BLK = 6;
} else
if ( n >= 707 && n < 797 ) {
	BLK = 5;
} else
if ( n >= 797 && n < 3011 ) {
	BLK = 1;
} else
if ( n >= 3011 && n < 4756 ) {
	BLK = 2;
} else
if ( n >= 4756 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
