#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Wed Jul 29 16:54:21  2026
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

if ( n >= 1 && n < 3 ) {
	BLK = 5;
} else
if ( n >= 3 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 23 ) {
	BLK = 3;
} else
if ( n >= 23 && n < 41 ) {
	BLK = 5;
} else
if ( n >= 41 && n < 44 ) {
	BLK = 1;
} else
if ( n >= 44 && n < 45 ) {
	BLK = 2;
} else
if ( n >= 45 && n < 137 ) {
	BLK = 5;
} else
if ( n >= 137 && n < 1878 ) {
	BLK = 4;
} else
if ( n >= 1878 && n < 3711 ) {
	BLK = 1;
} else
if ( n >= 3711 && n < 3730 ) {
	BLK = 2;
} else
if ( n >= 3730 && n < 3857 ) {
	BLK = 1;
} else
if ( n >= 3857 && n < 3858 ) {
	BLK = 3;
} else
if ( n >= 3858 && n < 3863 ) {
	BLK = 2;
} else
if ( n >= 3863 && n < 3864 ) {
	BLK = 1;
} else
if ( n >= 3864 && n < 3865 ) {
	BLK = 3;
} else
if ( n >= 3865 && n < 3868 ) {
	BLK = 2;
} else
if ( n >= 3868 && n < 7316 ) {
	BLK = 1;
} else
if ( n >= 7316 && n < 8156 ) {
	BLK = 3;
} else
if ( n >= 8156 && n < 9163 ) {
	BLK = 1;
} else
if ( n >= 9163 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
