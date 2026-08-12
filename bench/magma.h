#if __isFLOAT__
#define SYMV_U     SSYMV_U
#define SYMV_L     SSYMV_L
#define TEST_SYMV_U     "magma-ssymv-u"
#define TEST_SYMV_L     "magma-ssymv-l"
#define TEST2_SYMV_U    "magma2-ssymv-u"
#define TEST2_SYMV_L    "magma2-ssymv-l"
#define NAME_SYMV_U     "SSYMV -U"
#define NAME_SYMV_L     "SSYMV -L"
#define magmablasgemv      magmablas_sgemv
#define magmablassymv      magmablas_ssymv
#define magmablasgemv_work     magmablas_sgemv_work
#define magmablassymv_work     magmablas_ssymv_work
#endif

#if __isDOUBLE__
#define SYMV_U     DSYMV_U
#define SYMV_L     DSYMV_L
#define TEST_SYMV_U     "magma-dsymv-u"
#define TEST_SYMV_L     "magma-dsymv-l"
#define TEST2_SYMV_U    "magma2-dsymv-u"
#define TEST2_SYMV_L    "magma2-dsymv-l"
#define NAME_SYMV_U     "DSYMV -U"
#define NAME_SYMV_L     "DSYMV -L"
#define magmablasgemv      magmablas_dgemv
#define magmablassymv      magmablas_dsymv
#define magmablasgemv_work      magmablas_dgemv_work
#define magmablassymv_work      magmablas_dsymv_work
#endif

#if __isFLOAT_COMPLEX__
#define HEMV_U     CHEMV_U
#define HEMV_L     CHEMV_L
#define TEST_HEMV_U     "magma-chemv-u"
#define TEST_HEMV_L     "magma-chemv-l"
#define TEST2_HEMV_U    "magma2-chemv-u"
#define TEST2_HEMV_L    "magma2-chemv-l"
#define NAME_HEMV_U     "CHEMV -U"
#define NAME_HEMV_L     "CHEMV -L"
#define magmablasgemv      magmablas_cgemv
#define magmablashemv      magmablas_chemv
#define magmablasgemv_work     magmablas_cgemv_work
#define magmablashemv_work     magmablas_chemv_work
#endif

#if __isDOUBLE_COMPLEX__
#define HEMV_U     ZHEMV_U
#define HEMV_L     ZHEMV_L
#define TEST_HEMV_U     "magma-zhemv-u"
#define TEST_HEMV_L     "magma-zhemv-l"
#define TEST2_HEMV_U    "magma2-zhemv-u"
#define TEST2_HEMV_L    "magma2-zhemv-l"
#define NAME_HEMV_U     "ZHEMV -U"
#define NAME_HEMV_L     "ZHEMV -L"
#define magmablasgemv      magmablas_zgemv
#define magmablashemv      magmablas_zhemv
#define magmablasgemv_work      magmablas_zgemv_work
#define magmablashemv_work      magmablas_zhemv_work
#endif

