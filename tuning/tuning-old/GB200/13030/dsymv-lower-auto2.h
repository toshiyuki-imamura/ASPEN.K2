#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Tue Sep 29 22:31:30  2026
 Host on c237
 Device is GB200
****************************************/-->
// device name
DEVICE= GB200
// the number of multi-processors
MP= 152
// compute-compatibility generation
CG= 1000
// capacity of the global memory or host memory
MAXmem= 197555425280
// capacity of the work area reserved on the GPU
WORK= 13067520
// for double or cuFloatComplex or int64
MAXDIM= 149287
// for float or cuHalfComplex or int32
MAXDIM2= 211124
// for cuDoubleComplex or DD or int128
MAXDIM3= 105562
// for DD-Complex
MAXDIM4= 74643
// for half or int16
MAXDIM5= 298574
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 1000
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 6084 ) {
	BLK = 0;
} else
if ( n >= 6084 && n < 6099 ) {
	BLK = 2;
} else
if ( n >= 6099 && n < 6113 ) {
	BLK = 5;
} else
if ( n >= 6113 && n < 6319 ) {
	BLK = 0;
} else
if ( n >= 6319 && n < 40100 ) {
	BLK = 1;
} else
if ( n >= 40100 && n < 43133 ) {
	BLK = 4;
} else
if ( n >= 43133 && n < 46619 ) {
	BLK = 1;
} else
if ( n >= 46619 && n < 53422 ) {
	BLK = 4;
} else
if ( n >= 53422 && n < 54831 ) {
	BLK = 1;
} else
if ( n >= 54831 && n < 57016 ) {
	BLK = 4;
} else
if ( n >= 57016 && n < 61202 ) {
	BLK = 1;
} else
if ( n >= 61202 && n < 63793 ) {
	BLK = 4;
} else
if ( n >= 63793 && n < 65363 ) {
	BLK = 1;
} else
if ( n >= 65363 && n < 117456 ) {
	BLK = 4;
} else
if ( n >= 117456 && n < 120519 ) {
	BLK = 1;
} else
if ( n >= 120519 && n < 132759 ) {
	BLK = 4;
} else
if ( n >= 132759 && n < 136766 ) {
	BLK = 1;
} else
if ( n >= 136766 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
