#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Sun Sep 27 09:23:38  2026
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

if ( n >= 1 && n < 508 ) {
	BLK = 0;
} else
if ( n >= 508 && n < 512 ) {
	BLK = 1;
} else
if ( n >= 512 && n < 535 ) {
	BLK = 3;
} else
if ( n >= 535 && n < 556 ) {
	BLK = 0;
} else
if ( n >= 556 && n < 559 ) {
	BLK = 3;
} else
if ( n >= 559 && n < 793 ) {
	BLK = 1;
} else
if ( n >= 793 && n < 1412 ) {
	BLK = 0;
} else
if ( n >= 1412 && n < 2048 ) {
	BLK = 5;
} else
if ( n >= 2048 && n < 3456 ) {
	BLK = 4;
} else
if ( n >= 3456 && n < 3513 ) {
	BLK = 1;
} else
if ( n >= 3513 && n < 3714 ) {
	BLK = 3;
} else
if ( n >= 3714 && n < 3794 ) {
	BLK = 1;
} else
if ( n >= 3794 && n < 3845 ) {
	BLK = 3;
} else
if ( n >= 3845 && n < 4445 ) {
	BLK = 2;
} else
if ( n >= 4445 && n < 4510 ) {
	BLK = 1;
} else
if ( n >= 4510 && n < 4512 ) {
	BLK = 2;
} else
if ( n >= 4512 && n < 4515 ) {
	BLK = 3;
} else
if ( n >= 4515 && n < 4662 ) {
	BLK = 1;
} else
if ( n >= 4662 && n < 4732 ) {
	BLK = 2;
} else
if ( n >= 4732 && n < 4754 ) {
	BLK = 3;
} else
if ( n >= 4754 && n < 4758 ) {
	BLK = 1;
} else
if ( n >= 4758 && n < 4810 ) {
	BLK = 2;
} else
if ( n >= 4810 && n < 4818 ) {
	BLK = 1;
} else
if ( n >= 4818 && n < 4849 ) {
	BLK = 3;
} else
if ( n >= 4849 && n < 6894 ) {
	BLK = 2;
} else
if ( n >= 6894 && n < 9181 ) {
	BLK = 1;
} else
if ( n >= 9181 && n < 18021 ) {
	BLK = 2;
} else
if ( n >= 18021 && n < 18343 ) {
	BLK = 1;
} else
if ( n >= 18343 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
