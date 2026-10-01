#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Wed Sep 30 04:35:14  2026
 Host on qc-gh200-02.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 102123945984
// capacity of the work area reserved on the GPU
WORK= 8140288
// for double or cuFloatComplex or int64
MAXDIM= 107335
// for float or cuHalfComplex or int32
MAXDIM2= 151794
// for cuDoubleComplex or DD or int128
MAXDIM3= 75897
// for DD-Complex
MAXDIM4= 53667
// for half or int16
MAXDIM5= 214670
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3520 ) {
	BLK = 0;
} else
if ( n >= 3520 && n < 3567 ) {
	BLK = 3;
} else
if ( n >= 3567 && n < 3595 ) {
	BLK = 1;
} else
if ( n >= 3595 && n < 3597 ) {
	BLK = 0;
} else
if ( n >= 3597 && n < 3598 ) {
	BLK = 3;
} else
if ( n >= 3598 && n < 3599 ) {
	BLK = 1;
} else
if ( n >= 3599 && n < 3602 ) {
	BLK = 0;
} else
if ( n >= 3602 && n < 3603 ) {
	BLK = 3;
} else
if ( n >= 3603 && n < 3607 ) {
	BLK = 1;
} else
if ( n >= 3607 && n < 3608 ) {
	BLK = 3;
} else
if ( n >= 3608 && n < 3612 ) {
	BLK = 0;
} else
if ( n >= 3612 && n < 3614 ) {
	BLK = 1;
} else
if ( n >= 3614 && n < 3620 ) {
	BLK = 3;
} else
if ( n >= 3620 && n < 3621 ) {
	BLK = 0;
} else
if ( n >= 3621 && n < 3629 ) {
	BLK = 1;
} else
if ( n >= 3629 && n < 3630 ) {
	BLK = 0;
} else
if ( n >= 3630 && n < 4075 ) {
	BLK = 3;
} else
if ( n >= 4075 && n < 15440 ) {
	BLK = 1;
} else
if ( n >= 15440 && n < 15516 ) {
	BLK = 4;
} else
if ( n >= 15516 && n < 15691 ) {
	BLK = 3;
} else
if ( n >= 15691 && n < 15972 ) {
	BLK = 1;
} else
if ( n >= 15972 && n < 16226 ) {
	BLK = 3;
} else
if ( n >= 16226 && n < 17046 ) {
	BLK = 1;
} else
if ( n >= 17046 && n < 17848 ) {
	BLK = 3;
} else
if ( n >= 17848 && n < 17869 ) {
	BLK = 4;
} else
if ( n >= 17869 && n < 18296 ) {
	BLK = 1;
} else
if ( n >= 18296 && n < 19206 ) {
	BLK = 3;
} else
if ( n >= 19206 && n < 19679 ) {
	BLK = 1;
} else
if ( n >= 19679 && n < 19951 ) {
	BLK = 4;
} else
if ( n >= 19951 && n < 20424 ) {
	BLK = 1;
} else
if ( n >= 20424 && n < 20862 ) {
	BLK = 3;
} else
if ( n >= 20862 && n < 21328 ) {
	BLK = 1;
} else
if ( n >= 21328 && n < 21671 ) {
	BLK = 3;
} else
if ( n >= 21671 && n < 22121 ) {
	BLK = 1;
} else
if ( n >= 22121 && n < 23596 ) {
	BLK = 3;
} else
if ( n >= 23596 && n < 24452 ) {
	BLK = 1;
} else
if ( n >= 24452 && n < 24741 ) {
	BLK = 4;
} else
if ( n >= 24741 && n < 25281 ) {
	BLK = 1;
} else
if ( n >= 25281 && n < 26086 ) {
	BLK = 3;
} else
if ( n >= 26086 && n < 26869 ) {
	BLK = 1;
} else
if ( n >= 26869 && n < 27513 ) {
	BLK = 3;
} else
if ( n >= 27513 && n < 28386 ) {
	BLK = 1;
} else
if ( n >= 28386 && n < 29077 ) {
	BLK = 3;
} else
if ( n >= 29077 && n < 29790 ) {
	BLK = 1;
} else
if ( n >= 29790 && n < 31057 ) {
	BLK = 3;
} else
if ( n >= 31057 && n < 31999 ) {
	BLK = 1;
} else
if ( n >= 31999 && n < 32857 ) {
	BLK = 3;
} else
if ( n >= 32857 && n < 33967 ) {
	BLK = 1;
} else
if ( n >= 33967 && n < 34896 ) {
	BLK = 3;
} else
if ( n >= 34896 && n < 36346 ) {
	BLK = 1;
} else
if ( n >= 36346 && n < 37642 ) {
	BLK = 3;
} else
if ( n >= 37642 && n < 39329 ) {
	BLK = 1;
} else
if ( n >= 39329 && n < 41121 ) {
	BLK = 3;
} else
if ( n >= 41121 && n < 42542 ) {
	BLK = 1;
} else
if ( n >= 42542 && n < 44086 ) {
	BLK = 3;
} else
if ( n >= 44086 && n < 52293 ) {
	BLK = 1;
} else
if ( n >= 52293 && n < 54048 ) {
	BLK = 3;
} else
if ( n >= 54048 && n < 64765 ) {
	BLK = 1;
} else
if ( n >= 64765 && n < 69345 ) {
	BLK = 3;
} else
if ( n >= 69345 && n < 91143 ) {
	BLK = 1;
} else
if ( n >= 91143 && n < 95520 ) {
	BLK = 3;
} else
if ( n >= 95520 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
