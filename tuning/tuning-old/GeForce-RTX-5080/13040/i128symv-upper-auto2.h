#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Sat Sep 26 03:11:39  2026
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

if ( n >= 1 && n < 15 ) {
	BLK = 4;
} else
if ( n >= 15 && n < 23 ) {
	BLK = 5;
} else
if ( n >= 23 && n < 24 ) {
	BLK = 2;
} else
if ( n >= 24 && n < 48 ) {
	BLK = 3;
} else
if ( n >= 48 && n < 146 ) {
	BLK = 5;
} else
if ( n >= 146 && n < 156 ) {
	BLK = 0;
} else
if ( n >= 156 && n < 157 ) {
	BLK = 2;
} else
if ( n >= 157 && n < 159 ) {
	BLK = 5;
} else
if ( n >= 159 && n < 161 ) {
	BLK = 4;
} else
if ( n >= 161 && n < 180 ) {
	BLK = 0;
} else
if ( n >= 180 && n < 181 ) {
	BLK = 5;
} else
if ( n >= 181 && n < 183 ) {
	BLK = 2;
} else
if ( n >= 183 && n < 256 ) {
	BLK = 0;
} else
if ( n >= 256 && n < 272 ) {
	BLK = 5;
} else
if ( n >= 272 && n < 278 ) {
	BLK = 0;
} else
if ( n >= 278 && n < 288 ) {
	BLK = 3;
} else
if ( n >= 288 && n < 334 ) {
	BLK = 0;
} else
if ( n >= 334 && n < 335 ) {
	BLK = 4;
} else
if ( n >= 335 && n < 336 ) {
	BLK = 5;
} else
if ( n >= 336 && n < 368 ) {
	BLK = 0;
} else
if ( n >= 368 && n < 371 ) {
	BLK = 2;
} else
if ( n >= 371 && n < 372 ) {
	BLK = 3;
} else
if ( n >= 372 && n < 373 ) {
	BLK = 4;
} else
if ( n >= 373 && n < 374 ) {
	BLK = 2;
} else
if ( n >= 374 && n < 378 ) {
	BLK = 5;
} else
if ( n >= 378 && n < 379 ) {
	BLK = 1;
} else
if ( n >= 379 && n < 380 ) {
	BLK = 3;
} else
if ( n >= 380 && n < 381 ) {
	BLK = 2;
} else
if ( n >= 381 && n < 390 ) {
	BLK = 4;
} else
if ( n >= 390 && n < 391 ) {
	BLK = 5;
} else
if ( n >= 391 && n < 492 ) {
	BLK = 0;
} else
if ( n >= 492 && n < 493 ) {
	BLK = 4;
} else
if ( n >= 493 && n < 494 ) {
	BLK = 3;
} else
if ( n >= 494 && n < 509 ) {
	BLK = 0;
} else
if ( n >= 509 && n < 600 ) {
	BLK = 4;
} else
if ( n >= 600 && n < 616 ) {
	BLK = 0;
} else
if ( n >= 616 && n < 621 ) {
	BLK = 3;
} else
if ( n >= 621 && n < 627 ) {
	BLK = 0;
} else
if ( n >= 627 && n < 641 ) {
	BLK = 4;
} else
if ( n >= 641 && n < 651 ) {
	BLK = 3;
} else
if ( n >= 651 && n < 652 ) {
	BLK = 4;
} else
if ( n >= 652 && n < 653 ) {
	BLK = 0;
} else
if ( n >= 653 && n < 672 ) {
	BLK = 3;
} else
if ( n >= 672 && n < 678 ) {
	BLK = 0;
} else
if ( n >= 678 && n < 679 ) {
	BLK = 1;
} else
if ( n >= 679 && n < 682 ) {
	BLK = 4;
} else
if ( n >= 682 && n < 683 ) {
	BLK = 0;
} else
if ( n >= 683 && n < 723 ) {
	BLK = 3;
} else
if ( n >= 723 && n < 724 ) {
	BLK = 1;
} else
if ( n >= 724 && n < 725 ) {
	BLK = 0;
} else
if ( n >= 725 && n < 726 ) {
	BLK = 3;
} else
if ( n >= 726 && n < 727 ) {
	BLK = 1;
} else
if ( n >= 727 && n < 729 ) {
	BLK = 4;
} else
if ( n >= 729 && n < 735 ) {
	BLK = 0;
} else
if ( n >= 735 && n < 768 ) {
	BLK = 3;
} else
if ( n >= 768 && n < 815 ) {
	BLK = 1;
} else
if ( n >= 815 && n < 996 ) {
	BLK = 4;
} else
if ( n >= 996 && n < 998 ) {
	BLK = 3;
} else
if ( n >= 998 && n < 1001 ) {
	BLK = 1;
} else
if ( n >= 1001 && n < 1003 ) {
	BLK = 3;
} else
if ( n >= 1003 && n < 1004 ) {
	BLK = 4;
} else
if ( n >= 1004 && n < 1005 ) {
	BLK = 1;
} else
if ( n >= 1005 && n < 1022 ) {
	BLK = 3;
} else
if ( n >= 1022 && n < 1023 ) {
	BLK = 1;
} else
if ( n >= 1023 && n < 1025 ) {
	BLK = 4;
} else
if ( n >= 1025 && n < 1033 ) {
	BLK = 3;
} else
if ( n >= 1033 && n < 1042 ) {
	BLK = 1;
} else
if ( n >= 1042 && n < 1043 ) {
	BLK = 3;
} else
if ( n >= 1043 && n < 2563 ) {
	BLK = 4;
} else
if ( n >= 2563 && n < 4418 ) {
	BLK = 1;
} else
if ( n >= 4418 && n < 5284 ) {
	BLK = 5;
} else
if ( n >= 5284 && n < 8926 ) {
	BLK = 3;
} else
if ( n >= 8926 && n < 10645 ) {
	BLK = 2;
} else
if ( n >= 10645 && n < 11170 ) {
	BLK = 4;
} else
if ( n >= 11170 && n < 11639 ) {
	BLK = 2;
} else
if ( n >= 11639 && n < 12409 ) {
	BLK = 4;
} else
if ( n >= 12409 && n < 12953 ) {
	BLK = 2;
} else
if ( n >= 12953 && n < 20507 ) {
	BLK = 4;
} else
if ( n >= 20507 && n < 20831 ) {
	BLK = 2;
} else
if ( n >= 20831 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
