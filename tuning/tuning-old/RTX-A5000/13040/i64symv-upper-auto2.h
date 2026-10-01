#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Sat Sep 26 02:14:08  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 527 ) {
	BLK = 0;
} else
if ( n >= 527 && n < 528 ) {
	BLK = 2;
} else
if ( n >= 528 && n < 529 ) {
	BLK = 3;
} else
if ( n >= 529 && n < 884 ) {
	BLK = 0;
} else
if ( n >= 884 && n < 885 ) {
	BLK = 3;
} else
if ( n >= 885 && n < 886 ) {
	BLK = 2;
} else
if ( n >= 886 && n < 907 ) {
	BLK = 0;
} else
if ( n >= 907 && n < 908 ) {
	BLK = 2;
} else
if ( n >= 908 && n < 909 ) {
	BLK = 3;
} else
if ( n >= 909 && n < 960 ) {
	BLK = 0;
} else
if ( n >= 960 && n < 1025 ) {
	BLK = 3;
} else
if ( n >= 1025 && n < 1026 ) {
	BLK = 5;
} else
if ( n >= 1026 && n < 2977 ) {
	BLK = 2;
} else
if ( n >= 2977 && n < 2979 ) {
	BLK = 3;
} else
if ( n >= 2979 && n < 2980 ) {
	BLK = 4;
} else
if ( n >= 2980 && n < 2981 ) {
	BLK = 2;
} else
if ( n >= 2981 && n < 2982 ) {
	BLK = 3;
} else
if ( n >= 2982 && n < 2985 ) {
	BLK = 4;
} else
if ( n >= 2985 && n < 2986 ) {
	BLK = 2;
} else
if ( n >= 2986 && n < 3711 ) {
	BLK = 3;
} else
if ( n >= 3711 && n < 4131 ) {
	BLK = 4;
} else
if ( n >= 4131 && n < 4133 ) {
	BLK = 3;
} else
if ( n >= 4133 && n < 4143 ) {
	BLK = 1;
} else
if ( n >= 4143 && n < 4190 ) {
	BLK = 3;
} else
if ( n >= 4190 && n < 5491 ) {
	BLK = 4;
} else
if ( n >= 5491 && n < 12011 ) {
	BLK = 1;
} else
if ( n >= 12011 && n < 13329 ) {
	BLK = 4;
} else
if ( n >= 13329 && n < 13720 ) {
	BLK = 1;
} else
if ( n >= 13720 && n < 14339 ) {
	BLK = 4;
} else
if ( n >= 14339 && n < 14868 ) {
	BLK = 1;
} else
if ( n >= 14868 && n < 14902 ) {
	BLK = 4;
} else
if ( n >= 14902 && n < 15344 ) {
	BLK = 3;
} else
if ( n >= 15344 && n < 16666 ) {
	BLK = 4;
} else
if ( n >= 16666 && n < 17353 ) {
	BLK = 1;
} else
if ( n >= 17353 && n < 18300 ) {
	BLK = 4;
} else
if ( n >= 18300 && n < 19209 ) {
	BLK = 1;
} else
if ( n >= 19209 && n < 22416 ) {
	BLK = 4;
} else
if ( n >= 22416 && n < 23514 ) {
	BLK = 1;
} else
if ( n >= 23514 && n < 25610 ) {
	BLK = 4;
} else
if ( n >= 25610 && n < 26060 ) {
	BLK = 1;
} else
if ( n >= 26060 && n < 34944 ) {
	BLK = 4;
} else
if ( n >= 34944 && n < 35925 ) {
	BLK = 3;
} else
if ( n >= 35925 && n < 36309 ) {
	BLK = 4;
} else
if ( n >= 36309 && n < 37387 ) {
	BLK = 3;
} else
if ( n >= 37387 && n < 41809 ) {
	BLK = 4;
} else
if ( n >= 41809 && n < 46556 ) {
	BLK = 1;
} else
if ( n >= 46556 && n < 51194 ) {
	BLK = 4;
} else
if ( n >= 51194 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
