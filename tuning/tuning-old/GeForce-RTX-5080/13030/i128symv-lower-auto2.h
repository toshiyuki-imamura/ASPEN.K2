#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Fri Aug 07 09:43:47  2026
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

if ( n >= 1 && n < 12 ) {
	BLK = 5;
} else
if ( n >= 12 && n < 16 ) {
	BLK = 3;
} else
if ( n >= 16 && n < 17 ) {
	BLK = 5;
} else
if ( n >= 17 && n < 18 ) {
	BLK = 2;
} else
if ( n >= 18 && n < 22 ) {
	BLK = 3;
} else
if ( n >= 22 && n < 36 ) {
	BLK = 5;
} else
if ( n >= 36 && n < 43 ) {
	BLK = 1;
} else
if ( n >= 43 && n < 46 ) {
	BLK = 4;
} else
if ( n >= 46 && n < 154 ) {
	BLK = 3;
} else
if ( n >= 154 && n < 157 ) {
	BLK = 4;
} else
if ( n >= 157 && n < 158 ) {
	BLK = 2;
} else
if ( n >= 158 && n < 256 ) {
	BLK = 3;
} else
if ( n >= 256 && n < 348 ) {
	BLK = 2;
} else
if ( n >= 348 && n < 477 ) {
	BLK = 5;
} else
if ( n >= 477 && n < 2902 ) {
	BLK = 1;
} else
if ( n >= 2902 && n < 4749 ) {
	BLK = 2;
} else
if ( n >= 4749 && n < 4755 ) {
	BLK = 1;
} else
if ( n >= 4755 && n < 4757 ) {
	BLK = 4;
} else
if ( n >= 4757 && n < 5136 ) {
	BLK = 2;
} else
if ( n >= 5136 && n < 6217 ) {
	BLK = 4;
} else
if ( n >= 6217 && n < 8737 ) {
	BLK = 1;
} else
if ( n >= 8737 && n < 21077 ) {
	BLK = 3;
} else
if ( n >= 21077 && n < 21137 ) {
	BLK = 5;
} else
if ( n >= 21137 && n < 21365 ) {
	BLK = 1;
} else
if ( n >= 21365 && n < 25554 ) {
	BLK = 3;
} else
if ( n >= 25554 && n < 25557 ) {
	BLK = 1;
} else
if ( n >= 25557 && n < 25753 ) {
	BLK = 5;
} else
if ( n >= 25753 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
