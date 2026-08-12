#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Wed Aug 05 21:03:14  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 750 ) {
	BLK = 0;
} else
if ( n >= 750 && n < 2158 ) {
	BLK = 1;
} else
if ( n >= 2158 && n < 2670 ) {
	BLK = 2;
} else
if ( n >= 2670 && n < 4000 ) {
	BLK = 1;
} else
if ( n >= 4000 && n < 6271 ) {
	BLK = 2;
} else
if ( n >= 6271 && n < 7824 ) {
	BLK = 4;
} else
if ( n >= 7824 && n < 12845 ) {
	BLK = 1;
} else
if ( n >= 12845 && n < 17815 ) {
	BLK = 3;
} else
if ( n >= 17815 && n < 18121 ) {
	BLK = 1;
} else
if ( n >= 18121 && n < 21050 ) {
	BLK = 3;
} else
if ( n >= 21050 && n < 21357 ) {
	BLK = 1;
} else
if ( n >= 21357 && n < 23165 ) {
	BLK = 3;
} else
if ( n >= 23165 && n < 23482 ) {
	BLK = 1;
} else
if ( n >= 23482 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
