#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Sun Jul 26 18:54:29  2026
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

if ( n >= 1 && n < 2726 ) {
	BLK = 0;
} else
if ( n >= 2726 && n < 2748 ) {
	BLK = 1;
} else
if ( n >= 2748 && n < 2749 ) {
	BLK = 3;
} else
if ( n >= 2749 && n < 2764 ) {
	BLK = 0;
} else
if ( n >= 2764 && n < 2765 ) {
	BLK = 3;
} else
if ( n >= 2765 && n < 2769 ) {
	BLK = 1;
} else
if ( n >= 2769 && n < 2770 ) {
	BLK = 3;
} else
if ( n >= 2770 && n < 2779 ) {
	BLK = 0;
} else
if ( n >= 2779 && n < 2780 ) {
	BLK = 1;
} else
if ( n >= 2780 && n < 2784 ) {
	BLK = 3;
} else
if ( n >= 2784 && n < 2785 ) {
	BLK = 1;
} else
if ( n >= 2785 && n < 2786 ) {
	BLK = 0;
} else
if ( n >= 2786 && n < 2791 ) {
	BLK = 3;
} else
if ( n >= 2791 && n < 2798 ) {
	BLK = 1;
} else
if ( n >= 2798 && n < 2799 ) {
	BLK = 0;
} else
if ( n >= 2799 && n < 2815 ) {
	BLK = 3;
} else
if ( n >= 2815 && n < 2958 ) {
	BLK = 1;
} else
if ( n >= 2958 && n < 2960 ) {
	BLK = 3;
} else
if ( n >= 2960 && n < 2961 ) {
	BLK = 0;
} else
if ( n >= 2961 && n < 2968 ) {
	BLK = 1;
} else
if ( n >= 2968 && n < 2969 ) {
	BLK = 3;
} else
if ( n >= 2969 && n < 2970 ) {
	BLK = 0;
} else
if ( n >= 2970 && n < 2972 ) {
	BLK = 1;
} else
if ( n >= 2972 && n < 2973 ) {
	BLK = 3;
} else
if ( n >= 2973 && n < 2978 ) {
	BLK = 0;
} else
if ( n >= 2978 && n < 3013 ) {
	BLK = 3;
} else
if ( n >= 3013 && n < 3014 ) {
	BLK = 0;
} else
if ( n >= 3014 && n < 3738 ) {
	BLK = 1;
} else
if ( n >= 3738 && n < 3739 ) {
	BLK = 2;
} else
if ( n >= 3739 && n < 3838 ) {
	BLK = 3;
} else
if ( n >= 3838 && n < 4104 ) {
	BLK = 1;
} else
if ( n >= 4104 && n < 4112 ) {
	BLK = 2;
} else
if ( n >= 4112 && n < 28955 ) {
	BLK = 1;
} else
if ( n >= 28955 && n < 76380 ) {
	BLK = 2;
} else
if ( n >= 76380 && n < 79671 ) {
	BLK = 1;
} else
if ( n >= 79671 && n < 94739 ) {
	BLK = 2;
} else
if ( n >= 94739 && n < 99494 ) {
	BLK = 1;
} else
if ( n >= 99494 && n < 106101 ) {
	BLK = 2;
} else
if ( n >= 106101 && n < 108506 ) {
	BLK = 1;
} else
if ( n >= 108506 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
