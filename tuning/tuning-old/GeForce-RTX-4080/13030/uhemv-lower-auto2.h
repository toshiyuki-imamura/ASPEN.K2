#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Thu Jul 30 06:43:04  2026
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
MAXmem= 16743747584
// capacity of the work area reserved on the GPU
WORK= 2534400
// for double or cuFloatComplex or int64
MAXDIM= 43461
// for float or cuHalfComplex or int32
MAXDIM2= 61463
// for cuDoubleComplex or DD or int128
MAXDIM3= 30731
// for DD-Complex
MAXDIM4= 21730
// for half or int16
MAXDIM5= 86923
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 4 ) {
	BLK = 2;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 4;
} else
if ( n >= 5 && n < 11 ) {
	BLK = 1;
} else
if ( n >= 11 && n < 13 ) {
	BLK = 4;
} else
if ( n >= 13 && n < 23 ) {
	BLK = 3;
} else
if ( n >= 23 && n < 2450 ) {
	BLK = 5;
} else
if ( n >= 2450 && n < 3360 ) {
	BLK = 2;
} else
if ( n >= 3360 && n < 6503 ) {
	BLK = 1;
} else
if ( n >= 6503 && n < 6873 ) {
	BLK = 4;
} else
if ( n >= 6873 && n < 7017 ) {
	BLK = 2;
} else
if ( n >= 7017 && n < 7951 ) {
	BLK = 3;
} else
if ( n >= 7951 && n < 8655 ) {
	BLK = 1;
} else
if ( n >= 8655 && n < 9754 ) {
	BLK = 3;
} else
if ( n >= 9754 && n < 10229 ) {
	BLK = 1;
} else
if ( n >= 10229 && n < 13052 ) {
	BLK = 3;
} else
if ( n >= 13052 && n < 13508 ) {
	BLK = 1;
} else
if ( n >= 13508 && n < 20014 ) {
	BLK = 3;
} else
if ( n >= 20014 && n < 21004 ) {
	BLK = 1;
} else
if ( n >= 21004 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
