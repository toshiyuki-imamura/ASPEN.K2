import sys
import re


def conversion( lines, tid, pattern ) :

  def _dot( item ) :
    return (item.lower()).replace('_','.')

  _space    = _dot(_Space)
  _mode     = _dot(_Mode)
  _volatile = _dot(_Volatile)

  _type     = pattern[tid][0]
  _data     = pattern[tid][1]
  _e_type   = pattern[tid][2]
  _e_e_type = pattern[tid][3]
  _bin      = pattern[tid][4]
  _abin     = pattern[tid][5]
  _ext      = pattern[tid][6]
  _direct   = pattern[tid][7]

  sub_data = (
   ( r"@Space."   , _Space    ),
   ( r"@space."   , _space    ),
   ( r"@Mode."    , _Mode     ),
   ( r"@mode."    , _mode     ),
   ( r"@Volatile.", _Volatile ),
   ( r"@volatile.", _volatile ),
   ( r"@type."    , _type     ),
   ( r"@e_type."  , _e_type   ),
   ( r"@e_e_type.", _e_e_type ),
   ( r"@data."    , _data     ),
   ( r"@bin."     , _bin      ),
   ( r"@abin."    , _abin     ),
   ( r"@ext."     , _ext      ),
   ( r"@direct."  , _direct   ),
   ( r"@V."       , (_Volatile+' ')[0] ),
   ( r"@T."       , (_e_type+' ')[0] ),
   ( "" , "" )
  )

  linex=lines
  for i in range(len(sub_data)-1):
    linex=re.sub( sub_data[i][0] , sub_data[i][1], linex )
  print(linex)


pattern = (
  #
  # _type      : the name of datatype
  # _data      : the number of words required to represented by _e_e_type
  #              in the case of big endian, int128#_data must be 2
  # _e_type    : primary element
  # _e_e_type  : secondary element consisting _e_type
  # _bin       : inline assmble bin representation
  # _abin      : inline assmble argument prefix
  # _ext       : some extra info or trick items, asm inline arguments type
  # _direct    : direct return or conversion (direct: 1, convert: 0)
  #
  ('cuddreal',        '2', 'double',   'double',   '.b64', 'd', 'double',  '0'),
  ('double',          '1', 'double',   'double',   '.b64', 'd', 'double',  '1'),
  #('cudfreal',        '2', 'float',    'float',    '.b32', 'f', 'float',  '0'),
  ('float',           '1', 'float',    'float',    '.b32', 'f', 'float',   '1'),
  ('cuddcomplex',     '4', 'cuddreal', 'double',   '.b64', 'd', 'ddreal',  '0'),
  ('cuDoubleComplex', '2', 'double',   'double',   '.b64', 'd', 'double',  '0'),
  ('cuFloatComplex',  '2', 'float',    'float',    '.b32', 'f', 'float',   '0'),
  ('cuHalfComplex',   '2', 'half',     'half',     '.b16', 'h', 'ushort',  '0'),
  ('half',            '1', 'half',     'half',     '.b16', 'h', 'ushort',  '0'),
  ('int128',          '2', 'int64_t',  'int64_t',  '.u64', 'l', 'uint64_t','0'),
  ('int64',           '1', 'int64_t',  'int64_t',  '.u64', 'l', 'int64_t', '0'),
  ('int32',           '1', 'int32_t',  'int32_t',  '.u32', 'r', 'int32_t', '0'),
  ('int16',           '1', 'int16_t',  'int16_t',  '.u16', 'h', 'int16_t', '0'),
  #('int8',            '1', 'int8_t',   'int8_t',   '.u8',  'z', 'int8_t', '0'),
  #('bfloat16',        '1', 'bfloat16', 'bfloat16', '.u16', 'h', 'ushort', '0'),
  )


data_LD0=\
'''template < class TYPE >
__forceinline__ __device__ TYPE
Load@Volatile.@Space.@Mode. ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }
'''

