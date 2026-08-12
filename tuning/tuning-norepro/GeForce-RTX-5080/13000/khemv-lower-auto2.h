#ifndef KHEMVL_AUTO2_H_INCLUDED
#define KHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVL
 Sun Nov 10 20:20:25  2024
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 18 ) {
	BLK = 4;
} else
if ( n >= 18 && n < 30 ) {
	BLK = 2;
} else
if ( n >= 30 && n < 1475 ) {
	BLK = 0;
} else
if ( n >= 1475 && n < 1959 ) {
	BLK = 2;
} else
if ( n >= 1959 && n < 2910 ) {
	BLK = 1;
} else
if ( n >= 2910 && n < 3388 ) {
	BLK = 2;
} else
if ( n >= 3388 && n < 3822 ) {
	BLK = 1;
} else
if ( n >= 3822 && n < 4069 ) {
	BLK = 2;
} else
if ( n >= 4069 && n < 4950 ) {
	BLK = 4;
} else
if ( n >= 4950 && n < 5902 ) {
	BLK = 1;
} else
if ( n >= 5902 && n < 8395 ) {
	BLK = 4;
} else
if ( n >= 8395 && n < 10963 ) {
	BLK = 3;
} else
if ( n >= 10963 && n < 13850 ) {
	BLK = 5;
} else
if ( n >= 13850 && n < 15481 ) {
	BLK = 4;
} else
if ( n >= 15481 && n < 21853 ) {
	BLK = 3;
} else
if ( n >= 21853 && n < 24740 ) {
	BLK = 5;
} else
if ( n >= 24740 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
