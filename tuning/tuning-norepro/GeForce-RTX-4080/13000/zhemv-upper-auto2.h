#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Wed Oct 29 03:46:50  2025
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
MAXmem= 16715563008
// capacity of the work area reserved on the GPU
WORK= 506368
// for double or cuFloatComplex or int64
MAXDIM= 43424
// for float or cuHalfComplex or int32
MAXDIM2= 61412
// for cuDoubleComplex or DD or int128
MAXDIM3= 30706
// for DD-Complex
MAXDIM4= 21712
// for half or int16
MAXDIM5= 86849
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 4 ) {
	BLK = 1;
} else
if ( n >= 4 && n < 6 ) {
	BLK = 5;
} else
if ( n >= 6 && n < 8 ) {
	BLK = 6;
} else
if ( n >= 8 && n < 10 ) {
	BLK = 1;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 14 ) {
	BLK = 6;
} else
if ( n >= 14 && n < 20 ) {
	BLK = 1;
} else
if ( n >= 20 && n < 21 ) {
	BLK = 2;
} else
if ( n >= 21 && n < 27 ) {
	BLK = 4;
} else
if ( n >= 27 && n < 35 ) {
	BLK = 1;
} else
if ( n >= 35 && n < 999 ) {
	BLK = 2;
} else
if ( n >= 999 && n < 1004 ) {
	BLK = 6;
} else
if ( n >= 1004 && n < 1057 ) {
	BLK = 4;
} else
if ( n >= 1057 && n < 1058 ) {
	BLK = 2;
} else
if ( n >= 1058 && n < 1754 ) {
	BLK = 6;
} else
if ( n >= 1754 && n < 1800 ) {
	BLK = 2;
} else
if ( n >= 1800 && n < 1812 ) {
	BLK = 1;
} else
if ( n >= 1812 && n < 1905 ) {
	BLK = 6;
} else
if ( n >= 1905 && n < 2552 ) {
	BLK = 5;
} else
if ( n >= 2552 && n < 7773 ) {
	BLK = 1;
} else
if ( n >= 7773 && n < 17518 ) {
	BLK = 5;
} else
if ( n >= 17518 && n < 18173 ) {
	BLK = 6;
} else
if ( n >= 18173 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
