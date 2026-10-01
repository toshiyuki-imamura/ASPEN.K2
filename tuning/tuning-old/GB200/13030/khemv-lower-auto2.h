#ifndef KHEMVL_AUTO2_H_INCLUDED
#define KHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVL
 Thu Oct 01 13:31:58  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 8849 ) {
	BLK = 0;
} else
if ( n >= 8849 && n < 9695 ) {
	BLK = 5;
} else
if ( n >= 9695 && n < 10461 ) {
	BLK = 0;
} else
if ( n >= 10461 && n < 14102 ) {
	BLK = 5;
} else
if ( n >= 14102 && n < 28812 ) {
	BLK = 3;
} else
if ( n >= 28812 && n < 30831 ) {
	BLK = 4;
} else
if ( n >= 30831 && n < 45395 ) {
	BLK = 3;
} else
if ( n >= 45395 && n < 46948 ) {
	BLK = 4;
} else
if ( n >= 46948 && n < 53478 ) {
	BLK = 3;
} else
if ( n >= 53478 && n < 55637 ) {
	BLK = 4;
} else
if ( n >= 55637 && n < 83657 ) {
	BLK = 3;
} else
if ( n >= 83657 && n < 90196 ) {
	BLK = 4;
} else
if ( n >= 90196 && n < 94778 ) {
	BLK = 3;
} else
if ( n >= 94778 && n < 97872 ) {
	BLK = 4;
} else
if ( n >= 97872 && n < 106946 ) {
	BLK = 3;
} else
if ( n >= 106946 && n < 110504 ) {
	BLK = 4;
} else
if ( n >= 110504 && n < 127543 ) {
	BLK = 3;
} else
if ( n >= 127543 && n < 131681 ) {
	BLK = 4;
} else
if ( n >= 131681 && n < 137962 ) {
	BLK = 3;
} else
if ( n >= 137962 && n < 150462 ) {
	BLK = 4;
} else
if ( n >= 150462 && n < 164428 ) {
	BLK = 3;
} else
if ( n >= 164428 && n < 171726 ) {
	BLK = 4;
} else
if ( n >= 171726 && n < 178904 ) {
	BLK = 3;
} else
if ( n >= 178904 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
