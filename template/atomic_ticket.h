#pragma once

//=============================================================================

#  include "aspen_atomic.h"

//=============================================================================

template < typename Tt >
__forceinline__ __device__ void
get_Ticket ( Tt * Ticket, Tt const block_id )
{
  if ( threadIdx.x == 0 ) {
    Tt const next_block_id = (Tt)(-1);
    while ( 1 ) {
      __nanosleep__( 32 );
#if USE_STRONG_TICKET_ORDER
      Tt const response = atomicCAS_STRONG ( Ticket, block_id, next_block_id );
#else
      Tt const response = atomicCAS        ( Ticket, block_id, next_block_id );
#endif
      if ( response == block_id ) break;
    }
  }
  __syncthreads ( );
}

template < typename Tt >
__forceinline__ __device__ void
release_Ticket ( Tt * Ticket, Tt const next_block_id )
{
//
// **CAUTION**
// releasing the ticket has an immediate return that would be failed in
// an unexpected completion of the background atomic operation.
// Thus, THIS MUST BE STRONG ORDER, which can guarantee the operation.
//
#if !USE_ATOMIC && !USE_STRONG_ATOM_ORDER && !USE_STRONG_LDST_ORDER && !USE_CONFIRM_LDST
  __syncthreads ( );
  __threadfence ( );
#endif
  __syncthreads ( );
  if ( threadIdx.x == 0 ) {
#if USE_STRICT_TICKET_CHECK
    Tt const block_id = (Tt)(-1);
//#if USE_STRONG_TICKET_ORDER
    atomicCAS_STRONG ( Ticket, block_id, next_block_id );
//#else
//    atomicCAS        ( Ticket, block_id, next_block_id );
//#endif
#else
    asm volatile ( "red.release.and.b32\t[%0], %1;" : :
			"l"(Ticket), "r"(next_block_id) );
#endif
  }
  __syncthreads ( );
}

//=============================================================================


