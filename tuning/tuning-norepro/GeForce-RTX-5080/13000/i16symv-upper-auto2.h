#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Thu Nov 07 09:42:57  2024
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
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 15 ) {
	BLK = 0;
} else
if ( n >= 15 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 45 ) {
	BLK = 3;
} else
if ( n >= 45 && n < 58 ) {
	BLK = 2;
} else
if ( n >= 58 && n < 999 ) {
	BLK = 0;
} else
if ( n >= 999 && n < 2078 ) {
	BLK = 3;
} else
if ( n >= 2078 && n < 2107 ) {
	BLK = 5;
} else
if ( n >= 2107 && n < 2122 ) {
	BLK = 2;
} else
if ( n >= 2122 && n < 2178 ) {
	BLK = 3;
} else
if ( n >= 2178 && n < 2373 ) {
	BLK = 5;
} else
if ( n >= 2373 && n < 2379 ) {
	BLK = 3;
} else
if ( n >= 2379 && n < 4070 ) {
	BLK = 2;
} else
if ( n >= 4070 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
