#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Tue Sep 29 23:43:29  2026
 Host on qc-gh200-02.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 102123945984
// capacity of the work area reserved on the GPU
WORK= 8140288
// for double or cuFloatComplex or int64
MAXDIM= 107335
// for float or cuHalfComplex or int32
MAXDIM2= 151794
// for cuDoubleComplex or DD or int128
MAXDIM3= 75897
// for DD-Complex
MAXDIM4= 53667
// for half or int16
MAXDIM5= 214670
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 900
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

if ( n >= 1 && n < 2558 ) {
	BLK = 0;
} else
if ( n >= 2558 && n < 2559 ) {
	BLK = 2;
} else
if ( n >= 2559 && n < 2798 ) {
	BLK = 5;
} else
if ( n >= 2798 && n < 2859 ) {
	BLK = 0;
} else
if ( n >= 2859 && n < 3438 ) {
	BLK = 5;
} else
if ( n >= 3438 && n < 3439 ) {
	BLK = 3;
} else
if ( n >= 3439 && n < 3453 ) {
	BLK = 4;
} else
if ( n >= 3453 && n < 3470 ) {
	BLK = 5;
} else
if ( n >= 3470 && n < 3471 ) {
	BLK = 4;
} else
if ( n >= 3471 && n < 3472 ) {
	BLK = 3;
} else
if ( n >= 3472 && n < 3473 ) {
	BLK = 1;
} else
if ( n >= 3473 && n < 3474 ) {
	BLK = 5;
} else
if ( n >= 3474 && n < 3485 ) {
	BLK = 3;
} else
if ( n >= 3485 && n < 3570 ) {
	BLK = 4;
} else
if ( n >= 3570 && n < 3615 ) {
	BLK = 1;
} else
if ( n >= 3615 && n < 3616 ) {
	BLK = 3;
} else
if ( n >= 3616 && n < 3622 ) {
	BLK = 4;
} else
if ( n >= 3622 && n < 3625 ) {
	BLK = 1;
} else
if ( n >= 3625 && n < 3635 ) {
	BLK = 4;
} else
if ( n >= 3635 && n < 3674 ) {
	BLK = 3;
} else
if ( n >= 3674 && n < 3807 ) {
	BLK = 1;
} else
if ( n >= 3807 && n < 4488 ) {
	BLK = 4;
} else
if ( n >= 4488 && n < 6379 ) {
	BLK = 3;
} else
if ( n >= 6379 && n < 9431 ) {
	BLK = 1;
} else
if ( n >= 9431 && n < 15211 ) {
	BLK = 3;
} else
if ( n >= 15211 && n < 15438 ) {
	BLK = 1;
} else
if ( n >= 15438 && n < 15469 ) {
	BLK = 4;
} else
if ( n >= 15469 && n < 17877 ) {
	BLK = 3;
} else
if ( n >= 17877 && n < 18280 ) {
	BLK = 1;
} else
if ( n >= 18280 && n < 21711 ) {
	BLK = 3;
} else
if ( n >= 21711 && n < 22045 ) {
	BLK = 1;
} else
if ( n >= 22045 && n < 27722 ) {
	BLK = 3;
} else
if ( n >= 27722 && n < 28230 ) {
	BLK = 1;
} else
if ( n >= 28230 && n < 38062 ) {
	BLK = 3;
} else
if ( n >= 38062 && n < 38913 ) {
	BLK = 1;
} else
if ( n >= 38913 && n < 48370 ) {
	BLK = 3;
} else
if ( n >= 48370 && n < 50737 ) {
	BLK = 1;
} else
if ( n >= 50737 && n < 60800 ) {
	BLK = 3;
} else
if ( n >= 60800 && n < 63967 ) {
	BLK = 1;
} else
if ( n >= 63967 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