data_LD1=\
'''template < >
__forceinline__ __device__ @type.
Load@Volatile.@Space.@Mode. ( @type. const * __restrict__ const addr__ )
{
#if @data.==4
  typedef struct { @e_type. x; @e_type. y; } u_type;
  typedef struct { @e_e_type. sx; @e_e_type. sy; } v_type;
  @type. * addr_ = (@type. *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld@volatile.@space.@mode..v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(u.sx), "=@abin."(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<@e_type. *>(&u));
  asm volatile ( "ld@volatile.@space.@mode..v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(v.sx), "=@abin."(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<@e_type. *>(&v));
  @type. const t = *(reinterpret_cast<@type. *>(&w));
  return t;
#endif
#if @data.==2
  struct { @ext. sx; @ext. sy; } u;
  asm volatile ( "ld@volatile.@space.@mode..v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(u.sx), "=@abin."(u.sy) : "l"(addr__) );
  @type. const t = *(reinterpret_cast<@type. *>(&u));
  return t;
#endif
#if @data.==1
#if '@V.' != ' ' && '@abin.' != 'h'
  @type. volatile * addr = (@type. *)addr__;
  return *addr;
#else
  @ext. u;
  asm volatile ( "ld@volatile.@space.@mode.@bin. %0, [%1];"
                 : "=@abin."(u) : "l"(addr__) );
#if @direct.==1
  return u;
#else
  @type. const t = *(reinterpret_cast<@type. *>(&u));
  return t;
#endif
#endif
#endif
}
'''

data_LDx0=\
'''@@#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ TYPE
Load@Mode.@Space. ( TYPE const * __restrict__ const addr__ )
{ return makeCONST <TYPE> (0); }
@@#endif
'''

data_LDx1=\
'''@@#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ @type.
Load@Mode.@Space. ( @type. const * __restrict__ const addr__ )
{
#if @data.==4
  typedef struct { @e_type. x; @e_type. y; } u_type;
  typedef struct { @e_e_type. sx; @e_e_type. sy; } v_type;
  @type. * addr_ = (@type. *)addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  v_type u, v;
  u_type w;
  asm volatile ( "ld@mode..gpu@space..v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(u.sx), "=@abin."(u.sy) : "l"(&addr___->x) );
  w.x = *(reinterpret_cast<@e_type. *>(&u));
  asm volatile ( "ld@mode..gpu@space..v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(v.sx), "=@abin."(v.sy) : "l"(&addr___->y) );
  w.y = *(reinterpret_cast<@e_type. *>(&v));
  @type. const t = *(reinterpret_cast<@type. *>(&w));
  return t;
#endif

#if @data.==2
  struct { @ext. sx; @ext. sy; } u;
  asm volatile ( "ld@mode..gpu@space..v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(u.sx), "=@abin."(u.sy) : "l"(addr__) );
  @type. const t = *(reinterpret_cast<@type. *>(&u));
  return t;
#endif

#if @data.==1
  @ext. u;
  asm volatile ( "ld@mode..gpu@space.@bin. %0, [%1];"
                 : "=@abin."(u) : "l"(addr__) );
#if @direct.==1
  return u;
#else
  @type. const t = *(reinterpret_cast<@type. *>(&u));
  return t;
#endif
#endif
}
@@#endif
'''

data_LDsh0=\
'''template < class TYPE >
__forceinline__ __device__ TYPE
Load@Volatile._Shared ( SHMEM_addr_t const addr__ )
{ return makeCONST <TYPE> (0); }
'''

