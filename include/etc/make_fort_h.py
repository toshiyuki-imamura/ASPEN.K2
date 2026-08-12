import sys
import re

def conversion( lines, tid, pattern ) :

  def _dot( item ) :
    return (item.lower()).replace('_','.')

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

  linex=lines.format( char = 'char', int = 'int', dev = 'devptr_t' )
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
  linex = re.sub( '@\[@', '{', linex );
  linex = re.sub( '@\]@', '}', linex );
  print(linex)


pattern = (
  # _type     : the name of datatype
  # _F_prefix : prefix in Fortran
  # _C_prefix : prefix in C/C++
  # _hesy     : primary element
  # _ext      : some extra info
  ( 'cuddreal',        'W',    'w',    'sy'  ,   0 ),
  ( 'double',          'D',    'd',    'sy'  ,   0 ),
  #( 'cudfreal',        'F',    'f',    'sy'  ,  -1 ),
  ( 'float',           'S',    's',    'sy'  ,   0 ),
  ( 'half',            'H',    'h',    'sy'  ,   1 ),
  ( 'cuddcomplex',     'U',    'u',    'he'  ,   0 ),
  ( 'cuDoubleComplex', 'Z',    'z',    'he'  ,   0 ),
  ( 'cuFloatComplex',  'C',    'c',    'he'  ,   0 ),
  ( 'cuHalfComplex',   'K',    'k',    'he'  ,   1 ),
  ( 'int128',          'I128', 'i128', 'sy'  ,   0 ),
  ( 'int64',           'I64',  'i64',  'sy'  ,   0 ),
  ( 'int32',           'I32',  'i32',  'sy'  ,   0 ),
  ( 'int16',           'I16',  'i16',  'sy'  ,   0 ),
  #( 'bfloat16',        'BF16', 'bf16', 'sy'  ,  -1 ),
  )


data_Prolog=\
'''@@#ifndef ASPEN_FORTRAN_H_INCLUDED
@@#define ASPEN_FORTRAN_H_INCLUDED\t1

@@#if !defined(_____)
@@#  define  _____   @@/@@* */
@@#endif
@@#include "aspen_version.h"
@@#include "aspen_types.h"

typedef size_t devptr_t;

@@#ifdef __cplusplus
extern  "C" {
@@#endif

  @@/@@* User must call ASPEN_init for initialization */
  void
  aspen_init_ ( int const * device_id );

  @@/@@* User must finalize the ASPEN library by ASPEN_shutdown */
  void
  aspen_shutdown_ ( void );

  @@/@@* Get version info ASPEN_get_version_info */
  void
  aspen_get_version_info_ ( int *version,
                            char *codename, unsigned int length_codename,
                            char *releasedate, unsigned int length_releasedate );
'''

data_Epilog=\
'''
@@#ifdef __cplusplus
}
@@#endif

@@#endif '''


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
                );'''

data_AXPY=\
'''  void
  aspen_[@p.]axpy_ (
                  {int:<18} const * const n,
                  [@type.18] const * const alpha,
                  {dev:<18} const * const devPtrx,
                  {int:<18} const * const incx,
                  {dev:<18} const * const devPtry,
                  {int:<18} const * const incy
                );'''

data_AXPBY=\
'''  void
  aspen_[@p.]axpby_ (
                  {int:<18} const * const n,
                  [@type.18] const * const alpha,
                  {dev:<18} const * const devPtrx,
                  {int:<18} const * const incx,
                  [@type.18] const * const beta,
                  {dev:<18} const * const devPtry,
                  {int:<18} const * const incy
                );'''

data_SWAP=\
'''  void
  aspen_[@p.]swap_ (
                  {int:<18} const * const n,
                  {dev:<18} const * const devPtrx,
                  {int:<18} const * const incx,
                  {dev:<18} const * const devPtry,
                  {int:<18} const * const incy
                );'''

data_COPY=\
'''  void
  aspen_[@p.]copy_ (
                  {int:<18} const * const n,
                  {dev:<18} const * const devPtrx,
                  {int:<18} const * const incx,
                  {dev:<18} const * const devPtry,
                  {int:<18} const * const incy
                );'''

data_SCAL=\
'''  void
  aspen_[@p.]scal_ (
                  {int:<18} const * const n,
                  [@type.18] const * const alpha,
                  {dev:<18} const * const devPtrx,
                  {int:<18} const * const incx
                );'''

data_ZERO=\
'''  void
  aspen_[@p.]zero_ (
                  {dev:<18} const * const devPtrx,
                  {int:<18} const * const n 
                );'''

N = len(pattern)

print( data_Prolog )

print('')
for tid in range(N) :
    conversion( data_HESYMV, tid, pattern )

print('')
for tid in range(N) :
    conversion( data_AXPY,   tid, pattern )

print('')
for tid in range(N) :
    conversion( data_AXPBY,  tid, pattern )

print('')
for tid in range(N) :
    conversion( data_SWAP,   tid, pattern )

print('')
for tid in range(N) :
    conversion( data_COPY,   tid, pattern )

print('')
for tid in range(N) :
    conversion( data_SCAL,   tid, pattern )

print('')
for tid in range(N) :
    conversion( data_ZERO,   tid, pattern )

print('')
print( data_Epilog )

