#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Mon Nov 17 07:50:27  2025
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5938 ) {
	BLK = 0;
} else
if ( n >= 5938 && n < 8072 ) {
	BLK = 3;
} else
if ( n >= 8072 && n < 10039 ) {
	BLK = 2;
} else
if ( n >= 10039 && n < 11239 ) {
	BLK = 1;
} else
if ( n >= 11239 && n < 11288 ) {
	BLK = 2;
} else
if ( n >= 11288 && n < 11323 ) {
	BLK = 3;
} else
if ( n >= 11323 && n < 15569 ) {
	BLK = 1;
} else
if ( n >= 15569 && n < 17120 ) {
	BLK = 3;
} else
if ( n >= 17120 && n < 17393 ) {
	BLK = 1;
} else
if ( n >= 17393 && n < 17927 ) {
	BLK = 3;
} else
if ( n >= 17927 && n < 19132 ) {
	BLK = 1;
} else
if ( n >= 19132 && n < 19480 ) {
	BLK = 3;
} else
if ( n >= 19480 && n < 20374 ) {
	BLK = 1;
} else
if ( n >= 20374 && n < 22578 ) {
	BLK = 3;
} else
if ( n >= 22578 && n < 23909 ) {
	BLK = 1;
} else
if ( n >= 23909 && n < 31333 ) {
	BLK = 3;
} else
if ( n >= 31333 && n < 31852 ) {
	BLK = 1;
} else
if ( n >= 31852 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
