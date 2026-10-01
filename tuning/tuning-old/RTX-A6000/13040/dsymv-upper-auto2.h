#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Sat Sep 26 00:53:38  2026
 Host on pascal.r-ccs27.riken.jp
 Device is RTX-A6000
****************************************/-->
// device name
DEVICE= RTX-A6000
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 50949160960
// capacity of the work area reserved on the GPU
WORK= 4423680
// for double or cuFloatComplex or int64
MAXDIM= 75813
// for float or cuHalfComplex or int32
MAXDIM2= 107216
// for cuDoubleComplex or DD or int128
MAXDIM3= 53608
// for DD-Complex
MAXDIM4= 37906
// for half or int16
MAXDIM5= 151627
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

if ( n >= 1 && n < 10 ) {
	BLK = 0;
} else
if ( n >= 10 && n < 14 ) {
	BLK = 2;
} else
if ( n >= 14 && n < 42 ) {
	BLK = 3;
} else
if ( n >= 42 && n < 1004 ) {
	BLK = 0;
} else
if ( n >= 1004 && n < 1077 ) {
	BLK = 4;
} else
if ( n >= 1077 && n < 1079 ) {
	BLK = 5;
} else
if ( n >= 1079 && n < 1080 ) {
	BLK = 0;
} else
if ( n >= 1080 && n < 1102 ) {
	BLK = 4;
} else
if ( n >= 1102 && n < 1103 ) {
	BLK = 0;
} else
if ( n >= 1103 && n < 1111 ) {
	BLK = 5;
} else
if ( n >= 1111 && n < 1112 ) {
	BLK = 0;
} else
if ( n >= 1112 && n < 1125 ) {
	BLK = 4;
} else
if ( n >= 1125 && n < 1126 ) {
	BLK = 0;
} else
if ( n >= 1126 && n < 1144 ) {
	BLK = 5;
} else
if ( n >= 1144 && n < 1149 ) {
	BLK = 0;
} else
if ( n >= 1149 && n < 1153 ) {
	BLK = 4;
} else
if ( n >= 1153 && n < 1154 ) {
	BLK = 5;
} else
if ( n >= 1154 && n < 1155 ) {
	BLK = 0;
} else
if ( n >= 1155 && n < 1158 ) {
	BLK = 4;
} else
if ( n >= 1158 && n < 1169 ) {
	BLK = 5;
} else
if ( n >= 1169 && n < 1171 ) {
	BLK = 0;
} else
if ( n >= 1171 && n < 1172 ) {
	BLK = 4;
} else
if ( n >= 1172 && n < 1173 ) {
	BLK = 5;
} else
if ( n >= 1173 && n < 1175 ) {
	BLK = 0;
} else
if ( n >= 1175 && n < 1176 ) {
	BLK = 4;
} else
if ( n >= 1176 && n < 1321 ) {
	BLK = 5;
} else
if ( n >= 1321 && n < 1536 ) {
	BLK = 3;
} else
if ( n >= 1536 && n < 2471 ) {
	BLK = 5;
} else
if ( n >= 2471 && n < 4180 ) {
	BLK = 3;
} else
if ( n >= 4180 && n < 11022 ) {
	BLK = 1;
} else
if ( n >= 11022 && n < 12991 ) {
	BLK = 2;
} else
if ( n >= 12991 && n < 15668 ) {
	BLK = 1;
} else
if ( n >= 15668 && n < 17981 ) {
	BLK = 2;
} else
if ( n >= 17981 && n < 18800 ) {
	BLK = 1;
} else
if ( n >= 18800 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
