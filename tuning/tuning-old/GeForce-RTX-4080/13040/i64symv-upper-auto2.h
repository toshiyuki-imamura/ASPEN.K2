#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Wed Sep 23 04:36:19  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 333 ) {
	BLK = 0;
} else
if ( n >= 333 && n < 377 ) {
	BLK = 5;
} else
if ( n >= 377 && n < 397 ) {
	BLK = 1;
} else
if ( n >= 397 && n < 510 ) {
	BLK = 0;
} else
if ( n >= 510 && n < 527 ) {
	BLK = 3;
} else
if ( n >= 527 && n < 568 ) {
	BLK = 1;
} else
if ( n >= 568 && n < 743 ) {
	BLK = 3;
} else
if ( n >= 743 && n < 744 ) {
	BLK = 0;
} else
if ( n >= 744 && n < 746 ) {
	BLK = 1;
} else
if ( n >= 746 && n < 767 ) {
	BLK = 3;
} else
if ( n >= 767 && n < 832 ) {
	BLK = 0;
} else
if ( n >= 832 && n < 882 ) {
	BLK = 1;
} else
if ( n >= 882 && n < 909 ) {
	BLK = 0;
} else
if ( n >= 909 && n < 992 ) {
	BLK = 3;
} else
if ( n >= 992 && n < 1057 ) {
	BLK = 1;
} else
if ( n >= 1057 && n < 1058 ) {
	BLK = 3;
} else
if ( n >= 1058 && n < 1059 ) {
	BLK = 4;
} else
if ( n >= 1059 && n < 1074 ) {
	BLK = 1;
} else
if ( n >= 1074 && n < 1075 ) {
	BLK = 4;
} else
if ( n >= 1075 && n < 1088 ) {
	BLK = 3;
} else
if ( n >= 1088 && n < 1090 ) {
	BLK = 1;
} else
if ( n >= 1090 && n < 1091 ) {
	BLK = 4;
} else
if ( n >= 1091 && n < 1092 ) {
	BLK = 3;
} else
if ( n >= 1092 && n < 1505 ) {
	BLK = 1;
} else
if ( n >= 1505 && n < 2097 ) {
	BLK = 3;
} else
if ( n >= 2097 && n < 2098 ) {
	BLK = 1;
} else
if ( n >= 2098 && n < 2110 ) {
	BLK = 2;
} else
if ( n >= 2110 && n < 3384 ) {
	BLK = 3;
} else
if ( n >= 3384 && n < 3996 ) {
	BLK = 2;
} else
if ( n >= 3996 && n < 3997 ) {
	BLK = 3;
} else
if ( n >= 3997 && n < 3998 ) {
	BLK = 4;
} else
if ( n >= 3998 && n < 4204 ) {
	BLK = 2;
} else
if ( n >= 4204 && n < 5583 ) {
	BLK = 4;
} else
if ( n >= 5583 && n < 5899 ) {
	BLK = 2;
} else
if ( n >= 5899 && n < 6987 ) {
	BLK = 3;
} else
if ( n >= 6987 && n < 13888 ) {
	BLK = 1;
} else
if ( n >= 13888 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
