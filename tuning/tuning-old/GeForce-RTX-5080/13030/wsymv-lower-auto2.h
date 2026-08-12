#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Thu Aug 06 20:11:59  2026
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

if ( n >= 1 && n < 7 ) {
	BLK = 5;
} else
if ( n >= 7 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 17 ) {
	BLK = 5;
} else
if ( n >= 17 && n < 320 ) {
	BLK = 4;
} else
if ( n >= 320 && n < 896 ) {
	BLK = 1;
} else
if ( n >= 896 && n < 1920 ) {
	BLK = 4;
} else
if ( n >= 1920 && n < 4423 ) {
	BLK = 1;
} else
if ( n >= 4423 && n < 5902 ) {
	BLK = 3;
} else
if ( n >= 5902 && n < 6022 ) {
	BLK = 1;
} else
if ( n >= 6022 && n < 8667 ) {
	BLK = 2;
} else
if ( n >= 8667 && n < 9688 ) {
	BLK = 5;
} else
if ( n >= 9688 && n < 9807 ) {
	BLK = 1;
} else
if ( n >= 9807 && n < 9849 ) {
	BLK = 3;
} else
if ( n >= 9849 && n < 9888 ) {
	BLK = 5;
} else
if ( n >= 9888 && n < 12874 ) {
	BLK = 1;
} else
if ( n >= 12874 && n < 17312 ) {
	BLK = 2;
} else
if ( n >= 17312 && n < 19347 ) {
	BLK = 5;
} else
if ( n >= 19347 && n < 25777 ) {
	BLK = 2;
} else
if ( n >= 25777 && n < 26772 ) {
	BLK = 5;
} else
if ( n >= 26772 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
