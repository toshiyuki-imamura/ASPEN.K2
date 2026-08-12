#ifndef ASPEN_GPU_CONF_H_INCLUDED
#  define ASPEN_GPU_CONF_H_INCLUDED	1

#  if defined(GPU_ARCH)

#    if GPU_ARCH == Tesla || GPU_ARCH == Fermi || GPU_ARCH == Kepler || GPU_ARCH == Kepler2 || GPU_ARCH == Kepler3 || GPU_ARCH == Maxwell
/*
 * obsolated architectures. not supported
 */
#      error
error
#      error
error
#      error
#    endif

#    if GPU_ARCH == Tesla
// 130
// Tesla, GT2xx
#      define	GPU_PREFIX		TESLA
#      define	MAX_THREAD_BLOCKS       (8)
#      define	MAX_REGS_PER_BLOCK	(32768)
#      define	MAX_WARP_PER_MP		(32)
#      define	MAX_LDST_PER_MP		(2)
#      define	SHMEM_CAPACITY_KB	(16)
#      define	SHMEM_wo_OPTIN_KB	(16)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(1)
#      define	WARP_ALLOC_UNIT		(2)
#      define	FENCE(...)		__LOOP_DIVIDER__()
#      define	FENCE_BLOCK(...)	__LOOP_DIVIDER__()
#      define	FENCE_SYSTEM(...)	__LOOP_DIVIDER__()
#    endif

#    if GPU_ARCH == Fermi
// 200
// Fermi
#      define	GPU_PREFIX		FERMI
#      define	MAX_THREAD_BLOCKS       (8)
#      define	MAX_REGS_PER_BLOCK	(32768)
#      define	MAX_WARP_PER_MP		(48)
#      define	MAX_LDST_PER_MP		(16)
#      define	SHMEM_CAPACITY_KB	(48)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(32)
#      define	REGIS_UNIT_SIZE		(128)
#      define	WARP_ALLOC_UNIT		(2)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Kepler
// 300
// Kepler
#      define	GPU_PREFIX		KEPLER
#      define	MAX_THREAD_BLOCKS       (16)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(48)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Kepler2
// 350
// Kepler
#      define	GPU_PREFIX		KEPLER2
#      define	MAX_THREAD_BLOCKS       (16)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(48)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Kepler3
// 370
// Kepler
#      define	GPU_PREFIX		KEPLER3
#      define	MAX_THREAD_BLOCKS       (16)
#      define	MAX_REGS_PER_BLOCK	(65536*2)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(112)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Maxwell
// 500
// Maxwell (GM107, GM108)
#      define	GPU_PREFIX		MAXWELL
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(96)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Maxwell2
// 520
// Maxwell2 (GM200, GM204, GM206)
#      define	GPU_PREFIX		MAXWELL2
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(96)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Maxwell3
// 530
// Maxwell3 (GM20B)
#      define	GPU_PREFIX		MAXWELL3
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(64)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Pascal
// 600
// Pascal (GP100)
#      define	GPU_PREFIX		PASCAL
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(16)
#      define	SHMEM_CAPACITY_KB	(64)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Pascal1
// 610
// Pascal1 (GP102, GP104, GP106, GP107, GP108)
#      define	GPU_PREFIX		PASCAL1
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(96)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Pascal2
// 620
// Pascal2 (GP10B) Tegra X2, etc
#      define	GPU_PREFIX		PASCAL2
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(64)
#      define	SHMEM_wo_OPTIN_KB	(48)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Volta
// 700
// Volta (GV100)
#      define	GPU_PREFIX		VOLTA
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(96)
#      define	SHMEM_wo_OPTIN_KB	(96)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Turing
// 750
// Turing (TU102, TU104, TU106, TU116, TU117)
#      define	GPU_PREFIX		TURING
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(32)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(96)
#      define	SHMEM_wo_OPTIN_KB	(64)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Ampere
// 800
// Ampere (GA100)
#      define	GPU_PREFIX		AMPERE
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(16)
#      define	SHMEM_CAPACITY_KB	(164)
#      define	SHMEM_wo_OPTIN_KB	(164)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Ampere2
// 860
// Ampere2 (GA102, GA103, GA104, GA106, GA107)
#      define	GPU_PREFIX		AMPERE2
#      define	MAX_THREAD_BLOCKS       (16)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(48)
#      define	MAX_LDST_PER_MP		(16)
#      define	SHMEM_CAPACITY_KB	(100)
#      define	SHMEM_wo_OPTIN_KB	(100)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Ampere3
// 870
// Ampere3 (GA10B) Jetson, etc
#      define	GPU_PREFIX		AMPERE3
#      define	MAX_THREAD_BLOCKS       (16)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(48)
#      define	MAX_LDST_PER_MP		(16)
#      define	SHMEM_CAPACITY_KB	(100)
#      define	SHMEM_wo_OPTIN_KB	(100)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Ada
// 890
// Ada Lovelace(AD102, AD103, AD104)
#      define	GPU_PREFIX		ADA
#      define	MAX_THREAD_BLOCKS       (24)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(48)
#      define	MAX_LDST_PER_MP		(16)
#      define	SHMEM_CAPACITY_KB	(128)
#      define	SHMEM_wo_OPTIN_KB	(100)
#      define	SHMEM_UNIT_SIZE		(128)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Hopper
// 900
// Hopper (GH100)
#      define	GPU_PREFIX		HOPPER
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(228)
#      define	SHMEM_wo_OPTIN_KB	(100)
#      define	SHMEM_UNIT_SIZE		(256)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Blackwell
// 1000
// Blackwell (GB100)
#      define	GPU_PREFIX		BLACKWELL
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(64)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(256)
#      define	SHMEM_wo_OPTIN_KB	(100)
#      define	SHMEM_UNIT_SIZE		(256)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#    if GPU_ARCH == Blackwell2
// 1200
// Hopper (GB20X)
#      define	GPU_PREFIX		BLACKWELL2
#      define	MAX_THREAD_BLOCKS       (32)
#      define	MAX_REGS_PER_BLOCK	(65536)
#      define	MAX_WARP_PER_MP		(48)
#      define	MAX_LDST_PER_MP		(32)
#      define	SHMEM_CAPACITY_KB	(100)
#      define	SHMEM_wo_OPTIN_KB	(100)
#      define	SHMEM_UNIT_SIZE		(256)
#      define	REGIS_UNIT_SIZE		(256)
#      define	WARP_ALLOC_UNIT		(4)
#      define	FENCE(...)		__threadfence( )
#      define	FENCE_BLOCK(...)	__threadfence_block( )
#      define	FENCE_SYSTEM(...)	__threadfence_system( )
#    endif

#  endif  // GPU_ARCH

#endif

