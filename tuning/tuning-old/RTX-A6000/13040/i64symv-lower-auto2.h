#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Mon Sep 28 05:38:42  2026
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
MAXmem= 50949160960
// capacity of the work area reserved on the GPU
WORK= 4423680
// for double or cuFloatComplex or int64
MAXDIM= 75813
// for float or cuHalfComplex or int32
MAXDIM2= 107216
// for cuDoubleComplex or DD or int128
MAXDIM3= 53608
// for DD-Complex
MAXDIM4= 37906
// for half or int16
MAXDIM5= 151627
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 860
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

if ( n >= 1 && n < 26 ) {
	BLK = 0;
} else
if ( n >= 26 && n < 27 ) {
	BLK = 3;
} else
if ( n >= 27 && n < 37 ) {
	BLK = 2;
} else
if ( n >= 37 && n < 353 ) {
	BLK = 0;
} else
if ( n >= 353 && n < 354 ) {
	BLK = 3;
} else
if ( n >= 354 && n < 361 ) {
	BLK = 2;
} else
if ( n >= 361 && n < 630 ) {
	BLK = 0;
} else
if ( n >= 630 && n < 632 ) {
	BLK = 2;
} else
if ( n >= 632 && n < 634 ) {
	BLK = 3;
} else
if ( n >= 634 && n < 636 ) {
	BLK = 1;
} else
if ( n >= 636 && n < 880 ) {
	BLK = 0;
} else
if ( n >= 880 && n < 881 ) {
	BLK = 4;
} else
if ( n >= 881 && n < 884 ) {
	BLK = 3;
} else
if ( n >= 884 && n < 892 ) {
	BLK = 4;
} else
if ( n >= 892 && n < 903 ) {
	BLK = 0;
} else
if ( n >= 903 && n < 904 ) {
	BLK = 3;
} else
if ( n >= 904 && n < 905 ) {
	BLK = 5;
} else
if ( n >= 905 && n < 968 ) {
	BLK = 0;
} else
if ( n >= 968 && n < 969 ) {
	BLK = 5;
} else
if ( n >= 969 && n < 975 ) {
	BLK = 3;
} else
if ( n >= 975 && n < 1080 ) {
	BLK = 0;
} else
if ( n >= 1080 && n < 1081 ) {
	BLK = 5;
} else
if ( n >= 1081 && n < 1086 ) {
	BLK = 3;
} else
if ( n >= 1086 && n < 1087 ) {
	BLK = 0;
} else
if ( n >= 1087 && n < 1088 ) {
	BLK = 4;
} else
if ( n >= 1088 && n < 1089 ) {
	BLK = 5;
} else
if ( n >= 1089 && n < 1134 ) {
	BLK = 0;
} else
if ( n >= 1134 && n < 1135 ) {
	BLK = 3;
} else
if ( n >= 1135 && n < 1136 ) {
	BLK = 5;
} else
if ( n >= 1136 && n < 1270 ) {
	BLK = 0;
} else
if ( n >= 1270 && n < 1271 ) {
	BLK = 3;
} else
if ( n >= 1271 && n < 1272 ) {
	BLK = 2;
} else
if ( n >= 1272 && n < 1444 ) {
	BLK = 0;
} else
if ( n >= 1444 && n < 1445 ) {
	BLK = 2;
} else
if ( n >= 1445 && n < 1446 ) {
	BLK = 5;
} else
if ( n >= 1446 && n < 1449 ) {
	BLK = 3;
} else
if ( n >= 1449 && n < 1456 ) {
	BLK = 0;
} else
if ( n >= 1456 && n < 1464 ) {
	BLK = 4;
} else
if ( n >= 1464 && n < 1465 ) {
	BLK = 2;
} else
if ( n >= 1465 && n < 1469 ) {
	BLK = 0;
} else
if ( n >= 1469 && n < 1473 ) {
	BLK = 4;
} else
if ( n >= 1473 && n < 1474 ) {
	BLK = 2;
} else
if ( n >= 1474 && n < 1484 ) {
	BLK = 0;
} else
if ( n >= 1484 && n < 1485 ) {
	BLK = 4;
} else
if ( n >= 1485 && n < 1486 ) {
	BLK = 5;
} else
if ( n >= 1486 && n < 1487 ) {
	BLK = 3;
} else
if ( n >= 1487 && n < 1492 ) {
	BLK = 0;
} else
if ( n >= 1492 && n < 1493 ) {
	BLK = 1;
} else
if ( n >= 1493 && n < 1497 ) {
	BLK = 4;
} else
if ( n >= 1497 && n < 1501 ) {
	BLK = 0;
} else
if ( n >= 1501 && n < 1502 ) {
	BLK = 3;
} else
if ( n >= 1502 && n < 1503 ) {
	BLK = 4;
} else
if ( n >= 1503 && n < 1505 ) {
	BLK = 0;
} else
if ( n >= 1505 && n < 1506 ) {
	BLK = 3;
} else
if ( n >= 1506 && n < 1514 ) {
	BLK = 4;
} else
if ( n >= 1514 && n < 1529 ) {
	BLK = 0;
} else
if ( n >= 1529 && n < 1530 ) {
	BLK = 4;
} else
if ( n >= 1530 && n < 1531 ) {
	BLK = 2;
} else
if ( n >= 1531 && n < 1532 ) {
	BLK = 0;
} else
if ( n >= 1532 && n < 1533 ) {
	BLK = 4;
} else
if ( n >= 1533 && n < 1534 ) {
	BLK = 3;
} else
if ( n >= 1534 && n < 1540 ) {
	BLK = 0;
} else
if ( n >= 1540 && n < 1541 ) {
	BLK = 1;
} else
if ( n >= 1541 && n < 1554 ) {
	BLK = 4;
} else
if ( n >= 1554 && n < 1555 ) {
	BLK = 3;
} else
if ( n >= 1555 && n < 1560 ) {
	BLK = 0;
} else
if ( n >= 1560 && n < 1567 ) {
	BLK = 4;
} else
if ( n >= 1567 && n < 1568 ) {
	BLK = 3;
} else
if ( n >= 1568 && n < 1569 ) {
	BLK = 2;
} else
if ( n >= 1569 && n < 1570 ) {
	BLK = 4;
} else
if ( n >= 1570 && n < 1571 ) {
	BLK = 3;
} else
if ( n >= 1571 && n < 1572 ) {
	BLK = 0;
} else
if ( n >= 1572 && n < 1573 ) {
	BLK = 5;
} else
if ( n >= 1573 && n < 1578 ) {
	BLK = 4;
} else
if ( n >= 1578 && n < 1579 ) {
	BLK = 3;
} else
if ( n >= 1579 && n < 1580 ) {
	BLK = 2;
} else
if ( n >= 1580 && n < 1581 ) {
	BLK = 5;
} else
if ( n >= 1581 && n < 1601 ) {
	BLK = 4;
} else
if ( n >= 1601 && n < 1602 ) {
	BLK = 2;
} else
if ( n >= 1602 && n < 1603 ) {
	BLK = 1;
} else
if ( n >= 1603 && n < 1604 ) {
	BLK = 3;
} else
if ( n >= 1604 && n < 1605 ) {
	BLK = 0;
} else
if ( n >= 1605 && n < 1617 ) {
	BLK = 4;
} else
if ( n >= 1617 && n < 1618 ) {
	BLK = 5;
} else
if ( n >= 1618 && n < 1627 ) {
	BLK = 3;
} else
if ( n >= 1627 && n < 1637 ) {
	BLK = 4;
} else
if ( n >= 1637 && n < 1648 ) {
	BLK = 3;
} else
if ( n >= 1648 && n < 1649 ) {
	BLK = 4;
} else
if ( n >= 1649 && n < 1650 ) {
	BLK = 2;
} else
if ( n >= 1650 && n < 1676 ) {
	BLK = 3;
} else
if ( n >= 1676 && n < 1685 ) {
	BLK = 4;
} else
if ( n >= 1685 && n < 1775 ) {
	BLK = 3;
} else
if ( n >= 1775 && n < 1816 ) {
	BLK = 4;
} else
if ( n >= 1816 && n < 1818 ) {
	BLK = 5;
} else
if ( n >= 1818 && n < 1819 ) {
	BLK = 3;
} else
if ( n >= 1819 && n < 1820 ) {
	BLK = 2;
} else
if ( n >= 1820 && n < 1833 ) {
	BLK = 4;
} else
if ( n >= 1833 && n < 1834 ) {
	BLK = 3;
} else
if ( n >= 1834 && n < 1877 ) {
	BLK = 5;
} else
if ( n >= 1877 && n < 1882 ) {
	BLK = 4;
} else
if ( n >= 1882 && n < 1888 ) {
	BLK = 3;
} else
if ( n >= 1888 && n < 1889 ) {
	BLK = 4;
} else
if ( n >= 1889 && n < 1976 ) {
	BLK = 5;
} else
if ( n >= 1976 && n < 1996 ) {
	BLK = 4;
} else
if ( n >= 1996 && n < 2000 ) {
	BLK = 5;
} else
if ( n >= 2000 && n < 2001 ) {
	BLK = 1;
} else
if ( n >= 2001 && n < 2015 ) {
	BLK = 4;
} else
if ( n >= 2015 && n < 2026 ) {
	BLK = 5;
} else
if ( n >= 2026 && n < 2027 ) {
	BLK = 3;
} else
if ( n >= 2027 && n < 2040 ) {
	BLK = 4;
} else
if ( n >= 2040 && n < 2047 ) {
	BLK = 2;
} else
if ( n >= 2047 && n < 2051 ) {
	BLK = 4;
} else
if ( n >= 2051 && n < 2097 ) {
	BLK = 5;
} else
if ( n >= 2097 && n < 2105 ) {
	BLK = 4;
} else
if ( n >= 2105 && n < 2188 ) {
	BLK = 5;
} else
if ( n >= 2188 && n < 2193 ) {
	BLK = 4;
} else
if ( n >= 2193 && n < 2199 ) {
	BLK = 5;
} else
if ( n >= 2199 && n < 2202 ) {
	BLK = 1;
} else
if ( n >= 2202 && n < 2203 ) {
	BLK = 4;
} else
if ( n >= 2203 && n < 2246 ) {
	BLK = 5;
} else
if ( n >= 2246 && n < 2247 ) {
	BLK = 4;
} else
if ( n >= 2247 && n < 2248 ) {
	BLK = 1;
} else
if ( n >= 2248 && n < 2304 ) {
	BLK = 5;
} else
if ( n >= 2304 && n < 2305 ) {
	BLK = 4;
} else
if ( n >= 2305 && n < 2309 ) {
	BLK = 1;
} else
if ( n >= 2309 && n < 2311 ) {
	BLK = 5;
} else
if ( n >= 2311 && n < 2315 ) {
	BLK = 3;
} else
if ( n >= 2315 && n < 2316 ) {
	BLK = 2;
} else
if ( n >= 2316 && n < 2318 ) {
	BLK = 5;
} else
if ( n >= 2318 && n < 2330 ) {
	BLK = 4;
} else
if ( n >= 2330 && n < 2331 ) {
	BLK = 5;
} else
if ( n >= 2331 && n < 2344 ) {
	BLK = 1;
} else
if ( n >= 2344 && n < 2345 ) {
	BLK = 5;
} else
if ( n >= 2345 && n < 2350 ) {
	BLK = 4;
} else
if ( n >= 2350 && n < 2356 ) {
	BLK = 5;
} else
if ( n >= 2356 && n < 2367 ) {
	BLK = 1;
} else
if ( n >= 2367 && n < 2368 ) {
	BLK = 5;
} else
if ( n >= 2368 && n < 2375 ) {
	BLK = 4;
} else
if ( n >= 2375 && n < 2380 ) {
	BLK = 1;
} else
if ( n >= 2380 && n < 2392 ) {
	BLK = 4;
} else
if ( n >= 2392 && n < 2403 ) {
	BLK = 5;
} else
if ( n >= 2403 && n < 2419 ) {
	BLK = 1;
} else
if ( n >= 2419 && n < 2420 ) {
	BLK = 3;
} else
if ( n >= 2420 && n < 2461 ) {
	BLK = 4;
} else
if ( n >= 2461 && n < 2464 ) {
	BLK = 1;
} else
if ( n >= 2464 && n < 2469 ) {
	BLK = 3;
} else
if ( n >= 2469 && n < 2470 ) {
	BLK = 1;
} else
if ( n >= 2470 && n < 2471 ) {
	BLK = 5;
} else
if ( n >= 2471 && n < 2477 ) {
	BLK = 3;
} else
if ( n >= 2477 && n < 2478 ) {
	BLK = 1;
} else
if ( n >= 2478 && n < 2479 ) {
	BLK = 5;
} else
if ( n >= 2479 && n < 2480 ) {
	BLK = 3;
} else
if ( n >= 2480 && n < 2481 ) {
	BLK = 4;
} else
if ( n >= 2481 && n < 2482 ) {
	BLK = 1;
} else
if ( n >= 2482 && n < 2483 ) {
	BLK = 5;
} else
if ( n >= 2483 && n < 2487 ) {
	BLK = 3;
} else
if ( n >= 2487 && n < 2488 ) {
	BLK = 4;
} else
if ( n >= 2488 && n < 2490 ) {
	BLK = 1;
} else
if ( n >= 2490 && n < 2491 ) {
	BLK = 5;
} else
if ( n >= 2491 && n < 2492 ) {
	BLK = 4;
} else
if ( n >= 2492 && n < 2499 ) {
	BLK = 3;
} else
if ( n >= 2499 && n < 2500 ) {
	BLK = 4;
} else
if ( n >= 2500 && n < 2502 ) {
	BLK = 1;
} else
if ( n >= 2502 && n < 2507 ) {
	BLK = 3;
} else
if ( n >= 2507 && n < 2508 ) {
	BLK = 1;
} else
if ( n >= 2508 && n < 2509 ) {
	BLK = 4;
} else
if ( n >= 2509 && n < 2521 ) {
	BLK = 3;
} else
if ( n >= 2521 && n < 2523 ) {
	BLK = 1;
} else
if ( n >= 2523 && n < 2524 ) {
	BLK = 4;
} else
if ( n >= 2524 && n < 2525 ) {
	BLK = 3;
} else
if ( n >= 2525 && n < 2526 ) {
	BLK = 1;
} else
if ( n >= 2526 && n < 2527 ) {
	BLK = 4;
} else
if ( n >= 2527 && n < 2550 ) {
	BLK = 3;
} else
if ( n >= 2550 && n < 2553 ) {
	BLK = 1;
} else
if ( n >= 2553 && n < 2559 ) {
	BLK = 4;
} else
if ( n >= 2559 && n < 2589 ) {
	BLK = 3;
} else
if ( n >= 2589 && n < 2590 ) {
	BLK = 4;
} else
if ( n >= 2590 && n < 2691 ) {
	BLK = 1;
} else
if ( n >= 2691 && n < 2692 ) {
	BLK = 4;
} else
if ( n >= 2692 && n < 2931 ) {
	BLK = 3;
} else
if ( n >= 2931 && n < 2932 ) {
	BLK = 1;
} else
if ( n >= 2932 && n < 2933 ) {
	BLK = 4;
} else
if ( n >= 2933 && n < 3020 ) {
	BLK = 3;
} else
if ( n >= 3020 && n < 3021 ) {
	BLK = 4;
} else
if ( n >= 3021 && n < 3426 ) {
	BLK = 1;
} else
if ( n >= 3426 && n < 3561 ) {
	BLK = 3;
} else
if ( n >= 3561 && n < 3562 ) {
	BLK = 1;
} else
if ( n >= 3562 && n < 3563 ) {
	BLK = 2;
} else
if ( n >= 3563 && n < 3690 ) {
	BLK = 3;
} else
if ( n >= 3690 && n < 3693 ) {
	BLK = 4;
} else
if ( n >= 3693 && n < 3700 ) {
	BLK = 3;
} else
if ( n >= 3700 && n < 3713 ) {
	BLK = 2;
} else
if ( n >= 3713 && n < 3714 ) {
	BLK = 4;
} else
if ( n >= 3714 && n < 3727 ) {
	BLK = 3;
} else
if ( n >= 3727 && n < 3734 ) {
	BLK = 2;
} else
if ( n >= 3734 && n < 3735 ) {
	BLK = 4;
} else
if ( n >= 3735 && n < 4014 ) {
	BLK = 3;
} else
if ( n >= 4014 && n < 4016 ) {
	BLK = 2;
} else
if ( n >= 4016 && n < 4017 ) {
	BLK = 4;
} else
if ( n >= 4017 && n < 4126 ) {
	BLK = 3;
} else
if ( n >= 4126 && n < 4147 ) {
	BLK = 2;
} else
if ( n >= 4147 && n < 4154 ) {
	BLK = 1;
} else
if ( n >= 4154 && n < 4178 ) {
	BLK = 4;
} else
if ( n >= 4178 && n < 4182 ) {
	BLK = 1;
} else
if ( n >= 4182 && n < 4334 ) {
	BLK = 2;
} else
if ( n >= 4334 && n < 4335 ) {
	BLK = 1;
} else
if ( n >= 4335 && n < 4370 ) {
	BLK = 4;
} else
if ( n >= 4370 && n < 4404 ) {
	BLK = 2;
} else
if ( n >= 4404 && n < 4406 ) {
	BLK = 1;
} else
if ( n >= 4406 && n < 5297 ) {
	BLK = 4;
} else
if ( n >= 5297 && n < 5496 ) {
	BLK = 2;
} else
if ( n >= 5496 && n < 7615 ) {
	BLK = 1;
} else
if ( n >= 7615 && n < 7635 ) {
	BLK = 2;
} else
if ( n >= 7635 && n < 7652 ) {
	BLK = 4;
} else
if ( n >= 7652 && n < 7953 ) {
	BLK = 1;
} else
if ( n >= 7953 && n < 8040 ) {
	BLK = 2;
} else
if ( n >= 8040 && n < 8098 ) {
	BLK = 4;
} else
if ( n >= 8098 && n < 8265 ) {
	BLK = 1;
} else
if ( n >= 8265 && n < 8788 ) {
	BLK = 4;
} else
if ( n >= 8788 && n < 15181 ) {
	BLK = 2;
} else
if ( n >= 15181 && n < 15268 ) {
	BLK = 1;
} else
if ( n >= 15268 && n < 15550 ) {
	BLK = 4;
} else
if ( n >= 15550 && n < 16485 ) {
	BLK = 2;
} else
if ( n >= 16485 && n < 17057 ) {
	BLK = 3;
} else
if ( n >= 17057 && n < 18736 ) {
	BLK = 2;
} else
if ( n >= 18736 && n < 19413 ) {
	BLK = 4;
} else
if ( n >= 19413 && n < 24660 ) {
	BLK = 2;
} else
if ( n >= 24660 && n < 25055 ) {
	BLK = 4;
} else
if ( n >= 25055 && n < 25322 ) {
	BLK = 2;
} else
if ( n >= 25322 && n < 25677 ) {
	BLK = 4;
} else
if ( n >= 25677 && n < 26094 ) {
	BLK = 2;
} else
if ( n >= 26094 && n < 27027 ) {
	BLK = 3;
} else
if ( n >= 27027 && n < 31972 ) {
	BLK = 2;
} else
if ( n >= 31972 && n < 33461 ) {
	BLK = 3;
} else
if ( n >= 33461 && n < 36113 ) {
	BLK = 2;
} else
if ( n >= 36113 && n < 37461 ) {
	BLK = 4;
} else
if ( n >= 37461 && n < 60990 ) {
	BLK = 2;
} else
if ( n >= 60990 && n < 67827 ) {
	BLK = 3;
} else
if ( n >= 67827 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
