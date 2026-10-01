#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Fri Sep 25 19:35:44  2026
 Host on fermat.r-ccs27.riken.jp
 Device is RTX-A5000
****************************************/-->
// device name
DEVICE= RTX-A5000
// the number of multi-processors
MP= 64
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 25327001600
// capacity of the work area reserved on the GPU
WORK= 3118080
// for double or cuFloatComplex or int64
MAXDIM= 53452
// for float or cuHalfComplex or int32
MAXDIM2= 75593
// for cuDoubleComplex or DD or int128
MAXDIM3= 37796
// for DD-Complex
MAXDIM4= 26726
// for half or int16
MAXDIM5= 106905
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

if ( n >= 1 && n < 1540 ) {
	BLK = 0;
} else
if ( n >= 1540 && n < 1541 ) {
	BLK = 4;
} else
if ( n >= 1541 && n < 1546 ) {
	BLK = 3;
} else
if ( n >= 1546 && n < 1548 ) {
	BLK = 0;
} else
if ( n >= 1548 && n < 1549 ) {
	BLK = 4;
} else
if ( n >= 1549 && n < 1556 ) {
	BLK = 3;
} else
if ( n >= 1556 && n < 1559 ) {
	BLK = 4;
} else
if ( n >= 1559 && n < 1600 ) {
	BLK = 0;
} else
if ( n >= 1600 && n < 1605 ) {
	BLK = 3;
} else
if ( n >= 1605 && n < 1610 ) {
	BLK = 5;
} else
if ( n >= 1610 && n < 1612 ) {
	BLK = 0;
} else
if ( n >= 1612 && n < 1618 ) {
	BLK = 3;
} else
if ( n >= 1618 && n < 1620 ) {
	BLK = 0;
} else
if ( n >= 1620 && n < 1627 ) {
	BLK = 5;
} else
if ( n >= 1627 && n < 1628 ) {
	BLK = 4;
} else
if ( n >= 1628 && n < 1639 ) {
	BLK = 3;
} else
if ( n >= 1639 && n < 1642 ) {
	BLK = 5;
} else
if ( n >= 1642 && n < 1644 ) {
	BLK = 4;
} else
if ( n >= 1644 && n < 1645 ) {
	BLK = 0;
} else
if ( n >= 1645 && n < 1659 ) {
	BLK = 3;
} else
if ( n >= 1659 && n < 1660 ) {
	BLK = 4;
} else
if ( n >= 1660 && n < 1661 ) {
	BLK = 0;
} else
if ( n >= 1661 && n < 1670 ) {
	BLK = 5;
} else
if ( n >= 1670 && n < 1728 ) {
	BLK = 3;
} else
if ( n >= 1728 && n < 1820 ) {
	BLK = 4;
} else
if ( n >= 1820 && n < 2688 ) {
	BLK = 5;
} else
if ( n >= 2688 && n < 5299 ) {
	BLK = 1;
} else
if ( n >= 5299 && n < 5308 ) {
	BLK = 3;
} else
if ( n >= 5308 && n < 5440 ) {
	BLK = 2;
} else
if ( n >= 5440 && n < 6880 ) {
	BLK = 3;
} else
if ( n >= 6880 && n < 7030 ) {
	BLK = 2;
} else
if ( n >= 7030 && n < 7049 ) {
	BLK = 3;
} else
if ( n >= 7049 && n < 7105 ) {
	BLK = 1;
} else
if ( n >= 7105 && n < 7192 ) {
	BLK = 2;
} else
if ( n >= 7192 && n < 7195 ) {
	BLK = 3;
} else
if ( n >= 7195 && n < 7621 ) {
	BLK = 1;
} else
if ( n >= 7621 && n < 7625 ) {
	BLK = 3;
} else
if ( n >= 7625 && n < 7729 ) {
	BLK = 2;
} else
if ( n >= 7729 && n < 7762 ) {
	BLK = 1;
} else
if ( n >= 7762 && n < 7934 ) {
	BLK = 3;
} else
if ( n >= 7934 && n < 8052 ) {
	BLK = 2;
} else
if ( n >= 8052 && n < 18012 ) {
	BLK = 3;
} else
if ( n >= 18012 && n < 18331 ) {
	BLK = 1;
} else
if ( n >= 18331 && n < 39341 ) {
	BLK = 3;
} else
if ( n >= 39341 && n < 39963 ) {
	BLK = 2;
} else
if ( n >= 39963 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
