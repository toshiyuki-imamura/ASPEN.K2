#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Thu Oct 01 10:05:56  2026
 Host on c181
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
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5562 ) {
	BLK = 0;
} else
if ( n >= 5562 && n < 9317 ) {
	BLK = 4;
} else
if ( n >= 9317 && n < 29953 ) {
	BLK = 2;
} else
if ( n >= 29953 && n < 30554 ) {
	BLK = 3;
} else
if ( n >= 30554 && n < 30965 ) {
	BLK = 2;
} else
if ( n >= 30965 && n < 32350 ) {
	BLK = 3;
} else
if ( n >= 32350 && n < 36612 ) {
	BLK = 2;
} else
if ( n >= 36612 && n < 57124 ) {
	BLK = 3;
} else
if ( n >= 57124 && n < 63463 ) {
	BLK = 2;
} else
if ( n >= 63463 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
