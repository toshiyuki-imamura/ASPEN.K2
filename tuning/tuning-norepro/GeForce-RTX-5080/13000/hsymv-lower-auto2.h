#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Fri Nov 08 10:16:36  2024
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
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 15 ) {
	BLK = 0;
} else
if ( n >= 15 && n < 30 ) {
	BLK = 1;
} else
if ( n >= 30 && n < 2361 ) {
	BLK = 0;
} else
if ( n >= 2361 && n < 2386 ) {
	BLK = 4;
} else
if ( n >= 2386 && n < 2489 ) {
	BLK = 2;
} else
if ( n >= 2489 && n < 2518 ) {
	BLK = 0;
} else
if ( n >= 2518 && n < 2710 ) {
	BLK = 3;
} else
if ( n >= 2710 && n < 2760 ) {
	BLK = 2;
} else
if ( n >= 2760 && n < 6682 ) {
	BLK = 1;
} else
if ( n >= 6682 && n < 30178 ) {
	BLK = 3;
} else
if ( n >= 30178 && n < 30531 ) {
	BLK = 6;
} else
if ( n >= 30531 && n < 33187 ) {
	BLK = 3;
} else
if ( n >= 33187 && n < 35730 ) {
	BLK = 6;
} else
if ( n >= 35730 && n < 42891 ) {
	BLK = 3;
} else
if ( n >= 42891 && n < 46746 ) {
	BLK = 6;
} else
if ( n >= 46746 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
