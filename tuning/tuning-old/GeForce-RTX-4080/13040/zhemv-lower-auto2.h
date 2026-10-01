#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Thu Sep 24 20:20:36  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 24 ) {
	BLK = 1;
} else
if ( n >= 24 && n < 396 ) {
	BLK = 2;
} else
if ( n >= 396 && n < 684 ) {
	BLK = 5;
} else
if ( n >= 684 && n < 704 ) {
	BLK = 3;
} else
if ( n >= 704 && n < 706 ) {
	BLK = 2;
} else
if ( n >= 706 && n < 707 ) {
	BLK = 1;
} else
if ( n >= 707 && n < 720 ) {
	BLK = 5;
} else
if ( n >= 720 && n < 736 ) {
	BLK = 3;
} else
if ( n >= 736 && n < 737 ) {
	BLK = 2;
} else
if ( n >= 737 && n < 746 ) {
	BLK = 5;
} else
if ( n >= 746 && n < 747 ) {
	BLK = 3;
} else
if ( n >= 747 && n < 750 ) {
	BLK = 2;
} else
if ( n >= 750 && n < 759 ) {
	BLK = 5;
} else
if ( n >= 759 && n < 760 ) {
	BLK = 2;
} else
if ( n >= 760 && n < 761 ) {
	BLK = 3;
} else
if ( n >= 761 && n < 767 ) {
	BLK = 5;
} else
if ( n >= 767 && n < 783 ) {
	BLK = 3;
} else
if ( n >= 783 && n < 792 ) {
	BLK = 1;
} else
if ( n >= 792 && n < 793 ) {
	BLK = 5;
} else
if ( n >= 793 && n < 797 ) {
	BLK = 3;
} else
if ( n >= 797 && n < 805 ) {
	BLK = 1;
} else
if ( n >= 805 && n < 827 ) {
	BLK = 3;
} else
if ( n >= 827 && n < 866 ) {
	BLK = 5;
} else
if ( n >= 866 && n < 878 ) {
	BLK = 2;
} else
if ( n >= 878 && n < 880 ) {
	BLK = 5;
} else
if ( n >= 880 && n < 883 ) {
	BLK = 3;
} else
if ( n >= 883 && n < 884 ) {
	BLK = 2;
} else
if ( n >= 884 && n < 885 ) {
	BLK = 5;
} else
if ( n >= 885 && n < 977 ) {
	BLK = 3;
} else
if ( n >= 977 && n < 990 ) {
	BLK = 2;
} else
if ( n >= 990 && n < 992 ) {
	BLK = 1;
} else
if ( n >= 992 && n < 1003 ) {
	BLK = 3;
} else
if ( n >= 1003 && n < 1119 ) {
	BLK = 2;
} else
if ( n >= 1119 && n < 1137 ) {
	BLK = 1;
} else
if ( n >= 1137 && n < 1141 ) {
	BLK = 5;
} else
if ( n >= 1141 && n < 1148 ) {
	BLK = 1;
} else
if ( n >= 1148 && n < 1395 ) {
	BLK = 5;
} else
if ( n >= 1395 && n < 3146 ) {
	BLK = 3;
} else
if ( n >= 3146 && n < 4992 ) {
	BLK = 1;
} else
if ( n >= 4992 && n < 8083 ) {
	BLK = 3;
} else
if ( n >= 8083 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
