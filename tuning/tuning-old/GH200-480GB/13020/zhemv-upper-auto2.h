#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Thu Aug 06 11:37:13  2026
 Host on qc-gh200-01.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 101997334528
// capacity of the work area reserved on the GPU
WORK= 8136960
// for double or cuFloatComplex or int64
MAXDIM= 107268
// for float or cuHalfComplex or int32
MAXDIM2= 151700
// for cuDoubleComplex or DD or int128
MAXDIM3= 75850
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214537
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 13 ) {
	BLK = 5;
} else
if ( n >= 13 && n < 48 ) {
	BLK = 3;
} else
if ( n >= 48 && n < 144 ) {
	BLK = 5;
} else
if ( n >= 144 && n < 147 ) {
	BLK = 4;
} else
if ( n >= 147 && n < 152 ) {
	BLK = 3;
} else
if ( n >= 152 && n < 155 ) {
	BLK = 5;
} else
if ( n >= 155 && n < 158 ) {
	BLK = 4;
} else
if ( n >= 158 && n < 164 ) {
	BLK = 3;
} else
if ( n >= 164 && n < 165 ) {
	BLK = 4;
} else
if ( n >= 165 && n < 166 ) {
	BLK = 5;
} else
if ( n >= 166 && n < 167 ) {
	BLK = 2;
} else
if ( n >= 167 && n < 180 ) {
	BLK = 3;
} else
if ( n >= 180 && n < 181 ) {
	BLK = 5;
} else
if ( n >= 181 && n < 183 ) {
	BLK = 4;
} else
if ( n >= 183 && n < 192 ) {
	BLK = 3;
} else
if ( n >= 192 && n < 213 ) {
	BLK = 5;
} else
if ( n >= 213 && n < 216 ) {
	BLK = 3;
} else
if ( n >= 216 && n < 218 ) {
	BLK = 5;
} else
if ( n >= 218 && n < 219 ) {
	BLK = 4;
} else
if ( n >= 219 && n < 288 ) {
	BLK = 3;
} else
if ( n >= 288 && n < 291 ) {
	BLK = 5;
} else
if ( n >= 291 && n < 292 ) {
	BLK = 3;
} else
if ( n >= 292 && n < 294 ) {
	BLK = 4;
} else
if ( n >= 294 && n < 297 ) {
	BLK = 5;
} else
if ( n >= 297 && n < 301 ) {
	BLK = 3;
} else
if ( n >= 301 && n < 355 ) {
	BLK = 5;
} else
if ( n >= 355 && n < 416 ) {
	BLK = 2;
} else
if ( n >= 416 && n < 417 ) {
	BLK = 4;
} else
if ( n >= 417 && n < 420 ) {
	BLK = 5;
} else
if ( n >= 420 && n < 431 ) {
	BLK = 2;
} else
if ( n >= 431 && n < 432 ) {
	BLK = 3;
} else
if ( n >= 432 && n < 433 ) {
	BLK = 5;
} else
if ( n >= 433 && n < 439 ) {
	BLK = 4;
} else
if ( n >= 439 && n < 441 ) {
	BLK = 5;
} else
if ( n >= 441 && n < 544 ) {
	BLK = 3;
} else
if ( n >= 544 && n < 679 ) {
	BLK = 4;
} else
if ( n >= 679 && n < 2024 ) {
	BLK = 3;
} else
if ( n >= 2024 && n < 2127 ) {
	BLK = 4;
} else
if ( n >= 2127 && n < 4645 ) {
	BLK = 2;
} else
if ( n >= 4645 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
