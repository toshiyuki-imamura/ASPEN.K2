#ifndef I128SYMVU_AUTO2_H_INCLUDED
#define I128SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVU
 Thu Jul 23 04:49:40  2026
 Host on pascal.r-ccs27.riken.jp
 Device is RTX-A6000
****************************************/-->
// device name
DEVICE= RTX-A6000
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 50892406784
// capacity of the work area reserved on the GPU
WORK= 4421120
// for double or cuFloatComplex or int64
MAXDIM= 75771
// for float or cuHalfComplex or int32
MAXDIM2= 107156
// for cuDoubleComplex or DD or int128
MAXDIM3= 53578
// for DD-Complex
MAXDIM4= 37885
// for half or int16
MAXDIM5= 151542
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 2 ) {
	BLK = 2;
} else
if ( n >= 2 && n < 17 ) {
	BLK = 1;
} else
if ( n >= 17 && n < 23 ) {
	BLK = 2;
} else
if ( n >= 23 && n < 24 ) {
	BLK = 3;
} else
if ( n >= 24 && n < 29 ) {
	BLK = 1;
} else
if ( n >= 29 && n < 31 ) {
	BLK = 3;
} else
if ( n >= 31 && n < 42 ) {
	BLK = 2;
} else
if ( n >= 42 && n < 52 ) {
	BLK = 1;
} else
if ( n >= 52 && n < 61 ) {
	BLK = 3;
} else
if ( n >= 61 && n < 64 ) {
	BLK = 2;
} else
if ( n >= 64 && n < 71 ) {
	BLK = 1;
} else
if ( n >= 71 && n < 72 ) {
	BLK = 2;
} else
if ( n >= 72 && n < 73 ) {
	BLK = 3;
} else
if ( n >= 73 && n < 74 ) {
	BLK = 1;
} else
if ( n >= 74 && n < 84 ) {
	BLK = 2;
} else
if ( n >= 84 && n < 94 ) {
	BLK = 1;
} else
if ( n >= 94 && n < 95 ) {
	BLK = 2;
} else
if ( n >= 95 && n < 96 ) {
	BLK = 3;
} else
if ( n >= 96 && n < 103 ) {
	BLK = 1;
} else
if ( n >= 103 && n < 116 ) {
	BLK = 2;
} else
if ( n >= 116 && n < 119 ) {
	BLK = 1;
} else
if ( n >= 119 && n < 125 ) {
	BLK = 2;
} else
if ( n >= 125 && n < 126 ) {
	BLK = 1;
} else
if ( n >= 126 && n < 134 ) {
	BLK = 3;
} else
if ( n >= 134 && n < 137 ) {
	BLK = 2;
} else
if ( n >= 137 && n < 138 ) {
	BLK = 1;
} else
if ( n >= 138 && n < 139 ) {
	BLK = 3;
} else
if ( n >= 139 && n < 140 ) {
	BLK = 2;
} else
if ( n >= 140 && n < 141 ) {
	BLK = 1;
} else
if ( n >= 141 && n < 147 ) {
	BLK = 3;
} else
if ( n >= 147 && n < 173 ) {
	BLK = 2;
} else
if ( n >= 173 && n < 174 ) {
	BLK = 3;
} else
if ( n >= 174 && n < 175 ) {
	BLK = 1;
} else
if ( n >= 175 && n < 178 ) {
	BLK = 2;
} else
if ( n >= 178 && n < 180 ) {
	BLK = 3;
} else
if ( n >= 180 && n < 184 ) {
	BLK = 1;
} else
if ( n >= 184 && n < 185 ) {
	BLK = 2;
} else
if ( n >= 185 && n < 187 ) {
	BLK = 3;
} else
if ( n >= 187 && n < 189 ) {
	BLK = 1;
} else
if ( n >= 189 && n < 208 ) {
	BLK = 2;
} else
if ( n >= 208 && n < 209 ) {
	BLK = 3;
} else
if ( n >= 209 && n < 210 ) {
	BLK = 1;
} else
if ( n >= 210 && n < 211 ) {
	BLK = 2;
} else
if ( n >= 211 && n < 215 ) {
	BLK = 3;
} else
if ( n >= 215 && n < 216 ) {
	BLK = 1;
} else
if ( n >= 216 && n < 218 ) {
	BLK = 2;
} else
if ( n >= 218 && n < 220 ) {
	BLK = 3;
} else
if ( n >= 220 && n < 227 ) {
	BLK = 1;
} else
if ( n >= 227 && n < 230 ) {
	BLK = 2;
} else
if ( n >= 230 && n < 231 ) {
	BLK = 1;
} else
if ( n >= 231 && n < 232 ) {
	BLK = 3;
} else
if ( n >= 232 && n < 239 ) {
	BLK = 2;
} else
if ( n >= 239 && n < 245 ) {
	BLK = 1;
} else
if ( n >= 245 && n < 246 ) {
	BLK = 3;
} else
if ( n >= 246 && n < 251 ) {
	BLK = 2;
} else
if ( n >= 251 && n < 257 ) {
	BLK = 3;
} else
if ( n >= 257 && n < 258 ) {
	BLK = 1;
} else
if ( n >= 258 && n < 259 ) {
	BLK = 2;
} else
if ( n >= 259 && n < 262 ) {
	BLK = 3;
} else
if ( n >= 262 && n < 264 ) {
	BLK = 2;
} else
if ( n >= 264 && n < 269 ) {
	BLK = 1;
} else
if ( n >= 269 && n < 270 ) {
	BLK = 2;
} else
if ( n >= 270 && n < 273 ) {
	BLK = 3;
} else
if ( n >= 273 && n < 275 ) {
	BLK = 2;
} else
if ( n >= 275 && n < 279 ) {
	BLK = 1;
} else
if ( n >= 279 && n < 280 ) {
	BLK = 3;
} else
if ( n >= 280 && n < 281 ) {
	BLK = 2;
} else
if ( n >= 281 && n < 282 ) {
	BLK = 1;
} else
if ( n >= 282 && n < 285 ) {
	BLK = 3;
} else
if ( n >= 285 && n < 289 ) {
	BLK = 2;
} else
if ( n >= 289 && n < 322 ) {
	BLK = 3;
} else
if ( n >= 322 && n < 328 ) {
	BLK = 2;
} else
if ( n >= 328 && n < 333 ) {
	BLK = 1;
} else
if ( n >= 333 && n < 336 ) {
	BLK = 3;
} else
if ( n >= 336 && n < 343 ) {
	BLK = 2;
} else
if ( n >= 343 && n < 353 ) {
	BLK = 1;
} else
if ( n >= 353 && n < 358 ) {
	BLK = 2;
} else
if ( n >= 358 && n < 359 ) {
	BLK = 3;
} else
if ( n >= 359 && n < 363 ) {
	BLK = 1;
} else
if ( n >= 363 && n < 367 ) {
	BLK = 2;
} else
if ( n >= 367 && n < 368 ) {
	BLK = 1;
} else
if ( n >= 368 && n < 369 ) {
	BLK = 3;
} else
if ( n >= 369 && n < 372 ) {
	BLK = 2;
} else
if ( n >= 372 && n < 374 ) {
	BLK = 3;
} else
if ( n >= 374 && n < 376 ) {
	BLK = 1;
} else
if ( n >= 376 && n < 388 ) {
	BLK = 2;
} else
if ( n >= 388 && n < 389 ) {
	BLK = 3;
} else
if ( n >= 389 && n < 390 ) {
	BLK = 1;
} else
if ( n >= 390 && n < 406 ) {
	BLK = 2;
} else
if ( n >= 406 && n < 407 ) {
	BLK = 3;
} else
if ( n >= 407 && n < 408 ) {
	BLK = 1;
} else
if ( n >= 408 && n < 422 ) {
	BLK = 2;
} else
if ( n >= 422 && n < 423 ) {
	BLK = 3;
} else
if ( n >= 423 && n < 424 ) {
	BLK = 1;
} else
if ( n >= 424 && n < 431 ) {
	BLK = 2;
} else
if ( n >= 431 && n < 434 ) {
	BLK = 3;
} else
if ( n >= 434 && n < 437 ) {
	BLK = 2;
} else
if ( n >= 437 && n < 438 ) {
	BLK = 1;
} else
if ( n >= 438 && n < 448 ) {
	BLK = 3;
} else
if ( n >= 448 && n < 468 ) {
	BLK = 2;
} else
if ( n >= 468 && n < 473 ) {
	BLK = 3;
} else
if ( n >= 473 && n < 475 ) {
	BLK = 1;
} else
if ( n >= 475 && n < 491 ) {
	BLK = 2;
} else
if ( n >= 491 && n < 492 ) {
	BLK = 1;
} else
if ( n >= 492 && n < 493 ) {
	BLK = 3;
} else
if ( n >= 493 && n < 576 ) {
	BLK = 2;
} else
if ( n >= 576 && n < 577 ) {
	BLK = 1;
} else
if ( n >= 577 && n < 584 ) {
	BLK = 3;
} else
if ( n >= 584 && n < 587 ) {
	BLK = 2;
} else
if ( n >= 587 && n < 588 ) {
	BLK = 1;
} else
if ( n >= 588 && n < 599 ) {
	BLK = 3;
} else
if ( n >= 599 && n < 601 ) {
	BLK = 2;
} else
if ( n >= 601 && n < 602 ) {
	BLK = 1;
} else
if ( n >= 602 && n < 603 ) {
	BLK = 3;
} else
if ( n >= 603 && n < 647 ) {
	BLK = 2;
} else
if ( n >= 647 && n < 648 ) {
	BLK = 1;
} else
if ( n >= 648 && n < 650 ) {
	BLK = 3;
} else
if ( n >= 650 && n < 675 ) {
	BLK = 2;
} else
if ( n >= 675 && n < 677 ) {
	BLK = 1;
} else
if ( n >= 677 && n < 681 ) {
	BLK = 3;
} else
if ( n >= 681 && n < 683 ) {
	BLK = 2;
} else
if ( n >= 683 && n < 684 ) {
	BLK = 1;
} else
if ( n >= 684 && n < 793 ) {
	BLK = 3;
} else
if ( n >= 793 && n < 857 ) {
	BLK = 2;
} else
if ( n >= 857 && n < 858 ) {
	BLK = 3;
} else
if ( n >= 858 && n < 859 ) {
	BLK = 1;
} else
if ( n >= 859 && n < 860 ) {
	BLK = 2;
} else
if ( n >= 860 && n < 861 ) {
	BLK = 3;
} else
if ( n >= 861 && n < 862 ) {
	BLK = 1;
} else
if ( n >= 862 && n < 875 ) {
	BLK = 2;
} else
if ( n >= 875 && n < 955 ) {
	BLK = 3;
} else
if ( n >= 955 && n < 956 ) {
	BLK = 1;
} else
if ( n >= 956 && n < 1014 ) {
	BLK = 2;
} else
if ( n >= 1014 && n < 1016 ) {
	BLK = 3;
} else
if ( n >= 1016 && n < 1017 ) {
	BLK = 1;
} else
if ( n >= 1017 && n < 1188 ) {
	BLK = 2;
} else
if ( n >= 1188 && n < 1189 ) {
	BLK = 1;
} else
if ( n >= 1189 && n < 1225 ) {
	BLK = 3;
} else
if ( n >= 1225 && n < 1226 ) {
	BLK = 2;
} else
if ( n >= 1226 && n < 1227 ) {
	BLK = 1;
} else
if ( n >= 1227 && n < 1285 ) {
	BLK = 3;
} else
if ( n >= 1285 && n < 1368 ) {
	BLK = 2;
} else
if ( n >= 1368 && n < 1369 ) {
	BLK = 3;
} else
if ( n >= 1369 && n < 1370 ) {
	BLK = 1;
} else
if ( n >= 1370 && n < 1696 ) {
	BLK = 2;
} else
if ( n >= 1696 && n < 1697 ) {
	BLK = 1;
} else
if ( n >= 1697 && n < 3902 ) {
	BLK = 3;
} else
if ( n >= 3902 && n < 3911 ) {
	BLK = 2;
} else
if ( n >= 3911 && n < 3912 ) {
	BLK = 1;
} else
if ( n >= 3912 && n < 3928 ) {
	BLK = 3;
} else
if ( n >= 3928 && n < 3934 ) {
	BLK = 2;
} else
if ( n >= 3934 && n < 3935 ) {
	BLK = 1;
} else
if ( n >= 3935 && n < 3938 ) {
	BLK = 3;
} else
if ( n >= 3938 && n < 4062 ) {
	BLK = 2;
} else
if ( n >= 4062 && n < 4064 ) {
	BLK = 1;
} else
if ( n >= 4064 && n < 4070 ) {
	BLK = 3;
} else
if ( n >= 4070 && n < 4073 ) {
	BLK = 1;
} else
if ( n >= 4073 && n < 4096 ) {
	BLK = 2;
} else
if ( n >= 4096 && n < 4098 ) {
	BLK = 3;
} else
if ( n >= 4098 && n < 4121 ) {
	BLK = 1;
} else
if ( n >= 4121 && n < 4123 ) {
	BLK = 3;
} else
if ( n >= 4123 && n < 4129 ) {
	BLK = 2;
} else
if ( n >= 4129 && n < 4132 ) {
	BLK = 1;
} else
if ( n >= 4132 && n < 4154 ) {
	BLK = 3;
} else
if ( n >= 4154 && n < 4155 ) {
	BLK = 1;
} else
if ( n >= 4155 && n < 4163 ) {
	BLK = 2;
} else
if ( n >= 4163 && n < 4168 ) {
	BLK = 3;
} else
if ( n >= 4168 && n < 4191 ) {
	BLK = 1;
} else
if ( n >= 4191 && n < 4193 ) {
	BLK = 3;
} else
if ( n >= 4193 && n < 4258 ) {
	BLK = 2;
} else
if ( n >= 4258 && n < 4286 ) {
	BLK = 1;
} else
if ( n >= 4286 && n < 4293 ) {
	BLK = 3;
} else
if ( n >= 4293 && n < 4325 ) {
	BLK = 2;
} else
if ( n >= 4325 && n < 4347 ) {
	BLK = 1;
} else
if ( n >= 4347 && n < 4353 ) {
	BLK = 3;
} else
if ( n >= 4353 && n < 4429 ) {
	BLK = 2;
} else
if ( n >= 4429 && n < 4463 ) {
	BLK = 1;
} else
if ( n >= 4463 && n < 4467 ) {
	BLK = 3;
} else
if ( n >= 4467 && n < 4470 ) {
	BLK = 2;
} else
if ( n >= 4470 && n < 4480 ) {
	BLK = 1;
} else
if ( n >= 4480 && n < 4481 ) {
	BLK = 3;
} else
if ( n >= 4481 && n < 4485 ) {
	BLK = 2;
} else
if ( n >= 4485 && n < 4580 ) {
	BLK = 1;
} else
if ( n >= 4580 && n < 4586 ) {
	BLK = 3;
} else
if ( n >= 4586 && n < 4591 ) {
	BLK = 2;
} else
if ( n >= 4591 && n < 4648 ) {
	BLK = 1;
} else
if ( n >= 4648 && n < 4649 ) {
	BLK = 3;
} else
if ( n >= 4649 && n < 4897 ) {
	BLK = 2;
} else
if ( n >= 4897 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
