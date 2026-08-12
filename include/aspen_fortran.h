#ifndef ASPEN_FORTRAN_H_INCLUDED
#define ASPEN_FORTRAN_H_INCLUDED	1

#if !defined(_____)
#  define  _____   /* */
#endif
#include "aspen_version.h"
#include "aspen_types.h"

typedef size_t devptr_t;

#ifdef __cplusplus
extern  "C" {
#endif

  /* User must call ASPEN_init for initialization */
  void
  aspen_init_ ( int const * device_id );

  /* User must finalize the ASPEN library by ASPEN_shutdown */
  void
  aspen_shutdown_ ( void );

  /* Get version info ASPEN_get_version_info */
  void
  aspen_get_version_info_ ( int *version,
                            char *codename, unsigned int length_codename,
                            char *releasedate, unsigned int length_releasedate );

  void
  aspen_wsymv_ (
                  char               const * const uplo,
                  int                const * const n,
                  cuddreal           const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuddreal           const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_dsymv_ (
                  char               const * const uplo,
                  int                const * const n,
                  double             const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  double             const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_ssymv_ (
                  char               const * const uplo,
                  int                const * const n,
                  float              const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  float              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_hsymv_ (
                  char               const * const uplo,
                  int                const * const n,
                  half               const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  half               const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_uhemv_ (
                  char               const * const uplo,
                  int                const * const n,
                  cuddcomplex        const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuddcomplex        const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_zhemv_ (
                  char               const * const uplo,
                  int                const * const n,
                  cuDoubleComplex    const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuDoubleComplex    const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_chemv_ (
                  char               const * const uplo,
                  int                const * const n,
                  cuFloatComplex     const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuFloatComplex     const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_khemv_ (
                  char               const * const uplo,
                  int                const * const n,
                  cuHalfComplex      const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuHalfComplex      const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i128symv_ (
                  char               const * const uplo,
                  int                const * const n,
                  int128             const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int128             const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i64symv_ (
                  char               const * const uplo,
                  int                const * const n,
                  int64              const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int64              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i32symv_ (
                  char               const * const uplo,
                  int                const * const n,
                  int32              const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int32              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i16symv_ (
                  char               const * const uplo,
                  int                const * const n,
                  int16              const * const alpha,
                  devptr_t           const * const devPtrA,
                  int                const * const lda,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int16              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );

  void
  aspen_waxpy_ (
                  int                const * const n,
                  cuddreal           const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_daxpy_ (
                  int                const * const n,
                  double             const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_saxpy_ (
                  int                const * const n,
                  float              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_haxpy_ (
                  int                const * const n,
                  half               const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_uaxpy_ (
                  int                const * const n,
                  cuddcomplex        const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_zaxpy_ (
                  int                const * const n,
                  cuDoubleComplex    const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_caxpy_ (
                  int                const * const n,
                  cuFloatComplex     const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_kaxpy_ (
                  int                const * const n,
                  cuHalfComplex      const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i128axpy_ (
                  int                const * const n,
                  int128             const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i64axpy_ (
                  int                const * const n,
                  int64              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i32axpy_ (
                  int                const * const n,
                  int32              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i16axpy_ (
                  int                const * const n,
                  int16              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );

  void
  aspen_waxpby_ (
                  int                const * const n,
                  cuddreal           const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuddreal           const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_daxpby_ (
                  int                const * const n,
                  double             const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  double             const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_saxpby_ (
                  int                const * const n,
                  float              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  float              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_haxpby_ (
                  int                const * const n,
                  half               const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  half               const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_uaxpby_ (
                  int                const * const n,
                  cuddcomplex        const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuddcomplex        const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_zaxpby_ (
                  int                const * const n,
                  cuDoubleComplex    const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuDoubleComplex    const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_caxpby_ (
                  int                const * const n,
                  cuFloatComplex     const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuFloatComplex     const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_kaxpby_ (
                  int                const * const n,
                  cuHalfComplex      const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  cuHalfComplex      const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i128axpby_ (
                  int                const * const n,
                  int128             const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int128             const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i64axpby_ (
                  int                const * const n,
                  int64              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int64              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i32axpby_ (
                  int                const * const n,
                  int32              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int32              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i16axpby_ (
                  int                const * const n,
                  int16              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  int16              const * const beta,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );

  void
  aspen_wswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_dswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_sswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_hswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_uswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_zswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_cswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_kswap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i128swap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i64swap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i32swap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i16swap_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );

  void
  aspen_wcopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_dcopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_scopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_hcopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_ucopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_zcopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_ccopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_kcopy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i128copy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i64copy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i32copy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );
  void
  aspen_i16copy_ (
                  int                const * const n,
                  devptr_t           const * const devPtrx,
                  int                const * const incx,
                  devptr_t           const * const devPtry,
                  int                const * const incy
                );

  void
  aspen_wscal_ (
                  int                const * const n,
                  cuddreal           const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_dscal_ (
                  int                const * const n,
                  double             const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_sscal_ (
                  int                const * const n,
                  float              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_hscal_ (
                  int                const * const n,
                  half               const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_uscal_ (
                  int                const * const n,
                  cuddcomplex        const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_zscal_ (
                  int                const * const n,
                  cuDoubleComplex    const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_cscal_ (
                  int                const * const n,
                  cuFloatComplex     const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_kscal_ (
                  int                const * const n,
                  cuHalfComplex      const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_i128scal_ (
                  int                const * const n,
                  int128             const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_i64scal_ (
                  int                const * const n,
                  int64              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_i32scal_ (
                  int                const * const n,
                  int32              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );
  void
  aspen_i16scal_ (
                  int                const * const n,
                  int16              const * const alpha,
                  devptr_t           const * const devPtrx,
                  int                const * const incx
                );

  void
  aspen_wzero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_dzero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_szero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_hzero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_uzero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_zzero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_czero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_kzero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_i128zero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_i64zero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_i32zero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );
  void
  aspen_i16zero_ (
                  devptr_t           const * const devPtrx,
                  int                const * const n 
                );

#ifdef __cplusplus
}
#endif

#endif 
