#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Fri Jul 24 07:13:55  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3 ) {
	BLK = 2;
} else
if ( n >= 3 && n < 6 ) {
	BLK = 0;
} else
if ( n >= 6 && n < 10 ) {
	BLK = 2;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 0;
} else
if ( n >= 11 && n < 14 ) {
	BLK = 3;
} else
if ( n >= 14 && n < 29 ) {
	BLK = 2;
} else
if ( n >= 29 && n < 30 ) {
	BLK = 3;
} else
if ( n >= 30 && n < 31 ) {
	BLK = 1;
} else
if ( n >= 31 && n < 32 ) {
	BLK = 0;
} else
if ( n >= 32 && n < 33 ) {
	BLK = 3;
} else
if ( n >= 33 && n < 37 ) {
	BLK = 2;
} else
if ( n >= 37 && n < 38 ) {
	BLK = 0;
} else
if ( n >= 38 && n < 39 ) {
	BLK = 3;
} else
if ( n >= 39 && n < 40 ) {
	BLK = 1;
} else
if ( n >= 40 && n < 46 ) {
	BLK = 2;
} else
if ( n >= 46 && n < 47 ) {
	BLK = 3;
} else
if ( n >= 47 && n < 48 ) {
	BLK = 1;
} else
if ( n >= 48 && n < 55 ) {
	BLK = 2;
} else
if ( n >= 55 && n < 56 ) {
	BLK = 0;
} else
if ( n >= 56 && n < 71 ) {
	BLK = 1;
} else
if ( n >= 71 && n < 87 ) {
	BLK = 2;
} else
if ( n >= 87 && n < 89 ) {
	BLK = 0;
} else
if ( n >= 89 && n < 90 ) {
	BLK = 3;
} else
if ( n >= 90 && n < 122 ) {
	BLK = 2;
} else
if ( n >= 122 && n < 123 ) {
	BLK = 1;
} else
if ( n >= 123 && n < 124 ) {
	BLK = 0;
} else
if ( n >= 124 && n < 147 ) {
	BLK = 2;
} else
if ( n >= 147 && n < 148 ) {
	BLK = 0;
} else
if ( n >= 148 && n < 159 ) {
	BLK = 3;
} else
if ( n >= 159 && n < 163 ) {
	BLK = 2;
} else
if ( n >= 163 && n < 164 ) {
	BLK = 0;
} else
if ( n >= 164 && n < 173 ) {
	BLK = 1;
} else
if ( n >= 173 && n < 178 ) {
	BLK = 0;
} else
if ( n >= 178 && n < 186 ) {
	BLK = 2;
} else
if ( n >= 186 && n < 198 ) {
	BLK = 0;
} else
if ( n >= 198 && n < 211 ) {
	BLK = 2;
} else
if ( n >= 211 && n < 212 ) {
	BLK = 1;
} else
if ( n >= 212 && n < 226 ) {
	BLK = 3;
} else
if ( n >= 226 && n < 227 ) {
	BLK = 2;
} else
if ( n >= 227 && n < 229 ) {
	BLK = 0;
} else
if ( n >= 229 && n < 230 ) {
	BLK = 1;
} else
if ( n >= 230 && n < 240 ) {
	BLK = 2;
} else
if ( n >= 240 && n < 247 ) {
	BLK = 0;
} else
if ( n >= 247 && n < 248 ) {
	BLK = 1;
} else
if ( n >= 248 && n < 251 ) {
	BLK = 2;
} else
if ( n >= 251 && n < 256 ) {
	BLK = 3;
} else
if ( n >= 256 && n < 258 ) {
	BLK = 2;
} else
if ( n >= 258 && n < 259 ) {
	BLK = 1;
} else
if ( n >= 259 && n < 260 ) {
	BLK = 0;
} else
if ( n >= 260 && n < 262 ) {
	BLK = 3;
} else
if ( n >= 262 && n < 300 ) {
	BLK = 2;
} else
if ( n >= 300 && n < 301 ) {
	BLK = 3;
} else
if ( n >= 301 && n < 307 ) {
	BLK = 0;
} else
if ( n >= 307 && n < 311 ) {
	BLK = 2;
} else
if ( n >= 311 && n < 312 ) {
	BLK = 3;
} else
if ( n >= 312 && n < 313 ) {
	BLK = 0;
} else
if ( n >= 313 && n < 314 ) {
	BLK = 2;
} else
if ( n >= 314 && n < 315 ) {
	BLK = 3;
} else
if ( n >= 315 && n < 319 ) {
	BLK = 0;
} else
if ( n >= 319 && n < 322 ) {
	BLK = 1;
} else
if ( n >= 322 && n < 323 ) {
	BLK = 0;
} else
if ( n >= 323 && n < 328 ) {
	BLK = 3;
} else
if ( n >= 328 && n < 329 ) {
	BLK = 0;
} else
if ( n >= 329 && n < 330 ) {
	BLK = 1;
} else
if ( n >= 330 && n < 336 ) {
	BLK = 2;
} else
if ( n >= 336 && n < 345 ) {
	BLK = 3;
} else
if ( n >= 345 && n < 347 ) {
	BLK = 0;
} else
if ( n >= 347 && n < 385 ) {
	BLK = 2;
} else
if ( n >= 385 && n < 386 ) {
	BLK = 3;
} else
if ( n >= 386 && n < 387 ) {
	BLK = 1;
} else
if ( n >= 387 && n < 397 ) {
	BLK = 2;
} else
if ( n >= 397 && n < 398 ) {
	BLK = 1;
} else
if ( n >= 398 && n < 399 ) {
	BLK = 3;
} else
if ( n >= 399 && n < 402 ) {
	BLK = 2;
} else
if ( n >= 402 && n < 403 ) {
	BLK = 0;
} else
if ( n >= 403 && n < 405 ) {
	BLK = 1;
} else
if ( n >= 405 && n < 413 ) {
	BLK = 2;
} else
if ( n >= 413 && n < 417 ) {
	BLK = 1;
} else
if ( n >= 417 && n < 421 ) {
	BLK = 3;
} else
if ( n >= 421 && n < 429 ) {
	BLK = 2;
} else
if ( n >= 429 && n < 430 ) {
	BLK = 1;
} else
if ( n >= 430 && n < 431 ) {
	BLK = 0;
} else
if ( n >= 431 && n < 432 ) {
	BLK = 3;
} else
if ( n >= 432 && n < 437 ) {
	BLK = 2;
} else
if ( n >= 437 && n < 448 ) {
	BLK = 0;
} else
if ( n >= 448 && n < 449 ) {
	BLK = 3;
} else
if ( n >= 449 && n < 464 ) {
	BLK = 2;
} else
if ( n >= 464 && n < 468 ) {
	BLK = 0;
} else
if ( n >= 468 && n < 476 ) {
	BLK = 2;
} else
if ( n >= 476 && n < 482 ) {
	BLK = 3;
} else
if ( n >= 482 && n < 487 ) {
	BLK = 2;
} else
if ( n >= 487 && n < 491 ) {
	BLK = 0;
} else
if ( n >= 491 && n < 492 ) {
	BLK = 3;
} else
if ( n >= 492 && n < 495 ) {
	BLK = 2;
} else
if ( n >= 495 && n < 496 ) {
	BLK = 0;
} else
if ( n >= 496 && n < 497 ) {
	BLK = 3;
} else
if ( n >= 497 && n < 498 ) {
	BLK = 2;
} else
if ( n >= 498 && n < 499 ) {
	BLK = 0;
} else
if ( n >= 499 && n < 500 ) {
	BLK = 1;
} else
if ( n >= 500 && n < 510 ) {
	BLK = 2;
} else
if ( n >= 510 && n < 511 ) {
	BLK = 1;
} else
if ( n >= 511 && n < 523 ) {
	BLK = 3;
} else
if ( n >= 523 && n < 531 ) {
	BLK = 2;
} else
if ( n >= 531 && n < 535 ) {
	BLK = 1;
} else
if ( n >= 535 && n < 536 ) {
	BLK = 0;
} else
if ( n >= 536 && n < 556 ) {
	BLK = 2;
} else
if ( n >= 556 && n < 557 ) {
	BLK = 1;
} else
if ( n >= 557 && n < 558 ) {
	BLK = 3;
} else
if ( n >= 558 && n < 559 ) {
	BLK = 0;
} else
if ( n >= 559 && n < 561 ) {
	BLK = 2;
} else
if ( n >= 561 && n < 563 ) {
	BLK = 3;
} else
if ( n >= 563 && n < 573 ) {
	BLK = 1;
} else
if ( n >= 573 && n < 574 ) {
	BLK = 0;
} else
if ( n >= 574 && n < 575 ) {
	BLK = 2;
} else
if ( n >= 575 && n < 576 ) {
	BLK = 1;
} else
if ( n >= 576 && n < 585 ) {
	BLK = 3;
} else
if ( n >= 585 && n < 590 ) {
	BLK = 2;
} else
if ( n >= 590 && n < 591 ) {
	BLK = 3;
} else
if ( n >= 591 && n < 595 ) {
	BLK = 0;
} else
if ( n >= 595 && n < 596 ) {
	BLK = 2;
} else
if ( n >= 596 && n < 597 ) {
	BLK = 1;
} else
if ( n >= 597 && n < 598 ) {
	BLK = 3;
} else
if ( n >= 598 && n < 605 ) {
	BLK = 2;
} else
if ( n >= 605 && n < 606 ) {
	BLK = 0;
} else
if ( n >= 606 && n < 616 ) {
	BLK = 3;
} else
if ( n >= 616 && n < 617 ) {
	BLK = 2;
} else
if ( n >= 617 && n < 618 ) {
	BLK = 0;
} else
if ( n >= 618 && n < 619 ) {
	BLK = 1;
} else
if ( n >= 619 && n < 631 ) {
	BLK = 2;
} else
if ( n >= 631 && n < 639 ) {
	BLK = 0;
} else
if ( n >= 639 && n < 641 ) {
	BLK = 2;
} else
if ( n >= 641 && n < 643 ) {
	BLK = 3;
} else
if ( n >= 643 && n < 645 ) {
	BLK = 0;
} else
if ( n >= 645 && n < 646 ) {
	BLK = 2;
} else
if ( n >= 646 && n < 651 ) {
	BLK = 1;
} else
if ( n >= 651 && n < 657 ) {
	BLK = 2;
} else
if ( n >= 657 && n < 658 ) {
	BLK = 0;
} else
if ( n >= 658 && n < 659 ) {
	BLK = 1;
} else
if ( n >= 659 && n < 666 ) {
	BLK = 2;
} else
if ( n >= 666 && n < 667 ) {
	BLK = 0;
} else
if ( n >= 667 && n < 678 ) {
	BLK = 3;
} else
if ( n >= 678 && n < 679 ) {
	BLK = 1;
} else
if ( n >= 679 && n < 701 ) {
	BLK = 2;
} else
if ( n >= 701 && n < 704 ) {
	BLK = 0;
} else
if ( n >= 704 && n < 715 ) {
	BLK = 2;
} else
if ( n >= 715 && n < 717 ) {
	BLK = 0;
} else
if ( n >= 717 && n < 736 ) {
	BLK = 3;
} else
if ( n >= 736 && n < 772 ) {
	BLK = 2;
} else
if ( n >= 772 && n < 773 ) {
	BLK = 3;
} else
if ( n >= 773 && n < 783 ) {
	BLK = 0;
} else
if ( n >= 783 && n < 787 ) {
	BLK = 3;
} else
if ( n >= 787 && n < 800 ) {
	BLK = 2;
} else
if ( n >= 800 && n < 802 ) {
	BLK = 0;
} else
if ( n >= 802 && n < 803 ) {
	BLK = 3;
} else
if ( n >= 803 && n < 805 ) {
	BLK = 2;
} else
if ( n >= 805 && n < 806 ) {
	BLK = 0;
} else
if ( n >= 806 && n < 812 ) {
	BLK = 1;
} else
if ( n >= 812 && n < 814 ) {
	BLK = 2;
} else
if ( n >= 814 && n < 815 ) {
	BLK = 0;
} else
if ( n >= 815 && n < 816 ) {
	BLK = 3;
} else
if ( n >= 816 && n < 820 ) {
	BLK = 2;
} else
if ( n >= 820 && n < 821 ) {
	BLK = 0;
} else
if ( n >= 821 && n < 823 ) {
	BLK = 3;
} else
if ( n >= 823 && n < 833 ) {
	BLK = 2;
} else
if ( n >= 833 && n < 836 ) {
	BLK = 3;
} else
if ( n >= 836 && n < 838 ) {
	BLK = 2;
} else
if ( n >= 838 && n < 839 ) {
	BLK = 1;
} else
if ( n >= 839 && n < 843 ) {
	BLK = 3;
} else
if ( n >= 843 && n < 844 ) {
	BLK = 0;
} else
if ( n >= 844 && n < 871 ) {
	BLK = 2;
} else
if ( n >= 871 && n < 872 ) {
	BLK = 1;
} else
if ( n >= 872 && n < 873 ) {
	BLK = 3;
} else
if ( n >= 873 && n < 874 ) {
	BLK = 0;
} else
if ( n >= 874 && n < 884 ) {
	BLK = 2;
} else
if ( n >= 884 && n < 885 ) {
	BLK = 3;
} else
if ( n >= 885 && n < 888 ) {
	BLK = 0;
} else
if ( n >= 888 && n < 904 ) {
	BLK = 3;
} else
if ( n >= 904 && n < 905 ) {
	BLK = 2;
} else
if ( n >= 905 && n < 916 ) {
	BLK = 0;
} else
if ( n >= 916 && n < 919 ) {
	BLK = 1;
} else
if ( n >= 919 && n < 920 ) {
	BLK = 3;
} else
if ( n >= 920 && n < 930 ) {
	BLK = 2;
} else
if ( n >= 930 && n < 931 ) {
	BLK = 3;
} else
if ( n >= 931 && n < 932 ) {
	BLK = 1;
} else
if ( n >= 932 && n < 933 ) {
	BLK = 0;
} else
if ( n >= 933 && n < 943 ) {
	BLK = 3;
} else
if ( n >= 943 && n < 954 ) {
	BLK = 0;
} else
if ( n >= 954 && n < 960 ) {
	BLK = 2;
} else
if ( n >= 960 && n < 967 ) {
	BLK = 3;
} else
if ( n >= 967 && n < 968 ) {
	BLK = 0;
} else
if ( n >= 968 && n < 976 ) {
	BLK = 2;
} else
if ( n >= 976 && n < 977 ) {
	BLK = 3;
} else
if ( n >= 977 && n < 980 ) {
	BLK = 0;
} else
if ( n >= 980 && n < 981 ) {
	BLK = 1;
} else
if ( n >= 981 && n < 988 ) {
	BLK = 2;
} else
if ( n >= 988 && n < 989 ) {
	BLK = 1;
} else
if ( n >= 989 && n < 992 ) {
	BLK = 0;
} else
if ( n >= 992 && n < 993 ) {
	BLK = 2;
} else
if ( n >= 993 && n < 994 ) {
	BLK = 3;
} else
if ( n >= 994 && n < 995 ) {
	BLK = 1;
} else
if ( n >= 995 && n < 998 ) {
	BLK = 0;
} else
if ( n >= 998 && n < 1005 ) {
	BLK = 3;
} else
if ( n >= 1005 && n < 1008 ) {
	BLK = 2;
} else
if ( n >= 1008 && n < 1012 ) {
	BLK = 3;
} else
if ( n >= 1012 && n < 1013 ) {
	BLK = 1;
} else
if ( n >= 1013 && n < 1019 ) {
	BLK = 2;
} else
if ( n >= 1019 && n < 1020 ) {
	BLK = 0;
} else
if ( n >= 1020 && n < 1022 ) {
	BLK = 3;
} else
if ( n >= 1022 && n < 1023 ) {
	BLK = 2;
} else
if ( n >= 1023 && n < 1024 ) {
	BLK = 1;
} else
if ( n >= 1024 && n < 1026 ) {
	BLK = 0;
} else
if ( n >= 1026 && n < 1027 ) {
	BLK = 3;
} else
if ( n >= 1027 && n < 1035 ) {
	BLK = 2;
} else
if ( n >= 1035 && n < 1038 ) {
	BLK = 3;
} else
if ( n >= 1038 && n < 1044 ) {
	BLK = 0;
} else
if ( n >= 1044 && n < 1045 ) {
	BLK = 1;
} else
if ( n >= 1045 && n < 1048 ) {
	BLK = 2;
} else
if ( n >= 1048 && n < 1052 ) {
	BLK = 0;
} else
if ( n >= 1052 && n < 1053 ) {
	BLK = 3;
} else
if ( n >= 1053 && n < 1055 ) {
	BLK = 2;
} else
if ( n >= 1055 && n < 1061 ) {
	BLK = 0;
} else
if ( n >= 1061 && n < 1062 ) {
	BLK = 2;
} else
if ( n >= 1062 && n < 1070 ) {
	BLK = 3;
} else
if ( n >= 1070 && n < 1071 ) {
	BLK = 0;
} else
if ( n >= 1071 && n < 1074 ) {
	BLK = 2;
} else
if ( n >= 1074 && n < 1086 ) {
	BLK = 3;
} else
if ( n >= 1086 && n < 1087 ) {
	BLK = 2;
} else
if ( n >= 1087 && n < 1090 ) {
	BLK = 0;
} else
if ( n >= 1090 && n < 1091 ) {
	BLK = 3;
} else
if ( n >= 1091 && n < 1092 ) {
	BLK = 2;
} else
if ( n >= 1092 && n < 1093 ) {
	BLK = 0;
} else
if ( n >= 1093 && n < 1094 ) {
	BLK = 1;
} else
if ( n >= 1094 && n < 1095 ) {
	BLK = 3;
} else
if ( n >= 1095 && n < 1096 ) {
	BLK = 2;
} else
if ( n >= 1096 && n < 1097 ) {
	BLK = 1;
} else
if ( n >= 1097 && n < 1099 ) {
	BLK = 3;
} else
if ( n >= 1099 && n < 1100 ) {
	BLK = 0;
} else
if ( n >= 1100 && n < 1103 ) {
	BLK = 2;
} else
if ( n >= 1103 && n < 1104 ) {
	BLK = 0;
} else
if ( n >= 1104 && n < 1118 ) {
	BLK = 3;
} else
if ( n >= 1118 && n < 1125 ) {
	BLK = 2;
} else
if ( n >= 1125 && n < 1132 ) {
	BLK = 3;
} else
if ( n >= 1132 && n < 1133 ) {
	BLK = 1;
} else
if ( n >= 1133 && n < 1134 ) {
	BLK = 2;
} else
if ( n >= 1134 && n < 1136 ) {
	BLK = 0;
} else
if ( n >= 1136 && n < 1137 ) {
	BLK = 3;
} else
if ( n >= 1137 && n < 1143 ) {
	BLK = 2;
} else
if ( n >= 1143 && n < 1145 ) {
	BLK = 3;
} else
if ( n >= 1145 && n < 1154 ) {
	BLK = 0;
} else
if ( n >= 1154 && n < 1155 ) {
	BLK = 1;
} else
if ( n >= 1155 && n < 1157 ) {
	BLK = 3;
} else
if ( n >= 1157 && n < 1158 ) {
	BLK = 0;
} else
if ( n >= 1158 && n < 1159 ) {
	BLK = 1;
} else
if ( n >= 1159 && n < 1161 ) {
	BLK = 2;
} else
if ( n >= 1161 && n < 1166 ) {
	BLK = 0;
} else
if ( n >= 1166 && n < 1167 ) {
	BLK = 1;
} else
if ( n >= 1167 && n < 1169 ) {
	BLK = 3;
} else
if ( n >= 1169 && n < 1174 ) {
	BLK = 2;
} else
if ( n >= 1174 && n < 1175 ) {
	BLK = 1;
} else
if ( n >= 1175 && n < 1177 ) {
	BLK = 3;
} else
if ( n >= 1177 && n < 1178 ) {
	BLK = 0;
} else
if ( n >= 1178 && n < 1187 ) {
	BLK = 2;
} else
if ( n >= 1187 && n < 1188 ) {
	BLK = 1;
} else
if ( n >= 1188 && n < 1189 ) {
	BLK = 0;
} else
if ( n >= 1189 && n < 1191 ) {
	BLK = 3;
} else
if ( n >= 1191 && n < 1195 ) {
	BLK = 2;
} else
if ( n >= 1195 && n < 1196 ) {
	BLK = 3;
} else
if ( n >= 1196 && n < 1204 ) {
	BLK = 0;
} else
if ( n >= 1204 && n < 1205 ) {
	BLK = 2;
} else
if ( n >= 1205 && n < 1209 ) {
	BLK = 3;
} else
if ( n >= 1209 && n < 1210 ) {
	BLK = 2;
} else
if ( n >= 1210 && n < 1212 ) {
	BLK = 1;
} else
if ( n >= 1212 && n < 1216 ) {
	BLK = 3;
} else
if ( n >= 1216 && n < 1219 ) {
	BLK = 0;
} else
if ( n >= 1219 && n < 1220 ) {
	BLK = 3;
} else
if ( n >= 1220 && n < 1228 ) {
	BLK = 2;
} else
if ( n >= 1228 && n < 1230 ) {
	BLK = 3;
} else
if ( n >= 1230 && n < 1237 ) {
	BLK = 0;
} else
if ( n >= 1237 && n < 1240 ) {
	BLK = 2;
} else
if ( n >= 1240 && n < 1245 ) {
	BLK = 3;
} else
if ( n >= 1245 && n < 1246 ) {
	BLK = 1;
} else
if ( n >= 1246 && n < 1247 ) {
	BLK = 0;
} else
if ( n >= 1247 && n < 1251 ) {
	BLK = 3;
} else
if ( n >= 1251 && n < 1255 ) {
	BLK = 0;
} else
if ( n >= 1255 && n < 1256 ) {
	BLK = 2;
} else
if ( n >= 1256 && n < 1257 ) {
	BLK = 3;
} else
if ( n >= 1257 && n < 1258 ) {
	BLK = 1;
} else
if ( n >= 1258 && n < 1264 ) {
	BLK = 2;
} else
if ( n >= 1264 && n < 1266 ) {
	BLK = 0;
} else
if ( n >= 1266 && n < 1270 ) {
	BLK = 3;
} else
if ( n >= 1270 && n < 1271 ) {
	BLK = 1;
} else
if ( n >= 1271 && n < 1272 ) {
	BLK = 2;
} else
if ( n >= 1272 && n < 1276 ) {
	BLK = 3;
} else
if ( n >= 1276 && n < 1277 ) {
	BLK = 0;
} else
if ( n >= 1277 && n < 1278 ) {
	BLK = 2;
} else
if ( n >= 1278 && n < 1280 ) {
	BLK = 3;
} else
if ( n >= 1280 && n < 1284 ) {
	BLK = 0;
} else
if ( n >= 1284 && n < 1296 ) {
	BLK = 3;
} else
if ( n >= 1296 && n < 1297 ) {
	BLK = 2;
} else
if ( n >= 1297 && n < 1300 ) {
	BLK = 0;
} else
if ( n >= 1300 && n < 1304 ) {
	BLK = 2;
} else
if ( n >= 1304 && n < 1308 ) {
	BLK = 3;
} else
if ( n >= 1308 && n < 1309 ) {
	BLK = 2;
} else
if ( n >= 1309 && n < 1311 ) {
	BLK = 0;
} else
if ( n >= 1311 && n < 1312 ) {
	BLK = 3;
} else
if ( n >= 1312 && n < 1316 ) {
	BLK = 2;
} else
if ( n >= 1316 && n < 1319 ) {
	BLK = 0;
} else
if ( n >= 1319 && n < 1322 ) {
	BLK = 3;
} else
if ( n >= 1322 && n < 1323 ) {
	BLK = 2;
} else
if ( n >= 1323 && n < 1333 ) {
	BLK = 0;
} else
if ( n >= 1333 && n < 1335 ) {
	BLK = 3;
} else
if ( n >= 1335 && n < 1336 ) {
	BLK = 2;
} else
if ( n >= 1336 && n < 1337 ) {
	BLK = 0;
} else
if ( n >= 1337 && n < 1338 ) {
	BLK = 1;
} else
if ( n >= 1338 && n < 1346 ) {
	BLK = 3;
} else
if ( n >= 1346 && n < 1349 ) {
	BLK = 0;
} else
if ( n >= 1349 && n < 1351 ) {
	BLK = 2;
} else
if ( n >= 1351 && n < 1352 ) {
	BLK = 1;
} else
if ( n >= 1352 && n < 1353 ) {
	BLK = 0;
} else
if ( n >= 1353 && n < 1356 ) {
	BLK = 2;
} else
if ( n >= 1356 && n < 1357 ) {
	BLK = 1;
} else
if ( n >= 1357 && n < 1391 ) {
	BLK = 0;
} else
if ( n >= 1391 && n < 1397 ) {
	BLK = 3;
} else
if ( n >= 1397 && n < 1398 ) {
	BLK = 1;
} else
if ( n >= 1398 && n < 1402 ) {
	BLK = 2;
} else
if ( n >= 1402 && n < 1403 ) {
	BLK = 1;
} else
if ( n >= 1403 && n < 1405 ) {
	BLK = 3;
} else
if ( n >= 1405 && n < 1406 ) {
	BLK = 2;
} else
if ( n >= 1406 && n < 1409 ) {
	BLK = 0;
} else
if ( n >= 1409 && n < 1410 ) {
	BLK = 2;
} else
if ( n >= 1410 && n < 1411 ) {
	BLK = 1;
} else
if ( n >= 1411 && n < 1414 ) {
	BLK = 3;
} else
if ( n >= 1414 && n < 1422 ) {
	BLK = 0;
} else
if ( n >= 1422 && n < 1453 ) {
	BLK = 3;
} else
if ( n >= 1453 && n < 1454 ) {
	BLK = 2;
} else
if ( n >= 1454 && n < 1455 ) {
	BLK = 0;
} else
if ( n >= 1455 && n < 1458 ) {
	BLK = 3;
} else
if ( n >= 1458 && n < 1459 ) {
	BLK = 0;
} else
if ( n >= 1459 && n < 1469 ) {
	BLK = 2;
} else
if ( n >= 1469 && n < 1470 ) {
	BLK = 0;
} else
if ( n >= 1470 && n < 1475 ) {
	BLK = 3;
} else
if ( n >= 1475 && n < 1476 ) {
	BLK = 0;
} else
if ( n >= 1476 && n < 1481 ) {
	BLK = 2;
} else
if ( n >= 1481 && n < 1482 ) {
	BLK = 0;
} else
if ( n >= 1482 && n < 1487 ) {
	BLK = 3;
} else
if ( n >= 1487 && n < 1488 ) {
	BLK = 1;
} else
if ( n >= 1488 && n < 1489 ) {
	BLK = 2;
} else
if ( n >= 1489 && n < 1505 ) {
	BLK = 3;
} else
if ( n >= 1505 && n < 1506 ) {
	BLK = 0;
} else
if ( n >= 1506 && n < 1511 ) {
	BLK = 2;
} else
if ( n >= 1511 && n < 1512 ) {
	BLK = 0;
} else
if ( n >= 1512 && n < 1513 ) {
	BLK = 3;
} else
if ( n >= 1513 && n < 1515 ) {
	BLK = 2;
} else
if ( n >= 1515 && n < 1516 ) {
	BLK = 0;
} else
if ( n >= 1516 && n < 1517 ) {
	BLK = 1;
} else
if ( n >= 1517 && n < 1534 ) {
	BLK = 3;
} else
if ( n >= 1534 && n < 1537 ) {
	BLK = 2;
} else
if ( n >= 1537 && n < 1538 ) {
	BLK = 0;
} else
if ( n >= 1538 && n < 1541 ) {
	BLK = 3;
} else
if ( n >= 1541 && n < 1548 ) {
	BLK = 2;
} else
if ( n >= 1548 && n < 1561 ) {
	BLK = 3;
} else
if ( n >= 1561 && n < 1565 ) {
	BLK = 2;
} else
if ( n >= 1565 && n < 1566 ) {
	BLK = 0;
} else
if ( n >= 1566 && n < 1567 ) {
	BLK = 1;
} else
if ( n >= 1567 && n < 1568 ) {
	BLK = 3;
} else
if ( n >= 1568 && n < 1570 ) {
	BLK = 2;
} else
if ( n >= 1570 && n < 1578 ) {
	BLK = 0;
} else
if ( n >= 1578 && n < 1581 ) {
	BLK = 3;
} else
if ( n >= 1581 && n < 1582 ) {
	BLK = 2;
} else
if ( n >= 1582 && n < 1583 ) {
	BLK = 0;
} else
if ( n >= 1583 && n < 1585 ) {
	BLK = 3;
} else
if ( n >= 1585 && n < 1586 ) {
	BLK = 2;
} else
if ( n >= 1586 && n < 1588 ) {
	BLK = 0;
} else
if ( n >= 1588 && n < 1593 ) {
	BLK = 3;
} else
if ( n >= 1593 && n < 1594 ) {
	BLK = 1;
} else
if ( n >= 1594 && n < 1595 ) {
	BLK = 2;
} else
if ( n >= 1595 && n < 1596 ) {
	BLK = 0;
} else
if ( n >= 1596 && n < 1597 ) {
	BLK = 1;
} else
if ( n >= 1597 && n < 1598 ) {
	BLK = 3;
} else
if ( n >= 1598 && n < 1599 ) {
	BLK = 2;
} else
if ( n >= 1599 && n < 1600 ) {
	BLK = 0;
} else
if ( n >= 1600 && n < 1615 ) {
	BLK = 3;
} else
if ( n >= 1615 && n < 1618 ) {
	BLK = 0;
} else
if ( n >= 1618 && n < 1619 ) {
	BLK = 2;
} else
if ( n >= 1619 && n < 1624 ) {
	BLK = 3;
} else
if ( n >= 1624 && n < 1625 ) {
	BLK = 1;
} else
if ( n >= 1625 && n < 1626 ) {
	BLK = 2;
} else
if ( n >= 1626 && n < 1631 ) {
	BLK = 0;
} else
if ( n >= 1631 && n < 1636 ) {
	BLK = 2;
} else
if ( n >= 1636 && n < 1644 ) {
	BLK = 3;
} else
if ( n >= 1644 && n < 1645 ) {
	BLK = 1;
} else
if ( n >= 1645 && n < 1652 ) {
	BLK = 0;
} else
if ( n >= 1652 && n < 1673 ) {
	BLK = 3;
} else
if ( n >= 1673 && n < 1675 ) {
	BLK = 0;
} else
if ( n >= 1675 && n < 1676 ) {
	BLK = 2;
} else
if ( n >= 1676 && n < 1680 ) {
	BLK = 3;
} else
if ( n >= 1680 && n < 1681 ) {
	BLK = 2;
} else
if ( n >= 1681 && n < 1683 ) {
	BLK = 0;
} else
if ( n >= 1683 && n < 1691 ) {
	BLK = 3;
} else
if ( n >= 1691 && n < 1692 ) {
	BLK = 2;
} else
if ( n >= 1692 && n < 1693 ) {
	BLK = 0;
} else
if ( n >= 1693 && n < 1704 ) {
	BLK = 3;
} else
if ( n >= 1704 && n < 1705 ) {
	BLK = 0;
} else
if ( n >= 1705 && n < 1707 ) {
	BLK = 2;
} else
if ( n >= 1707 && n < 1759 ) {
	BLK = 3;
} else
if ( n >= 1759 && n < 1762 ) {
	BLK = 0;
} else
if ( n >= 1762 && n < 1767 ) {
	BLK = 2;
} else
if ( n >= 1767 && n < 1768 ) {
	BLK = 0;
} else
if ( n >= 1768 && n < 1807 ) {
	BLK = 3;
} else
if ( n >= 1807 && n < 1808 ) {
	BLK = 0;
} else
if ( n >= 1808 && n < 1811 ) {
	BLK = 2;
} else
if ( n >= 1811 && n < 1812 ) {
	BLK = 1;
} else
if ( n >= 1812 && n < 1813 ) {
	BLK = 3;
} else
if ( n >= 1813 && n < 1814 ) {
	BLK = 0;
} else
if ( n >= 1814 && n < 1815 ) {
	BLK = 2;
} else
if ( n >= 1815 && n < 1827 ) {
	BLK = 3;
} else
if ( n >= 1827 && n < 1830 ) {
	BLK = 0;
} else
if ( n >= 1830 && n < 1836 ) {
	BLK = 3;
} else
if ( n >= 1836 && n < 1843 ) {
	BLK = 2;
} else
if ( n >= 1843 && n < 1858 ) {
	BLK = 3;
} else
if ( n >= 1858 && n < 1859 ) {
	BLK = 2;
} else
if ( n >= 1859 && n < 1872 ) {
	BLK = 1;
} else
if ( n >= 1872 && n < 1881 ) {
	BLK = 3;
} else
if ( n >= 1881 && n < 1886 ) {
	BLK = 2;
} else
if ( n >= 1886 && n < 1887 ) {
	BLK = 3;
} else
if ( n >= 1887 && n < 1888 ) {
	BLK = 1;
} else
if ( n >= 1888 && n < 1891 ) {
	BLK = 2;
} else
if ( n >= 1891 && n < 1892 ) {
	BLK = 0;
} else
if ( n >= 1892 && n < 1893 ) {
	BLK = 1;
} else
if ( n >= 1893 && n < 1903 ) {
	BLK = 2;
} else
if ( n >= 1903 && n < 1904 ) {
	BLK = 1;
} else
if ( n >= 1904 && n < 1919 ) {
	BLK = 3;
} else
if ( n >= 1919 && n < 1920 ) {
	BLK = 2;
} else
if ( n >= 1920 && n < 1921 ) {
	BLK = 0;
} else
if ( n >= 1921 && n < 1925 ) {
	BLK = 3;
} else
if ( n >= 1925 && n < 1944 ) {
	BLK = 2;
} else
if ( n >= 1944 && n < 1945 ) {
	BLK = 3;
} else
if ( n >= 1945 && n < 1946 ) {
	BLK = 1;
} else
if ( n >= 1946 && n < 1979 ) {
	BLK = 2;
} else
if ( n >= 1979 && n < 1981 ) {
	BLK = 3;
} else
if ( n >= 1981 && n < 1982 ) {
	BLK = 1;
} else
if ( n >= 1982 && n < 1998 ) {
	BLK = 2;
} else
if ( n >= 1998 && n < 1999 ) {
	BLK = 1;
} else
if ( n >= 1999 && n < 2000 ) {
	BLK = 3;
} else
if ( n >= 2000 && n < 2014 ) {
	BLK = 2;
} else
if ( n >= 2014 && n < 2015 ) {
	BLK = 3;
} else
if ( n >= 2015 && n < 2016 ) {
	BLK = 1;
} else
if ( n >= 2016 && n < 2031 ) {
	BLK = 2;
} else
if ( n >= 2031 && n < 2032 ) {
	BLK = 1;
} else
if ( n >= 2032 && n < 2033 ) {
	BLK = 0;
} else
if ( n >= 2033 && n < 2039 ) {
	BLK = 2;
} else
if ( n >= 2039 && n < 2115 ) {
	BLK = 3;
} else
if ( n >= 2115 && n < 2117 ) {
	BLK = 2;
} else
if ( n >= 2117 && n < 2118 ) {
	BLK = 1;
} else
if ( n >= 2118 && n < 2127 ) {
	BLK = 3;
} else
if ( n >= 2127 && n < 2128 ) {
	BLK = 1;
} else
if ( n >= 2128 && n < 2129 ) {
	BLK = 2;
} else
if ( n >= 2129 && n < 2174 ) {
	BLK = 3;
} else
if ( n >= 2174 && n < 2175 ) {
	BLK = 2;
} else
if ( n >= 2175 && n < 2182 ) {
	BLK = 1;
} else
if ( n >= 2182 && n < 2185 ) {
	BLK = 3;
} else
if ( n >= 2185 && n < 2186 ) {
	BLK = 2;
} else
if ( n >= 2186 && n < 2188 ) {
	BLK = 1;
} else
if ( n >= 2188 && n < 2260 ) {
	BLK = 3;
} else
if ( n >= 2260 && n < 2263 ) {
	BLK = 2;
} else
if ( n >= 2263 && n < 2265 ) {
	BLK = 1;
} else
if ( n >= 2265 && n < 2318 ) {
	BLK = 3;
} else
if ( n >= 2318 && n < 2337 ) {
	BLK = 2;
} else
if ( n >= 2337 && n < 2362 ) {
	BLK = 3;
} else
if ( n >= 2362 && n < 2400 ) {
	BLK = 2;
} else
if ( n >= 2400 && n < 2401 ) {
	BLK = 3;
} else
if ( n >= 2401 && n < 2402 ) {
	BLK = 1;
} else
if ( n >= 2402 && n < 2421 ) {
	BLK = 2;
} else
if ( n >= 2421 && n < 2424 ) {
	BLK = 1;
} else
if ( n >= 2424 && n < 2453 ) {
	BLK = 2;
} else
if ( n >= 2453 && n < 2467 ) {
	BLK = 3;
} else
if ( n >= 2467 && n < 2491 ) {
	BLK = 2;
} else
if ( n >= 2491 && n < 2501 ) {
	BLK = 3;
} else
if ( n >= 2501 && n < 2503 ) {
	BLK = 2;
} else
if ( n >= 2503 && n < 2504 ) {
	BLK = 1;
} else
if ( n >= 2504 && n < 2514 ) {
	BLK = 3;
} else
if ( n >= 2514 && n < 2515 ) {
	BLK = 2;
} else
if ( n >= 2515 && n < 2523 ) {
	BLK = 1;
} else
if ( n >= 2523 && n < 2566 ) {
	BLK = 3;
} else
if ( n >= 2566 && n < 2567 ) {
	BLK = 1;
} else
if ( n >= 2567 && n < 2569 ) {
	BLK = 2;
} else
if ( n >= 2569 && n < 2573 ) {
	BLK = 3;
} else
if ( n >= 2573 && n < 2576 ) {
	BLK = 1;
} else
if ( n >= 2576 && n < 2609 ) {
	BLK = 3;
} else
if ( n >= 2609 && n < 2610 ) {
	BLK = 1;
} else
if ( n >= 2610 && n < 2656 ) {
	BLK = 2;
} else
if ( n >= 2656 && n < 2659 ) {
	BLK = 3;
} else
if ( n >= 2659 && n < 2660 ) {
	BLK = 1;
} else
if ( n >= 2660 && n < 2672 ) {
	BLK = 2;
} else
if ( n >= 2672 && n < 2731 ) {
	BLK = 3;
} else
if ( n >= 2731 && n < 2734 ) {
	BLK = 2;
} else
if ( n >= 2734 && n < 2735 ) {
	BLK = 1;
} else
if ( n >= 2735 && n < 2812 ) {
	BLK = 3;
} else
if ( n >= 2812 && n < 2814 ) {
	BLK = 1;
} else
if ( n >= 2814 && n < 2818 ) {
	BLK = 2;
} else
if ( n >= 2818 && n < 2838 ) {
	BLK = 3;
} else
if ( n >= 2838 && n < 2839 ) {
	BLK = 1;
} else
if ( n >= 2839 && n < 2866 ) {
	BLK = 2;
} else
if ( n >= 2866 && n < 2901 ) {
	BLK = 3;
} else
if ( n >= 2901 && n < 2907 ) {
	BLK = 1;
} else
if ( n >= 2907 && n < 2956 ) {
	BLK = 2;
} else
if ( n >= 2956 && n < 2975 ) {
	BLK = 3;
} else
if ( n >= 2975 && n < 2977 ) {
	BLK = 2;
} else
if ( n >= 2977 && n < 2978 ) {
	BLK = 1;
} else
if ( n >= 2978 && n < 2983 ) {
	BLK = 3;
} else
if ( n >= 2983 && n < 2984 ) {
	BLK = 2;
} else
if ( n >= 2984 && n < 2988 ) {
	BLK = 1;
} else
if ( n >= 2988 && n < 2998 ) {
	BLK = 3;
} else
if ( n >= 2998 && n < 3009 ) {
	BLK = 2;
} else
if ( n >= 3009 && n < 3070 ) {
	BLK = 3;
} else
if ( n >= 3070 && n < 3071 ) {
	BLK = 2;
} else
if ( n >= 3071 && n < 3072 ) {
	BLK = 1;
} else
if ( n >= 3072 && n < 3120 ) {
	BLK = 3;
} else
if ( n >= 3120 && n < 3121 ) {
	BLK = 2;
} else
if ( n >= 3121 && n < 3122 ) {
	BLK = 1;
} else
if ( n >= 3122 && n < 3124 ) {
	BLK = 3;
} else
if ( n >= 3124 && n < 3140 ) {
	BLK = 2;
} else
if ( n >= 3140 && n < 3141 ) {
	BLK = 3;
} else
if ( n >= 3141 && n < 3142 ) {
	BLK = 1;
} else
if ( n >= 3142 && n < 3168 ) {
	BLK = 2;
} else
if ( n >= 3168 && n < 3170 ) {
	BLK = 1;
} else
if ( n >= 3170 && n < 3173 ) {
	BLK = 3;
} else
if ( n >= 3173 && n < 3230 ) {
	BLK = 2;
} else
if ( n >= 3230 && n < 3231 ) {
	BLK = 3;
} else
if ( n >= 3231 && n < 3232 ) {
	BLK = 1;
} else
if ( n >= 3232 && n < 3247 ) {
	BLK = 2;
} else
if ( n >= 3247 && n < 3248 ) {
	BLK = 3;
} else
if ( n >= 3248 && n < 3249 ) {
	BLK = 1;
} else
if ( n >= 3249 && n < 3266 ) {
	BLK = 2;
} else
if ( n >= 3266 && n < 3285 ) {
	BLK = 3;
} else
if ( n >= 3285 && n < 3291 ) {
	BLK = 2;
} else
if ( n >= 3291 && n < 3292 ) {
	BLK = 3;
} else
if ( n >= 3292 && n < 3296 ) {
	BLK = 1;
} else
if ( n >= 3296 && n < 3311 ) {
	BLK = 2;
} else
if ( n >= 3311 && n < 3330 ) {
	BLK = 3;
} else
if ( n >= 3330 && n < 3341 ) {
	BLK = 2;
} else
if ( n >= 3341 && n < 3342 ) {
	BLK = 3;
} else
if ( n >= 3342 && n < 3349 ) {
	BLK = 1;
} else
if ( n >= 3349 && n < 3381 ) {
	BLK = 2;
} else
if ( n >= 3381 && n < 3382 ) {
	BLK = 1;
} else
if ( n >= 3382 && n < 3394 ) {
	BLK = 3;
} else
if ( n >= 3394 && n < 3415 ) {
	BLK = 2;
} else
if ( n >= 3415 && n < 3423 ) {
	BLK = 3;
} else
if ( n >= 3423 && n < 3426 ) {
	BLK = 2;
} else
if ( n >= 3426 && n < 3427 ) {
	BLK = 1;
} else
if ( n >= 3427 && n < 3428 ) {
	BLK = 3;
} else
if ( n >= 3428 && n < 3522 ) {
	BLK = 2;
} else
if ( n >= 3522 && n < 3523 ) {
	BLK = 3;
} else
if ( n >= 3523 && n < 3527 ) {
	BLK = 1;
} else
if ( n >= 3527 && n < 3615 ) {
	BLK = 2;
} else
if ( n >= 3615 && n < 3618 ) {
	BLK = 3;
} else
if ( n >= 3618 && n < 3631 ) {
	BLK = 2;
} else
if ( n >= 3631 && n < 3634 ) {
	BLK = 3;
} else
if ( n >= 3634 && n < 3635 ) {
	BLK = 1;
} else
if ( n >= 3635 && n < 3699 ) {
	BLK = 2;
} else
if ( n >= 3699 && n < 3700 ) {
	BLK = 3;
} else
if ( n >= 3700 && n < 3713 ) {
	BLK = 1;
} else
if ( n >= 3713 && n < 3793 ) {
	BLK = 2;
} else
if ( n >= 3793 && n < 3794 ) {
	BLK = 3;
} else
if ( n >= 3794 && n < 3795 ) {
	BLK = 1;
} else
if ( n >= 3795 && n < 3818 ) {
	BLK = 2;
} else
if ( n >= 3818 && n < 3819 ) {
	BLK = 1;
} else
if ( n >= 3819 && n < 3826 ) {
	BLK = 3;
} else
if ( n >= 3826 && n < 3861 ) {
	BLK = 2;
} else
if ( n >= 3861 && n < 3862 ) {
	BLK = 1;
} else
if ( n >= 3862 && n < 3863 ) {
	BLK = 3;
} else
if ( n >= 3863 && n < 3986 ) {
	BLK = 2;
} else
if ( n >= 3986 && n < 3987 ) {
	BLK = 1;
} else
if ( n >= 3987 && n < 3990 ) {
	BLK = 3;
} else
if ( n >= 3990 && n < 4010 ) {
	BLK = 1;
} else
if ( n >= 4010 && n < 4124 ) {
	BLK = 2;
} else
if ( n >= 4124 && n < 4127 ) {
	BLK = 1;
} else
if ( n >= 4127 && n < 4129 ) {
	BLK = 3;
} else
if ( n >= 4129 && n < 4206 ) {
	BLK = 2;
} else
if ( n >= 4206 && n < 4210 ) {
	BLK = 1;
} else
if ( n >= 4210 && n < 4212 ) {
	BLK = 3;
} else
if ( n >= 4212 && n < 4725 ) {
	BLK = 2;
} else
if ( n >= 4725 && n < 4730 ) {
	BLK = 3;
} else
if ( n >= 4730 && n < 4739 ) {
	BLK = 1;
} else
if ( n >= 4739 && n < 5115 ) {
	BLK = 2;
} else
if ( n >= 5115 && n < 5123 ) {
	BLK = 1;
} else
if ( n >= 5123 && n < 5128 ) {
	BLK = 3;
} else
if ( n >= 5128 && n < 6353 ) {
	BLK = 2;
} else
if ( n >= 6353 && n < 6377 ) {
	BLK = 1;
} else
if ( n >= 6377 && n < 6387 ) {
	BLK = 3;
} else
if ( n >= 6387 && n < 6422 ) {
	BLK = 2;
} else
if ( n >= 6422 && n < 6433 ) {
	BLK = 1;
} else
if ( n >= 6433 && n < 6436 ) {
	BLK = 3;
} else
if ( n >= 6436 && n < 17792 ) {
	BLK = 2;
} else
if ( n >= 17792 && n < 18121 ) {
	BLK = 1;
} else
if ( n >= 18121 && n < 26605 ) {
	BLK = 2;
} else
if ( n >= 26605 && n < 26963 ) {
	BLK = 1;
} else
if ( n >= 26963 && n < 31341 ) {
	BLK = 2;
} else
if ( n >= 31341 && n < 31760 ) {
	BLK = 1;
} else
if ( n >= 31760 && n < 37052 ) {
	BLK = 2;
} else
if ( n >= 37052 && n < 38505 ) {
	BLK = 1;
} else
if ( n >= 38505 && n < 47676 ) {
	BLK = 2;
} else
if ( n >= 47676 && n < 48217 ) {
	BLK = 1;
} else
if ( n >= 48217 && n < 65859 ) {
	BLK = 2;
} else
if ( n >= 65859 && n < 66346 ) {
	BLK = 1;
} else
if ( n >= 66346 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
