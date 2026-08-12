#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Wed Nov 19 05:13:32  2025
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


// default kernel is
BLK = 1;

if ( n >= 1 && n < 8 ) {
	BLK = 4;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 16 ) {
	BLK = 3;
} else
if ( n >= 16 && n < 583 ) {
	BLK = 2;
} else
if ( n >= 583 && n < 806 ) {
	BLK = 5;
} else
if ( n >= 806 && n < 807 ) {
	BLK = 2;
} else
if ( n >= 807 && n < 2113 ) {
	BLK = 1;
} else
if ( n >= 2113 && n < 2174 ) {
	BLK = 4;
} else
if ( n >= 2174 && n < 2598 ) {
	BLK = 3;
} else
if ( n >= 2598 && n < 2599 ) {
	BLK = 4;
} else
if ( n >= 2599 && n < 2600 ) {
	BLK = 1;
} else
if ( n >= 2600 && n < 2972 ) {
	BLK = 3;
} else
if ( n >= 2972 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
