#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Sun Sep 27 05:40:04  2026
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
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
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

if ( n >= 1 && n < 251 ) {
	BLK = 0;
} else
if ( n >= 251 && n < 256 ) {
	BLK = 3;
} else
if ( n >= 256 && n < 3545 ) {
	BLK = 0;
} else
if ( n >= 3545 && n < 3546 ) {
	BLK = 1;
} else
if ( n >= 3546 && n < 3547 ) {
	BLK = 2;
} else
if ( n >= 3547 && n < 4131 ) {
	BLK = 0;
} else
if ( n >= 4131 && n < 4132 ) {
	BLK = 1;
} else
if ( n >= 4132 && n < 4190 ) {
	BLK = 2;
} else
if ( n >= 4190 && n < 4193 ) {
	BLK = 0;
} else
if ( n >= 4193 && n < 4196 ) {
	BLK = 1;
} else
if ( n >= 4196 && n < 4218 ) {
	BLK = 2;
} else
if ( n >= 4218 && n < 4221 ) {
	BLK = 1;
} else
if ( n >= 4221 && n < 4454 ) {
	BLK = 0;
} else
if ( n >= 4454 && n < 4570 ) {
	BLK = 1;
} else
if ( n >= 4570 && n < 4572 ) {
	BLK = 0;
} else
if ( n >= 4572 && n < 7059 ) {
	BLK = 2;
} else
if ( n >= 7059 && n < 7087 ) {
	BLK = 5;
} else
if ( n >= 7087 && n < 7109 ) {
	BLK = 1;
} else
if ( n >= 7109 && n < 7188 ) {
	BLK = 2;
} else
if ( n >= 7188 && n < 7247 ) {
	BLK = 4;
} else
if ( n >= 7247 && n < 7254 ) {
	BLK = 5;
} else
if ( n >= 7254 && n < 7260 ) {
	BLK = 2;
} else
if ( n >= 7260 && n < 7668 ) {
	BLK = 1;
} else
if ( n >= 7668 && n < 12087 ) {
	BLK = 5;
} else
if ( n >= 12087 && n < 14438 ) {
	BLK = 4;
} else
if ( n >= 14438 && n < 20892 ) {
	BLK = 1;
} else
if ( n >= 20892 && n < 21719 ) {
	BLK = 2;
} else
if ( n >= 21719 && n < 22181 ) {
	BLK = 1;
} else
if ( n >= 22181 && n < 22783 ) {
	BLK = 2;
} else
if ( n >= 22783 && n < 23278 ) {
	BLK = 1;
} else
if ( n >= 23278 && n < 23797 ) {
	BLK = 2;
} else
if ( n >= 23797 && n < 24128 ) {
	BLK = 1;
} else
if ( n >= 24128 && n < 24812 ) {
	BLK = 2;
} else
if ( n >= 24812 && n < 46381 ) {
	BLK = 1;
} else
if ( n >= 46381 && n < 47213 ) {
	BLK = 3;
} else
if ( n >= 47213 && n < 63952 ) {
	BLK = 1;
} else
if ( n >= 63952 && n < 66338 ) {
	BLK = 3;
} else
if ( n >= 66338 && n < 71133 ) {
	BLK = 1;
} else
if ( n >= 71133 && n < 76433 ) {
	BLK = 3;
} else
if ( n >= 76433 && n < 79951 ) {
	BLK = 1;
} else
if ( n >= 79951 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
