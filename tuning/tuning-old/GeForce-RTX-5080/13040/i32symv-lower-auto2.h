#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Sun Sep 27 03:39:01  2026
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

if ( n >= 1 && n < 244 ) {
	BLK = 0;
} else
if ( n >= 244 && n < 246 ) {
	BLK = 2;
} else
if ( n >= 246 && n < 260 ) {
	BLK = 5;
} else
if ( n >= 260 && n < 263 ) {
	BLK = 2;
} else
if ( n >= 263 && n < 265 ) {
	BLK = 0;
} else
if ( n >= 265 && n < 268 ) {
	BLK = 5;
} else
if ( n >= 268 && n < 269 ) {
	BLK = 2;
} else
if ( n >= 269 && n < 275 ) {
	BLK = 0;
} else
if ( n >= 275 && n < 278 ) {
	BLK = 5;
} else
if ( n >= 278 && n < 282 ) {
	BLK = 2;
} else
if ( n >= 282 && n < 579 ) {
	BLK = 0;
} else
if ( n >= 579 && n < 580 ) {
	BLK = 2;
} else
if ( n >= 580 && n < 581 ) {
	BLK = 5;
} else
if ( n >= 581 && n < 584 ) {
	BLK = 0;
} else
if ( n >= 584 && n < 587 ) {
	BLK = 2;
} else
if ( n >= 587 && n < 627 ) {
	BLK = 0;
} else
if ( n >= 627 && n < 628 ) {
	BLK = 2;
} else
if ( n >= 628 && n < 641 ) {
	BLK = 5;
} else
if ( n >= 641 && n < 642 ) {
	BLK = 2;
} else
if ( n >= 642 && n < 659 ) {
	BLK = 0;
} else
if ( n >= 659 && n < 672 ) {
	BLK = 5;
} else
if ( n >= 672 && n < 770 ) {
	BLK = 0;
} else
if ( n >= 770 && n < 777 ) {
	BLK = 2;
} else
if ( n >= 777 && n < 792 ) {
	BLK = 0;
} else
if ( n >= 792 && n < 793 ) {
	BLK = 5;
} else
if ( n >= 793 && n < 805 ) {
	BLK = 2;
} else
if ( n >= 805 && n < 806 ) {
	BLK = 5;
} else
if ( n >= 806 && n < 809 ) {
	BLK = 0;
} else
if ( n >= 809 && n < 840 ) {
	BLK = 2;
} else
if ( n >= 840 && n < 843 ) {
	BLK = 5;
} else
if ( n >= 843 && n < 846 ) {
	BLK = 0;
} else
if ( n >= 846 && n < 852 ) {
	BLK = 2;
} else
if ( n >= 852 && n < 853 ) {
	BLK = 0;
} else
if ( n >= 853 && n < 854 ) {
	BLK = 5;
} else
if ( n >= 854 && n < 898 ) {
	BLK = 2;
} else
if ( n >= 898 && n < 1023 ) {
	BLK = 0;
} else
if ( n >= 1023 && n < 1099 ) {
	BLK = 2;
} else
if ( n >= 1099 && n < 1101 ) {
	BLK = 3;
} else
if ( n >= 1101 && n < 1126 ) {
	BLK = 5;
} else
if ( n >= 1126 && n < 1166 ) {
	BLK = 2;
} else
if ( n >= 1166 && n < 1167 ) {
	BLK = 0;
} else
if ( n >= 1167 && n < 1168 ) {
	BLK = 3;
} else
if ( n >= 1168 && n < 1341 ) {
	BLK = 2;
} else
if ( n >= 1341 && n < 1342 ) {
	BLK = 4;
} else
if ( n >= 1342 && n < 1355 ) {
	BLK = 3;
} else
if ( n >= 1355 && n < 1483 ) {
	BLK = 2;
} else
if ( n >= 1483 && n < 1484 ) {
	BLK = 4;
} else
if ( n >= 1484 && n < 1485 ) {
	BLK = 3;
} else
if ( n >= 1485 && n < 1543 ) {
	BLK = 2;
} else
if ( n >= 1543 && n < 1552 ) {
	BLK = 4;
} else
if ( n >= 1552 && n < 1583 ) {
	BLK = 2;
} else
if ( n >= 1583 && n < 1584 ) {
	BLK = 4;
} else
if ( n >= 1584 && n < 1585 ) {
	BLK = 3;
} else
if ( n >= 1585 && n < 1590 ) {
	BLK = 2;
} else
if ( n >= 1590 && n < 1591 ) {
	BLK = 3;
} else
if ( n >= 1591 && n < 1592 ) {
	BLK = 4;
} else
if ( n >= 1592 && n < 1608 ) {
	BLK = 2;
} else
if ( n >= 1608 && n < 1612 ) {
	BLK = 4;
} else
if ( n >= 1612 && n < 1639 ) {
	BLK = 3;
} else
if ( n >= 1639 && n < 1641 ) {
	BLK = 2;
} else
if ( n >= 1641 && n < 1642 ) {
	BLK = 4;
} else
if ( n >= 1642 && n < 1643 ) {
	BLK = 3;
} else
if ( n >= 1643 && n < 1669 ) {
	BLK = 2;
} else
if ( n >= 1669 && n < 1670 ) {
	BLK = 4;
} else
if ( n >= 1670 && n < 1671 ) {
	BLK = 0;
} else
if ( n >= 1671 && n < 1673 ) {
	BLK = 2;
} else
if ( n >= 1673 && n < 1674 ) {
	BLK = 3;
} else
if ( n >= 1674 && n < 1675 ) {
	BLK = 4;
} else
if ( n >= 1675 && n < 1676 ) {
	BLK = 0;
} else
if ( n >= 1676 && n < 1677 ) {
	BLK = 2;
} else
if ( n >= 1677 && n < 1678 ) {
	BLK = 3;
} else
if ( n >= 1678 && n < 1679 ) {
	BLK = 4;
} else
if ( n >= 1679 && n < 1681 ) {
	BLK = 2;
} else
if ( n >= 1681 && n < 1682 ) {
	BLK = 0;
} else
if ( n >= 1682 && n < 1683 ) {
	BLK = 4;
} else
if ( n >= 1683 && n < 1685 ) {
	BLK = 2;
} else
if ( n >= 1685 && n < 1686 ) {
	BLK = 3;
} else
if ( n >= 1686 && n < 1687 ) {
	BLK = 0;
} else
if ( n >= 1687 && n < 1707 ) {
	BLK = 2;
} else
if ( n >= 1707 && n < 1708 ) {
	BLK = 4;
} else
if ( n >= 1708 && n < 1709 ) {
	BLK = 3;
} else
if ( n >= 1709 && n < 1723 ) {
	BLK = 2;
} else
if ( n >= 1723 && n < 1730 ) {
	BLK = 3;
} else
if ( n >= 1730 && n < 1739 ) {
	BLK = 4;
} else
if ( n >= 1739 && n < 1740 ) {
	BLK = 0;
} else
if ( n >= 1740 && n < 1743 ) {
	BLK = 2;
} else
if ( n >= 1743 && n < 1746 ) {
	BLK = 4;
} else
if ( n >= 1746 && n < 1747 ) {
	BLK = 0;
} else
if ( n >= 1747 && n < 1755 ) {
	BLK = 2;
} else
if ( n >= 1755 && n < 1756 ) {
	BLK = 4;
} else
if ( n >= 1756 && n < 1757 ) {
	BLK = 0;
} else
if ( n >= 1757 && n < 1770 ) {
	BLK = 2;
} else
if ( n >= 1770 && n < 1771 ) {
	BLK = 3;
} else
if ( n >= 1771 && n < 1772 ) {
	BLK = 4;
} else
if ( n >= 1772 && n < 1773 ) {
	BLK = 2;
} else
if ( n >= 1773 && n < 1775 ) {
	BLK = 0;
} else
if ( n >= 1775 && n < 1779 ) {
	BLK = 4;
} else
if ( n >= 1779 && n < 1780 ) {
	BLK = 3;
} else
if ( n >= 1780 && n < 1781 ) {
	BLK = 2;
} else
if ( n >= 1781 && n < 1782 ) {
	BLK = 0;
} else
if ( n >= 1782 && n < 1783 ) {
	BLK = 3;
} else
if ( n >= 1783 && n < 1784 ) {
	BLK = 4;
} else
if ( n >= 1784 && n < 1800 ) {
	BLK = 2;
} else
if ( n >= 1800 && n < 1803 ) {
	BLK = 0;
} else
if ( n >= 1803 && n < 1804 ) {
	BLK = 4;
} else
if ( n >= 1804 && n < 1805 ) {
	BLK = 2;
} else
if ( n >= 1805 && n < 1806 ) {
	BLK = 0;
} else
if ( n >= 1806 && n < 1808 ) {
	BLK = 3;
} else
if ( n >= 1808 && n < 1811 ) {
	BLK = 4;
} else
if ( n >= 1811 && n < 1812 ) {
	BLK = 0;
} else
if ( n >= 1812 && n < 1813 ) {
	BLK = 2;
} else
if ( n >= 1813 && n < 1814 ) {
	BLK = 4;
} else
if ( n >= 1814 && n < 1815 ) {
	BLK = 3;
} else
if ( n >= 1815 && n < 1816 ) {
	BLK = 2;
} else
if ( n >= 1816 && n < 1828 ) {
	BLK = 4;
} else
if ( n >= 1828 && n < 1830 ) {
	BLK = 2;
} else
if ( n >= 1830 && n < 1831 ) {
	BLK = 0;
} else
if ( n >= 1831 && n < 1832 ) {
	BLK = 4;
} else
if ( n >= 1832 && n < 1833 ) {
	BLK = 2;
} else
if ( n >= 1833 && n < 1834 ) {
	BLK = 3;
} else
if ( n >= 1834 && n < 1859 ) {
	BLK = 4;
} else
if ( n >= 1859 && n < 1861 ) {
	BLK = 3;
} else
if ( n >= 1861 && n < 1863 ) {
	BLK = 2;
} else
if ( n >= 1863 && n < 1865 ) {
	BLK = 4;
} else
if ( n >= 1865 && n < 1866 ) {
	BLK = 3;
} else
if ( n >= 1866 && n < 1867 ) {
	BLK = 2;
} else
if ( n >= 1867 && n < 1868 ) {
	BLK = 0;
} else
if ( n >= 1868 && n < 1880 ) {
	BLK = 4;
} else
if ( n >= 1880 && n < 1881 ) {
	BLK = 3;
} else
if ( n >= 1881 && n < 1925 ) {
	BLK = 2;
} else
if ( n >= 1925 && n < 1937 ) {
	BLK = 4;
} else
if ( n >= 1937 && n < 1948 ) {
	BLK = 2;
} else
if ( n >= 1948 && n < 1957 ) {
	BLK = 4;
} else
if ( n >= 1957 && n < 2023 ) {
	BLK = 2;
} else
if ( n >= 2023 && n < 2024 ) {
	BLK = 3;
} else
if ( n >= 2024 && n < 2030 ) {
	BLK = 4;
} else
if ( n >= 2030 && n < 2035 ) {
	BLK = 2;
} else
if ( n >= 2035 && n < 2037 ) {
	BLK = 3;
} else
if ( n >= 2037 && n < 2043 ) {
	BLK = 4;
} else
if ( n >= 2043 && n < 2045 ) {
	BLK = 2;
} else
if ( n >= 2045 && n < 2052 ) {
	BLK = 3;
} else
if ( n >= 2052 && n < 2063 ) {
	BLK = 4;
} else
if ( n >= 2063 && n < 2072 ) {
	BLK = 3;
} else
if ( n >= 2072 && n < 2073 ) {
	BLK = 2;
} else
if ( n >= 2073 && n < 2076 ) {
	BLK = 4;
} else
if ( n >= 2076 && n < 2083 ) {
	BLK = 2;
} else
if ( n >= 2083 && n < 2086 ) {
	BLK = 3;
} else
if ( n >= 2086 && n < 2103 ) {
	BLK = 4;
} else
if ( n >= 2103 && n < 2104 ) {
	BLK = 2;
} else
if ( n >= 2104 && n < 2144 ) {
	BLK = 3;
} else
if ( n >= 2144 && n < 2145 ) {
	BLK = 4;
} else
if ( n >= 2145 && n < 2147 ) {
	BLK = 2;
} else
if ( n >= 2147 && n < 2150 ) {
	BLK = 0;
} else
if ( n >= 2150 && n < 2183 ) {
	BLK = 4;
} else
if ( n >= 2183 && n < 2184 ) {
	BLK = 2;
} else
if ( n >= 2184 && n < 2185 ) {
	BLK = 3;
} else
if ( n >= 2185 && n < 2189 ) {
	BLK = 0;
} else
if ( n >= 2189 && n < 2195 ) {
	BLK = 3;
} else
if ( n >= 2195 && n < 2335 ) {
	BLK = 4;
} else
if ( n >= 2335 && n < 2337 ) {
	BLK = 2;
} else
if ( n >= 2337 && n < 2361 ) {
	BLK = 3;
} else
if ( n >= 2361 && n < 2364 ) {
	BLK = 4;
} else
if ( n >= 2364 && n < 2365 ) {
	BLK = 0;
} else
if ( n >= 2365 && n < 2371 ) {
	BLK = 3;
} else
if ( n >= 2371 && n < 2400 ) {
	BLK = 4;
} else
if ( n >= 2400 && n < 2401 ) {
	BLK = 2;
} else
if ( n >= 2401 && n < 2409 ) {
	BLK = 0;
} else
if ( n >= 2409 && n < 2437 ) {
	BLK = 4;
} else
if ( n >= 2437 && n < 2441 ) {
	BLK = 0;
} else
if ( n >= 2441 && n < 2443 ) {
	BLK = 3;
} else
if ( n >= 2443 && n < 2464 ) {
	BLK = 4;
} else
if ( n >= 2464 && n < 2482 ) {
	BLK = 0;
} else
if ( n >= 2482 && n < 2525 ) {
	BLK = 4;
} else
if ( n >= 2525 && n < 2536 ) {
	BLK = 2;
} else
if ( n >= 2536 && n < 2555 ) {
	BLK = 4;
} else
if ( n >= 2555 && n < 2558 ) {
	BLK = 2;
} else
if ( n >= 2558 && n < 2572 ) {
	BLK = 4;
} else
if ( n >= 2572 && n < 2573 ) {
	BLK = 3;
} else
if ( n >= 2573 && n < 2577 ) {
	BLK = 2;
} else
if ( n >= 2577 && n < 2598 ) {
	BLK = 4;
} else
if ( n >= 2598 && n < 2599 ) {
	BLK = 3;
} else
if ( n >= 2599 && n < 2600 ) {
	BLK = 2;
} else
if ( n >= 2600 && n < 2628 ) {
	BLK = 4;
} else
if ( n >= 2628 && n < 2630 ) {
	BLK = 3;
} else
if ( n >= 2630 && n < 2645 ) {
	BLK = 2;
} else
if ( n >= 2645 && n < 2663 ) {
	BLK = 3;
} else
if ( n >= 2663 && n < 2669 ) {
	BLK = 4;
} else
if ( n >= 2669 && n < 2671 ) {
	BLK = 3;
} else
if ( n >= 2671 && n < 2675 ) {
	BLK = 0;
} else
if ( n >= 2675 && n < 2682 ) {
	BLK = 3;
} else
if ( n >= 2682 && n < 2685 ) {
	BLK = 4;
} else
if ( n >= 2685 && n < 2687 ) {
	BLK = 2;
} else
if ( n >= 2687 && n < 2704 ) {
	BLK = 3;
} else
if ( n >= 2704 && n < 2766 ) {
	BLK = 4;
} else
if ( n >= 2766 && n < 2767 ) {
	BLK = 3;
} else
if ( n >= 2767 && n < 2768 ) {
	BLK = 2;
} else
if ( n >= 2768 && n < 2769 ) {
	BLK = 4;
} else
if ( n >= 2769 && n < 2770 ) {
	BLK = 3;
} else
if ( n >= 2770 && n < 2771 ) {
	BLK = 2;
} else
if ( n >= 2771 && n < 2775 ) {
	BLK = 4;
} else
if ( n >= 2775 && n < 2784 ) {
	BLK = 3;
} else
if ( n >= 2784 && n < 2797 ) {
	BLK = 4;
} else
if ( n >= 2797 && n < 2798 ) {
	BLK = 3;
} else
if ( n >= 2798 && n < 2799 ) {
	BLK = 2;
} else
if ( n >= 2799 && n < 2808 ) {
	BLK = 4;
} else
if ( n >= 2808 && n < 2810 ) {
	BLK = 3;
} else
if ( n >= 2810 && n < 2811 ) {
	BLK = 2;
} else
if ( n >= 2811 && n < 3552 ) {
	BLK = 4;
} else
if ( n >= 3552 && n < 4784 ) {
	BLK = 3;
} else
if ( n >= 4784 && n < 5796 ) {
	BLK = 4;
} else
if ( n >= 5796 && n < 8851 ) {
	BLK = 3;
} else
if ( n >= 8851 && n < 8915 ) {
	BLK = 4;
} else
if ( n >= 8915 && n < 10248 ) {
	BLK = 5;
} else
if ( n >= 10248 && n < 17033 ) {
	BLK = 2;
} else
if ( n >= 17033 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
