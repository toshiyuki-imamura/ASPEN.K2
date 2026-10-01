#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Thu Sep 24 05:10:37  2026
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16800759808
// capacity of the work area reserved on the GPU
WORK= 2539520
// for double or cuFloatComplex or int64
MAXDIM= 43535
// for float or cuHalfComplex or int32
MAXDIM2= 61568
// for cuDoubleComplex or DD or int128
MAXDIM3= 30784
// for DD-Complex
MAXDIM4= 21767
// for half or int16
MAXDIM5= 87070
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1636 ) {
	BLK = 0;
} else
if ( n >= 1636 && n < 2370 ) {
	BLK = 1;
} else
if ( n >= 2370 && n < 2371 ) {
	BLK = 4;
} else
if ( n >= 2371 && n < 2385 ) {
	BLK = 3;
} else
if ( n >= 2385 && n < 2386 ) {
	BLK = 0;
} else
if ( n >= 2386 && n < 2464 ) {
	BLK = 1;
} else
if ( n >= 2464 && n < 2465 ) {
	BLK = 4;
} else
if ( n >= 2465 && n < 2466 ) {
	BLK = 2;
} else
if ( n >= 2466 && n < 2608 ) {
	BLK = 1;
} else
if ( n >= 2608 && n < 2609 ) {
	BLK = 3;
} else
if ( n >= 2609 && n < 2610 ) {
	BLK = 0;
} else
if ( n >= 2610 && n < 2614 ) {
	BLK = 1;
} else
if ( n >= 2614 && n < 2615 ) {
	BLK = 0;
} else
if ( n >= 2615 && n < 2619 ) {
	BLK = 3;
} else
if ( n >= 2619 && n < 2717 ) {
	BLK = 1;
} else
if ( n >= 2717 && n < 2738 ) {
	BLK = 0;
} else
if ( n >= 2738 && n < 2748 ) {
	BLK = 1;
} else
if ( n >= 2748 && n < 2749 ) {
	BLK = 3;
} else
if ( n >= 2749 && n < 2750 ) {
	BLK = 0;
} else
if ( n >= 2750 && n < 2818 ) {
	BLK = 1;
} else
if ( n >= 2818 && n < 2819 ) {
	BLK = 0;
} else
if ( n >= 2819 && n < 2820 ) {
	BLK = 2;
} else
if ( n >= 2820 && n < 2822 ) {
	BLK = 3;
} else
if ( n >= 2822 && n < 2823 ) {
	BLK = 0;
} else
if ( n >= 2823 && n < 2824 ) {
	BLK = 1;
} else
if ( n >= 2824 && n < 2830 ) {
	BLK = 3;
} else
if ( n >= 2830 && n < 2831 ) {
	BLK = 2;
} else
if ( n >= 2831 && n < 2832 ) {
	BLK = 1;
} else
if ( n >= 2832 && n < 2833 ) {
	BLK = 3;
} else
if ( n >= 2833 && n < 2834 ) {
	BLK = 0;
} else
if ( n >= 2834 && n < 2835 ) {
	BLK = 2;
} else
if ( n >= 2835 && n < 2837 ) {
	BLK = 1;
} else
if ( n >= 2837 && n < 2845 ) {
	BLK = 3;
} else
if ( n >= 2845 && n < 2847 ) {
	BLK = 1;
} else
if ( n >= 2847 && n < 2848 ) {
	BLK = 0;
} else
if ( n >= 2848 && n < 2849 ) {
	BLK = 3;
} else
if ( n >= 2849 && n < 2853 ) {
	BLK = 1;
} else
if ( n >= 2853 && n < 2855 ) {
	BLK = 0;
} else
if ( n >= 2855 && n < 2856 ) {
	BLK = 3;
} else
if ( n >= 2856 && n < 2859 ) {
	BLK = 1;
} else
if ( n >= 2859 && n < 2864 ) {
	BLK = 3;
} else
if ( n >= 2864 && n < 2866 ) {
	BLK = 1;
} else
if ( n >= 2866 && n < 2869 ) {
	BLK = 0;
} else
if ( n >= 2869 && n < 2920 ) {
	BLK = 1;
} else
if ( n >= 2920 && n < 2948 ) {
	BLK = 0;
} else
if ( n >= 2948 && n < 2949 ) {
	BLK = 1;
} else
if ( n >= 2949 && n < 2950 ) {
	BLK = 3;
} else
if ( n >= 2950 && n < 2958 ) {
	BLK = 0;
} else
if ( n >= 2958 && n < 2959 ) {
	BLK = 3;
} else
if ( n >= 2959 && n < 2965 ) {
	BLK = 1;
} else
if ( n >= 2965 && n < 2966 ) {
	BLK = 0;
} else
if ( n >= 2966 && n < 2967 ) {
	BLK = 3;
} else
if ( n >= 2967 && n < 2968 ) {
	BLK = 1;
} else
if ( n >= 2968 && n < 2971 ) {
	BLK = 0;
} else
if ( n >= 2971 && n < 2987 ) {
	BLK = 1;
} else
if ( n >= 2987 && n < 2988 ) {
	BLK = 0;
} else
if ( n >= 2988 && n < 2991 ) {
	BLK = 3;
} else
if ( n >= 2991 && n < 3057 ) {
	BLK = 0;
} else
if ( n >= 3057 && n < 3078 ) {
	BLK = 1;
} else
if ( n >= 3078 && n < 3120 ) {
	BLK = 3;
} else
if ( n >= 3120 && n < 3122 ) {
	BLK = 0;
} else
if ( n >= 3122 && n < 3126 ) {
	BLK = 1;
} else
if ( n >= 3126 && n < 3127 ) {
	BLK = 3;
} else
if ( n >= 3127 && n < 3128 ) {
	BLK = 0;
} else
if ( n >= 3128 && n < 3129 ) {
	BLK = 1;
} else
if ( n >= 3129 && n < 3130 ) {
	BLK = 3;
} else
if ( n >= 3130 && n < 3134 ) {
	BLK = 0;
} else
if ( n >= 3134 && n < 3137 ) {
	BLK = 3;
} else
if ( n >= 3137 && n < 3143 ) {
	BLK = 0;
} else
if ( n >= 3143 && n < 3144 ) {
	BLK = 1;
} else
if ( n >= 3144 && n < 3145 ) {
	BLK = 3;
} else
if ( n >= 3145 && n < 3151 ) {
	BLK = 0;
} else
if ( n >= 3151 && n < 3152 ) {
	BLK = 1;
} else
if ( n >= 3152 && n < 3153 ) {
	BLK = 3;
} else
if ( n >= 3153 && n < 3186 ) {
	BLK = 0;
} else
if ( n >= 3186 && n < 3187 ) {
	BLK = 1;
} else
if ( n >= 3187 && n < 3188 ) {
	BLK = 3;
} else
if ( n >= 3188 && n < 3195 ) {
	BLK = 0;
} else
if ( n >= 3195 && n < 3196 ) {
	BLK = 1;
} else
if ( n >= 3196 && n < 3202 ) {
	BLK = 3;
} else
if ( n >= 3202 && n < 3234 ) {
	BLK = 0;
} else
if ( n >= 3234 && n < 3235 ) {
	BLK = 1;
} else
if ( n >= 3235 && n < 3253 ) {
	BLK = 3;
} else
if ( n >= 3253 && n < 3254 ) {
	BLK = 0;
} else
if ( n >= 3254 && n < 3256 ) {
	BLK = 1;
} else
if ( n >= 3256 && n < 3257 ) {
	BLK = 3;
} else
if ( n >= 3257 && n < 3263 ) {
	BLK = 0;
} else
if ( n >= 3263 && n < 3264 ) {
	BLK = 2;
} else
if ( n >= 3264 && n < 3265 ) {
	BLK = 3;
} else
if ( n >= 3265 && n < 3313 ) {
	BLK = 0;
} else
if ( n >= 3313 && n < 3328 ) {
	BLK = 1;
} else
if ( n >= 3328 && n < 3347 ) {
	BLK = 0;
} else
if ( n >= 3347 && n < 3373 ) {
	BLK = 3;
} else
if ( n >= 3373 && n < 3374 ) {
	BLK = 2;
} else
if ( n >= 3374 && n < 3391 ) {
	BLK = 1;
} else
if ( n >= 3391 && n < 3400 ) {
	BLK = 3;
} else
if ( n >= 3400 && n < 3402 ) {
	BLK = 0;
} else
if ( n >= 3402 && n < 3403 ) {
	BLK = 1;
} else
if ( n >= 3403 && n < 3436 ) {
	BLK = 3;
} else
if ( n >= 3436 && n < 3439 ) {
	BLK = 0;
} else
if ( n >= 3439 && n < 3445 ) {
	BLK = 1;
} else
if ( n >= 3445 && n < 3449 ) {
	BLK = 3;
} else
if ( n >= 3449 && n < 3450 ) {
	BLK = 1;
} else
if ( n >= 3450 && n < 3459 ) {
	BLK = 0;
} else
if ( n >= 3459 && n < 3531 ) {
	BLK = 3;
} else
if ( n >= 3531 && n < 3552 ) {
	BLK = 0;
} else
if ( n >= 3552 && n < 3558 ) {
	BLK = 1;
} else
if ( n >= 3558 && n < 3559 ) {
	BLK = 3;
} else
if ( n >= 3559 && n < 3560 ) {
	BLK = 0;
} else
if ( n >= 3560 && n < 3561 ) {
	BLK = 1;
} else
if ( n >= 3561 && n < 3564 ) {
	BLK = 3;
} else
if ( n >= 3564 && n < 3584 ) {
	BLK = 1;
} else
if ( n >= 3584 && n < 3606 ) {
	BLK = 3;
} else
if ( n >= 3606 && n < 3607 ) {
	BLK = 2;
} else
if ( n >= 3607 && n < 3608 ) {
	BLK = 1;
} else
if ( n >= 3608 && n < 3609 ) {
	BLK = 0;
} else
if ( n >= 3609 && n < 3610 ) {
	BLK = 3;
} else
if ( n >= 3610 && n < 3613 ) {
	BLK = 2;
} else
if ( n >= 3613 && n < 3614 ) {
	BLK = 0;
} else
if ( n >= 3614 && n < 3623 ) {
	BLK = 3;
} else
if ( n >= 3623 && n < 3643 ) {
	BLK = 2;
} else
if ( n >= 3643 && n < 3645 ) {
	BLK = 3;
} else
if ( n >= 3645 && n < 3646 ) {
	BLK = 1;
} else
if ( n >= 3646 && n < 3650 ) {
	BLK = 2;
} else
if ( n >= 3650 && n < 3651 ) {
	BLK = 3;
} else
if ( n >= 3651 && n < 3653 ) {
	BLK = 1;
} else
if ( n >= 3653 && n < 3654 ) {
	BLK = 0;
} else
if ( n >= 3654 && n < 3673 ) {
	BLK = 3;
} else
if ( n >= 3673 && n < 3674 ) {
	BLK = 1;
} else
if ( n >= 3674 && n < 3675 ) {
	BLK = 2;
} else
if ( n >= 3675 && n < 3682 ) {
	BLK = 3;
} else
if ( n >= 3682 && n < 3683 ) {
	BLK = 0;
} else
if ( n >= 3683 && n < 3684 ) {
	BLK = 1;
} else
if ( n >= 3684 && n < 3719 ) {
	BLK = 3;
} else
if ( n >= 3719 && n < 3720 ) {
	BLK = 1;
} else
if ( n >= 3720 && n < 3731 ) {
	BLK = 2;
} else
if ( n >= 3731 && n < 3732 ) {
	BLK = 0;
} else
if ( n >= 3732 && n < 3754 ) {
	BLK = 3;
} else
if ( n >= 3754 && n < 3756 ) {
	BLK = 2;
} else
if ( n >= 3756 && n < 3757 ) {
	BLK = 0;
} else
if ( n >= 3757 && n < 3807 ) {
	BLK = 3;
} else
if ( n >= 3807 && n < 3810 ) {
	BLK = 2;
} else
if ( n >= 3810 && n < 3815 ) {
	BLK = 0;
} else
if ( n >= 3815 && n < 3839 ) {
	BLK = 3;
} else
if ( n >= 3839 && n < 3840 ) {
	BLK = 1;
} else
if ( n >= 3840 && n < 3938 ) {
	BLK = 2;
} else
if ( n >= 3938 && n < 3939 ) {
	BLK = 0;
} else
if ( n >= 3939 && n < 3958 ) {
	BLK = 1;
} else
if ( n >= 3958 && n < 13339 ) {
	BLK = 2;
} else
if ( n >= 13339 && n < 16757 ) {
	BLK = 1;
} else
if ( n >= 16757 && n < 21438 ) {
	BLK = 3;
} else
if ( n >= 21438 && n < 21837 ) {
	BLK = 1;
} else
if ( n >= 21837 && n < 23397 ) {
	BLK = 3;
} else
if ( n >= 23397 && n < 23809 ) {
	BLK = 1;
} else
if ( n >= 23809 && n < 25035 ) {
	BLK = 3;
} else
if ( n >= 25035 && n < 25357 ) {
	BLK = 1;
} else
if ( n >= 25357 && n < 25867 ) {
	BLK = 3;
} else
if ( n >= 25867 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
