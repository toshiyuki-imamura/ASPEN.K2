#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Wed Sep 30 23:08:30  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 11 ) {
	BLK = 4;
} else
if ( n >= 11 && n < 18 ) {
	BLK = 3;
} else
if ( n >= 18 && n < 21 ) {
	BLK = 4;
} else
if ( n >= 21 && n < 29 ) {
	BLK = 1;
} else
if ( n >= 29 && n < 32 ) {
	BLK = 3;
} else
if ( n >= 32 && n < 33 ) {
	BLK = 5;
} else
if ( n >= 33 && n < 51 ) {
	BLK = 1;
} else
if ( n >= 51 && n < 62 ) {
	BLK = 4;
} else
if ( n >= 62 && n < 63 ) {
	BLK = 1;
} else
if ( n >= 63 && n < 64 ) {
	BLK = 5;
} else
if ( n >= 64 && n < 68 ) {
	BLK = 4;
} else
if ( n >= 68 && n < 95 ) {
	BLK = 1;
} else
if ( n >= 95 && n < 98 ) {
	BLK = 5;
} else
if ( n >= 98 && n < 99 ) {
	BLK = 4;
} else
if ( n >= 99 && n < 114 ) {
	BLK = 1;
} else
if ( n >= 114 && n < 118 ) {
	BLK = 4;
} else
if ( n >= 118 && n < 119 ) {
	BLK = 5;
} else
if ( n >= 119 && n < 131 ) {
	BLK = 1;
} else
if ( n >= 131 && n < 133 ) {
	BLK = 5;
} else
if ( n >= 133 && n < 134 ) {
	BLK = 4;
} else
if ( n >= 134 && n < 137 ) {
	BLK = 1;
} else
if ( n >= 137 && n < 138 ) {
	BLK = 4;
} else
if ( n >= 138 && n < 140 ) {
	BLK = 5;
} else
if ( n >= 140 && n < 144 ) {
	BLK = 1;
} else
if ( n >= 144 && n < 147 ) {
	BLK = 5;
} else
if ( n >= 147 && n < 153 ) {
	BLK = 4;
} else
if ( n >= 153 && n < 176 ) {
	BLK = 1;
} else
if ( n >= 176 && n < 191 ) {
	BLK = 5;
} else
if ( n >= 191 && n < 531 ) {
	BLK = 1;
} else
if ( n >= 531 && n < 539 ) {
	BLK = 5;
} else
if ( n >= 539 && n < 646 ) {
	BLK = 1;
} else
if ( n >= 646 && n < 647 ) {
	BLK = 5;
} else
if ( n >= 647 && n < 652 ) {
	BLK = 4;
} else
if ( n >= 652 && n < 712 ) {
	BLK = 1;
} else
if ( n >= 712 && n < 713 ) {
	BLK = 5;
} else
if ( n >= 713 && n < 714 ) {
	BLK = 4;
} else
if ( n >= 714 && n < 736 ) {
	BLK = 1;
} else
if ( n >= 736 && n < 738 ) {
	BLK = 4;
} else
if ( n >= 738 && n < 2659 ) {
	BLK = 5;
} else
if ( n >= 2659 && n < 3175 ) {
	BLK = 1;
} else
if ( n >= 3175 && n < 3176 ) {
	BLK = 5;
} else
if ( n >= 3176 && n < 3177 ) {
	BLK = 3;
} else
if ( n >= 3177 && n < 3579 ) {
	BLK = 1;
} else
if ( n >= 3579 && n < 6349 ) {
	BLK = 3;
} else
if ( n >= 6349 && n < 13623 ) {
	BLK = 4;
} else
if ( n >= 13623 && n < 87292 ) {
	BLK = 2;
} else
if ( n >= 87292 && n < 93753 ) {
	BLK = 4;
} else
if ( n >= 93753 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
