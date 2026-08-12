#ifndef KHEMVU_AUTO2_H_INCLUDED
#define KHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVU
 Sun Nov 10 03:08:26  2024
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
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 7 ) {
	BLK = 1;
} else
if ( n >= 7 && n < 18 ) {
	BLK = 6;
} else
if ( n >= 18 && n < 20 ) {
	BLK = 3;
} else
if ( n >= 20 && n < 22 ) {
	BLK = 2;
} else
if ( n >= 22 && n < 38 ) {
	BLK = 6;
} else
if ( n >= 38 && n < 154 ) {
	BLK = 0;
} else
if ( n >= 154 && n < 2835 ) {
	BLK = 1;
} else
if ( n >= 2835 && n < 4311 ) {
	BLK = 2;
} else
if ( n >= 4311 && n < 10362 ) {
	BLK = 1;
} else
if ( n >= 10362 && n < 10639 ) {
	BLK = 5;
} else
if ( n >= 10639 && n < 17764 ) {
	BLK = 1;
} else
if ( n >= 17764 && n < 18223 ) {
	BLK = 5;
} else
if ( n >= 18223 && n < 19594 ) {
	BLK = 1;
} else
if ( n >= 19594 && n < 20227 ) {
	BLK = 5;
} else
if ( n >= 20227 && n < 27799 ) {
	BLK = 1;
} else
if ( n >= 27799 && n < 28916 ) {
	BLK = 5;
} else
if ( n >= 28916 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
