#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Sat Sep 26 20:06:35  2026
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
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
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

if ( n >= 1 && n < 8128 ) {
	BLK = 0;
} else
if ( n >= 8128 && n < 8130 ) {
	BLK = 5;
} else
if ( n >= 8130 && n < 8473 ) {
	BLK = 4;
} else
if ( n >= 8473 && n < 12462 ) {
	BLK = 2;
} else
if ( n >= 12462 && n < 15996 ) {
	BLK = 4;
} else
if ( n >= 15996 && n < 25172 ) {
	BLK = 1;
} else
if ( n >= 25172 && n < 25896 ) {
	BLK = 3;
} else
if ( n >= 25896 && n < 26821 ) {
	BLK = 1;
} else
if ( n >= 26821 && n < 27117 ) {
	BLK = 3;
} else
if ( n >= 27117 && n < 27391 ) {
	BLK = 1;
} else
if ( n >= 27391 && n < 28910 ) {
	BLK = 3;
} else
if ( n >= 28910 && n < 30997 ) {
	BLK = 1;
} else
if ( n >= 30997 && n < 35773 ) {
	BLK = 3;
} else
if ( n >= 35773 && n < 36968 ) {
	BLK = 1;
} else
if ( n >= 36968 && n < 37364 ) {
	BLK = 3;
} else
if ( n >= 37364 && n < 41667 ) {
	BLK = 1;
} else
if ( n >= 41667 && n < 44455 ) {
	BLK = 3;
} else
if ( n >= 44455 && n < 45666 ) {
	BLK = 1;
} else
if ( n >= 45666 && n < 48859 ) {
	BLK = 3;
} else
if ( n >= 48859 && n < 49647 ) {
	BLK = 1;
} else
if ( n >= 49647 && n < 53772 ) {
	BLK = 3;
} else
if ( n >= 53772 && n < 56067 ) {
	BLK = 1;
} else
if ( n >= 56067 && n < 69195 ) {
	BLK = 3;
} else
if ( n >= 69195 && n < 72209 ) {
	BLK = 1;
} else
if ( n >= 72209 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
