#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Thu Aug 06 06:01:29  2026
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

if ( n >= 1 && n < 7 ) {
	BLK = 3;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 4;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 2;
} else
if ( n >= 9 && n < 11 ) {
	BLK = 1;
} else
if ( n >= 11 && n < 12 ) {
	BLK = 3;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 4;
} else
if ( n >= 13 && n < 14 ) {
	BLK = 1;
} else
if ( n >= 14 && n < 17 ) {
	BLK = 3;
} else
if ( n >= 17 && n < 24 ) {
	BLK = 4;
} else
if ( n >= 24 && n < 25 ) {
	BLK = 1;
} else
if ( n >= 25 && n < 33 ) {
	BLK = 5;
} else
if ( n >= 33 && n < 143 ) {
	BLK = 4;
} else
if ( n >= 143 && n < 144 ) {
	BLK = 2;
} else
if ( n >= 144 && n < 158 ) {
	BLK = 5;
} else
if ( n >= 158 && n < 181 ) {
	BLK = 2;
} else
if ( n >= 181 && n < 436 ) {
	BLK = 4;
} else
if ( n >= 436 && n < 2670 ) {
	BLK = 1;
} else
if ( n >= 2670 && n < 2864 ) {
	BLK = 3;
} else
if ( n >= 2864 && n < 4507 ) {
	BLK = 4;
} else
if ( n >= 4507 && n < 6034 ) {
	BLK = 5;
} else
if ( n >= 6034 && n < 8864 ) {
	BLK = 3;
} else
if ( n >= 8864 && n < 8949 ) {
	BLK = 2;
} else
if ( n >= 8949 && n < 8995 ) {
	BLK = 1;
} else
if ( n >= 8995 && n < 9091 ) {
	BLK = 2;
} else
if ( n >= 9091 && n < 9135 ) {
	BLK = 3;
} else
if ( n >= 9135 && n < 9141 ) {
	BLK = 1;
} else
if ( n >= 9141 && n < 9257 ) {
	BLK = 2;
} else
if ( n >= 9257 && n < 9278 ) {
	BLK = 3;
} else
if ( n >= 9278 && n < 11161 ) {
	BLK = 1;
} else
if ( n >= 11161 && n < 11643 ) {
	BLK = 2;
} else
if ( n >= 11643 && n < 20552 ) {
	BLK = 1;
} else
if ( n >= 20552 && n < 20859 ) {
	BLK = 2;
} else
if ( n >= 20859 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
