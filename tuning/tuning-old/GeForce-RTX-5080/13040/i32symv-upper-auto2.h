#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Sat Sep 26 08:41:59  2026
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
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
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

if ( n >= 1 && n < 196 ) {
	BLK = 0;
} else
if ( n >= 196 && n < 197 ) {
	BLK = 2;
} else
if ( n >= 197 && n < 198 ) {
	BLK = 3;
} else
if ( n >= 198 && n < 227 ) {
	BLK = 0;
} else
if ( n >= 227 && n < 234 ) {
	BLK = 3;
} else
if ( n >= 234 && n < 235 ) {
	BLK = 0;
} else
if ( n >= 235 && n < 236 ) {
	BLK = 2;
} else
if ( n >= 236 && n < 237 ) {
	BLK = 3;
} else
if ( n >= 237 && n < 238 ) {
	BLK = 0;
} else
if ( n >= 238 && n < 253 ) {
	BLK = 2;
} else
if ( n >= 253 && n < 255 ) {
	BLK = 3;
} else
if ( n >= 255 && n < 275 ) {
	BLK = 0;
} else
if ( n >= 275 && n < 276 ) {
	BLK = 3;
} else
if ( n >= 276 && n < 279 ) {
	BLK = 2;
} else
if ( n >= 279 && n < 287 ) {
	BLK = 0;
} else
if ( n >= 287 && n < 290 ) {
	BLK = 3;
} else
if ( n >= 290 && n < 291 ) {
	BLK = 4;
} else
if ( n >= 291 && n < 310 ) {
	BLK = 0;
} else
if ( n >= 310 && n < 311 ) {
	BLK = 3;
} else
if ( n >= 311 && n < 379 ) {
	BLK = 2;
} else
if ( n >= 379 && n < 1082 ) {
	BLK = 0;
} else
if ( n >= 1082 && n < 1118 ) {
	BLK = 3;
} else
if ( n >= 1118 && n < 1120 ) {
	BLK = 0;
} else
if ( n >= 1120 && n < 1156 ) {
	BLK = 4;
} else
if ( n >= 1156 && n < 1215 ) {
	BLK = 3;
} else
if ( n >= 1215 && n < 1223 ) {
	BLK = 0;
} else
if ( n >= 1223 && n < 1224 ) {
	BLK = 3;
} else
if ( n >= 1224 && n < 1226 ) {
	BLK = 4;
} else
if ( n >= 1226 && n < 1247 ) {
	BLK = 0;
} else
if ( n >= 1247 && n < 1259 ) {
	BLK = 3;
} else
if ( n >= 1259 && n < 1260 ) {
	BLK = 4;
} else
if ( n >= 1260 && n < 1269 ) {
	BLK = 0;
} else
if ( n >= 1269 && n < 1325 ) {
	BLK = 3;
} else
if ( n >= 1325 && n < 1696 ) {
	BLK = 0;
} else
if ( n >= 1696 && n < 4253 ) {
	BLK = 1;
} else
if ( n >= 4253 && n < 5355 ) {
	BLK = 4;
} else
if ( n >= 5355 && n < 5704 ) {
	BLK = 1;
} else
if ( n >= 5704 && n < 8209 ) {
	BLK = 3;
} else
if ( n >= 8209 && n < 8993 ) {
	BLK = 1;
} else
if ( n >= 8993 && n < 10862 ) {
	BLK = 4;
} else
if ( n >= 10862 && n < 17872 ) {
	BLK = 5;
} else
if ( n >= 17872 && n < 19704 ) {
	BLK = 2;
} else
if ( n >= 19704 && n < 19964 ) {
	BLK = 5;
} else
if ( n >= 19964 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
