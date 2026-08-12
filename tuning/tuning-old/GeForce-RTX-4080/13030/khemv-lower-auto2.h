#ifndef KHEMVL_AUTO2_H_INCLUDED
#define KHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVL
 Thu Jul 30 17:27:54  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2492 ) {
	BLK = 0;
} else
if ( n >= 2492 && n < 4252 ) {
	BLK = 5;
} else
if ( n >= 4252 && n < 4782 ) {
	BLK = 3;
} else
if ( n >= 4782 && n < 5523 ) {
	BLK = 0;
} else
if ( n >= 5523 && n < 5861 ) {
	BLK = 1;
} else
if ( n >= 5861 && n < 9616 ) {
	BLK = 3;
} else
if ( n >= 9616 && n < 9621 ) {
	BLK = 1;
} else
if ( n >= 9621 && n < 9686 ) {
	BLK = 4;
} else
if ( n >= 9686 && n < 9712 ) {
	BLK = 3;
} else
if ( n >= 9712 && n < 9724 ) {
	BLK = 1;
} else
if ( n >= 9724 && n < 10424 ) {
	BLK = 5;
} else
if ( n >= 10424 && n < 11284 ) {
	BLK = 1;
} else
if ( n >= 11284 && n < 11295 ) {
	BLK = 4;
} else
if ( n >= 11295 && n < 11419 ) {
	BLK = 5;
} else
if ( n >= 11419 && n < 11634 ) {
	BLK = 1;
} else
if ( n >= 11634 && n < 12090 ) {
	BLK = 4;
} else
if ( n >= 12090 && n < 18967 ) {
	BLK = 1;
} else
if ( n >= 18967 && n < 19709 ) {
	BLK = 4;
} else
if ( n >= 19709 && n < 21166 ) {
	BLK = 1;
} else
if ( n >= 21166 && n < 21623 ) {
	BLK = 4;
} else
if ( n >= 21623 && n < 22229 ) {
	BLK = 1;
} else
if ( n >= 22229 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
