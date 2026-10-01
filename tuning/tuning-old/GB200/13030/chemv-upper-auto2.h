#ifndef CHEMVU_AUTO2_H_INCLUDED
#define CHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVU
 Thu Oct 01 01:14:59  2026
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
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2 ) {
	BLK = 4;
} else
if ( n >= 2 && n < 4440 ) {
	BLK = 0;
} else
if ( n >= 4440 && n < 5454 ) {
	BLK = 1;
} else
if ( n >= 5454 && n < 6495 ) {
	BLK = 0;
} else
if ( n >= 6495 && n < 14188 ) {
	BLK = 2;
} else
if ( n >= 14188 && n < 14749 ) {
	BLK = 3;
} else
if ( n >= 14749 && n < 19887 ) {
	BLK = 2;
} else
if ( n >= 19887 && n < 22632 ) {
	BLK = 3;
} else
if ( n >= 22632 && n < 30234 ) {
	BLK = 2;
} else
if ( n >= 30234 && n < 37137 ) {
	BLK = 3;
} else
if ( n >= 37137 && n < 38605 ) {
	BLK = 2;
} else
if ( n >= 38605 && n < 43263 ) {
	BLK = 3;
} else
if ( n >= 43263 && n < 45332 ) {
	BLK = 2;
} else
if ( n >= 45332 && n < 74470 ) {
	BLK = 3;
} else
if ( n >= 74470 && n < 79699 ) {
	BLK = 2;
} else
if ( n >= 79699 && n < 117357 ) {
	BLK = 3;
} else
if ( n >= 117357 && n < 120562 ) {
	BLK = 2;
} else
if ( n >= 120562 && n < 132577 ) {
	BLK = 3;
} else
if ( n >= 132577 && n < 136963 ) {
	BLK = 2;
} else
if ( n >= 136963 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
