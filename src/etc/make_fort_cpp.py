import sys
import re

def conversion( lines, tid, pattern ) :

  def _pre( linex ) :
    linex = re.sub( '\{\{', '@[@', linex )
    linex = re.sub( '\}\}', '@]@', linex )
    return linex
  def _post( linex ) :
    linex = re.sub( '@\[@', '{', linex )
    linex = re.sub( '@\]@', '}', linex )
    return linex

  _type     = pattern[tid][0]
  _F_prefix = pattern[tid][1]
  _C_prefix = pattern[tid][2]
  _hesy     = pattern[tid][3]
  _ext      = pattern[tid][4]

  sub_data = (
   ( r"@type."    , _type      ),
   ( r"@P."       , _F_prefix  ),
   ( r"@p."       , _C_prefix  ),
   ( r"@hesy."    , _hesy      ),
   ( r"@ext."     , _ext       ),
   ( "" , "" )
  )

  if int(_ext) < 0 :
    return

  linex = _pre( lines )
  linex = linex.format( char = 'char', int = 'int', dev = 'devptr_t' )
  for i in range(5):
    counter = 0
    t = re.subn( '\['+sub_data[i][0]+'([0-9]+)\]', '{sub:<\\1}', linex )
    if t[1] > 0 :
      counter = counter + t[1]
      linex = t[0]
    t = re.subn( '\['+sub_data[i][0]+'\]', '{sub}', linex )
    if t[1] > 0 :
      counter = counter + t[1]
      linex = t[0]
    if counter > 0 :
      linex = linex.format( sub=sub_data[i][1] )
  linex = _post( linex )
  print(linex)


pattern = (
  # _type     : the name of datatype
  # _F_prefix : prefix in Fortran
  # _C_prefix : prefix in C/C++
  # _hesy     : primary element
  # _ext      : some extra info
  ( 'cuddreal',        'W',    'w',    'sy'  ,   0 ),
  ( 'double',          'D',    'd',    'sy'  ,   0 ),
  ( 'cudfreal',        'F',    'f',    'sy'  ,  -1 ),
  ( 'float',           'S',    's',    'sy'  ,   0 ),
  ( 'cuddcomplex',     'U',    'u',    'he'  ,   0 ),
  ( 'cuDoubleComplex', 'Z',    'z',    'he'  ,   0 ),
  ( 'cudfcomplex',     'K',    'k',    'he'  ,  -1 ),
  ( 'cuFloatComplex',  'C',    'c',    'he'  ,   0 ),
  ( 'half',            'H',    'h',    'sy'  ,   1 ),
  ( 'int128',          'I128', 'i128', 'sy'  ,   0 ),
  ( 'int64',           'I64',  'i64',  'sy'  ,   0 ),
  ( 'int32',           'I32',  'i32',  'sy'  ,   0 ),
  ( 'int16',           'I16',  'i16',  'sy'  ,   0 ),
  ( 'bfloat16',        'BF16', 'bf16', 'sy'  ,  -1 ),
  )


data_Prolog=\
'''@@#include <ctype.h>
@@#include <stdio.h>
@@#include <string.h>
@@#include <stddef.h>
@@#include <stdint.h>
@@#include "cublas.h"

@@#include "aspen.h"
@@#include "aspen_fortran.h"

/@@/ external API from fortran calls
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
'''

data_Epilog=\
'''
}
'''


data_OPEN=\
'''#if [@ext.]==1
@@#if ASPEN_HALF_ENABLED
#endif'''

data_CLOSE=\
'''#if [@ext.]==1
@@#endif
#endif'''

data_HESYMV=\
'''  void
  aspen_[@p.][@hesy.]mv_ (
                  {char:<18} const * const uplo,
                  {int:<18} const * const n,
                  [@type.18] const * const alpha,
                  {dev:<18} const * const devPtrA,
                  {int:<18} const * const lda,
                  {dev:<18} const * const devPtrx,
                  {int:<18} const * const incx,
                  [@type.18] const * const beta,
                  {dev:<18} const * const devPtry,
                  {int:<18} const * const incy
                )
  {{
    [@type.] *A = ([@type.] * const)(uintptr_t)(*devPtrA);
    [@type.] *x = ([@type.] * const)(uintptr_t)(*devPtrx);
          [@type.] *y = ([@type.] *)(uintptr_t)(*devPtry);

    ASPEN_[@p.][@hesy.]mv( *uplo, *n,
                 *alpha, A, *lda, x, *incx, *beta,  y, *incy );
  }}
'''

