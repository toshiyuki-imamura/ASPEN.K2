#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Thu Sep 24 10:09:13  2026
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

if ( n >= 1 && n < 6 ) {
	BLK = 1;
} else
if ( n >= 6 && n < 26 ) {
	BLK = 2;
} else
if ( n >= 26 && n < 27 ) {
	BLK = 3;
} else
if ( n >= 27 && n < 28 ) {
	BLK = 4;
} else
if ( n >= 28 && n < 30 ) {
	BLK = 2;
} else
if ( n >= 30 && n < 528 ) {
	BLK = 1;
} else
if ( n >= 528 && n < 533 ) {
	BLK = 5;
} else
if ( n >= 533 && n < 603 ) {
	BLK = 1;
} else
if ( n >= 603 && n < 615 ) {
	BLK = 3;
} else
if ( n >= 615 && n < 622 ) {
	BLK = 5;
} else
if ( n >= 622 && n < 677 ) {
	BLK = 4;
} else
if ( n >= 677 && n < 678 ) {
	BLK = 3;
} else
if ( n >= 678 && n < 679 ) {
	BLK = 5;
} else
if ( n >= 679 && n < 738 ) {
	BLK = 4;
} else
if ( n >= 738 && n < 746 ) {
	BLK = 1;
} else
if ( n >= 746 && n < 747 ) {
	BLK = 3;
} else
if ( n >= 747 && n < 748 ) {
	BLK = 5;
} else
if ( n >= 748 && n < 968 ) {
	BLK = 1;
} else
if ( n >= 968 && n < 981 ) {
	BLK = 5;
} else
if ( n >= 981 && n < 983 ) {
	BLK = 4;
} else
if ( n >= 983 && n < 984 ) {
	BLK = 1;
} else
if ( n >= 984 && n < 988 ) {
	BLK = 5;
} else
if ( n >= 988 && n < 989 ) {
	BLK = 1;
} else
if ( n >= 989 && n < 996 ) {
	BLK = 4;
} else
if ( n >= 996 && n < 1014 ) {
	BLK = 5;
} else
if ( n >= 1014 && n < 1064 ) {
	BLK = 4;
} else
if ( n >= 1064 && n < 1629 ) {
	BLK = 5;
} else
if ( n >= 1629 && n < 2128 ) {
	BLK = 4;
} else
if ( n >= 2128 && n < 3221 ) {
	BLK = 3;
} else
if ( n >= 3221 && n < 7104 ) {
	BLK = 2;
} else
if ( n >= 7104 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
