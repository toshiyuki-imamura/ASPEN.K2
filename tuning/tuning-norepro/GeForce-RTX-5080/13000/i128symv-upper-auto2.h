#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Wed Nov 06 14:26:17  2024
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

if ( n >= 1 && n < 1194 ) {
	BLK = 0;
} else
if ( n >= 1194 && n < 1961 ) {
	BLK = 3;
} else
if ( n >= 1961 && n < 4005 ) {
	BLK = 1;
} else
if ( n >= 4005 && n < 4698 ) {
	BLK = 2;
} else
if ( n >= 4698 && n < 11760 ) {
	BLK = 1;
} else
if ( n >= 11760 && n < 12037 ) {
	BLK = 2;
} else
if ( n >= 12037 && n < 12998 ) {
	BLK = 1;
} else
if ( n >= 12998 && n < 13647 ) {
	BLK = 2;
} else
if ( n >= 13647 && n < 18796 ) {
	BLK = 1;
} else
if ( n >= 18796 && n < 19495 ) {
	BLK = 2;
} else
if ( n >= 19495 && n < 20373 ) {
	BLK = 1;
} else
if ( n >= 20373 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
