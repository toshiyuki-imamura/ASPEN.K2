#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Wed Jul 29 07:02:16  2026
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

if ( n >= 1 && n < 1404 ) {
	BLK = 0;
} else
if ( n >= 1404 && n < 1405 ) {
	BLK = 1;
} else
if ( n >= 1405 && n < 1408 ) {
	BLK = 2;
} else
if ( n >= 1408 && n < 1494 ) {
	BLK = 0;
} else
if ( n >= 1494 && n < 1495 ) {
	BLK = 1;
} else
if ( n >= 1495 && n < 1496 ) {
	BLK = 2;
} else
if ( n >= 1496 && n < 1502 ) {
	BLK = 0;
} else
if ( n >= 1502 && n < 1505 ) {
	BLK = 1;
} else
if ( n >= 1505 && n < 1507 ) {
	BLK = 0;
} else
if ( n >= 1507 && n < 1512 ) {
	BLK = 2;
} else
if ( n >= 1512 && n < 1519 ) {
	BLK = 0;
} else
if ( n >= 1519 && n < 1520 ) {
	BLK = 2;
} else
if ( n >= 1520 && n < 1521 ) {
	BLK = 1;
} else
if ( n >= 1521 && n < 1526 ) {
	BLK = 0;
} else
if ( n >= 1526 && n < 1527 ) {
	BLK = 1;
} else
if ( n >= 1527 && n < 3903 ) {
	BLK = 2;
} else
if ( n >= 3903 && n < 6296 ) {
	BLK = 1;
} else
if ( n >= 6296 && n < 8412 ) {
	BLK = 2;
} else
if ( n >= 8412 && n < 14963 ) {
	BLK = 3;
} else
if ( n >= 14963 && n < 15676 ) {
	BLK = 2;
} else
if ( n >= 15676 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
