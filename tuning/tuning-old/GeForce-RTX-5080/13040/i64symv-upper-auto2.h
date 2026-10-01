#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Sat Sep 26 06:21:04  2026
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

if ( n >= 1 && n < 423 ) {
	BLK = 0;
} else
if ( n >= 423 && n < 442 ) {
	BLK = 2;
} else
if ( n >= 442 && n < 467 ) {
	BLK = 1;
} else
if ( n >= 467 && n < 543 ) {
	BLK = 0;
} else
if ( n >= 543 && n < 544 ) {
	BLK = 2;
} else
if ( n >= 544 && n < 553 ) {
	BLK = 1;
} else
if ( n >= 553 && n < 564 ) {
	BLK = 0;
} else
if ( n >= 564 && n < 583 ) {
	BLK = 2;
} else
if ( n >= 583 && n < 618 ) {
	BLK = 0;
} else
if ( n >= 618 && n < 622 ) {
	BLK = 2;
} else
if ( n >= 622 && n < 638 ) {
	BLK = 1;
} else
if ( n >= 638 && n < 653 ) {
	BLK = 0;
} else
if ( n >= 653 && n < 675 ) {
	BLK = 2;
} else
if ( n >= 675 && n < 717 ) {
	BLK = 0;
} else
if ( n >= 717 && n < 718 ) {
	BLK = 2;
} else
if ( n >= 718 && n < 2285 ) {
	BLK = 1;
} else
if ( n >= 2285 && n < 2290 ) {
	BLK = 5;
} else
if ( n >= 2290 && n < 2291 ) {
	BLK = 3;
} else
if ( n >= 2291 && n < 3872 ) {
	BLK = 1;
} else
if ( n >= 3872 && n < 5596 ) {
	BLK = 3;
} else
if ( n >= 5596 && n < 6344 ) {
	BLK = 5;
} else
if ( n >= 6344 && n < 9634 ) {
	BLK = 1;
} else
if ( n >= 9634 && n < 12866 ) {
	BLK = 4;
} else
if ( n >= 12866 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
