#pragma once

//=============================================================================
//
// TB_control_t defines a control handler variables
//

typedef struct {
  int  id_master;
  int  counter;
} TB_control_t;

//=============================================================================

static int constexpr TB_FULL = 0xffffffff;
static int constexpr TB_DONE = TB_FULL-1;
static int constexpr TB_LOCK = 0x80000000;
static int constexpr TB_OKAY = 0x00000000;
static long constexpr TB_FULL64 = 0xffffffffffffffff;
static long constexpr TB_OKAY64 = 0x0000000000000000;

//=============================================================================

static __forceinline__ __host__ void
__init_ThreadBlocks__ ( TB_control_t * TB_device, int const n, cudaStream_t const stream )
{
  const char FULL = (char)0xff;
  cudaMemsetAsync( TB_device, FULL, sizeof(TB_control_t)*n, stream );
}

// --

static __forceinline__ __device__ int
__read_TB_pointer ( TB_control_t * TB_root )
{
  extern __shared__ int __shmem[];
  int * const comm = __shmem;
  __syncthreads ( );
  bool const mask = ( threadIdx.x == 0 );
  if ( mask ) {
#if USE_STRONG_CONTROL_ORDER
    *comm = atomicLoad_STRONG ( &TB_root->id_master );
#else
    *comm = atomicLoad        ( &TB_root->id_master );
#endif
  }
  __syncthreads ( );
  const int pointer = *comm;
  __syncthreads ( );
  return pointer;
}

// --

static __forceinline__ __device__ void
__start_ThreadBlocks__ ( TB_control_t * TB_root, TB_control_t * TB_ptr, int const TB_id ) 
{
  bool const mask = ( threadIdx.x == 0 );
  __syncthreads ( );
  if ( mask ) {
#if USE_STRONG_CONTROL_ORDER
    if ( TB_id == atomicLoad_STRONG ( &TB_root->id_master ) ) {
      if ( TB_FULL ==
        atomicCAS_STRONG  ( &TB_ptr->id_master, TB_FULL, TB_LOCK ) ) {
        atomicExch_STRONG ( (long *)&TB_ptr->id_master, TB_OKAY64 );
      }
    }
#else
    if ( TB_id == atomicLoad ( &TB_root->id_master ) ) {
      if ( TB_FULL ==
        atomicCAS         ( &TB_ptr->id_master, TB_FULL, TB_LOCK ) ) {
        atomicExch        ( (long *)&TB_ptr->id_master, TB_OKAY64 );
      }
    }
#endif
  }
  __syncthreads ( ); __threadfence_system ( ); __syncthreads ( );
}

static __forceinline__ __device__ int
__get_block_id__ ( TB_control_t * TB_ptr, int const N_max )
{
  extern __shared__ int __shmem[];
  int * const comm = __shmem;
  __syncthreads ( );
  bool const mask = ( threadIdx.x == 0 );
  if ( mask ) {
    int a_ret = TB_DONE;
    while ( true ) {
#if USE_STRONG_CONTROL_ORDER
      int const a_orig = atomicLoad_STRONG ( &TB_ptr->id_master );
#else
      int const a_orig = atomicLoad        ( &TB_ptr->id_master );
#endif
      if ( a_orig < TB_OKAY ) {
        break;
      }
      int a_next = a_orig + 1;
      a_next  = ( a_next > TB_OKAY && a_next < N_max ) ? a_next : TB_DONE;
#if USE_STRONG_CONTROL_ORDER
      if ( a_orig == atomicCAS_STRONG ( &TB_ptr->id_master, a_orig, a_next ) )
#else
      if ( a_orig == atomicCAS        ( &TB_ptr->id_master, a_orig, a_next ) )
#endif
      {
        a_ret = a_orig; break;
      }
    }
    *comm = a_ret;
  }
  __syncthreads ( );
  const int block_id = *comm;
  __syncthreads ( );
  return block_id;
}

static __forceinline__ __device__ void
__checkpoint_ThreadBlocks__ ( int const next_pointer, TB_control_t * TB_root, TB_control_t * TB_ptr, int const min_MPs )
{
  bool const mask = ( threadIdx.x == 0 );
  if ( mask ) {
#if USE_STRONG_CONTROL_ORDER
    if ( atomicAdd_STRONG ( &TB_ptr->counter, 1 ) == (min_MPs-1) ) {
      atomicExch_STRONG ( &TB_root->id_master, next_pointer );
      atomicExch_STRONG ( (long *)&TB_ptr->id_master, TB_FULL64 );
    }
#else
    if ( atomicAdd ( &TB_ptr->counter, 1 ) == (min_MPs-1) ) {
      atomicExch ( &TB_root->id_master, next_pointer );
      atomicExch ( (long *)&TB_ptr->id_master, TB_FULL64 );
    }
#endif
  }
  __syncthreads ( );
}

static __forceinline__ __device__ void
__weaksync_ThreadBlocks__ ( const int current_pointer, TB_control_t * TB_root, TB_control_t * TB_ptr )
{
  bool const mask = ( threadIdx.x == 0 );
  if ( mask ) {
    while ( true ) {
#if USE_STRONG_CONTROL_ORDER
      if ( atomicLoad_STRONG ( &TB_root->id_master ) != current_pointer ) break;
      if ( atomicLoad_STRONG ( (long *)&TB_ptr->id_master ) == TB_FULL64 ) break;
#else
      if ( atomicLoad ( &TB_root->id_master ) != current_pointer ) break;
      if ( atomicLoad ( (long *)&TB_ptr->id_master ) == TB_FULL64 ) break;
#endif
    }
  }
  __syncthreads ( );
}

//=============================================================================

#define TASK_SKIP(TB_root, TB_device, TB_id, next_TB_id) \
	do { \
          if ( threadIdx.x == 0 ) { \
            if (  USE_STRONG_CONTROL_ORDER ) \
            atomicCAS_STRONG ( &TB_root->id_master, (TB_id), (next_TB_id) ); \
            if ( !USE_STRONG_CONTROL_ORDER ) \
            atomicCAS        ( &TB_root->id_master, (TB_id), (next_TB_id) ); \
          } \
          __syncthreads ( ); \
	} while ( false )

#define TASK_LOOP(TB_root, TB_device, TB_id, N_max, global_id) \
	do { \
		TB_control_t * const __root__ = TB_root; \
		TB_control_t * const __ptr__ = TB_device + (TB_id); \
		int const N_MAX = (N_max); \
		int const ID = (TB_id); \
		__start_ThreadBlocks__ ( __root__, __ptr__, ID ); \
	    while ( global_id = __get_block_id__( __ptr__, N_MAX ), \
		( global_id >= 0 && global_id < N_MAX ) ) do {

#define TASK_WAIT(next_TB_id) \
	    } while ( \
		__checkpoint_ThreadBlocks__ ( (next_TB_id), __root__, __ptr__, N_MAX ), \
		false ); \
	    __weaksync_ThreadBlocks__ ( ID, __root__, __ptr__ ); \
	} while ( false )

//=============================================================================


