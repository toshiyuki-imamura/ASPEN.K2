#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Mon Nov 17 02:07:23  2025
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
#define	KERNEL_2	1
#define	KERNEL_4	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5998 ) {
	BLK = 0;
} else
if ( n >= 5998 && n < 13585 ) {
	BLK = 4;
} else
if ( n >= 13585 && n < 19878 ) {
	BLK = 6;
} else
if ( n >= 19878 && n < 20428 ) {
	BLK = 2;
} else
if ( n >= 20428 && n < 20708 ) {
	BLK = 4;
} else
if ( n >= 20708 && n < 29926 ) {
	BLK = 2;
} else
if ( n >= 29926 && n < 30500 ) {
	BLK = 6;
} else
if ( n >= 30500 && n < 36417 ) {
	BLK = 2;
} else
if ( n >= 36417 && n < 37717 ) {
	BLK = 6;
} else
if ( n >= 37717 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
