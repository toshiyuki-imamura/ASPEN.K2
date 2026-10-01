#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Tue Sep 22 15:57:19  2026
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16800759808
// capacity of the work area reserved on the GPU
WORK= 2539520
// for double or cuFloatComplex or int64
MAXDIM= 43535
// for float or cuHalfComplex or int32
MAXDIM2= 61568
// for cuDoubleComplex or DD or int128
MAXDIM3= 30784
// for DD-Complex
MAXDIM4= 21767
// for half or int16
MAXDIM5= 87070
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 9 ) {
	BLK = 2;
} else
if ( n >= 9 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 12 ) {
	BLK = 4;
} else
if ( n >= 12 && n < 32 ) {
	BLK = 2;
} else
if ( n >= 32 && n < 603 ) {
	BLK = 3;
} else
if ( n >= 603 && n < 612 ) {
	BLK = 5;
} else
if ( n >= 612 && n < 614 ) {
	BLK = 1;
} else
if ( n >= 614 && n < 618 ) {
	BLK = 3;
} else
if ( n >= 618 && n < 676 ) {
	BLK = 1;
} else
if ( n >= 676 && n < 1860 ) {
	BLK = 3;
} else
if ( n >= 1860 && n < 4353 ) {
	BLK = 1;
} else
if ( n >= 4353 && n < 5589 ) {
	BLK = 2;
} else
if ( n >= 5589 && n < 8568 ) {
	BLK = 1;
} else
if ( n >= 8568 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
