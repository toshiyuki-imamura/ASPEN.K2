#if __isHALF__
#define GEMV_N     HGEMV_N
#define GEMV_T     HGEMV_T
#define GEMV_C     HGEMV_T
#define SYMV_U     HSYMV_U
#define SYMV_L     HSYMV_L
#define TEST_GEMV_N     "test-hgemv-n"
#define TEST_GEMV_T     "test-hgemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-hsymv-u"
#define TEST_SYMV_L     "test-hsymv-l"
#define TEST2_GEMV_N    "test2-hgemv-n"
#define TEST2_GEMV_T    "test2-hgemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-hsymv-u"
#define TEST2_SYMV_L    "test2-hsymv-l"
#define NAME_GEMV_N     "HGEMV -N"
#define NAME_GEMV_T     "HGEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "HSYMV -U"
#define NAME_SYMV_L     "HSYMV -L"
#define ASPEN_GEMV_n    ASPEN_HGEMV_n
#define ASPEN_GEMV_t    ASPEN_HGEMV_t
#define ASPEN_GEMV_c    ASPEN_HGEMV_t
#define ASPEN_SYMVu     ASPEN_HSYMVu
#define ASPEN_SYMVl     ASPEN_HSYMVl
#define cblas_gemv      hgemv
#define cblas_symv      hsymv
#endif

#if __isFLOAT__
#define GEMV_N     SGEMV_N
#define GEMV_T     SGEMV_T
#define GEMV_C     SGEMV_T
#define SYMV_U     SSYMV_U
#define SYMV_L     SSYMV_L
#define TEST_GEMV_N     "test-sgemv-n"
#define TEST_GEMV_T     "test-sgemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-ssymv-u"
#define TEST_SYMV_L     "test-ssymv-l"
#define TEST2_GEMV_N    "test2-sgemv-n"
#define TEST2_GEMV_T    "test2-sgemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-ssymv-u"
#define TEST2_SYMV_L    "test2-ssymv-l"
#define NAME_GEMV_N     "SGEMV -N"
#define NAME_GEMV_T     "SGEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "SSYMV -U"
#define NAME_SYMV_L     "SSYMV -L"
#define ASPEN_GEMV_n    ASPEN_SGEMV_n
#define ASPEN_GEMV_t    ASPEN_SGEMV_t
#define ASPEN_GEMV_c    ASPEN_SGEMV_t
#define ASPEN_SYMVu     ASPEN_SSYMVu
#define ASPEN_SYMVl     ASPEN_SSYMVl
#define cblas_gemv      cblas_sgemv
#define cblas_symv      cblas_ssymv
#endif

#if __isDOUBLE__
#define GEMV_N     DGEMV_N
#define GEMV_T     DGEMV_T
#define GEMV_C     DGEMV_T
#define SYMV_U     DSYMV_U
#define SYMV_L     DSYMV_L
#define TEST_GEMV_N     "test-dgemv-n"
#define TEST_GEMV_T     "test-dgemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-dsymv-u"
#define TEST_SYMV_L     "test-dsymv-l"
#define TEST2_GEMV_N    "test2-dgemv-n"
#define TEST2_GEMV_T    "test2-dgemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-dsymv-u"
#define TEST2_SYMV_L    "test2-dsymv-l"
#define NAME_GEMV_N     "DGEMV -N"
#define NAME_GEMV_T     "DGEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "DSYMV -U"
#define NAME_SYMV_L     "DSYMV -L"
#define ASPEN_GEMV_n    ASPEN_DGEMV_n
#define ASPEN_GEMV_t    ASPEN_DGEMV_t
#define ASPEN_GEMV_c    ASPEN_DGEMV_t
#define ASPEN_SYMVu     ASPEN_DSYMVu
#define ASPEN_SYMVl     ASPEN_DSYMVl
#define cblas_gemv      cblas_dgemv
#define cblas_symv      cblas_dsymv
#endif

#if __isDD__
#define GEMV_N     WGEMV_N
#define GEMV_T     WGEMV_T
#define GEMV_C     WGEMV_T
#define SYMV_U     WSYMV_U
#define SYMV_L     WSYMV_L
#define TEST_GEMV_N     "test-wgemv-n"
#define TEST_GEMV_T     "test-wgemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-wsymv-u"
#define TEST_SYMV_L     "test-wsymv-l"
#define TEST2_GEMV_N    "test2-wgemv-n"
#define TEST2_GEMV_T    "test2-wgemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-wsymv-u"
#define TEST2_SYMV_L    "test2-wsymv-l"
#define NAME_GEMV_N     "WGEMV -N"
#define NAME_GEMV_T     "WGEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "WSYMV -U"
#define NAME_SYMV_L     "WSYMV -L"
#define ASPEN_GEMV_n    ASPEN_WGEMV_n
#define ASPEN_GEMV_t    ASPEN_WGEMV_t
#define ASPEN_GEMV_c    ASPEN_WGEMV_t
#define ASPEN_SYMVu     ASPEN_WSYMVu
#define ASPEN_SYMVl     ASPEN_WSYMVl
#define cblas_gemv      wgemv
#define cblas_symv      wsymv
#endif

