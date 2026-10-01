#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Sat Sep 26 05:44:40  2026
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
	BLK = 2;
} else
if ( n >= 2 && n < 7 ) {
	BLK = 0;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 10 ) {
	BLK = 5;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 4;
} else
if ( n >= 11 && n < 12 ) {
	BLK = 2;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 5;
} else
if ( n >= 13 && n < 14 ) {
	BLK = 3;
} else
if ( n >= 14 && n < 835 ) {
	BLK = 0;
} else
if ( n >= 835 && n < 837 ) {
	BLK = 3;
} else
if ( n >= 837 && n < 839 ) {
	BLK = 5;
} else
if ( n >= 839 && n < 1225 ) {
	BLK = 0;
} else
if ( n >= 1225 && n < 1226 ) {
	BLK = 5;
} else
if ( n >= 1226 && n < 1267 ) {
	BLK = 4;
} else
if ( n >= 1267 && n < 1365 ) {
	BLK = 0;
} else
if ( n >= 1365 && n < 1366 ) {
	BLK = 5;
} else
if ( n >= 1366 && n < 1367 ) {
	BLK = 4;
} else
if ( n >= 1367 && n < 1376 ) {
	BLK = 0;
} else
if ( n >= 1376 && n < 1384 ) {
	BLK = 3;
} else
if ( n >= 1384 && n < 1385 ) {
	BLK = 0;
} else
if ( n >= 1385 && n < 1407 ) {
	BLK = 5;
} else
if ( n >= 1407 && n < 1408 ) {
	BLK = 4;
} else
if ( n >= 1408 && n < 1414 ) {
	BLK = 0;
} else
if ( n >= 1414 && n < 1425 ) {
	BLK = 5;
} else
if ( n >= 1425 && n < 1426 ) {
	BLK = 4;
} else
if ( n >= 1426 && n < 1430 ) {
	BLK = 0;
} else
if ( n >= 1430 && n < 1440 ) {
	BLK = 5;
} else
if ( n >= 1440 && n < 1441 ) {
	BLK = 3;
} else
if ( n >= 1441 && n < 1450 ) {
	BLK = 0;
} else
if ( n >= 1450 && n < 1451 ) {
	BLK = 4;
} else
if ( n >= 1451 && n < 1452 ) {
	BLK = 3;
} else
if ( n >= 1452 && n < 1456 ) {
	BLK = 0;
} else
if ( n >= 1456 && n < 1459 ) {
	BLK = 1;
} else
if ( n >= 1459 && n < 1481 ) {
	BLK = 0;
} else
if ( n >= 1481 && n < 1482 ) {
	BLK = 3;
} else
if ( n >= 1482 && n < 1483 ) {
	BLK = 4;
} else
if ( n >= 1483 && n < 1507 ) {
	BLK = 0;
} else
if ( n >= 1507 && n < 1509 ) {
	BLK = 4;
} else
if ( n >= 1509 && n < 1525 ) {
	BLK = 5;
} else
if ( n >= 1525 && n < 1526 ) {
	BLK = 3;
} else
if ( n >= 1526 && n < 1527 ) {
	BLK = 0;
} else
if ( n >= 1527 && n < 1553 ) {
	BLK = 5;
} else
if ( n >= 1553 && n < 1564 ) {
	BLK = 0;
} else
if ( n >= 1564 && n < 1573 ) {
	BLK = 5;
} else
if ( n >= 1573 && n < 1574 ) {
	BLK = 0;
} else
if ( n >= 1574 && n < 1578 ) {
	BLK = 4;
} else
if ( n >= 1578 && n < 1579 ) {
	BLK = 0;
} else
if ( n >= 1579 && n < 1586 ) {
	BLK = 5;
} else
if ( n >= 1586 && n < 1587 ) {
	BLK = 3;
} else
if ( n >= 1587 && n < 1588 ) {
	BLK = 0;
} else
if ( n >= 1588 && n < 1589 ) {
	BLK = 5;
} else
if ( n >= 1589 && n < 1590 ) {
	BLK = 4;
} else
if ( n >= 1590 && n < 1592 ) {
	BLK = 3;
} else
if ( n >= 1592 && n < 1633 ) {
	BLK = 0;
} else
if ( n >= 1633 && n < 1634 ) {
	BLK = 3;
} else
if ( n >= 1634 && n < 1637 ) {
	BLK = 4;
} else
if ( n >= 1637 && n < 1638 ) {
	BLK = 3;
} else
if ( n >= 1638 && n < 1642 ) {
	BLK = 5;
} else
if ( n >= 1642 && n < 1645 ) {
	BLK = 0;
} else
if ( n >= 1645 && n < 1652 ) {
	BLK = 4;
} else
if ( n >= 1652 && n < 1653 ) {
	BLK = 3;
} else
if ( n >= 1653 && n < 1655 ) {
	BLK = 5;
} else
if ( n >= 1655 && n < 1668 ) {
	BLK = 0;
} else
if ( n >= 1668 && n < 1671 ) {
	BLK = 5;
} else
if ( n >= 1671 && n < 1676 ) {
	BLK = 4;
} else
if ( n >= 1676 && n < 1677 ) {
	BLK = 5;
} else
if ( n >= 1677 && n < 1692 ) {
	BLK = 0;
} else
if ( n >= 1692 && n < 1971 ) {
	BLK = 4;
} else
if ( n >= 1971 && n < 1972 ) {
	BLK = 0;
} else
if ( n >= 1972 && n < 1973 ) {
	BLK = 1;
} else
if ( n >= 1973 && n < 2042 ) {
	BLK = 4;
} else
if ( n >= 2042 && n < 2043 ) {
	BLK = 1;
} else
if ( n >= 2043 && n < 2052 ) {
	BLK = 0;
} else
if ( n >= 2052 && n < 2136 ) {
	BLK = 4;
} else
if ( n >= 2136 && n < 2137 ) {
	BLK = 0;
} else
if ( n >= 2137 && n < 2153 ) {
	BLK = 1;
} else
if ( n >= 2153 && n < 2159 ) {
	BLK = 4;
} else
if ( n >= 2159 && n < 2160 ) {
	BLK = 1;
} else
if ( n >= 2160 && n < 2161 ) {
	BLK = 0;
} else
if ( n >= 2161 && n < 2181 ) {
	BLK = 4;
} else
if ( n >= 2181 && n < 2182 ) {
	BLK = 0;
} else
if ( n >= 2182 && n < 2183 ) {
	BLK = 1;
} else
if ( n >= 2183 && n < 3202 ) {
	BLK = 4;
} else
if ( n >= 3202 && n < 3214 ) {
	BLK = 1;
} else
if ( n >= 3214 && n < 3215 ) {
	BLK = 4;
} else
if ( n >= 3215 && n < 3216 ) {
	BLK = 5;
} else
if ( n >= 3216 && n < 3224 ) {
	BLK = 1;
} else
if ( n >= 3224 && n < 3240 ) {
	BLK = 4;
} else
if ( n >= 3240 && n < 3243 ) {
	BLK = 1;
} else
if ( n >= 3243 && n < 3244 ) {
	BLK = 5;
} else
if ( n >= 3244 && n < 3276 ) {
	BLK = 4;
} else
if ( n >= 3276 && n < 3283 ) {
	BLK = 5;
} else
if ( n >= 3283 && n < 3284 ) {
	BLK = 4;
} else
if ( n >= 3284 && n < 3294 ) {
	BLK = 1;
} else
if ( n >= 3294 && n < 3295 ) {
	BLK = 4;
} else
if ( n >= 3295 && n < 3299 ) {
	BLK = 5;
} else
if ( n >= 3299 && n < 3307 ) {
	BLK = 4;
} else
if ( n >= 3307 && n < 3308 ) {
	BLK = 1;
} else
if ( n >= 3308 && n < 3309 ) {
	BLK = 5;
} else
if ( n >= 3309 && n < 3869 ) {
	BLK = 4;
} else
if ( n >= 3869 && n < 20581 ) {
	BLK = 1;
} else
if ( n >= 20581 && n < 22728 ) {
	BLK = 2;
} else
if ( n >= 22728 && n < 23092 ) {
	BLK = 1;
} else
if ( n >= 23092 && n < 25158 ) {
	BLK = 2;
} else
if ( n >= 25158 && n < 26130 ) {
	BLK = 1;
} else
if ( n >= 26130 && n < 30011 ) {
	BLK = 2;
} else
if ( n >= 30011 && n < 30330 ) {
	BLK = 1;
} else
if ( n >= 30330 && n < 33325 ) {
	BLK = 2;
} else
if ( n >= 33325 && n < 34386 ) {
	BLK = 1;
} else
if ( n >= 34386 && n < 38273 ) {
	BLK = 2;
} else
if ( n >= 38273 && n < 38800 ) {
	BLK = 1;
} else
if ( n >= 38800 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
