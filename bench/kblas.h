#if __isFLOAT__
#define SYMV_U     SSYMV_U
#define SYMV_L     SSYMV_L
#define TEST_SYMV_U     "kblas-ssymv-u"
#define TEST_SYMV_L     "kblas-ssymv-l"
#define NAME_SYMV_U     "SSYMV -U"
#define NAME_SYMV_L     "SSYMV -L"
#define kblassymv      kblas_ssymv
#endif

#if __isDOUBLE__
#define SYMV_U     DSYMV_U
#define SYMV_L     DSYMV_L
#define TEST_SYMV_U     "kblas-dsymv-u"
#define TEST_SYMV_L     "kblas-dsymv-l"
#define NAME_SYMV_U     "DSYMV -U"
#define NAME_SYMV_L     "DSYMV -L"
#define kblassymv      kblas_dsymv
#endif

#if __isFLOAT_COMPLEX__
#define HEMV_U     CHEMV_U
#define HEMV_L     CHEMV_L
#define TEST_HEMV_U     "kblas-chemv-u"
#define TEST_HEMV_L     "kblas-chemv-l"
#define NAME_HEMV_U     "CHEMV -U"
#define NAME_HEMV_L     "CHEMV -L"
#define kblashemv      kblas_chemv
#endif

#if __isDOUBLE_COMPLEX__
#define HEMV_U     ZHEMV_U
#define HEMV_L     ZHEMV_L
#define TEST_HEMV_U     "kblas-zhemv-u"
#define TEST_HEMV_L     "kblas-zhemv-l"
#define NAME_HEMV_U     "ZHEMV -U"
#define NAME_HEMV_L     "ZHEMV -L"
#define kblashemv      kblas_zhemv
#endif

