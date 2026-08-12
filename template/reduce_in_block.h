#pragma once

#  if GPU_ARCH>=300

//=============================================================================

typedef struct {
  uint32_t  x;
  uint32_t  y;
} uint32_t2;

typedef struct {
  uint32_t2  x;
  uint32_t2  y;
} uint32_t2x2;

typedef struct {
  uint32_t  x;
  uint32_t  y;
  uint32_t  z;
} uint32_t3;

typedef struct {
  uint32_t3  x;
  uint32_t3  y;
} uint32_t3x2;

typedef struct {
  uint32_t  x;
  uint32_t  y;
  uint32_t  z;
  uint32_t  w;
} uint32_t4;

typedef struct {
  uint32_t4  x;
  uint32_t4  y;
} uint32_t4x2;

//=============================================================================

template < class TYPE >
__forceinline__ __device__ TYPE
__SHFL_xor ( TYPE const x, int const laneMask, int const width )
{
#    if CUDA_VERSION >= 9000
#      define SHFL_XOR( x, laneMask, width, ...)        \
  __shfl_xor_sync ( 0xffffffff, x, laneMask, width )
#    else
#      define SHFL_XOR( x, laneMask, width, ...)	\
  __shfl_xor ( x, laneMask, width )
#    endif
  TYPE _____ xx = x;
  if constexpr ( sizeof(TYPE) == 2 ) {
#    if 0
    uint16_t const y = *(reinterpret_cast < uint16_t* > (&xx));
    uint16_t _____ z = SHFL_XOR ( y, laneMask, width );
    xx = *(reinterpret_cast < TYPE* > (&z));
#    else
    __half const y = *(reinterpret_cast < __half* > (&xx));
    __half _____ z = SHFL_XOR ( y, laneMask, width );
    xx = *(reinterpret_cast < TYPE* > (&z));
#    endif
  }
  if constexpr ( sizeof(TYPE) == 4 ) {
    uint32_t const y = *(reinterpret_cast < uint32_t* > (&xx));
    uint32_t _____ z = SHFL_XOR ( y, laneMask, width );
    xx = *(reinterpret_cast < TYPE* > (&z));
  }
  if constexpr ( sizeof(TYPE) == 8 ) {
    uint32_t2 const y = *(reinterpret_cast <uint32_t2* > (&xx));
    uint32_t2 _____ z;
    z.x = SHFL_XOR ( y.x, laneMask, width );
    z.y = SHFL_XOR ( y.y, laneMask, width );
    xx = *(reinterpret_cast < TYPE* > (&z));
  }
  if constexpr ( sizeof(TYPE) == 16 ) {
    uint32_t4 const y = *(reinterpret_cast < uint32_t4* > (&xx));
    uint32_t4 _____ z;
    z.x = SHFL_XOR ( y.x, laneMask, width );
    z.y = SHFL_XOR ( y.y, laneMask, width );
    z.z = SHFL_XOR ( y.z, laneMask, width );
    z.w = SHFL_XOR ( y.w, laneMask, width );
    xx = *(reinterpret_cast < TYPE* > (&z));
  }
  if constexpr ( sizeof(TYPE) == 32 ) {
    uint32_t4x2 const y = *(reinterpret_cast < uint32_t4x2* > (&xx));
    uint32_t4x2 _____ z;
    z.x = __SHFL_xor ( y.x, laneMask, width );
    z.y = __SHFL_xor ( y.y, laneMask, width );
    xx = *(reinterpret_cast < TYPE* > (&z));
  }
  return xx;
#    undef SHFL_XOR
}


// In return, if flag is true, x and y are swapped
//  int flag : flag whether swap the arguments
//  TYPE x,y : regsiters
template < class TYPE >
__forceinline__ __device__  void
Swap_Elements ( TYPE &x, TYPE &y, bool const flag )
{
  TYPE const z = x;
  TYPE const w = y;
  x = __choose__ ( flag, w, z );
  y = __choose__ ( flag, z, w );
}

