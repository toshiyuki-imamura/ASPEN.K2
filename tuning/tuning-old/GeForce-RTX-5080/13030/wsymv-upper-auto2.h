#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Wed Aug 05 16:38:06  2026
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
MAXmem= 16647024640
// capacity of the work area reserved on the GPU
WORK= 2526720
// for double or cuFloatComplex or int64
MAXDIM= 43335
// for float or cuHalfComplex or int32
MAXDIM2= 61286
// for cuDoubleComplex or DD or int128
MAXDIM3= 30643
// for DD-Complex
MAXDIM4= 21667
// for half or int16
MAXDIM5= 86671
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
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

if ( n >= 1 && n < 2 ) {
	BLK = 1;
} else
if ( n >= 2 && n < 21 ) {
	BLK = 4;
} else
if ( n >= 21 && n < 320 ) {
	BLK = 5;
} else
if ( n >= 320 && n < 905 ) {
	BLK = 1;
} else
if ( n >= 905 && n < 2056 ) {
	BLK = 5;
} else
if ( n >= 2056 && n < 3592 ) {
	BLK = 1;
} else
if ( n >= 3592 && n < 4983 ) {
	BLK = 2;
} else
if ( n >= 4983 && n < 6609 ) {
	BLK = 1;
} else
if ( n >= 6609 && n < 7495 ) {
	BLK = 2;
} else
if ( n >= 7495 && n < 9700 ) {
	BLK = 3;
} else
if ( n >= 9700 && n < 10863 ) {
	BLK = 4;
} else
if ( n >= 10863 && n < 15832 ) {
	BLK = 2;
} else
if ( n >= 15832 && n < 16447 ) {
	BLK = 3;
} else
if ( n >= 16447 && n < 17318 ) {
	BLK = 2;
} else
if ( n >= 17318 && n < 17892 ) {
	BLK = 3;
} else
if ( n >= 17892 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
