#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Wed Aug 05 00:59:11  2026
 Host on qc-gh200-04.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 101997334528
// capacity of the work area reserved on the GPU
WORK= 8136960
// for double or cuFloatComplex or int64
MAXDIM= 107268
// for float or cuHalfComplex or int32
MAXDIM2= 151700
// for cuDoubleComplex or DD or int128
MAXDIM3= 75850
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214537
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
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

if ( n >= 1 && n < 2238 ) {
	BLK = 0;
} else
if ( n >= 2238 && n < 3498 ) {
	BLK = 1;
} else
if ( n >= 3498 && n < 4221 ) {
	BLK = 2;
} else
if ( n >= 4221 && n < 10435 ) {
	BLK = 3;
} else
if ( n >= 10435 && n < 10488 ) {
	BLK = 4;
} else
if ( n >= 10488 && n < 10493 ) {
	BLK = 2;
} else
if ( n >= 10493 && n < 10709 ) {
	BLK = 3;
} else
if ( n >= 10709 && n < 10754 ) {
	BLK = 5;
} else
if ( n >= 10754 && n < 10806 ) {
	BLK = 4;
} else
if ( n >= 10806 && n < 11145 ) {
	BLK = 3;
} else
if ( n >= 11145 && n < 11197 ) {
	BLK = 2;
} else
if ( n >= 11197 && n < 11263 ) {
	BLK = 5;
} else
if ( n >= 11263 && n < 11375 ) {
	BLK = 3;
} else
if ( n >= 11375 && n < 11460 ) {
	BLK = 4;
} else
if ( n >= 11460 && n < 11889 ) {
	BLK = 2;
} else
if ( n >= 11889 && n < 11988 ) {
	BLK = 4;
} else
if ( n >= 11988 && n < 12181 ) {
	BLK = 5;
} else
if ( n >= 12181 && n < 12201 ) {
	BLK = 2;
} else
if ( n >= 12201 && n < 12320 ) {
	BLK = 4;
} else
if ( n >= 12320 && n < 13069 ) {
	BLK = 5;
} else
if ( n >= 13069 && n < 13645 ) {
	BLK = 4;
} else
if ( n >= 13645 && n < 21015 ) {
	BLK = 2;
} else
if ( n >= 21015 && n < 21476 ) {
	BLK = 5;
} else
if ( n >= 21476 && n < 23924 ) {
	BLK = 2;
} else
if ( n >= 23924 && n < 24193 ) {
	BLK = 5;
} else
if ( n >= 24193 && n < 24845 ) {
	BLK = 2;
} else
if ( n >= 24845 && n < 25529 ) {
	BLK = 5;
} else
if ( n >= 25529 && n < 29247 ) {
	BLK = 2;
} else
if ( n >= 29247 && n < 29676 ) {
	BLK = 5;
} else
if ( n >= 29676 && n < 34620 ) {
	BLK = 2;
} else
if ( n >= 34620 && n < 35579 ) {
	BLK = 5;
} else
if ( n >= 35579 && n < 41587 ) {
	BLK = 2;
} else
if ( n >= 41587 && n < 42727 ) {
	BLK = 5;
} else
if ( n >= 42727 && n < 48900 ) {
	BLK = 2;
} else
if ( n >= 48900 && n < 51063 ) {
	BLK = 5;
} else
if ( n >= 51063 && n < 92979 ) {
	BLK = 2;
} else
if ( n >= 92979 && n < 96363 ) {
	BLK = 5;
} else
if ( n >= 96363 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
