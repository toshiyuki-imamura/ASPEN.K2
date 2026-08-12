#ifndef KHEMVU_AUTO2_H_INCLUDED
#define KHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVU
 Sat Aug 08 09:55:47  2026
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

if ( n >= 1 && n < 379 ) {
	BLK = 0;
} else
if ( n >= 379 && n < 380 ) {
	BLK = 2;
} else
if ( n >= 380 && n < 381 ) {
	BLK = 1;
} else
if ( n >= 381 && n < 490 ) {
	BLK = 0;
} else
if ( n >= 490 && n < 520 ) {
	BLK = 5;
} else
if ( n >= 520 && n < 524 ) {
	BLK = 2;
} else
if ( n >= 524 && n < 525 ) {
	BLK = 4;
} else
if ( n >= 525 && n < 593 ) {
	BLK = 5;
} else
if ( n >= 593 && n < 594 ) {
	BLK = 4;
} else
if ( n >= 594 && n < 595 ) {
	BLK = 2;
} else
if ( n >= 595 && n < 691 ) {
	BLK = 5;
} else
if ( n >= 691 && n < 757 ) {
	BLK = 0;
} else
if ( n >= 757 && n < 788 ) {
	BLK = 5;
} else
if ( n >= 788 && n < 789 ) {
	BLK = 0;
} else
if ( n >= 789 && n < 796 ) {
	BLK = 2;
} else
if ( n >= 796 && n < 803 ) {
	BLK = 5;
} else
if ( n >= 803 && n < 806 ) {
	BLK = 2;
} else
if ( n >= 806 && n < 998 ) {
	BLK = 0;
} else
if ( n >= 998 && n < 1193 ) {
	BLK = 2;
} else
if ( n >= 1193 && n < 1195 ) {
	BLK = 3;
} else
if ( n >= 1195 && n < 1241 ) {
	BLK = 4;
} else
if ( n >= 1241 && n < 1242 ) {
	BLK = 0;
} else
if ( n >= 1242 && n < 1246 ) {
	BLK = 3;
} else
if ( n >= 1246 && n < 1254 ) {
	BLK = 2;
} else
if ( n >= 1254 && n < 1271 ) {
	BLK = 4;
} else
if ( n >= 1271 && n < 1272 ) {
	BLK = 3;
} else
if ( n >= 1272 && n < 1343 ) {
	BLK = 2;
} else
if ( n >= 1343 && n < 1406 ) {
	BLK = 4;
} else
if ( n >= 1406 && n < 1412 ) {
	BLK = 5;
} else
if ( n >= 1412 && n < 1417 ) {
	BLK = 4;
} else
if ( n >= 1417 && n < 1420 ) {
	BLK = 5;
} else
if ( n >= 1420 && n < 1435 ) {
	BLK = 0;
} else
if ( n >= 1435 && n < 1436 ) {
	BLK = 5;
} else
if ( n >= 1436 && n < 1437 ) {
	BLK = 4;
} else
if ( n >= 1437 && n < 1451 ) {
	BLK = 0;
} else
if ( n >= 1451 && n < 1462 ) {
	BLK = 5;
} else
if ( n >= 1462 && n < 1466 ) {
	BLK = 4;
} else
if ( n >= 1466 && n < 1467 ) {
	BLK = 0;
} else
if ( n >= 1467 && n < 1468 ) {
	BLK = 5;
} else
if ( n >= 1468 && n < 1469 ) {
	BLK = 4;
} else
if ( n >= 1469 && n < 1476 ) {
	BLK = 3;
} else
if ( n >= 1476 && n < 1481 ) {
	BLK = 5;
} else
if ( n >= 1481 && n < 1482 ) {
	BLK = 3;
} else
if ( n >= 1482 && n < 1503 ) {
	BLK = 4;
} else
if ( n >= 1503 && n < 1504 ) {
	BLK = 5;
} else
if ( n >= 1504 && n < 1505 ) {
	BLK = 3;
} else
if ( n >= 1505 && n < 1543 ) {
	BLK = 4;
} else
if ( n >= 1543 && n < 1551 ) {
	BLK = 3;
} else
if ( n >= 1551 && n < 1558 ) {
	BLK = 4;
} else
if ( n >= 1558 && n < 1559 ) {
	BLK = 3;
} else
if ( n >= 1559 && n < 1577 ) {
	BLK = 5;
} else
if ( n >= 1577 && n < 1578 ) {
	BLK = 4;
} else
if ( n >= 1578 && n < 1579 ) {
	BLK = 3;
} else
if ( n >= 1579 && n < 1582 ) {
	BLK = 5;
} else
if ( n >= 1582 && n < 1596 ) {
	BLK = 4;
} else
if ( n >= 1596 && n < 1739 ) {
	BLK = 3;
} else
if ( n >= 1739 && n < 1740 ) {
	BLK = 0;
} else
if ( n >= 1740 && n < 2045 ) {
	BLK = 2;
} else
if ( n >= 2045 && n < 2046 ) {
	BLK = 3;
} else
if ( n >= 2046 && n < 2130 ) {
	BLK = 4;
} else
if ( n >= 2130 && n < 2220 ) {
	BLK = 2;
} else
if ( n >= 2220 && n < 2225 ) {
	BLK = 3;
} else
if ( n >= 2225 && n < 2396 ) {
	BLK = 2;
} else
if ( n >= 2396 && n < 2397 ) {
	BLK = 3;
} else
if ( n >= 2397 && n < 2408 ) {
	BLK = 4;
} else
if ( n >= 2408 && n < 2421 ) {
	BLK = 3;
} else
if ( n >= 2421 && n < 2422 ) {
	BLK = 4;
} else
if ( n >= 2422 && n < 2432 ) {
	BLK = 2;
} else
if ( n >= 2432 && n < 2436 ) {
	BLK = 4;
} else
if ( n >= 2436 && n < 2438 ) {
	BLK = 3;
} else
if ( n >= 2438 && n < 2439 ) {
	BLK = 2;
} else
if ( n >= 2439 && n < 2487 ) {
	BLK = 4;
} else
if ( n >= 2487 && n < 2488 ) {
	BLK = 3;
} else
if ( n >= 2488 && n < 2497 ) {
	BLK = 2;
} else
if ( n >= 2497 && n < 2515 ) {
	BLK = 4;
} else
if ( n >= 2515 && n < 2523 ) {
	BLK = 2;
} else
if ( n >= 2523 && n < 2524 ) {
	BLK = 4;
} else
if ( n >= 2524 && n < 2539 ) {
	BLK = 3;
} else
if ( n >= 2539 && n < 2609 ) {
	BLK = 2;
} else
if ( n >= 2609 && n < 2610 ) {
	BLK = 3;
} else
if ( n >= 2610 && n < 2611 ) {
	BLK = 4;
} else
if ( n >= 2611 && n < 2629 ) {
	BLK = 2;
} else
if ( n >= 2629 && n < 2640 ) {
	BLK = 3;
} else
if ( n >= 2640 && n < 2644 ) {
	BLK = 4;
} else
if ( n >= 2644 && n < 2647 ) {
	BLK = 2;
} else
if ( n >= 2647 && n < 2659 ) {
	BLK = 3;
} else
if ( n >= 2659 && n < 2662 ) {
	BLK = 4;
} else
if ( n >= 2662 && n < 2671 ) {
	BLK = 3;
} else
if ( n >= 2671 && n < 2672 ) {
	BLK = 2;
} else
if ( n >= 2672 && n < 2673 ) {
	BLK = 4;
} else
if ( n >= 2673 && n < 2682 ) {
	BLK = 3;
} else
if ( n >= 2682 && n < 2684 ) {
	BLK = 2;
} else
if ( n >= 2684 && n < 2685 ) {
	BLK = 4;
} else
if ( n >= 2685 && n < 2693 ) {
	BLK = 3;
} else
if ( n >= 2693 && n < 2694 ) {
	BLK = 4;
} else
if ( n >= 2694 && n < 2703 ) {
	BLK = 2;
} else
if ( n >= 2703 && n < 2709 ) {
	BLK = 4;
} else
if ( n >= 2709 && n < 2713 ) {
	BLK = 3;
} else
if ( n >= 2713 && n < 2714 ) {
	BLK = 4;
} else
if ( n >= 2714 && n < 2715 ) {
	BLK = 2;
} else
if ( n >= 2715 && n < 2716 ) {
	BLK = 3;
} else
if ( n >= 2716 && n < 2718 ) {
	BLK = 4;
} else
if ( n >= 2718 && n < 2719 ) {
	BLK = 2;
} else
if ( n >= 2719 && n < 2739 ) {
	BLK = 3;
} else
if ( n >= 2739 && n < 2740 ) {
	BLK = 2;
} else
if ( n >= 2740 && n < 2744 ) {
	BLK = 4;
} else
if ( n >= 2744 && n < 2748 ) {
	BLK = 2;
} else
if ( n >= 2748 && n < 2770 ) {
	BLK = 3;
} else
if ( n >= 2770 && n < 2771 ) {
	BLK = 4;
} else
if ( n >= 2771 && n < 2772 ) {
	BLK = 2;
} else
if ( n >= 2772 && n < 2858 ) {
	BLK = 3;
} else
if ( n >= 2858 && n < 2912 ) {
	BLK = 4;
} else
if ( n >= 2912 && n < 2917 ) {
	BLK = 2;
} else
if ( n >= 2917 && n < 2918 ) {
	BLK = 4;
} else
if ( n >= 2918 && n < 2919 ) {
	BLK = 3;
} else
if ( n >= 2919 && n < 2934 ) {
	BLK = 2;
} else
if ( n >= 2934 && n < 2935 ) {
	BLK = 4;
} else
if ( n >= 2935 && n < 2955 ) {
	BLK = 3;
} else
if ( n >= 2955 && n < 2962 ) {
	BLK = 4;
} else
if ( n >= 2962 && n < 2963 ) {
	BLK = 2;
} else
if ( n >= 2963 && n < 2998 ) {
	BLK = 3;
} else
if ( n >= 2998 && n < 2999 ) {
	BLK = 4;
} else
if ( n >= 2999 && n < 3010 ) {
	BLK = 2;
} else
if ( n >= 3010 && n < 3011 ) {
	BLK = 4;
} else
if ( n >= 3011 && n < 3029 ) {
	BLK = 3;
} else
if ( n >= 3029 && n < 3030 ) {
	BLK = 4;
} else
if ( n >= 3030 && n < 3031 ) {
	BLK = 2;
} else
if ( n >= 3031 && n < 3052 ) {
	BLK = 3;
} else
if ( n >= 3052 && n < 3055 ) {
	BLK = 2;
} else
if ( n >= 3055 && n < 3056 ) {
	BLK = 4;
} else
if ( n >= 3056 && n < 3089 ) {
	BLK = 3;
} else
if ( n >= 3089 && n < 3094 ) {
	BLK = 2;
} else
if ( n >= 3094 && n < 3130 ) {
	BLK = 3;
} else
if ( n >= 3130 && n < 3131 ) {
	BLK = 2;
} else
if ( n >= 3131 && n < 3144 ) {
	BLK = 4;
} else
if ( n >= 3144 && n < 5121 ) {
	BLK = 3;
} else
if ( n >= 5121 && n < 5412 ) {
	BLK = 1;
} else
if ( n >= 5412 && n < 5628 ) {
	BLK = 4;
} else
if ( n >= 5628 && n < 9031 ) {
	BLK = 2;
} else
if ( n >= 9031 && n < 11404 ) {
	BLK = 5;
} else
if ( n >= 11404 && n < 18265 ) {
	BLK = 1;
} else
if ( n >= 18265 && n < 18605 ) {
	BLK = 3;
} else
if ( n >= 18605 && n < 19233 ) {
	BLK = 1;
} else
if ( n >= 19233 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
