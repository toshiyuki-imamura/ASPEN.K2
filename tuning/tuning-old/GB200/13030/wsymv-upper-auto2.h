#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Tue Sep 29 13:22:06  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3 ) {
	BLK = 0;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 5;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 3;
} else
if ( n >= 5 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 10 ) {
	BLK = 5;
} else
if ( n >= 10 && n < 2710 ) {
	BLK = 0;
} else
if ( n >= 2710 && n < 3299 ) {
	BLK = 1;
} else
if ( n >= 3299 && n < 3300 ) {
	BLK = 5;
} else
if ( n >= 3300 && n < 3311 ) {
	BLK = 2;
} else
if ( n >= 3311 && n < 3387 ) {
	BLK = 1;
} else
if ( n >= 3387 && n < 3390 ) {
	BLK = 5;
} else
if ( n >= 3390 && n < 3443 ) {
	BLK = 1;
} else
if ( n >= 3443 && n < 3473 ) {
	BLK = 2;
} else
if ( n >= 3473 && n < 3476 ) {
	BLK = 1;
} else
if ( n >= 3476 && n < 3478 ) {
	BLK = 5;
} else
if ( n >= 3478 && n < 3479 ) {
	BLK = 2;
} else
if ( n >= 3479 && n < 3485 ) {
	BLK = 1;
} else
if ( n >= 3485 && n < 3489 ) {
	BLK = 5;
} else
if ( n >= 3489 && n < 3495 ) {
	BLK = 2;
} else
if ( n >= 3495 && n < 3496 ) {
	BLK = 1;
} else
if ( n >= 3496 && n < 3504 ) {
	BLK = 5;
} else
if ( n >= 3504 && n < 3519 ) {
	BLK = 2;
} else
if ( n >= 3519 && n < 3520 ) {
	BLK = 5;
} else
if ( n >= 3520 && n < 3521 ) {
	BLK = 1;
} else
if ( n >= 3521 && n < 3527 ) {
	BLK = 2;
} else
if ( n >= 3527 && n < 3532 ) {
	BLK = 5;
} else
if ( n >= 3532 && n < 7803 ) {
	BLK = 2;
} else
if ( n >= 7803 && n < 2147483647 ) {
	BLK = 0;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 0;
} 

#endif
