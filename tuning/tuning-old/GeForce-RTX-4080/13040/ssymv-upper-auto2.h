#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Tue Sep 22 21:24:01  2026
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

if ( n >= 1 && n < 3 ) {
	BLK = 1;
} else
if ( n >= 3 && n < 1232 ) {
	BLK = 0;
} else
if ( n >= 1232 && n < 1239 ) {
	BLK = 1;
} else
if ( n >= 1239 && n < 1240 ) {
	BLK = 0;
} else
if ( n >= 1240 && n < 1243 ) {
	BLK = 4;
} else
if ( n >= 1243 && n < 1252 ) {
	BLK = 1;
} else
if ( n >= 1252 && n < 1253 ) {
	BLK = 5;
} else
if ( n >= 1253 && n < 1254 ) {
	BLK = 4;
} else
if ( n >= 1254 && n < 1262 ) {
	BLK = 1;
} else
if ( n >= 1262 && n < 1264 ) {
	BLK = 5;
} else
if ( n >= 1264 && n < 1268 ) {
	BLK = 4;
} else
if ( n >= 1268 && n < 1270 ) {
	BLK = 1;
} else
if ( n >= 1270 && n < 1271 ) {
	BLK = 5;
} else
if ( n >= 1271 && n < 1306 ) {
	BLK = 4;
} else
if ( n >= 1306 && n < 1313 ) {
	BLK = 1;
} else
if ( n >= 1313 && n < 1314 ) {
	BLK = 5;
} else
if ( n >= 1314 && n < 1315 ) {
	BLK = 4;
} else
if ( n >= 1315 && n < 1332 ) {
	BLK = 1;
} else
if ( n >= 1332 && n < 1334 ) {
	BLK = 5;
} else
if ( n >= 1334 && n < 1335 ) {
	BLK = 4;
} else
if ( n >= 1335 && n < 1347 ) {
	BLK = 1;
} else
if ( n >= 1347 && n < 1348 ) {
	BLK = 4;
} else
if ( n >= 1348 && n < 1358 ) {
	BLK = 5;
} else
if ( n >= 1358 && n < 1359 ) {
	BLK = 1;
} else
if ( n >= 1359 && n < 1364 ) {
	BLK = 4;
} else
if ( n >= 1364 && n < 1367 ) {
	BLK = 1;
} else
if ( n >= 1367 && n < 1369 ) {
	BLK = 5;
} else
if ( n >= 1369 && n < 1370 ) {
	BLK = 4;
} else
if ( n >= 1370 && n < 1399 ) {
	BLK = 1;
} else
if ( n >= 1399 && n < 1400 ) {
	BLK = 0;
} else
if ( n >= 1400 && n < 1408 ) {
	BLK = 5;
} else
if ( n >= 1408 && n < 1415 ) {
	BLK = 1;
} else
if ( n >= 1415 && n < 1474 ) {
	BLK = 5;
} else
if ( n >= 1474 && n < 1475 ) {
	BLK = 0;
} else
if ( n >= 1475 && n < 1477 ) {
	BLK = 1;
} else
if ( n >= 1477 && n < 1478 ) {
	BLK = 4;
} else
if ( n >= 1478 && n < 1479 ) {
	BLK = 5;
} else
if ( n >= 1479 && n < 1976 ) {
	BLK = 1;
} else
if ( n >= 1976 && n < 2800 ) {
	BLK = 0;
} else
if ( n >= 2800 && n < 4548 ) {
	BLK = 2;
} else
if ( n >= 4548 && n < 8967 ) {
	BLK = 3;
} else
if ( n >= 8967 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
