#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Thu Oct 01 08:01:55  2026
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

if ( n >= 1 && n < 2 ) {
	BLK = 3;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 4;
} else
if ( n >= 3 && n < 5 ) {
	BLK = 5;
} else
if ( n >= 5 && n < 6 ) {
	BLK = 2;
} else
if ( n >= 6 && n < 7 ) {
	BLK = 4;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 5;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 2;
} else
if ( n >= 9 && n < 10 ) {
	BLK = 1;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 17 ) {
	BLK = 1;
} else
if ( n >= 17 && n < 18 ) {
	BLK = 4;
} else
if ( n >= 18 && n < 19 ) {
	BLK = 3;
} else
if ( n >= 19 && n < 23 ) {
	BLK = 2;
} else
if ( n >= 23 && n < 24 ) {
	BLK = 3;
} else
if ( n >= 24 && n < 36 ) {
	BLK = 4;
} else
if ( n >= 36 && n < 84 ) {
	BLK = 3;
} else
if ( n >= 84 && n < 87 ) {
	BLK = 2;
} else
if ( n >= 87 && n < 89 ) {
	BLK = 3;
} else
if ( n >= 89 && n < 90 ) {
	BLK = 4;
} else
if ( n >= 90 && n < 233 ) {
	BLK = 2;
} else
if ( n >= 233 && n < 234 ) {
	BLK = 4;
} else
if ( n >= 234 && n < 238 ) {
	BLK = 3;
} else
if ( n >= 238 && n < 264 ) {
	BLK = 2;
} else
if ( n >= 264 && n < 267 ) {
	BLK = 3;
} else
if ( n >= 267 && n < 268 ) {
	BLK = 4;
} else
if ( n >= 268 && n < 271 ) {
	BLK = 2;
} else
if ( n >= 271 && n < 276 ) {
	BLK = 3;
} else
if ( n >= 276 && n < 286 ) {
	BLK = 2;
} else
if ( n >= 286 && n < 287 ) {
	BLK = 4;
} else
if ( n >= 287 && n < 311 ) {
	BLK = 3;
} else
if ( n >= 311 && n < 314 ) {
	BLK = 2;
} else
if ( n >= 314 && n < 315 ) {
	BLK = 4;
} else
if ( n >= 315 && n < 318 ) {
	BLK = 3;
} else
if ( n >= 318 && n < 319 ) {
	BLK = 4;
} else
if ( n >= 319 && n < 325 ) {
	BLK = 2;
} else
if ( n >= 325 && n < 330 ) {
	BLK = 4;
} else
if ( n >= 330 && n < 331 ) {
	BLK = 3;
} else
if ( n >= 331 && n < 345 ) {
	BLK = 2;
} else
if ( n >= 345 && n < 350 ) {
	BLK = 3;
} else
if ( n >= 350 && n < 354 ) {
	BLK = 2;
} else
if ( n >= 354 && n < 361 ) {
	BLK = 3;
} else
if ( n >= 361 && n < 369 ) {
	BLK = 2;
} else
if ( n >= 369 && n < 371 ) {
	BLK = 4;
} else
if ( n >= 371 && n < 390 ) {
	BLK = 3;
} else
if ( n >= 390 && n < 391 ) {
	BLK = 2;
} else
if ( n >= 391 && n < 392 ) {
	BLK = 4;
} else
if ( n >= 392 && n < 416 ) {
	BLK = 3;
} else
if ( n >= 416 && n < 423 ) {
	BLK = 2;
} else
if ( n >= 423 && n < 427 ) {
	BLK = 3;
} else
if ( n >= 427 && n < 450 ) {
	BLK = 2;
} else
if ( n >= 450 && n < 453 ) {
	BLK = 4;
} else
if ( n >= 453 && n < 516 ) {
	BLK = 2;
} else
if ( n >= 516 && n < 517 ) {
	BLK = 3;
} else
if ( n >= 517 && n < 556 ) {
	BLK = 4;
} else
if ( n >= 556 && n < 557 ) {
	BLK = 3;
} else
if ( n >= 557 && n < 571 ) {
	BLK = 2;
} else
if ( n >= 571 && n < 573 ) {
	BLK = 4;
} else
if ( n >= 573 && n < 575 ) {
	BLK = 3;
} else
if ( n >= 575 && n < 585 ) {
	BLK = 2;
} else
if ( n >= 585 && n < 586 ) {
	BLK = 4;
} else
if ( n >= 586 && n < 587 ) {
	BLK = 3;
} else
if ( n >= 587 && n < 606 ) {
	BLK = 2;
} else
if ( n >= 606 && n < 611 ) {
	BLK = 3;
} else
if ( n >= 611 && n < 612 ) {
	BLK = 4;
} else
if ( n >= 612 && n < 614 ) {
	BLK = 2;
} else
if ( n >= 614 && n < 620 ) {
	BLK = 3;
} else
if ( n >= 620 && n < 624 ) {
	BLK = 4;
} else
if ( n >= 624 && n < 625 ) {
	BLK = 2;
} else
if ( n >= 625 && n < 628 ) {
	BLK = 3;
} else
if ( n >= 628 && n < 647 ) {
	BLK = 4;
} else
if ( n >= 647 && n < 659 ) {
	BLK = 2;
} else
if ( n >= 659 && n < 660 ) {
	BLK = 3;
} else
if ( n >= 660 && n < 678 ) {
	BLK = 4;
} else
if ( n >= 678 && n < 709 ) {
	BLK = 2;
} else
if ( n >= 709 && n < 710 ) {
	BLK = 4;
} else
if ( n >= 710 && n < 711 ) {
	BLK = 3;
} else
if ( n >= 711 && n < 767 ) {
	BLK = 2;
} else
if ( n >= 767 && n < 768 ) {
	BLK = 3;
} else
if ( n >= 768 && n < 783 ) {
	BLK = 4;
} else
if ( n >= 783 && n < 787 ) {
	BLK = 2;
} else
if ( n >= 787 && n < 788 ) {
	BLK = 3;
} else
if ( n >= 788 && n < 966 ) {
	BLK = 4;
} else
if ( n >= 966 && n < 998 ) {
	BLK = 3;
} else
if ( n >= 998 && n < 999 ) {
	BLK = 2;
} else
if ( n >= 999 && n < 1001 ) {
	BLK = 4;
} else
if ( n >= 1001 && n < 1021 ) {
	BLK = 3;
} else
if ( n >= 1021 && n < 1063 ) {
	BLK = 4;
} else
if ( n >= 1063 && n < 1076 ) {
	BLK = 2;
} else
if ( n >= 1076 && n < 1077 ) {
	BLK = 4;
} else
if ( n >= 1077 && n < 1079 ) {
	BLK = 3;
} else
if ( n >= 1079 && n < 1089 ) {
	BLK = 2;
} else
if ( n >= 1089 && n < 1145 ) {
	BLK = 4;
} else
if ( n >= 1145 && n < 1146 ) {
	BLK = 2;
} else
if ( n >= 1146 && n < 1153 ) {
	BLK = 3;
} else
if ( n >= 1153 && n < 1535 ) {
	BLK = 4;
} else
if ( n >= 1535 && n < 1536 ) {
	BLK = 2;
} else
if ( n >= 1536 && n < 1561 ) {
	BLK = 3;
} else
if ( n >= 1561 && n < 1806 ) {
	BLK = 4;
} else
if ( n >= 1806 && n < 1816 ) {
	BLK = 3;
} else
if ( n >= 1816 && n < 1817 ) {
	BLK = 2;
} else
if ( n >= 1817 && n < 1820 ) {
	BLK = 4;
} else
if ( n >= 1820 && n < 2126 ) {
	BLK = 3;
} else
if ( n >= 2126 && n < 2173 ) {
	BLK = 4;
} else
if ( n >= 2173 && n < 2174 ) {
	BLK = 2;
} else
if ( n >= 2174 && n < 2531 ) {
	BLK = 3;
} else
if ( n >= 2531 && n < 2545 ) {
	BLK = 4;
} else
if ( n >= 2545 && n < 2548 ) {
	BLK = 3;
} else
if ( n >= 2548 && n < 2549 ) {
	BLK = 2;
} else
if ( n >= 2549 && n < 2605 ) {
	BLK = 4;
} else
if ( n >= 2605 && n < 2616 ) {
	BLK = 3;
} else
if ( n >= 2616 && n < 2617 ) {
	BLK = 2;
} else
if ( n >= 2617 && n < 2636 ) {
	BLK = 4;
} else
if ( n >= 2636 && n < 2977 ) {
	BLK = 3;
} else
if ( n >= 2977 && n < 2978 ) {
	BLK = 2;
} else
if ( n >= 2978 && n < 2981 ) {
	BLK = 4;
} else
if ( n >= 2981 && n < 2987 ) {
	BLK = 3;
} else
if ( n >= 2987 && n < 2988 ) {
	BLK = 4;
} else
if ( n >= 2988 && n < 2989 ) {
	BLK = 2;
} else
if ( n >= 2989 && n < 3000 ) {
	BLK = 3;
} else
if ( n >= 3000 && n < 3001 ) {
	BLK = 4;
} else
if ( n >= 3001 && n < 3002 ) {
	BLK = 2;
} else
if ( n >= 3002 && n < 3045 ) {
	BLK = 3;
} else
if ( n >= 3045 && n < 3082 ) {
	BLK = 4;
} else
if ( n >= 3082 && n < 3084 ) {
	BLK = 2;
} else
if ( n >= 3084 && n < 3085 ) {
	BLK = 3;
} else
if ( n >= 3085 && n < 3102 ) {
	BLK = 4;
} else
if ( n >= 3102 && n < 3109 ) {
	BLK = 3;
} else
if ( n >= 3109 && n < 3112 ) {
	BLK = 2;
} else
if ( n >= 3112 && n < 3117 ) {
	BLK = 3;
} else
if ( n >= 3117 && n < 3127 ) {
	BLK = 4;
} else
if ( n >= 3127 && n < 3130 ) {
	BLK = 3;
} else
if ( n >= 3130 && n < 3136 ) {
	BLK = 2;
} else
if ( n >= 3136 && n < 3154 ) {
	BLK = 3;
} else
if ( n >= 3154 && n < 3155 ) {
	BLK = 4;
} else
if ( n >= 3155 && n < 3169 ) {
	BLK = 2;
} else
if ( n >= 3169 && n < 3170 ) {
	BLK = 3;
} else
if ( n >= 3170 && n < 3173 ) {
	BLK = 4;
} else
if ( n >= 3173 && n < 3183 ) {
	BLK = 2;
} else
if ( n >= 3183 && n < 3184 ) {
	BLK = 3;
} else
if ( n >= 3184 && n < 3219 ) {
	BLK = 4;
} else
if ( n >= 3219 && n < 3220 ) {
	BLK = 3;
} else
if ( n >= 3220 && n < 4879 ) {
	BLK = 2;
} else
if ( n >= 4879 && n < 4911 ) {
	BLK = 4;
} else
if ( n >= 4911 && n < 55930 ) {
	BLK = 1;
} else
if ( n >= 55930 && n < 59129 ) {
	BLK = 5;
} else
if ( n >= 59129 && n < 60292 ) {
	BLK = 1;
} else
if ( n >= 60292 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
