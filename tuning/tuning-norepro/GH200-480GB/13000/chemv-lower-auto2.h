#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Fri Nov 21 20:34:12  2025
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
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 4187 ) {
	BLK = 0;
} else
if ( n >= 4187 && n < 6675 ) {
	BLK = 3;
} else
if ( n >= 6675 && n < 10001 ) {
	BLK = 4;
} else
if ( n >= 10001 && n < 11408 ) {
	BLK = 3;
} else
if ( n >= 11408 && n < 11722 ) {
	BLK = 4;
} else
if ( n >= 11722 && n < 12605 ) {
	BLK = 3;
} else
if ( n >= 12605 && n < 12865 ) {
	BLK = 4;
} else
if ( n >= 12865 && n < 19525 ) {
	BLK = 3;
} else
if ( n >= 19525 && n < 19594 ) {
	BLK = 4;
} else
if ( n >= 19594 && n < 19669 ) {
	BLK = 1;
} else
if ( n >= 19669 && n < 23913 ) {
	BLK = 3;
} else
if ( n >= 23913 && n < 24444 ) {
	BLK = 4;
} else
if ( n >= 24444 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
