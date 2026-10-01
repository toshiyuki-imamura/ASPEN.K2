#ifndef KHEMVU_AUTO2_H_INCLUDED
#define KHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVU
 Thu Oct 01 04:48:29  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 11582 ) {
	BLK = 0;
} else
if ( n >= 11582 && n < 19364 ) {
	BLK = 3;
} else
if ( n >= 19364 && n < 20082 ) {
	BLK = 4;
} else
if ( n >= 20082 && n < 27033 ) {
	BLK = 3;
} else
if ( n >= 27033 && n < 31201 ) {
	BLK = 4;
} else
if ( n >= 31201 && n < 44793 ) {
	BLK = 3;
} else
if ( n >= 44793 && n < 47982 ) {
	BLK = 4;
} else
if ( n >= 47982 && n < 49502 ) {
	BLK = 3;
} else
if ( n >= 49502 && n < 50425 ) {
	BLK = 4;
} else
if ( n >= 50425 && n < 52566 ) {
	BLK = 3;
} else
if ( n >= 52566 && n < 56089 ) {
	BLK = 4;
} else
if ( n >= 56089 && n < 68931 ) {
	BLK = 3;
} else
if ( n >= 68931 && n < 71085 ) {
	BLK = 4;
} else
if ( n >= 71085 && n < 77201 ) {
	BLK = 3;
} else
if ( n >= 77201 && n < 79875 ) {
	BLK = 4;
} else
if ( n >= 79875 && n < 108098 ) {
	BLK = 3;
} else
if ( n >= 108098 && n < 110452 ) {
	BLK = 4;
} else
if ( n >= 110452 && n < 116233 ) {
	BLK = 3;
} else
if ( n >= 116233 && n < 126424 ) {
	BLK = 4;
} else
if ( n >= 126424 && n < 132001 ) {
	BLK = 3;
} else
if ( n >= 132001 && n < 133651 ) {
	BLK = 4;
} else
if ( n >= 133651 && n < 143962 ) {
	BLK = 3;
} else
if ( n >= 143962 && n < 149639 ) {
	BLK = 4;
} else
if ( n >= 149639 && n < 152319 ) {
	BLK = 3;
} else
if ( n >= 152319 && n < 158282 ) {
	BLK = 4;
} else
if ( n >= 158282 && n < 164304 ) {
	BLK = 3;
} else
if ( n >= 164304 && n < 171919 ) {
	BLK = 4;
} else
if ( n >= 171919 && n < 187815 ) {
	BLK = 3;
} else
if ( n >= 187815 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
