#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Mon Jul 27 11:11:31  2026
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

if ( n >= 1 && n < 1586 ) {
	BLK = 0;
} else
if ( n >= 1586 && n < 1602 ) {
	BLK = 2;
} else
if ( n >= 1602 && n < 1603 ) {
	BLK = 1;
} else
if ( n >= 1603 && n < 1606 ) {
	BLK = 0;
} else
if ( n >= 1606 && n < 1607 ) {
	BLK = 2;
} else
if ( n >= 1607 && n < 1608 ) {
	BLK = 1;
} else
if ( n >= 1608 && n < 1620 ) {
	BLK = 0;
} else
if ( n >= 1620 && n < 1627 ) {
	BLK = 2;
} else
if ( n >= 1627 && n < 1630 ) {
	BLK = 0;
} else
if ( n >= 1630 && n < 1631 ) {
	BLK = 2;
} else
if ( n >= 1631 && n < 1632 ) {
	BLK = 1;
} else
if ( n >= 1632 && n < 1635 ) {
	BLK = 0;
} else
if ( n >= 1635 && n < 1644 ) {
	BLK = 2;
} else
if ( n >= 1644 && n < 1645 ) {
	BLK = 0;
} else
if ( n >= 1645 && n < 1650 ) {
	BLK = 1;
} else
if ( n >= 1650 && n < 1653 ) {
	BLK = 2;
} else
if ( n >= 1653 && n < 1654 ) {
	BLK = 1;
} else
if ( n >= 1654 && n < 1656 ) {
	BLK = 0;
} else
if ( n >= 1656 && n < 1666 ) {
	BLK = 2;
} else
if ( n >= 1666 && n < 1667 ) {
	BLK = 1;
} else
if ( n >= 1667 && n < 1680 ) {
	BLK = 0;
} else
if ( n >= 1680 && n < 1684 ) {
	BLK = 2;
} else
if ( n >= 1684 && n < 1685 ) {
	BLK = 0;
} else
if ( n >= 1685 && n < 1688 ) {
	BLK = 1;
} else
if ( n >= 1688 && n < 1743 ) {
	BLK = 2;
} else
if ( n >= 1743 && n < 1744 ) {
	BLK = 3;
} else
if ( n >= 1744 && n < 1807 ) {
	BLK = 1;
} else
if ( n >= 1807 && n < 1808 ) {
	BLK = 2;
} else
if ( n >= 1808 && n < 1810 ) {
	BLK = 3;
} else
if ( n >= 1810 && n < 1815 ) {
	BLK = 1;
} else
if ( n >= 1815 && n < 1821 ) {
	BLK = 3;
} else
if ( n >= 1821 && n < 1830 ) {
	BLK = 2;
} else
if ( n >= 1830 && n < 1833 ) {
	BLK = 1;
} else
if ( n >= 1833 && n < 1834 ) {
	BLK = 3;
} else
if ( n >= 1834 && n < 1987 ) {
	BLK = 2;
} else
if ( n >= 1987 && n < 1988 ) {
	BLK = 1;
} else
if ( n >= 1988 && n < 1989 ) {
	BLK = 3;
} else
if ( n >= 1989 && n < 2086 ) {
	BLK = 2;
} else
if ( n >= 2086 && n < 2087 ) {
	BLK = 3;
} else
if ( n >= 2087 && n < 2263 ) {
	BLK = 1;
} else
if ( n >= 2263 && n < 2264 ) {
	BLK = 3;
} else
if ( n >= 2264 && n < 2299 ) {
	BLK = 2;
} else
if ( n >= 2299 && n < 2441 ) {
	BLK = 1;
} else
if ( n >= 2441 && n < 2442 ) {
	BLK = 3;
} else
if ( n >= 2442 && n < 2478 ) {
	BLK = 2;
} else
if ( n >= 2478 && n < 2480 ) {
	BLK = 1;
} else
if ( n >= 2480 && n < 2481 ) {
	BLK = 3;
} else
if ( n >= 2481 && n < 2530 ) {
	BLK = 2;
} else
if ( n >= 2530 && n < 2531 ) {
	BLK = 1;
} else
if ( n >= 2531 && n < 2532 ) {
	BLK = 3;
} else
if ( n >= 2532 && n < 2798 ) {
	BLK = 2;
} else
if ( n >= 2798 && n < 2799 ) {
	BLK = 3;
} else
if ( n >= 2799 && n < 2816 ) {
	BLK = 1;
} else
if ( n >= 2816 && n < 2972 ) {
	BLK = 2;
} else
if ( n >= 2972 && n < 2974 ) {
	BLK = 1;
} else
if ( n >= 2974 && n < 2975 ) {
	BLK = 3;
} else
if ( n >= 2975 && n < 3007 ) {
	BLK = 2;
} else
if ( n >= 3007 && n < 3076 ) {
	BLK = 1;
} else
if ( n >= 3076 && n < 3108 ) {
	BLK = 2;
} else
if ( n >= 3108 && n < 3110 ) {
	BLK = 1;
} else
if ( n >= 3110 && n < 3111 ) {
	BLK = 3;
} else
if ( n >= 3111 && n < 3117 ) {
	BLK = 2;
} else
if ( n >= 3117 && n < 3120 ) {
	BLK = 3;
} else
if ( n >= 3120 && n < 3157 ) {
	BLK = 2;
} else
if ( n >= 3157 && n < 3329 ) {
	BLK = 1;
} else
if ( n >= 3329 && n < 3349 ) {
	BLK = 2;
} else
if ( n >= 3349 && n < 3350 ) {
	BLK = 1;
} else
if ( n >= 3350 && n < 3351 ) {
	BLK = 3;
} else
if ( n >= 3351 && n < 3366 ) {
	BLK = 2;
} else
if ( n >= 3366 && n < 3367 ) {
	BLK = 3;
} else
if ( n >= 3367 && n < 3376 ) {
	BLK = 1;
} else
if ( n >= 3376 && n < 3377 ) {
	BLK = 2;
} else
if ( n >= 3377 && n < 3378 ) {
	BLK = 3;
} else
if ( n >= 3378 && n < 3406 ) {
	BLK = 1;
} else
if ( n >= 3406 && n < 3407 ) {
	BLK = 2;
} else
if ( n >= 3407 && n < 3408 ) {
	BLK = 3;
} else
if ( n >= 3408 && n < 3420 ) {
	BLK = 1;
} else
if ( n >= 3420 && n < 3526 ) {
	BLK = 2;
} else
if ( n >= 3526 && n < 3527 ) {
	BLK = 3;
} else
if ( n >= 3527 && n < 3583 ) {
	BLK = 1;
} else
if ( n >= 3583 && n < 3592 ) {
	BLK = 2;
} else
if ( n >= 3592 && n < 3593 ) {
	BLK = 1;
} else
if ( n >= 3593 && n < 3594 ) {
	BLK = 3;
} else
if ( n >= 3594 && n < 3644 ) {
	BLK = 2;
} else
if ( n >= 3644 && n < 3645 ) {
	BLK = 3;
} else
if ( n >= 3645 && n < 3758 ) {
	BLK = 1;
} else
if ( n >= 3758 && n < 3954 ) {
	BLK = 2;
} else
if ( n >= 3954 && n < 3955 ) {
	BLK = 3;
} else
if ( n >= 3955 && n < 3956 ) {
	BLK = 1;
} else
if ( n >= 3956 && n < 3979 ) {
	BLK = 2;
} else
if ( n >= 3979 && n < 3980 ) {
	BLK = 1;
} else
if ( n >= 3980 && n < 3981 ) {
	BLK = 3;
} else
if ( n >= 3981 && n < 3993 ) {
	BLK = 2;
} else
if ( n >= 3993 && n < 3994 ) {
	BLK = 3;
} else
if ( n >= 3994 && n < 4030 ) {
	BLK = 1;
} else
if ( n >= 4030 && n < 4051 ) {
	BLK = 2;
} else
if ( n >= 4051 && n < 4052 ) {
	BLK = 3;
} else
if ( n >= 4052 && n < 4093 ) {
	BLK = 1;
} else
if ( n >= 4093 && n < 4094 ) {
	BLK = 3;
} else
if ( n >= 4094 && n < 4149 ) {
	BLK = 2;
} else
if ( n >= 4149 && n < 4154 ) {
	BLK = 1;
} else
if ( n >= 4154 && n < 4156 ) {
	BLK = 3;
} else
if ( n >= 4156 && n < 4185 ) {
	BLK = 2;
} else
if ( n >= 4185 && n < 4186 ) {
	BLK = 3;
} else
if ( n >= 4186 && n < 4330 ) {
	BLK = 1;
} else
if ( n >= 4330 && n < 4471 ) {
	BLK = 2;
} else
if ( n >= 4471 && n < 4477 ) {
	BLK = 3;
} else
if ( n >= 4477 && n < 4706 ) {
	BLK = 1;
} else
if ( n >= 4706 && n < 4734 ) {
	BLK = 2;
} else
if ( n >= 4734 && n < 4743 ) {
	BLK = 3;
} else
if ( n >= 4743 && n < 4979 ) {
	BLK = 1;
} else
if ( n >= 4979 && n < 5046 ) {
	BLK = 2;
} else
if ( n >= 5046 && n < 5072 ) {
	BLK = 1;
} else
if ( n >= 5072 && n < 5083 ) {
	BLK = 3;
} else
if ( n >= 5083 && n < 5314 ) {
	BLK = 2;
} else
if ( n >= 5314 && n < 5338 ) {
	BLK = 1;
} else
if ( n >= 5338 && n < 5495 ) {
	BLK = 3;
} else
if ( n >= 5495 && n < 5633 ) {
	BLK = 2;
} else
if ( n >= 5633 && n < 5662 ) {
	BLK = 3;
} else
if ( n >= 5662 && n < 5674 ) {
	BLK = 1;
} else
if ( n >= 5674 && n < 5898 ) {
	BLK = 2;
} else
if ( n >= 5898 && n < 6067 ) {
	BLK = 1;
} else
if ( n >= 6067 && n < 6302 ) {
	BLK = 2;
} else
if ( n >= 6302 && n < 6444 ) {
	BLK = 3;
} else
if ( n >= 6444 && n < 6463 ) {
	BLK = 2;
} else
if ( n >= 6463 && n < 6477 ) {
	BLK = 1;
} else
if ( n >= 6477 && n < 6507 ) {
	BLK = 3;
} else
if ( n >= 6507 && n < 6709 ) {
	BLK = 2;
} else
if ( n >= 6709 && n < 6751 ) {
	BLK = 3;
} else
if ( n >= 6751 && n < 6780 ) {
	BLK = 1;
} else
if ( n >= 6780 && n < 7445 ) {
	BLK = 2;
} else
if ( n >= 7445 && n < 13101 ) {
	BLK = 3;
} else
if ( n >= 13101 && n < 13274 ) {
	BLK = 2;
} else
if ( n >= 13274 && n < 13463 ) {
	BLK = 1;
} else
if ( n >= 13463 && n < 16276 ) {
	BLK = 3;
} else
if ( n >= 16276 && n < 16803 ) {
	BLK = 2;
} else
if ( n >= 16803 && n < 17307 ) {
	BLK = 3;
} else
if ( n >= 17307 && n < 17482 ) {
	BLK = 2;
} else
if ( n >= 17482 && n < 17873 ) {
	BLK = 1;
} else
if ( n >= 17873 && n < 20817 ) {
	BLK = 3;
} else
if ( n >= 20817 && n < 21306 ) {
	BLK = 1;
} else
if ( n >= 21306 && n < 21448 ) {
	BLK = 3;
} else
if ( n >= 21448 && n < 21951 ) {
	BLK = 2;
} else
if ( n >= 21951 && n < 23425 ) {
	BLK = 3;
} else
if ( n >= 23425 && n < 23700 ) {
	BLK = 2;
} else
if ( n >= 23700 && n < 25314 ) {
	BLK = 3;
} else
if ( n >= 25314 && n < 25657 ) {
	BLK = 2;
} else
if ( n >= 25657 && n < 26196 ) {
	BLK = 1;
} else
if ( n >= 26196 && n < 26366 ) {
	BLK = 2;
} else
if ( n >= 26366 && n < 30565 ) {
	BLK = 3;
} else
if ( n >= 30565 && n < 32457 ) {
	BLK = 2;
} else
if ( n >= 32457 && n < 40658 ) {
	BLK = 3;
} else
if ( n >= 40658 && n < 41967 ) {
	BLK = 2;
} else
if ( n >= 41967 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
