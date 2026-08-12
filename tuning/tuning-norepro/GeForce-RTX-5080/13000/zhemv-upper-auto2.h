#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Sat Nov 09 15:48:47  2024
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

if ( n >= 1 && n < 2 ) {
	BLK = 0;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 3;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 2;
} else
if ( n >= 4 && n < 795 ) {
	BLK = 0;
} else
if ( n >= 795 && n < 2076 ) {
	BLK = 2;
} else
if ( n >= 2076 && n < 2097 ) {
	BLK = 3;
} else
if ( n >= 2097 && n < 2257 ) {
	BLK = 5;
} else
if ( n >= 2257 && n < 2303 ) {
	BLK = 3;
} else
if ( n >= 2303 && n < 2369 ) {
	BLK = 2;
} else
if ( n >= 2369 && n < 2382 ) {
	BLK = 5;
} else
if ( n >= 2382 && n < 3181 ) {
	BLK = 3;
} else
if ( n >= 3181 && n < 3923 ) {
	BLK = 1;
} else
if ( n >= 3923 && n < 4476 ) {
	BLK = 4;
} else
if ( n >= 4476 && n < 4676 ) {
	BLK = 3;
} else
if ( n >= 4676 && n < 5686 ) {
	BLK = 1;
} else
if ( n >= 5686 && n < 5780 ) {
	BLK = 4;
} else
if ( n >= 5780 && n < 6603 ) {
	BLK = 3;
} else
if ( n >= 6603 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