data_LDsh1=\
'''template < >
__forceinline__ __device__ @type.
Load@Volatile._Shared ( SHMEM_addr_t const addr__ )
{
#if @data.==4
  struct { @e_e_type. sx; @e_e_type. sy; } u;
  asm volatile ( "ld@volatile..shared.v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(u.sx), "=@abin."(u.sy) : "r"(addr__) );
  @e_type. const tx = *(reinterpret_cast<@e_type. *>(&u));
  struct { @e_e_type. sx; @e_e_type. sy; } v;
  SHMEM_addr_t const bddr__ = addr__ + sizeof(@e_type.);
  asm volatile ( "ld@volatile..shared.v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(v.sx), "=@abin."(v.sy) : "r"(bddr__) );
  @e_type. const ty = *(reinterpret_cast<@e_type. *>(&v));
  struct { @e_type. tx; @e_type. ty; } w = { tx, ty };
  @type. const t = *(reinterpret_cast<@type. *>(&w));
  return t;
#endif

#if @data.==2
  struct { @ext. sx; @ext. sy; } u;
  asm volatile ( "ld@volatile..shared.v2@bin. {%0,%1}, [%2];"
                 : "=@abin."(u.sx), "=@abin."(u.sy) : "r"(addr__) );
  @type. const t = *(reinterpret_cast<@type. *>(&u));
  return t;
#endif

#if @data.==1
  @ext. u;
  asm volatile ( "ld@volatile..shared@bin. %0, [%1];"
                 : "=@abin."(u) : "r"(addr__) );
#if @direct.==1
  return u;
#else
  @type. const t = *(reinterpret_cast<@type. *>(&u));
  return t;
#endif
#endif
}
'''

data_ST0=\
'''template < class TYPE >
__forceinline__ __device__ void
Store@Volatile.@Space.@Mode. ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }
'''

data_ST1=\
'''template < >
__forceinline__ __device__ void
Store@Volatile.@Space.@Mode. ( @type. * __restrict__ const addr__, @type. const s )
{
#if @data.==4
  typedef struct { @e_type. x; @e_type. y; } u_type;
  typedef struct { @e_e_type. x; @e_e_type. y; } v_type;
  @type. * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  @type. ss = static_cast<@type.>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st@volatile.@space.@mode..v2.f64 [%2], {%0,%1};"
                 : : "@abin."(v1.x), "@abin."(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st@volatile.@space.@mode..v2.f64 [%2], {%0,%1};"
                 : : "@abin."(v2.x), "@abin."(v2.y), "l"(&addr___->y) );
#endif

#if @data.==2
  typedef struct { @ext. sx; @ext. sy; } u_type;
  @type. ss = static_cast<@type.>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st@volatile.@space.@mode..v2@bin. [%2], {%0,%1};"
                 : : "@abin."(u.sx), "@abin."(u.sy), "l"(addr__) );
#endif

#if @data.==1
  @type. ss = static_cast<@type.>(s);
  @ext. t = *(reinterpret_cast<@ext. *>(&ss));
  asm volatile ( "st@volatile.@space.@mode.@bin. [%1], %0;"
                 : : "@abin."(t), "l"(addr__) );
#endif
}
'''

data_STx0=\
'''@@#if CURRENT_GPU>=700
template < class TYPE >
__forceinline__ __device__ void
Store@Mode.@Space. ( TYPE * __restrict__ const addr__, TYPE const s )
{ ; }
@@#endif
'''

data_STx1=\
'''@@#if CURRENT_GPU>=700
template < >
__forceinline__ __device__ void
Store@Mode.@Space. ( @type. * __restrict__ const addr__, @type. const s )
{
#if @data.==4
  typedef struct { @e_type. x; @e_type. y; } u_type;
  typedef struct { @e_e_type. x; @e_e_type. y; } v_type;
  @type. * addr_ = addr__;
  u_type const * const addr___ = (reinterpret_cast<u_type *>(addr_));
  @type. ss = static_cast<@type.>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st@mode..gpu@space..v2.f64 [%2], {%0,%1};"
                 : : "@abin."(v1.x), "@abin."(v1.y), "l"(&addr___->x) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  asm volatile ( "st@mode..gpu@space..v2.f64 [%2], {%0,%1};"
                 : : "@abin."(v2.x), "@abin."(v2.y), "l"(&addr___->y) );
#endif

#if @data.==2
  typedef struct { @ext. sx; @ext. sy; } u_type;
  @type. ss = static_cast<@type.>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st@mode..gpu@space..v2@bin. [%2], {%0,%1};"
                 : : "@abin."(u.sx), "@abin."(u.sy), "l"(addr__) );
#endif

#if @data.==1
  @type. ss = static_cast<@type.>(s);
  @ext. t = *(reinterpret_cast<@ext. *>(&ss));
  asm volatile ( "st@mode..gpu@space.@bin. [%1], %0;"
                 : : "@abin."(t), "l"(addr__) );
#endif
}
@@#endif
'''