#if __isHALF_COMPLEX__
#define GEMV_N     KGEMV_N
#define GEMV_T     KGEMV_T
#define GEMV_C     KGEMV_C
#define HEMV_U     KHEMV_U
#define HEMV_L     KHEMV_L
#define TEST_GEMV_N     "test-kgemv-n"
#define TEST_GEMV_T     "test-kgemv-t"
#define TEST_GEMV_C     "test-kgemv-c"
#define TEST_HEMV_U     "test-khemv-u"
#define TEST_HEMV_L     "test-khemv-l"
#define TEST2_GEMV_N    "test2-kgemv-n"
#define TEST2_GEMV_T    "test2-kgemv-t"
#define TEST2_GEMV_C    "test2-kgemv-c"
#define TEST2_HEMV_U    "test2-khemv-u"
#define TEST2_HEMV_L    "test2-khemv-l"
#define NAME_GEMV_N     "KGEMV -N"
#define NAME_GEMV_T     "KGEMV -T"
#define NAME_GEMV_C     "KGEMV -C"
#define NAME_HEMV_U     "KHEMV -U"
#define NAME_HEMV_L     "KHEMV -L"
#define ASPEN_GEMV_n    ASPEN_KGEMV_n
#define ASPEN_GEMV_t    ASPEN_KGEMV_t
#define ASPEN_GEMV_c    ASPEN_KGEMV_c
#define ASPEN_HEMVu     ASPEN_KHEMVu
#define ASPEN_HEMVl     ASPEN_KHEMVl
#define cblas_hemv      khemv
#define cblas_gemv      kgemv
#endif

#if __isFLOAT_COMPLEX__
#define GEMV_N     CGEMV_N
#define GEMV_T     CGEMV_T
#define GEMV_C     CGEMV_C
#define HEMV_U     CHEMV_U
#define HEMV_L     CHEMV_L
#define TEST_GEMV_N     "test-cgemv-n"
#define TEST_GEMV_T     "test-cgemv-t"
#define TEST_GEMV_C     "test-cgemv-c"
#define TEST_HEMV_U     "test-chemv-u"
#define TEST_HEMV_L     "test-chemv-l"
#define TEST2_GEMV_N    "test2-cgemv-n"
#define TEST2_GEMV_T    "test2-cgemv-t"
#define TEST2_GEMV_C    "test2-cgemv-c"
#define TEST2_HEMV_U    "test2-chemv-u"
#define TEST2_HEMV_L    "test2-chemv-l"
#define NAME_GEMV_N     "CGEMV -N"
#define NAME_GEMV_T     "CGEMV -T"
#define NAME_GEMV_C     "CGEMV -C"
#define NAME_HEMV_U     "CHEMV -U"
#define NAME_HEMV_L     "CHEMV -L"
#define ASPEN_GEMV_n    ASPEN_CGEMV_n
#define ASPEN_GEMV_t    ASPEN_CGEMV_t
#define ASPEN_GEMV_c    ASPEN_CGEMV_c
#define ASPEN_HEMVu     ASPEN_CHEMVu
#define ASPEN_HEMVl     ASPEN_CHEMVl
#define cblas_hemv      cblas_chemv
#define cblas_gemv      cblas_cgemv
#endif

#if __isDOUBLE_COMPLEX__
#define GEMV_N     ZGEMV_N
#define GEMV_T     ZGEMV_T
#define GEMV_C     ZGEMV_C
#define HEMV_U     ZHEMV_U
#define HEMV_L     ZHEMV_L
#define TEST_GEMV_N     "test-zgemv-n"
#define TEST_GEMV_T     "test-zgemv-t"
#define TEST_GEMV_C     "test-zgemv-c"
#define TEST_HEMV_U     "test-zhemv-u"
#define TEST_HEMV_L     "test-zhemv-l"
#define TEST2_GEMV_N    "test2-zgemv-n"
#define TEST2_GEMV_T    "test2-zgemv-t"
#define TEST2_GEMV_C    "test2-zgemv-c"
#define TEST2_HEMV_U    "test2-zhemv-u"
#define TEST2_HEMV_L    "test2-zhemv-l"
#define NAME_GEMV_N     "ZGEMV -N"
#define NAME_GEMV_T     "ZGEMV -T"
#define NAME_GEMV_C     "ZGEMV -C"
#define NAME_HEMV_U     "ZHEMV -U"
#define NAME_HEMV_L     "ZHEMV -L"
#define ASPEN_GEMV_n    ASPEN_ZGEMV_n
#define ASPEN_GEMV_t    ASPEN_ZGEMV_t
#define ASPEN_GEMV_c    ASPEN_ZGEMV_c
#define ASPEN_HEMVu     ASPEN_ZHEMVu
#define ASPEN_HEMVl     ASPEN_ZHEMVl
#define cblas_gemv      cblas_zgemv
#define cblas_hemv      cblas_zhemv
#endif

