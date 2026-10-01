#if !defined(CURRENT_GPU)
#  include "../tuning/CURRENT_GPU"
#endif
#if !defined(GPU_ARCH)
#  define	GPU_ARCH	CURRENT_GPU
#endif

#include "_half_complex_.h"
#include "aspen_devel.h"

#define NUM_THREADS             64


#if !defined(GPU_ARCH)
error !!
#error un-supported architecture
#endif
#if GPU_ARCH == Tesla
error !!
#error un-supported architecture
#endif // Tesla
#if GPU_ARCH == Fermi
error !!
#error un-supported architecture
#endif // Fermi
#if GPU_ARCH == Kepler
error !!
#error un-supported architecture
#endif // Kepler
#if GPU_ARCH == Kepler2
error !!
#error un-supported architecture
#endif // Kepler2
#if GPU_ARCH == Kepler3
error !!
#error un-supported architecture
#endif // Kepler3
#if GPU_ARCH == Maxwell
error !!
#error un-supported architecture
#endif // Maxwell
#if GPU_ARCH == Maxwell2
error !!
#error un-supported architecture
#endif // Maxwell2
#if GPU_ARCH == Maxwell3
error !!
#error un-supported architecture
#endif // Maxwell3
#if GPU_ARCH == Pascal
error !!
#error un-supported architecture
#endif // Pascal
#if GPU_ARCH == Pascal1
error !!
#error un-supported architecture
#endif // Pascal1
#if GPU_ARCH == Pascal2
error !!
#error un-supported architecture
#endif // Pascal2
#if GPU_ARCH == Pascal3
error !!
#error un-supported architecture
#endif // Pascal3
#if GPU_ARCH == Volta
error !!
#error un-supported architecture
#endif // Volta
#if GPU_ARCH == Turing
error !!
#error un-supported architecture
#endif // Turing


#define	USE_INLINE	1


#include "aspen_devel_postdef.h"

#define	ASPEN_UPLO		UPPER
#define	SUMUP_PREFIX		KHEMVU

#if CURRENT_GPU==GPU_ARCH
#  if !defined(BLOCK_SIZE) || !defined(VX) || !defined(UX)
#    include "../tuning/param-khemvu.h"
#  endif
#  if defined(BLOCK_SIZE)
#    undef BLOCK_SIZE
#  endif
#  if defined(VX)
#    undef VX
#  endif
#  if defined(UX)
#    undef UX
#  endif
#  include "../template/hesymv_atomic_template.incl"
#endif


extern "C" void
API_private(KHEMVu_STUB) ( int const blk,
                           int const n, scalar_t const * a, int const lda,
                           scalar_t const * x, int const incx,
                           scalar_t * y, int const incy,
                           scalar_t const alpha, scalar_t const beta )
{

  // y = alpha * A * x + beta * y
  // y(1:n1)
  // x(1:n2)

#if CURRENT_GPU==GPU_ARCH
  if ( n == 0 && blk == -1 ) return;
  int BLK = blk;
# include "../tuning/param-khemvu.h"
# include "../tuning/khemv-upper-auto.h"
#else
  fprintf( stderr,
           "Caution, ASPEN is tuned up for %s.\n",
           ASPEN_GPU_Names(CURRENT_GPU) );
#endif

}

