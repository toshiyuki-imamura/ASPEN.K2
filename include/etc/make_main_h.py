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

  if int(_ext) ==2 :
    print( '  // the header of the function is defined here,' )
    print( '  // however, the function may not be supported.' )

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
  #( 'cudfreal',        'F',    'f',    'sy'  ,   2 ),
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
  #( 'bfloat16',        'BF16', 'bf16', 'sy'  ,   2 ),
  )


data_Prolog=\
'''@@#ifndef ASPEN_H_INCLUDED
@@#define ASPEN_H_INCLUDED\t1

@@#include "aspen_version.h"
@@#include "aspen_types.h"


@@#if !defined(_____)
@@#  define _____ @@/@@* */
@@#endif

@@#ifdef __cplusplus
extern  "C" {
@@#endif

  @@/@@* User must call ASPEN_init for initialization */
  int
  ASPEN_init ( int const device_id );

  @@/@@* User must finalize the ASPEN library by ASPEN_shutdown */
  int
  ASPEN_shutdown ( void );

  @@/@@* Get version info ASPEN_get_version_info */
  void
  ASPEN_get_version_info ( int *version, char *codename, char *releasedate );
'''

data_Epilog=\
'''
@@#ifdef __cplusplus
}
@@#endif

@@#endif '''


data_HESYMV=\
'''  void
  ASPEN_[@p.][@hesy.]mv (
                  {char:<18} const  uplo,
                  {int:<18} const  n,
                  [@type.18] const   alpha,
                  [@type.18] const * const a,
                  {int:<18} const  lda,
                  [@type.18] const * const x,
                  {int:<18} const  incx,
                  [@type.18] const   beta,
                  [@type.18] _____ * const y,
                  {int:<18} const  incy
                );'''

data_AXPY=\
'''  void
  ASPEN_[@p.]axpy (
                  {int:<18} const  n,
                  [@type.18] const   alpha,
                  [@type.18] const * const x,
                  {int:<18} const  incx,
                  [@type.18] _____ * const y,
                  {int:<18} const  incy
                );'''

data_AXPBY=\
'''  void
  ASPEN_[@p.]axpby (
                  {int:<18} const  n,
                  [@type.18] const   alpha,
                  [@type.18] const * const x,
                  {int:<18} const  incx,
                  [@type.18] const   beta,
                  [@type.18] _____ * const y,
                  {int:<18} const  incy
                );'''

data_SWAP=\
'''  void
  ASPEN_[@p.]swap (
                  {int:<18} const  n,
                  [@type.18] _____ * const x,
                  {int:<18} const  incx,
                  [@type.18] _____ * const y,
                  {int:<18} const  incy
                );'''

data_COPY=\
'''  void
  ASPEN_[@p.]copy (
                  {int:<18} const  n,
                  [@type.18] const * const x,
                  {int:<18} const  incx,
                  [@type.18] _____ * const y,
                  {int:<18} const  incy
                );'''

data_SCAL=\
'''  void
  ASPEN_[@p.]scal (
                  {int:<18} const  n,
                  [@type.18] const   alpha,
                  [@type.18] _____ * const x,
                  {int:<18} const  incx
                );'''

data_ZERO=\
'''  void
  ASPEN_[@P.]ZERO (
                  [@type.18] _____ * const x,
                  {int:<18} const  n 
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

