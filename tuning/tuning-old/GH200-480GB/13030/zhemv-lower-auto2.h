#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Wed Sep 30 17:12:29  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 1;
} else
if ( n >= 2 && n < 11 ) {
	BLK = 4;
} else
if ( n >= 11 && n < 12 ) {
	BLK = 2;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 5;
} else
if ( n >= 13 && n < 14 ) {
	BLK = 4;
} else
if ( n >= 14 && n < 19 ) {
	BLK = 1;
} else
if ( n >= 19 && n < 20 ) {
	BLK = 3;
} else
if ( n >= 20 && n < 21 ) {
	BLK = 4;
} else
if ( n >= 21 && n < 25 ) {
	BLK = 2;
} else
if ( n >= 25 && n < 27 ) {
	BLK = 1;
} else
if ( n >= 27 && n < 609 ) {
	BLK = 5;
} else
if ( n >= 609 && n < 610 ) {
	BLK = 2;
} else
if ( n >= 610 && n < 624 ) {
	BLK = 3;
} else
if ( n >= 624 && n < 625 ) {
	BLK = 5;
} else
if ( n >= 625 && n < 626 ) {
	BLK = 2;
} else
if ( n >= 626 && n < 632 ) {
	BLK = 3;
} else
if ( n >= 632 && n < 633 ) {
	BLK = 5;
} else
if ( n >= 633 && n < 634 ) {
	BLK = 2;
} else
if ( n >= 634 && n < 639 ) {
	BLK = 3;
} else
if ( n >= 639 && n < 642 ) {
	BLK = 5;
} else
if ( n >= 642 && n < 643 ) {
	BLK = 2;
} else
if ( n >= 643 && n < 837 ) {
	BLK = 3;
} else
if ( n >= 837 && n < 838 ) {
	BLK = 5;
} else
if ( n >= 838 && n < 1457 ) {
	BLK = 2;
} else
if ( n >= 1457 && n < 2454 ) {
	BLK = 3;
} else
if ( n >= 2454 && n < 2509 ) {
	BLK = 2;
} else
if ( n >= 2509 && n < 2540 ) {
	BLK = 4;
} else
if ( n >= 2540 && n < 2541 ) {
	BLK = 1;
} else
if ( n >= 2541 && n < 2542 ) {
	BLK = 2;
} else
if ( n >= 2542 && n < 2547 ) {
	BLK = 4;
} else
if ( n >= 2547 && n < 2548 ) {
	BLK = 2;
} else
if ( n >= 2548 && n < 2549 ) {
	BLK = 1;
} else
if ( n >= 2549 && n < 2554 ) {
	BLK = 4;
} else
if ( n >= 2554 && n < 2555 ) {
	BLK = 2;
} else
if ( n >= 2555 && n < 2556 ) {
	BLK = 1;
} else
if ( n >= 2556 && n < 2564 ) {
	BLK = 4;
} else
if ( n >= 2564 && n < 2565 ) {
	BLK = 1;
} else
if ( n >= 2565 && n < 2566 ) {
	BLK = 2;
} else
if ( n >= 2566 && n < 2568 ) {
	BLK = 4;
} else
if ( n >= 2568 && n < 2569 ) {
	BLK = 1;
} else
if ( n >= 2569 && n < 2570 ) {
	BLK = 2;
} else
if ( n >= 2570 && n < 2572 ) {
	BLK = 4;
} else
if ( n >= 2572 && n < 2633 ) {
	BLK = 1;
} else
if ( n >= 2633 && n < 2634 ) {
	BLK = 2;
} else
if ( n >= 2634 && n < 2637 ) {
	BLK = 4;
} else
if ( n >= 2637 && n < 2638 ) {
	BLK = 2;
} else
if ( n >= 2638 && n < 3230 ) {
	BLK = 1;
} else
if ( n >= 3230 && n < 3241 ) {
	BLK = 4;
} else
if ( n >= 3241 && n < 5261 ) {
	BLK = 1;
} else
if ( n >= 5261 && n < 8625 ) {
	BLK = 4;
} else
if ( n >= 8625 && n < 8686 ) {
	BLK = 2;
} else
if ( n >= 8686 && n < 8833 ) {
	BLK = 1;
} else
if ( n >= 8833 && n < 10842 ) {
	BLK = 4;
} else
if ( n >= 10842 && n < 12595 ) {
	BLK = 1;
} else
if ( n >= 12595 && n < 12857 ) {
	BLK = 2;
} else
if ( n >= 12857 && n < 15197 ) {
	BLK = 1;
} else
if ( n >= 15197 && n < 15797 ) {
	BLK = 2;
} else
if ( n >= 15797 && n < 17737 ) {
	BLK = 1;
} else
if ( n >= 17737 && n < 18130 ) {
	BLK = 2;
} else
if ( n >= 18130 && n < 18591 ) {
	BLK = 1;
} else
if ( n >= 18591 && n < 22481 ) {
	BLK = 2;
} else
if ( n >= 22481 && n < 22932 ) {
	BLK = 1;
} else
if ( n >= 22932 && n < 24846 ) {
	BLK = 2;
} else
if ( n >= 24846 && n < 25458 ) {
	BLK = 1;
} else
if ( n >= 25458 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
