#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Sun Sep 27 17:15:46  2026
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

if ( n >= 1 && n < 1535 ) {
	BLK = 0;
} else
if ( n >= 1535 && n < 1536 ) {
	BLK = 3;
} else
if ( n >= 1536 && n < 1537 ) {
	BLK = 2;
} else
if ( n >= 1537 && n < 1567 ) {
	BLK = 0;
} else
if ( n >= 1567 && n < 1568 ) {
	BLK = 3;
} else
if ( n >= 1568 && n < 1569 ) {
	BLK = 2;
} else
if ( n >= 1569 && n < 1573 ) {
	BLK = 0;
} else
if ( n >= 1573 && n < 1574 ) {
	BLK = 3;
} else
if ( n >= 1574 && n < 1575 ) {
	BLK = 2;
} else
if ( n >= 1575 && n < 1582 ) {
	BLK = 0;
} else
if ( n >= 1582 && n < 1583 ) {
	BLK = 2;
} else
if ( n >= 1583 && n < 1610 ) {
	BLK = 3;
} else
if ( n >= 1610 && n < 1612 ) {
	BLK = 0;
} else
if ( n >= 1612 && n < 1614 ) {
	BLK = 2;
} else
if ( n >= 1614 && n < 1615 ) {
	BLK = 3;
} else
if ( n >= 1615 && n < 1618 ) {
	BLK = 0;
} else
if ( n >= 1618 && n < 1619 ) {
	BLK = 5;
} else
if ( n >= 1619 && n < 1624 ) {
	BLK = 3;
} else
if ( n >= 1624 && n < 1625 ) {
	BLK = 5;
} else
if ( n >= 1625 && n < 1630 ) {
	BLK = 0;
} else
if ( n >= 1630 && n < 1634 ) {
	BLK = 3;
} else
if ( n >= 1634 && n < 1983 ) {
	BLK = 0;
} else
if ( n >= 1983 && n < 2000 ) {
	BLK = 2;
} else
if ( n >= 2000 && n < 2001 ) {
	BLK = 5;
} else
if ( n >= 2001 && n < 2005 ) {
	BLK = 0;
} else
if ( n >= 2005 && n < 2008 ) {
	BLK = 2;
} else
if ( n >= 2008 && n < 2009 ) {
	BLK = 5;
} else
if ( n >= 2009 && n < 2010 ) {
	BLK = 0;
} else
if ( n >= 2010 && n < 2012 ) {
	BLK = 2;
} else
if ( n >= 2012 && n < 2013 ) {
	BLK = 5;
} else
if ( n >= 2013 && n < 2021 ) {
	BLK = 0;
} else
if ( n >= 2021 && n < 2022 ) {
	BLK = 2;
} else
if ( n >= 2022 && n < 2023 ) {
	BLK = 5;
} else
if ( n >= 2023 && n < 2030 ) {
	BLK = 0;
} else
if ( n >= 2030 && n < 2031 ) {
	BLK = 5;
} else
if ( n >= 2031 && n < 2037 ) {
	BLK = 2;
} else
if ( n >= 2037 && n < 2038 ) {
	BLK = 0;
} else
if ( n >= 2038 && n < 2041 ) {
	BLK = 5;
} else
if ( n >= 2041 && n < 2096 ) {
	BLK = 0;
} else
if ( n >= 2096 && n < 4030 ) {
	BLK = 2;
} else
if ( n >= 4030 && n < 14686 ) {
	BLK = 4;
} else
if ( n >= 14686 && n < 16425 ) {
	BLK = 1;
} else
if ( n >= 16425 && n < 17083 ) {
	BLK = 4;
} else
if ( n >= 17083 && n < 17368 ) {
	BLK = 1;
} else
if ( n >= 17368 && n < 18904 ) {
	BLK = 4;
} else
if ( n >= 18904 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