// In return, warp-oriented sumup are stored on x0 of the first warp
// Hidden / un-passed/ implicit parameters
//  TYPE x0  : variable to be sumed up
//  TYPE w[] : work area on shared_memory : blockDim.x-32 or more
//  int  c = local_id / 32; : the warp number
template < class TYPE, int BLOCK_SIZE >
__forceinline__ __device__ void
_sumup_inter_Warp( int const w_offset, TYPE &x, int const threadIdx_x )
{
  if ( BLOCK_SIZE <= 32 ) return;
  SHMEM_addr_t _____ shmem_w = shared_memory_raw_proxy < TYPE > ( w_offset );
  bool         const flag    = ( threadIdx_x < 32 );
  __syncthreads ( );
  TYPE x_ = x;
  if ( !flag ) {
    Store_Shared( shmem_w, x_ );
  }
  __syncthreads ( );
  if ( flag ) {
    SHMEM_addr_t const step    = 32*sizeof(TYPE);
#pragma unroll
    for(int i=1; i<BLOCK_SIZE/32; i++) {
      x_ += Load_Shared < TYPE > ( shmem_w + i*step);
    }
    x = x_;
  }
}

// In return, x@mine += x@(mine^(1<<lane))
//  TYPE x   : regsiters to be summed up
//  int lane : lane , a distance of the registers sumed up
template < class TYPE >
__forceinline__ __device__ void
ADD_Default( TYPE &a, int const lane )
{
  TYPE a_ = a;
  a_ += __SHFL_xor ( a_,  lane, 32 );
  a = a_;
}


#define ADD_WithSwap( a, b, lane )	_ADD_WithSwap( a, b, lane, threadIdx_x )
#define ADD_WithSwap1( a, b, lane )	_ADD_WithSwap1( a, b, lane,threadIdx_x )
#define ADD_WithSwap2( a, b, lane )	_ADD_WithSwap2( a, b, lane,threadIdx_x )
#define ADD_WithSwap3( a, b, lane )	_ADD_WithSwap3( a, b, lane,threadIdx_x )

template < class TYPE >
__forceinline__ __device__ void
_ADD_WithSwap1( TYPE &a, TYPE &b, int const lane, int const threadIdx_x )
{
  TYPE a_ = a, b_ = b;
  bool const flag = ( threadIdx_x & lane );
  Swap_Elements( a_, b_, flag );
  a = a_; b = b_;
}

template < class TYPE >
__forceinline__ __device__ void
_ADD_WithSwap2( TYPE &a, TYPE &b, int const lane, int const threadIdx_x )
{
  TYPE b_ = b;
  b_ = __SHFL_xor ( b_,  lane, 32 );
  b = b_;
}

template < class TYPE >
__forceinline__ __device__ void
_ADD_WithSwap3( TYPE &a, TYPE &b, int const lane, int const threadIdx_x )
{
  TYPE a_ = a, b_ = b;
  a_ += b_;
  a = a_;
}

// In return, x@{mine,(mine^(1<<lane))} += y@{(mine^(1<<lane)),mine}
//  TYPE x,y : regsiters to be summed up
//  int lane : lane , a distance of butterfly swaps
template < class TYPE >
__forceinline__ __device__ void
_ADD_WithSwap( TYPE &a, TYPE &b, int const lane, int const threadIdx_x )
{
  TYPE a_ = a, b_ = b;
  _ADD_WithSwap1( a_, b_, lane, threadIdx_x );
  _ADD_WithSwap2( a_, b_, lane, threadIdx_x );
  _ADD_WithSwap3( a_, b_, lane, threadIdx_x );
  a = a_; b = b_;
}


#    if __isHALF__
#      define	HALFv2		half2
#      define	__HALFv2	__halfrealv2__
#    endif
#    if __isINT16__
#      define	HALFv2		int16v2
#      define	__HALFv2	__int16v2__t_
#    endif

