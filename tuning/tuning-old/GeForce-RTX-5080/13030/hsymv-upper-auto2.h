#ifndef HSYMVU_AUTO2_H_INCLUDED
#define HSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVU
 Thu Aug 06 03:07:25  2026
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

if ( n >= 1 && n < 498 ) {
	BLK = 0;
} else
if ( n >= 498 && n < 499 ) {
	BLK = 4;
} else
if ( n >= 499 && n < 526 ) {
	BLK = 5;
} else
if ( n >= 526 && n < 1022 ) {
	BLK = 0;
} else
if ( n >= 1022 && n < 1285 ) {
	BLK = 3;
} else
if ( n >= 1285 && n < 1286 ) {
	BLK = 4;
} else
if ( n >= 1286 && n < 1315 ) {
	BLK = 0;
} else
if ( n >= 1315 && n < 1324 ) {
	BLK = 3;
} else
if ( n >= 1324 && n < 1325 ) {
	BLK = 4;
} else
if ( n >= 1325 && n < 1340 ) {
	BLK = 0;
} else
if ( n >= 1340 && n < 1344 ) {
	BLK = 4;
} else
if ( n >= 1344 && n < 1503 ) {
	BLK = 0;
} else
if ( n >= 1503 && n < 1504 ) {
	BLK = 4;
} else
if ( n >= 1504 && n < 1505 ) {
	BLK = 3;
} else
if ( n >= 1505 && n < 1506 ) {
	BLK = 0;
} else
if ( n >= 1506 && n < 1507 ) {
	BLK = 2;
} else
if ( n >= 1507 && n < 1585 ) {
	BLK = 4;
} else
if ( n >= 1585 && n < 1667 ) {
	BLK = 3;
} else
if ( n >= 1667 && n < 1669 ) {
	BLK = 4;
} else
if ( n >= 1669 && n < 1672 ) {
	BLK = 0;
} else
if ( n >= 1672 && n < 1679 ) {
	BLK = 3;
} else
if ( n >= 1679 && n < 1694 ) {
	BLK = 0;
} else
if ( n >= 1694 && n < 1702 ) {
	BLK = 3;
} else
if ( n >= 1702 && n < 1703 ) {
	BLK = 0;
} else
if ( n >= 1703 && n < 1728 ) {
	BLK = 4;
} else
if ( n >= 1728 && n < 1732 ) {
	BLK = 0;
} else
if ( n >= 1732 && n < 1733 ) {
	BLK = 4;
} else
if ( n >= 1733 && n < 1739 ) {
	BLK = 3;
} else
if ( n >= 1739 && n < 1788 ) {
	BLK = 0;
} else
if ( n >= 1788 && n < 1792 ) {
	BLK = 3;
} else
if ( n >= 1792 && n < 1798 ) {
	BLK = 1;
} else
if ( n >= 1798 && n < 1815 ) {
	BLK = 3;
} else
if ( n >= 1815 && n < 1880 ) {
	BLK = 0;
} else
if ( n >= 1880 && n < 1881 ) {
	BLK = 3;
} else
if ( n >= 1881 && n < 2016 ) {
	BLK = 4;
} else
if ( n >= 2016 && n < 2046 ) {
	BLK = 0;
} else
if ( n >= 2046 && n < 2180 ) {
	BLK = 2;
} else
if ( n >= 2180 && n < 2182 ) {
	BLK = 1;
} else
if ( n >= 2182 && n < 2184 ) {
	BLK = 0;
} else
if ( n >= 2184 && n < 2187 ) {
	BLK = 2;
} else
if ( n >= 2187 && n < 2189 ) {
	BLK = 1;
} else
if ( n >= 2189 && n < 2213 ) {
	BLK = 0;
} else
if ( n >= 2213 && n < 2215 ) {
	BLK = 2;
} else
if ( n >= 2215 && n < 2220 ) {
	BLK = 1;
} else
if ( n >= 2220 && n < 2496 ) {
	BLK = 0;
} else
if ( n >= 2496 && n < 2498 ) {
	BLK = 2;
} else
if ( n >= 2498 && n < 2572 ) {
	BLK = 1;
} else
if ( n >= 2572 && n < 2596 ) {
	BLK = 2;
} else
if ( n >= 2596 && n < 2597 ) {
	BLK = 0;
} else
if ( n >= 2597 && n < 2598 ) {
	BLK = 1;
} else
if ( n >= 2598 && n < 2612 ) {
	BLK = 2;
} else
if ( n >= 2612 && n < 3460 ) {
	BLK = 0;
} else
if ( n >= 3460 && n < 3461 ) {
	BLK = 4;
} else
if ( n >= 3461 && n < 3484 ) {
	BLK = 1;
} else
if ( n >= 3484 && n < 3485 ) {
	BLK = 0;
} else
if ( n >= 3485 && n < 3624 ) {
	BLK = 4;
} else
if ( n >= 3624 && n < 3625 ) {
	BLK = 2;
} else
if ( n >= 3625 && n < 3638 ) {
	BLK = 1;
} else
if ( n >= 3638 && n < 3640 ) {
	BLK = 4;
} else
if ( n >= 3640 && n < 3641 ) {
	BLK = 2;
} else
if ( n >= 3641 && n < 3642 ) {
	BLK = 1;
} else
if ( n >= 3642 && n < 3678 ) {
	BLK = 4;
} else
if ( n >= 3678 && n < 3903 ) {
	BLK = 1;
} else
if ( n >= 3903 && n < 3904 ) {
	BLK = 2;
} else
if ( n >= 3904 && n < 3905 ) {
	BLK = 4;
} else
if ( n >= 3905 && n < 4854 ) {
	BLK = 1;
} else
if ( n >= 4854 && n < 4863 ) {
	BLK = 4;
} else
if ( n >= 4863 && n < 4976 ) {
	BLK = 2;
} else
if ( n >= 4976 && n < 4985 ) {
	BLK = 1;
} else
if ( n >= 4985 && n < 4992 ) {
	BLK = 4;
} else
if ( n >= 4992 && n < 5047 ) {
	BLK = 2;
} else
if ( n >= 5047 && n < 5062 ) {
	BLK = 4;
} else
if ( n >= 5062 && n < 5093 ) {
	BLK = 1;
} else
if ( n >= 5093 && n < 5153 ) {
	BLK = 2;
} else
if ( n >= 5153 && n < 5290 ) {
	BLK = 1;
} else
if ( n >= 5290 && n < 5336 ) {
	BLK = 2;
} else
if ( n >= 5336 && n < 5356 ) {
	BLK = 4;
} else
if ( n >= 5356 && n < 5798 ) {
	BLK = 1;
} else
if ( n >= 5798 && n < 7974 ) {
	BLK = 2;
} else
if ( n >= 7974 && n < 8006 ) {
	BLK = 4;
} else
if ( n >= 8006 && n < 8138 ) {
	BLK = 0;
} else
if ( n >= 8138 && n < 8146 ) {
	BLK = 2;
} else
if ( n >= 8146 && n < 15658 ) {
	BLK = 4;
} else
if ( n >= 15658 && n < 15877 ) {
	BLK = 1;
} else
if ( n >= 15877 && n < 15902 ) {
	BLK = 3;
} else
if ( n >= 15902 && n < 16098 ) {
	BLK = 4;
} else
if ( n >= 16098 && n < 16314 ) {
	BLK = 1;
} else
if ( n >= 16314 && n < 17757 ) {
	BLK = 2;
} else
if ( n >= 17757 && n < 18030 ) {
	BLK = 3;
} else
if ( n >= 18030 && n < 18301 ) {
	BLK = 2;
} else
if ( n >= 18301 && n < 18726 ) {
	BLK = 3;
} else
if ( n >= 18726 && n < 19143 ) {
	BLK = 2;
} else
if ( n >= 19143 && n < 19430 ) {
	BLK = 3;
} else
if ( n >= 19430 && n < 20800 ) {
	BLK = 2;
} else
if ( n >= 20800 && n < 21214 ) {
	BLK = 3;
} else
if ( n >= 21214 && n < 21763 ) {
	BLK = 2;
} else
if ( n >= 21763 && n < 22199 ) {
	BLK = 3;
} else
if ( n >= 22199 && n < 25214 ) {
	BLK = 2;
} else
if ( n >= 25214 && n < 25623 ) {
	BLK = 3;
} else
if ( n >= 25623 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
