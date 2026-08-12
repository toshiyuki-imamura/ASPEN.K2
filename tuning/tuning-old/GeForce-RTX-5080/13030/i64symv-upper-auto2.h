#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Thu Aug 06 10:29:09  2026
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

if ( n >= 1 && n < 234 ) {
	BLK = 0;
} else
if ( n >= 234 && n < 236 ) {
	BLK = 1;
} else
if ( n >= 236 && n < 250 ) {
	BLK = 2;
} else
if ( n >= 250 && n < 783 ) {
	BLK = 0;
} else
if ( n >= 783 && n < 823 ) {
	BLK = 1;
} else
if ( n >= 823 && n < 870 ) {
	BLK = 0;
} else
if ( n >= 870 && n < 871 ) {
	BLK = 3;
} else
if ( n >= 871 && n < 886 ) {
	BLK = 1;
} else
if ( n >= 886 && n < 887 ) {
	BLK = 3;
} else
if ( n >= 887 && n < 888 ) {
	BLK = 0;
} else
if ( n >= 888 && n < 890 ) {
	BLK = 1;
} else
if ( n >= 890 && n < 891 ) {
	BLK = 3;
} else
if ( n >= 891 && n < 1015 ) {
	BLK = 0;
} else
if ( n >= 1015 && n < 1043 ) {
	BLK = 3;
} else
if ( n >= 1043 && n < 1083 ) {
	BLK = 5;
} else
if ( n >= 1083 && n < 1091 ) {
	BLK = 3;
} else
if ( n >= 1091 && n < 1092 ) {
	BLK = 0;
} else
if ( n >= 1092 && n < 1096 ) {
	BLK = 5;
} else
if ( n >= 1096 && n < 1110 ) {
	BLK = 3;
} else
if ( n >= 1110 && n < 1111 ) {
	BLK = 1;
} else
if ( n >= 1111 && n < 1116 ) {
	BLK = 5;
} else
if ( n >= 1116 && n < 1119 ) {
	BLK = 0;
} else
if ( n >= 1119 && n < 1153 ) {
	BLK = 3;
} else
if ( n >= 1153 && n < 1154 ) {
	BLK = 5;
} else
if ( n >= 1154 && n < 1155 ) {
	BLK = 0;
} else
if ( n >= 1155 && n < 1162 ) {
	BLK = 3;
} else
if ( n >= 1162 && n < 1164 ) {
	BLK = 0;
} else
if ( n >= 1164 && n < 1165 ) {
	BLK = 1;
} else
if ( n >= 1165 && n < 1166 ) {
	BLK = 5;
} else
if ( n >= 1166 && n < 1171 ) {
	BLK = 3;
} else
if ( n >= 1171 && n < 1172 ) {
	BLK = 0;
} else
if ( n >= 1172 && n < 1173 ) {
	BLK = 5;
} else
if ( n >= 1173 && n < 1176 ) {
	BLK = 3;
} else
if ( n >= 1176 && n < 1184 ) {
	BLK = 1;
} else
if ( n >= 1184 && n < 1210 ) {
	BLK = 5;
} else
if ( n >= 1210 && n < 1211 ) {
	BLK = 1;
} else
if ( n >= 1211 && n < 1212 ) {
	BLK = 3;
} else
if ( n >= 1212 && n < 1216 ) {
	BLK = 5;
} else
if ( n >= 1216 && n < 1248 ) {
	BLK = 1;
} else
if ( n >= 1248 && n < 1249 ) {
	BLK = 3;
} else
if ( n >= 1249 && n < 1259 ) {
	BLK = 5;
} else
if ( n >= 1259 && n < 1291 ) {
	BLK = 1;
} else
if ( n >= 1291 && n < 1292 ) {
	BLK = 5;
} else
if ( n >= 1292 && n < 1293 ) {
	BLK = 3;
} else
if ( n >= 1293 && n < 1301 ) {
	BLK = 1;
} else
if ( n >= 1301 && n < 1307 ) {
	BLK = 5;
} else
if ( n >= 1307 && n < 1315 ) {
	BLK = 3;
} else
if ( n >= 1315 && n < 1372 ) {
	BLK = 5;
} else
if ( n >= 1372 && n < 1373 ) {
	BLK = 3;
} else
if ( n >= 1373 && n < 1374 ) {
	BLK = 1;
} else
if ( n >= 1374 && n < 1455 ) {
	BLK = 5;
} else
if ( n >= 1455 && n < 1456 ) {
	BLK = 1;
} else
if ( n >= 1456 && n < 1457 ) {
	BLK = 4;
} else
if ( n >= 1457 && n < 1492 ) {
	BLK = 5;
} else
if ( n >= 1492 && n < 1538 ) {
	BLK = 1;
} else
if ( n >= 1538 && n < 1539 ) {
	BLK = 3;
} else
if ( n >= 1539 && n < 1552 ) {
	BLK = 5;
} else
if ( n >= 1552 && n < 1622 ) {
	BLK = 3;
} else
if ( n >= 1622 && n < 1623 ) {
	BLK = 5;
} else
if ( n >= 1623 && n < 1747 ) {
	BLK = 1;
} else
if ( n >= 1747 && n < 1804 ) {
	BLK = 3;
} else
if ( n >= 1804 && n < 1805 ) {
	BLK = 5;
} else
if ( n >= 1805 && n < 1872 ) {
	BLK = 1;
} else
if ( n >= 1872 && n < 1873 ) {
	BLK = 5;
} else
if ( n >= 1873 && n < 1887 ) {
	BLK = 3;
} else
if ( n >= 1887 && n < 1894 ) {
	BLK = 5;
} else
if ( n >= 1894 && n < 1898 ) {
	BLK = 3;
} else
if ( n >= 1898 && n < 1905 ) {
	BLK = 1;
} else
if ( n >= 1905 && n < 1907 ) {
	BLK = 3;
} else
if ( n >= 1907 && n < 1913 ) {
	BLK = 5;
} else
if ( n >= 1913 && n < 1929 ) {
	BLK = 3;
} else
if ( n >= 1929 && n < 1932 ) {
	BLK = 1;
} else
if ( n >= 1932 && n < 1933 ) {
	BLK = 5;
} else
if ( n >= 1933 && n < 1949 ) {
	BLK = 3;
} else
if ( n >= 1949 && n < 1950 ) {
	BLK = 5;
} else
if ( n >= 1950 && n < 2021 ) {
	BLK = 1;
} else
if ( n >= 2021 && n < 2022 ) {
	BLK = 5;
} else
if ( n >= 2022 && n < 2366 ) {
	BLK = 3;
} else
if ( n >= 2366 && n < 3866 ) {
	BLK = 1;
} else
if ( n >= 3866 && n < 6065 ) {
	BLK = 4;
} else
if ( n >= 6065 && n < 7033 ) {
	BLK = 1;
} else
if ( n >= 7033 && n < 10727 ) {
	BLK = 3;
} else
if ( n >= 10727 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
