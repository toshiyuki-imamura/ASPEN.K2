#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Thu Jul 30 09:44:12  2026
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16743747584
// capacity of the work area reserved on the GPU
WORK= 2534400
// for double or cuFloatComplex or int64
MAXDIM= 43461
// for float or cuHalfComplex or int32
MAXDIM2= 61463
// for cuDoubleComplex or DD or int128
MAXDIM3= 30731
// for DD-Complex
MAXDIM4= 21730
// for half or int16
MAXDIM5= 86923
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 4;
} else
if ( n >= 2 && n < 4 ) {
	BLK = 2;
} else
if ( n >= 4 && n < 7 ) {
	BLK = 5;
} else
if ( n >= 7 && n < 13 ) {
	BLK = 3;
} else
if ( n >= 13 && n < 15 ) {
	BLK = 4;
} else
if ( n >= 15 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 24 ) {
	BLK = 5;
} else
if ( n >= 24 && n < 27 ) {
	BLK = 1;
} else
if ( n >= 27 && n < 28 ) {
	BLK = 2;
} else
if ( n >= 28 && n < 30 ) {
	BLK = 4;
} else
if ( n >= 30 && n < 168 ) {
	BLK = 5;
} else
if ( n >= 168 && n < 169 ) {
	BLK = 2;
} else
if ( n >= 169 && n < 175 ) {
	BLK = 4;
} else
if ( n >= 175 && n < 176 ) {
	BLK = 1;
} else
if ( n >= 176 && n < 177 ) {
	BLK = 3;
} else
if ( n >= 177 && n < 192 ) {
	BLK = 4;
} else
if ( n >= 192 && n < 258 ) {
	BLK = 1;
} else
if ( n >= 258 && n < 259 ) {
	BLK = 5;
} else
if ( n >= 259 && n < 260 ) {
	BLK = 4;
} else
if ( n >= 260 && n < 273 ) {
	BLK = 1;
} else
if ( n >= 273 && n < 274 ) {
	BLK = 4;
} else
if ( n >= 274 && n < 281 ) {
	BLK = 5;
} else
if ( n >= 281 && n < 288 ) {
	BLK = 4;
} else
if ( n >= 288 && n < 298 ) {
	BLK = 1;
} else
if ( n >= 298 && n < 367 ) {
	BLK = 5;
} else
if ( n >= 367 && n < 376 ) {
	BLK = 4;
} else
if ( n >= 376 && n < 377 ) {
	BLK = 2;
} else
if ( n >= 377 && n < 382 ) {
	BLK = 3;
} else
if ( n >= 382 && n < 512 ) {
	BLK = 2;
} else
if ( n >= 512 && n < 2807 ) {
	BLK = 4;
} else
if ( n >= 2807 && n < 4177 ) {
	BLK = 2;
} else
if ( n >= 4177 && n < 4435 ) {
	BLK = 1;
} else
if ( n >= 4435 && n < 4699 ) {
	BLK = 2;
} else
if ( n >= 4699 && n < 4864 ) {
	BLK = 1;
} else
if ( n >= 4864 && n < 4939 ) {
	BLK = 5;
} else
if ( n >= 4939 && n < 12095 ) {
	BLK = 1;
} else
if ( n >= 12095 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
