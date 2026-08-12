#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Fri Aug 07 00:35:36  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 494 ) {
	BLK = 0;
} else
if ( n >= 494 && n < 668 ) {
	BLK = 4;
} else
if ( n >= 668 && n < 671 ) {
	BLK = 0;
} else
if ( n >= 671 && n < 676 ) {
	BLK = 2;
} else
if ( n >= 676 && n < 834 ) {
	BLK = 4;
} else
if ( n >= 834 && n < 974 ) {
	BLK = 1;
} else
if ( n >= 974 && n < 995 ) {
	BLK = 0;
} else
if ( n >= 995 && n < 1404 ) {
	BLK = 1;
} else
if ( n >= 1404 && n < 1513 ) {
	BLK = 0;
} else
if ( n >= 1513 && n < 1516 ) {
	BLK = 2;
} else
if ( n >= 1516 && n < 1517 ) {
	BLK = 3;
} else
if ( n >= 1517 && n < 1518 ) {
	BLK = 0;
} else
if ( n >= 1518 && n < 1538 ) {
	BLK = 2;
} else
if ( n >= 1538 && n < 1540 ) {
	BLK = 1;
} else
if ( n >= 1540 && n < 1567 ) {
	BLK = 3;
} else
if ( n >= 1567 && n < 1655 ) {
	BLK = 2;
} else
if ( n >= 1655 && n < 1658 ) {
	BLK = 0;
} else
if ( n >= 1658 && n < 1662 ) {
	BLK = 3;
} else
if ( n >= 1662 && n < 1791 ) {
	BLK = 0;
} else
if ( n >= 1791 && n < 2878 ) {
	BLK = 1;
} else
if ( n >= 2878 && n < 2880 ) {
	BLK = 2;
} else
if ( n >= 2880 && n < 2881 ) {
	BLK = 4;
} else
if ( n >= 2881 && n < 3208 ) {
	BLK = 1;
} else
if ( n >= 3208 && n < 3214 ) {
	BLK = 2;
} else
if ( n >= 3214 && n < 3215 ) {
	BLK = 1;
} else
if ( n >= 3215 && n < 3221 ) {
	BLK = 5;
} else
if ( n >= 3221 && n < 3237 ) {
	BLK = 2;
} else
if ( n >= 3237 && n < 3241 ) {
	BLK = 1;
} else
if ( n >= 3241 && n < 3242 ) {
	BLK = 5;
} else
if ( n >= 3242 && n < 6186 ) {
	BLK = 2;
} else
if ( n >= 6186 && n < 8173 ) {
	BLK = 1;
} else
if ( n >= 8173 && n < 8179 ) {
	BLK = 3;
} else
if ( n >= 8179 && n < 8225 ) {
	BLK = 4;
} else
if ( n >= 8225 && n < 8455 ) {
	BLK = 1;
} else
if ( n >= 8455 && n < 14185 ) {
	BLK = 3;
} else
if ( n >= 14185 && n < 37971 ) {
	BLK = 5;
} else
if ( n >= 37971 && n < 38697 ) {
	BLK = 3;
} else
if ( n >= 38697 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
