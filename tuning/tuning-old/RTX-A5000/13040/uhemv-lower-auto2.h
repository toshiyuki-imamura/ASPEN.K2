#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Sun Sep 27 05:31:38  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 19 ) {
	BLK = 4;
} else
if ( n >= 19 && n < 20 ) {
	BLK = 1;
} else
if ( n >= 20 && n < 528 ) {
	BLK = 3;
} else
if ( n >= 528 && n < 1056 ) {
	BLK = 2;
} else
if ( n >= 1056 && n < 1540 ) {
	BLK = 3;
} else
if ( n >= 1540 && n < 1571 ) {
	BLK = 5;
} else
if ( n >= 1571 && n < 1636 ) {
	BLK = 3;
} else
if ( n >= 1636 && n < 1795 ) {
	BLK = 5;
} else
if ( n >= 1795 && n < 2007 ) {
	BLK = 2;
} else
if ( n >= 2007 && n < 2016 ) {
	BLK = 3;
} else
if ( n >= 2016 && n < 2112 ) {
	BLK = 4;
} else
if ( n >= 2112 && n < 2879 ) {
	BLK = 2;
} else
if ( n >= 2879 && n < 2901 ) {
	BLK = 4;
} else
if ( n >= 2901 && n < 2904 ) {
	BLK = 1;
} else
if ( n >= 2904 && n < 2975 ) {
	BLK = 2;
} else
if ( n >= 2975 && n < 2979 ) {
	BLK = 4;
} else
if ( n >= 2979 && n < 2982 ) {
	BLK = 1;
} else
if ( n >= 2982 && n < 2983 ) {
	BLK = 4;
} else
if ( n >= 2983 && n < 2988 ) {
	BLK = 2;
} else
if ( n >= 2988 && n < 2998 ) {
	BLK = 4;
} else
if ( n >= 2998 && n < 2999 ) {
	BLK = 2;
} else
if ( n >= 2999 && n < 3006 ) {
	BLK = 1;
} else
if ( n >= 3006 && n < 3014 ) {
	BLK = 4;
} else
if ( n >= 3014 && n < 3022 ) {
	BLK = 2;
} else
if ( n >= 3022 && n < 3023 ) {
	BLK = 1;
} else
if ( n >= 3023 && n < 3027 ) {
	BLK = 4;
} else
if ( n >= 3027 && n < 3032 ) {
	BLK = 2;
} else
if ( n >= 3032 && n < 3034 ) {
	BLK = 1;
} else
if ( n >= 3034 && n < 3044 ) {
	BLK = 4;
} else
if ( n >= 3044 && n < 3045 ) {
	BLK = 3;
} else
if ( n >= 3045 && n < 3048 ) {
	BLK = 2;
} else
if ( n >= 3048 && n < 3049 ) {
	BLK = 3;
} else
if ( n >= 3049 && n < 3050 ) {
	BLK = 1;
} else
if ( n >= 3050 && n < 3056 ) {
	BLK = 4;
} else
if ( n >= 3056 && n < 3058 ) {
	BLK = 1;
} else
if ( n >= 3058 && n < 3060 ) {
	BLK = 2;
} else
if ( n >= 3060 && n < 3061 ) {
	BLK = 3;
} else
if ( n >= 3061 && n < 3064 ) {
	BLK = 4;
} else
if ( n >= 3064 && n < 3065 ) {
	BLK = 2;
} else
if ( n >= 3065 && n < 3066 ) {
	BLK = 1;
} else
if ( n >= 3066 && n < 3068 ) {
	BLK = 4;
} else
if ( n >= 3068 && n < 3069 ) {
	BLK = 3;
} else
if ( n >= 3069 && n < 3070 ) {
	BLK = 2;
} else
if ( n >= 3070 && n < 3071 ) {
	BLK = 4;
} else
if ( n >= 3071 && n < 3081 ) {
	BLK = 1;
} else
if ( n >= 3081 && n < 3084 ) {
	BLK = 4;
} else
if ( n >= 3084 && n < 3088 ) {
	BLK = 1;
} else
if ( n >= 3088 && n < 3089 ) {
	BLK = 2;
} else
if ( n >= 3089 && n < 3090 ) {
	BLK = 4;
} else
if ( n >= 3090 && n < 3091 ) {
	BLK = 1;
} else
if ( n >= 3091 && n < 3092 ) {
	BLK = 2;
} else
if ( n >= 3092 && n < 3093 ) {
	BLK = 4;
} else
if ( n >= 3093 && n < 3094 ) {
	BLK = 1;
} else
if ( n >= 3094 && n < 3098 ) {
	BLK = 2;
} else
if ( n >= 3098 && n < 3101 ) {
	BLK = 4;
} else
if ( n >= 3101 && n < 3198 ) {
	BLK = 2;
} else
if ( n >= 3198 && n < 3351 ) {
	BLK = 1;
} else
if ( n >= 3351 && n < 3840 ) {
	BLK = 2;
} else
if ( n >= 3840 && n < 5796 ) {
	BLK = 4;
} else
if ( n >= 5796 && n < 6447 ) {
	BLK = 1;
} else
if ( n >= 6447 && n < 7109 ) {
	BLK = 4;
} else
if ( n >= 7109 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
