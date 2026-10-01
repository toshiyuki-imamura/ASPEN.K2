#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Fri Sep 25 20:58:29  2026
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

if ( n >= 1 && n < 8 ) {
	BLK = 0;
} else
if ( n >= 8 && n < 16 ) {
	BLK = 4;
} else
if ( n >= 16 && n < 18 ) {
	BLK = 5;
} else
if ( n >= 18 && n < 19 ) {
	BLK = 3;
} else
if ( n >= 19 && n < 22 ) {
	BLK = 2;
} else
if ( n >= 22 && n < 24 ) {
	BLK = 5;
} else
if ( n >= 24 && n < 38 ) {
	BLK = 3;
} else
if ( n >= 38 && n < 245 ) {
	BLK = 1;
} else
if ( n >= 245 && n < 1004 ) {
	BLK = 0;
} else
if ( n >= 1004 && n < 1045 ) {
	BLK = 2;
} else
if ( n >= 1045 && n < 1061 ) {
	BLK = 5;
} else
if ( n >= 1061 && n < 1062 ) {
	BLK = 4;
} else
if ( n >= 1062 && n < 1112 ) {
	BLK = 2;
} else
if ( n >= 1112 && n < 1116 ) {
	BLK = 4;
} else
if ( n >= 1116 && n < 1144 ) {
	BLK = 2;
} else
if ( n >= 1144 && n < 1145 ) {
	BLK = 5;
} else
if ( n >= 1145 && n < 1152 ) {
	BLK = 4;
} else
if ( n >= 1152 && n < 1166 ) {
	BLK = 5;
} else
if ( n >= 1166 && n < 1167 ) {
	BLK = 2;
} else
if ( n >= 1167 && n < 1170 ) {
	BLK = 4;
} else
if ( n >= 1170 && n < 1225 ) {
	BLK = 2;
} else
if ( n >= 1225 && n < 1226 ) {
	BLK = 5;
} else
if ( n >= 1226 && n < 1227 ) {
	BLK = 4;
} else
if ( n >= 1227 && n < 1256 ) {
	BLK = 2;
} else
if ( n >= 1256 && n < 1257 ) {
	BLK = 4;
} else
if ( n >= 1257 && n < 1258 ) {
	BLK = 5;
} else
if ( n >= 1258 && n < 1614 ) {
	BLK = 2;
} else
if ( n >= 1614 && n < 1632 ) {
	BLK = 5;
} else
if ( n >= 1632 && n < 1633 ) {
	BLK = 4;
} else
if ( n >= 1633 && n < 1634 ) {
	BLK = 2;
} else
if ( n >= 1634 && n < 1639 ) {
	BLK = 5;
} else
if ( n >= 1639 && n < 1640 ) {
	BLK = 2;
} else
if ( n >= 1640 && n < 1641 ) {
	BLK = 4;
} else
if ( n >= 1641 && n < 1663 ) {
	BLK = 5;
} else
if ( n >= 1663 && n < 1664 ) {
	BLK = 4;
} else
if ( n >= 1664 && n < 1665 ) {
	BLK = 2;
} else
if ( n >= 1665 && n < 1670 ) {
	BLK = 5;
} else
if ( n >= 1670 && n < 1684 ) {
	BLK = 4;
} else
if ( n >= 1684 && n < 1693 ) {
	BLK = 2;
} else
if ( n >= 1693 && n < 1694 ) {
	BLK = 5;
} else
if ( n >= 1694 && n < 1698 ) {
	BLK = 4;
} else
if ( n >= 1698 && n < 1699 ) {
	BLK = 2;
} else
if ( n >= 1699 && n < 1701 ) {
	BLK = 5;
} else
if ( n >= 1701 && n < 1730 ) {
	BLK = 4;
} else
if ( n >= 1730 && n < 1791 ) {
	BLK = 2;
} else
if ( n >= 1791 && n < 1792 ) {
	BLK = 4;
} else
if ( n >= 1792 && n < 1793 ) {
	BLK = 5;
} else
if ( n >= 1793 && n < 1811 ) {
	BLK = 2;
} else
if ( n >= 1811 && n < 1847 ) {
	BLK = 4;
} else
if ( n >= 1847 && n < 1848 ) {
	BLK = 2;
} else
if ( n >= 1848 && n < 1849 ) {
	BLK = 5;
} else
if ( n >= 1849 && n < 1853 ) {
	BLK = 4;
} else
if ( n >= 1853 && n < 1854 ) {
	BLK = 2;
} else
if ( n >= 1854 && n < 1855 ) {
	BLK = 5;
} else
if ( n >= 1855 && n < 1874 ) {
	BLK = 4;
} else
if ( n >= 1874 && n < 1875 ) {
	BLK = 2;
} else
if ( n >= 1875 && n < 1876 ) {
	BLK = 5;
} else
if ( n >= 1876 && n < 1923 ) {
	BLK = 4;
} else
if ( n >= 1923 && n < 1966 ) {
	BLK = 2;
} else
if ( n >= 1966 && n < 1967 ) {
	BLK = 5;
} else
if ( n >= 1967 && n < 1981 ) {
	BLK = 3;
} else
if ( n >= 1981 && n < 2236 ) {
	BLK = 2;
} else
if ( n >= 2236 && n < 3593 ) {
	BLK = 3;
} else
if ( n >= 3593 && n < 3594 ) {
	BLK = 4;
} else
if ( n >= 3594 && n < 3595 ) {
	BLK = 2;
} else
if ( n >= 3595 && n < 3649 ) {
	BLK = 3;
} else
if ( n >= 3649 && n < 3651 ) {
	BLK = 2;
} else
if ( n >= 3651 && n < 3652 ) {
	BLK = 4;
} else
if ( n >= 3652 && n < 3667 ) {
	BLK = 3;
} else
if ( n >= 3667 && n < 3669 ) {
	BLK = 2;
} else
if ( n >= 3669 && n < 3670 ) {
	BLK = 4;
} else
if ( n >= 3670 && n < 3673 ) {
	BLK = 3;
} else
if ( n >= 3673 && n < 3680 ) {
	BLK = 2;
} else
if ( n >= 3680 && n < 3714 ) {
	BLK = 3;
} else
if ( n >= 3714 && n < 3723 ) {
	BLK = 2;
} else
if ( n >= 3723 && n < 3724 ) {
	BLK = 4;
} else
if ( n >= 3724 && n < 3795 ) {
	BLK = 3;
} else
if ( n >= 3795 && n < 3796 ) {
	BLK = 2;
} else
if ( n >= 3796 && n < 3805 ) {
	BLK = 4;
} else
if ( n >= 3805 && n < 3810 ) {
	BLK = 2;
} else
if ( n >= 3810 && n < 3838 ) {
	BLK = 3;
} else
if ( n >= 3838 && n < 6279 ) {
	BLK = 2;
} else
if ( n >= 6279 && n < 6304 ) {
	BLK = 5;
} else
if ( n >= 6304 && n < 6310 ) {
	BLK = 3;
} else
if ( n >= 6310 && n < 6338 ) {
	BLK = 2;
} else
if ( n >= 6338 && n < 6362 ) {
	BLK = 5;
} else
if ( n >= 6362 && n < 6414 ) {
	BLK = 3;
} else
if ( n >= 6414 && n < 6549 ) {
	BLK = 5;
} else
if ( n >= 6549 && n < 6574 ) {
	BLK = 3;
} else
if ( n >= 6574 && n < 6869 ) {
	BLK = 4;
} else
if ( n >= 6869 && n < 6891 ) {
	BLK = 5;
} else
if ( n >= 6891 && n < 6917 ) {
	BLK = 3;
} else
if ( n >= 6917 && n < 10817 ) {
	BLK = 4;
} else
if ( n >= 10817 && n < 21019 ) {
	BLK = 1;
} else
if ( n >= 21019 && n < 21505 ) {
	BLK = 4;
} else
if ( n >= 21505 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
