#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Mon Sep 28 23:17:54  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 3 ) {
	BLK = 4;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 2;
} else
if ( n >= 4 && n < 6 ) {
	BLK = 1;
} else
if ( n >= 6 && n < 12 ) {
	BLK = 4;
} else
if ( n >= 12 && n < 13 ) {
	BLK = 3;
} else
if ( n >= 13 && n < 14 ) {
	BLK = 2;
} else
if ( n >= 14 && n < 16 ) {
	BLK = 1;
} else
if ( n >= 16 && n < 24 ) {
	BLK = 3;
} else
if ( n >= 24 && n < 1790 ) {
	BLK = 4;
} else
if ( n >= 1790 && n < 1793 ) {
	BLK = 5;
} else
if ( n >= 1793 && n < 1796 ) {
	BLK = 3;
} else
if ( n >= 1796 && n < 1932 ) {
	BLK = 5;
} else
if ( n >= 1932 && n < 2038 ) {
	BLK = 3;
} else
if ( n >= 2038 && n < 2063 ) {
	BLK = 4;
} else
if ( n >= 2063 && n < 3067 ) {
	BLK = 3;
} else
if ( n >= 3067 && n < 3186 ) {
	BLK = 1;
} else
if ( n >= 3186 && n < 3240 ) {
	BLK = 3;
} else
if ( n >= 3240 && n < 3241 ) {
	BLK = 2;
} else
if ( n >= 3241 && n < 3261 ) {
	BLK = 1;
} else
if ( n >= 3261 && n < 3403 ) {
	BLK = 3;
} else
if ( n >= 3403 && n < 3404 ) {
	BLK = 1;
} else
if ( n >= 3404 && n < 3405 ) {
	BLK = 5;
} else
if ( n >= 3405 && n < 3406 ) {
	BLK = 2;
} else
if ( n >= 3406 && n < 3431 ) {
	BLK = 3;
} else
if ( n >= 3431 && n < 3436 ) {
	BLK = 1;
} else
if ( n >= 3436 && n < 3441 ) {
	BLK = 3;
} else
if ( n >= 3441 && n < 3442 ) {
	BLK = 1;
} else
if ( n >= 3442 && n < 3443 ) {
	BLK = 2;
} else
if ( n >= 3443 && n < 3451 ) {
	BLK = 3;
} else
if ( n >= 3451 && n < 3453 ) {
	BLK = 1;
} else
if ( n >= 3453 && n < 3455 ) {
	BLK = 2;
} else
if ( n >= 3455 && n < 3460 ) {
	BLK = 3;
} else
if ( n >= 3460 && n < 3463 ) {
	BLK = 1;
} else
if ( n >= 3463 && n < 3464 ) {
	BLK = 3;
} else
if ( n >= 3464 && n < 3469 ) {
	BLK = 2;
} else
if ( n >= 3469 && n < 3470 ) {
	BLK = 1;
} else
if ( n >= 3470 && n < 3484 ) {
	BLK = 3;
} else
if ( n >= 3484 && n < 3485 ) {
	BLK = 5;
} else
if ( n >= 3485 && n < 3490 ) {
	BLK = 1;
} else
if ( n >= 3490 && n < 3501 ) {
	BLK = 3;
} else
if ( n >= 3501 && n < 3504 ) {
	BLK = 1;
} else
if ( n >= 3504 && n < 3508 ) {
	BLK = 2;
} else
if ( n >= 3508 && n < 3511 ) {
	BLK = 3;
} else
if ( n >= 3511 && n < 3512 ) {
	BLK = 5;
} else
if ( n >= 3512 && n < 3521 ) {
	BLK = 2;
} else
if ( n >= 3521 && n < 3526 ) {
	BLK = 1;
} else
if ( n >= 3526 && n < 3543 ) {
	BLK = 3;
} else
if ( n >= 3543 && n < 3544 ) {
	BLK = 1;
} else
if ( n >= 3544 && n < 3553 ) {
	BLK = 2;
} else
if ( n >= 3553 && n < 3563 ) {
	BLK = 3;
} else
if ( n >= 3563 && n < 3565 ) {
	BLK = 2;
} else
if ( n >= 3565 && n < 3572 ) {
	BLK = 1;
} else
if ( n >= 3572 && n < 3573 ) {
	BLK = 2;
} else
if ( n >= 3573 && n < 3581 ) {
	BLK = 3;
} else
if ( n >= 3581 && n < 3589 ) {
	BLK = 2;
} else
if ( n >= 3589 && n < 3600 ) {
	BLK = 1;
} else
if ( n >= 3600 && n < 3627 ) {
	BLK = 3;
} else
if ( n >= 3627 && n < 3639 ) {
	BLK = 1;
} else
if ( n >= 3639 && n < 3657 ) {
	BLK = 3;
} else
if ( n >= 3657 && n < 3660 ) {
	BLK = 2;
} else
if ( n >= 3660 && n < 3661 ) {
	BLK = 1;
} else
if ( n >= 3661 && n < 3679 ) {
	BLK = 3;
} else
if ( n >= 3679 && n < 3683 ) {
	BLK = 2;
} else
if ( n >= 3683 && n < 3692 ) {
	BLK = 1;
} else
if ( n >= 3692 && n < 3697 ) {
	BLK = 3;
} else
if ( n >= 3697 && n < 3698 ) {
	BLK = 2;
} else
if ( n >= 3698 && n < 3699 ) {
	BLK = 1;
} else
if ( n >= 3699 && n < 3700 ) {
	BLK = 3;
} else
if ( n >= 3700 && n < 3703 ) {
	BLK = 2;
} else
if ( n >= 3703 && n < 3705 ) {
	BLK = 3;
} else
if ( n >= 3705 && n < 3706 ) {
	BLK = 1;
} else
if ( n >= 3706 && n < 3726 ) {
	BLK = 2;
} else
if ( n >= 3726 && n < 3727 ) {
	BLK = 3;
} else
if ( n >= 3727 && n < 3728 ) {
	BLK = 1;
} else
if ( n >= 3728 && n < 3732 ) {
	BLK = 2;
} else
if ( n >= 3732 && n < 3739 ) {
	BLK = 3;
} else
if ( n >= 3739 && n < 3743 ) {
	BLK = 1;
} else
if ( n >= 3743 && n < 3752 ) {
	BLK = 3;
} else
if ( n >= 3752 && n < 3754 ) {
	BLK = 1;
} else
if ( n >= 3754 && n < 3828 ) {
	BLK = 2;
} else
if ( n >= 3828 && n < 3829 ) {
	BLK = 1;
} else
if ( n >= 3829 && n < 3834 ) {
	BLK = 3;
} else
if ( n >= 3834 && n < 3888 ) {
	BLK = 1;
} else
if ( n >= 3888 && n < 3889 ) {
	BLK = 2;
} else
if ( n >= 3889 && n < 3890 ) {
	BLK = 3;
} else
if ( n >= 3890 && n < 3900 ) {
	BLK = 1;
} else
if ( n >= 3900 && n < 3903 ) {
	BLK = 3;
} else
if ( n >= 3903 && n < 3914 ) {
	BLK = 2;
} else
if ( n >= 3914 && n < 3915 ) {
	BLK = 3;
} else
if ( n >= 3915 && n < 3955 ) {
	BLK = 1;
} else
if ( n >= 3955 && n < 3958 ) {
	BLK = 3;
} else
if ( n >= 3958 && n < 3962 ) {
	BLK = 2;
} else
if ( n >= 3962 && n < 3964 ) {
	BLK = 1;
} else
if ( n >= 3964 && n < 3974 ) {
	BLK = 3;
} else
if ( n >= 3974 && n < 3995 ) {
	BLK = 2;
} else
if ( n >= 3995 && n < 3996 ) {
	BLK = 1;
} else
if ( n >= 3996 && n < 3997 ) {
	BLK = 3;
} else
if ( n >= 3997 && n < 3998 ) {
	BLK = 2;
} else
if ( n >= 3998 && n < 4016 ) {
	BLK = 1;
} else
if ( n >= 4016 && n < 4029 ) {
	BLK = 2;
} else
if ( n >= 4029 && n < 4031 ) {
	BLK = 3;
} else
if ( n >= 4031 && n < 4059 ) {
	BLK = 1;
} else
if ( n >= 4059 && n < 4060 ) {
	BLK = 3;
} else
if ( n >= 4060 && n < 4111 ) {
	BLK = 2;
} else
if ( n >= 4111 && n < 4113 ) {
	BLK = 1;
} else
if ( n >= 4113 && n < 4116 ) {
	BLK = 3;
} else
if ( n >= 4116 && n < 5994 ) {
	BLK = 2;
} else
if ( n >= 5994 && n < 6598 ) {
	BLK = 1;
} else
if ( n >= 6598 && n < 7833 ) {
	BLK = 2;
} else
if ( n >= 7833 && n < 8564 ) {
	BLK = 1;
} else
if ( n >= 8564 && n < 18028 ) {
	BLK = 2;
} else
if ( n >= 18028 && n < 18315 ) {
	BLK = 1;
} else
if ( n >= 18315 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
