#include "_float_complex_.h"
#include "aspen_devel.h"


extern "C" void
API(chemv) ( char const uplo, int const n,
	     scalar_t const alpha,
	     scalar_t const * a, int const lda,
	     scalar_t const * x, int const incx,
	     scalar_t const beta,
	     scalar_t _____ * y, int const incy )
{
#if 'c'!='h' || ASPEN_HALF_ENABLED

  if ( n <= 0 ) return;
  if ( incy == 0 ) return;

#if 'c'!='h' && 'c'!='k'
  if ( alpha == makeCONST<scalar_t>(0) ) {
    if ( beta == makeCONST<scalar_t>(1) ) return;
    if ( beta == makeCONST<scalar_t>(0) && incy == 1 ) {
      API(CZERO) ( y, n );
    } else {
      API(cscal) ( n, beta, y, incy );
    }
    return;
  }
#endif

  int upper = (uplo=='U')||(uplo=='u');
  int lower = (uplo=='L')||(uplo=='l');
  if ( upper ) {
    API(CHEMVu) ( -1, n, a, lda, x, incx, y, incy, alpha, beta );
  } else if ( lower ) {
    API(CHEMVl) ( -1, n, a, lda, x, incx, y, incy, alpha, beta );
  } else {
    // error
  }

#endif
}

