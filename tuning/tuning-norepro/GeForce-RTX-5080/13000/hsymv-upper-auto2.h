#ifndef HSYMVU_AUTO2_H_INCLUDED
#define HSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVU
 Wed Nov 06 10:53:25  2024
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

if ( n >= 1 && n < 39 ) {
	BLK = 5;
} else
if ( n >= 39 && n < 42 ) {
	BLK = 3;
} else
if ( n >= 42 && n < 2113 ) {
	BLK = 0;
} else
if ( n >= 2113 && n < 3128 ) {
	BLK = 3;
} else
if ( n >= 3128 && n < 3375 ) {
	BLK = 1;
} else
if ( n >= 3375 && n < 4926 ) {
	BLK = 2;
} else
if ( n >= 4926 && n < 7066 ) {
	BLK = 5;
} else
if ( n >= 7066 && n < 10880 ) {
	BLK = 4;
} else
if ( n >= 10880 && n < 11182 ) {
	BLK = 5;
} else
if ( n >= 11182 && n < 13777 ) {
	BLK = 4;
} else
if ( n >= 13777 && n < 20786 ) {
	BLK = 6;
} else
if ( n >= 20786 && n < 26525 ) {
	BLK = 4;
} else
if ( n >= 26525 && n < 2147483647 ) {
	BLK = 6;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 6;
} 

#endif
