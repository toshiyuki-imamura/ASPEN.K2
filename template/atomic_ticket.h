#pragma once

//=============================================================================

#  include "aspen_atomic.h"

//=============================================================================

  template < bool strong_order = true, int timer_count = 32 >
  __forceinline__ __device__ static void
  get_Ticket ( int * const Ticket, int const block_id )
  {
    static_assert( strong_order == true );
    bool flag = ( threadIdx.x != 0 );
    while ( !flag ) {
      __nanosleep__( timer_count );
      flag = ( block_id == Load_Acquire_Global ( Ticket ) );
    }
    __nanosleep__( timer_count );
    __syncthreads();
  }

  template < bool strong_order = false, int timer_count = 32 >
  __forceinline__ __device__ static void
  release_Ticket ( int * const Ticket, int const block_id, int const next_block_id )
  {
    __syncthreads();
    if ( threadIdx.x == 0 ) {
      if constexpr ( strong_order ) {
        atomicCAS_STRONG ( Ticket, block_id, next_block_id );
      } else {
        atomicCAS ( Ticket, block_id, next_block_id );
      }
    }
    __nanosleep__( timer_count );
    __syncthreads();
  }

//=============================================================================


