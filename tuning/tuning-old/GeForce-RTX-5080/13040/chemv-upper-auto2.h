#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Sun Sep 27 12:51:17  2026
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

if ( n >= 1 && n < 226 ) {
	BLK = 0;
} else
if ( n >= 226 && n < 228 ) {
	BLK = 2;
} else
if ( n >= 228 && n < 249 ) {
	BLK = 3;
} else
if ( n >= 249 && n < 259 ) {
	BLK = 0;
} else
if ( n >= 259 && n < 260 ) {
	BLK = 2;
} else
if ( n >= 260 && n < 262 ) {
	BLK = 3;
} else
if ( n >= 262 && n < 283 ) {
	BLK = 0;
} else
if ( n >= 283 && n < 286 ) {
	BLK = 2;
} else
if ( n >= 286 && n < 560 ) {
	BLK = 0;
} else
if ( n >= 560 && n < 567 ) {
	BLK = 3;
} else
if ( n >= 567 && n < 568 ) {
	BLK = 1;
} else
if ( n >= 568 && n < 576 ) {
	BLK = 0;
} else
if ( n >= 576 && n < 612 ) {
	BLK = 3;
} else
if ( n >= 612 && n < 617 ) {
	BLK = 0;
} else
if ( n >= 617 && n < 630 ) {
	BLK = 1;
} else
if ( n >= 630 && n < 757 ) {
	BLK = 0;
} else
if ( n >= 757 && n < 783 ) {
	BLK = 3;
} else
if ( n >= 783 && n < 784 ) {
	BLK = 0;
} else
if ( n >= 784 && n < 791 ) {
	BLK = 1;
} else
if ( n >= 791 && n < 793 ) {
	BLK = 0;
} else
if ( n >= 793 && n < 795 ) {
	BLK = 3;
} else
if ( n >= 795 && n < 796 ) {
	BLK = 1;
} else
if ( n >= 796 && n < 814 ) {
	BLK = 0;
} else
if ( n >= 814 && n < 815 ) {
	BLK = 3;
} else
if ( n >= 815 && n < 816 ) {
	BLK = 1;
} else
if ( n >= 816 && n < 1006 ) {
	BLK = 0;
} else
if ( n >= 1006 && n < 1139 ) {
	BLK = 1;
} else
if ( n >= 1139 && n < 1146 ) {
	BLK = 3;
} else
if ( n >= 1146 && n < 1160 ) {
	BLK = 1;
} else
if ( n >= 1160 && n < 1161 ) {
	BLK = 5;
} else
if ( n >= 1161 && n < 1202 ) {
	BLK = 3;
} else
if ( n >= 1202 && n < 1216 ) {
	BLK = 1;
} else
if ( n >= 1216 && n < 1223 ) {
	BLK = 3;
} else
if ( n >= 1223 && n < 1225 ) {
	BLK = 5;
} else
if ( n >= 1225 && n < 1226 ) {
	BLK = 1;
} else
if ( n >= 1226 && n < 1237 ) {
	BLK = 3;
} else
if ( n >= 1237 && n < 1966 ) {
	BLK = 5;
} else
if ( n >= 1966 && n < 2754 ) {
	BLK = 4;
} else
if ( n >= 2754 && n < 2757 ) {
	BLK = 1;
} else
if ( n >= 2757 && n < 2758 ) {
	BLK = 3;
} else
if ( n >= 2758 && n < 2765 ) {
	BLK = 4;
} else
if ( n >= 2765 && n < 2766 ) {
	BLK = 3;
} else
if ( n >= 2766 && n < 2788 ) {
	BLK = 1;
} else
if ( n >= 2788 && n < 2801 ) {
	BLK = 4;
} else
if ( n >= 2801 && n < 6176 ) {
	BLK = 1;
} else
if ( n >= 6176 && n < 6333 ) {
	BLK = 5;
} else
if ( n >= 6333 && n < 10727 ) {
	BLK = 3;
} else
if ( n >= 10727 && n < 21112 ) {
	BLK = 2;
} else
if ( n >= 21112 && n < 21383 ) {
	BLK = 3;
} else
if ( n >= 21383 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
