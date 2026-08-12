#include "_ddreal_.h"
#include "aspen_devel.h"


extern "C" void
API(wsymv) ( char const uplo, int const n,
	     scalar_t const alpha,
	     scalar_t const * a, int const lda,
	     scalar_t const * x, int const incx,
	     scalar_t const beta,
	     scalar_t _____ * y, int const incy )
{
#if 'w'!='h' || ASPEN_HALF_ENABLED

  if ( n <= 0 ) return;
  if ( incy == 0 ) return;

#if 'w'!='h' && 'w'!='k'
  if ( alpha == makeCONST<scalar_t>(0) ) {
    if ( beta == makeCONST<scalar_t>(1) ) return;
    if ( beta == makeCONST<scalar_t>(0) && incy == 1 ) {
      API(WZERO) ( y, n );
    } else {
      API(wscal) ( n, beta, y, incy );
    }
    return;
  }
#endif

  int upper = (uplo=='U')||(uplo=='u');
  int lower = (uplo=='L')||(uplo=='l');
  if ( upper ) {
    API(WSYMVu) ( -1, n, a, lda, x, incx, y, incy, alpha, beta );
  } else if ( lower ) {
    API(WSYMVl) ( -1, n, a, lda, x, incx, y, incy, alpha, beta );
  } else {
    // error
  }

#endif
}

