#ifndef DSYMVU_AUTO2_H_INCLUDED
#define DSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Tue Sep 29 15:29:33  2026
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

if ( n >= 1 && n < 5 ) {
	BLK = 2;
} else
if ( n >= 5 && n < 4261 ) {
	BLK = 0;
} else
if ( n >= 4261 && n < 4962 ) {
	BLK = 1;
} else
if ( n >= 4962 && n < 4980 ) {
	BLK = 5;
} else
if ( n >= 4980 && n < 4988 ) {
	BLK = 0;
} else
if ( n >= 4988 && n < 5069 ) {
	BLK = 1;
} else
if ( n >= 5069 && n < 8179 ) {
	BLK = 5;
} else
if ( n >= 8179 && n < 71535 ) {
	BLK = 2;
} else
if ( n >= 71535 && n < 74001 ) {
	BLK = 4;
} else
if ( n >= 74001 && n < 80211 ) {
	BLK = 2;
} else
if ( n >= 80211 && n < 83274 ) {
	BLK = 4;
} else
if ( n >= 83274 && n < 86764 ) {
	BLK = 2;
} else
if ( n >= 86764 && n < 90389 ) {
	BLK = 4;
} else
if ( n >= 90389 && n < 93585 ) {
	BLK = 2;
} else
if ( n >= 93585 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
