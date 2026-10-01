#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Wed Sep 30 03:59:38  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2 ) {
	BLK = 3;
} else
if ( n >= 2 && n < 5 ) {
	BLK = 4;
} else
if ( n >= 5 && n < 1275 ) {
	BLK = 0;
} else
if ( n >= 1275 && n < 1276 ) {
	BLK = 2;
} else
if ( n >= 1276 && n < 1277 ) {
	BLK = 3;
} else
if ( n >= 1277 && n < 1298 ) {
	BLK = 0;
} else
if ( n >= 1298 && n < 1299 ) {
	BLK = 2;
} else
if ( n >= 1299 && n < 1345 ) {
	BLK = 3;
} else
if ( n >= 1345 && n < 2658 ) {
	BLK = 0;
} else
if ( n >= 2658 && n < 3415 ) {
	BLK = 4;
} else
if ( n >= 3415 && n < 4086 ) {
	BLK = 2;
} else
if ( n >= 4086 && n < 4112 ) {
	BLK = 3;
} else
if ( n >= 4112 && n < 4142 ) {
	BLK = 2;
} else
if ( n >= 4142 && n < 4145 ) {
	BLK = 3;
} else
if ( n >= 4145 && n < 75312 ) {
	BLK = 1;
} else
if ( n >= 75312 && n < 78956 ) {
	BLK = 2;
} else
if ( n >= 78956 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
