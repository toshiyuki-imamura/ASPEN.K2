#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Mon Jul 27 07:12:50  2026
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16743747584
// capacity of the work area reserved on the GPU
WORK= 2534400
// for double or cuFloatComplex or int64
MAXDIM= 43461
// for float or cuHalfComplex or int32
MAXDIM2= 61463
// for cuDoubleComplex or DD or int128
MAXDIM3= 30731
// for DD-Complex
MAXDIM4= 21730
// for half or int16
MAXDIM5= 86923
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 66 ) {
	BLK = 0;
} else
if ( n >= 66 && n < 67 ) {
	BLK = 3;
} else
if ( n >= 67 && n < 75 ) {
	BLK = 2;
} else
if ( n >= 75 && n < 2345 ) {
	BLK = 0;
} else
if ( n >= 2345 && n < 2352 ) {
	BLK = 2;
} else
if ( n >= 2352 && n < 2353 ) {
	BLK = 3;
} else
if ( n >= 2353 && n < 2779 ) {
	BLK = 0;
} else
if ( n >= 2779 && n < 2875 ) {
	BLK = 2;
} else
if ( n >= 2875 && n < 4210 ) {
	BLK = 0;
} else
if ( n >= 4210 && n < 6428 ) {
	BLK = 3;
} else
if ( n >= 6428 && n < 10867 ) {
	BLK = 2;
} else
if ( n >= 10867 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
