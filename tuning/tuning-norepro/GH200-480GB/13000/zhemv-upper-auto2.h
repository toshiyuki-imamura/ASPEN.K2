#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Wed Nov 19 16:05:07  2025
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

if ( n >= 1 && n < 5 ) {
	BLK = 1;
} else
if ( n >= 5 && n < 7 ) {
	BLK = 6;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 3;
} else
if ( n >= 9 && n < 13 ) {
	BLK = 1;
} else
if ( n >= 13 && n < 16 ) {
	BLK = 3;
} else
if ( n >= 16 && n < 29 ) {
	BLK = 1;
} else
if ( n >= 29 && n < 411 ) {
	BLK = 4;
} else
if ( n >= 411 && n < 414 ) {
	BLK = 5;
} else
if ( n >= 414 && n < 415 ) {
	BLK = 3;
} else
if ( n >= 415 && n < 416 ) {
	BLK = 4;
} else
if ( n >= 416 && n < 444 ) {
	BLK = 5;
} else
if ( n >= 444 && n < 445 ) {
	BLK = 4;
} else
if ( n >= 445 && n < 1112 ) {
	BLK = 3;
} else
if ( n >= 1112 && n < 1920 ) {
	BLK = 2;
} else
if ( n >= 1920 && n < 2030 ) {
	BLK = 1;
} else
if ( n >= 2030 && n < 2031 ) {
	BLK = 3;
} else
if ( n >= 2031 && n < 2032 ) {
	BLK = 2;
} else
if ( n >= 2032 && n < 2038 ) {
	BLK = 1;
} else
if ( n >= 2038 && n < 2039 ) {
	BLK = 3;
} else
if ( n >= 2039 && n < 2938 ) {
	BLK = 2;
} else
if ( n >= 2938 && n < 5638 ) {
	BLK = 1;
} else
if ( n >= 5638 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