data_AXPY=\
'''  void
  aspen_[@p.]axpy_ (
                  {int:<18} const * n,
                  [@type.18] const * alpha,
                  {dev:<18} const * devPtrx,
                  {int:<18} const * incx,
                  {dev:<18} const * devPtry,
                  {int:<18} const * incy
                )
  {{
    [@type.] *x = ([@type.] *)(uintptr_t)(*devPtrx);
          [@type.] *y = ([@type.] *)(uintptr_t)(*devPtry);

    ASPEN_[@p.]axpy( *n,
                 *alpha, x, *incx, y, *incy );
  }}
'''

data_AXPBY=\
'''  void
  aspen_[@p.]axpby_ (
                  {int:<18} const * n,
                  [@type.18] const * alpha,
                  {dev:<18} const * devPtrx,
                  {int:<18} const * incx,
                  [@type.18] const * beta,
                  {dev:<18} const * devPtry,
                  {int:<18} const * incy
                )
  {{
    [@type.] *x = ([@type.] *)(uintptr_t)(*devPtrx);
          [@type.] *y = ([@type.] *)(uintptr_t)(*devPtry);

    ASPEN_[@p.]axpby( *n,
                 *alpha, x, *incx, *beta, y, *incy );
  }}
'''

data_SWAP=\
'''  void
  aspen_[@p.]swap_ (
                  {int:<18} const * n,
                  {dev:<18} const * devPtrx,
                  {int:<18} const * incx,
                  {dev:<18} const * devPtry,
                  {int:<18} const * incy
                )
  {{
    [@type.] *x = ([@type.] *)(uintptr_t)(*devPtrx);
    [@type.] *y = ([@type.] *)(uintptr_t)(*devPtry);

    ASPEN_[@p.]swap( *n,
                 x, *incx, y, *incy );
  }}
'''

data_COPY=\
'''  void
  aspen_[@p.]copy_ (
                  {int:<18} const * n,
                  {dev:<18} const * devPtrx,
                  {int:<18} const * incx,
                  {dev:<18} const * devPtry,
                  {int:<18} const * incy
                )
  {{
    [@type.] *x = ([@type.] *)(uintptr_t)(*devPtrx);
          [@type.] *y = ([@type.] *)(uintptr_t)(*devPtry);

    ASPEN_[@p.]copy( *n,
                 x, *incx, y, *incy );
  }}
'''

data_SCAL=\
'''  void
  aspen_[@p.]scal_ (
                  {int:<18} const * n,
                  [@type.18] const * alpha,
                  {dev:<18} const * devPtrx,
                  {int:<18} const * incx
                )
  {{
    [@type.] *x = ([@type.] *)(uintptr_t)(*devPtrx);

    ASPEN_[@p.]scal( *n,
                 *alpha, x, *incx );
  }}
'''

data_ZERO=\
'''  void
  aspen_[@p.]zero_ (
                  {dev:<18} const * devPtrx,
                  {int:<18} const * n 
                )
  {{
    [@type.] *x = ([@type.] *)(uintptr_t)(*devPtrx);

    ASPEN_[@P.]ZERO( x, *n );
  }}
'''


print( data_Prolog )

print('')
for tid in range(14) :
    conversion( data_OPEN,   tid, pattern )
    conversion( data_HESYMV, tid, pattern )
    conversion( data_CLOSE,  tid, pattern )

print('')
for tid in range(14) :
    conversion( data_OPEN,   tid, pattern )
    conversion( data_AXPY,   tid, pattern )
    conversion( data_CLOSE,  tid, pattern )

print('')
for tid in range(14) :
    conversion( data_OPEN,   tid, pattern )
    conversion( data_AXPBY,  tid, pattern )
    conversion( data_CLOSE,  tid, pattern )

print('')
for tid in range(14) :
    conversion( data_OPEN,   tid, pattern )
    conversion( data_SWAP,   tid, pattern )
    conversion( data_CLOSE,  tid, pattern )

print('')
for tid in range(14) :
    conversion( data_OPEN,   tid, pattern )
    conversion( data_COPY,   tid, pattern )
    conversion( data_CLOSE,  tid, pattern )

print('')
for tid in range(14) :
    conversion( data_OPEN,   tid, pattern )
    conversion( data_SCAL,   tid, pattern )
    conversion( data_CLOSE,  tid, pattern )

print('')
for tid in range(14) :
    conversion( data_OPEN,   tid, pattern )
    conversion( data_ZERO,   tid, pattern )
    conversion( data_CLOSE,  tid, pattern )

print('')
print( data_Epilog )

