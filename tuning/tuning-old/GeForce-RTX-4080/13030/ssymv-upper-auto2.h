#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Mon Jul 27 12:20:20  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3 ) {
	BLK = 0;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 2;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 1;
} else
if ( n >= 5 && n < 10 ) {
	BLK = 0;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 12 ) {
	BLK = 2;
} else
if ( n >= 12 && n < 49 ) {
	BLK = 0;
} else
if ( n >= 49 && n < 50 ) {
	BLK = 2;
} else
if ( n >= 50 && n < 51 ) {
	BLK = 3;
} else
if ( n >= 51 && n < 57 ) {
	BLK = 0;
} else
if ( n >= 57 && n < 58 ) {
	BLK = 2;
} else
if ( n >= 58 && n < 69 ) {
	BLK = 1;
} else
if ( n >= 69 && n < 75 ) {
	BLK = 0;
} else
if ( n >= 75 && n < 76 ) {
	BLK = 2;
} else
if ( n >= 76 && n < 77 ) {
	BLK = 3;
} else
if ( n >= 77 && n < 108 ) {
	BLK = 0;
} else
if ( n >= 108 && n < 109 ) {
	BLK = 1;
} else
if ( n >= 109 && n < 110 ) {
	BLK = 3;
} else
if ( n >= 110 && n < 147 ) {
	BLK = 0;
} else
if ( n >= 147 && n < 148 ) {
	BLK = 2;
} else
if ( n >= 148 && n < 149 ) {
	BLK = 1;
} else
if ( n >= 149 && n < 150 ) {
	BLK = 3;
} else
if ( n >= 150 && n < 193 ) {
	BLK = 0;
} else
if ( n >= 193 && n < 195 ) {
	BLK = 3;
} else
if ( n >= 195 && n < 199 ) {
	BLK = 1;
} else
if ( n >= 199 && n < 203 ) {
	BLK = 3;
} else
if ( n >= 203 && n < 204 ) {
	BLK = 1;
} else
if ( n >= 204 && n < 208 ) {
	BLK = 0;
} else
if ( n >= 208 && n < 209 ) {
	BLK = 2;
} else
if ( n >= 209 && n < 215 ) {
	BLK = 1;
} else
if ( n >= 215 && n < 244 ) {
	BLK = 0;
} else
if ( n >= 244 && n < 245 ) {
	BLK = 2;
} else
if ( n >= 245 && n < 246 ) {
	BLK = 1;
} else
if ( n >= 246 && n < 247 ) {
	BLK = 0;
} else
if ( n >= 247 && n < 248 ) {
	BLK = 2;
} else
if ( n >= 248 && n < 254 ) {
	BLK = 1;
} else
if ( n >= 254 && n < 255 ) {
	BLK = 3;
} else
if ( n >= 255 && n < 256 ) {
	BLK = 2;
} else
if ( n >= 256 && n < 260 ) {
	BLK = 0;
} else
if ( n >= 260 && n < 261 ) {
	BLK = 1;
} else
if ( n >= 261 && n < 262 ) {
	BLK = 3;
} else
if ( n >= 262 && n < 277 ) {
	BLK = 0;
} else
if ( n >= 277 && n < 278 ) {
	BLK = 1;
} else
if ( n >= 278 && n < 279 ) {
	BLK = 3;
} else
if ( n >= 279 && n < 280 ) {
	BLK = 0;
} else
if ( n >= 280 && n < 287 ) {
	BLK = 1;
} else
if ( n >= 287 && n < 290 ) {
	BLK = 0;
} else
if ( n >= 290 && n < 291 ) {
	BLK = 3;
} else
if ( n >= 291 && n < 302 ) {
	BLK = 1;
} else
if ( n >= 302 && n < 303 ) {
	BLK = 3;
} else
if ( n >= 303 && n < 311 ) {
	BLK = 0;
} else
if ( n >= 311 && n < 312 ) {
	BLK = 3;
} else
if ( n >= 312 && n < 316 ) {
	BLK = 1;
} else
if ( n >= 316 && n < 346 ) {
	BLK = 0;
} else
if ( n >= 346 && n < 347 ) {
	BLK = 2;
} else
if ( n >= 347 && n < 354 ) {
	BLK = 1;
} else
if ( n >= 354 && n < 355 ) {
	BLK = 3;
} else
if ( n >= 355 && n < 372 ) {
	BLK = 0;
} else
if ( n >= 372 && n < 378 ) {
	BLK = 1;
} else
if ( n >= 378 && n < 379 ) {
	BLK = 2;
} else
if ( n >= 379 && n < 385 ) {
	BLK = 0;
} else
if ( n >= 385 && n < 386 ) {
	BLK = 3;
} else
if ( n >= 386 && n < 393 ) {
	BLK = 1;
} else
if ( n >= 393 && n < 394 ) {
	BLK = 0;
} else
if ( n >= 394 && n < 398 ) {
	BLK = 2;
} else
if ( n >= 398 && n < 403 ) {
	BLK = 1;
} else
if ( n >= 403 && n < 404 ) {
	BLK = 0;
} else
if ( n >= 404 && n < 407 ) {
	BLK = 3;
} else
if ( n >= 407 && n < 421 ) {
	BLK = 0;
} else
if ( n >= 421 && n < 460 ) {
	BLK = 1;
} else
if ( n >= 460 && n < 465 ) {
	BLK = 3;
} else
if ( n >= 465 && n < 466 ) {
	BLK = 1;
} else
if ( n >= 466 && n < 467 ) {
	BLK = 0;
} else
if ( n >= 467 && n < 468 ) {
	BLK = 2;
} else
if ( n >= 468 && n < 470 ) {
	BLK = 1;
} else
if ( n >= 470 && n < 474 ) {
	BLK = 0;
} else
if ( n >= 474 && n < 475 ) {
	BLK = 1;
} else
if ( n >= 475 && n < 476 ) {
	BLK = 3;
} else
if ( n >= 476 && n < 498 ) {
	BLK = 0;
} else
if ( n >= 498 && n < 500 ) {
	BLK = 1;
} else
if ( n >= 500 && n < 501 ) {
	BLK = 2;
} else
if ( n >= 501 && n < 502 ) {
	BLK = 3;
} else
if ( n >= 502 && n < 504 ) {
	BLK = 1;
} else
if ( n >= 504 && n < 529 ) {
	BLK = 0;
} else
if ( n >= 529 && n < 530 ) {
	BLK = 1;
} else
if ( n >= 530 && n < 533 ) {
	BLK = 2;
} else
if ( n >= 533 && n < 545 ) {
	BLK = 0;
} else
if ( n >= 545 && n < 546 ) {
	BLK = 2;
} else
if ( n >= 546 && n < 594 ) {
	BLK = 1;
} else
if ( n >= 594 && n < 595 ) {
	BLK = 2;
} else
if ( n >= 595 && n < 596 ) {
	BLK = 0;
} else
if ( n >= 596 && n < 597 ) {
	BLK = 1;
} else
if ( n >= 597 && n < 598 ) {
	BLK = 2;
} else
if ( n >= 598 && n < 621 ) {
	BLK = 0;
} else
if ( n >= 621 && n < 622 ) {
	BLK = 2;
} else
if ( n >= 622 && n < 642 ) {
	BLK = 1;
} else
if ( n >= 642 && n < 643 ) {
	BLK = 0;
} else
if ( n >= 643 && n < 650 ) {
	BLK = 2;
} else
if ( n >= 650 && n < 769 ) {
	BLK = 1;
} else
if ( n >= 769 && n < 770 ) {
	BLK = 0;
} else
if ( n >= 770 && n < 771 ) {
	BLK = 3;
} else
if ( n >= 771 && n < 901 ) {
	BLK = 1;
} else
if ( n >= 901 && n < 905 ) {
	BLK = 0;
} else
if ( n >= 905 && n < 906 ) {
	BLK = 2;
} else
if ( n >= 906 && n < 922 ) {
	BLK = 1;
} else
if ( n >= 922 && n < 923 ) {
	BLK = 2;
} else
if ( n >= 923 && n < 1007 ) {
	BLK = 0;
} else
if ( n >= 1007 && n < 1008 ) {
	BLK = 2;
} else
if ( n >= 1008 && n < 1031 ) {
	BLK = 1;
} else
if ( n >= 1031 && n < 1032 ) {
	BLK = 2;
} else
if ( n >= 1032 && n < 1034 ) {
	BLK = 0;
} else
if ( n >= 1034 && n < 1037 ) {
	BLK = 1;
} else
if ( n >= 1037 && n < 1042 ) {
	BLK = 2;
} else
if ( n >= 1042 && n < 1090 ) {
	BLK = 0;
} else
if ( n >= 1090 && n < 1091 ) {
	BLK = 2;
} else
if ( n >= 1091 && n < 1210 ) {
	BLK = 1;
} else
if ( n >= 1210 && n < 2644 ) {
	BLK = 0;
} else
if ( n >= 2644 && n < 5029 ) {
	BLK = 2;
} else
if ( n >= 5029 && n < 5065 ) {
	BLK = 0;
} else
if ( n >= 5065 && n < 5163 ) {
	BLK = 1;
} else
if ( n >= 5163 && n < 5171 ) {
	BLK = 0;
} else
if ( n >= 5171 && n < 5249 ) {
	BLK = 2;
} else
if ( n >= 5249 && n < 5266 ) {
	BLK = 1;
} else
if ( n >= 5266 && n < 5280 ) {
	BLK = 0;
} else
if ( n >= 5280 && n < 5370 ) {
	BLK = 2;
} else
if ( n >= 5370 && n < 5444 ) {
	BLK = 1;
} else
if ( n >= 5444 && n < 6398 ) {
	BLK = 0;
} else
if ( n >= 6398 && n < 11008 ) {
	BLK = 1;
} else
if ( n >= 11008 && n < 16102 ) {
	BLK = 2;
} else
if ( n >= 16102 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
