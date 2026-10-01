#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Sat Sep 26 16:40:54  2026
 Host on fermat.r-ccs27.riken.jp
 Device is RTX-A5000
****************************************/-->
// device name
DEVICE= RTX-A5000
// the number of multi-processors
MP= 64
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 25327001600
// capacity of the work area reserved on the GPU
WORK= 3118080
// for double or cuFloatComplex or int64
MAXDIM= 53452
// for float or cuHalfComplex or int32
MAXDIM2= 75593
// for cuDoubleComplex or DD or int128
MAXDIM3= 37796
// for DD-Complex
MAXDIM4= 26726
// for half or int16
MAXDIM5= 106905
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


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1424 ) {
	BLK = 0;
} else
if ( n >= 1424 && n < 3165 ) {
	BLK = 1;
} else
if ( n >= 3165 && n < 4220 ) {
	BLK = 2;
} else
if ( n >= 4220 && n < 7288 ) {
	BLK = 1;
} else
if ( n >= 7288 && n < 12100 ) {
	BLK = 2;
} else
if ( n >= 12100 && n < 13300 ) {
	BLK = 4;
} else
if ( n >= 13300 && n < 13736 ) {
	BLK = 2;
} else
if ( n >= 13736 && n < 14293 ) {
	BLK = 4;
} else
if ( n >= 14293 && n < 14305 ) {
	BLK = 1;
} else
if ( n >= 14305 && n < 14941 ) {
	BLK = 2;
} else
if ( n >= 14941 && n < 15468 ) {
	BLK = 4;
} else
if ( n >= 15468 && n < 15738 ) {
	BLK = 2;
} else
if ( n >= 15738 && n < 16571 ) {
	BLK = 4;
} else
if ( n >= 16571 && n < 17404 ) {
	BLK = 2;
} else
if ( n >= 17404 && n < 18028 ) {
	BLK = 4;
} else
if ( n >= 18028 && n < 18215 ) {
	BLK = 3;
} else
if ( n >= 18215 && n < 18340 ) {
	BLK = 1;
} else
if ( n >= 18340 && n < 19323 ) {
	BLK = 2;
} else
if ( n >= 19323 && n < 21540 ) {
	BLK = 4;
} else
if ( n >= 21540 && n < 21874 ) {
	BLK = 2;
} else
if ( n >= 21874 && n < 22188 ) {
	BLK = 4;
} else
if ( n >= 22188 && n < 23999 ) {
	BLK = 2;
} else
if ( n >= 23999 && n < 25399 ) {
	BLK = 4;
} else
if ( n >= 25399 && n < 27381 ) {
	BLK = 2;
} else
if ( n >= 27381 && n < 27938 ) {
	BLK = 4;
} else
if ( n >= 27938 && n < 33409 ) {
	BLK = 2;
} else
if ( n >= 33409 && n < 34019 ) {
	BLK = 4;
} else
if ( n >= 34019 && n < 37859 ) {
	BLK = 2;
} else
if ( n >= 37859 && n < 41284 ) {
	BLK = 4;
} else
if ( n >= 41284 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
