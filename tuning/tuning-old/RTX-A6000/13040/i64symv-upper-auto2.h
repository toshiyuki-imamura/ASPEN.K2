#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Sat Sep 26 18:11:50  2026
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

if ( n >= 1 && n < 613 ) {
	BLK = 0;
} else
if ( n >= 613 && n < 632 ) {
	BLK = 3;
} else
if ( n >= 632 && n < 669 ) {
	BLK = 4;
} else
if ( n >= 669 && n < 1057 ) {
	BLK = 0;
} else
if ( n >= 1057 && n < 1088 ) {
	BLK = 4;
} else
if ( n >= 1088 && n < 1089 ) {
	BLK = 2;
} else
if ( n >= 1089 && n < 1099 ) {
	BLK = 3;
} else
if ( n >= 1099 && n < 1100 ) {
	BLK = 0;
} else
if ( n >= 1100 && n < 1101 ) {
	BLK = 2;
} else
if ( n >= 1101 && n < 1104 ) {
	BLK = 3;
} else
if ( n >= 1104 && n < 1105 ) {
	BLK = 4;
} else
if ( n >= 1105 && n < 1109 ) {
	BLK = 0;
} else
if ( n >= 1109 && n < 1127 ) {
	BLK = 3;
} else
if ( n >= 1127 && n < 1128 ) {
	BLK = 2;
} else
if ( n >= 1128 && n < 1129 ) {
	BLK = 4;
} else
if ( n >= 1129 && n < 1137 ) {
	BLK = 3;
} else
if ( n >= 1137 && n < 1140 ) {
	BLK = 4;
} else
if ( n >= 1140 && n < 1142 ) {
	BLK = 3;
} else
if ( n >= 1142 && n < 1143 ) {
	BLK = 2;
} else
if ( n >= 1143 && n < 1144 ) {
	BLK = 1;
} else
if ( n >= 1144 && n < 1149 ) {
	BLK = 3;
} else
if ( n >= 1149 && n < 1150 ) {
	BLK = 0;
} else
if ( n >= 1150 && n < 1151 ) {
	BLK = 2;
} else
if ( n >= 1151 && n < 1155 ) {
	BLK = 3;
} else
if ( n >= 1155 && n < 1160 ) {
	BLK = 2;
} else
if ( n >= 1160 && n < 1161 ) {
	BLK = 0;
} else
if ( n >= 1161 && n < 1162 ) {
	BLK = 4;
} else
if ( n >= 1162 && n < 1164 ) {
	BLK = 3;
} else
if ( n >= 1164 && n < 1165 ) {
	BLK = 0;
} else
if ( n >= 1165 && n < 1186 ) {
	BLK = 4;
} else
if ( n >= 1186 && n < 1278 ) {
	BLK = 3;
} else
if ( n >= 1278 && n < 1279 ) {
	BLK = 4;
} else
if ( n >= 1279 && n < 1283 ) {
	BLK = 0;
} else
if ( n >= 1283 && n < 1284 ) {
	BLK = 4;
} else
if ( n >= 1284 && n < 1286 ) {
	BLK = 2;
} else
if ( n >= 1286 && n < 1291 ) {
	BLK = 3;
} else
if ( n >= 1291 && n < 1292 ) {
	BLK = 4;
} else
if ( n >= 1292 && n < 1382 ) {
	BLK = 2;
} else
if ( n >= 1382 && n < 1383 ) {
	BLK = 1;
} else
if ( n >= 1383 && n < 3340 ) {
	BLK = 4;
} else
if ( n >= 3340 && n < 3341 ) {
	BLK = 1;
} else
if ( n >= 3341 && n < 3382 ) {
	BLK = 5;
} else
if ( n >= 3382 && n < 5146 ) {
	BLK = 4;
} else
if ( n >= 5146 && n < 11154 ) {
	BLK = 1;
} else
if ( n >= 11154 && n < 13282 ) {
	BLK = 2;
} else
if ( n >= 13282 && n < 13801 ) {
	BLK = 4;
} else
if ( n >= 13801 && n < 13924 ) {
	BLK = 2;
} else
if ( n >= 13924 && n < 13990 ) {
	BLK = 5;
} else
if ( n >= 13990 && n < 14505 ) {
	BLK = 4;
} else
if ( n >= 14505 && n < 14632 ) {
	BLK = 2;
} else
if ( n >= 14632 && n < 14684 ) {
	BLK = 5;
} else
if ( n >= 14684 && n < 15158 ) {
	BLK = 4;
} else
if ( n >= 15158 && n < 15271 ) {
	BLK = 1;
} else
if ( n >= 15271 && n < 15566 ) {
	BLK = 2;
} else
if ( n >= 15566 && n < 17417 ) {
	BLK = 4;
} else
if ( n >= 17417 && n < 18236 ) {
	BLK = 5;
} else
if ( n >= 18236 && n < 19142 ) {
	BLK = 4;
} else
if ( n >= 19142 && n < 19462 ) {
	BLK = 2;
} else
if ( n >= 19462 && n < 20944 ) {
	BLK = 4;
} else
if ( n >= 20944 && n < 21623 ) {
	BLK = 5;
} else
if ( n >= 21623 && n < 24441 ) {
	BLK = 4;
} else
if ( n >= 24441 && n < 25915 ) {
	BLK = 2;
} else
if ( n >= 25915 && n < 34135 ) {
	BLK = 4;
} else
if ( n >= 34135 && n < 35222 ) {
	BLK = 5;
} else
if ( n >= 35222 && n < 35797 ) {
	BLK = 4;
} else
if ( n >= 35797 && n < 37798 ) {
	BLK = 2;
} else
if ( n >= 37798 && n < 67757 ) {
	BLK = 4;
} else
if ( n >= 67757 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
