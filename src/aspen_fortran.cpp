#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include "cublas.h"

#include "aspen.h"
#include "aspen_fortran.h"

// external API from fortran calls
extern  "C" {

  void
  aspen_init_ ( int const * device_id )
  {
    ASPEN_init( *device_id );
  }

  void
  aspen_shutdown_ ( void )
  {
    ASPEN_shutdown( );
  }

  void
  aspen_get_version_info_ ( int *version,
                            char *codename, unsigned int length_codename,
                            char *releasedate, unsigned int length_releasedate )
  {
    int  version_;
    char code_name[256];
    char release_date[256];

    ASPEN_get_version_info ( &version_, code_name, release_date );

    *version = version_;

    memset( codename, ' ', length_codename );
    size_t len_code_name = strlen( code_name );
    if ( len_code_name >= length_codename ) {
      len_code_name = (size_t)length_codename;
    }
    strncpy( codename, code_name, len_code_name );

    memset( releasedate, ' ', length_releasedate );
    size_t len_release_date = strlen( release_date );
    if ( len_release_date >= length_releasedate ) {
      len_release_date = (size_t)length_releasedate;
    }
    strncpy( releasedate, release_date, len_release_date );
  }

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
                )
  {
    cuddreal *A = (cuddreal * const)(uintptr_t)(*devPtrA);
    cuddreal *x = (cuddreal * const)(uintptr_t)(*devPtrx);
          cuddreal *y = (cuddreal *)(uintptr_t)(*devPtry);

    ASPEN_wsymv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    double *A = (double * const)(uintptr_t)(*devPtrA);
    double *x = (double * const)(uintptr_t)(*devPtrx);
          double *y = (double *)(uintptr_t)(*devPtry);

    ASPEN_dsymv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    float *A = (float * const)(uintptr_t)(*devPtrA);
    float *x = (float * const)(uintptr_t)(*devPtrx);
          float *y = (float *)(uintptr_t)(*devPtry);

    ASPEN_ssymv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    cuddcomplex *A = (cuddcomplex * const)(uintptr_t)(*devPtrA);
    cuddcomplex *x = (cuddcomplex * const)(uintptr_t)(*devPtrx);
          cuddcomplex *y = (cuddcomplex *)(uintptr_t)(*devPtry);

    ASPEN_uhemv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    cuDoubleComplex *A = (cuDoubleComplex * const)(uintptr_t)(*devPtrA);
    cuDoubleComplex *x = (cuDoubleComplex * const)(uintptr_t)(*devPtrx);
          cuDoubleComplex *y = (cuDoubleComplex *)(uintptr_t)(*devPtry);

    ASPEN_zhemv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    cuFloatComplex *A = (cuFloatComplex * const)(uintptr_t)(*devPtrA);
    cuFloatComplex *x = (cuFloatComplex * const)(uintptr_t)(*devPtrx);
          cuFloatComplex *y = (cuFloatComplex *)(uintptr_t)(*devPtry);

    ASPEN_chemv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

#if ASPEN_HALF_ENABLED
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
                )
  {
    half *A = (half * const)(uintptr_t)(*devPtrA);
    half *x = (half * const)(uintptr_t)(*devPtrx);
          half *y = (half *)(uintptr_t)(*devPtry);

    ASPEN_hsymv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

#endif
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
                )
  {
    int128 *A = (int128 * const)(uintptr_t)(*devPtrA);
    int128 *x = (int128 * const)(uintptr_t)(*devPtrx);
          int128 *y = (int128 *)(uintptr_t)(*devPtry);

    ASPEN_i128symv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    int64 *A = (int64 * const)(uintptr_t)(*devPtrA);
    int64 *x = (int64 * const)(uintptr_t)(*devPtrx);
          int64 *y = (int64 *)(uintptr_t)(*devPtry);

    ASPEN_i64symv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    int32 *A = (int32 * const)(uintptr_t)(*devPtrA);
    int32 *x = (int32 * const)(uintptr_t)(*devPtrx);
          int32 *y = (int32 *)(uintptr_t)(*devPtry);

    ASPEN_i32symv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

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
                )
  {
    int16 *A = (int16 * const)(uintptr_t)(*devPtrA);
    int16 *x = (int16 * const)(uintptr_t)(*devPtrx);
          int16 *y = (int16 *)(uintptr_t)(*devPtry);

    ASPEN_i16symv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }

  void
  aspen_waxpy_ (
                  int                const * n,
                  cuddreal           const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddreal *x = (cuddreal *)(uintptr_t)(*devPtrx);
          cuddreal *y = (cuddreal *)(uintptr_t)(*devPtry);

    ASPEN_waxpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_daxpy_ (
                  int                const * n,
                  double             const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    double *x = (double *)(uintptr_t)(*devPtrx);
          double *y = (double *)(uintptr_t)(*devPtry);

    ASPEN_daxpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_saxpy_ (
                  int                const * n,
                  float              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    float *x = (float *)(uintptr_t)(*devPtrx);
          float *y = (float *)(uintptr_t)(*devPtry);

    ASPEN_saxpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_uaxpy_ (
                  int                const * n,
                  cuddcomplex        const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddcomplex *x = (cuddcomplex *)(uintptr_t)(*devPtrx);
          cuddcomplex *y = (cuddcomplex *)(uintptr_t)(*devPtry);

    ASPEN_uaxpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_zaxpy_ (
                  int                const * n,
                  cuDoubleComplex    const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuDoubleComplex *x = (cuDoubleComplex *)(uintptr_t)(*devPtrx);
          cuDoubleComplex *y = (cuDoubleComplex *)(uintptr_t)(*devPtry);

    ASPEN_zaxpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_caxpy_ (
                  int                const * n,
                  cuFloatComplex     const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuFloatComplex *x = (cuFloatComplex *)(uintptr_t)(*devPtrx);
          cuFloatComplex *y = (cuFloatComplex *)(uintptr_t)(*devPtry);

    ASPEN_caxpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

#if ASPEN_HALF_ENABLED
  void
  aspen_haxpy_ (
                  int                const * n,
                  half               const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    half *x = (half *)(uintptr_t)(*devPtrx);
          half *y = (half *)(uintptr_t)(*devPtry);

    ASPEN_haxpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

#endif
  void
  aspen_i128axpy_ (
                  int                const * n,
                  int128             const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int128 *x = (int128 *)(uintptr_t)(*devPtrx);
          int128 *y = (int128 *)(uintptr_t)(*devPtry);

    ASPEN_i128axpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_i64axpy_ (
                  int                const * n,
                  int64              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int64 *x = (int64 *)(uintptr_t)(*devPtrx);
          int64 *y = (int64 *)(uintptr_t)(*devPtry);

    ASPEN_i64axpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_i32axpy_ (
                  int                const * n,
                  int32              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int32 *x = (int32 *)(uintptr_t)(*devPtrx);
          int32 *y = (int32 *)(uintptr_t)(*devPtry);

    ASPEN_i32axpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_i16axpy_ (
                  int                const * n,
                  int16              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int16 *x = (int16 *)(uintptr_t)(*devPtrx);
          int16 *y = (int16 *)(uintptr_t)(*devPtry);

    ASPEN_i16axpy( *n,
                 *alpha, x, *incx, y, *incy );
  }

  void
  aspen_waxpby_ (
                  int                const * n,
                  cuddreal           const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  cuddreal           const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddreal *x = (cuddreal *)(uintptr_t)(*devPtrx);
          cuddreal *y = (cuddreal *)(uintptr_t)(*devPtry);

    ASPEN_waxpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_daxpby_ (
                  int                const * n,
                  double             const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  double             const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    double *x = (double *)(uintptr_t)(*devPtrx);
          double *y = (double *)(uintptr_t)(*devPtry);

    ASPEN_daxpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_saxpby_ (
                  int                const * n,
                  float              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  float              const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    float *x = (float *)(uintptr_t)(*devPtrx);
          float *y = (float *)(uintptr_t)(*devPtry);

    ASPEN_saxpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_uaxpby_ (
                  int                const * n,
                  cuddcomplex        const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  cuddcomplex        const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddcomplex *x = (cuddcomplex *)(uintptr_t)(*devPtrx);
          cuddcomplex *y = (cuddcomplex *)(uintptr_t)(*devPtry);

    ASPEN_uaxpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_zaxpby_ (
                  int                const * n,
                  cuDoubleComplex    const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  cuDoubleComplex    const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuDoubleComplex *x = (cuDoubleComplex *)(uintptr_t)(*devPtrx);
          cuDoubleComplex *y = (cuDoubleComplex *)(uintptr_t)(*devPtry);

    ASPEN_zaxpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_caxpby_ (
                  int                const * n,
                  cuFloatComplex     const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  cuFloatComplex     const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuFloatComplex *x = (cuFloatComplex *)(uintptr_t)(*devPtrx);
          cuFloatComplex *y = (cuFloatComplex *)(uintptr_t)(*devPtry);

    ASPEN_caxpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

#if ASPEN_HALF_ENABLED
  void
  aspen_haxpby_ (
                  int                const * n,
                  half               const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  half               const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    half *x = (half *)(uintptr_t)(*devPtrx);
          half *y = (half *)(uintptr_t)(*devPtry);

    ASPEN_haxpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

#endif
  void
  aspen_i128axpby_ (
                  int                const * n,
                  int128             const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  int128             const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int128 *x = (int128 *)(uintptr_t)(*devPtrx);
          int128 *y = (int128 *)(uintptr_t)(*devPtry);

    ASPEN_i128axpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_i64axpby_ (
                  int                const * n,
                  int64              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  int64              const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int64 *x = (int64 *)(uintptr_t)(*devPtrx);
          int64 *y = (int64 *)(uintptr_t)(*devPtry);

    ASPEN_i64axpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_i32axpby_ (
                  int                const * n,
                  int32              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  int32              const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int32 *x = (int32 *)(uintptr_t)(*devPtrx);
          int32 *y = (int32 *)(uintptr_t)(*devPtry);

    ASPEN_i32axpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_i16axpby_ (
                  int                const * n,
                  int16              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  int16              const * beta,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int16 *x = (int16 *)(uintptr_t)(*devPtrx);
          int16 *y = (int16 *)(uintptr_t)(*devPtry);

    ASPEN_i16axpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }

  void
  aspen_wswap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddreal *x = (cuddreal *)(uintptr_t)(*devPtrx);
    cuddreal *y = (cuddreal *)(uintptr_t)(*devPtry);

    ASPEN_wswap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_dswap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    double *x = (double *)(uintptr_t)(*devPtrx);
    double *y = (double *)(uintptr_t)(*devPtry);

    ASPEN_dswap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_sswap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    float *x = (float *)(uintptr_t)(*devPtrx);
    float *y = (float *)(uintptr_t)(*devPtry);

    ASPEN_sswap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_uswap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddcomplex *x = (cuddcomplex *)(uintptr_t)(*devPtrx);
    cuddcomplex *y = (cuddcomplex *)(uintptr_t)(*devPtry);

    ASPEN_uswap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_zswap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuDoubleComplex *x = (cuDoubleComplex *)(uintptr_t)(*devPtrx);
    cuDoubleComplex *y = (cuDoubleComplex *)(uintptr_t)(*devPtry);

    ASPEN_zswap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_cswap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuFloatComplex *x = (cuFloatComplex *)(uintptr_t)(*devPtrx);
    cuFloatComplex *y = (cuFloatComplex *)(uintptr_t)(*devPtry);

    ASPEN_cswap( *n,
                 x, *incx, y, *incy );
  }

#if ASPEN_HALF_ENABLED
  void
  aspen_hswap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    half *x = (half *)(uintptr_t)(*devPtrx);
    half *y = (half *)(uintptr_t)(*devPtry);

    ASPEN_hswap( *n,
                 x, *incx, y, *incy );
  }

#endif
  void
  aspen_i128swap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int128 *x = (int128 *)(uintptr_t)(*devPtrx);
    int128 *y = (int128 *)(uintptr_t)(*devPtry);

    ASPEN_i128swap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_i64swap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int64 *x = (int64 *)(uintptr_t)(*devPtrx);
    int64 *y = (int64 *)(uintptr_t)(*devPtry);

    ASPEN_i64swap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_i32swap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int32 *x = (int32 *)(uintptr_t)(*devPtrx);
    int32 *y = (int32 *)(uintptr_t)(*devPtry);

    ASPEN_i32swap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_i16swap_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int16 *x = (int16 *)(uintptr_t)(*devPtrx);
    int16 *y = (int16 *)(uintptr_t)(*devPtry);

    ASPEN_i16swap( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_wcopy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddreal *x = (cuddreal *)(uintptr_t)(*devPtrx);
          cuddreal *y = (cuddreal *)(uintptr_t)(*devPtry);

    ASPEN_wcopy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_dcopy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    double *x = (double *)(uintptr_t)(*devPtrx);
          double *y = (double *)(uintptr_t)(*devPtry);

    ASPEN_dcopy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_scopy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    float *x = (float *)(uintptr_t)(*devPtrx);
          float *y = (float *)(uintptr_t)(*devPtry);

    ASPEN_scopy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_ucopy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuddcomplex *x = (cuddcomplex *)(uintptr_t)(*devPtrx);
          cuddcomplex *y = (cuddcomplex *)(uintptr_t)(*devPtry);

    ASPEN_ucopy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_zcopy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuDoubleComplex *x = (cuDoubleComplex *)(uintptr_t)(*devPtrx);
          cuDoubleComplex *y = (cuDoubleComplex *)(uintptr_t)(*devPtry);

    ASPEN_zcopy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_ccopy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    cuFloatComplex *x = (cuFloatComplex *)(uintptr_t)(*devPtrx);
          cuFloatComplex *y = (cuFloatComplex *)(uintptr_t)(*devPtry);

    ASPEN_ccopy( *n,
                 x, *incx, y, *incy );
  }

#if ASPEN_HALF_ENABLED
  void
  aspen_hcopy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    half *x = (half *)(uintptr_t)(*devPtrx);
          half *y = (half *)(uintptr_t)(*devPtry);

    ASPEN_hcopy( *n,
                 x, *incx, y, *incy );
  }

#endif
  void
  aspen_i128copy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int128 *x = (int128 *)(uintptr_t)(*devPtrx);
          int128 *y = (int128 *)(uintptr_t)(*devPtry);

    ASPEN_i128copy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_i64copy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int64 *x = (int64 *)(uintptr_t)(*devPtrx);
          int64 *y = (int64 *)(uintptr_t)(*devPtry);

    ASPEN_i64copy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_i32copy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int32 *x = (int32 *)(uintptr_t)(*devPtrx);
          int32 *y = (int32 *)(uintptr_t)(*devPtry);

    ASPEN_i32copy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_i16copy_ (
                  int                const * n,
                  devptr_t           const * devPtrx,
                  int                const * incx,
                  devptr_t           const * devPtry,
                  int                const * incy
                )
  {
    int16 *x = (int16 *)(uintptr_t)(*devPtrx);
          int16 *y = (int16 *)(uintptr_t)(*devPtry);

    ASPEN_i16copy( *n,
                 x, *incx, y, *incy );
  }

  void
  aspen_wscal_ (
                  int                const * n,
                  cuddreal           const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    cuddreal *x = (cuddreal *)(uintptr_t)(*devPtrx);

    ASPEN_wscal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_dscal_ (
                  int                const * n,
                  double             const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    double *x = (double *)(uintptr_t)(*devPtrx);

    ASPEN_dscal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_sscal_ (
                  int                const * n,
                  float              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    float *x = (float *)(uintptr_t)(*devPtrx);

    ASPEN_sscal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_uscal_ (
                  int                const * n,
                  cuddcomplex        const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    cuddcomplex *x = (cuddcomplex *)(uintptr_t)(*devPtrx);

    ASPEN_uscal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_zscal_ (
                  int                const * n,
                  cuDoubleComplex    const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    cuDoubleComplex *x = (cuDoubleComplex *)(uintptr_t)(*devPtrx);

    ASPEN_zscal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_cscal_ (
                  int                const * n,
                  cuFloatComplex     const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    cuFloatComplex *x = (cuFloatComplex *)(uintptr_t)(*devPtrx);

    ASPEN_cscal( *n,
                 *alpha, x, *incx );
  }

#if ASPEN_HALF_ENABLED
  void
  aspen_hscal_ (
                  int                const * n,
                  half               const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    half *x = (half *)(uintptr_t)(*devPtrx);

    ASPEN_hscal( *n,
                 *alpha, x, *incx );
  }

#endif
  void
  aspen_i128scal_ (
                  int                const * n,
                  int128             const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    int128 *x = (int128 *)(uintptr_t)(*devPtrx);

    ASPEN_i128scal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_i64scal_ (
                  int                const * n,
                  int64              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    int64 *x = (int64 *)(uintptr_t)(*devPtrx);

    ASPEN_i64scal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_i32scal_ (
                  int                const * n,
                  int32              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    int32 *x = (int32 *)(uintptr_t)(*devPtrx);

    ASPEN_i32scal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_i16scal_ (
                  int                const * n,
                  int16              const * alpha,
                  devptr_t           const * devPtrx,
                  int                const * incx
                )
  {
    int16 *x = (int16 *)(uintptr_t)(*devPtrx);

    ASPEN_i16scal( *n,
                 *alpha, x, *incx );
  }

  void
  aspen_wzero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    cuddreal *x = (cuddreal *)(uintptr_t)(*devPtrx);

    ASPEN_WZERO( x, *n );
  }

  void
  aspen_dzero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    double *x = (double *)(uintptr_t)(*devPtrx);

    ASPEN_DZERO( x, *n );
  }

  void
  aspen_szero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    float *x = (float *)(uintptr_t)(*devPtrx);

    ASPEN_SZERO( x, *n );
  }

  void
  aspen_uzero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    cuddcomplex *x = (cuddcomplex *)(uintptr_t)(*devPtrx);

    ASPEN_UZERO( x, *n );
  }

  void
  aspen_zzero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    cuDoubleComplex *x = (cuDoubleComplex *)(uintptr_t)(*devPtrx);

    ASPEN_ZZERO( x, *n );
  }

  void
  aspen_czero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    cuFloatComplex *x = (cuFloatComplex *)(uintptr_t)(*devPtrx);

    ASPEN_CZERO( x, *n );
  }

#if ASPEN_HALF_ENABLED
  void
  aspen_hzero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    half *x = (half *)(uintptr_t)(*devPtrx);

    ASPEN_HZERO( x, *n );
  }

#endif
  void
  aspen_i128zero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    int128 *x = (int128 *)(uintptr_t)(*devPtrx);

    ASPEN_I128ZERO( x, *n );
  }

  void
  aspen_i64zero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    int64 *x = (int64 *)(uintptr_t)(*devPtrx);

    ASPEN_I64ZERO( x, *n );
  }

  void
  aspen_i32zero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    int32 *x = (int32 *)(uintptr_t)(*devPtrx);

    ASPEN_I32ZERO( x, *n );
  }

  void
  aspen_i16zero_ (
                  devptr_t           const * devPtrx,
                  int                const * n 
                )
  {
    int16 *x = (int16 *)(uintptr_t)(*devPtrx);

    ASPEN_I16ZERO( x, *n );
  }

}