#    if __isHALF__ || __isINT16__
template < class TYPE >
__forceinline__ __device__ void
Half2_Swap( TYPE &a, TYPE &b )
{
#      if 1
  uint32_t u = *(reinterpret_cast < uint32_t* > (&(a)));
  uint32_t v = *(reinterpret_cast < uint32_t* > (&(b)));
  uint32_t w = __funnelshift_lc( u, u, 16 ); // [ax,ay] --> [ay,ax]
  w = __funnelshift_lc( w, v, 16 ); // [ay,ax][bx,by] --> [ax,bx]
  v = __funnelshift_lc( v, v, 16 ); // [bx,by] --> [by,bx]
  u = __funnelshift_lc( u, v, 16 ); // [ax,ay][by,bx] --> [ay,by]
  a = *(reinterpret_cast < TYPE* > (&(w)));
  b = *(reinterpret_cast < TYPE* > (&(u)));
#      else
  uint32_t16_t2 *u = (reinterpret_cast < uint32_t16_t2* > (&(a)));
  uint32_t16_t2 *v = (reinterpret_cast < uint32_t16_t2* > (&(b)));
  uint32_t16_t const t = u->y; u->y = v->x; v->x = t;
  a = *(reinterpret_cast < TYPE* > (u));
  b = *(reinterpret_cast < TYPE* > (v));
#      endif
}
#    endif



template < class TYPE, int BLOCK_SIZE >
__device__ TYPE
reduce_in_block_non_power2 (
                            TYPE x0,
                            int const threadIdx_x,
                            int const w_offset, int const z_offset )
{
  SHMEM_addr_t _____ shmem_w = shared_memory_raw_proxy < TYPE > ( w_offset );

  __syncthreads();
  if ( threadIdx_x >= 1 ) {
    Store_Shared ( shmem_w, x0 );
  }
  __syncthreads();

  if ( threadIdx_x < 1 ) {
    int          const step    = (int)sizeof(TYPE);
#pragma unroll
    for(int i=1; i<BLOCK_SIZE; i++) {
      x0 += Load_Shared < TYPE > ( shmem_w + i*step);
    }

    if ( z_offset >= 0 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
  return x0;
}

template < class TYPE, int BLOCK_SIZE >
__device__ TYPE
reduce_in_block_power2_multiple32 (
                                   TYPE x0,
                                   int const threadIdx_x,
                                   int const w_offset,    int const z_offset )
{
  if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

  if ( BLOCK_SIZE > 32 ) {
    _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
  }

  if ( threadIdx_x < 32 ) {
    ADD_Default( x0, 1  );
    ADD_Default( x0, 2  );
    ADD_Default( x0, 4  );
    if ( BLOCK_SIZE > 8 ) {
      ADD_Default( x0, 8  );
      if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
    }
  }

  if ( z_offset >= 0 && threadIdx_x < 1 ) {
    reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
  }
  return x0;
}

template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ TYPE
//__noinline__ __device__ TYPE
reduce_in_block (
                 TYPE x0,
                 int3 const ss )
{
  int3 const tt = ss;
  int  const threadIdx_x = tt.x;
  int  const w_offset    = tt.y;
  int  const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    x0 = reduce_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                     x0, threadIdx_x, w_offset, z_offset );
  } else {
    x0 = reduce_in_block_power2_multiple32 < TYPE, BLOCK_SIZE > (
                                            x0, threadIdx_x, w_offset, z_offset );
  }
  return x0;
}

template < class TYPE, int BLOCK_SIZE >
__device__ void
reduce2_in_block_non_power2 (
                             TYPE x0, TYPE x1,
                             int const threadIdx_x,
                             int const w_offset, int const z_offset )
{
  SHMEM_addr_t _____ shmem_w = shared_memory_raw_proxy < TYPE > ( w_offset );

  __syncthreads();
  {
    bool         const flag    = (threadIdx_x & 0x1);
    Swap_Elements ( x0, x1, flag );
    int          const step    = (int)sizeof(TYPE);
    SHMEM_addr_t const shmem_d = shmem_w + (flag ? - step : + step);
    Store_Shared ( shmem_d, x1 );
    __syncthreads();
    x0 += Load_Shared < TYPE > ( shmem_w );
  }
  __syncthreads();

  if ( threadIdx_x >= 2 ) {
    Store_Shared ( shmem_w, x0 );
  }
  __syncthreads();

  if ( threadIdx_x < 2 ) {
    int          const step    = (int)sizeof(TYPE)*2;
#pragma unroll
    for(int i=1; i<BLOCK_SIZE/2; i++) {
      x0 += Load_Shared < TYPE > ( shmem_w + i*step);
    }

    reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
  }
}

