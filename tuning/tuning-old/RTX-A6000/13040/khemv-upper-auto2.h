#ifndef KHEMVU_AUTO2_H_INCLUDED
#define KHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVU
 Tue Sep 29 09:12:33  2026
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

if ( n >= 1 && n < 1536 ) {
	BLK = 0;
} else
if ( n >= 1536 && n < 1551 ) {
	BLK = 2;
} else
if ( n >= 1551 && n < 1580 ) {
	BLK = 0;
} else
if ( n >= 1580 && n < 1581 ) {
	BLK = 4;
} else
if ( n >= 1581 && n < 1621 ) {
	BLK = 2;
} else
if ( n >= 1621 && n < 1630 ) {
	BLK = 0;
} else
if ( n >= 1630 && n < 1641 ) {
	BLK = 2;
} else
if ( n >= 1641 && n < 1643 ) {
	BLK = 0;
} else
if ( n >= 1643 && n < 1644 ) {
	BLK = 4;
} else
if ( n >= 1644 && n < 1653 ) {
	BLK = 2;
} else
if ( n >= 1653 && n < 1655 ) {
	BLK = 0;
} else
if ( n >= 1655 && n < 1658 ) {
	BLK = 3;
} else
if ( n >= 1658 && n < 1785 ) {
	BLK = 2;
} else
if ( n >= 1785 && n < 1984 ) {
	BLK = 0;
} else
if ( n >= 1984 && n < 1993 ) {
	BLK = 3;
} else
if ( n >= 1993 && n < 1996 ) {
	BLK = 4;
} else
if ( n >= 1996 && n < 2163 ) {
	BLK = 3;
} else
if ( n >= 2163 && n < 3528 ) {
	BLK = 4;
} else
if ( n >= 3528 && n < 4698 ) {
	BLK = 5;
} else
if ( n >= 4698 && n < 20300 ) {
	BLK = 3;
} else
if ( n >= 20300 && n < 20749 ) {
	BLK = 1;
} else
if ( n >= 20749 && n < 21079 ) {
	BLK = 3;
} else
if ( n >= 21079 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
