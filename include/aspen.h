#ifndef ASPEN_H_INCLUDED
#define ASPEN_H_INCLUDED	1

#include "aspen_version.h"
#include "aspen_types.h"

#if !defined(_____)
#  define _____ /* */
#endif

#ifdef __cplusplus
extern  "C" {
#endif

  /* User must call ASPEN_init for initialization */
  int
  ASPEN_init ( int const device_id );

  /* User must finalize the ASPEN library by ASPEN_shutdown */
  int
  ASPEN_shutdown ( void );

  /* Get version info ASPEN_get_version_info */
  void
  ASPEN_get_version_info ( int *version, char *codename, char *releasedate );

  void
  ASPEN_wsymv (
                  char               const  uplo,
                  int                const  n,
                  cuddreal           const   alpha,
                  cuddreal           const * const a,
                  int                const  lda,
                  cuddreal           const * const x,
                  int                const  incx,
                  cuddreal           const   beta,
                  cuddreal           _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_dsymv (
                  char               const  uplo,
                  int                const  n,
                  double             const   alpha,
                  double             const * const a,
                  int                const  lda,
                  double             const * const x,
                  int                const  incx,
                  double             const   beta,
                  double             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_ssymv (
                  char               const  uplo,
                  int                const  n,
                  float              const   alpha,
                  float              const * const a,
                  int                const  lda,
                  float              const * const x,
                  int                const  incx,
                  float              const   beta,
                  float              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_hsymv (
                  char               const  uplo,
                  int                const  n,
                  half               const   alpha,
                  half               const * const a,
                  int                const  lda,
                  half               const * const x,
                  int                const  incx,
                  half               const   beta,
                  half               _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_uhemv (
                  char               const  uplo,
                  int                const  n,
                  cuddcomplex        const   alpha,
                  cuddcomplex        const * const a,
                  int                const  lda,
                  cuddcomplex        const * const x,
                  int                const  incx,
                  cuddcomplex        const   beta,
                  cuddcomplex        _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_zhemv (
                  char               const  uplo,
                  int                const  n,
                  cuDoubleComplex    const   alpha,
                  cuDoubleComplex    const * const a,
                  int                const  lda,
                  cuDoubleComplex    const * const x,
                  int                const  incx,
                  cuDoubleComplex    const   beta,
                  cuDoubleComplex    _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_chemv (
                  char               const  uplo,
                  int                const  n,
                  cuFloatComplex     const   alpha,
                  cuFloatComplex     const * const a,
                  int                const  lda,
                  cuFloatComplex     const * const x,
                  int                const  incx,
                  cuFloatComplex     const   beta,
                  cuFloatComplex     _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_khemv (
                  char               const  uplo,
                  int                const  n,
                  cuHalfComplex      const   alpha,
                  cuHalfComplex      const * const a,
                  int                const  lda,
                  cuHalfComplex      const * const x,
                  int                const  incx,
                  cuHalfComplex      const   beta,
                  cuHalfComplex      _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i128symv (
                  char               const  uplo,
                  int                const  n,
                  int128             const   alpha,
                  int128             const * const a,
                  int                const  lda,
                  int128             const * const x,
                  int                const  incx,
                  int128             const   beta,
                  int128             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i64symv (
                  char               const  uplo,
                  int                const  n,
                  int64              const   alpha,
                  int64              const * const a,
                  int                const  lda,
                  int64              const * const x,
                  int                const  incx,
                  int64              const   beta,
                  int64              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i32symv (
                  char               const  uplo,
                  int                const  n,
                  int32              const   alpha,
                  int32              const * const a,
                  int                const  lda,
                  int32              const * const x,
                  int                const  incx,
                  int32              const   beta,
                  int32              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i16symv (
                  char               const  uplo,
                  int                const  n,
                  int16              const   alpha,
                  int16              const * const a,
                  int                const  lda,
                  int16              const * const x,
                  int                const  incx,
                  int16              const   beta,
                  int16              _____ * const y,
                  int                const  incy
                );

  void
  ASPEN_waxpy (
                  int                const  n,
                  cuddreal           const   alpha,
                  cuddreal           const * const x,
                  int                const  incx,
                  cuddreal           _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_daxpy (
                  int                const  n,
                  double             const   alpha,
                  double             const * const x,
                  int                const  incx,
                  double             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_saxpy (
                  int                const  n,
                  float              const   alpha,
                  float              const * const x,
                  int                const  incx,
                  float              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_haxpy (
                  int                const  n,
                  half               const   alpha,
                  half               const * const x,
                  int                const  incx,
                  half               _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_uaxpy (
                  int                const  n,
                  cuddcomplex        const   alpha,
                  cuddcomplex        const * const x,
                  int                const  incx,
                  cuddcomplex        _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_zaxpy (
                  int                const  n,
                  cuDoubleComplex    const   alpha,
                  cuDoubleComplex    const * const x,
                  int                const  incx,
                  cuDoubleComplex    _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_caxpy (
                  int                const  n,
                  cuFloatComplex     const   alpha,
                  cuFloatComplex     const * const x,
                  int                const  incx,
                  cuFloatComplex     _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_kaxpy (
                  int                const  n,
                  cuHalfComplex      const   alpha,
                  cuHalfComplex      const * const x,
                  int                const  incx,
                  cuHalfComplex      _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i128axpy (
                  int                const  n,
                  int128             const   alpha,
                  int128             const * const x,
                  int                const  incx,
                  int128             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i64axpy (
                  int                const  n,
                  int64              const   alpha,
                  int64              const * const x,
                  int                const  incx,
                  int64              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i32axpy (
                  int                const  n,
                  int32              const   alpha,
                  int32              const * const x,
                  int                const  incx,
                  int32              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i16axpy (
                  int                const  n,
                  int16              const   alpha,
                  int16              const * const x,
                  int                const  incx,
                  int16              _____ * const y,
                  int                const  incy
                );

  void
  ASPEN_waxpby (
                  int                const  n,
                  cuddreal           const   alpha,
                  cuddreal           const * const x,
                  int                const  incx,
                  cuddreal           const   beta,
                  cuddreal           _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_daxpby (
                  int                const  n,
                  double             const   alpha,
                  double             const * const x,
                  int                const  incx,
                  double             const   beta,
                  double             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_saxpby (
                  int                const  n,
                  float              const   alpha,
                  float              const * const x,
                  int                const  incx,
                  float              const   beta,
                  float              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_haxpby (
                  int                const  n,
                  half               const   alpha,
                  half               const * const x,
                  int                const  incx,
                  half               const   beta,
                  half               _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_uaxpby (
                  int                const  n,
                  cuddcomplex        const   alpha,
                  cuddcomplex        const * const x,
                  int                const  incx,
                  cuddcomplex        const   beta,
                  cuddcomplex        _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_zaxpby (
                  int                const  n,
                  cuDoubleComplex    const   alpha,
                  cuDoubleComplex    const * const x,
                  int                const  incx,
                  cuDoubleComplex    const   beta,
                  cuDoubleComplex    _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_caxpby (
                  int                const  n,
                  cuFloatComplex     const   alpha,
                  cuFloatComplex     const * const x,
                  int                const  incx,
                  cuFloatComplex     const   beta,
                  cuFloatComplex     _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_kaxpby (
                  int                const  n,
                  cuHalfComplex      const   alpha,
                  cuHalfComplex      const * const x,
                  int                const  incx,
                  cuHalfComplex      const   beta,
                  cuHalfComplex      _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i128axpby (
                  int                const  n,
                  int128             const   alpha,
                  int128             const * const x,
                  int                const  incx,
                  int128             const   beta,
                  int128             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i64axpby (
                  int                const  n,
                  int64              const   alpha,
                  int64              const * const x,
                  int                const  incx,
                  int64              const   beta,
                  int64              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i32axpby (
                  int                const  n,
                  int32              const   alpha,
                  int32              const * const x,
                  int                const  incx,
                  int32              const   beta,
                  int32              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i16axpby (
                  int                const  n,
                  int16              const   alpha,
                  int16              const * const x,
                  int                const  incx,
                  int16              const   beta,
                  int16              _____ * const y,
                  int                const  incy
                );

  void
  ASPEN_wswap (
                  int                const  n,
                  cuddreal           _____ * const x,
                  int                const  incx,
                  cuddreal           _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_dswap (
                  int                const  n,
                  double             _____ * const x,
                  int                const  incx,
                  double             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_sswap (
                  int                const  n,
                  float              _____ * const x,
                  int                const  incx,
                  float              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_hswap (
                  int                const  n,
                  half               _____ * const x,
                  int                const  incx,
                  half               _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_uswap (
                  int                const  n,
                  cuddcomplex        _____ * const x,
                  int                const  incx,
                  cuddcomplex        _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_zswap (
                  int                const  n,
                  cuDoubleComplex    _____ * const x,
                  int                const  incx,
                  cuDoubleComplex    _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_cswap (
                  int                const  n,
                  cuFloatComplex     _____ * const x,
                  int                const  incx,
                  cuFloatComplex     _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_kswap (
                  int                const  n,
                  cuHalfComplex      _____ * const x,
                  int                const  incx,
                  cuHalfComplex      _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i128swap (
                  int                const  n,
                  int128             _____ * const x,
                  int                const  incx,
                  int128             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i64swap (
                  int                const  n,
                  int64              _____ * const x,
                  int                const  incx,
                  int64              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i32swap (
                  int                const  n,
                  int32              _____ * const x,
                  int                const  incx,
                  int32              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i16swap (
                  int                const  n,
                  int16              _____ * const x,
                  int                const  incx,
                  int16              _____ * const y,
                  int                const  incy
                );

  void
  ASPEN_wcopy (
                  int                const  n,
                  cuddreal           const * const x,
                  int                const  incx,
                  cuddreal           _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_dcopy (
                  int                const  n,
                  double             const * const x,
                  int                const  incx,
                  double             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_scopy (
                  int                const  n,
                  float              const * const x,
                  int                const  incx,
                  float              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_hcopy (
                  int                const  n,
                  half               const * const x,
                  int                const  incx,
                  half               _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_ucopy (
                  int                const  n,
                  cuddcomplex        const * const x,
                  int                const  incx,
                  cuddcomplex        _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_zcopy (
                  int                const  n,
                  cuDoubleComplex    const * const x,
                  int                const  incx,
                  cuDoubleComplex    _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_ccopy (
                  int                const  n,
                  cuFloatComplex     const * const x,
                  int                const  incx,
                  cuFloatComplex     _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_kcopy (
                  int                const  n,
                  cuHalfComplex      const * const x,
                  int                const  incx,
                  cuHalfComplex      _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i128copy (
                  int                const  n,
                  int128             const * const x,
                  int                const  incx,
                  int128             _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i64copy (
                  int                const  n,
                  int64              const * const x,
                  int                const  incx,
                  int64              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i32copy (
                  int                const  n,
                  int32              const * const x,
                  int                const  incx,
                  int32              _____ * const y,
                  int                const  incy
                );
  void
  ASPEN_i16copy (
                  int                const  n,
                  int16              const * const x,
                  int                const  incx,
                  int16              _____ * const y,
                  int                const  incy
                );

  void
  ASPEN_wscal (
                  int                const  n,
                  cuddreal           const   alpha,
                  cuddreal           _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_dscal (
                  int                const  n,
                  double             const   alpha,
                  double             _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_sscal (
                  int                const  n,
                  float              const   alpha,
                  float              _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_hscal (
                  int                const  n,
                  half               const   alpha,
                  half               _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_uscal (
                  int                const  n,
                  cuddcomplex        const   alpha,
                  cuddcomplex        _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_zscal (
                  int                const  n,
                  cuDoubleComplex    const   alpha,
                  cuDoubleComplex    _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_cscal (
                  int                const  n,
                  cuFloatComplex     const   alpha,
                  cuFloatComplex     _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_kscal (
                  int                const  n,
                  cuHalfComplex      const   alpha,
                  cuHalfComplex      _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_i128scal (
                  int                const  n,
                  int128             const   alpha,
                  int128             _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_i64scal (
                  int                const  n,
                  int64              const   alpha,
                  int64              _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_i32scal (
                  int                const  n,
                  int32              const   alpha,
                  int32              _____ * const x,
                  int                const  incx
                );
  void
  ASPEN_i16scal (
                  int                const  n,
                  int16              const   alpha,
                  int16              _____ * const x,
                  int                const  incx
                );

  void
  ASPEN_WZERO (
                  cuddreal           _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_DZERO (
                  double             _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_SZERO (
                  float              _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_HZERO (
                  half               _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_UZERO (
                  cuddcomplex        _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_ZZERO (
                  cuDoubleComplex    _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_CZERO (
                  cuFloatComplex     _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_KZERO (
                  cuHalfComplex      _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_I128ZERO (
                  int128             _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_I64ZERO (
                  int64              _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_I32ZERO (
                  int32              _____ * const x,
                  int                const  n 
                );
  void
  ASPEN_I16ZERO (
                  int16              _____ * const x,
                  int                const  n 
                );

#ifdef __cplusplus
}
#endif

#endif 
