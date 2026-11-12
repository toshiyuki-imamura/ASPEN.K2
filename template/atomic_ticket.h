#pragma once

//=============================================================================

#  include "aspen_atomic.h"

//=============================================================================

  template < int timer_count = 32 >
  __forceinline__ __device__ static void
  get_Ticket ( int * const Ticket, int const block_id )
  {
    bool flag = ( threadIdx.x != 0 );
    while ( !flag ) {
      __nanosleep__( timer_count );
      flag = ( block_id == Load_Acquire_Global ( Ticket ) );
    }
    __nanosleep__( timer_count );
    __syncthreads();
  }

  template < int timer_count = 32 >
  __forceinline__ __device__ static void
  release_Ticket ( int * const Ticket, int const block_id, int const next_block_id )
  {
    __syncthreads();
    if ( threadIdx.x == 0 ) {
      atomicCAS_STRONG ( Ticket, block_id, next_block_id );
    }
    __nanosleep__( timer_count );
    __syncthreads();
  }

//=============================================================================


