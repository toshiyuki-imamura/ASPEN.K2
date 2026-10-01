#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Fri Sep 25 23:19:33  2026
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

if ( n >= 1 && n < 261 ) {
	BLK = 0;
} else
if ( n >= 261 && n < 262 ) {
	BLK = 3;
} else
if ( n >= 262 && n < 263 ) {
	BLK = 5;
} else
if ( n >= 263 && n < 307 ) {
	BLK = 0;
} else
if ( n >= 307 && n < 309 ) {
	BLK = 3;
} else
if ( n >= 309 && n < 321 ) {
	BLK = 5;
} else
if ( n >= 321 && n < 322 ) {
	BLK = 3;
} else
if ( n >= 322 && n < 369 ) {
	BLK = 0;
} else
if ( n >= 369 && n < 370 ) {
	BLK = 3;
} else
if ( n >= 370 && n < 372 ) {
	BLK = 5;
} else
if ( n >= 372 && n < 1616 ) {
	BLK = 0;
} else
if ( n >= 1616 && n < 1617 ) {
	BLK = 2;
} else
if ( n >= 1617 && n < 1649 ) {
	BLK = 1;
} else
if ( n >= 1649 && n < 1653 ) {
	BLK = 0;
} else
if ( n >= 1653 && n < 1655 ) {
	BLK = 1;
} else
if ( n >= 1655 && n < 1658 ) {
	BLK = 2;
} else
if ( n >= 1658 && n < 1690 ) {
	BLK = 0;
} else
if ( n >= 1690 && n < 1692 ) {
	BLK = 2;
} else
if ( n >= 1692 && n < 1693 ) {
	BLK = 1;
} else
if ( n >= 1693 && n < 1696 ) {
	BLK = 0;
} else
if ( n >= 1696 && n < 1879 ) {
	BLK = 2;
} else
if ( n >= 1879 && n < 1880 ) {
	BLK = 1;
} else
if ( n >= 1880 && n < 1883 ) {
	BLK = 0;
} else
if ( n >= 1883 && n < 1939 ) {
	BLK = 2;
} else
if ( n >= 1939 && n < 1954 ) {
	BLK = 0;
} else
if ( n >= 1954 && n < 1955 ) {
	BLK = 2;
} else
if ( n >= 1955 && n < 1957 ) {
	BLK = 1;
} else
if ( n >= 1957 && n < 1964 ) {
	BLK = 0;
} else
if ( n >= 1964 && n < 1969 ) {
	BLK = 1;
} else
if ( n >= 1969 && n < 1970 ) {
	BLK = 0;
} else
if ( n >= 1970 && n < 1971 ) {
	BLK = 2;
} else
if ( n >= 1971 && n < 1985 ) {
	BLK = 1;
} else
if ( n >= 1985 && n < 2034 ) {
	BLK = 0;
} else
if ( n >= 2034 && n < 2080 ) {
	BLK = 1;
} else
if ( n >= 2080 && n < 2081 ) {
	BLK = 0;
} else
if ( n >= 2081 && n < 2082 ) {
	BLK = 2;
} else
if ( n >= 2082 && n < 2158 ) {
	BLK = 1;
} else
if ( n >= 2158 && n < 2159 ) {
	BLK = 2;
} else
if ( n >= 2159 && n < 3897 ) {
	BLK = 0;
} else
if ( n >= 3897 && n < 8979 ) {
	BLK = 1;
} else
if ( n >= 8979 && n < 10533 ) {
	BLK = 4;
} else
if ( n >= 10533 && n < 11733 ) {
	BLK = 5;
} else
if ( n >= 11733 && n < 18731 ) {
	BLK = 2;
} else
if ( n >= 18731 && n < 19616 ) {
	BLK = 3;
} else
if ( n >= 19616 && n < 20089 ) {
	BLK = 2;
} else
if ( n >= 20089 && n < 25330 ) {
	BLK = 3;
} else
if ( n >= 25330 && n < 26008 ) {
	BLK = 2;
} else
if ( n >= 26008 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
