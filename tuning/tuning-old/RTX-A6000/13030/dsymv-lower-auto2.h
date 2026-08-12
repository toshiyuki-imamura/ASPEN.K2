#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Sat Jul 25 18:45:55  2026
 Host on pascal.r-ccs27.riken.jp
 Device is RTX-A6000
****************************************/-->
// device name
DEVICE= RTX-A6000
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 50892406784
// capacity of the work area reserved on the GPU
WORK= 4421120
// for double or cuFloatComplex or int64
MAXDIM= 75771
// for float or cuHalfComplex or int32
MAXDIM2= 107156
// for cuDoubleComplex or DD or int128
MAXDIM3= 53578
// for DD-Complex
MAXDIM4= 37885
// for half or int16
MAXDIM5= 151542
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 4 ) {
	BLK = 0;
} else
if ( n >= 4 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 13 ) {
	BLK = 0;
} else
if ( n >= 13 && n < 14 ) {
	BLK = 2;
} else
if ( n >= 14 && n < 15 ) {
	BLK = 3;
} else
if ( n >= 15 && n < 39 ) {
	BLK = 0;
} else
if ( n >= 39 && n < 40 ) {
	BLK = 1;
} else
if ( n >= 40 && n < 47 ) {
	BLK = 2;
} else
if ( n >= 47 && n < 264 ) {
	BLK = 0;
} else
if ( n >= 264 && n < 265 ) {
	BLK = 1;
} else
if ( n >= 265 && n < 266 ) {
	BLK = 3;
} else
if ( n >= 266 && n < 271 ) {
	BLK = 0;
} else
if ( n >= 271 && n < 273 ) {
	BLK = 3;
} else
if ( n >= 273 && n < 274 ) {
	BLK = 1;
} else
if ( n >= 274 && n < 484 ) {
	BLK = 0;
} else
if ( n >= 484 && n < 485 ) {
	BLK = 1;
} else
if ( n >= 485 && n < 492 ) {
	BLK = 3;
} else
if ( n >= 492 && n < 493 ) {
	BLK = 1;
} else
if ( n >= 493 && n < 500 ) {
	BLK = 2;
} else
if ( n >= 500 && n < 501 ) {
	BLK = 3;
} else
if ( n >= 501 && n < 513 ) {
	BLK = 1;
} else
if ( n >= 513 && n < 514 ) {
	BLK = 0;
} else
if ( n >= 514 && n < 531 ) {
	BLK = 3;
} else
if ( n >= 531 && n < 532 ) {
	BLK = 0;
} else
if ( n >= 532 && n < 544 ) {
	BLK = 1;
} else
if ( n >= 544 && n < 545 ) {
	BLK = 3;
} else
if ( n >= 545 && n < 547 ) {
	BLK = 0;
} else
if ( n >= 547 && n < 550 ) {
	BLK = 1;
} else
if ( n >= 550 && n < 558 ) {
	BLK = 3;
} else
if ( n >= 558 && n < 559 ) {
	BLK = 1;
} else
if ( n >= 559 && n < 560 ) {
	BLK = 0;
} else
if ( n >= 560 && n < 566 ) {
	BLK = 3;
} else
if ( n >= 566 && n < 567 ) {
	BLK = 1;
} else
if ( n >= 567 && n < 573 ) {
	BLK = 0;
} else
if ( n >= 573 && n < 596 ) {
	BLK = 3;
} else
if ( n >= 596 && n < 597 ) {
	BLK = 0;
} else
if ( n >= 597 && n < 598 ) {
	BLK = 1;
} else
if ( n >= 598 && n < 613 ) {
	BLK = 3;
} else
if ( n >= 613 && n < 617 ) {
	BLK = 0;
} else
if ( n >= 617 && n < 622 ) {
	BLK = 1;
} else
if ( n >= 622 && n < 627 ) {
	BLK = 0;
} else
if ( n >= 627 && n < 628 ) {
	BLK = 3;
} else
if ( n >= 628 && n < 629 ) {
	BLK = 1;
} else
if ( n >= 629 && n < 651 ) {
	BLK = 0;
} else
if ( n >= 651 && n < 652 ) {
	BLK = 1;
} else
if ( n >= 652 && n < 655 ) {
	BLK = 3;
} else
if ( n >= 655 && n < 656 ) {
	BLK = 0;
} else
if ( n >= 656 && n < 659 ) {
	BLK = 1;
} else
if ( n >= 659 && n < 671 ) {
	BLK = 3;
} else
if ( n >= 671 && n < 1350 ) {
	BLK = 0;
} else
if ( n >= 1350 && n < 1355 ) {
	BLK = 1;
} else
if ( n >= 1355 && n < 1356 ) {
	BLK = 2;
} else
if ( n >= 1356 && n < 1357 ) {
	BLK = 0;
} else
if ( n >= 1357 && n < 1372 ) {
	BLK = 1;
} else
if ( n >= 1372 && n < 1373 ) {
	BLK = 0;
} else
if ( n >= 1373 && n < 1376 ) {
	BLK = 2;
} else
if ( n >= 1376 && n < 2178 ) {
	BLK = 1;
} else
if ( n >= 2178 && n < 2182 ) {
	BLK = 2;
} else
if ( n >= 2182 && n < 2183 ) {
	BLK = 3;
} else
if ( n >= 2183 && n < 9232 ) {
	BLK = 1;
} else
if ( n >= 9232 && n < 9289 ) {
	BLK = 2;
} else
if ( n >= 9289 && n < 47637 ) {
	BLK = 3;
} else
if ( n >= 47637 && n < 50048 ) {
	BLK = 1;
} else
if ( n >= 50048 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