#if __isDD_COMPLEX__
#define GEMV_N     UGEMV_N
#define GEMV_T     UGEMV_T
#define GEMV_C     UGEMV_C
#define HEMV_U     UHEMV_U
#define HEMV_L     UHEMV_L
#define TEST_GEMV_N     "test-ugemv-n"
#define TEST_GEMV_T     "test-ugemv-t"
#define TEST_GEMV_C     "test-ugemv-c"
#define TEST_HEMV_U     "test-uhemv-u"
#define TEST_HEMV_L     "test-uhemv-l"
#define TEST2_GEMV_N    "test2-ugemv-n"
#define TEST2_GEMV_T    "test2-ugemv-t"
#define TEST2_GEMV_C    "test2-ugemv-c"
#define TEST2_HEMV_U    "test2-uhemv-u"
#define TEST2_HEMV_L    "test2-uhemv-l"
#define NAME_GEMV_N     "UGEMV -N"
#define NAME_GEMV_T     "UGEMV -T"
#define NAME_GEMV_C     "UGEMV -C"
#define NAME_HEMV_U     "UHEMV -U"
#define NAME_HEMV_L     "UHEMV -L"
#define ASPEN_GEMV_n    ASPEN_UGEMV_n
#define ASPEN_GEMV_t    ASPEN_UGEMV_t
#define ASPEN_GEMV_c    ASPEN_UGEMV_c
#define ASPEN_HEMVu     ASPEN_UHEMVu
#define ASPEN_HEMVl     ASPEN_UHEMVl
#define cblas_gemv      ugemv
#define cblas_hemv      uhemv
#endif

#if __isINT16__
#define GEMV_N     I16GEMV_N
#define GEMV_T     I16GEMV_T
#define GEMV_C     I16GEMV_T
#define SYMV_U     I16SYMV_U
#define SYMV_L     I16SYMV_L
#define TEST_GEMV_N     "test-i16gemv-n"
#define TEST_GEMV_T     "test-i16gemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-i16symv-u"
#define TEST_SYMV_L     "test-i16symv-l"
#define TEST2_GEMV_N    "test2-i16gemv-n"
#define TEST2_GEMV_T    "test2-i16gemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-i16symv-u"
#define TEST2_SYMV_L    "test2-i16symv-l"
#define NAME_GEMV_N     "I16GEMV -N"
#define NAME_GEMV_T     "I16GEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "I16SYMV -U"
#define NAME_SYMV_L     "I16SYMV -L"
#define ASPEN_GEMV_n    ASPEN_I16GEMV_n
#define ASPEN_GEMV_t    ASPEN_I16GEMV_t
#define ASPEN_GEMV_c    ASPEN_I16GEMV_t
#define ASPEN_SYMVu     ASPEN_I16SYMVu
#define ASPEN_SYMVl     ASPEN_I16SYMVl
#define cblas_gemv      i16gemv
#define cblas_symv      i16symv
#endif

#if __isINT32__
#define GEMV_N     I32GEMV_N
#define GEMV_T     I32GEMV_T
#define GEMV_C     I32GEMV_T
#define SYMV_U     I32SYMV_U
#define SYMV_L     I32SYMV_L
#define TEST_GEMV_N     "test-i32gemv-n"
#define TEST_GEMV_T     "test-i32gemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-i32symv-u"
#define TEST_SYMV_L     "test-i32symv-l"
#define TEST2_GEMV_N    "test2-i32gemv-n"
#define TEST2_GEMV_T    "test2-i32gemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-i32symv-u"
#define TEST2_SYMV_L    "test2-i32symv-l"
#define NAME_GEMV_N     "I32GEMV -N"
#define NAME_GEMV_T     "I32GEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "I32SYMV -U"
#define NAME_SYMV_L     "I32SYMV -L"
#define ASPEN_GEMV_n    ASPEN_I32GEMV_n
#define ASPEN_GEMV_t    ASPEN_I32GEMV_t
#define ASPEN_GEMV_c    ASPEN_I32GEMV_t
#define ASPEN_SYMVu     ASPEN_I32SYMVu
#define ASPEN_SYMVl     ASPEN_I32SYMVl
#define cblas_gemv      i32gemv
#define cblas_symv      i32symv
#endif

