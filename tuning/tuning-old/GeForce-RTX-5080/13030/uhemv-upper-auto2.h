#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Fri Aug 07 23:14:39  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16647024640
// capacity of the work area reserved on the GPU
WORK= 2526720
// for double or cuFloatComplex or int64
MAXDIM= 43335
// for float or cuHalfComplex or int32
MAXDIM2= 61286
// for cuDoubleComplex or DD or int128
MAXDIM3= 30643
// for DD-Complex
MAXDIM4= 21667
// for half or int16
MAXDIM5= 86671
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1200
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 11 ) {
	BLK = 2;
} else
if ( n >= 11 && n < 13 ) {
	BLK = 4;
} else
if ( n >= 13 && n < 21 ) {
	BLK = 5;
} else
if ( n >= 21 && n < 3602 ) {
	BLK = 1;
} else
if ( n >= 3602 && n < 4411 ) {
	BLK = 2;
} else
if ( n >= 4411 && n < 4632 ) {
	BLK = 3;
} else
if ( n >= 4632 && n < 4645 ) {
	BLK = 4;
} else
if ( n >= 4645 && n < 4651 ) {
	BLK = 2;
} else
if ( n >= 4651 && n < 6606 ) {
	BLK = 1;
} else
if ( n >= 6606 && n < 6650 ) {
	BLK = 4;
} else
if ( n >= 6650 && n < 7021 ) {
	BLK = 5;
} else
if ( n >= 7021 && n < 7087 ) {
	BLK = 4;
} else
if ( n >= 7087 && n < 7141 ) {
	BLK = 2;
} else
if ( n >= 7141 && n < 7159 ) {
	BLK = 5;
} else
if ( n >= 7159 && n < 7191 ) {
	BLK = 4;
} else
if ( n >= 7191 && n < 8526 ) {
	BLK = 2;
} else
if ( n >= 8526 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
