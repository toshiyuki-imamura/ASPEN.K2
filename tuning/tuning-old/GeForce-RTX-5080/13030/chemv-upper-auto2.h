#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Sat Aug 08 06:31:24  2026
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
MAXmem= 16647024640
// capacity of the work area reserved on the GPU
WORK= 2526720
// for double or cuFloatComplex or int64
MAXDIM= 43335
// for float or cuHalfComplex or int32
MAXDIM2= 61286
// for cuDoubleComplex or DD or int128
MAXDIM3= 30643
// for DD-Complex
MAXDIM4= 21667
// for half or int16
MAXDIM5= 86671
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1200
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

if ( n >= 1 && n < 271 ) {
	BLK = 0;
} else
if ( n >= 271 && n < 283 ) {
	BLK = 2;
} else
if ( n >= 283 && n < 298 ) {
	BLK = 0;
} else
if ( n >= 298 && n < 301 ) {
	BLK = 4;
} else
if ( n >= 301 && n < 302 ) {
	BLK = 2;
} else
if ( n >= 302 && n < 319 ) {
	BLK = 0;
} else
if ( n >= 319 && n < 324 ) {
	BLK = 2;
} else
if ( n >= 324 && n < 349 ) {
	BLK = 4;
} else
if ( n >= 349 && n < 352 ) {
	BLK = 0;
} else
if ( n >= 352 && n < 379 ) {
	BLK = 2;
} else
if ( n >= 379 && n < 380 ) {
	BLK = 0;
} else
if ( n >= 380 && n < 381 ) {
	BLK = 1;
} else
if ( n >= 381 && n < 384 ) {
	BLK = 2;
} else
if ( n >= 384 && n < 385 ) {
	BLK = 1;
} else
if ( n >= 385 && n < 392 ) {
	BLK = 0;
} else
if ( n >= 392 && n < 401 ) {
	BLK = 4;
} else
if ( n >= 401 && n < 654 ) {
	BLK = 1;
} else
if ( n >= 654 && n < 656 ) {
	BLK = 2;
} else
if ( n >= 656 && n < 664 ) {
	BLK = 3;
} else
if ( n >= 664 && n < 666 ) {
	BLK = 2;
} else
if ( n >= 666 && n < 668 ) {
	BLK = 1;
} else
if ( n >= 668 && n < 669 ) {
	BLK = 3;
} else
if ( n >= 669 && n < 671 ) {
	BLK = 2;
} else
if ( n >= 671 && n < 679 ) {
	BLK = 1;
} else
if ( n >= 679 && n < 681 ) {
	BLK = 3;
} else
if ( n >= 681 && n < 682 ) {
	BLK = 2;
} else
if ( n >= 682 && n < 767 ) {
	BLK = 1;
} else
if ( n >= 767 && n < 784 ) {
	BLK = 2;
} else
if ( n >= 784 && n < 789 ) {
	BLK = 1;
} else
if ( n >= 789 && n < 790 ) {
	BLK = 3;
} else
if ( n >= 790 && n < 800 ) {
	BLK = 2;
} else
if ( n >= 800 && n < 801 ) {
	BLK = 3;
} else
if ( n >= 801 && n < 817 ) {
	BLK = 1;
} else
if ( n >= 817 && n < 818 ) {
	BLK = 3;
} else
if ( n >= 818 && n < 828 ) {
	BLK = 2;
} else
if ( n >= 828 && n < 837 ) {
	BLK = 1;
} else
if ( n >= 837 && n < 838 ) {
	BLK = 3;
} else
if ( n >= 838 && n < 841 ) {
	BLK = 2;
} else
if ( n >= 841 && n < 911 ) {
	BLK = 1;
} else
if ( n >= 911 && n < 912 ) {
	BLK = 2;
} else
if ( n >= 912 && n < 930 ) {
	BLK = 3;
} else
if ( n >= 930 && n < 1092 ) {
	BLK = 1;
} else
if ( n >= 1092 && n < 1094 ) {
	BLK = 2;
} else
if ( n >= 1094 && n < 1095 ) {
	BLK = 3;
} else
if ( n >= 1095 && n < 1105 ) {
	BLK = 1;
} else
if ( n >= 1105 && n < 1106 ) {
	BLK = 3;
} else
if ( n >= 1106 && n < 1135 ) {
	BLK = 2;
} else
if ( n >= 1135 && n < 1136 ) {
	BLK = 1;
} else
if ( n >= 1136 && n < 1137 ) {
	BLK = 3;
} else
if ( n >= 1137 && n < 1152 ) {
	BLK = 2;
} else
if ( n >= 1152 && n < 1153 ) {
	BLK = 1;
} else
if ( n >= 1153 && n < 1158 ) {
	BLK = 3;
} else
if ( n >= 1158 && n < 1159 ) {
	BLK = 1;
} else
if ( n >= 1159 && n < 1170 ) {
	BLK = 2;
} else
if ( n >= 1170 && n < 1174 ) {
	BLK = 3;
} else
if ( n >= 1174 && n < 1176 ) {
	BLK = 1;
} else
if ( n >= 1176 && n < 1177 ) {
	BLK = 2;
} else
if ( n >= 1177 && n < 1183 ) {
	BLK = 3;
} else
if ( n >= 1183 && n < 1184 ) {
	BLK = 1;
} else
if ( n >= 1184 && n < 1199 ) {
	BLK = 5;
} else
if ( n >= 1199 && n < 1200 ) {
	BLK = 2;
} else
if ( n >= 1200 && n < 1209 ) {
	BLK = 3;
} else
if ( n >= 1209 && n < 1223 ) {
	BLK = 2;
} else
if ( n >= 1223 && n < 1224 ) {
	BLK = 5;
} else
if ( n >= 1224 && n < 1242 ) {
	BLK = 3;
} else
if ( n >= 1242 && n < 1243 ) {
	BLK = 1;
} else
if ( n >= 1243 && n < 1248 ) {
	BLK = 2;
} else
if ( n >= 1248 && n < 1266 ) {
	BLK = 3;
} else
if ( n >= 1266 && n < 1274 ) {
	BLK = 2;
} else
if ( n >= 1274 && n < 1276 ) {
	BLK = 1;
} else
if ( n >= 1276 && n < 1280 ) {
	BLK = 3;
} else
if ( n >= 1280 && n < 1289 ) {
	BLK = 2;
} else
if ( n >= 1289 && n < 1291 ) {
	BLK = 5;
} else
if ( n >= 1291 && n < 1302 ) {
	BLK = 1;
} else
if ( n >= 1302 && n < 1307 ) {
	BLK = 2;
} else
if ( n >= 1307 && n < 1308 ) {
	BLK = 3;
} else
if ( n >= 1308 && n < 1309 ) {
	BLK = 5;
} else
if ( n >= 1309 && n < 1331 ) {
	BLK = 2;
} else
if ( n >= 1331 && n < 1332 ) {
	BLK = 5;
} else
if ( n >= 1332 && n < 1337 ) {
	BLK = 1;
} else
if ( n >= 1337 && n < 1594 ) {
	BLK = 5;
} else
if ( n >= 1594 && n < 1632 ) {
	BLK = 1;
} else
if ( n >= 1632 && n < 1633 ) {
	BLK = 2;
} else
if ( n >= 1633 && n < 1634 ) {
	BLK = 3;
} else
if ( n >= 1634 && n < 1776 ) {
	BLK = 1;
} else
if ( n >= 1776 && n < 1845 ) {
	BLK = 3;
} else
if ( n >= 1845 && n < 1884 ) {
	BLK = 1;
} else
if ( n >= 1884 && n < 1885 ) {
	BLK = 3;
} else
if ( n >= 1885 && n < 1935 ) {
	BLK = 2;
} else
if ( n >= 1935 && n < 2080 ) {
	BLK = 1;
} else
if ( n >= 2080 && n < 2085 ) {
	BLK = 3;
} else
if ( n >= 2085 && n < 2086 ) {
	BLK = 2;
} else
if ( n >= 2086 && n < 2509 ) {
	BLK = 1;
} else
if ( n >= 2509 && n < 3714 ) {
	BLK = 3;
} else
if ( n >= 3714 && n < 6107 ) {
	BLK = 2;
} else
if ( n >= 6107 && n < 7930 ) {
	BLK = 5;
} else
if ( n >= 7930 && n < 19643 ) {
	BLK = 1;
} else
if ( n >= 19643 && n < 20049 ) {
	BLK = 5;
} else
if ( n >= 20049 && n < 24461 ) {
	BLK = 1;
} else
if ( n >= 24461 && n < 24920 ) {
	BLK = 5;
} else
if ( n >= 24920 && n < 37658 ) {
	BLK = 1;
} else
if ( n >= 37658 && n < 39059 ) {
	BLK = 5;
} else
if ( n >= 39059 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
