#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Sat Sep 26 07:46:31  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 8 ) {
	BLK = 5;
} else
if ( n >= 8 && n < 27 ) {
	BLK = 1;
} else
if ( n >= 27 && n < 675 ) {
	BLK = 5;
} else
if ( n >= 675 && n < 1753 ) {
	BLK = 3;
} else
if ( n >= 1753 && n < 1757 ) {
	BLK = 1;
} else
if ( n >= 1757 && n < 1760 ) {
	BLK = 4;
} else
if ( n >= 1760 && n < 2464 ) {
	BLK = 2;
} else
if ( n >= 2464 && n < 2482 ) {
	BLK = 5;
} else
if ( n >= 2482 && n < 2722 ) {
	BLK = 3;
} else
if ( n >= 2722 && n < 3054 ) {
	BLK = 2;
} else
if ( n >= 3054 && n < 4613 ) {
	BLK = 1;
} else
if ( n >= 4613 && n < 6085 ) {
	BLK = 2;
} else
if ( n >= 6085 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