data_STsh0=\
'''template < class TYPE >
__forceinline__ __device__ void
Store@Volatile._Shared ( SHMEM_addr_t const addr__, TYPE const s )
{ ; }
'''

data_STsh1=\
'''template < >
__forceinline__ __device__ void
Store@Volatile._Shared ( SHMEM_addr_t const addr__, @type. const s )
{
#if @data.==4
  typedef struct { @e_type. x; @e_type. y; } u_type;
  typedef struct { @e_e_type. x; @e_e_type. y; } v_type;
  @type. ss = static_cast<@type.>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  v_type v1 = *(reinterpret_cast<v_type *>(&u.x));
  asm volatile ( "st@volatile..shared.v2@bin. [%2], {%0,%1};"
                 : : "@abin."(v1.x), "@abin."(v1.y), "r"(addr__) );
  v_type v2 = *(reinterpret_cast<v_type *>(&u.y));
  SHMEM_addr_t const bddr__ = addr__ + sizeof(@e_type.);
  asm volatile ( "st@volatile..shared.v2@bin. [%2], {%0,%1};"
                 : : "@abin."(v2.x), "@abin."(v2.y), "r"(bddr__) );
#endif

#if @data.==2
  typedef struct { @ext. sx; @ext. sy; } u_type;
  @type. ss = static_cast<@type.>(s);
  u_type u = *(reinterpret_cast<u_type *>(&ss));
  asm volatile ( "st@volatile..shared.v2@bin. [%2], {%0,%1};"
                 : : "@abin."(u.sx), "@abin."(u.sy), "r"(addr__) );
#endif

#if @data.==1
  @type. ss = static_cast<@type.>(s);
  @ext. t = *(reinterpret_cast<@ext. *>(&ss));
  asm volatile ( "st@volatile..shared@bin. [%1], %0;"
                 : : "@abin."(t), "r"(addr__) );
#endif
}
'''

data_ConfLD0=\
'''template < class TYPE >
__forceinline__ __device__ TYPE
Load_Global_with_Confirm( TYPE * addr__ )
{
  return Load_Acquire_Global ( addr__ );
}
'''

data_ConfST0=\
'''template < class TYPE >
__forceinline__ __device__ void
Store_Global_with_Confirm_sub( TYPE * addr__, TYPE const s )
{
  Store_Global ( addr__, s );
  __threadfence ( );
@@#pragma unroll 1
  while ( true ) {
    __nanosleep__(0);
    if ( s == Load_Global_CV ( addr__ ) ) break;
  }
}

template < class TYPE >
__forceinline__ __device__ void
Store_Global_with_Confirm( TYPE * addr__, TYPE const s )
{
  TYPE ss = (TYPE)s;
  switch ( 8 * sizeof(TYPE) ) {
  case 16:
    {
      int16 t = *(reinterpret_cast<int16 *>(&ss));
      int16 * addr_ = (reinterpret_cast<int16 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 32:
    {
      int32 t = *(reinterpret_cast<int32 *>(&ss));
      int32 * addr_ = (reinterpret_cast<int32 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 64:
    {
      int64 t = *(reinterpret_cast<int64 *>(&ss));
      int64 * addr_ = (reinterpret_cast<int64 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 128:
    {
      int128 t = *(reinterpret_cast<int128 *>(&ss));
      int128 * addr_ = (reinterpret_cast<int128 *>(addr__));
      Store_Global_with_Confirm_sub ( addr_, t );
    }
    break;
  case 256:
    {
      typedef struct { int128 sx; int128 sy; } u_type;
      u_type u = *(reinterpret_cast<u_type *>(&ss));
      u_type * addr_ = (reinterpret_cast<u_type *>(addr__));
      Store_Global_with_Confirm_sub ( &addr_->sx, u.sx );
      Store_Global_with_Confirm_sub ( &addr_->sy, u.sy );
    }
    break;
  }
}
'''

