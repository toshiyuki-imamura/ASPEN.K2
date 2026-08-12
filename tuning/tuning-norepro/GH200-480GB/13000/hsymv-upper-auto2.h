#ifndef HSYMVU_AUTO2_H_INCLUDED
#define HSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVU
 Fri Nov 14 06:43:05  2025
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
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 8327 ) {
	BLK = 0;
} else
if ( n >= 8327 && n < 9638 ) {
	BLK = 3;
} else
if ( n >= 9638 && n < 9959 ) {
	BLK = 4;
} else
if ( n >= 9959 && n < 10223 ) {
	BLK = 3;
} else
if ( n >= 10223 && n < 13575 ) {
	BLK = 4;
} else
if ( n >= 13575 && n < 20033 ) {
	BLK = 3;
} else
if ( n >= 20033 && n < 20478 ) {
	BLK = 4;
} else
if ( n >= 20478 && n < 20737 ) {
	BLK = 3;
} else
if ( n >= 20737 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
