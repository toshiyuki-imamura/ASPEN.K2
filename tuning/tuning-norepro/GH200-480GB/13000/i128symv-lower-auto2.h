#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Mon Nov 17 17:44:32  2025
 Host on shannon.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16585474048
// capacity of the work area reserved on the GPU
WORK= 504832
// for double or cuFloatComplex or int64
MAXDIM= 43255
// for float or cuHalfComplex or int32
MAXDIM2= 61172
// for cuDoubleComplex or DD or int128
MAXDIM3= 30586
// for DD-Complex
MAXDIM4= 21627
// for half or int16
MAXDIM5= 86511
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 1200
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

if ( n >= 1 && n < 2 ) {
	BLK = 2;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 5;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 3;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 6;
} else
if ( n >= 5 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 11 ) {
	BLK = 5;
} else
if ( n >= 11 && n < 14 ) {
	BLK = 2;
} else
if ( n >= 14 && n < 18 ) {
	BLK = 5;
} else
if ( n >= 18 && n < 32 ) {
	BLK = 2;
} else
if ( n >= 32 && n < 1023 ) {
	BLK = 4;
} else
if ( n >= 1023 && n < 1331 ) {
	BLK = 2;
} else
if ( n >= 1331 && n < 1332 ) {
	BLK = 6;
} else
if ( n >= 1332 && n < 1333 ) {
	BLK = 3;
} else
if ( n >= 1333 && n < 1408 ) {
	BLK = 2;
} else
if ( n >= 1408 && n < 2783 ) {
	BLK = 3;
} else
if ( n >= 2783 && n < 2937 ) {
	BLK = 6;
} else
if ( n >= 2937 && n < 4721 ) {
	BLK = 1;
} else
if ( n >= 4721 && n < 7401 ) {
	BLK = 5;
} else
if ( n >= 7401 && n < 9552 ) {
	BLK = 6;
} else
if ( n >= 9552 && n < 23332 ) {
	BLK = 5;
} else
if ( n >= 23332 && n < 23918 ) {
	BLK = 6;
} else
if ( n >= 23918 && n < 25337 ) {
	BLK = 5;
} else
if ( n >= 25337 && n < 26005 ) {
	BLK = 6;
} else
if ( n >= 26005 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
