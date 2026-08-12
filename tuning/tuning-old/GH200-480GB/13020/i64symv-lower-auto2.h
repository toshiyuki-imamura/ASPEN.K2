#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Thu Aug 06 05:13:22  2026
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
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3583 ) {
	BLK = 0;
} else
if ( n >= 3583 && n < 3632 ) {
	BLK = 2;
} else
if ( n >= 3632 && n < 3638 ) {
	BLK = 1;
} else
if ( n >= 3638 && n < 3657 ) {
	BLK = 5;
} else
if ( n >= 3657 && n < 3817 ) {
	BLK = 1;
} else
if ( n >= 3817 && n < 3824 ) {
	BLK = 5;
} else
if ( n >= 3824 && n < 3840 ) {
	BLK = 2;
} else
if ( n >= 3840 && n < 3848 ) {
	BLK = 5;
} else
if ( n >= 3848 && n < 3863 ) {
	BLK = 1;
} else
if ( n >= 3863 && n < 3900 ) {
	BLK = 5;
} else
if ( n >= 3900 && n < 3911 ) {
	BLK = 1;
} else
if ( n >= 3911 && n < 3921 ) {
	BLK = 5;
} else
if ( n >= 3921 && n < 3922 ) {
	BLK = 1;
} else
if ( n >= 3922 && n < 3935 ) {
	BLK = 2;
} else
if ( n >= 3935 && n < 3951 ) {
	BLK = 5;
} else
if ( n >= 3951 && n < 4167 ) {
	BLK = 1;
} else
if ( n >= 4167 && n < 4169 ) {
	BLK = 5;
} else
if ( n >= 4169 && n < 4277 ) {
	BLK = 2;
} else
if ( n >= 4277 && n < 4290 ) {
	BLK = 1;
} else
if ( n >= 4290 && n < 4293 ) {
	BLK = 2;
} else
if ( n >= 4293 && n < 4295 ) {
	BLK = 5;
} else
if ( n >= 4295 && n < 4296 ) {
	BLK = 4;
} else
if ( n >= 4296 && n < 4305 ) {
	BLK = 1;
} else
if ( n >= 4305 && n < 4311 ) {
	BLK = 2;
} else
if ( n >= 4311 && n < 4314 ) {
	BLK = 4;
} else
if ( n >= 4314 && n < 4317 ) {
	BLK = 1;
} else
if ( n >= 4317 && n < 4335 ) {
	BLK = 5;
} else
if ( n >= 4335 && n < 4339 ) {
	BLK = 2;
} else
if ( n >= 4339 && n < 4539 ) {
	BLK = 1;
} else
if ( n >= 4539 && n < 4646 ) {
	BLK = 4;
} else
if ( n >= 4646 && n < 4784 ) {
	BLK = 1;
} else
if ( n >= 4784 && n < 4813 ) {
	BLK = 2;
} else
if ( n >= 4813 && n < 4925 ) {
	BLK = 4;
} else
if ( n >= 4925 && n < 4942 ) {
	BLK = 2;
} else
if ( n >= 4942 && n < 5065 ) {
	BLK = 4;
} else
if ( n >= 5065 && n < 5193 ) {
	BLK = 1;
} else
if ( n >= 5193 && n < 5745 ) {
	BLK = 4;
} else
if ( n >= 5745 && n < 5757 ) {
	BLK = 5;
} else
if ( n >= 5757 && n < 5846 ) {
	BLK = 1;
} else
if ( n >= 5846 && n < 6476 ) {
	BLK = 4;
} else
if ( n >= 6476 && n < 15365 ) {
	BLK = 1;
} else
if ( n >= 15365 && n < 15471 ) {
	BLK = 5;
} else
if ( n >= 15471 && n < 16295 ) {
	BLK = 2;
} else
if ( n >= 16295 && n < 17025 ) {
	BLK = 1;
} else
if ( n >= 17025 && n < 17379 ) {
	BLK = 2;
} else
if ( n >= 17379 && n < 18752 ) {
	BLK = 1;
} else
if ( n >= 18752 && n < 18900 ) {
	BLK = 5;
} else
if ( n >= 18900 && n < 19190 ) {
	BLK = 2;
} else
if ( n >= 19190 && n < 19599 ) {
	BLK = 1;
} else
if ( n >= 19599 && n < 19996 ) {
	BLK = 2;
} else
if ( n >= 19996 && n < 21383 ) {
	BLK = 1;
} else
if ( n >= 21383 && n < 21676 ) {
	BLK = 2;
} else
if ( n >= 21676 && n < 22240 ) {
	BLK = 1;
} else
if ( n >= 22240 && n < 22737 ) {
	BLK = 2;
} else
if ( n >= 22737 && n < 23233 ) {
	BLK = 1;
} else
if ( n >= 23233 && n < 23553 ) {
	BLK = 2;
} else
if ( n >= 23553 && n < 24377 ) {
	BLK = 1;
} else
if ( n >= 24377 && n < 24796 ) {
	BLK = 2;
} else
if ( n >= 24796 && n < 25472 ) {
	BLK = 1;
} else
if ( n >= 25472 && n < 25987 ) {
	BLK = 2;
} else
if ( n >= 25987 && n < 28211 ) {
	BLK = 1;
} else
if ( n >= 28211 && n < 28947 ) {
	BLK = 2;
} else
if ( n >= 28947 && n < 30132 ) {
	BLK = 1;
} else
if ( n >= 30132 && n < 31056 ) {
	BLK = 2;
} else
if ( n >= 31056 && n < 32146 ) {
	BLK = 1;
} else
if ( n >= 32146 && n < 32668 ) {
	BLK = 2;
} else
if ( n >= 32668 && n < 33834 ) {
	BLK = 1;
} else
if ( n >= 33834 && n < 35023 ) {
	BLK = 2;
} else
if ( n >= 35023 && n < 36749 ) {
	BLK = 1;
} else
if ( n >= 36749 && n < 37937 ) {
	BLK = 2;
} else
if ( n >= 37937 && n < 39878 ) {
	BLK = 1;
} else
if ( n >= 39878 && n < 40376 ) {
	BLK = 2;
} else
if ( n >= 40376 && n < 42535 ) {
	BLK = 1;
} else
if ( n >= 42535 && n < 44263 ) {
	BLK = 2;
} else
if ( n >= 44263 && n < 47341 ) {
	BLK = 1;
} else
if ( n >= 47341 && n < 48277 ) {
	BLK = 2;
} else
if ( n >= 48277 && n < 51687 ) {
	BLK = 1;
} else
if ( n >= 51687 && n < 54323 ) {
	BLK = 2;
} else
if ( n >= 54323 && n < 65119 ) {
	BLK = 1;
} else
if ( n >= 65119 && n < 70071 ) {
	BLK = 2;
} else
if ( n >= 70071 && n < 100503 ) {
	BLK = 1;
} else
if ( n >= 100503 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
