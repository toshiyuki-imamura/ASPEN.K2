#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Tue Sep 29 14:15:08  2026
 Host on qc-gh200-02.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 102123945984
// capacity of the work area reserved on the GPU
WORK= 8140288
// for double or cuFloatComplex or int64
MAXDIM= 107335
// for float or cuHalfComplex or int32
MAXDIM2= 151794
// for cuDoubleComplex or DD or int128
MAXDIM3= 75897
// for DD-Complex
MAXDIM4= 53667
// for half or int16
MAXDIM5= 214670
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2876 ) {
	BLK = 0;
} else
if ( n >= 2876 && n < 2877 ) {
	BLK = 2;
} else
if ( n >= 2877 && n < 2878 ) {
	BLK = 5;
} else
if ( n >= 2878 && n < 2892 ) {
	BLK = 0;
} else
if ( n >= 2892 && n < 2893 ) {
	BLK = 5;
} else
if ( n >= 2893 && n < 2894 ) {
	BLK = 2;
} else
if ( n >= 2894 && n < 2897 ) {
	BLK = 0;
} else
if ( n >= 2897 && n < 2907 ) {
	BLK = 5;
} else
if ( n >= 2907 && n < 2908 ) {
	BLK = 2;
} else
if ( n >= 2908 && n < 2909 ) {
	BLK = 0;
} else
if ( n >= 2909 && n < 2914 ) {
	BLK = 5;
} else
if ( n >= 2914 && n < 2919 ) {
	BLK = 2;
} else
if ( n >= 2919 && n < 2920 ) {
	BLK = 0;
} else
if ( n >= 2920 && n < 2931 ) {
	BLK = 5;
} else
if ( n >= 2931 && n < 2932 ) {
	BLK = 0;
} else
if ( n >= 2932 && n < 2943 ) {
	BLK = 2;
} else
if ( n >= 2943 && n < 2950 ) {
	BLK = 0;
} else
if ( n >= 2950 && n < 6570 ) {
	BLK = 2;
} else
if ( n >= 6570 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
