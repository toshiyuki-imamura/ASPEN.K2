#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Mon Jul 27 20:11:42  2026
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


// default kernel is
BLK = 1;

if ( n >= 1 && n < 5 ) {
	BLK = 2;
} else
if ( n >= 5 && n < 6 ) {
	BLK = 1;
} else
if ( n >= 6 && n < 7 ) {
	BLK = 3;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 23 ) {
	BLK = 1;
} else
if ( n >= 23 && n < 30 ) {
	BLK = 3;
} else
if ( n >= 30 && n < 73 ) {
	BLK = 1;
} else
if ( n >= 73 && n < 74 ) {
	BLK = 2;
} else
if ( n >= 74 && n < 75 ) {
	BLK = 3;
} else
if ( n >= 75 && n < 91 ) {
	BLK = 1;
} else
if ( n >= 91 && n < 94 ) {
	BLK = 2;
} else
if ( n >= 94 && n < 95 ) {
	BLK = 3;
} else
if ( n >= 95 && n < 140 ) {
	BLK = 1;
} else
if ( n >= 140 && n < 141 ) {
	BLK = 3;
} else
if ( n >= 141 && n < 150 ) {
	BLK = 2;
} else
if ( n >= 150 && n < 151 ) {
	BLK = 1;
} else
if ( n >= 151 && n < 152 ) {
	BLK = 3;
} else
if ( n >= 152 && n < 156 ) {
	BLK = 2;
} else
if ( n >= 156 && n < 171 ) {
	BLK = 1;
} else
if ( n >= 171 && n < 172 ) {
	BLK = 2;
} else
if ( n >= 172 && n < 173 ) {
	BLK = 3;
} else
if ( n >= 173 && n < 204 ) {
	BLK = 1;
} else
if ( n >= 204 && n < 205 ) {
	BLK = 2;
} else
if ( n >= 205 && n < 206 ) {
	BLK = 3;
} else
if ( n >= 206 && n < 648 ) {
	BLK = 1;
} else
if ( n >= 648 && n < 649 ) {
	BLK = 2;
} else
if ( n >= 649 && n < 650 ) {
	BLK = 3;
} else
if ( n >= 650 && n < 882 ) {
	BLK = 1;
} else
if ( n >= 882 && n < 883 ) {
	BLK = 3;
} else
if ( n >= 883 && n < 895 ) {
	BLK = 2;
} else
if ( n >= 895 && n < 896 ) {
	BLK = 3;
} else
if ( n >= 896 && n < 911 ) {
	BLK = 1;
} else
if ( n >= 911 && n < 914 ) {
	BLK = 2;
} else
if ( n >= 914 && n < 916 ) {
	BLK = 3;
} else
if ( n >= 916 && n < 2781 ) {
	BLK = 1;
} else
if ( n >= 2781 && n < 4902 ) {
	BLK = 3;
} else
if ( n >= 4902 && n < 9310 ) {
	BLK = 1;
} else
if ( n >= 9310 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
