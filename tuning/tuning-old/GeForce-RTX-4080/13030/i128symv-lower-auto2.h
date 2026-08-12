#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Wed Jul 29 02:56:39  2026
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


// default kernel is
BLK = 1;

if ( n >= 1 && n < 5 ) {
	BLK = 1;
} else
if ( n >= 5 && n < 12 ) {
	BLK = 3;
} else
if ( n >= 12 && n < 19 ) {
	BLK = 2;
} else
if ( n >= 19 && n < 28 ) {
	BLK = 3;
} else
if ( n >= 28 && n < 29 ) {
	BLK = 1;
} else
if ( n >= 29 && n < 30 ) {
	BLK = 2;
} else
if ( n >= 30 && n < 38 ) {
	BLK = 3;
} else
if ( n >= 38 && n < 51 ) {
	BLK = 2;
} else
if ( n >= 51 && n < 54 ) {
	BLK = 1;
} else
if ( n >= 54 && n < 55 ) {
	BLK = 3;
} else
if ( n >= 55 && n < 58 ) {
	BLK = 2;
} else
if ( n >= 58 && n < 59 ) {
	BLK = 1;
} else
if ( n >= 59 && n < 61 ) {
	BLK = 3;
} else
if ( n >= 61 && n < 64 ) {
	BLK = 2;
} else
if ( n >= 64 && n < 65 ) {
	BLK = 1;
} else
if ( n >= 65 && n < 68 ) {
	BLK = 3;
} else
if ( n >= 68 && n < 74 ) {
	BLK = 2;
} else
if ( n >= 74 && n < 79 ) {
	BLK = 3;
} else
if ( n >= 79 && n < 80 ) {
	BLK = 1;
} else
if ( n >= 80 && n < 88 ) {
	BLK = 2;
} else
if ( n >= 88 && n < 89 ) {
	BLK = 3;
} else
if ( n >= 89 && n < 90 ) {
	BLK = 1;
} else
if ( n >= 90 && n < 93 ) {
	BLK = 2;
} else
if ( n >= 93 && n < 94 ) {
	BLK = 1;
} else
if ( n >= 94 && n < 105 ) {
	BLK = 3;
} else
if ( n >= 105 && n < 106 ) {
	BLK = 1;
} else
if ( n >= 106 && n < 107 ) {
	BLK = 2;
} else
if ( n >= 107 && n < 111 ) {
	BLK = 3;
} else
if ( n >= 111 && n < 112 ) {
	BLK = 2;
} else
if ( n >= 112 && n < 114 ) {
	BLK = 1;
} else
if ( n >= 114 && n < 115 ) {
	BLK = 3;
} else
if ( n >= 115 && n < 116 ) {
	BLK = 2;
} else
if ( n >= 116 && n < 118 ) {
	BLK = 1;
} else
if ( n >= 118 && n < 122 ) {
	BLK = 3;
} else
if ( n >= 122 && n < 126 ) {
	BLK = 2;
} else
if ( n >= 126 && n < 160 ) {
	BLK = 3;
} else
if ( n >= 160 && n < 161 ) {
	BLK = 1;
} else
if ( n >= 161 && n < 164 ) {
	BLK = 2;
} else
if ( n >= 164 && n < 165 ) {
	BLK = 3;
} else
if ( n >= 165 && n < 193 ) {
	BLK = 1;
} else
if ( n >= 193 && n < 201 ) {
	BLK = 2;
} else
if ( n >= 201 && n < 203 ) {
	BLK = 1;
} else
if ( n >= 203 && n < 204 ) {
	BLK = 3;
} else
if ( n >= 204 && n < 254 ) {
	BLK = 2;
} else
if ( n >= 254 && n < 325 ) {
	BLK = 1;
} else
if ( n >= 325 && n < 326 ) {
	BLK = 2;
} else
if ( n >= 326 && n < 334 ) {
	BLK = 3;
} else
if ( n >= 334 && n < 337 ) {
	BLK = 2;
} else
if ( n >= 337 && n < 343 ) {
	BLK = 3;
} else
if ( n >= 343 && n < 364 ) {
	BLK = 1;
} else
if ( n >= 364 && n < 373 ) {
	BLK = 3;
} else
if ( n >= 373 && n < 377 ) {
	BLK = 1;
} else
if ( n >= 377 && n < 383 ) {
	BLK = 3;
} else
if ( n >= 383 && n < 406 ) {
	BLK = 1;
} else
if ( n >= 406 && n < 414 ) {
	BLK = 3;
} else
if ( n >= 414 && n < 415 ) {
	BLK = 1;
} else
if ( n >= 415 && n < 416 ) {
	BLK = 2;
} else
if ( n >= 416 && n < 459 ) {
	BLK = 3;
} else
if ( n >= 459 && n < 494 ) {
	BLK = 1;
} else
if ( n >= 494 && n < 495 ) {
	BLK = 2;
} else
if ( n >= 495 && n < 506 ) {
	BLK = 3;
} else
if ( n >= 506 && n < 507 ) {
	BLK = 2;
} else
if ( n >= 507 && n < 508 ) {
	BLK = 1;
} else
if ( n >= 508 && n < 743 ) {
	BLK = 3;
} else
if ( n >= 743 && n < 746 ) {
	BLK = 2;
} else
if ( n >= 746 && n < 747 ) {
	BLK = 3;
} else
if ( n >= 747 && n < 748 ) {
	BLK = 1;
} else
if ( n >= 748 && n < 1920 ) {
	BLK = 2;
} else
if ( n >= 1920 && n < 2864 ) {
	BLK = 1;
} else
if ( n >= 2864 && n < 2915 ) {
	BLK = 2;
} else
if ( n >= 2915 && n < 4300 ) {
	BLK = 3;
} else
if ( n >= 4300 && n < 5602 ) {
	BLK = 2;
} else
if ( n >= 5602 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
