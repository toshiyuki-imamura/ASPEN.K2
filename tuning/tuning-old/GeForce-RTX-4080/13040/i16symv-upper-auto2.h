#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Wed Sep 23 09:24:28  2026
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16800759808
// capacity of the work area reserved on the GPU
WORK= 2539520
// for double or cuFloatComplex or int64
MAXDIM= 43535
// for float or cuHalfComplex or int32
MAXDIM2= 61568
// for cuDoubleComplex or DD or int128
MAXDIM3= 30784
// for DD-Complex
MAXDIM4= 21767
// for half or int16
MAXDIM5= 87070
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 890
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

if ( n >= 1 && n < 704 ) {
	BLK = 0;
} else
if ( n >= 704 && n < 707 ) {
	BLK = 4;
} else
if ( n >= 707 && n < 720 ) {
	BLK = 5;
} else
if ( n >= 720 && n < 722 ) {
	BLK = 0;
} else
if ( n >= 722 && n < 743 ) {
	BLK = 4;
} else
if ( n >= 743 && n < 746 ) {
	BLK = 0;
} else
if ( n >= 746 && n < 771 ) {
	BLK = 5;
} else
if ( n >= 771 && n < 775 ) {
	BLK = 4;
} else
if ( n >= 775 && n < 832 ) {
	BLK = 0;
} else
if ( n >= 832 && n < 842 ) {
	BLK = 4;
} else
if ( n >= 842 && n < 865 ) {
	BLK = 5;
} else
if ( n >= 865 && n < 867 ) {
	BLK = 4;
} else
if ( n >= 867 && n < 868 ) {
	BLK = 3;
} else
if ( n >= 868 && n < 869 ) {
	BLK = 2;
} else
if ( n >= 869 && n < 871 ) {
	BLK = 5;
} else
if ( n >= 871 && n < 873 ) {
	BLK = 0;
} else
if ( n >= 873 && n < 898 ) {
	BLK = 4;
} else
if ( n >= 898 && n < 900 ) {
	BLK = 3;
} else
if ( n >= 900 && n < 901 ) {
	BLK = 2;
} else
if ( n >= 901 && n < 902 ) {
	BLK = 0;
} else
if ( n >= 902 && n < 903 ) {
	BLK = 5;
} else
if ( n >= 903 && n < 904 ) {
	BLK = 2;
} else
if ( n >= 904 && n < 906 ) {
	BLK = 0;
} else
if ( n >= 906 && n < 908 ) {
	BLK = 4;
} else
if ( n >= 908 && n < 910 ) {
	BLK = 5;
} else
if ( n >= 910 && n < 918 ) {
	BLK = 0;
} else
if ( n >= 918 && n < 924 ) {
	BLK = 2;
} else
if ( n >= 924 && n < 925 ) {
	BLK = 1;
} else
if ( n >= 925 && n < 926 ) {
	BLK = 4;
} else
if ( n >= 926 && n < 1083 ) {
	BLK = 0;
} else
if ( n >= 1083 && n < 1086 ) {
	BLK = 2;
} else
if ( n >= 1086 && n < 1113 ) {
	BLK = 0;
} else
if ( n >= 1113 && n < 1117 ) {
	BLK = 4;
} else
if ( n >= 1117 && n < 1126 ) {
	BLK = 2;
} else
if ( n >= 1126 && n < 1331 ) {
	BLK = 4;
} else
if ( n >= 1331 && n < 1388 ) {
	BLK = 1;
} else
if ( n >= 1388 && n < 1389 ) {
	BLK = 0;
} else
if ( n >= 1389 && n < 1390 ) {
	BLK = 4;
} else
if ( n >= 1390 && n < 1410 ) {
	BLK = 1;
} else
if ( n >= 1410 && n < 1412 ) {
	BLK = 2;
} else
if ( n >= 1412 && n < 1417 ) {
	BLK = 4;
} else
if ( n >= 1417 && n < 1418 ) {
	BLK = 0;
} else
if ( n >= 1418 && n < 1425 ) {
	BLK = 1;
} else
if ( n >= 1425 && n < 1426 ) {
	BLK = 0;
} else
if ( n >= 1426 && n < 1428 ) {
	BLK = 2;
} else
if ( n >= 1428 && n < 1429 ) {
	BLK = 1;
} else
if ( n >= 1429 && n < 1433 ) {
	BLK = 0;
} else
if ( n >= 1433 && n < 1434 ) {
	BLK = 2;
} else
if ( n >= 1434 && n < 1448 ) {
	BLK = 4;
} else
if ( n >= 1448 && n < 1451 ) {
	BLK = 0;
} else
if ( n >= 1451 && n < 1454 ) {
	BLK = 1;
} else
if ( n >= 1454 && n < 1482 ) {
	BLK = 0;
} else
if ( n >= 1482 && n < 1483 ) {
	BLK = 2;
} else
if ( n >= 1483 && n < 1547 ) {
	BLK = 4;
} else
if ( n >= 1547 && n < 1548 ) {
	BLK = 1;
} else
if ( n >= 1548 && n < 1562 ) {
	BLK = 2;
} else
if ( n >= 1562 && n < 1572 ) {
	BLK = 4;
} else
if ( n >= 1572 && n < 1574 ) {
	BLK = 2;
} else
if ( n >= 1574 && n < 1611 ) {
	BLK = 0;
} else
if ( n >= 1611 && n < 1624 ) {
	BLK = 4;
} else
if ( n >= 1624 && n < 1852 ) {
	BLK = 0;
} else
if ( n >= 1852 && n < 1856 ) {
	BLK = 4;
} else
if ( n >= 1856 && n < 1857 ) {
	BLK = 0;
} else
if ( n >= 1857 && n < 1858 ) {
	BLK = 1;
} else
if ( n >= 1858 && n < 1897 ) {
	BLK = 4;
} else
if ( n >= 1897 && n < 1900 ) {
	BLK = 1;
} else
if ( n >= 1900 && n < 1938 ) {
	BLK = 0;
} else
if ( n >= 1938 && n < 1939 ) {
	BLK = 1;
} else
if ( n >= 1939 && n < 1957 ) {
	BLK = 4;
} else
if ( n >= 1957 && n < 1958 ) {
	BLK = 3;
} else
if ( n >= 1958 && n < 1979 ) {
	BLK = 0;
} else
if ( n >= 1979 && n < 1980 ) {
	BLK = 1;
} else
if ( n >= 1980 && n < 2082 ) {
	BLK = 4;
} else
if ( n >= 2082 && n < 2083 ) {
	BLK = 1;
} else
if ( n >= 2083 && n < 2084 ) {
	BLK = 0;
} else
if ( n >= 2084 && n < 2086 ) {
	BLK = 4;
} else
if ( n >= 2086 && n < 2094 ) {
	BLK = 1;
} else
if ( n >= 2094 && n < 2104 ) {
	BLK = 4;
} else
if ( n >= 2104 && n < 2106 ) {
	BLK = 0;
} else
if ( n >= 2106 && n < 2110 ) {
	BLK = 1;
} else
if ( n >= 2110 && n < 2137 ) {
	BLK = 4;
} else
if ( n >= 2137 && n < 2138 ) {
	BLK = 0;
} else
if ( n >= 2138 && n < 2142 ) {
	BLK = 1;
} else
if ( n >= 2142 && n < 2276 ) {
	BLK = 4;
} else
if ( n >= 2276 && n < 2279 ) {
	BLK = 0;
} else
if ( n >= 2279 && n < 2299 ) {
	BLK = 4;
} else
if ( n >= 2299 && n < 2378 ) {
	BLK = 1;
} else
if ( n >= 2378 && n < 2381 ) {
	BLK = 0;
} else
if ( n >= 2381 && n < 2386 ) {
	BLK = 1;
} else
if ( n >= 2386 && n < 2437 ) {
	BLK = 4;
} else
if ( n >= 2437 && n < 2440 ) {
	BLK = 1;
} else
if ( n >= 2440 && n < 2442 ) {
	BLK = 0;
} else
if ( n >= 2442 && n < 2460 ) {
	BLK = 4;
} else
if ( n >= 2460 && n < 2461 ) {
	BLK = 0;
} else
if ( n >= 2461 && n < 2468 ) {
	BLK = 1;
} else
if ( n >= 2468 && n < 2470 ) {
	BLK = 4;
} else
if ( n >= 2470 && n < 2471 ) {
	BLK = 0;
} else
if ( n >= 2471 && n < 2472 ) {
	BLK = 1;
} else
if ( n >= 2472 && n < 2473 ) {
	BLK = 4;
} else
if ( n >= 2473 && n < 2474 ) {
	BLK = 0;
} else
if ( n >= 2474 && n < 2539 ) {
	BLK = 1;
} else
if ( n >= 2539 && n < 2675 ) {
	BLK = 4;
} else
if ( n >= 2675 && n < 2685 ) {
	BLK = 1;
} else
if ( n >= 2685 && n < 2686 ) {
	BLK = 0;
} else
if ( n >= 2686 && n < 2698 ) {
	BLK = 4;
} else
if ( n >= 2698 && n < 2699 ) {
	BLK = 1;
} else
if ( n >= 2699 && n < 2700 ) {
	BLK = 0;
} else
if ( n >= 2700 && n < 2724 ) {
	BLK = 4;
} else
if ( n >= 2724 && n < 2753 ) {
	BLK = 1;
} else
if ( n >= 2753 && n < 2754 ) {
	BLK = 4;
} else
if ( n >= 2754 && n < 2755 ) {
	BLK = 0;
} else
if ( n >= 2755 && n < 2774 ) {
	BLK = 1;
} else
if ( n >= 2774 && n < 2776 ) {
	BLK = 4;
} else
if ( n >= 2776 && n < 2777 ) {
	BLK = 0;
} else
if ( n >= 2777 && n < 2778 ) {
	BLK = 1;
} else
if ( n >= 2778 && n < 2779 ) {
	BLK = 4;
} else
if ( n >= 2779 && n < 2780 ) {
	BLK = 0;
} else
if ( n >= 2780 && n < 2826 ) {
	BLK = 1;
} else
if ( n >= 2826 && n < 2827 ) {
	BLK = 0;
} else
if ( n >= 2827 && n < 2828 ) {
	BLK = 4;
} else
if ( n >= 2828 && n < 2842 ) {
	BLK = 1;
} else
if ( n >= 2842 && n < 2843 ) {
	BLK = 0;
} else
if ( n >= 2843 && n < 2847 ) {
	BLK = 4;
} else
if ( n >= 2847 && n < 2849 ) {
	BLK = 1;
} else
if ( n >= 2849 && n < 2850 ) {
	BLK = 3;
} else
if ( n >= 2850 && n < 2860 ) {
	BLK = 4;
} else
if ( n >= 2860 && n < 2902 ) {
	BLK = 1;
} else
if ( n >= 2902 && n < 2904 ) {
	BLK = 4;
} else
if ( n >= 2904 && n < 2905 ) {
	BLK = 0;
} else
if ( n >= 2905 && n < 3078 ) {
	BLK = 1;
} else
if ( n >= 3078 && n < 3079 ) {
	BLK = 4;
} else
if ( n >= 3079 && n < 3080 ) {
	BLK = 3;
} else
if ( n >= 3080 && n < 3160 ) {
	BLK = 1;
} else
if ( n >= 3160 && n < 3161 ) {
	BLK = 4;
} else
if ( n >= 3161 && n < 3162 ) {
	BLK = 3;
} else
if ( n >= 3162 && n < 3175 ) {
	BLK = 1;
} else
if ( n >= 3175 && n < 3176 ) {
	BLK = 3;
} else
if ( n >= 3176 && n < 3271 ) {
	BLK = 4;
} else
if ( n >= 3271 && n < 4871 ) {
	BLK = 1;
} else
if ( n >= 4871 && n < 12925 ) {
	BLK = 3;
} else
if ( n >= 12925 && n < 15773 ) {
	BLK = 1;
} else
if ( n >= 15773 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
