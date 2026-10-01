#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Thu Sep 24 13:13:21  2026
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

if ( n >= 1 && n < 513 ) {
	BLK = 0;
} else
if ( n >= 513 && n < 538 ) {
	BLK = 5;
} else
if ( n >= 538 && n < 543 ) {
	BLK = 1;
} else
if ( n >= 543 && n < 573 ) {
	BLK = 0;
} else
if ( n >= 573 && n < 574 ) {
	BLK = 1;
} else
if ( n >= 574 && n < 575 ) {
	BLK = 5;
} else
if ( n >= 575 && n < 755 ) {
	BLK = 0;
} else
if ( n >= 755 && n < 756 ) {
	BLK = 1;
} else
if ( n >= 756 && n < 757 ) {
	BLK = 3;
} else
if ( n >= 757 && n < 758 ) {
	BLK = 5;
} else
if ( n >= 758 && n < 762 ) {
	BLK = 0;
} else
if ( n >= 762 && n < 763 ) {
	BLK = 1;
} else
if ( n >= 763 && n < 767 ) {
	BLK = 5;
} else
if ( n >= 767 && n < 768 ) {
	BLK = 0;
} else
if ( n >= 768 && n < 769 ) {
	BLK = 3;
} else
if ( n >= 769 && n < 775 ) {
	BLK = 1;
} else
if ( n >= 775 && n < 776 ) {
	BLK = 3;
} else
if ( n >= 776 && n < 781 ) {
	BLK = 0;
} else
if ( n >= 781 && n < 785 ) {
	BLK = 1;
} else
if ( n >= 785 && n < 792 ) {
	BLK = 0;
} else
if ( n >= 792 && n < 795 ) {
	BLK = 5;
} else
if ( n >= 795 && n < 796 ) {
	BLK = 1;
} else
if ( n >= 796 && n < 923 ) {
	BLK = 0;
} else
if ( n >= 923 && n < 1021 ) {
	BLK = 1;
} else
if ( n >= 1021 && n < 1082 ) {
	BLK = 5;
} else
if ( n >= 1082 && n < 1092 ) {
	BLK = 1;
} else
if ( n >= 1092 && n < 1094 ) {
	BLK = 3;
} else
if ( n >= 1094 && n < 1095 ) {
	BLK = 5;
} else
if ( n >= 1095 && n < 1098 ) {
	BLK = 1;
} else
if ( n >= 1098 && n < 1099 ) {
	BLK = 3;
} else
if ( n >= 1099 && n < 1140 ) {
	BLK = 5;
} else
if ( n >= 1140 && n < 1141 ) {
	BLK = 1;
} else
if ( n >= 1141 && n < 1144 ) {
	BLK = 3;
} else
if ( n >= 1144 && n < 1147 ) {
	BLK = 1;
} else
if ( n >= 1147 && n < 1148 ) {
	BLK = 3;
} else
if ( n >= 1148 && n < 1154 ) {
	BLK = 5;
} else
if ( n >= 1154 && n < 1233 ) {
	BLK = 1;
} else
if ( n >= 1233 && n < 1509 ) {
	BLK = 3;
} else
if ( n >= 1509 && n < 1645 ) {
	BLK = 5;
} else
if ( n >= 1645 && n < 1650 ) {
	BLK = 4;
} else
if ( n >= 1650 && n < 1652 ) {
	BLK = 2;
} else
if ( n >= 1652 && n < 1746 ) {
	BLK = 5;
} else
if ( n >= 1746 && n < 2736 ) {
	BLK = 4;
} else
if ( n >= 2736 && n < 4098 ) {
	BLK = 2;
} else
if ( n >= 4098 && n < 6463 ) {
	BLK = 3;
} else
if ( n >= 6463 && n < 7569 ) {
	BLK = 2;
} else
if ( n >= 7569 && n < 8220 ) {
	BLK = 4;
} else
if ( n >= 8220 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
