#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Fri Aug 07 04:22:16  2026
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

if ( n >= 1 && n < 497 ) {
	BLK = 0;
} else
if ( n >= 497 && n < 525 ) {
	BLK = 1;
} else
if ( n >= 525 && n < 526 ) {
	BLK = 4;
} else
if ( n >= 526 && n < 538 ) {
	BLK = 0;
} else
if ( n >= 538 && n < 539 ) {
	BLK = 5;
} else
if ( n >= 539 && n < 549 ) {
	BLK = 1;
} else
if ( n >= 549 && n < 557 ) {
	BLK = 0;
} else
if ( n >= 557 && n < 558 ) {
	BLK = 5;
} else
if ( n >= 558 && n < 559 ) {
	BLK = 4;
} else
if ( n >= 559 && n < 560 ) {
	BLK = 0;
} else
if ( n >= 560 && n < 565 ) {
	BLK = 1;
} else
if ( n >= 565 && n < 566 ) {
	BLK = 4;
} else
if ( n >= 566 && n < 571 ) {
	BLK = 0;
} else
if ( n >= 571 && n < 574 ) {
	BLK = 1;
} else
if ( n >= 574 && n < 575 ) {
	BLK = 5;
} else
if ( n >= 575 && n < 576 ) {
	BLK = 2;
} else
if ( n >= 576 && n < 585 ) {
	BLK = 0;
} else
if ( n >= 585 && n < 586 ) {
	BLK = 4;
} else
if ( n >= 586 && n < 587 ) {
	BLK = 1;
} else
if ( n >= 587 && n < 588 ) {
	BLK = 2;
} else
if ( n >= 588 && n < 589 ) {
	BLK = 0;
} else
if ( n >= 589 && n < 590 ) {
	BLK = 4;
} else
if ( n >= 590 && n < 592 ) {
	BLK = 5;
} else
if ( n >= 592 && n < 596 ) {
	BLK = 0;
} else
if ( n >= 596 && n < 599 ) {
	BLK = 2;
} else
if ( n >= 599 && n < 600 ) {
	BLK = 4;
} else
if ( n >= 600 && n < 603 ) {
	BLK = 0;
} else
if ( n >= 603 && n < 604 ) {
	BLK = 5;
} else
if ( n >= 604 && n < 607 ) {
	BLK = 2;
} else
if ( n >= 607 && n < 609 ) {
	BLK = 0;
} else
if ( n >= 609 && n < 610 ) {
	BLK = 1;
} else
if ( n >= 610 && n < 611 ) {
	BLK = 4;
} else
if ( n >= 611 && n < 624 ) {
	BLK = 0;
} else
if ( n >= 624 && n < 626 ) {
	BLK = 2;
} else
if ( n >= 626 && n < 627 ) {
	BLK = 1;
} else
if ( n >= 627 && n < 659 ) {
	BLK = 0;
} else
if ( n >= 659 && n < 660 ) {
	BLK = 1;
} else
if ( n >= 660 && n < 673 ) {
	BLK = 5;
} else
if ( n >= 673 && n < 767 ) {
	BLK = 0;
} else
if ( n >= 767 && n < 771 ) {
	BLK = 1;
} else
if ( n >= 771 && n < 777 ) {
	BLK = 4;
} else
if ( n >= 777 && n < 783 ) {
	BLK = 1;
} else
if ( n >= 783 && n < 786 ) {
	BLK = 0;
} else
if ( n >= 786 && n < 792 ) {
	BLK = 4;
} else
if ( n >= 792 && n < 793 ) {
	BLK = 0;
} else
if ( n >= 793 && n < 794 ) {
	BLK = 1;
} else
if ( n >= 794 && n < 798 ) {
	BLK = 4;
} else
if ( n >= 798 && n < 800 ) {
	BLK = 5;
} else
if ( n >= 800 && n < 801 ) {
	BLK = 1;
} else
if ( n >= 801 && n < 866 ) {
	BLK = 0;
} else
if ( n >= 866 && n < 867 ) {
	BLK = 4;
} else
if ( n >= 867 && n < 882 ) {
	BLK = 1;
} else
if ( n >= 882 && n < 982 ) {
	BLK = 0;
} else
if ( n >= 982 && n < 990 ) {
	BLK = 1;
} else
if ( n >= 990 && n < 991 ) {
	BLK = 3;
} else
if ( n >= 991 && n < 992 ) {
	BLK = 0;
} else
if ( n >= 992 && n < 1029 ) {
	BLK = 1;
} else
if ( n >= 1029 && n < 1030 ) {
	BLK = 2;
} else
if ( n >= 1030 && n < 1031 ) {
	BLK = 4;
} else
if ( n >= 1031 && n < 1053 ) {
	BLK = 1;
} else
if ( n >= 1053 && n < 1054 ) {
	BLK = 4;
} else
if ( n >= 1054 && n < 1055 ) {
	BLK = 2;
} else
if ( n >= 1055 && n < 1056 ) {
	BLK = 1;
} else
if ( n >= 1056 && n < 1069 ) {
	BLK = 4;
} else
if ( n >= 1069 && n < 1079 ) {
	BLK = 1;
} else
if ( n >= 1079 && n < 1080 ) {
	BLK = 2;
} else
if ( n >= 1080 && n < 1088 ) {
	BLK = 4;
} else
if ( n >= 1088 && n < 1089 ) {
	BLK = 5;
} else
if ( n >= 1089 && n < 1093 ) {
	BLK = 2;
} else
if ( n >= 1093 && n < 1094 ) {
	BLK = 0;
} else
if ( n >= 1094 && n < 1099 ) {
	BLK = 1;
} else
if ( n >= 1099 && n < 1100 ) {
	BLK = 2;
} else
if ( n >= 1100 && n < 1105 ) {
	BLK = 4;
} else
if ( n >= 1105 && n < 1106 ) {
	BLK = 2;
} else
if ( n >= 1106 && n < 1107 ) {
	BLK = 0;
} else
if ( n >= 1107 && n < 1111 ) {
	BLK = 4;
} else
if ( n >= 1111 && n < 1115 ) {
	BLK = 1;
} else
if ( n >= 1115 && n < 1116 ) {
	BLK = 4;
} else
if ( n >= 1116 && n < 1117 ) {
	BLK = 2;
} else
if ( n >= 1117 && n < 1118 ) {
	BLK = 1;
} else
if ( n >= 1118 && n < 1119 ) {
	BLK = 0;
} else
if ( n >= 1119 && n < 1120 ) {
	BLK = 2;
} else
if ( n >= 1120 && n < 1121 ) {
	BLK = 5;
} else
if ( n >= 1121 && n < 1122 ) {
	BLK = 0;
} else
if ( n >= 1122 && n < 1123 ) {
	BLK = 2;
} else
if ( n >= 1123 && n < 1125 ) {
	BLK = 1;
} else
if ( n >= 1125 && n < 1126 ) {
	BLK = 4;
} else
if ( n >= 1126 && n < 1128 ) {
	BLK = 2;
} else
if ( n >= 1128 && n < 1129 ) {
	BLK = 0;
} else
if ( n >= 1129 && n < 1151 ) {
	BLK = 1;
} else
if ( n >= 1151 && n < 1152 ) {
	BLK = 3;
} else
if ( n >= 1152 && n < 1162 ) {
	BLK = 4;
} else
if ( n >= 1162 && n < 1170 ) {
	BLK = 1;
} else
if ( n >= 1170 && n < 1171 ) {
	BLK = 2;
} else
if ( n >= 1171 && n < 1186 ) {
	BLK = 4;
} else
if ( n >= 1186 && n < 1187 ) {
	BLK = 1;
} else
if ( n >= 1187 && n < 1190 ) {
	BLK = 2;
} else
if ( n >= 1190 && n < 1201 ) {
	BLK = 4;
} else
if ( n >= 1201 && n < 1202 ) {
	BLK = 3;
} else
if ( n >= 1202 && n < 1203 ) {
	BLK = 2;
} else
if ( n >= 1203 && n < 1213 ) {
	BLK = 4;
} else
if ( n >= 1213 && n < 1214 ) {
	BLK = 1;
} else
if ( n >= 1214 && n < 1215 ) {
	BLK = 2;
} else
if ( n >= 1215 && n < 1231 ) {
	BLK = 4;
} else
if ( n >= 1231 && n < 1233 ) {
	BLK = 1;
} else
if ( n >= 1233 && n < 1234 ) {
	BLK = 2;
} else
if ( n >= 1234 && n < 1244 ) {
	BLK = 4;
} else
if ( n >= 1244 && n < 1249 ) {
	BLK = 2;
} else
if ( n >= 1249 && n < 1275 ) {
	BLK = 1;
} else
if ( n >= 1275 && n < 1276 ) {
	BLK = 2;
} else
if ( n >= 1276 && n < 1281 ) {
	BLK = 5;
} else
if ( n >= 1281 && n < 1325 ) {
	BLK = 1;
} else
if ( n >= 1325 && n < 1368 ) {
	BLK = 4;
} else
if ( n >= 1368 && n < 1383 ) {
	BLK = 2;
} else
if ( n >= 1383 && n < 1385 ) {
	BLK = 4;
} else
if ( n >= 1385 && n < 1386 ) {
	BLK = 0;
} else
if ( n >= 1386 && n < 1406 ) {
	BLK = 2;
} else
if ( n >= 1406 && n < 1596 ) {
	BLK = 4;
} else
if ( n >= 1596 && n < 1597 ) {
	BLK = 5;
} else
if ( n >= 1597 && n < 1598 ) {
	BLK = 1;
} else
if ( n >= 1598 && n < 1665 ) {
	BLK = 0;
} else
if ( n >= 1665 && n < 1666 ) {
	BLK = 5;
} else
if ( n >= 1666 && n < 1670 ) {
	BLK = 2;
} else
if ( n >= 1670 && n < 1701 ) {
	BLK = 0;
} else
if ( n >= 1701 && n < 1702 ) {
	BLK = 1;
} else
if ( n >= 1702 && n < 1706 ) {
	BLK = 4;
} else
if ( n >= 1706 && n < 1719 ) {
	BLK = 0;
} else
if ( n >= 1719 && n < 1720 ) {
	BLK = 2;
} else
if ( n >= 1720 && n < 1721 ) {
	BLK = 1;
} else
if ( n >= 1721 && n < 1732 ) {
	BLK = 0;
} else
if ( n >= 1732 && n < 1734 ) {
	BLK = 2;
} else
if ( n >= 1734 && n < 1735 ) {
	BLK = 4;
} else
if ( n >= 1735 && n < 1737 ) {
	BLK = 0;
} else
if ( n >= 1737 && n < 1741 ) {
	BLK = 2;
} else
if ( n >= 1741 && n < 1744 ) {
	BLK = 0;
} else
if ( n >= 1744 && n < 1745 ) {
	BLK = 1;
} else
if ( n >= 1745 && n < 1746 ) {
	BLK = 4;
} else
if ( n >= 1746 && n < 1757 ) {
	BLK = 0;
} else
if ( n >= 1757 && n < 1758 ) {
	BLK = 4;
} else
if ( n >= 1758 && n < 1759 ) {
	BLK = 2;
} else
if ( n >= 1759 && n < 1762 ) {
	BLK = 0;
} else
if ( n >= 1762 && n < 1763 ) {
	BLK = 4;
} else
if ( n >= 1763 && n < 1764 ) {
	BLK = 2;
} else
if ( n >= 1764 && n < 1809 ) {
	BLK = 0;
} else
if ( n >= 1809 && n < 1810 ) {
	BLK = 2;
} else
if ( n >= 1810 && n < 1812 ) {
	BLK = 1;
} else
if ( n >= 1812 && n < 1838 ) {
	BLK = 0;
} else
if ( n >= 1838 && n < 1839 ) {
	BLK = 1;
} else
if ( n >= 1839 && n < 1840 ) {
	BLK = 5;
} else
if ( n >= 1840 && n < 1856 ) {
	BLK = 0;
} else
if ( n >= 1856 && n < 1859 ) {
	BLK = 1;
} else
if ( n >= 1859 && n < 1865 ) {
	BLK = 2;
} else
if ( n >= 1865 && n < 1870 ) {
	BLK = 0;
} else
if ( n >= 1870 && n < 1871 ) {
	BLK = 1;
} else
if ( n >= 1871 && n < 1875 ) {
	BLK = 2;
} else
if ( n >= 1875 && n < 1918 ) {
	BLK = 1;
} else
if ( n >= 1918 && n < 1919 ) {
	BLK = 2;
} else
if ( n >= 1919 && n < 1920 ) {
	BLK = 5;
} else
if ( n >= 1920 && n < 2048 ) {
	BLK = 1;
} else
if ( n >= 2048 && n < 2049 ) {
	BLK = 5;
} else
if ( n >= 2049 && n < 2050 ) {
	BLK = 4;
} else
if ( n >= 2050 && n < 2068 ) {
	BLK = 1;
} else
if ( n >= 2068 && n < 2069 ) {
	BLK = 2;
} else
if ( n >= 2069 && n < 2071 ) {
	BLK = 5;
} else
if ( n >= 2071 && n < 2072 ) {
	BLK = 4;
} else
if ( n >= 2072 && n < 2073 ) {
	BLK = 0;
} else
if ( n >= 2073 && n < 2074 ) {
	BLK = 2;
} else
if ( n >= 2074 && n < 2085 ) {
	BLK = 1;
} else
if ( n >= 2085 && n < 2086 ) {
	BLK = 4;
} else
if ( n >= 2086 && n < 2092 ) {
	BLK = 2;
} else
if ( n >= 2092 && n < 2094 ) {
	BLK = 0;
} else
if ( n >= 2094 && n < 2101 ) {
	BLK = 4;
} else
if ( n >= 2101 && n < 2102 ) {
	BLK = 2;
} else
if ( n >= 2102 && n < 2111 ) {
	BLK = 1;
} else
if ( n >= 2111 && n < 2121 ) {
	BLK = 2;
} else
if ( n >= 2121 && n < 2131 ) {
	BLK = 1;
} else
if ( n >= 2131 && n < 2132 ) {
	BLK = 2;
} else
if ( n >= 2132 && n < 2133 ) {
	BLK = 0;
} else
if ( n >= 2133 && n < 2134 ) {
	BLK = 1;
} else
if ( n >= 2134 && n < 2153 ) {
	BLK = 2;
} else
if ( n >= 2153 && n < 2154 ) {
	BLK = 1;
} else
if ( n >= 2154 && n < 2155 ) {
	BLK = 4;
} else
if ( n >= 2155 && n < 2157 ) {
	BLK = 2;
} else
if ( n >= 2157 && n < 2158 ) {
	BLK = 1;
} else
if ( n >= 2158 && n < 2190 ) {
	BLK = 0;
} else
if ( n >= 2190 && n < 2191 ) {
	BLK = 1;
} else
if ( n >= 2191 && n < 2192 ) {
	BLK = 2;
} else
if ( n >= 2192 && n < 2204 ) {
	BLK = 0;
} else
if ( n >= 2204 && n < 2205 ) {
	BLK = 2;
} else
if ( n >= 2205 && n < 2207 ) {
	BLK = 1;
} else
if ( n >= 2207 && n < 2209 ) {
	BLK = 0;
} else
if ( n >= 2209 && n < 2211 ) {
	BLK = 2;
} else
if ( n >= 2211 && n < 2212 ) {
	BLK = 1;
} else
if ( n >= 2212 && n < 2218 ) {
	BLK = 0;
} else
if ( n >= 2218 && n < 2220 ) {
	BLK = 2;
} else
if ( n >= 2220 && n < 2223 ) {
	BLK = 1;
} else
if ( n >= 2223 && n < 2224 ) {
	BLK = 0;
} else
if ( n >= 2224 && n < 2225 ) {
	BLK = 4;
} else
if ( n >= 2225 && n < 2233 ) {
	BLK = 2;
} else
if ( n >= 2233 && n < 2234 ) {
	BLK = 0;
} else
if ( n >= 2234 && n < 2236 ) {
	BLK = 1;
} else
if ( n >= 2236 && n < 2238 ) {
	BLK = 4;
} else
if ( n >= 2238 && n < 2261 ) {
	BLK = 2;
} else
if ( n >= 2261 && n < 2262 ) {
	BLK = 4;
} else
if ( n >= 2262 && n < 2263 ) {
	BLK = 5;
} else
if ( n >= 2263 && n < 2266 ) {
	BLK = 0;
} else
if ( n >= 2266 && n < 2268 ) {
	BLK = 1;
} else
if ( n >= 2268 && n < 2269 ) {
	BLK = 2;
} else
if ( n >= 2269 && n < 2270 ) {
	BLK = 4;
} else
if ( n >= 2270 && n < 2291 ) {
	BLK = 1;
} else
if ( n >= 2291 && n < 2292 ) {
	BLK = 2;
} else
if ( n >= 2292 && n < 2293 ) {
	BLK = 4;
} else
if ( n >= 2293 && n < 2294 ) {
	BLK = 1;
} else
if ( n >= 2294 && n < 2302 ) {
	BLK = 2;
} else
if ( n >= 2302 && n < 2560 ) {
	BLK = 1;
} else
if ( n >= 2560 && n < 2588 ) {
	BLK = 2;
} else
if ( n >= 2588 && n < 2589 ) {
	BLK = 1;
} else
if ( n >= 2589 && n < 2606 ) {
	BLK = 4;
} else
if ( n >= 2606 && n < 2607 ) {
	BLK = 1;
} else
if ( n >= 2607 && n < 2619 ) {
	BLK = 2;
} else
if ( n >= 2619 && n < 2620 ) {
	BLK = 4;
} else
if ( n >= 2620 && n < 2623 ) {
	BLK = 1;
} else
if ( n >= 2623 && n < 2624 ) {
	BLK = 4;
} else
if ( n >= 2624 && n < 2632 ) {
	BLK = 2;
} else
if ( n >= 2632 && n < 2633 ) {
	BLK = 4;
} else
if ( n >= 2633 && n < 2635 ) {
	BLK = 1;
} else
if ( n >= 2635 && n < 2645 ) {
	BLK = 2;
} else
if ( n >= 2645 && n < 2647 ) {
	BLK = 1;
} else
if ( n >= 2647 && n < 2648 ) {
	BLK = 4;
} else
if ( n >= 2648 && n < 2655 ) {
	BLK = 2;
} else
if ( n >= 2655 && n < 2662 ) {
	BLK = 1;
} else
if ( n >= 2662 && n < 2663 ) {
	BLK = 2;
} else
if ( n >= 2663 && n < 2665 ) {
	BLK = 4;
} else
if ( n >= 2665 && n < 2670 ) {
	BLK = 1;
} else
if ( n >= 2670 && n < 2671 ) {
	BLK = 4;
} else
if ( n >= 2671 && n < 2672 ) {
	BLK = 2;
} else
if ( n >= 2672 && n < 2681 ) {
	BLK = 1;
} else
if ( n >= 2681 && n < 2735 ) {
	BLK = 4;
} else
if ( n >= 2735 && n < 2868 ) {
	BLK = 1;
} else
if ( n >= 2868 && n < 2988 ) {
	BLK = 4;
} else
if ( n >= 2988 && n < 2989 ) {
	BLK = 1;
} else
if ( n >= 2989 && n < 2990 ) {
	BLK = 2;
} else
if ( n >= 2990 && n < 3008 ) {
	BLK = 4;
} else
if ( n >= 3008 && n < 3016 ) {
	BLK = 2;
} else
if ( n >= 3016 && n < 3020 ) {
	BLK = 1;
} else
if ( n >= 3020 && n < 3021 ) {
	BLK = 4;
} else
if ( n >= 3021 && n < 3022 ) {
	BLK = 2;
} else
if ( n >= 3022 && n < 3026 ) {
	BLK = 1;
} else
if ( n >= 3026 && n < 3027 ) {
	BLK = 4;
} else
if ( n >= 3027 && n < 3035 ) {
	BLK = 2;
} else
if ( n >= 3035 && n < 3036 ) {
	BLK = 1;
} else
if ( n >= 3036 && n < 3039 ) {
	BLK = 4;
} else
if ( n >= 3039 && n < 3040 ) {
	BLK = 2;
} else
if ( n >= 3040 && n < 3071 ) {
	BLK = 1;
} else
if ( n >= 3071 && n < 3134 ) {
	BLK = 4;
} else
if ( n >= 3134 && n < 3135 ) {
	BLK = 1;
} else
if ( n >= 3135 && n < 3165 ) {
	BLK = 5;
} else
if ( n >= 3165 && n < 3328 ) {
	BLK = 4;
} else
if ( n >= 3328 && n < 3388 ) {
	BLK = 2;
} else
if ( n >= 3388 && n < 3389 ) {
	BLK = 5;
} else
if ( n >= 3389 && n < 3391 ) {
	BLK = 4;
} else
if ( n >= 3391 && n < 3399 ) {
	BLK = 2;
} else
if ( n >= 3399 && n < 3400 ) {
	BLK = 4;
} else
if ( n >= 3400 && n < 3405 ) {
	BLK = 5;
} else
if ( n >= 3405 && n < 3421 ) {
	BLK = 2;
} else
if ( n >= 3421 && n < 3423 ) {
	BLK = 4;
} else
if ( n >= 3423 && n < 3424 ) {
	BLK = 5;
} else
if ( n >= 3424 && n < 3433 ) {
	BLK = 2;
} else
if ( n >= 3433 && n < 3435 ) {
	BLK = 5;
} else
if ( n >= 3435 && n < 3436 ) {
	BLK = 4;
} else
if ( n >= 3436 && n < 3454 ) {
	BLK = 2;
} else
if ( n >= 3454 && n < 3485 ) {
	BLK = 4;
} else
if ( n >= 3485 && n < 3486 ) {
	BLK = 1;
} else
if ( n >= 3486 && n < 3487 ) {
	BLK = 5;
} else
if ( n >= 3487 && n < 3583 ) {
	BLK = 4;
} else
if ( n >= 3583 && n < 3709 ) {
	BLK = 5;
} else
if ( n >= 3709 && n < 4013 ) {
	BLK = 2;
} else
if ( n >= 4013 && n < 4015 ) {
	BLK = 5;
} else
if ( n >= 4015 && n < 4030 ) {
	BLK = 4;
} else
if ( n >= 4030 && n < 5355 ) {
	BLK = 2;
} else
if ( n >= 5355 && n < 6156 ) {
	BLK = 5;
} else
if ( n >= 6156 && n < 8674 ) {
	BLK = 1;
} else
if ( n >= 8674 && n < 11008 ) {
	BLK = 2;
} else
if ( n >= 11008 && n < 17672 ) {
	BLK = 4;
} else
if ( n >= 17672 && n < 20125 ) {
	BLK = 3;
} else
if ( n >= 20125 && n < 20606 ) {
	BLK = 4;
} else
if ( n >= 20606 && n < 22086 ) {
	BLK = 3;
} else
if ( n >= 22086 && n < 22378 ) {
	BLK = 4;
} else
if ( n >= 22378 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
