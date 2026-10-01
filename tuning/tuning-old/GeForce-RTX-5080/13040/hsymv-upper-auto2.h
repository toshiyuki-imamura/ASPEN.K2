#ifndef HSYMVU_AUTO2_H_INCLUDED
#define HSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVU
 Sat Sep 26 01:00:54  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2078 ) {
	BLK = 0;
} else
if ( n >= 2078 && n < 2181 ) {
	BLK = 2;
} else
if ( n >= 2181 && n < 3895 ) {
	BLK = 0;
} else
if ( n >= 3895 && n < 5023 ) {
	BLK = 3;
} else
if ( n >= 5023 && n < 7776 ) {
	BLK = 1;
} else
if ( n >= 7776 && n < 15309 ) {
	BLK = 2;
} else
if ( n >= 15309 && n < 54792 ) {
	BLK = 1;
} else
if ( n >= 54792 && n < 55181 ) {
	BLK = 5;
} else
if ( n >= 55181 && n < 70460 ) {
	BLK = 1;
} else
if ( n >= 70460 && n < 75665 ) {
	BLK = 5;
} else
if ( n >= 75665 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
