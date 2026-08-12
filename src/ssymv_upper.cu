#if !defined(CURRENT_GPU)
#  include "../tuning/CURRENT_GPU"
#endif
#if !defined(GPU_ARCH)
#  define GPU_ARCH	CURRENT_GPU
#endif

#include "_float_.h"
#include "aspen_devel.h"

#if ( 's'!='h' && 's'!='k' ) || ASPEN_HALF_ENABLED
#  include "ssymv_upper-X_template.cu"
#endif

extern "C" void
API(SSYMVu) ( int const blk,
              int const n, scalar_t const * a, int const lda,
              scalar_t const * x, int const incx,
              scalar_t * y, int const incy,
              scalar_t const alpha, scalar_t const beta )
{

  // y = alpha * A * x + beta * y
  // y(1:n1)
  // x(1:n2)

#if ( 's'!='h' && 's'!='k' ) || ASPEN_HALF_ENABLED

  int Ver = API(get_device_CC) ( );

#if 1
  {  
    API_private(SSYMVu_STUB) ( blk,
                               n, a, lda, x, incx, y, incy, alpha, beta );
  }
#else
  if ( CURRENT_GPU == Ver ) {
    API_private(SSYMVu_STUB) ( blk,
                               n, a, lda, x, incx, y, incy, alpha, beta );
  } else {
    perror( "unmatched GPU generation" ); /* unmatched */
  }
#endif

#endif

}

#if ( 's'!='h' && 's'!='k' ) || ASPEN_HALF_ENABLED
#  include "aspen_devel_postdef.h"
#  include "../template/trmv_tn_upper_template.incl"
#endif

extern "C"
void
ssymv_upper_small (
              int const n,
              scalar_t const alpha,
              scalar_t const * a, int const lda,
              scalar_t const * x, int const incx,
              scalar_t const beta,
              _____ scalar_t * y, int const incy
        )
{
#if ( 's'!='h' && 's'!='k' ) || ASPEN_HALF_ENABLED

  if ( n <= 0 ) return;

#define	THREAD_SIZE		(512)
#  if defined(SMALL_NX)
#    undef      SMALL_NX
#  endif
#  if defined(SMALL_NY)
#    undef      SMALL_NY
#  endif
#  if CURRENT_GPU==800
#    define     SMALL_NX        16
#  else
#    define     SMALL_NX        32
#  endif
#    define     SMALL_NY        ((THREAD_SIZE)/SMALL_NX)

#  if defined(SMALL_TX)
#    undef      SMALL_TX
#  endif
#  if defined(SMALL_TY)
#    undef      SMALL_TY
#  endif
#  if CURRENT_GPU==800
#    define     SMALL_TX        64
#  else
#    define     SMALL_TX        32
#  endif
#    define     SMALL_TY        ((THREAD_SIZE)/SMALL_TX)

  API(TRMV_tn_upper_host)
    < scalar_t, SMALL_NX, SMALL_NY, SMALL_TX, SMALL_TY >
    ( n, alpha, beta, a, lda, x, incx, y, incy );

#endif
}

