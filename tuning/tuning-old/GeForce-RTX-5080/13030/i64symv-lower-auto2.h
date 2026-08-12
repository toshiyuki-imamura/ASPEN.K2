#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Fri Aug 07 13:59:53  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1096 ) {
	BLK = 0;
} else
if ( n >= 1096 && n < 1348 ) {
	BLK = 1;
} else
if ( n >= 1348 && n < 1349 ) {
	BLK = 0;
} else
if ( n >= 1349 && n < 1357 ) {
	BLK = 4;
} else
if ( n >= 1357 && n < 1363 ) {
	BLK = 1;
} else
if ( n >= 1363 && n < 1364 ) {
	BLK = 4;
} else
if ( n >= 1364 && n < 1373 ) {
	BLK = 0;
} else
if ( n >= 1373 && n < 1396 ) {
	BLK = 1;
} else
if ( n >= 1396 && n < 1397 ) {
	BLK = 4;
} else
if ( n >= 1397 && n < 1398 ) {
	BLK = 0;
} else
if ( n >= 1398 && n < 1476 ) {
	BLK = 1;
} else
if ( n >= 1476 && n < 1477 ) {
	BLK = 3;
} else
if ( n >= 1477 && n < 1478 ) {
	BLK = 0;
} else
if ( n >= 1478 && n < 2201 ) {
	BLK = 1;
} else
if ( n >= 2201 && n < 3840 ) {
	BLK = 3;
} else
if ( n >= 3840 && n < 6012 ) {
	BLK = 1;
} else
if ( n >= 6012 && n < 7368 ) {
	BLK = 3;
} else
if ( n >= 7368 && n < 9166 ) {
	BLK = 4;
} else
if ( n >= 9166 && n < 9290 ) {
	BLK = 2;
} else
if ( n >= 9290 && n < 9650 ) {
	BLK = 4;
} else
if ( n >= 9650 && n < 21084 ) {
	BLK = 2;
} else
if ( n >= 21084 && n < 21359 ) {
	BLK = 5;
} else
if ( n >= 21359 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
