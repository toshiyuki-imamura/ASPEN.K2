#include "_int128_.h"
#include "aspen_devel.h"


extern "C" void
API(i128symv) ( char const uplo, int const n,
	     scalar_t const alpha,
	     scalar_t const * a, int const lda,
	     scalar_t const * x, int const incx,
	     scalar_t const beta,
	     scalar_t _____ * y, int const incy )
{
#if 'i'!='h' || ASPEN_HALF_ENABLED

  if ( n <= 0 ) return;
  if ( incy == 0 ) return;

#if 'i'!='h' && 'i'!='k'
  if ( alpha == makeCONST<scalar_t>(0) ) {
    if ( beta == makeCONST<scalar_t>(1) ) return;
    if ( beta == makeCONST<scalar_t>(0) && incy == 1 ) {
      API(I128ZERO) ( y, n );
    } else {
      API(i128scal) ( n, beta, y, incy );
    }
    return;
  }
#endif

  int upper = (uplo=='U')||(uplo=='u');
  int lower = (uplo=='L')||(uplo=='l');
  if ( upper ) {
    API(I128SYMVu) ( -1, n, a, lda, x, incx, y, incy, alpha, beta );
  } else if ( lower ) {
    API(I128SYMVl) ( -1, n, a, lda, x, incx, y, incy, alpha, beta );
  } else {
    // error
  }

#endif
}

