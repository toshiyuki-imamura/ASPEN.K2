#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Wed Sep 23 01:30:06  2026
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

if ( n >= 1 && n < 2 ) {
	BLK = 2;
} else
if ( n >= 2 && n < 7 ) {
	BLK = 1;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 13 ) {
	BLK = 3;
} else
if ( n >= 13 && n < 32 ) {
	BLK = 1;
} else
if ( n >= 32 && n < 37 ) {
	BLK = 0;
} else
if ( n >= 37 && n < 40 ) {
	BLK = 2;
} else
if ( n >= 40 && n < 41 ) {
	BLK = 3;
} else
if ( n >= 41 && n < 42 ) {
	BLK = 0;
} else
if ( n >= 42 && n < 44 ) {
	BLK = 5;
} else
if ( n >= 44 && n < 45 ) {
	BLK = 3;
} else
if ( n >= 45 && n < 893 ) {
	BLK = 0;
} else
if ( n >= 893 && n < 918 ) {
	BLK = 2;
} else
if ( n >= 918 && n < 923 ) {
	BLK = 5;
} else
if ( n >= 923 && n < 924 ) {
	BLK = 2;
} else
if ( n >= 924 && n < 930 ) {
	BLK = 0;
} else
if ( n >= 930 && n < 933 ) {
	BLK = 2;
} else
if ( n >= 933 && n < 934 ) {
	BLK = 3;
} else
if ( n >= 934 && n < 937 ) {
	BLK = 0;
} else
if ( n >= 937 && n < 938 ) {
	BLK = 2;
} else
if ( n >= 938 && n < 939 ) {
	BLK = 3;
} else
if ( n >= 939 && n < 940 ) {
	BLK = 0;
} else
if ( n >= 940 && n < 943 ) {
	BLK = 2;
} else
if ( n >= 943 && n < 944 ) {
	BLK = 3;
} else
if ( n >= 944 && n < 954 ) {
	BLK = 0;
} else
if ( n >= 954 && n < 1005 ) {
	BLK = 3;
} else
if ( n >= 1005 && n < 1030 ) {
	BLK = 5;
} else
if ( n >= 1030 && n < 1035 ) {
	BLK = 3;
} else
if ( n >= 1035 && n < 1036 ) {
	BLK = 0;
} else
if ( n >= 1036 && n < 1040 ) {
	BLK = 5;
} else
if ( n >= 1040 && n < 1041 ) {
	BLK = 3;
} else
if ( n >= 1041 && n < 1042 ) {
	BLK = 0;
} else
if ( n >= 1042 && n < 1046 ) {
	BLK = 5;
} else
if ( n >= 1046 && n < 1047 ) {
	BLK = 3;
} else
if ( n >= 1047 && n < 1048 ) {
	BLK = 0;
} else
if ( n >= 1048 && n < 1049 ) {
	BLK = 5;
} else
if ( n >= 1049 && n < 1050 ) {
	BLK = 3;
} else
if ( n >= 1050 && n < 1056 ) {
	BLK = 0;
} else
if ( n >= 1056 && n < 1073 ) {
	BLK = 5;
} else
if ( n >= 1073 && n < 1074 ) {
	BLK = 0;
} else
if ( n >= 1074 && n < 1080 ) {
	BLK = 3;
} else
if ( n >= 1080 && n < 1085 ) {
	BLK = 5;
} else
if ( n >= 1085 && n < 1230 ) {
	BLK = 3;
} else
if ( n >= 1230 && n < 1231 ) {
	BLK = 0;
} else
if ( n >= 1231 && n < 1232 ) {
	BLK = 2;
} else
if ( n >= 1232 && n < 1234 ) {
	BLK = 1;
} else
if ( n >= 1234 && n < 1247 ) {
	BLK = 0;
} else
if ( n >= 1247 && n < 1248 ) {
	BLK = 3;
} else
if ( n >= 1248 && n < 1249 ) {
	BLK = 2;
} else
if ( n >= 1249 && n < 1261 ) {
	BLK = 0;
} else
if ( n >= 1261 && n < 1262 ) {
	BLK = 4;
} else
if ( n >= 1262 && n < 1263 ) {
	BLK = 1;
} else
if ( n >= 1263 && n < 1267 ) {
	BLK = 2;
} else
if ( n >= 1267 && n < 1270 ) {
	BLK = 0;
} else
if ( n >= 1270 && n < 1278 ) {
	BLK = 1;
} else
if ( n >= 1278 && n < 1293 ) {
	BLK = 2;
} else
if ( n >= 1293 && n < 1294 ) {
	BLK = 3;
} else
if ( n >= 1294 && n < 1311 ) {
	BLK = 1;
} else
if ( n >= 1311 && n < 1337 ) {
	BLK = 2;
} else
if ( n >= 1337 && n < 1338 ) {
	BLK = 0;
} else
if ( n >= 1338 && n < 1484 ) {
	BLK = 3;
} else
if ( n >= 1484 && n < 1487 ) {
	BLK = 4;
} else
if ( n >= 1487 && n < 1491 ) {
	BLK = 1;
} else
if ( n >= 1491 && n < 1494 ) {
	BLK = 4;
} else
if ( n >= 1494 && n < 1498 ) {
	BLK = 3;
} else
if ( n >= 1498 && n < 1501 ) {
	BLK = 1;
} else
if ( n >= 1501 && n < 1504 ) {
	BLK = 4;
} else
if ( n >= 1504 && n < 1507 ) {
	BLK = 3;
} else
if ( n >= 1507 && n < 1511 ) {
	BLK = 1;
} else
if ( n >= 1511 && n < 1513 ) {
	BLK = 4;
} else
if ( n >= 1513 && n < 1531 ) {
	BLK = 3;
} else
if ( n >= 1531 && n < 2731 ) {
	BLK = 1;
} else
if ( n >= 2731 && n < 3063 ) {
	BLK = 4;
} else
if ( n >= 3063 && n < 3064 ) {
	BLK = 5;
} else
if ( n >= 3064 && n < 3068 ) {
	BLK = 0;
} else
if ( n >= 3068 && n < 3069 ) {
	BLK = 4;
} else
if ( n >= 3069 && n < 3070 ) {
	BLK = 5;
} else
if ( n >= 3070 && n < 3072 ) {
	BLK = 0;
} else
if ( n >= 3072 && n < 3103 ) {
	BLK = 4;
} else
if ( n >= 3103 && n < 3104 ) {
	BLK = 5;
} else
if ( n >= 3104 && n < 3110 ) {
	BLK = 0;
} else
if ( n >= 3110 && n < 4629 ) {
	BLK = 4;
} else
if ( n >= 4629 && n < 5583 ) {
	BLK = 3;
} else
if ( n >= 5583 && n < 9973 ) {
	BLK = 2;
} else
if ( n >= 9973 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
