#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Tue Feb 03 12:15:05  2026
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
MAXmem= 101999210496
// capacity of the work area reserved on the GPU
WORK= 6259200
// for double or cuFloatComplex or int64
MAXDIM= 107269
// for float or cuHalfComplex or int32
MAXDIM2= 151702
// for cuDoubleComplex or DD or int128
MAXDIM3= 75851
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214539
// cuda version
CUDA= 13010
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 496 ) {
	BLK = 0;
} else
if ( n >= 496 && n < 498 ) {
	BLK = 1;
} else
if ( n >= 498 && n < 499 ) {
	BLK = 2;
} else
if ( n >= 499 && n < 500 ) {
	BLK = 0;
} else
if ( n >= 500 && n < 501 ) {
	BLK = 5;
} else
if ( n >= 501 && n < 513 ) {
	BLK = 1;
} else
if ( n >= 513 && n < 536 ) {
	BLK = 0;
} else
if ( n >= 536 && n < 537 ) {
	BLK = 2;
} else
if ( n >= 537 && n < 573 ) {
	BLK = 1;
} else
if ( n >= 573 && n < 574 ) {
	BLK = 6;
} else
if ( n >= 574 && n < 575 ) {
	BLK = 5;
} else
if ( n >= 575 && n < 591 ) {
	BLK = 0;
} else
if ( n >= 591 && n < 592 ) {
	BLK = 1;
} else
if ( n >= 592 && n < 593 ) {
	BLK = 6;
} else
if ( n >= 593 && n < 624 ) {
	BLK = 0;
} else
if ( n >= 624 && n < 625 ) {
	BLK = 1;
} else
if ( n >= 625 && n < 626 ) {
	BLK = 2;
} else
if ( n >= 626 && n < 766 ) {
	BLK = 0;
} else
if ( n >= 766 && n < 767 ) {
	BLK = 2;
} else
if ( n >= 767 && n < 768 ) {
	BLK = 6;
} else
if ( n >= 768 && n < 1671 ) {
	BLK = 0;
} else
if ( n >= 1671 && n < 1714 ) {
	BLK = 1;
} else
if ( n >= 1714 && n < 1787 ) {
	BLK = 0;
} else
if ( n >= 1787 && n < 1798 ) {
	BLK = 1;
} else
if ( n >= 1798 && n < 1799 ) {
	BLK = 4;
} else
if ( n >= 1799 && n < 1902 ) {
	BLK = 0;
} else
if ( n >= 1902 && n < 1903 ) {
	BLK = 3;
} else
if ( n >= 1903 && n < 1918 ) {
	BLK = 1;
} else
if ( n >= 1918 && n < 1919 ) {
	BLK = 6;
} else
if ( n >= 1919 && n < 1922 ) {
	BLK = 0;
} else
if ( n >= 1922 && n < 1928 ) {
	BLK = 1;
} else
if ( n >= 1928 && n < 1932 ) {
	BLK = 0;
} else
if ( n >= 1932 && n < 1933 ) {
	BLK = 3;
} else
if ( n >= 1933 && n < 1940 ) {
	BLK = 1;
} else
if ( n >= 1940 && n < 1945 ) {
	BLK = 3;
} else
if ( n >= 1945 && n < 1957 ) {
	BLK = 0;
} else
if ( n >= 1957 && n < 1960 ) {
	BLK = 1;
} else
if ( n >= 1960 && n < 1967 ) {
	BLK = 0;
} else
if ( n >= 1967 && n < 1988 ) {
	BLK = 1;
} else
if ( n >= 1988 && n < 1991 ) {
	BLK = 0;
} else
if ( n >= 1991 && n < 1992 ) {
	BLK = 1;
} else
if ( n >= 1992 && n < 1993 ) {
	BLK = 3;
} else
if ( n >= 1993 && n < 2016 ) {
	BLK = 0;
} else
if ( n >= 2016 && n < 2017 ) {
	BLK = 3;
} else
if ( n >= 2017 && n < 2019 ) {
	BLK = 1;
} else
if ( n >= 2019 && n < 2027 ) {
	BLK = 0;
} else
if ( n >= 2027 && n < 2050 ) {
	BLK = 1;
} else
if ( n >= 2050 && n < 2053 ) {
	BLK = 3;
} else
if ( n >= 2053 && n < 2056 ) {
	BLK = 0;
} else
if ( n >= 2056 && n < 2062 ) {
	BLK = 3;
} else
if ( n >= 2062 && n < 2063 ) {
	BLK = 0;
} else
if ( n >= 2063 && n < 2064 ) {
	BLK = 1;
} else
if ( n >= 2064 && n < 2065 ) {
	BLK = 3;
} else
if ( n >= 2065 && n < 2070 ) {
	BLK = 0;
} else
if ( n >= 2070 && n < 2071 ) {
	BLK = 3;
} else
if ( n >= 2071 && n < 2111 ) {
	BLK = 1;
} else
if ( n >= 2111 && n < 2112 ) {
	BLK = 0;
} else
if ( n >= 2112 && n < 2131 ) {
	BLK = 3;
} else
if ( n >= 2131 && n < 2132 ) {
	BLK = 0;
} else
if ( n >= 2132 && n < 2154 ) {
	BLK = 1;
} else
if ( n >= 2154 && n < 2155 ) {
	BLK = 6;
} else
if ( n >= 2155 && n < 2169 ) {
	BLK = 3;
} else
if ( n >= 2169 && n < 2170 ) {
	BLK = 0;
} else
if ( n >= 2170 && n < 2187 ) {
	BLK = 1;
} else
if ( n >= 2187 && n < 2188 ) {
	BLK = 0;
} else
if ( n >= 2188 && n < 2265 ) {
	BLK = 3;
} else
if ( n >= 2265 && n < 2266 ) {
	BLK = 0;
} else
if ( n >= 2266 && n < 2268 ) {
	BLK = 1;
} else
if ( n >= 2268 && n < 3273 ) {
	BLK = 3;
} else
if ( n >= 3273 && n < 5081 ) {
	BLK = 1;
} else
if ( n >= 5081 && n < 5093 ) {
	BLK = 5;
} else
if ( n >= 5093 && n < 5268 ) {
	BLK = 4;
} else
if ( n >= 5268 && n < 7075 ) {
	BLK = 1;
} else
if ( n >= 7075 && n < 7101 ) {
	BLK = 4;
} else
if ( n >= 7101 && n < 7122 ) {
	BLK = 5;
} else
if ( n >= 7122 && n < 7237 ) {
	BLK = 1;
} else
if ( n >= 7237 && n < 7249 ) {
	BLK = 4;
} else
if ( n >= 7249 && n < 7287 ) {
	BLK = 5;
} else
if ( n >= 7287 && n < 7684 ) {
	BLK = 1;
} else
if ( n >= 7684 && n < 7696 ) {
	BLK = 4;
} else
if ( n >= 7696 && n < 7737 ) {
	BLK = 5;
} else
if ( n >= 7737 && n < 8394 ) {
	BLK = 1;
} else
if ( n >= 8394 && n < 8418 ) {
	BLK = 5;
} else
if ( n >= 8418 && n < 8427 ) {
	BLK = 4;
} else
if ( n >= 8427 && n < 13760 ) {
	BLK = 1;
} else
if ( n >= 13760 && n < 13815 ) {
	BLK = 2;
} else
if ( n >= 13815 && n < 13842 ) {
	BLK = 5;
} else
if ( n >= 13842 && n < 14349 ) {
	BLK = 1;
} else
if ( n >= 14349 && n < 14973 ) {
	BLK = 2;
} else
if ( n >= 14973 && n < 15126 ) {
	BLK = 5;
} else
if ( n >= 15126 && n < 15236 ) {
	BLK = 1;
} else
if ( n >= 15236 && n < 15414 ) {
	BLK = 2;
} else
if ( n >= 15414 && n < 15544 ) {
	BLK = 5;
} else
if ( n >= 15544 && n < 16865 ) {
	BLK = 1;
} else
if ( n >= 16865 && n < 17460 ) {
	BLK = 5;
} else
if ( n >= 17460 && n < 18531 ) {
	BLK = 1;
} else
if ( n >= 18531 && n < 88237 ) {
	BLK = 5;
} else
if ( n >= 88237 && n < 92175 ) {
	BLK = 1;
} else
if ( n >= 92175 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
