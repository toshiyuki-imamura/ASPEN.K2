#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Thu Nov 07 18:30:51  2024
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
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 647 ) {
	BLK = 0;
} else
if ( n >= 647 && n < 650 ) {
	BLK = 2;
} else
if ( n >= 650 && n < 651 ) {
	BLK = 4;
} else
if ( n >= 651 && n < 671 ) {
	BLK = 0;
} else
if ( n >= 671 && n < 672 ) {
	BLK = 2;
} else
if ( n >= 672 && n < 685 ) {
	BLK = 4;
} else
if ( n >= 685 && n < 864 ) {
	BLK = 0;
} else
if ( n >= 864 && n < 889 ) {
	BLK = 4;
} else
if ( n >= 889 && n < 891 ) {
	BLK = 6;
} else
if ( n >= 891 && n < 893 ) {
	BLK = 0;
} else
if ( n >= 893 && n < 938 ) {
	BLK = 2;
} else
if ( n >= 938 && n < 939 ) {
	BLK = 6;
} else
if ( n >= 939 && n < 952 ) {
	BLK = 4;
} else
if ( n >= 952 && n < 971 ) {
	BLK = 2;
} else
if ( n >= 971 && n < 979 ) {
	BLK = 6;
} else
if ( n >= 979 && n < 982 ) {
	BLK = 4;
} else
if ( n >= 982 && n < 1093 ) {
	BLK = 2;
} else
if ( n >= 1093 && n < 2102 ) {
	BLK = 4;
} else
if ( n >= 2102 && n < 2373 ) {
	BLK = 5;
} else
if ( n >= 2373 && n < 7586 ) {
	BLK = 3;
} else
if ( n >= 7586 && n < 8387 ) {
	BLK = 1;
} else
if ( n >= 8387 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
