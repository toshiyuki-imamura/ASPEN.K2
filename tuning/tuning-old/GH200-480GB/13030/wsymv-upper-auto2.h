#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Tue Sep 29 12:46:44  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3 ) {
	BLK = 1;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 3;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 2;
} else
if ( n >= 5 && n < 6 ) {
	BLK = 1;
} else
if ( n >= 6 && n < 7 ) {
	BLK = 3;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 10 ) {
	BLK = 4;
} else
if ( n >= 10 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 17 ) {
	BLK = 1;
} else
if ( n >= 17 && n < 24 ) {
	BLK = 4;
} else
if ( n >= 24 && n < 2112 ) {
	BLK = 0;
} else
if ( n >= 2112 && n < 2142 ) {
	BLK = 5;
} else
if ( n >= 2142 && n < 4745 ) {
	BLK = 2;
} else
if ( n >= 4745 && n < 41331 ) {
	BLK = 1;
} else
if ( n >= 41331 && n < 42819 ) {
	BLK = 4;
} else
if ( n >= 42819 && n < 52006 ) {
	BLK = 1;
} else
if ( n >= 52006 && n < 53619 ) {
	BLK = 4;
} else
if ( n >= 53619 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
