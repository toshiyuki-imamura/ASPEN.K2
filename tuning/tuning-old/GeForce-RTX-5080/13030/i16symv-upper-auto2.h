#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Thu Aug 06 16:48:26  2026
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
MAXmem= 16647024640
// capacity of the work area reserved on the GPU
WORK= 2526720
// for double or cuFloatComplex or int64
MAXDIM= 43335
// for float or cuHalfComplex or int32
MAXDIM2= 61286
// for cuDoubleComplex or DD or int128
MAXDIM3= 30643
// for DD-Complex
MAXDIM4= 21667
// for half or int16
MAXDIM5= 86671
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
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

if ( n >= 1 && n < 379 ) {
	BLK = 0;
} else
if ( n >= 379 && n < 381 ) {
	BLK = 2;
} else
if ( n >= 381 && n < 382 ) {
	BLK = 3;
} else
if ( n >= 382 && n < 395 ) {
	BLK = 0;
} else
if ( n >= 395 && n < 396 ) {
	BLK = 4;
} else
if ( n >= 396 && n < 397 ) {
	BLK = 3;
} else
if ( n >= 397 && n < 412 ) {
	BLK = 0;
} else
if ( n >= 412 && n < 416 ) {
	BLK = 2;
} else
if ( n >= 416 && n < 427 ) {
	BLK = 0;
} else
if ( n >= 427 && n < 431 ) {
	BLK = 3;
} else
if ( n >= 431 && n < 442 ) {
	BLK = 0;
} else
if ( n >= 442 && n < 445 ) {
	BLK = 2;
} else
if ( n >= 445 && n < 446 ) {
	BLK = 1;
} else
if ( n >= 446 && n < 481 ) {
	BLK = 0;
} else
if ( n >= 481 && n < 484 ) {
	BLK = 1;
} else
if ( n >= 484 && n < 485 ) {
	BLK = 2;
} else
if ( n >= 485 && n < 488 ) {
	BLK = 0;
} else
if ( n >= 488 && n < 502 ) {
	BLK = 2;
} else
if ( n >= 502 && n < 503 ) {
	BLK = 1;
} else
if ( n >= 503 && n < 508 ) {
	BLK = 3;
} else
if ( n >= 508 && n < 509 ) {
	BLK = 4;
} else
if ( n >= 509 && n < 512 ) {
	BLK = 1;
} else
if ( n >= 512 && n < 521 ) {
	BLK = 3;
} else
if ( n >= 521 && n < 528 ) {
	BLK = 4;
} else
if ( n >= 528 && n < 529 ) {
	BLK = 5;
} else
if ( n >= 529 && n < 534 ) {
	BLK = 2;
} else
if ( n >= 534 && n < 541 ) {
	BLK = 1;
} else
if ( n >= 541 && n < 542 ) {
	BLK = 4;
} else
if ( n >= 542 && n < 562 ) {
	BLK = 2;
} else
if ( n >= 562 && n < 564 ) {
	BLK = 1;
} else
if ( n >= 564 && n < 565 ) {
	BLK = 0;
} else
if ( n >= 565 && n < 570 ) {
	BLK = 2;
} else
if ( n >= 570 && n < 571 ) {
	BLK = 4;
} else
if ( n >= 571 && n < 572 ) {
	BLK = 3;
} else
if ( n >= 572 && n < 589 ) {
	BLK = 1;
} else
if ( n >= 589 && n < 1236 ) {
	BLK = 2;
} else
if ( n >= 1236 && n < 1255 ) {
	BLK = 0;
} else
if ( n >= 1255 && n < 1256 ) {
	BLK = 2;
} else
if ( n >= 1256 && n < 1361 ) {
	BLK = 1;
} else
if ( n >= 1361 && n < 1363 ) {
	BLK = 0;
} else
if ( n >= 1363 && n < 1977 ) {
	BLK = 2;
} else
if ( n >= 1977 && n < 3267 ) {
	BLK = 1;
} else
if ( n >= 3267 && n < 3268 ) {
	BLK = 3;
} else
if ( n >= 3268 && n < 3269 ) {
	BLK = 5;
} else
if ( n >= 3269 && n < 4355 ) {
	BLK = 1;
} else
if ( n >= 4355 && n < 6115 ) {
	BLK = 3;
} else
if ( n >= 6115 && n < 8133 ) {
	BLK = 5;
} else
if ( n >= 8133 && n < 12985 ) {
	BLK = 1;
} else
if ( n >= 12985 && n < 23175 ) {
	BLK = 2;
} else
if ( n >= 23175 && n < 24369 ) {
	BLK = 4;
} else
if ( n >= 24369 && n < 25366 ) {
	BLK = 2;
} else
if ( n >= 25366 && n < 28103 ) {
	BLK = 4;
} else
if ( n >= 28103 && n < 28788 ) {
	BLK = 2;
} else
if ( n >= 28788 && n < 29621 ) {
	BLK = 4;
} else
if ( n >= 29621 && n < 30360 ) {
	BLK = 2;
} else
if ( n >= 30360 && n < 31387 ) {
	BLK = 4;
} else
if ( n >= 31387 && n < 32452 ) {
	BLK = 2;
} else
if ( n >= 32452 && n < 34478 ) {
	BLK = 4;
} else
if ( n >= 34478 && n < 35208 ) {
	BLK = 2;
} else
if ( n >= 35208 && n < 36438 ) {
	BLK = 4;
} else
if ( n >= 36438 && n < 38262 ) {
	BLK = 2;
} else
if ( n >= 38262 && n < 41246 ) {
	BLK = 4;
} else
if ( n >= 41246 && n < 51659 ) {
	BLK = 2;
} else
if ( n >= 51659 && n < 52530 ) {
	BLK = 4;
} else
if ( n >= 52530 && n < 64211 ) {
	BLK = 2;
} else
if ( n >= 64211 && n < 66076 ) {
	BLK = 4;
} else
if ( n >= 66076 && n < 72626 ) {
	BLK = 2;
} else
if ( n >= 72626 && n < 75963 ) {
	BLK = 4;
} else
if ( n >= 75963 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
