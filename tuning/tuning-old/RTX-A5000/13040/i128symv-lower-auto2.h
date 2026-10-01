#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Sat Sep 26 14:44:20  2026
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

if ( n >= 1 && n < 4 ) {
	BLK = 1;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 2;
} else
if ( n >= 5 && n < 7 ) {
	BLK = 3;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 5;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 21 ) {
	BLK = 3;
} else
if ( n >= 21 && n < 1080 ) {
	BLK = 0;
} else
if ( n >= 1080 && n < 2217 ) {
	BLK = 1;
} else
if ( n >= 2217 && n < 2239 ) {
	BLK = 4;
} else
if ( n >= 2239 && n < 2243 ) {
	BLK = 1;
} else
if ( n >= 2243 && n < 2255 ) {
	BLK = 2;
} else
if ( n >= 2255 && n < 2256 ) {
	BLK = 1;
} else
if ( n >= 2256 && n < 2559 ) {
	BLK = 4;
} else
if ( n >= 2559 && n < 6660 ) {
	BLK = 1;
} else
if ( n >= 6660 && n < 6668 ) {
	BLK = 3;
} else
if ( n >= 6668 && n < 6694 ) {
	BLK = 2;
} else
if ( n >= 6694 && n < 7000 ) {
	BLK = 1;
} else
if ( n >= 7000 && n < 7020 ) {
	BLK = 3;
} else
if ( n >= 7020 && n < 7229 ) {
	BLK = 2;
} else
if ( n >= 7229 && n < 7317 ) {
	BLK = 3;
} else
if ( n >= 7317 && n < 8578 ) {
	BLK = 1;
} else
if ( n >= 8578 && n < 8835 ) {
	BLK = 3;
} else
if ( n >= 8835 && n < 9045 ) {
	BLK = 1;
} else
if ( n >= 9045 && n < 9072 ) {
	BLK = 3;
} else
if ( n >= 9072 && n < 9093 ) {
	BLK = 2;
} else
if ( n >= 9093 && n < 9330 ) {
	BLK = 1;
} else
if ( n >= 9330 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
