#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Sat Aug 08 12:53:13  2026
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

if ( n >= 1 && n < 3 ) {
	BLK = 1;
} else
if ( n >= 3 && n < 7 ) {
	BLK = 5;
} else
if ( n >= 7 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 16 ) {
	BLK = 4;
} else
if ( n >= 16 && n < 4311 ) {
	BLK = 1;
} else
if ( n >= 4311 && n < 4312 ) {
	BLK = 3;
} else
if ( n >= 4312 && n < 4315 ) {
	BLK = 2;
} else
if ( n >= 4315 && n < 4473 ) {
	BLK = 1;
} else
if ( n >= 4473 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
