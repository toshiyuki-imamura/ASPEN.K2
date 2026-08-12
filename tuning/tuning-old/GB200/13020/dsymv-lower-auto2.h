#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Fri Jun 19 11:28:06  2026
 Host on ar13n17-m.ai.r-ccs.riken.jp
 Device is GB200
****************************************/-->
// device name
DEVICE= GB200
// the number of multi-processors
MP= 152
// compute-compatibility generation
CG= 1000
// capacity of the global memory or host memory
MAXmem= 197555425280
// capacity of the work area reserved on the GPU
WORK= 13067520
// for double or cuFloatComplex or int64
MAXDIM= 149287
// for float or cuHalfComplex or int32
MAXDIM2= 211124
// for cuDoubleComplex or DD or int128
MAXDIM3= 105562
// for DD-Complex
MAXDIM4= 74643
// for half or int16
MAXDIM5= 298574
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1000
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 69 ) {
	BLK = 0;
} else
if ( n >= 69 && n < 75 ) {
	BLK = 1;
} else
if ( n >= 75 && n < 201 ) {
	BLK = 0;
} else
if ( n >= 201 && n < 202 ) {
	BLK = 1;
} else
if ( n >= 202 && n < 207 ) {
	BLK = 2;
} else
if ( n >= 207 && n < 286 ) {
	BLK = 0;
} else
if ( n >= 286 && n < 289 ) {
	BLK = 1;
} else
if ( n >= 289 && n < 356 ) {
	BLK = 0;
} else
if ( n >= 356 && n < 357 ) {
	BLK = 1;
} else
if ( n >= 357 && n < 358 ) {
	BLK = 2;
} else
if ( n >= 358 && n < 471 ) {
	BLK = 0;
} else
if ( n >= 471 && n < 472 ) {
	BLK = 1;
} else
if ( n >= 472 && n < 476 ) {
	BLK = 2;
} else
if ( n >= 476 && n < 500 ) {
	BLK = 0;
} else
if ( n >= 500 && n < 502 ) {
	BLK = 1;
} else
if ( n >= 502 && n < 503 ) {
	BLK = 2;
} else
if ( n >= 503 && n < 506 ) {
	BLK = 0;
} else
if ( n >= 506 && n < 508 ) {
	BLK = 1;
} else
if ( n >= 508 && n < 509 ) {
	BLK = 2;
} else
if ( n >= 509 && n < 613 ) {
	BLK = 0;
} else
if ( n >= 613 && n < 614 ) {
	BLK = 2;
} else
if ( n >= 614 && n < 615 ) {
	BLK = 1;
} else
if ( n >= 615 && n < 628 ) {
	BLK = 0;
} else
if ( n >= 628 && n < 682 ) {
	BLK = 1;
} else
if ( n >= 682 && n < 685 ) {
	BLK = 0;
} else
if ( n >= 685 && n < 686 ) {
	BLK = 2;
} else
if ( n >= 686 && n < 696 ) {
	BLK = 1;
} else
if ( n >= 696 && n < 763 ) {
	BLK = 0;
} else
if ( n >= 763 && n < 764 ) {
	BLK = 1;
} else
if ( n >= 764 && n < 765 ) {
	BLK = 2;
} else
if ( n >= 765 && n < 792 ) {
	BLK = 0;
} else
if ( n >= 792 && n < 793 ) {
	BLK = 2;
} else
if ( n >= 793 && n < 799 ) {
	BLK = 1;
} else
if ( n >= 799 && n < 848 ) {
	BLK = 0;
} else
if ( n >= 848 && n < 849 ) {
	BLK = 2;
} else
if ( n >= 849 && n < 898 ) {
	BLK = 1;
} else
if ( n >= 898 && n < 1095 ) {
	BLK = 0;
} else
if ( n >= 1095 && n < 1096 ) {
	BLK = 2;
} else
if ( n >= 1096 && n < 1100 ) {
	BLK = 1;
} else
if ( n >= 1100 && n < 1139 ) {
	BLK = 0;
} else
if ( n >= 1139 && n < 1140 ) {
	BLK = 1;
} else
if ( n >= 1140 && n < 1149 ) {
	BLK = 2;
} else
if ( n >= 1149 && n < 1164 ) {
	BLK = 0;
} else
if ( n >= 1164 && n < 1165 ) {
	BLK = 1;
} else
if ( n >= 1165 && n < 1166 ) {
	BLK = 2;
} else
if ( n >= 1166 && n < 1347 ) {
	BLK = 0;
} else
if ( n >= 1347 && n < 1348 ) {
	BLK = 1;
} else
if ( n >= 1348 && n < 1349 ) {
	BLK = 2;
} else
if ( n >= 1349 && n < 1521 ) {
	BLK = 0;
} else
if ( n >= 1521 && n < 1522 ) {
	BLK = 1;
} else
if ( n >= 1522 && n < 1526 ) {
	BLK = 2;
} else
if ( n >= 1526 && n < 1738 ) {
	BLK = 0;
} else
if ( n >= 1738 && n < 1739 ) {
	BLK = 1;
} else
if ( n >= 1739 && n < 1740 ) {
	BLK = 2;
} else
if ( n >= 1740 && n < 1786 ) {
	BLK = 0;
} else
if ( n >= 1786 && n < 1790 ) {
	BLK = 1;
} else
if ( n >= 1790 && n < 1791 ) {
	BLK = 2;
} else
if ( n >= 1791 && n < 1802 ) {
	BLK = 0;
} else
if ( n >= 1802 && n < 1803 ) {
	BLK = 1;
} else
if ( n >= 1803 && n < 1804 ) {
	BLK = 2;
} else
if ( n >= 1804 && n < 1807 ) {
	BLK = 0;
} else
if ( n >= 1807 && n < 1810 ) {
	BLK = 1;
} else
if ( n >= 1810 && n < 1821 ) {
	BLK = 0;
} else
if ( n >= 1821 && n < 1822 ) {
	BLK = 2;
} else
if ( n >= 1822 && n < 1823 ) {
	BLK = 1;
} else
if ( n >= 1823 && n < 2003 ) {
	BLK = 0;
} else
if ( n >= 2003 && n < 2045 ) {
	BLK = 1;
} else
if ( n >= 2045 && n < 2048 ) {
	BLK = 2;
} else
if ( n >= 2048 && n < 2142 ) {
	BLK = 0;
} else
if ( n >= 2142 && n < 2145 ) {
	BLK = 1;
} else
if ( n >= 2145 && n < 2146 ) {
	BLK = 2;
} else
if ( n >= 2146 && n < 4720 ) {
	BLK = 0;
} else
if ( n >= 4720 && n < 10210 ) {
	BLK = 1;
} else
if ( n >= 10210 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
