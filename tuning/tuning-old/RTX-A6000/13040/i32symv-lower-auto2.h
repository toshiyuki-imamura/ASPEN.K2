#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Mon Sep 28 10:35:28  2026
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

if ( n >= 1 && n < 2 ) {
	BLK = 0;
} else
if ( n >= 2 && n < 5 ) {
	BLK = 2;
} else
if ( n >= 5 && n < 8 ) {
	BLK = 1;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 3;
} else
if ( n >= 9 && n < 19 ) {
	BLK = 2;
} else
if ( n >= 19 && n < 24 ) {
	BLK = 0;
} else
if ( n >= 24 && n < 25 ) {
	BLK = 5;
} else
if ( n >= 25 && n < 31 ) {
	BLK = 2;
} else
if ( n >= 31 && n < 1535 ) {
	BLK = 0;
} else
if ( n >= 1535 && n < 1536 ) {
	BLK = 3;
} else
if ( n >= 1536 && n < 1537 ) {
	BLK = 4;
} else
if ( n >= 1537 && n < 1539 ) {
	BLK = 0;
} else
if ( n >= 1539 && n < 1540 ) {
	BLK = 5;
} else
if ( n >= 1540 && n < 1560 ) {
	BLK = 3;
} else
if ( n >= 1560 && n < 1585 ) {
	BLK = 0;
} else
if ( n >= 1585 && n < 1586 ) {
	BLK = 4;
} else
if ( n >= 1586 && n < 1587 ) {
	BLK = 1;
} else
if ( n >= 1587 && n < 1596 ) {
	BLK = 0;
} else
if ( n >= 1596 && n < 1597 ) {
	BLK = 1;
} else
if ( n >= 1597 && n < 1620 ) {
	BLK = 3;
} else
if ( n >= 1620 && n < 1621 ) {
	BLK = 0;
} else
if ( n >= 1621 && n < 1622 ) {
	BLK = 5;
} else
if ( n >= 1622 && n < 1625 ) {
	BLK = 3;
} else
if ( n >= 1625 && n < 1628 ) {
	BLK = 0;
} else
if ( n >= 1628 && n < 1634 ) {
	BLK = 3;
} else
if ( n >= 1634 && n < 1638 ) {
	BLK = 4;
} else
if ( n >= 1638 && n < 1643 ) {
	BLK = 1;
} else
if ( n >= 1643 && n < 1648 ) {
	BLK = 3;
} else
if ( n >= 1648 && n < 1651 ) {
	BLK = 4;
} else
if ( n >= 1651 && n < 1660 ) {
	BLK = 0;
} else
if ( n >= 1660 && n < 1664 ) {
	BLK = 4;
} else
if ( n >= 1664 && n < 1731 ) {
	BLK = 3;
} else
if ( n >= 1731 && n < 1733 ) {
	BLK = 4;
} else
if ( n >= 1733 && n < 1734 ) {
	BLK = 0;
} else
if ( n >= 1734 && n < 1736 ) {
	BLK = 3;
} else
if ( n >= 1736 && n < 1750 ) {
	BLK = 4;
} else
if ( n >= 1750 && n < 1751 ) {
	BLK = 0;
} else
if ( n >= 1751 && n < 1752 ) {
	BLK = 3;
} else
if ( n >= 1752 && n < 1753 ) {
	BLK = 4;
} else
if ( n >= 1753 && n < 1756 ) {
	BLK = 0;
} else
if ( n >= 1756 && n < 1758 ) {
	BLK = 3;
} else
if ( n >= 1758 && n < 2628 ) {
	BLK = 4;
} else
if ( n >= 2628 && n < 25991 ) {
	BLK = 1;
} else
if ( n >= 25991 && n < 27080 ) {
	BLK = 2;
} else
if ( n >= 27080 && n < 27654 ) {
	BLK = 1;
} else
if ( n >= 27654 && n < 28960 ) {
	BLK = 2;
} else
if ( n >= 28960 && n < 29588 ) {
	BLK = 1;
} else
if ( n >= 29588 && n < 32010 ) {
	BLK = 2;
} else
if ( n >= 32010 && n < 32823 ) {
	BLK = 1;
} else
if ( n >= 32823 && n < 34658 ) {
	BLK = 2;
} else
if ( n >= 34658 && n < 35567 ) {
	BLK = 1;
} else
if ( n >= 35567 && n < 37942 ) {
	BLK = 2;
} else
if ( n >= 37942 && n < 39876 ) {
	BLK = 1;
} else
if ( n >= 39876 && n < 42914 ) {
	BLK = 2;
} else
if ( n >= 42914 && n < 43619 ) {
	BLK = 1;
} else
if ( n >= 43619 && n < 48845 ) {
	BLK = 2;
} else
if ( n >= 48845 && n < 50338 ) {
	BLK = 1;
} else
if ( n >= 50338 && n < 57102 ) {
	BLK = 2;
} else
if ( n >= 57102 && n < 59072 ) {
	BLK = 1;
} else
if ( n >= 59072 && n < 67726 ) {
	BLK = 2;
} else
if ( n >= 67726 && n < 69664 ) {
	BLK = 1;
} else
if ( n >= 69664 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
