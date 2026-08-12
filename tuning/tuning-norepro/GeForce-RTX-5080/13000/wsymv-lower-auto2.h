#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Thu Nov 07 13:46:00  2024
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-GTX-1080
****************************************/-->
// device name
DEVICE= GeForce-GTX-1080
// the number of multi-processors
MP= 20
// compute-compatibility generation
CG= 610
// capacity of the global memory or host memory
MAXmem= 8497229824
// capacity of the work area reserved on the GPU
WORK= 360960
// for double or cuFloatComplex or int64
MAXDIM= 30961
// for float or cuHalfComplex or int32
MAXDIM2= 43785
// for cuDoubleComplex or DD or int128
MAXDIM3= 21892
// for DD-Complex
MAXDIM4= 15480
// for half or int16
MAXDIM5= 61922
// cuda version
CUDA= 12060
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 610
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 210 ) {
	BLK = 0;
} else
if ( n >= 210 && n < 211 ) {
	BLK = 2;
} else
if ( n >= 211 && n < 216 ) {
	BLK = 3;
} else
if ( n >= 216 && n < 230 ) {
	BLK = 0;
} else
if ( n >= 230 && n < 244 ) {
	BLK = 3;
} else
if ( n >= 244 && n < 282 ) {
	BLK = 2;
} else
if ( n >= 282 && n < 313 ) {
	BLK = 0;
} else
if ( n >= 313 && n < 316 ) {
	BLK = 2;
} else
if ( n >= 316 && n < 318 ) {
	BLK = 1;
} else
if ( n >= 318 && n < 748 ) {
	BLK = 0;
} else
if ( n >= 748 && n < 750 ) {
	BLK = 3;
} else
if ( n >= 750 && n < 752 ) {
	BLK = 2;
} else
if ( n >= 752 && n < 764 ) {
	BLK = 0;
} else
if ( n >= 764 && n < 767 ) {
	BLK = 3;
} else
if ( n >= 767 && n < 768 ) {
	BLK = 2;
} else
if ( n >= 768 && n < 853 ) {
	BLK = 0;
} else
if ( n >= 853 && n < 972 ) {
	BLK = 3;
} else
if ( n >= 972 && n < 975 ) {
	BLK = 0;
} else
if ( n >= 975 && n < 1542 ) {
	BLK = 2;
} else
if ( n >= 1542 && n < 1554 ) {
	BLK = 0;
} else
if ( n >= 1554 && n < 7049 ) {
	BLK = 1;
} else
if ( n >= 7049 && n < 2147483647 ) {
	BLK = 0;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 0;
} 

#endif
