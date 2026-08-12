#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Thu Aug 06 16:58:32  2026
 Host on qc-gh200-01.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 101997334528
// capacity of the work area reserved on the GPU
WORK= 8136960
// for double or cuFloatComplex or int64
MAXDIM= 107268
// for float or cuHalfComplex or int32
MAXDIM2= 151700
// for cuDoubleComplex or DD or int128
MAXDIM3= 75850
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214537
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 900
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

if ( n >= 1 && n < 492 ) {
	BLK = 0;
} else
if ( n >= 492 && n < 1477 ) {
	BLK = 5;
} else
if ( n >= 1477 && n < 1478 ) {
	BLK = 4;
} else
if ( n >= 1478 && n < 1480 ) {
	BLK = 0;
} else
if ( n >= 1480 && n < 1534 ) {
	BLK = 5;
} else
if ( n >= 1534 && n < 1560 ) {
	BLK = 4;
} else
if ( n >= 1560 && n < 3455 ) {
	BLK = 2;
} else
if ( n >= 3455 && n < 3711 ) {
	BLK = 3;
} else
if ( n >= 3711 && n < 3712 ) {
	BLK = 1;
} else
if ( n >= 3712 && n < 3718 ) {
	BLK = 2;
} else
if ( n >= 3718 && n < 3719 ) {
	BLK = 1;
} else
if ( n >= 3719 && n < 3724 ) {
	BLK = 3;
} else
if ( n >= 3724 && n < 3726 ) {
	BLK = 2;
} else
if ( n >= 3726 && n < 3727 ) {
	BLK = 1;
} else
if ( n >= 3727 && n < 3737 ) {
	BLK = 3;
} else
if ( n >= 3737 && n < 3743 ) {
	BLK = 2;
} else
if ( n >= 3743 && n < 3748 ) {
	BLK = 1;
} else
if ( n >= 3748 && n < 3749 ) {
	BLK = 3;
} else
if ( n >= 3749 && n < 3750 ) {
	BLK = 2;
} else
if ( n >= 3750 && n < 3751 ) {
	BLK = 1;
} else
if ( n >= 3751 && n < 3757 ) {
	BLK = 3;
} else
if ( n >= 3757 && n < 3759 ) {
	BLK = 2;
} else
if ( n >= 3759 && n < 3765 ) {
	BLK = 1;
} else
if ( n >= 3765 && n < 3788 ) {
	BLK = 3;
} else
if ( n >= 3788 && n < 3789 ) {
	BLK = 1;
} else
if ( n >= 3789 && n < 3790 ) {
	BLK = 2;
} else
if ( n >= 3790 && n < 3799 ) {
	BLK = 3;
} else
if ( n >= 3799 && n < 3800 ) {
	BLK = 1;
} else
if ( n >= 3800 && n < 3801 ) {
	BLK = 2;
} else
if ( n >= 3801 && n < 3802 ) {
	BLK = 3;
} else
if ( n >= 3802 && n < 3803 ) {
	BLK = 1;
} else
if ( n >= 3803 && n < 3816 ) {
	BLK = 2;
} else
if ( n >= 3816 && n < 3829 ) {
	BLK = 3;
} else
if ( n >= 3829 && n < 3887 ) {
	BLK = 1;
} else
if ( n >= 3887 && n < 3888 ) {
	BLK = 3;
} else
if ( n >= 3888 && n < 3904 ) {
	BLK = 2;
} else
if ( n >= 3904 && n < 3911 ) {
	BLK = 3;
} else
if ( n >= 3911 && n < 3912 ) {
	BLK = 2;
} else
if ( n >= 3912 && n < 3937 ) {
	BLK = 1;
} else
if ( n >= 3937 && n < 3939 ) {
	BLK = 2;
} else
if ( n >= 3939 && n < 3964 ) {
	BLK = 3;
} else
if ( n >= 3964 && n < 49201 ) {
	BLK = 1;
} else
if ( n >= 49201 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
