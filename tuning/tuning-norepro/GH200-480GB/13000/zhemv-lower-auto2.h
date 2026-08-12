#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Fri Nov 21 08:47:22  2025
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
	BLK = 1;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 2;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 3;
} else
if ( n >= 4 && n < 14 ) {
	BLK = 1;
} else
if ( n >= 14 && n < 15 ) {
	BLK = 6;
} else
if ( n >= 15 && n < 19 ) {
	BLK = 2;
} else
if ( n >= 19 && n < 20 ) {
	BLK = 3;
} else
if ( n >= 20 && n < 21 ) {
	BLK = 6;
} else
if ( n >= 21 && n < 24 ) {
	BLK = 1;
} else
if ( n >= 24 && n < 31 ) {
	BLK = 6;
} else
if ( n >= 31 && n < 519 ) {
	BLK = 4;
} else
if ( n >= 519 && n < 1403 ) {
	BLK = 3;
} else
if ( n >= 1403 && n < 1984 ) {
	BLK = 2;
} else
if ( n >= 1984 && n < 4834 ) {
	BLK = 1;
} else
if ( n >= 4834 && n < 5819 ) {
	BLK = 2;
} else
if ( n >= 5819 && n < 5822 ) {
	BLK = 1;
} else
if ( n >= 5822 && n < 5847 ) {
	BLK = 5;
} else
if ( n >= 5847 && n < 5861 ) {
	BLK = 2;
} else
if ( n >= 5861 && n < 6028 ) {
	BLK = 1;
} else
if ( n >= 6028 && n < 6050 ) {
	BLK = 2;
} else
if ( n >= 6050 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
