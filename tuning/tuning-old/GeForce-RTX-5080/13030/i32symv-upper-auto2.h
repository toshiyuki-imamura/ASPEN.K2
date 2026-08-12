#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Thu Aug 06 14:01:54  2026
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

if ( n >= 1 && n < 248 ) {
	BLK = 0;
} else
if ( n >= 248 && n < 250 ) {
	BLK = 1;
} else
if ( n >= 250 && n < 254 ) {
	BLK = 2;
} else
if ( n >= 254 && n < 256 ) {
	BLK = 0;
} else
if ( n >= 256 && n < 276 ) {
	BLK = 3;
} else
if ( n >= 276 && n < 278 ) {
	BLK = 1;
} else
if ( n >= 278 && n < 279 ) {
	BLK = 5;
} else
if ( n >= 279 && n < 287 ) {
	BLK = 0;
} else
if ( n >= 287 && n < 288 ) {
	BLK = 1;
} else
if ( n >= 288 && n < 289 ) {
	BLK = 5;
} else
if ( n >= 289 && n < 305 ) {
	BLK = 3;
} else
if ( n >= 305 && n < 1029 ) {
	BLK = 0;
} else
if ( n >= 1029 && n < 1030 ) {
	BLK = 2;
} else
if ( n >= 1030 && n < 1241 ) {
	BLK = 3;
} else
if ( n >= 1241 && n < 1695 ) {
	BLK = 0;
} else
if ( n >= 1695 && n < 2105 ) {
	BLK = 3;
} else
if ( n >= 2105 && n < 2106 ) {
	BLK = 2;
} else
if ( n >= 2106 && n < 2107 ) {
	BLK = 0;
} else
if ( n >= 2107 && n < 2180 ) {
	BLK = 3;
} else
if ( n >= 2180 && n < 2181 ) {
	BLK = 0;
} else
if ( n >= 2181 && n < 2200 ) {
	BLK = 2;
} else
if ( n >= 2200 && n < 2201 ) {
	BLK = 4;
} else
if ( n >= 2201 && n < 2202 ) {
	BLK = 3;
} else
if ( n >= 2202 && n < 2204 ) {
	BLK = 2;
} else
if ( n >= 2204 && n < 2205 ) {
	BLK = 0;
} else
if ( n >= 2205 && n < 2228 ) {
	BLK = 3;
} else
if ( n >= 2228 && n < 2229 ) {
	BLK = 0;
} else
if ( n >= 2229 && n < 2241 ) {
	BLK = 2;
} else
if ( n >= 2241 && n < 2242 ) {
	BLK = 3;
} else
if ( n >= 2242 && n < 2243 ) {
	BLK = 0;
} else
if ( n >= 2243 && n < 2254 ) {
	BLK = 2;
} else
if ( n >= 2254 && n < 2330 ) {
	BLK = 3;
} else
if ( n >= 2330 && n < 2391 ) {
	BLK = 2;
} else
if ( n >= 2391 && n < 2392 ) {
	BLK = 4;
} else
if ( n >= 2392 && n < 2597 ) {
	BLK = 3;
} else
if ( n >= 2597 && n < 2599 ) {
	BLK = 4;
} else
if ( n >= 2599 && n < 2963 ) {
	BLK = 2;
} else
if ( n >= 2963 && n < 2964 ) {
	BLK = 4;
} else
if ( n >= 2964 && n < 3152 ) {
	BLK = 3;
} else
if ( n >= 3152 && n < 3161 ) {
	BLK = 2;
} else
if ( n >= 3161 && n < 3162 ) {
	BLK = 4;
} else
if ( n >= 3162 && n < 3174 ) {
	BLK = 3;
} else
if ( n >= 3174 && n < 3176 ) {
	BLK = 4;
} else
if ( n >= 3176 && n < 3192 ) {
	BLK = 2;
} else
if ( n >= 3192 && n < 3193 ) {
	BLK = 4;
} else
if ( n >= 3193 && n < 3202 ) {
	BLK = 3;
} else
if ( n >= 3202 && n < 3208 ) {
	BLK = 2;
} else
if ( n >= 3208 && n < 3209 ) {
	BLK = 4;
} else
if ( n >= 3209 && n < 3236 ) {
	BLK = 3;
} else
if ( n >= 3236 && n < 3255 ) {
	BLK = 2;
} else
if ( n >= 3255 && n < 3264 ) {
	BLK = 4;
} else
if ( n >= 3264 && n < 3283 ) {
	BLK = 3;
} else
if ( n >= 3283 && n < 3291 ) {
	BLK = 2;
} else
if ( n >= 3291 && n < 3293 ) {
	BLK = 3;
} else
if ( n >= 3293 && n < 3294 ) {
	BLK = 4;
} else
if ( n >= 3294 && n < 3321 ) {
	BLK = 2;
} else
if ( n >= 3321 && n < 3366 ) {
	BLK = 3;
} else
if ( n >= 3366 && n < 3368 ) {
	BLK = 4;
} else
if ( n >= 3368 && n < 3381 ) {
	BLK = 2;
} else
if ( n >= 3381 && n < 3382 ) {
	BLK = 3;
} else
if ( n >= 3382 && n < 3388 ) {
	BLK = 4;
} else
if ( n >= 3388 && n < 3418 ) {
	BLK = 2;
} else
if ( n >= 3418 && n < 3419 ) {
	BLK = 3;
} else
if ( n >= 3419 && n < 3420 ) {
	BLK = 4;
} else
if ( n >= 3420 && n < 3427 ) {
	BLK = 2;
} else
if ( n >= 3427 && n < 3429 ) {
	BLK = 3;
} else
if ( n >= 3429 && n < 3433 ) {
	BLK = 4;
} else
if ( n >= 3433 && n < 3443 ) {
	BLK = 3;
} else
if ( n >= 3443 && n < 3491 ) {
	BLK = 2;
} else
if ( n >= 3491 && n < 3493 ) {
	BLK = 3;
} else
if ( n >= 3493 && n < 3499 ) {
	BLK = 4;
} else
if ( n >= 3499 && n < 3500 ) {
	BLK = 3;
} else
if ( n >= 3500 && n < 3505 ) {
	BLK = 2;
} else
if ( n >= 3505 && n < 3506 ) {
	BLK = 4;
} else
if ( n >= 3506 && n < 3520 ) {
	BLK = 3;
} else
if ( n >= 3520 && n < 3531 ) {
	BLK = 2;
} else
if ( n >= 3531 && n < 3532 ) {
	BLK = 4;
} else
if ( n >= 3532 && n < 3533 ) {
	BLK = 3;
} else
if ( n >= 3533 && n < 3537 ) {
	BLK = 2;
} else
if ( n >= 3537 && n < 3540 ) {
	BLK = 4;
} else
if ( n >= 3540 && n < 3541 ) {
	BLK = 3;
} else
if ( n >= 3541 && n < 3583 ) {
	BLK = 2;
} else
if ( n >= 3583 && n < 3585 ) {
	BLK = 3;
} else
if ( n >= 3585 && n < 3590 ) {
	BLK = 4;
} else
if ( n >= 3590 && n < 3592 ) {
	BLK = 3;
} else
if ( n >= 3592 && n < 3594 ) {
	BLK = 2;
} else
if ( n >= 3594 && n < 3596 ) {
	BLK = 4;
} else
if ( n >= 3596 && n < 3601 ) {
	BLK = 3;
} else
if ( n >= 3601 && n < 3604 ) {
	BLK = 2;
} else
if ( n >= 3604 && n < 3608 ) {
	BLK = 4;
} else
if ( n >= 3608 && n < 3610 ) {
	BLK = 2;
} else
if ( n >= 3610 && n < 3614 ) {
	BLK = 3;
} else
if ( n >= 3614 && n < 3619 ) {
	BLK = 2;
} else
if ( n >= 3619 && n < 3620 ) {
	BLK = 4;
} else
if ( n >= 3620 && n < 3649 ) {
	BLK = 3;
} else
if ( n >= 3649 && n < 3654 ) {
	BLK = 2;
} else
if ( n >= 3654 && n < 3655 ) {
	BLK = 4;
} else
if ( n >= 3655 && n < 3664 ) {
	BLK = 3;
} else
if ( n >= 3664 && n < 3706 ) {
	BLK = 2;
} else
if ( n >= 3706 && n < 3707 ) {
	BLK = 3;
} else
if ( n >= 3707 && n < 3708 ) {
	BLK = 4;
} else
if ( n >= 3708 && n < 3757 ) {
	BLK = 2;
} else
if ( n >= 3757 && n < 3758 ) {
	BLK = 3;
} else
if ( n >= 3758 && n < 3762 ) {
	BLK = 4;
} else
if ( n >= 3762 && n < 3768 ) {
	BLK = 3;
} else
if ( n >= 3768 && n < 3783 ) {
	BLK = 2;
} else
if ( n >= 3783 && n < 3784 ) {
	BLK = 4;
} else
if ( n >= 3784 && n < 3794 ) {
	BLK = 3;
} else
if ( n >= 3794 && n < 3795 ) {
	BLK = 2;
} else
if ( n >= 3795 && n < 3798 ) {
	BLK = 4;
} else
if ( n >= 3798 && n < 3799 ) {
	BLK = 3;
} else
if ( n >= 3799 && n < 3817 ) {
	BLK = 2;
} else
if ( n >= 3817 && n < 3819 ) {
	BLK = 3;
} else
if ( n >= 3819 && n < 3820 ) {
	BLK = 4;
} else
if ( n >= 3820 && n < 3827 ) {
	BLK = 2;
} else
if ( n >= 3827 && n < 3830 ) {
	BLK = 3;
} else
if ( n >= 3830 && n < 3833 ) {
	BLK = 4;
} else
if ( n >= 3833 && n < 3835 ) {
	BLK = 2;
} else
if ( n >= 3835 && n < 3838 ) {
	BLK = 3;
} else
if ( n >= 3838 && n < 3843 ) {
	BLK = 2;
} else
if ( n >= 3843 && n < 3844 ) {
	BLK = 4;
} else
if ( n >= 3844 && n < 3845 ) {
	BLK = 3;
} else
if ( n >= 3845 && n < 3861 ) {
	BLK = 2;
} else
if ( n >= 3861 && n < 3862 ) {
	BLK = 4;
} else
if ( n >= 3862 && n < 3863 ) {
	BLK = 3;
} else
if ( n >= 3863 && n < 3869 ) {
	BLK = 2;
} else
if ( n >= 3869 && n < 3872 ) {
	BLK = 4;
} else
if ( n >= 3872 && n < 3926 ) {
	BLK = 2;
} else
if ( n >= 3926 && n < 3944 ) {
	BLK = 3;
} else
if ( n >= 3944 && n < 3945 ) {
	BLK = 2;
} else
if ( n >= 3945 && n < 3946 ) {
	BLK = 4;
} else
if ( n >= 3946 && n < 3957 ) {
	BLK = 3;
} else
if ( n >= 3957 && n < 3958 ) {
	BLK = 2;
} else
if ( n >= 3958 && n < 3961 ) {
	BLK = 4;
} else
if ( n >= 3961 && n < 3963 ) {
	BLK = 3;
} else
if ( n >= 3963 && n < 3975 ) {
	BLK = 2;
} else
if ( n >= 3975 && n < 3977 ) {
	BLK = 4;
} else
if ( n >= 3977 && n < 3993 ) {
	BLK = 3;
} else
if ( n >= 3993 && n < 3994 ) {
	BLK = 4;
} else
if ( n >= 3994 && n < 4002 ) {
	BLK = 2;
} else
if ( n >= 4002 && n < 4004 ) {
	BLK = 3;
} else
if ( n >= 4004 && n < 4005 ) {
	BLK = 4;
} else
if ( n >= 4005 && n < 4014 ) {
	BLK = 2;
} else
if ( n >= 4014 && n < 4022 ) {
	BLK = 3;
} else
if ( n >= 4022 && n < 4027 ) {
	BLK = 4;
} else
if ( n >= 4027 && n < 4070 ) {
	BLK = 2;
} else
if ( n >= 4070 && n < 4072 ) {
	BLK = 4;
} else
if ( n >= 4072 && n < 4074 ) {
	BLK = 3;
} else
if ( n >= 4074 && n < 4081 ) {
	BLK = 2;
} else
if ( n >= 4081 && n < 4083 ) {
	BLK = 4;
} else
if ( n >= 4083 && n < 4085 ) {
	BLK = 3;
} else
if ( n >= 4085 && n < 4087 ) {
	BLK = 2;
} else
if ( n >= 4087 && n < 4090 ) {
	BLK = 4;
} else
if ( n >= 4090 && n < 4103 ) {
	BLK = 3;
} else
if ( n >= 4103 && n < 4172 ) {
	BLK = 4;
} else
if ( n >= 4172 && n < 4176 ) {
	BLK = 3;
} else
if ( n >= 4176 && n < 4248 ) {
	BLK = 2;
} else
if ( n >= 4248 && n < 4249 ) {
	BLK = 3;
} else
if ( n >= 4249 && n < 4290 ) {
	BLK = 4;
} else
if ( n >= 4290 && n < 4296 ) {
	BLK = 2;
} else
if ( n >= 4296 && n < 4320 ) {
	BLK = 3;
} else
if ( n >= 4320 && n < 4405 ) {
	BLK = 4;
} else
if ( n >= 4405 && n < 4419 ) {
	BLK = 3;
} else
if ( n >= 4419 && n < 4420 ) {
	BLK = 2;
} else
if ( n >= 4420 && n < 4430 ) {
	BLK = 4;
} else
if ( n >= 4430 && n < 4438 ) {
	BLK = 3;
} else
if ( n >= 4438 && n < 4439 ) {
	BLK = 2;
} else
if ( n >= 4439 && n < 4444 ) {
	BLK = 4;
} else
if ( n >= 4444 && n < 4460 ) {
	BLK = 3;
} else
if ( n >= 4460 && n < 4467 ) {
	BLK = 2;
} else
if ( n >= 4467 && n < 4509 ) {
	BLK = 4;
} else
if ( n >= 4509 && n < 4527 ) {
	BLK = 2;
} else
if ( n >= 4527 && n < 4529 ) {
	BLK = 3;
} else
if ( n >= 4529 && n < 4539 ) {
	BLK = 4;
} else
if ( n >= 4539 && n < 4571 ) {
	BLK = 2;
} else
if ( n >= 4571 && n < 4579 ) {
	BLK = 3;
} else
if ( n >= 4579 && n < 4591 ) {
	BLK = 2;
} else
if ( n >= 4591 && n < 4858 ) {
	BLK = 4;
} else
if ( n >= 4858 && n < 4865 ) {
	BLK = 2;
} else
if ( n >= 4865 && n < 4919 ) {
	BLK = 3;
} else
if ( n >= 4919 && n < 4923 ) {
	BLK = 2;
} else
if ( n >= 4923 && n < 8601 ) {
	BLK = 4;
} else
if ( n >= 8601 && n < 8655 ) {
	BLK = 5;
} else
if ( n >= 8655 && n < 13186 ) {
	BLK = 3;
} else
if ( n >= 13186 && n < 13467 ) {
	BLK = 1;
} else
if ( n >= 13467 && n < 13742 ) {
	BLK = 3;
} else
if ( n >= 13742 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
