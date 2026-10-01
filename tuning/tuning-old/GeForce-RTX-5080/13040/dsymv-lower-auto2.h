#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Sat Sep 26 15:57:12  2026
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
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 12 ) {
	BLK = 0;
} else
if ( n >= 12 && n < 16 ) {
	BLK = 1;
} else
if ( n >= 16 && n < 25 ) {
	BLK = 3;
} else
if ( n >= 25 && n < 244 ) {
	BLK = 1;
} else
if ( n >= 244 && n < 2829 ) {
	BLK = 0;
} else
if ( n >= 2829 && n < 2860 ) {
	BLK = 4;
} else
if ( n >= 2860 && n < 2861 ) {
	BLK = 3;
} else
if ( n >= 2861 && n < 2909 ) {
	BLK = 0;
} else
if ( n >= 2909 && n < 2910 ) {
	BLK = 4;
} else
if ( n >= 2910 && n < 2913 ) {
	BLK = 3;
} else
if ( n >= 2913 && n < 2922 ) {
	BLK = 0;
} else
if ( n >= 2922 && n < 2923 ) {
	BLK = 3;
} else
if ( n >= 2923 && n < 2927 ) {
	BLK = 4;
} else
if ( n >= 2927 && n < 2939 ) {
	BLK = 0;
} else
if ( n >= 2939 && n < 2968 ) {
	BLK = 3;
} else
if ( n >= 2968 && n < 2969 ) {
	BLK = 0;
} else
if ( n >= 2969 && n < 2970 ) {
	BLK = 4;
} else
if ( n >= 2970 && n < 2971 ) {
	BLK = 3;
} else
if ( n >= 2971 && n < 2973 ) {
	BLK = 0;
} else
if ( n >= 2973 && n < 3016 ) {
	BLK = 4;
} else
if ( n >= 3016 && n < 3968 ) {
	BLK = 3;
} else
if ( n >= 3968 && n < 6272 ) {
	BLK = 2;
} else
if ( n >= 6272 && n < 7149 ) {
	BLK = 4;
} else
if ( n >= 7149 && n < 11968 ) {
	BLK = 3;
} else
if ( n >= 11968 && n < 21025 ) {
	BLK = 1;
} else
if ( n >= 21025 && n < 21558 ) {
	BLK = 3;
} else
if ( n >= 21558 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