data_Prolog=\
'''@@#ifndef ASPEN_LDST_H_INCLUDED
@@#define ASPEN_LDST_H_INCLUDED           1

@@#include "aspen_types.h"
@@#include "aspen_shmem.h"
@@#include "aspen_const.h"

'''

data_Epilog=\
''' 
// ---------------------------------------------------------

@@#define	__PROXY_SHMEM_DECL__(...)	extern __shared__ int __shmem[]

__PROXY_SHMEM_DECL__();

__forceinline__ __device__ unsigned int
shared_memory_size_per_block( void )
{
  unsigned int ret;
  asm volatile ( "mov.s32 %0, %dynamic_smem_size;" : "=r"(ret) );
  return ret;
}

__forceinline__ __device__ SHMEM_addr_t
shared_memory_raw_proxy_root( void )
{
  SHMEM_addr_t ret;
  asm volatile ( "mov.u32 %0, __shmem;" : "=r"(ret) );
  return ret;
}

template < class TYPE >
__forceinline__ __device__ TYPE *
shared_memory_proxy_root( void )
{
  return reinterpret_cast<TYPE *>(__shmem);
}

template < class TYPE >
__forceinline__ __device__ SHMEM_addr_t
shared_memory_raw_proxy( int const offset )
{
  return shared_memory_raw_proxy_root ( ) + sizeof(TYPE) * offset;
}

template < class TYPE >
__forceinline__ __device__ TYPE *
shared_memory_proxy( void )
{
  int * ret = shared_memory_proxy_root < int > ( );
  return reinterpret_cast<TYPE *>(ret);
}

template < class TYPE >
__forceinline__ __device__ TYPE *
shared_memory_proxy( int const offset )
{
  return shared_memory_proxy <TYPE> ( ) + offset;
}

@@#if 0
template < class TYPE >
__forceinline__ __device__ TYPE
Load_Shared_from_BASE ( int const offset )
{
  TYPE * shmem = shared_memory_proxy < TYPE > ( offset );
  return *shmem;
}

template < class TYPE >
__forceinline__ __device__ TYPE
Load_Volatile_Shared_from_BASE ( int const offset )
{
  SHMEM_addr_t const shmem = shared_memory_raw_proxy < TYPE > ( offset );
  return Load_Volatile_Shared < TYPE > ( shmem );
}

template < class TYPE >
__forceinline__ __device__ void
Store_Shared_from_BASE ( int const offset, TYPE const x )
{
  TYPE * shmem = shared_memory_proxy < TYPE > ( offset );
  *shmem = x;
}

template < class TYPE >
__forceinline__ __device__ void
Store_Volatile_Shared_from_BASE ( int const offset, TYPE const x )
{
  SHMEM_addr_t const shmem = shared_memory_raw_proxy < TYPE > ( offset );
  Store_Volatile_Shared ( shmem, x );
}
@@#endif
// ---------------------------------------------------------

// ---------------------------------------------------------
__forceinline__ __device__ void *
convert_addr_to_global ( void const * __restrict__ const addr__ )
{
  unsigned long long int  global_addr;
  asm volatile ( "cvta.to.global.u64 %0, %1;"
                 : "=l"(global_addr) : "l"(addr__) );
  return (void *)global_addr;
}

__forceinline__ __device__ SHMEM_addr_t
convert_addr_to_shared ( void const * __restrict__ const addr__ )
{
  SHMEM_addr_t  shared_addr;
  asm volatile ( "{\\n\\t"
                 ".reg .u32 %temp;\\n\\t"
                 "cvt.u32.u64 %temp, %1;\\n\\t"
                 "cvta.to.shared.u32 %0, %temp;\\n\\t"
                 "}"
                 : "=r"(shared_addr) : "l"(addr__) );
  return shared_addr;
}

__forceinline__ __device__ void
prefetch_L1 ( void const * __restrict__ const addr__ )
{
  unsigned long long int const addr = (unsigned long long int) addr__;
  asm volatile ( "prefetch.global.L1 [%0];"
                 : : "l"(addr) );
}

__forceinline__ __device__ void
prefetch_L2 ( void const * __restrict__ const addr__ )
{
  unsigned long long int const addr = (unsigned long long int) addr__;
  asm volatile ( "prefetch.global.L2 [%0];"
                 : : "l"(addr) );
}
// ---------------------------------------------------------

@@#endif'''

