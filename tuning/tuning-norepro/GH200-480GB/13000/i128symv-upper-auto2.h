#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Fri Nov 14 16:20:06  2025
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

if ( n >= 1 && n < 32 ) {
	BLK = 2;
} else
if ( n >= 32 && n < 495 ) {
	BLK = 5;
} else
if ( n >= 495 && n < 1312 ) {
	BLK = 2;
} else
if ( n >= 1312 && n < 1631 ) {
	BLK = 4;
} else
if ( n >= 1631 && n < 2928 ) {
	BLK = 3;
} else
if ( n >= 2928 && n < 5441 ) {
	BLK = 1;
} else
if ( n >= 5441 && n < 9922 ) {
	BLK = 6;
} else
if ( n >= 9922 && n < 10898 ) {
	BLK = 1;
} else
if ( n >= 10898 && n < 11810 ) {
	BLK = 6;
} else
if ( n >= 11810 && n < 12721 ) {
	BLK = 1;
} else
if ( n >= 12721 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
