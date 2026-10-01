#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Sun Sep 27 01:12:01  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 1200
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 181 ) {
	BLK = 0;
} else
if ( n >= 181 && n < 182 ) {
	BLK = 5;
} else
if ( n >= 182 && n < 186 ) {
	BLK = 4;
} else
if ( n >= 186 && n < 188 ) {
	BLK = 3;
} else
if ( n >= 188 && n < 193 ) {
	BLK = 0;
} else
if ( n >= 193 && n < 196 ) {
	BLK = 2;
} else
if ( n >= 196 && n < 202 ) {
	BLK = 4;
} else
if ( n >= 202 && n < 203 ) {
	BLK = 3;
} else
if ( n >= 203 && n < 207 ) {
	BLK = 0;
} else
if ( n >= 207 && n < 214 ) {
	BLK = 4;
} else
if ( n >= 214 && n < 226 ) {
	BLK = 0;
} else
if ( n >= 226 && n < 229 ) {
	BLK = 2;
} else
if ( n >= 229 && n < 481 ) {
	BLK = 4;
} else
if ( n >= 481 && n < 540 ) {
	BLK = 5;
} else
if ( n >= 540 && n < 570 ) {
	BLK = 0;
} else
if ( n >= 570 && n < 571 ) {
	BLK = 4;
} else
if ( n >= 571 && n < 704 ) {
	BLK = 5;
} else
if ( n >= 704 && n < 1097 ) {
	BLK = 0;
} else
if ( n >= 1097 && n < 1098 ) {
	BLK = 1;
} else
if ( n >= 1098 && n < 1099 ) {
	BLK = 5;
} else
if ( n >= 1099 && n < 1103 ) {
	BLK = 0;
} else
if ( n >= 1103 && n < 1107 ) {
	BLK = 1;
} else
if ( n >= 1107 && n < 1108 ) {
	BLK = 0;
} else
if ( n >= 1108 && n < 1110 ) {
	BLK = 5;
} else
if ( n >= 1110 && n < 1154 ) {
	BLK = 1;
} else
if ( n >= 1154 && n < 1643 ) {
	BLK = 0;
} else
if ( n >= 1643 && n < 3859 ) {
	BLK = 1;
} else
if ( n >= 3859 && n < 6346 ) {
	BLK = 5;
} else
if ( n >= 6346 && n < 7248 ) {
	BLK = 1;
} else
if ( n >= 7248 && n < 10257 ) {
	BLK = 3;
} else
if ( n >= 10257 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
