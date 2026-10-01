#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Thu Sep 24 03:03:37  2026
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
MAXmem= 16800759808
// capacity of the work area reserved on the GPU
WORK= 2539520
// for double or cuFloatComplex or int64
MAXDIM= 43535
// for float or cuHalfComplex or int32
MAXDIM2= 61568
// for cuDoubleComplex or DD or int128
MAXDIM3= 30784
// for DD-Complex
MAXDIM4= 21767
// for half or int16
MAXDIM5= 87070
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 264 ) {
	BLK = 0;
} else
if ( n >= 264 && n < 265 ) {
	BLK = 3;
} else
if ( n >= 265 && n < 303 ) {
	BLK = 2;
} else
if ( n >= 303 && n < 304 ) {
	BLK = 1;
} else
if ( n >= 304 && n < 1026 ) {
	BLK = 0;
} else
if ( n >= 1026 && n < 1028 ) {
	BLK = 2;
} else
if ( n >= 1028 && n < 1030 ) {
	BLK = 1;
} else
if ( n >= 1030 && n < 1034 ) {
	BLK = 0;
} else
if ( n >= 1034 && n < 1056 ) {
	BLK = 2;
} else
if ( n >= 1056 && n < 1057 ) {
	BLK = 1;
} else
if ( n >= 1057 && n < 1063 ) {
	BLK = 0;
} else
if ( n >= 1063 && n < 1067 ) {
	BLK = 2;
} else
if ( n >= 1067 && n < 1068 ) {
	BLK = 0;
} else
if ( n >= 1068 && n < 1069 ) {
	BLK = 1;
} else
if ( n >= 1069 && n < 1080 ) {
	BLK = 2;
} else
if ( n >= 1080 && n < 1083 ) {
	BLK = 1;
} else
if ( n >= 1083 && n < 1088 ) {
	BLK = 0;
} else
if ( n >= 1088 && n < 1155 ) {
	BLK = 2;
} else
if ( n >= 1155 && n < 1168 ) {
	BLK = 0;
} else
if ( n >= 1168 && n < 1169 ) {
	BLK = 2;
} else
if ( n >= 1169 && n < 1172 ) {
	BLK = 1;
} else
if ( n >= 1172 && n < 1176 ) {
	BLK = 2;
} else
if ( n >= 1176 && n < 1183 ) {
	BLK = 1;
} else
if ( n >= 1183 && n < 1188 ) {
	BLK = 0;
} else
if ( n >= 1188 && n < 1189 ) {
	BLK = 2;
} else
if ( n >= 1189 && n < 1190 ) {
	BLK = 1;
} else
if ( n >= 1190 && n < 1196 ) {
	BLK = 0;
} else
if ( n >= 1196 && n < 1197 ) {
	BLK = 2;
} else
if ( n >= 1197 && n < 1235 ) {
	BLK = 1;
} else
if ( n >= 1235 && n < 1236 ) {
	BLK = 2;
} else
if ( n >= 1236 && n < 1237 ) {
	BLK = 0;
} else
if ( n >= 1237 && n < 1246 ) {
	BLK = 1;
} else
if ( n >= 1246 && n < 1247 ) {
	BLK = 0;
} else
if ( n >= 1247 && n < 1248 ) {
	BLK = 2;
} else
if ( n >= 1248 && n < 1249 ) {
	BLK = 1;
} else
if ( n >= 1249 && n < 1250 ) {
	BLK = 0;
} else
if ( n >= 1250 && n < 1255 ) {
	BLK = 2;
} else
if ( n >= 1255 && n < 1257 ) {
	BLK = 0;
} else
if ( n >= 1257 && n < 1258 ) {
	BLK = 1;
} else
if ( n >= 1258 && n < 1259 ) {
	BLK = 2;
} else
if ( n >= 1259 && n < 1264 ) {
	BLK = 0;
} else
if ( n >= 1264 && n < 1265 ) {
	BLK = 2;
} else
if ( n >= 1265 && n < 1269 ) {
	BLK = 1;
} else
if ( n >= 1269 && n < 1270 ) {
	BLK = 2;
} else
if ( n >= 1270 && n < 1273 ) {
	BLK = 0;
} else
if ( n >= 1273 && n < 1289 ) {
	BLK = 1;
} else
if ( n >= 1289 && n < 1290 ) {
	BLK = 0;
} else
if ( n >= 1290 && n < 1448 ) {
	BLK = 2;
} else
if ( n >= 1448 && n < 1468 ) {
	BLK = 0;
} else
if ( n >= 1468 && n < 5495 ) {
	BLK = 1;
} else
if ( n >= 5495 && n < 9628 ) {
	BLK = 3;
} else
if ( n >= 9628 && n < 12479 ) {
	BLK = 2;
} else
if ( n >= 12479 && n < 18195 ) {
	BLK = 1;
} else
if ( n >= 18195 && n < 18246 ) {
	BLK = 4;
} else
if ( n >= 18246 && n < 19077 ) {
	BLK = 2;
} else
if ( n >= 19077 && n < 19480 ) {
	BLK = 4;
} else
if ( n >= 19480 && n < 20174 ) {
	BLK = 2;
} else
if ( n >= 20174 && n < 20834 ) {
	BLK = 4;
} else
if ( n >= 20834 && n < 21426 ) {
	BLK = 2;
} else
if ( n >= 21426 && n < 22194 ) {
	BLK = 4;
} else
if ( n >= 22194 && n < 22795 ) {
	BLK = 2;
} else
if ( n >= 22795 && n < 26017 ) {
	BLK = 4;
} else
if ( n >= 26017 && n < 26983 ) {
	BLK = 2;
} else
if ( n >= 26983 && n < 28428 ) {
	BLK = 4;
} else
if ( n >= 28428 && n < 29633 ) {
	BLK = 2;
} else
if ( n >= 29633 && n < 31313 ) {
	BLK = 4;
} else
if ( n >= 31313 && n < 32707 ) {
	BLK = 2;
} else
if ( n >= 32707 && n < 34012 ) {
	BLK = 4;
} else
if ( n >= 34012 && n < 35543 ) {
	BLK = 2;
} else
if ( n >= 35543 && n < 44430 ) {
	BLK = 4;
} else
if ( n >= 44430 && n < 46936 ) {
	BLK = 2;
} else
if ( n >= 46936 && n < 50587 ) {
	BLK = 4;
} else
if ( n >= 50587 && n < 53465 ) {
	BLK = 2;
} else
if ( n >= 53465 && n < 54100 ) {
	BLK = 1;
} else
if ( n >= 54100 && n < 55834 ) {
	BLK = 2;
} else
if ( n >= 55834 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
