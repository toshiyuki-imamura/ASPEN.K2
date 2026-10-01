#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Thu Sep 24 00:32:38  2026
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

if ( n >= 1 && n < 517 ) {
	BLK = 0;
} else
if ( n >= 517 && n < 518 ) {
	BLK = 4;
} else
if ( n >= 518 && n < 522 ) {
	BLK = 1;
} else
if ( n >= 522 && n < 531 ) {
	BLK = 0;
} else
if ( n >= 531 && n < 532 ) {
	BLK = 1;
} else
if ( n >= 532 && n < 559 ) {
	BLK = 4;
} else
if ( n >= 559 && n < 791 ) {
	BLK = 0;
} else
if ( n >= 791 && n < 893 ) {
	BLK = 4;
} else
if ( n >= 893 && n < 1175 ) {
	BLK = 0;
} else
if ( n >= 1175 && n < 1176 ) {
	BLK = 4;
} else
if ( n >= 1176 && n < 1221 ) {
	BLK = 1;
} else
if ( n >= 1221 && n < 1252 ) {
	BLK = 4;
} else
if ( n >= 1252 && n < 1255 ) {
	BLK = 5;
} else
if ( n >= 1255 && n < 1256 ) {
	BLK = 1;
} else
if ( n >= 1256 && n < 1257 ) {
	BLK = 4;
} else
if ( n >= 1257 && n < 1265 ) {
	BLK = 5;
} else
if ( n >= 1265 && n < 1269 ) {
	BLK = 1;
} else
if ( n >= 1269 && n < 1271 ) {
	BLK = 4;
} else
if ( n >= 1271 && n < 1280 ) {
	BLK = 5;
} else
if ( n >= 1280 && n < 1281 ) {
	BLK = 1;
} else
if ( n >= 1281 && n < 1292 ) {
	BLK = 4;
} else
if ( n >= 1292 && n < 1293 ) {
	BLK = 1;
} else
if ( n >= 1293 && n < 1305 ) {
	BLK = 5;
} else
if ( n >= 1305 && n < 1306 ) {
	BLK = 1;
} else
if ( n >= 1306 && n < 1347 ) {
	BLK = 4;
} else
if ( n >= 1347 && n < 1358 ) {
	BLK = 1;
} else
if ( n >= 1358 && n < 1359 ) {
	BLK = 5;
} else
if ( n >= 1359 && n < 1360 ) {
	BLK = 4;
} else
if ( n >= 1360 && n < 1362 ) {
	BLK = 1;
} else
if ( n >= 1362 && n < 1363 ) {
	BLK = 5;
} else
if ( n >= 1363 && n < 1364 ) {
	BLK = 4;
} else
if ( n >= 1364 && n < 1367 ) {
	BLK = 1;
} else
if ( n >= 1367 && n < 1517 ) {
	BLK = 4;
} else
if ( n >= 1517 && n < 1534 ) {
	BLK = 1;
} else
if ( n >= 1534 && n < 1535 ) {
	BLK = 4;
} else
if ( n >= 1535 && n < 1598 ) {
	BLK = 5;
} else
if ( n >= 1598 && n < 2635 ) {
	BLK = 1;
} else
if ( n >= 2635 && n < 3326 ) {
	BLK = 5;
} else
if ( n >= 3326 && n < 3903 ) {
	BLK = 1;
} else
if ( n >= 3903 && n < 6645 ) {
	BLK = 3;
} else
if ( n >= 6645 && n < 7656 ) {
	BLK = 4;
} else
if ( n >= 7656 && n < 14144 ) {
	BLK = 1;
} else
if ( n >= 14144 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
