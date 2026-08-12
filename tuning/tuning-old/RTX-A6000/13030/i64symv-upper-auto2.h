#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Thu Jul 23 17:45:49  2026
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
MAXmem= 50892406784
// capacity of the work area reserved on the GPU
WORK= 4421120
// for double or cuFloatComplex or int64
MAXDIM= 75771
// for float or cuHalfComplex or int32
MAXDIM2= 107156
// for cuDoubleComplex or DD or int128
MAXDIM3= 53578
// for DD-Complex
MAXDIM4= 37885
// for half or int16
MAXDIM5= 151542
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1454 ) {
	BLK = 0;
} else
if ( n >= 1454 && n < 1573 ) {
	BLK = 1;
} else
if ( n >= 1573 && n < 1579 ) {
	BLK = 3;
} else
if ( n >= 1579 && n < 1580 ) {
	BLK = 2;
} else
if ( n >= 1580 && n < 1824 ) {
	BLK = 1;
} else
if ( n >= 1824 && n < 1825 ) {
	BLK = 2;
} else
if ( n >= 1825 && n < 1826 ) {
	BLK = 3;
} else
if ( n >= 1826 && n < 2122 ) {
	BLK = 1;
} else
if ( n >= 2122 && n < 2123 ) {
	BLK = 2;
} else
if ( n >= 2123 && n < 2136 ) {
	BLK = 3;
} else
if ( n >= 2136 && n < 2158 ) {
	BLK = 1;
} else
if ( n >= 2158 && n < 2159 ) {
	BLK = 2;
} else
if ( n >= 2159 && n < 2223 ) {
	BLK = 3;
} else
if ( n >= 2223 && n < 2454 ) {
	BLK = 1;
} else
if ( n >= 2454 && n < 2456 ) {
	BLK = 3;
} else
if ( n >= 2456 && n < 2466 ) {
	BLK = 2;
} else
if ( n >= 2466 && n < 2597 ) {
	BLK = 1;
} else
if ( n >= 2597 && n < 2598 ) {
	BLK = 2;
} else
if ( n >= 2598 && n < 2599 ) {
	BLK = 3;
} else
if ( n >= 2599 && n < 2786 ) {
	BLK = 1;
} else
if ( n >= 2786 && n < 2787 ) {
	BLK = 2;
} else
if ( n >= 2787 && n < 2791 ) {
	BLK = 3;
} else
if ( n >= 2791 && n < 2798 ) {
	BLK = 1;
} else
if ( n >= 2798 && n < 2799 ) {
	BLK = 2;
} else
if ( n >= 2799 && n < 2844 ) {
	BLK = 3;
} else
if ( n >= 2844 && n < 3017 ) {
	BLK = 1;
} else
if ( n >= 3017 && n < 3018 ) {
	BLK = 2;
} else
if ( n >= 3018 && n < 3107 ) {
	BLK = 3;
} else
if ( n >= 3107 && n < 3250 ) {
	BLK = 1;
} else
if ( n >= 3250 && n < 3251 ) {
	BLK = 2;
} else
if ( n >= 3251 && n < 3272 ) {
	BLK = 3;
} else
if ( n >= 3272 && n < 3327 ) {
	BLK = 1;
} else
if ( n >= 3327 && n < 3328 ) {
	BLK = 2;
} else
if ( n >= 3328 && n < 3384 ) {
	BLK = 3;
} else
if ( n >= 3384 && n < 3556 ) {
	BLK = 1;
} else
if ( n >= 3556 && n < 3557 ) {
	BLK = 3;
} else
if ( n >= 3557 && n < 3558 ) {
	BLK = 2;
} else
if ( n >= 3558 && n < 4150 ) {
	BLK = 1;
} else
if ( n >= 4150 && n < 4153 ) {
	BLK = 3;
} else
if ( n >= 4153 && n < 4155 ) {
	BLK = 2;
} else
if ( n >= 4155 && n < 5091 ) {
	BLK = 1;
} else
if ( n >= 5091 && n < 12854 ) {
	BLK = 3;
} else
if ( n >= 12854 && n < 13453 ) {
	BLK = 2;
} else
if ( n >= 13453 && n < 13885 ) {
	BLK = 3;
} else
if ( n >= 13885 && n < 14600 ) {
	BLK = 2;
} else
if ( n >= 14600 && n < 15022 ) {
	BLK = 3;
} else
if ( n >= 15022 && n < 15885 ) {
	BLK = 2;
} else
if ( n >= 15885 && n < 16323 ) {
	BLK = 3;
} else
if ( n >= 16323 && n < 17493 ) {
	BLK = 2;
} else
if ( n >= 17493 && n < 17792 ) {
	BLK = 3;
} else
if ( n >= 17792 && n < 19221 ) {
	BLK = 2;
} else
if ( n >= 19221 && n < 19338 ) {
	BLK = 3;
} else
if ( n >= 19338 && n < 19851 ) {
	BLK = 1;
} else
if ( n >= 19851 && n < 19968 ) {
	BLK = 3;
} else
if ( n >= 19968 && n < 21470 ) {
	BLK = 2;
} else
if ( n >= 21470 && n < 22296 ) {
	BLK = 3;
} else
if ( n >= 22296 && n < 24021 ) {
	BLK = 2;
} else
if ( n >= 24021 && n < 25416 ) {
	BLK = 3;
} else
if ( n >= 25416 && n < 28060 ) {
	BLK = 2;
} else
if ( n >= 28060 && n < 28611 ) {
	BLK = 3;
} else
if ( n >= 28611 && n < 33023 ) {
	BLK = 2;
} else
if ( n >= 33023 && n < 34477 ) {
	BLK = 3;
} else
if ( n >= 34477 && n < 41208 ) {
	BLK = 2;
} else
if ( n >= 41208 && n < 41620 ) {
	BLK = 3;
} else
if ( n >= 41620 && n < 52783 ) {
	BLK = 2;
} else
if ( n >= 52783 && n < 53166 ) {
	BLK = 3;
} else
if ( n >= 53166 && n < 56538 ) {
	BLK = 1;
} else
if ( n >= 56538 && n < 57743 ) {
	BLK = 3;
} else
if ( n >= 57743 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
