#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Sat Sep 26 09:46:54  2026
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

if ( n >= 1 && n < 1869 ) {
	BLK = 0;
} else
if ( n >= 1869 && n < 2112 ) {
	BLK = 3;
} else
if ( n >= 2112 && n < 3520 ) {
	BLK = 5;
} else
if ( n >= 3520 && n < 3692 ) {
	BLK = 2;
} else
if ( n >= 3692 && n < 3778 ) {
	BLK = 1;
} else
if ( n >= 3778 && n < 3796 ) {
	BLK = 4;
} else
if ( n >= 3796 && n < 3984 ) {
	BLK = 2;
} else
if ( n >= 3984 && n < 4048 ) {
	BLK = 4;
} else
if ( n >= 4048 && n < 18047 ) {
	BLK = 1;
} else
if ( n >= 18047 && n < 18325 ) {
	BLK = 4;
} else
if ( n >= 18325 && n < 34927 ) {
	BLK = 1;
} else
if ( n >= 34927 && n < 35327 ) {
	BLK = 4;
} else
if ( n >= 35327 && n < 37106 ) {
	BLK = 1;
} else
if ( n >= 37106 && n < 37698 ) {
	BLK = 4;
} else
if ( n >= 37698 && n < 43333 ) {
	BLK = 1;
} else
if ( n >= 43333 && n < 45533 ) {
	BLK = 4;
} else
if ( n >= 45533 && n < 47691 ) {
	BLK = 1;
} else
if ( n >= 47691 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
