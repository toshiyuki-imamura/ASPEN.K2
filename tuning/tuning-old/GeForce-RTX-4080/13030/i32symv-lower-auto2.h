#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Wed Jul 29 10:49:27  2026
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
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1503 ) {
	BLK = 0;
} else
if ( n >= 1503 && n < 1509 ) {
	BLK = 2;
} else
if ( n >= 1509 && n < 1510 ) {
	BLK = 1;
} else
if ( n >= 1510 && n < 1515 ) {
	BLK = 0;
} else
if ( n >= 1515 && n < 1516 ) {
	BLK = 2;
} else
if ( n >= 1516 && n < 1517 ) {
	BLK = 1;
} else
if ( n >= 1517 && n < 1519 ) {
	BLK = 0;
} else
if ( n >= 1519 && n < 8698 ) {
	BLK = 2;
} else
if ( n >= 8698 && n < 10590 ) {
	BLK = 1;
} else
if ( n >= 10590 && n < 19311 ) {
	BLK = 3;
} else
if ( n >= 19311 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
