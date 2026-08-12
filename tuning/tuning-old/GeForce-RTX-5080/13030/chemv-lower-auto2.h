#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Sat Aug 08 20:10:22  2026
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

if ( n >= 1 && n < 468 ) {
	BLK = 0;
} else
if ( n >= 468 && n < 481 ) {
	BLK = 4;
} else
if ( n >= 481 && n < 486 ) {
	BLK = 0;
} else
if ( n >= 486 && n < 489 ) {
	BLK = 4;
} else
if ( n >= 489 && n < 490 ) {
	BLK = 5;
} else
if ( n >= 490 && n < 491 ) {
	BLK = 0;
} else
if ( n >= 491 && n < 493 ) {
	BLK = 2;
} else
if ( n >= 493 && n < 498 ) {
	BLK = 4;
} else
if ( n >= 498 && n < 503 ) {
	BLK = 5;
} else
if ( n >= 503 && n < 505 ) {
	BLK = 4;
} else
if ( n >= 505 && n < 506 ) {
	BLK = 2;
} else
if ( n >= 506 && n < 510 ) {
	BLK = 5;
} else
if ( n >= 510 && n < 511 ) {
	BLK = 0;
} else
if ( n >= 511 && n < 523 ) {
	BLK = 2;
} else
if ( n >= 523 && n < 587 ) {
	BLK = 4;
} else
if ( n >= 587 && n < 644 ) {
	BLK = 2;
} else
if ( n >= 644 && n < 645 ) {
	BLK = 0;
} else
if ( n >= 645 && n < 648 ) {
	BLK = 4;
} else
if ( n >= 648 && n < 671 ) {
	BLK = 2;
} else
if ( n >= 671 && n < 672 ) {
	BLK = 0;
} else
if ( n >= 672 && n < 674 ) {
	BLK = 1;
} else
if ( n >= 674 && n < 677 ) {
	BLK = 2;
} else
if ( n >= 677 && n < 679 ) {
	BLK = 0;
} else
if ( n >= 679 && n < 680 ) {
	BLK = 1;
} else
if ( n >= 680 && n < 1343 ) {
	BLK = 2;
} else
if ( n >= 1343 && n < 1509 ) {
	BLK = 1;
} else
if ( n >= 1509 && n < 1596 ) {
	BLK = 3;
} else
if ( n >= 1596 && n < 2973 ) {
	BLK = 2;
} else
if ( n >= 2973 && n < 2976 ) {
	BLK = 1;
} else
if ( n >= 2976 && n < 2977 ) {
	BLK = 3;
} else
if ( n >= 2977 && n < 3197 ) {
	BLK = 2;
} else
if ( n >= 3197 && n < 3265 ) {
	BLK = 1;
} else
if ( n >= 3265 && n < 3282 ) {
	BLK = 3;
} else
if ( n >= 3282 && n < 3328 ) {
	BLK = 2;
} else
if ( n >= 3328 && n < 3346 ) {
	BLK = 3;
} else
if ( n >= 3346 && n < 3390 ) {
	BLK = 1;
} else
if ( n >= 3390 && n < 3524 ) {
	BLK = 3;
} else
if ( n >= 3524 && n < 3528 ) {
	BLK = 1;
} else
if ( n >= 3528 && n < 3529 ) {
	BLK = 2;
} else
if ( n >= 3529 && n < 5850 ) {
	BLK = 3;
} else
if ( n >= 5850 && n < 6019 ) {
	BLK = 4;
} else
if ( n >= 6019 && n < 7039 ) {
	BLK = 2;
} else
if ( n >= 7039 && n < 8475 ) {
	BLK = 5;
} else
if ( n >= 8475 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
