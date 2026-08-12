#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Mon Jul 27 01:39:24  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3 ) {
	BLK = 0;
} else
if ( n >= 3 && n < 6 ) {
	BLK = 2;
} else
if ( n >= 6 && n < 7 ) {
	BLK = 3;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 1;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 0;
} else
if ( n >= 9 && n < 12 ) {
	BLK = 3;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 1;
} else
if ( n >= 13 && n < 15 ) {
	BLK = 2;
} else
if ( n >= 15 && n < 16 ) {
	BLK = 3;
} else
if ( n >= 16 && n < 23 ) {
	BLK = 1;
} else
if ( n >= 23 && n < 167 ) {
	BLK = 0;
} else
if ( n >= 167 && n < 1232 ) {
	BLK = 2;
} else
if ( n >= 1232 && n < 3389 ) {
	BLK = 3;
} else
if ( n >= 3389 && n < 3839 ) {
	BLK = 2;
} else
if ( n >= 3839 && n < 5266 ) {
	BLK = 1;
} else
if ( n >= 5266 && n < 8704 ) {
	BLK = 2;
} else
if ( n >= 8704 && n < 9572 ) {
	BLK = 1;
} else
if ( n >= 9572 && n < 11041 ) {
	BLK = 2;
} else
if ( n >= 11041 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
