#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Tue Sep 29 22:15:42  2026
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
MAXmem= 102123945984
// capacity of the work area reserved on the GPU
WORK= 8140288
// for double or cuFloatComplex or int64
MAXDIM= 107335
// for float or cuHalfComplex or int32
MAXDIM2= 151794
// for cuDoubleComplex or DD or int128
MAXDIM3= 75897
// for DD-Complex
MAXDIM4= 53667
// for half or int16
MAXDIM5= 214670
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1156 ) {
	BLK = 0;
} else
if ( n >= 1156 && n < 1157 ) {
	BLK = 3;
} else
if ( n >= 1157 && n < 1167 ) {
	BLK = 1;
} else
if ( n >= 1167 && n < 1168 ) {
	BLK = 3;
} else
if ( n >= 1168 && n < 1531 ) {
	BLK = 0;
} else
if ( n >= 1531 && n < 1536 ) {
	BLK = 3;
} else
if ( n >= 1536 && n < 1561 ) {
	BLK = 1;
} else
if ( n >= 1561 && n < 1639 ) {
	BLK = 0;
} else
if ( n >= 1639 && n < 1641 ) {
	BLK = 1;
} else
if ( n >= 1641 && n < 1645 ) {
	BLK = 3;
} else
if ( n >= 1645 && n < 1656 ) {
	BLK = 0;
} else
if ( n >= 1656 && n < 1664 ) {
	BLK = 1;
} else
if ( n >= 1664 && n < 1675 ) {
	BLK = 3;
} else
if ( n >= 1675 && n < 1676 ) {
	BLK = 0;
} else
if ( n >= 1676 && n < 1677 ) {
	BLK = 1;
} else
if ( n >= 1677 && n < 1679 ) {
	BLK = 3;
} else
if ( n >= 1679 && n < 2112 ) {
	BLK = 0;
} else
if ( n >= 2112 && n < 6745 ) {
	BLK = 1;
} else
if ( n >= 6745 && n < 11111 ) {
	BLK = 2;
} else
if ( n >= 11111 && n < 13121 ) {
	BLK = 4;
} else
if ( n >= 13121 && n < 19197 ) {
	BLK = 2;
} else
if ( n >= 19197 && n < 20141 ) {
	BLK = 4;
} else
if ( n >= 20141 && n < 20469 ) {
	BLK = 2;
} else
if ( n >= 20469 && n < 20801 ) {
	BLK = 4;
} else
if ( n >= 20801 && n < 23636 ) {
	BLK = 2;
} else
if ( n >= 23636 && n < 25472 ) {
	BLK = 4;
} else
if ( n >= 25472 && n < 28194 ) {
	BLK = 2;
} else
if ( n >= 28194 && n < 30720 ) {
	BLK = 4;
} else
if ( n >= 30720 && n < 31371 ) {
	BLK = 2;
} else
if ( n >= 31371 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
