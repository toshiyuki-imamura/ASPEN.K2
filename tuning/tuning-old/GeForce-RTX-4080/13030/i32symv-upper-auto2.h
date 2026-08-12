#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Tue Jul 28 07:32:46  2026
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

if ( n >= 1 && n < 13 ) {
	BLK = 3;
} else
if ( n >= 13 && n < 58 ) {
	BLK = 0;
} else
if ( n >= 58 && n < 59 ) {
	BLK = 2;
} else
if ( n >= 59 && n < 125 ) {
	BLK = 1;
} else
if ( n >= 125 && n < 980 ) {
	BLK = 0;
} else
if ( n >= 980 && n < 982 ) {
	BLK = 2;
} else
if ( n >= 982 && n < 991 ) {
	BLK = 1;
} else
if ( n >= 991 && n < 1245 ) {
	BLK = 0;
} else
if ( n >= 1245 && n < 1246 ) {
	BLK = 1;
} else
if ( n >= 1246 && n < 1247 ) {
	BLK = 2;
} else
if ( n >= 1247 && n < 3395 ) {
	BLK = 0;
} else
if ( n >= 3395 && n < 3396 ) {
	BLK = 2;
} else
if ( n >= 3396 && n < 5370 ) {
	BLK = 1;
} else
if ( n >= 5370 && n < 5394 ) {
	BLK = 3;
} else
if ( n >= 5394 && n < 5400 ) {
	BLK = 0;
} else
if ( n >= 5400 && n < 5421 ) {
	BLK = 1;
} else
if ( n >= 5421 && n < 5507 ) {
	BLK = 3;
} else
if ( n >= 5507 && n < 6164 ) {
	BLK = 0;
} else
if ( n >= 6164 && n < 9021 ) {
	BLK = 3;
} else
if ( n >= 9021 && n < 15124 ) {
	BLK = 1;
} else
if ( n >= 15124 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
