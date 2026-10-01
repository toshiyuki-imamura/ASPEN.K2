#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Sun Sep 27 10:06:04  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
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

if ( n >= 1 && n < 12 ) {
	BLK = 1;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 2;
} else
if ( n >= 13 && n < 15 ) {
	BLK = 3;
} else
if ( n >= 15 && n < 28 ) {
	BLK = 4;
} else
if ( n >= 28 && n < 35 ) {
	BLK = 3;
} else
if ( n >= 35 && n < 320 ) {
	BLK = 5;
} else
if ( n >= 320 && n < 4425 ) {
	BLK = 1;
} else
if ( n >= 4425 && n < 4430 ) {
	BLK = 3;
} else
if ( n >= 4430 && n < 4433 ) {
	BLK = 4;
} else
if ( n >= 4433 && n < 4456 ) {
	BLK = 1;
} else
if ( n >= 4456 && n < 4501 ) {
	BLK = 3;
} else
if ( n >= 4501 && n < 4509 ) {
	BLK = 4;
} else
if ( n >= 4509 && n < 4515 ) {
	BLK = 1;
} else
if ( n >= 4515 && n < 4616 ) {
	BLK = 3;
} else
if ( n >= 4616 && n < 4622 ) {
	BLK = 1;
} else
if ( n >= 4622 && n < 4629 ) {
	BLK = 4;
} else
if ( n >= 4629 && n < 4806 ) {
	BLK = 3;
} else
if ( n >= 4806 && n < 4814 ) {
	BLK = 1;
} else
if ( n >= 4814 && n < 6154 ) {
	BLK = 4;
} else
if ( n >= 6154 && n < 7234 ) {
	BLK = 3;
} else
if ( n >= 7234 && n < 7263 ) {
	BLK = 2;
} else
if ( n >= 7263 && n < 7554 ) {
	BLK = 4;
} else
if ( n >= 7554 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
