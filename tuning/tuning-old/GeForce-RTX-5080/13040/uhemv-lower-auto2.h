#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Sun Sep 27 17:26:05  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 1200
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
	BLK = 3;
} else
if ( n >= 9 && n < 19 ) {
	BLK = 4;
} else
if ( n >= 19 && n < 1120 ) {
	BLK = 1;
} else
if ( n >= 1120 && n < 1536 ) {
	BLK = 2;
} else
if ( n >= 1536 && n < 1609 ) {
	BLK = 1;
} else
if ( n >= 1609 && n < 1612 ) {
	BLK = 5;
} else
if ( n >= 1612 && n < 1688 ) {
	BLK = 1;
} else
if ( n >= 1688 && n < 1689 ) {
	BLK = 3;
} else
if ( n >= 1689 && n < 1695 ) {
	BLK = 5;
} else
if ( n >= 1695 && n < 1703 ) {
	BLK = 1;
} else
if ( n >= 1703 && n < 1722 ) {
	BLK = 3;
} else
if ( n >= 1722 && n < 1726 ) {
	BLK = 5;
} else
if ( n >= 1726 && n < 5793 ) {
	BLK = 1;
} else
if ( n >= 5793 && n < 6997 ) {
	BLK = 4;
} else
if ( n >= 6997 && n < 7308 ) {
	BLK = 1;
} else
if ( n >= 7308 && n < 12205 ) {
	BLK = 3;
} else
if ( n >= 12205 && n < 13231 ) {
	BLK = 4;
} else
if ( n >= 13231 && n < 17997 ) {
	BLK = 3;
} else
if ( n >= 17997 && n < 21046 ) {
	BLK = 4;
} else
if ( n >= 21046 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
