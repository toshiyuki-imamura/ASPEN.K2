#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Sun Nov 16 05:43:20  2025
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

if ( n >= 1 && n < 3 ) {
	BLK = 6;
} else
if ( n >= 3 && n < 8 ) {
	BLK = 3;
} else
if ( n >= 8 && n < 11 ) {
	BLK = 4;
} else
if ( n >= 11 && n < 24 ) {
	BLK = 2;
} else
if ( n >= 24 && n < 223 ) {
	BLK = 6;
} else
if ( n >= 223 && n < 516 ) {
	BLK = 4;
} else
if ( n >= 516 && n < 704 ) {
	BLK = 5;
} else
if ( n >= 704 && n < 3775 ) {
	BLK = 1;
} else
if ( n >= 3775 && n < 3836 ) {
	BLK = 2;
} else
if ( n >= 3836 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