template < class TYPE, int BLOCK_SIZE >
__device__ void
reduce2_in_block_power2_multiple32 (
                                    TYPE x0, TYPE x1,
                                    int const threadIdx_x,
                                    int const w_offset,    int const z_offset )
{
  if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

  {
    ADD_WithSwap( x0, x1, 1 );
  }

  if ( BLOCK_SIZE > 32 ) {
    _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
  }

  if ( threadIdx_x < 32 ) {
    ADD_Default( x0, 2  );
    ADD_Default( x0, 4  );
    if ( BLOCK_SIZE > 8 ) {
      ADD_Default( x0, 8  );
      if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
    }
  }

  if ( threadIdx_x < 2 ) {
    reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
  }
}

template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce2_in_block (
                  TYPE x0, TYPE x1,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce2_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, threadIdx_x, w_offset, z_offset+0 );
  } else {
    reduce2_in_block_power2_multiple32 < TYPE, BLOCK_SIZE > (
                                        x0, x1, threadIdx_x, w_offset, z_offset+0 );
  }

}


template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce3_in_block (
                  TYPE x0, TYPE x1, TYPE x2,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce2_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, threadIdx_x, w_offset, z_offset+0 );
    reduce_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                x2, threadIdx_x, w_offset, z_offset+2 );
  } else {

    if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

    {
      ADD_WithSwap( x0, x1, 1 );
      ADD_Default ( x2,  1 );

      ADD_WithSwap( x0, x2, 2 );
    }

    if ( BLOCK_SIZE > 32 ) {
      _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
    }

    if ( threadIdx_x < 32 ) {
      ADD_Default( x0, 4  );
      if ( BLOCK_SIZE > 8 ) {
        ADD_Default( x0, 8  );
        if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
      }
    }

    if ( threadIdx_x < 3 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
}


template < class TYPE, int BLOCK_SIZE >
__device__ void
reduce4_in_block_non_power2 (
                             TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                             int const threadIdx_x,
                             int const w_offset, int const z_offset )
{
  SHMEM_addr_t _____ shmem_w = shared_memory_raw_proxy < TYPE > ( w_offset );

  __syncthreads();
  {
    bool         const flag    = (threadIdx_x & 0x1);
    int          const step    = (int)sizeof(TYPE);
    SHMEM_addr_t const shmem_d = shmem_w + (flag ? - step : + step);
    Swap_Elements ( x0, x1, flag );
    Store_Shared ( shmem_d, x1 );
    __syncthreads();
    x0 += Load_Shared < TYPE > ( shmem_w );
    __syncthreads();
    Swap_Elements ( x2, x3, flag );
    Store_Shared ( shmem_d, x3 );
    __syncthreads();
    x2 += Load_Shared < TYPE > ( shmem_w );
  }
  __syncthreads();

  {
    bool         const flag    = (threadIdx_x & 0x2);
    int          const step    = (int)sizeof(TYPE)*2;
    SHMEM_addr_t const shmem_d = shmem_w + (flag ? - step : + step);
    Swap_Elements ( x0, x2, flag );
    Store_Shared ( shmem_d, x2 );
    __syncthreads();
    x0 += Load_Shared < TYPE > ( shmem_w );
  }
  __syncthreads();


  if ( threadIdx_x >= 4 ) {
    Store_Shared ( shmem_w, x0 );
  }
  __syncthreads();

  if ( threadIdx_x < 4 ) {
    int          const step    = (int)sizeof(TYPE)*4;
#pragma unroll
    for(int i=1; i<BLOCK_SIZE/4; i++) {
      x0 += Load_Shared < TYPE > ( shmem_w + i*step);
    }

    reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
  }
}


template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce4_in_block (
                  TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce4_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, x2, x3, threadIdx_x, w_offset, z_offset+0 );
  } else {

    if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

    {
#    if __isHALF__ || __isINT16__
      HALFv2 y0 = __HALFv2( x0, x2 );
      HALFv2 y1 = __HALFv2( x1, x3 );
      ADD_WithSwap ( y0, y1, 1 );
      x0 = y0.x; x2 = y0.y;
#    else
      ADD_WithSwap ( x0, x1, 1 );
      ADD_WithSwap ( x2, x3, 1 );
#    endif
      ADD_WithSwap ( x0, x2, 2 );
    }

    if ( BLOCK_SIZE > 32 ) {
      _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
    }

    if ( threadIdx_x < 32 ) {
      ADD_Default( x0, 4  );
      if ( BLOCK_SIZE > 8 ) {
        ADD_Default( x0, 8  );
        if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
      }
    }

    if ( threadIdx_x < 4 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
}

template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce5_in_block (
                  TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                  TYPE x4,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce4_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, x2, x3, threadIdx_x, w_offset, z_offset+0 );
    reduce_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                x4, threadIdx_x, w_offset, z_offset+4 );
  } else {

    if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

    {
#    if __isHALF__ || __isINT16__
      HALFv2 y0 = __HALFv2( x0, x2 );
      HALFv2 y1 = __HALFv2( x1, x3 );
      ADD_WithSwap ( y0, y1, 1 );
      x0 = y0.x; x2 = y0.y;
#    else
      ADD_WithSwap ( x0, x1, 1 );
      ADD_WithSwap ( x2, x3, 1 );
#    endif
      ADD_Default  ( x4,  1 );

      ADD_WithSwap ( x0, x2, 2 );
      ADD_Default  ( x4,  2 );

      ADD_WithSwap ( x0, x4, 4 );
    }

    if ( BLOCK_SIZE > 32 ) {
      _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
    }

    if ( threadIdx_x < 32 ) {
      if ( BLOCK_SIZE > 8 ) {
        ADD_Default( x0, 8  );
        if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
      }
    }

    if ( threadIdx_x < 5 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
}

template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce6_in_block (
                  TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                  TYPE x4, TYPE x5,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce4_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, x2, x3, threadIdx_x, w_offset, z_offset+0 );
    reduce2_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x4, x5, threadIdx_x, w_offset, z_offset+4 );
  } else {

    if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

    {
#    if __isHALF__ || __isINT16__
      HALFv2 y0 = __HALFv2( x0, x2 );
      HALFv2 y1 = __HALFv2( x1, x3 );
      ADD_WithSwap ( y0, y1, 1 );
      ADD_WithSwap ( x4, x5, 1 );
      x0 = y0.x; x2 = y0.y;
#    else
      ADD_WithSwap ( x0, x1, 1 );
      ADD_WithSwap ( x2, x3, 1 );
      ADD_WithSwap ( x4, x5, 1 );
#    endif
      ADD_WithSwap ( x0, x2, 2 );
      ADD_Default  ( x4, 2 );

      ADD_WithSwap ( x0, x4, 4 );
    }

    if ( BLOCK_SIZE > 32 ) {
      _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
    }

    if ( threadIdx_x < 32 ) {
      if ( BLOCK_SIZE > 8 ) {
        ADD_Default( x0, 8  );
        if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
      }
    }

    if ( threadIdx_x < 6 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
}

template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce7_in_block (
                  TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                  TYPE x4, TYPE x5, TYPE x6,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce4_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, x2, x3, threadIdx_x, w_offset, z_offset+0 );
    reduce2_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x4, x5, threadIdx_x, w_offset, z_offset+4 );
    reduce_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                x6, threadIdx_x, w_offset, z_offset+6 );
  } else {

    if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

    {
#    if __isHALF__ || __isINT16__
      HALFv2 y0 = __HALFv2( x0, x2 );
      HALFv2 y1 = __HALFv2( x1, x3 );
      ADD_WithSwap ( y0, y1, 1 );
      ADD_WithSwap ( x4, x5, 1 );
      ADD_Default  ( x6, 1 );

      Half2_Swap( y0, y1 );
      ADD_WithSwap ( y0, y1, 2 );
      x0 = y0.x; x4 = y0.y;
#    else
      ADD_WithSwap ( x0, x1, 1 );
      ADD_WithSwap ( x2, x3, 1 );
      ADD_WithSwap ( x0, x2, 2 );

      ADD_WithSwap ( x4, x5, 1 );
      ADD_Default  ( x6, 1 );
      ADD_WithSwap ( x4, x6, 2 );
#    endif
      ADD_WithSwap ( x0, x4, 4 );
    }

    if ( BLOCK_SIZE > 32 ) {
      _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
    }

    if ( threadIdx_x < 32 ) {
      if ( BLOCK_SIZE > 8 ) {
        ADD_Default( x0, 8  );
        if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
      }
    }

    if ( threadIdx_x < 7 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
}


template < class TYPE, int BLOCK_SIZE >
__device__ void
reduce8_in_block_non_power2 (
                             TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                             TYPE x4, TYPE x5, TYPE x6, TYPE x7,
                             int const threadIdx_x,
                             int const w_offset, int const z_offset )
{
  SHMEM_addr_t _____ shmem_w = shared_memory_raw_proxy < TYPE > ( w_offset );

  __syncthreads();
  {
    bool         const flag    = (threadIdx_x & 0x1);
    int          const step    = (int)sizeof(TYPE);
    SHMEM_addr_t const shmem_d = shmem_w + (flag ? - step : + step);
    Swap_Elements ( x0, x1, flag );
    Store_Shared ( shmem_d, x1 );
    __syncthreads();
    x0 += Load_Shared < TYPE > ( shmem_w );
    __syncthreads();
    Swap_Elements ( x2, x3, flag );
    Store_Shared ( shmem_d, x3 );
    __syncthreads();
    x2 += Load_Shared < TYPE > ( shmem_w );
    __syncthreads();
    Swap_Elements ( x4, x5, flag );
    Store_Shared ( shmem_d, x5 );
    __syncthreads();
    x4 += Load_Shared < TYPE > ( shmem_w );
    __syncthreads();
    Swap_Elements ( x6, x7, flag );
    Store_Shared ( shmem_d, x7 );
    __syncthreads();
    x6 += Load_Shared < TYPE > ( shmem_w );
  }
  __syncthreads();

  {
    bool         const flag    = (threadIdx_x & 0x2);
    int          const step    = (int)sizeof(TYPE)*2;
    SHMEM_addr_t const shmem_d = shmem_w + (flag ? - step : + step);
    Swap_Elements ( x0, x2, flag );
    Store_Shared ( shmem_d, x2 );
    __syncthreads();
    x0 += Load_Shared < TYPE > ( shmem_w );
    __syncthreads();
    Swap_Elements ( x4, x6, flag );
    Store_Shared ( shmem_d, x6 );
    __syncthreads();
    x4 += Load_Shared < TYPE > ( shmem_w );
  }
  __syncthreads();

  {
    bool         const flag    = (threadIdx_x & 0x4);
    Swap_Elements ( x0, x4, flag );
    int          const step    = (int)sizeof(TYPE)*4;
    SHMEM_addr_t const shmem_d = shmem_w + (flag ? - step : + step);
    Store_Shared ( shmem_d, x4 );
    __syncthreads();
    x0 += Load_Shared < TYPE > ( shmem_w );
  }
  __syncthreads();


  if ( threadIdx_x >= 8 ) {
    Store_Shared ( shmem_w, x0 );
  }
  __syncthreads();

  if ( threadIdx_x < 8 ) {
    int          const step    = (int)sizeof(TYPE)*8;
#pragma unroll
    for(int i=1; i<BLOCK_SIZE/8; i++) {
      x0 += Load_Shared < TYPE > ( shmem_w + i*step);
    }

    reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
  }
}

template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce8_in_block (
                  TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                  TYPE x4, TYPE x5, TYPE x6, TYPE x7,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce8_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, x2, x3, x4, x5, x6, x7,
                                 threadIdx_x, w_offset, z_offset+0 );
  } else {

    if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

    {
#    if __isHALF__ || __isINT16__
      HALFv2 y0 = __HALFv2( x0, x2 );
      HALFv2 y1 = __HALFv2( x1, x3 );
      HALFv2 y2 = __HALFv2( x4, x6 );
      HALFv2 y3 = __HALFv2( x5, x7 );
      ADD_WithSwap ( y0, y1, 1 );
      ADD_WithSwap ( y2, y3, 1 );

      Half2_Swap( y0, y2 );
      ADD_WithSwap ( y0, y2, 2 );
      x0 = y0.x; x4 = y0.y;
#    else
      ADD_WithSwap ( x0, x1, 1 );
      ADD_WithSwap ( x2, x3, 1 );
      ADD_WithSwap ( x0, x2, 2 );

      ADD_WithSwap ( x4, x5, 1 );
      ADD_WithSwap ( x6, x7, 1 );
      ADD_WithSwap ( x4, x6, 2 );
#    endif
      ADD_WithSwap ( x0, x4, 4 );
    }

    if ( BLOCK_SIZE > 32 ) {
      _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
    }

    if ( threadIdx_x < 32 ) {
      if ( BLOCK_SIZE > 8 ) {
        ADD_Default( x0, 8  );
        if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
      }
    }

    if ( threadIdx_x < 8 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
}

template < class TYPE, int BLOCK_SIZE >
__INLINE__ __device__ void
reduce9_in_block (
                  TYPE x0, TYPE x1, TYPE x2, TYPE x3,
                  TYPE x4, TYPE x5, TYPE x6, TYPE x7,
                  TYPE x8,
                  int3 const tt )
{
  int const threadIdx_x = tt.x;
  int const w_offset    = tt.y;
  int const z_offset    = tt.z;

  if (  __popc(BLOCK_SIZE) > 1 && (BLOCK_SIZE % 32) ) {
    reduce8_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                 x0, x1, x2, x3, x4, x5, x6, x7,
                                 threadIdx_x, w_offset, z_offset+0 );
    reduce_in_block_non_power2 < TYPE, BLOCK_SIZE > (
                                x8, threadIdx_x, w_offset, z_offset+8 );
  } else {

    if ( BLOCK_SIZE > 32 ) { __syncthreads ( ); }

    {
#    if __isHALF__ || __isINT16__
      HALFv2 y0 = __HALFv2( x0, x2 );
      HALFv2 y1 = __HALFv2( x1, x3 );
      HALFv2 y2 = __HALFv2( x4, x6 );
      HALFv2 y3 = __HALFv2( x5, x7 );
      ADD_WithSwap ( y0, y1, 1 );
      ADD_WithSwap ( y2, y3, 1 );
      ADD_Default  ( x8,  1 );

      Half2_Swap( y0, y2 );
      ADD_WithSwap ( y0, y2, 2 );
      ADD_Default  ( x8,  2 );
      x0 = y0.x; x4 = y0.y;
#    else
      ADD_WithSwap ( x0, x1, 1 );
      ADD_WithSwap ( x2, x3, 1 );
      ADD_WithSwap ( x4, x5, 1 );
      ADD_WithSwap3( x6, x7, 1 );
      ADD_Default  ( x8,  1 );

      ADD_WithSwap ( x0, x2, 2 );
      ADD_WithSwap ( x4, x6, 2 );
      ADD_Default  ( x8,  2 );
#    endif
      ADD_WithSwap ( x0, x4, 4 );
      ADD_Default  ( x8,  4 );

      ADD_WithSwap ( x0, x8, 8 );
    }

    if ( BLOCK_SIZE > 32 ) {
      _sumup_inter_Warp < TYPE, BLOCK_SIZE > ( w_offset, x0, threadIdx_x );
    }

    if ( threadIdx_x < 32 ) {
      if ( BLOCK_SIZE > 16 ) ADD_Default( x0, 16 );
    }

    if ( threadIdx_x < 9 ) {
      reinterpret_cast < TYPE* > (__shmem)[z_offset] = x0;
    }
  }
}

//=============================================================================

#  endif


