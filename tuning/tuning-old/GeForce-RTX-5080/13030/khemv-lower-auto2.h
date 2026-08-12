#ifndef KHEMVL_AUTO2_H_INCLUDED
#define KHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVL
 Sat Aug 08 23:34:36  2026
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

if ( n >= 1 && n < 505 ) {
	BLK = 0;
} else
if ( n >= 505 && n < 511 ) {
	BLK = 5;
} else
if ( n >= 511 && n < 555 ) {
	BLK = 3;
} else
if ( n >= 555 && n < 996 ) {
	BLK = 0;
} else
if ( n >= 996 && n < 1085 ) {
	BLK = 3;
} else
if ( n >= 1085 && n < 1086 ) {
	BLK = 5;
} else
if ( n >= 1086 && n < 1148 ) {
	BLK = 2;
} else
if ( n >= 1148 && n < 1343 ) {
	BLK = 3;
} else
if ( n >= 1343 && n < 1344 ) {
	BLK = 2;
} else
if ( n >= 1344 && n < 1379 ) {
	BLK = 5;
} else
if ( n >= 1379 && n < 1380 ) {
	BLK = 2;
} else
if ( n >= 1380 && n < 1445 ) {
	BLK = 0;
} else
if ( n >= 1445 && n < 1450 ) {
	BLK = 3;
} else
if ( n >= 1450 && n < 1451 ) {
	BLK = 0;
} else
if ( n >= 1451 && n < 1452 ) {
	BLK = 2;
} else
if ( n >= 1452 && n < 1467 ) {
	BLK = 3;
} else
if ( n >= 1467 && n < 1468 ) {
	BLK = 0;
} else
if ( n >= 1468 && n < 1469 ) {
	BLK = 2;
} else
if ( n >= 1469 && n < 1474 ) {
	BLK = 3;
} else
if ( n >= 1474 && n < 1475 ) {
	BLK = 2;
} else
if ( n >= 1475 && n < 1489 ) {
	BLK = 0;
} else
if ( n >= 1489 && n < 1501 ) {
	BLK = 2;
} else
if ( n >= 1501 && n < 1577 ) {
	BLK = 3;
} else
if ( n >= 1577 && n < 1586 ) {
	BLK = 1;
} else
if ( n >= 1586 && n < 1618 ) {
	BLK = 3;
} else
if ( n >= 1618 && n < 1711 ) {
	BLK = 0;
} else
if ( n >= 1711 && n < 1712 ) {
	BLK = 4;
} else
if ( n >= 1712 && n < 1713 ) {
	BLK = 1;
} else
if ( n >= 1713 && n < 1714 ) {
	BLK = 0;
} else
if ( n >= 1714 && n < 1715 ) {
	BLK = 4;
} else
if ( n >= 1715 && n < 1792 ) {
	BLK = 1;
} else
if ( n >= 1792 && n < 1904 ) {
	BLK = 0;
} else
if ( n >= 1904 && n < 1918 ) {
	BLK = 2;
} else
if ( n >= 1918 && n < 1970 ) {
	BLK = 0;
} else
if ( n >= 1970 && n < 1971 ) {
	BLK = 2;
} else
if ( n >= 1971 && n < 1989 ) {
	BLK = 4;
} else
if ( n >= 1989 && n < 1995 ) {
	BLK = 0;
} else
if ( n >= 1995 && n < 1997 ) {
	BLK = 2;
} else
if ( n >= 1997 && n < 2002 ) {
	BLK = 4;
} else
if ( n >= 2002 && n < 2006 ) {
	BLK = 2;
} else
if ( n >= 2006 && n < 2014 ) {
	BLK = 0;
} else
if ( n >= 2014 && n < 2017 ) {
	BLK = 4;
} else
if ( n >= 2017 && n < 2019 ) {
	BLK = 2;
} else
if ( n >= 2019 && n < 2021 ) {
	BLK = 0;
} else
if ( n >= 2021 && n < 2022 ) {
	BLK = 4;
} else
if ( n >= 2022 && n < 2023 ) {
	BLK = 2;
} else
if ( n >= 2023 && n < 2024 ) {
	BLK = 0;
} else
if ( n >= 2024 && n < 2043 ) {
	BLK = 4;
} else
if ( n >= 2043 && n < 2044 ) {
	BLK = 0;
} else
if ( n >= 2044 && n < 2045 ) {
	BLK = 2;
} else
if ( n >= 2045 && n < 2052 ) {
	BLK = 4;
} else
if ( n >= 2052 && n < 2053 ) {
	BLK = 0;
} else
if ( n >= 2053 && n < 2059 ) {
	BLK = 2;
} else
if ( n >= 2059 && n < 2061 ) {
	BLK = 0;
} else
if ( n >= 2061 && n < 2079 ) {
	BLK = 4;
} else
if ( n >= 2079 && n < 2082 ) {
	BLK = 2;
} else
if ( n >= 2082 && n < 2086 ) {
	BLK = 0;
} else
if ( n >= 2086 && n < 2087 ) {
	BLK = 2;
} else
if ( n >= 2087 && n < 2088 ) {
	BLK = 4;
} else
if ( n >= 2088 && n < 2118 ) {
	BLK = 0;
} else
if ( n >= 2118 && n < 2147 ) {
	BLK = 2;
} else
if ( n >= 2147 && n < 2151 ) {
	BLK = 4;
} else
if ( n >= 2151 && n < 2155 ) {
	BLK = 0;
} else
if ( n >= 2155 && n < 2158 ) {
	BLK = 2;
} else
if ( n >= 2158 && n < 2159 ) {
	BLK = 4;
} else
if ( n >= 2159 && n < 2160 ) {
	BLK = 0;
} else
if ( n >= 2160 && n < 2161 ) {
	BLK = 2;
} else
if ( n >= 2161 && n < 2166 ) {
	BLK = 4;
} else
if ( n >= 2166 && n < 2174 ) {
	BLK = 2;
} else
if ( n >= 2174 && n < 2175 ) {
	BLK = 4;
} else
if ( n >= 2175 && n < 2176 ) {
	BLK = 3;
} else
if ( n >= 2176 && n < 2261 ) {
	BLK = 0;
} else
if ( n >= 2261 && n < 2298 ) {
	BLK = 2;
} else
if ( n >= 2298 && n < 2299 ) {
	BLK = 4;
} else
if ( n >= 2299 && n < 2300 ) {
	BLK = 3;
} else
if ( n >= 2300 && n < 2369 ) {
	BLK = 2;
} else
if ( n >= 2369 && n < 5292 ) {
	BLK = 4;
} else
if ( n >= 5292 && n < 8911 ) {
	BLK = 1;
} else
if ( n >= 8911 && n < 11543 ) {
	BLK = 5;
} else
if ( n >= 11543 && n < 13071 ) {
	BLK = 3;
} else
if ( n >= 13071 && n < 20188 ) {
	BLK = 4;
} else
if ( n >= 20188 && n < 20547 ) {
	BLK = 3;
} else
if ( n >= 20547 && n < 23090 ) {
	BLK = 4;
} else
if ( n >= 23090 && n < 23546 ) {
	BLK = 3;
} else
if ( n >= 23546 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
