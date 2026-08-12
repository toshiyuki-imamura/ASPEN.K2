#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Wed Jul 29 19:46:53  2026
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

if ( n >= 1 && n < 8 ) {
	BLK = 3;
} else
if ( n >= 8 && n < 12 ) {
	BLK = 5;
} else
if ( n >= 12 && n < 16 ) {
	BLK = 4;
} else
if ( n >= 16 && n < 1548 ) {
	BLK = 3;
} else
if ( n >= 1548 && n < 1549 ) {
	BLK = 5;
} else
if ( n >= 1549 && n < 1553 ) {
	BLK = 2;
} else
if ( n >= 1553 && n < 1555 ) {
	BLK = 3;
} else
if ( n >= 1555 && n < 1556 ) {
	BLK = 5;
} else
if ( n >= 1556 && n < 1567 ) {
	BLK = 2;
} else
if ( n >= 1567 && n < 1568 ) {
	BLK = 5;
} else
if ( n >= 1568 && n < 1572 ) {
	BLK = 3;
} else
if ( n >= 1572 && n < 1574 ) {
	BLK = 5;
} else
if ( n >= 1574 && n < 2276 ) {
	BLK = 2;
} else
if ( n >= 2276 && n < 2942 ) {
	BLK = 4;
} else
if ( n >= 2942 && n < 5014 ) {
	BLK = 2;
} else
if ( n >= 5014 && n < 9244 ) {
	BLK = 1;
} else
if ( n >= 9244 && n < 25804 ) {
	BLK = 3;
} else
if ( n >= 25804 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