#N = len(pattern) - 2
N = len(pattern)

print( data_Prolog )

for __Space in [ '', '_Global' ] :
  for __Mode in [ '', 'v', '_CG', '_CV', '_LU', '_CS', '_NC' ] :
    _Space = __Space
    _Mode  = __Mode

    if _Mode == 'v' :
      _Volatile = '_Volatile'
      _Mode = ''
    else :
      _Volatile = ''

    if _Mode == '_NC' and _Space != '_Global' :
      break

    print( '' )
    print( '// ---------------------------------------------------------' )

    conversion( data_LD0, 0, pattern )

    for _Type in range(N) :
      conversion( data_LD1, _Type, pattern )

    print( '// ---------------------------------------------------------' )

for __Space in [ '', '_Global' ] :
  for __Mode in [ '_Relaxed', '_Acquire' ] :
    _Space = __Space
    _Mode  = __Mode

    print( '' )
    print( '// ---------------------------------------------------------' )

    conversion( data_LDx0, 0, pattern )

    for _Type in range(N) :
      conversion( data_LDx1, _Type, pattern )

    print( '// ---------------------------------------------------------' )

for __Space in [ '', '_Global' ] :
  for __Mode in [ '', 'v', '_CG', '_WB', '_CS', '_WT' ] :
    _Space = __Space
    _Mode  = __Mode

    if _Mode == 'v' :
      _Volatile = '_Volatile'
      _Mode = ''
    else :
      _Volatile = ''

    print( '' )
    print( '// ---------------------------------------------------------' )

    conversion( data_ST0, 0, pattern )

    for _Type in range(N) :
      conversion( data_ST1, _Type, pattern )

    print( '// ---------------------------------------------------------' )

for __Space in [ '', '_Global' ] :
  for __Mode in [ '_Release', '_Relaxed' ] :
    _Space = __Space
    _Mode  = __Mode

    print( '' )
    print( '// ---------------------------------------------------------' )

    conversion( data_STx0, 0, pattern )

    for _Type in range(N) :
      conversion( data_STx1, _Type, pattern )

    print( '// ---------------------------------------------------------' )

_Space    = ''
_Mode     = ''
for _Volatile in [ '', '_Volatile' ] :
  
  print( '' )
  print( '// ---------------------------------------------------------' )
  conversion( data_LDsh0, 0, pattern )
  for _Type in range(N) :
    conversion( data_LDsh1, _Type, pattern )
  print( '// ---------------------------------------------------------' )
  
  print( '' )
  print( '// ---------------------------------------------------------' )
  conversion( data_STsh0, 0, pattern )
  for _Type in range(N) :
    conversion( data_STsh1, _Type, pattern )
  print( '// ---------------------------------------------------------' )

print( '' )
print( '// ---------------------------------------------------------' )
conversion( data_ConfLD0, 0, pattern )
conversion( data_ConfST0, 0, pattern )
print( '// ---------------------------------------------------------' )

print( data_Epilog )

