#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Sat Sep 26 23:04:22  2026
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

if ( n >= 1 && n < 1277 ) {
	BLK = 0;
} else
if ( n >= 1277 && n < 1318 ) {
	BLK = 5;
} else
if ( n >= 1318 && n < 1319 ) {
	BLK = 0;
} else
if ( n >= 1319 && n < 1320 ) {
	BLK = 3;
} else
if ( n >= 1320 && n < 1322 ) {
	BLK = 5;
} else
if ( n >= 1322 && n < 1323 ) {
	BLK = 0;
} else
if ( n >= 1323 && n < 1333 ) {
	BLK = 3;
} else
if ( n >= 1333 && n < 1335 ) {
	BLK = 5;
} else
if ( n >= 1335 && n < 1353 ) {
	BLK = 0;
} else
if ( n >= 1353 && n < 1359 ) {
	BLK = 5;
} else
if ( n >= 1359 && n < 1376 ) {
	BLK = 0;
} else
if ( n >= 1376 && n < 1538 ) {
	BLK = 5;
} else
if ( n >= 1538 && n < 1539 ) {
	BLK = 0;
} else
if ( n >= 1539 && n < 1542 ) {
	BLK = 3;
} else
if ( n >= 1542 && n < 1549 ) {
	BLK = 5;
} else
if ( n >= 1549 && n < 1550 ) {
	BLK = 3;
} else
if ( n >= 1550 && n < 1560 ) {
	BLK = 0;
} else
if ( n >= 1560 && n < 1563 ) {
	BLK = 5;
} else
if ( n >= 1563 && n < 1564 ) {
	BLK = 0;
} else
if ( n >= 1564 && n < 1565 ) {
	BLK = 1;
} else
if ( n >= 1565 && n < 1566 ) {
	BLK = 3;
} else
if ( n >= 1566 && n < 1567 ) {
	BLK = 0;
} else
if ( n >= 1567 && n < 1573 ) {
	BLK = 5;
} else
if ( n >= 1573 && n < 1574 ) {
	BLK = 3;
} else
if ( n >= 1574 && n < 1575 ) {
	BLK = 4;
} else
if ( n >= 1575 && n < 1587 ) {
	BLK = 5;
} else
if ( n >= 1587 && n < 1588 ) {
	BLK = 3;
} else
if ( n >= 1588 && n < 1591 ) {
	BLK = 0;
} else
if ( n >= 1591 && n < 1594 ) {
	BLK = 3;
} else
if ( n >= 1594 && n < 1598 ) {
	BLK = 5;
} else
if ( n >= 1598 && n < 1599 ) {
	BLK = 4;
} else
if ( n >= 1599 && n < 1600 ) {
	BLK = 3;
} else
if ( n >= 1600 && n < 1601 ) {
	BLK = 1;
} else
if ( n >= 1601 && n < 1624 ) {
	BLK = 5;
} else
if ( n >= 1624 && n < 1625 ) {
	BLK = 3;
} else
if ( n >= 1625 && n < 1626 ) {
	BLK = 4;
} else
if ( n >= 1626 && n < 1627 ) {
	BLK = 0;
} else
if ( n >= 1627 && n < 1628 ) {
	BLK = 3;
} else
if ( n >= 1628 && n < 1642 ) {
	BLK = 5;
} else
if ( n >= 1642 && n < 1644 ) {
	BLK = 0;
} else
if ( n >= 1644 && n < 1645 ) {
	BLK = 4;
} else
if ( n >= 1645 && n < 1669 ) {
	BLK = 5;
} else
if ( n >= 1669 && n < 1670 ) {
	BLK = 0;
} else
if ( n >= 1670 && n < 1675 ) {
	BLK = 4;
} else
if ( n >= 1675 && n < 1683 ) {
	BLK = 0;
} else
if ( n >= 1683 && n < 1684 ) {
	BLK = 5;
} else
if ( n >= 1684 && n < 1685 ) {
	BLK = 4;
} else
if ( n >= 1685 && n < 1687 ) {
	BLK = 0;
} else
if ( n >= 1687 && n < 1696 ) {
	BLK = 5;
} else
if ( n >= 1696 && n < 1698 ) {
	BLK = 4;
} else
if ( n >= 1698 && n < 1705 ) {
	BLK = 0;
} else
if ( n >= 1705 && n < 1707 ) {
	BLK = 4;
} else
if ( n >= 1707 && n < 1708 ) {
	BLK = 3;
} else
if ( n >= 1708 && n < 1713 ) {
	BLK = 5;
} else
if ( n >= 1713 && n < 1714 ) {
	BLK = 4;
} else
if ( n >= 1714 && n < 1715 ) {
	BLK = 0;
} else
if ( n >= 1715 && n < 1729 ) {
	BLK = 5;
} else
if ( n >= 1729 && n < 2948 ) {
	BLK = 4;
} else
if ( n >= 2948 && n < 7824 ) {
	BLK = 1;
} else
if ( n >= 7824 && n < 18024 ) {
	BLK = 2;
} else
if ( n >= 18024 && n < 18379 ) {
	BLK = 1;
} else
if ( n >= 18379 && n < 27118 ) {
	BLK = 2;
} else
if ( n >= 27118 && n < 27615 ) {
	BLK = 1;
} else
if ( n >= 27615 && n < 32059 ) {
	BLK = 2;
} else
if ( n >= 32059 && n < 32779 ) {
	BLK = 1;
} else
if ( n >= 32779 && n < 38040 ) {
	BLK = 2;
} else
if ( n >= 38040 && n < 39792 ) {
	BLK = 1;
} else
if ( n >= 39792 && n < 48954 ) {
	BLK = 2;
} else
if ( n >= 48954 && n < 50144 ) {
	BLK = 1;
} else
if ( n >= 50144 && n < 67800 ) {
	BLK = 2;
} else
if ( n >= 67800 && n < 69565 ) {
	BLK = 1;
} else
if ( n >= 69565 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
