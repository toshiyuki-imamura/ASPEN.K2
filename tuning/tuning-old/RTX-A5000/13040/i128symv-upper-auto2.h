#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Sat Sep 26 00:17:58  2026
 Host on fermat.r-ccs27.riken.jp
 Device is RTX-A5000
****************************************/-->
// device name
DEVICE= RTX-A5000
// the number of multi-processors
MP= 64
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 25327001600
// capacity of the work area reserved on the GPU
WORK= 3118080
// for double or cuFloatComplex or int64
MAXDIM= 53452
// for float or cuHalfComplex or int32
MAXDIM2= 75593
// for cuDoubleComplex or DD or int128
MAXDIM3= 37796
// for DD-Complex
MAXDIM4= 26726
// for half or int16
MAXDIM5= 106905
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 860
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

if ( n >= 1 && n < 5 ) {
	BLK = 3;
} else
if ( n >= 5 && n < 25 ) {
	BLK = 1;
} else
if ( n >= 25 && n < 921 ) {
	BLK = 0;
} else
if ( n >= 921 && n < 1070 ) {
	BLK = 4;
} else
if ( n >= 1070 && n < 1077 ) {
	BLK = 5;
} else
if ( n >= 1077 && n < 1078 ) {
	BLK = 2;
} else
if ( n >= 1078 && n < 1086 ) {
	BLK = 4;
} else
if ( n >= 1086 && n < 1087 ) {
	BLK = 5;
} else
if ( n >= 1087 && n < 1088 ) {
	BLK = 2;
} else
if ( n >= 1088 && n < 1090 ) {
	BLK = 4;
} else
if ( n >= 1090 && n < 1104 ) {
	BLK = 5;
} else
if ( n >= 1104 && n < 1106 ) {
	BLK = 2;
} else
if ( n >= 1106 && n < 1107 ) {
	BLK = 4;
} else
if ( n >= 1107 && n < 1130 ) {
	BLK = 5;
} else
if ( n >= 1130 && n < 1131 ) {
	BLK = 4;
} else
if ( n >= 1131 && n < 1132 ) {
	BLK = 2;
} else
if ( n >= 1132 && n < 1136 ) {
	BLK = 5;
} else
if ( n >= 1136 && n < 1209 ) {
	BLK = 4;
} else
if ( n >= 1209 && n < 1345 ) {
	BLK = 2;
} else
if ( n >= 1345 && n < 2112 ) {
	BLK = 5;
} else
if ( n >= 2112 && n < 4356 ) {
	BLK = 2;
} else
if ( n >= 4356 && n < 7930 ) {
	BLK = 3;
} else
if ( n >= 7930 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
