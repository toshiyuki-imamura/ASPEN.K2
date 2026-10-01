#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Sat Sep 26 19:52:36  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2967 ) {
	BLK = 0;
} else
if ( n >= 2967 && n < 6876 ) {
	BLK = 1;
} else
if ( n >= 6876 && n < 6988 ) {
	BLK = 5;
} else
if ( n >= 6988 && n < 7026 ) {
	BLK = 4;
} else
if ( n >= 7026 && n < 33186 ) {
	BLK = 1;
} else
if ( n >= 33186 && n < 33633 ) {
	BLK = 5;
} else
if ( n >= 33633 && n < 35196 ) {
	BLK = 1;
} else
if ( n >= 35196 && n < 38169 ) {
	BLK = 5;
} else
if ( n >= 38169 && n < 39303 ) {
	BLK = 3;
} else
if ( n >= 39303 && n < 47514 ) {
	BLK = 5;
} else
if ( n >= 47514 && n < 51430 ) {
	BLK = 1;
} else
if ( n >= 51430 && n < 53798 ) {
	BLK = 5;
} else
if ( n >= 53798 && n < 56210 ) {
	BLK = 1;
} else
if ( n >= 56210 && n < 58705 ) {
	BLK = 5;
} else
if ( n >= 58705 && n < 63897 ) {
	BLK = 1;
} else
if ( n >= 63897 && n < 67284 ) {
	BLK = 5;
} else
if ( n >= 67284 && n < 72953 ) {
	BLK = 1;
} else
if ( n >= 72953 && n < 76816 ) {
	BLK = 5;
} else
if ( n >= 76816 && n < 87358 ) {
	BLK = 1;
} else
if ( n >= 87358 && n < 92436 ) {
	BLK = 5;
} else
if ( n >= 92436 && n < 100712 ) {
	BLK = 1;
} else
if ( n >= 100712 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
