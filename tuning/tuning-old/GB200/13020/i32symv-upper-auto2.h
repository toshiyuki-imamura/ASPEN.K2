#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Sun Jun 21 04:47:39  2026
 Host on ar11n06-m.ai.r-ccs.riken.jp
 Device is GB200
****************************************/-->
// device name
DEVICE= GB200
// the number of multi-processors
MP= 152
// compute-compatibility generation
CG= 1000
// capacity of the global memory or host memory
MAXmem= 197555425280
// capacity of the work area reserved on the GPU
WORK= 13067520
// for double or cuFloatComplex or int64
MAXDIM= 149287
// for float or cuHalfComplex or int32
MAXDIM2= 211124
// for cuDoubleComplex or DD or int128
MAXDIM3= 105562
// for DD-Complex
MAXDIM4= 74643
// for half or int16
MAXDIM5= 298574
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1000
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 266 ) {
	BLK = 0;
} else
if ( n >= 266 && n < 267 ) {
	BLK = 2;
} else
if ( n >= 267 && n < 296 ) {
	BLK = 1;
} else
if ( n >= 296 && n < 329 ) {
	BLK = 0;
} else
if ( n >= 329 && n < 330 ) {
	BLK = 2;
} else
if ( n >= 330 && n < 349 ) {
	BLK = 1;
} else
if ( n >= 349 && n < 518 ) {
	BLK = 0;
} else
if ( n >= 518 && n < 519 ) {
	BLK = 2;
} else
if ( n >= 519 && n < 520 ) {
	BLK = 1;
} else
if ( n >= 520 && n < 531 ) {
	BLK = 0;
} else
if ( n >= 531 && n < 532 ) {
	BLK = 1;
} else
if ( n >= 532 && n < 534 ) {
	BLK = 2;
} else
if ( n >= 534 && n < 558 ) {
	BLK = 0;
} else
if ( n >= 558 && n < 559 ) {
	BLK = 1;
} else
if ( n >= 559 && n < 567 ) {
	BLK = 2;
} else
if ( n >= 567 && n < 606 ) {
	BLK = 0;
} else
if ( n >= 606 && n < 607 ) {
	BLK = 1;
} else
if ( n >= 607 && n < 608 ) {
	BLK = 2;
} else
if ( n >= 608 && n < 615 ) {
	BLK = 0;
} else
if ( n >= 615 && n < 644 ) {
	BLK = 1;
} else
if ( n >= 644 && n < 651 ) {
	BLK = 0;
} else
if ( n >= 651 && n < 652 ) {
	BLK = 2;
} else
if ( n >= 652 && n < 745 ) {
	BLK = 1;
} else
if ( n >= 745 && n < 934 ) {
	BLK = 0;
} else
if ( n >= 934 && n < 935 ) {
	BLK = 1;
} else
if ( n >= 935 && n < 946 ) {
	BLK = 2;
} else
if ( n >= 946 && n < 1414 ) {
	BLK = 0;
} else
if ( n >= 1414 && n < 1415 ) {
	BLK = 2;
} else
if ( n >= 1415 && n < 1416 ) {
	BLK = 1;
} else
if ( n >= 1416 && n < 2074 ) {
	BLK = 0;
} else
if ( n >= 2074 && n < 2075 ) {
	BLK = 1;
} else
if ( n >= 2075 && n < 2076 ) {
	BLK = 2;
} else
if ( n >= 2076 && n < 6541 ) {
	BLK = 0;
} else
if ( n >= 6541 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