#if __isINT64__
#define GEMV_N     I64GEMV_N
#define GEMV_T     I64GEMV_T
#define GEMV_C     I64GEMV_T
#define SYMV_U     I64SYMV_U
#define SYMV_L     I64SYMV_L
#define TEST_GEMV_N     "test-i64gemv-n"
#define TEST_GEMV_T     "test-i64gemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-i64symv-u"
#define TEST_SYMV_L     "test-i64symv-l"
#define TEST2_GEMV_N    "test2-i64gemv-n"
#define TEST2_GEMV_T    "test2-i64gemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-i64symv-u"
#define TEST2_SYMV_L    "test2-i64symv-l"
#define NAME_GEMV_N     "I64GEMV -N"
#define NAME_GEMV_T     "I64GEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "I64SYMV -U"
#define NAME_SYMV_L     "I64SYMV -L"
#define ASPEN_GEMV_n    ASPEN_I64GEMV_n
#define ASPEN_GEMV_t    ASPEN_I64GEMV_t
#define ASPEN_GEMV_c    ASPEN_I64GEMV_t
#define ASPEN_SYMVu     ASPEN_I64SYMVu
#define ASPEN_SYMVl     ASPEN_I64SYMVl
#define cblas_gemv      i64gemv
#define cblas_symv      i64symv
#endif

#if __isINT128__
#define GEMV_N     I128GEMV_N
#define GEMV_T     I128GEMV_T
#define GEMV_C     I128GEMV_T
#define SYMV_U     I128SYMV_U
#define SYMV_L     I128SYMV_L
#define TEST_GEMV_N     "test-i128gemv-n"
#define TEST_GEMV_T     "test-i128gemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-i128symv-u"
#define TEST_SYMV_L     "test-i128symv-l"
#define TEST2_GEMV_N    "test2-i128gemv-n"
#define TEST2_GEMV_T    "test2-i128gemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-i128symv-u"
#define TEST2_SYMV_L    "test2-i128symv-l"
#define NAME_GEMV_N     "I128GEMV -N"
#define NAME_GEMV_T     "I128GEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "I128SYMV -U"
#define NAME_SYMV_L     "I128SYMV -L"
#define ASPEN_GEMV_n    ASPEN_I128GEMV_n
#define ASPEN_GEMV_t    ASPEN_I128GEMV_t
#define ASPEN_GEMV_c    ASPEN_I128GEMV_t
#define ASPEN_SYMVu     ASPEN_I128SYMVu
#define ASPEN_SYMVl     ASPEN_I128SYMVl
#define cblas_gemv      i128gemv
#define cblas_symv      i128symv
#endif

#if __isBF16__
#define GEMV_N     BF16GEMV_N
#define GEMV_T     BF16GEMV_T
#define GEMV_C     BF16GEMV_T
#define SYMV_U     BF16SYMV_U
#define SYMV_L     BF16SYMV_L
#define TEST_GEMV_N     "test-bf16gemv-n"
#define TEST_GEMV_T     "test-bf16gemv-t"
#define TEST_GEMV_C     ""
#define TEST_SYMV_U     "test-bf16symv-u"
#define TEST_SYMV_L     "test-bf16symv-l"
#define TEST2_GEMV_N    "test2-bf16gemv-n"
#define TEST2_GEMV_T    "test2-bf16gemv-t"
#define TEST2_GEMV_C    ""
#define TEST2_SYMV_U    "test2-bf16symv-u"
#define TEST2_SYMV_L    "test2-bf16symv-l"
#define NAME_GEMV_N     "BF16GEMV -N"
#define NAME_GEMV_T     "BF16GEMV -T"
#define NAME_GEMV_C     ""
#define NAME_SYMV_U     "BF16SYMV -U"
#define NAME_SYMV_L     "BF16SYMV -L"
#define ASPEN_GEMV_n    ASPEN_BF16GEMV_n
#define ASPEN_GEMV_t    ASPEN_BF16GEMV_t
#define ASPEN_GEMV_c    ASPEN_BF16GEMV_t
#define ASPEN_SYMVu     ASPEN_BF16SYMVu
#define ASPEN_SYMVl     ASPEN_BF16SYMVl
#define cblas_gemv      bf16gemv
#define cblas_symv      bf16symv
#endif



