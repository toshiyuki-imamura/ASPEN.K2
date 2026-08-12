#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
_min_ (int x, int y) {
  return (x<y)?x:y;
}

int
_max_ (int x, int y) {
  return (x>y)?x:y;
}

int
_ceil_ (int x, int y) {
  return ((x-1)/y+1)*y;
}

int
_floor_ (int x, int y) {
  return (x/y)*y;
}


/*
  # ============================================================

  #	BX  Num of the Threads / ThreadBlock
  #	CX  Num of the Registers / Thread
  #	MX  [B] Minimum spend of Shared Memory / ThreadBlock
  #	CG  Compute Capability Generation (100, 200, 300, 500, ...)
  #
  # ============================================================
*/

int
main( int argc, char * argv[] ) {

  if ( argc < 4 ) {
    printf("0(0)\n");
    exit(1);
  }

  int BX = atoi(argv[1]);
  int CX = atoi(argv[2]);
  int MX = atoi(argv[3]);
  int CG = atoi(argv[4]);

  // # ============================================================

  //  int SHMEM_CAPACITY_KB = 48;
  int SHMEM_CAPACITY_KB = 16;
  int is_unified = 0;
  switch ( CG ) {

  case 100:
    SHMEM_CAPACITY_KB = 16;
    break;

  case 200:
  case 300:
  case 320:
  case 350:
    SHMEM_CAPACITY_KB = 48;
    break;

  case 500:
  case 530:
  case 600:
  case 620:
    SHMEM_CAPACITY_KB = 64;
    break;

  case 520:
  case 610:
    SHMEM_CAPACITY_KB = 96;
    break;

  case 370:
    SHMEM_CAPACITY_KB = 112;
    break;


  case 750:
    SHMEM_CAPACITY_KB = 64;
    is_unified = 1;
    break;

  case 700:
    SHMEM_CAPACITY_KB = 96;
    is_unified = 1;
    break;

  case 860:
    SHMEM_CAPACITY_KB = 100;
    is_unified = 1;
    break;

  case 890:
  case 1200:
    SHMEM_CAPACITY_KB = 128;
    is_unified = 1;
    break;

  case 800:
    SHMEM_CAPACITY_KB = 164;
    is_unified = 1;
    break;

  case 900:
  case 1000:
    SHMEM_CAPACITY_KB = 228;
    is_unified = 1;
    break;


  default:
    //    SHMEM_CAPACITY_KB = 48;
    SHMEM_CAPACITY_KB = 16;
    break;

  }

  int SX = SHMEM_CAPACITY_KB * 1024;

#if 0
  {
    int SHMEM_capacity = 0;
    if ( CG == 200 || CG == 300 || CG == 350 ) {
      SHMEM_capacity = 64;
    } 
    if ( CG == 370 ) {
      SHMEM_capacity = 128;
    } 
    if ( SHMEM_capacity > 0 ) {
      if ( strcmp( argv[0], "get_mult" ) ) {
        SX = (SHMEM_capacity - 48) * 1024;
      }
      if ( strcmp( argv[0], "get_mult32" ) ) {
        SX = (SHMEM_capacity - 32) * 1024;
      }
      if ( strcmp( argv[0], "get_mult48" ) ) {
        SX = (SHMEM_capacity - 16) * 1024;
      }
    }
  }
#else
  // When Unified shared / L1 memory,
  // SHMEM utilization is supposed to minimum to avoid conflict
  // to other users' processes
  // default is 48KB.
  if ( is_unified ) {
    //    int SHMEM_capacity = 48; // 16;
    int SHMEM_capacity = 16;
    SX = SHMEM_capacity * 1024;
  }
#endif

  // # ============================================================

  int WARP            = 32;

  int MAX_REGS        = -1;
  int MAX_BLK         = -1;
  int MAX_WARPS       = -1;
  int MAX_SHMEM       = -1;
  int SHMEM_UNIT_SIZE = -1;
  int REG_UNIT_SIZE   = -1;
  int GRANURARITY     = -1;

  // # ============================================================

  switch ( CG ) {
  case 130:
    // # for Tesla
    MAX_REGS        = 16384;
    MAX_BLK         = 8;
    MAX_WARPS       = 32;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 512;
    REG_UNIT_SIZE   = 512;
    GRANURARITY     = 2;
    break;

  case 200:
    // # for Fermi
    MAX_REGS        = 32768;
    MAX_BLK         = 8;
    MAX_WARPS       = 48;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 128;
    switch ( CX ) {
    case 21:
    case 22:
    case 29:
    case 30:
    case 37:
    case 38:
    case 45:
    case 46:
      REG_UNIT_SIZE = 128;
      break;
    default:
      REG_UNIT_SIZE=64;
      break;
    }
    GRANURARITY     = 2;
    break;

  case 300:
  case 320:
    // # for Kepler
  case 350:
    // # for Kepler2
    MAX_REGS        = 65536;
    MAX_BLK         = 16;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;

  case 370:
    // # for Kepler3
    MAX_REGS        = 65536*2;
    MAX_BLK         = 16;
    MAX_WARPS       = 64;
    MAX_SHMEM       = 48*1024;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;
    
  case 500:
    // # for Maxwell
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;

  case 520:
    // # for Maxwell2

  case 530:
    // # for Maxwell3
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 2;
    break;

  case 600:
    // # for Pascal
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 2;
    break;
    
  case 610:
    // # for Pascal1
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;

  case 620:
    // # for Pascal2
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 128;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;

  case 700:
    // # for Volta
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;

  case 750:
    // # for Turing
    MAX_REGS        = 65536;
    MAX_BLK         = 16;
    MAX_WARPS       = 32;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 256;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;

  case 800:
    // # for Ampere (A100)
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 128;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;
  
  case 860:
    // # for Ampere
    MAX_REGS        = 65536;
    MAX_BLK         = 16;
    MAX_WARPS       = 48;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 128;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;
  
  case 890:
    // # for Ada Lovelace
    MAX_REGS        = 65536;
    MAX_BLK         = 24;
    MAX_WARPS       = 48;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 128;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;
  
  case 900:
    // # for Hopper
  case 1000:
    // # for Blackwell
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 64;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 128;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;

  case 1200:
    // # for Blackwell GB20X
    MAX_REGS        = 65536;
    MAX_BLK         = 32;
    MAX_WARPS       = 48;
    MAX_SHMEM       = SX;
    SHMEM_UNIT_SIZE = 128;
    REG_UNIT_SIZE   = 256;
    GRANURARITY     = 4;
    break;
  
  default:
    printf("0(0)\n");
    exit(1);
    break;
  }

  // # ============================================================

  int SHMEM_RUNTIME = 0;
  // if CG > 800, runtime reserved is not neccessary
  if ( CG == 800 ) {
    SHMEM_RUNTIME = 1024;
  }

  // # ============================================================

  if ( MAX_REGS < 0 ) {
    printf("0(0)\n");
    exit(1);
  }

  if ( SX < MX ) {
    printf("0(0)\n");
    exit(1);
  }

  // # ============================================================

  int AllocatedThreadBlocks = 0;

  // # ============================================================

  int MaxShmemUnits = SX / SHMEM_UNIT_SIZE;
  int AllocatedShmemUnitsPerThreadBlock = ((MX+SHMEM_RUNTIME-1) / SHMEM_UNIT_SIZE) + 1;
  int MaxShmemUnitsPerThreadBlock = MAX_SHMEM / SHMEM_UNIT_SIZE;
  int ShmemUnitsPerThreadBlock = _min_( AllocatedShmemUnitsPerThreadBlock, MaxShmemUnitsPerThreadBlock );

  // # ============================================================

  int WarpsPerThreadBlock = ((BX-1)/WARP) + 1;

  // # ============================================================

  int RegistersPerWarp = CX * WARP;
  int AllocatedRegistersPerWarp = _ceil_ ( RegistersPerWarp, REG_UNIT_SIZE );

  if ( CG < 200 ) {

    int AllocatedWarpsPerThreadBlock = _ceil_ ( WarpsPerThreadBlock , 2 );
    int AllocatedRegistersPerThreadBlock = _ceil_ ( AllocatedWarpsPerThreadBlock * RegistersPerWarp, REG_UNIT_SIZE );
    int MaxRegisters = MAX_REGS;

    AllocatedThreadBlocks = MaxRegisters / AllocatedRegistersPerThreadBlock;

  } else {

    int factor = 1; if ( CG == 370 || CG == 520 || CG == 530 ) factor = 2;
    int MaxRegistersPerThreadBlock = MAX_REGS / factor;

    int AllocatedWarps = _floor_ ( MaxRegistersPerThreadBlock / AllocatedRegistersPerWarp, GRANURARITY );

    AllocatedThreadBlocks = ( AllocatedWarps / WarpsPerThreadBlock );
    AllocatedThreadBlocks *= factor;

  }

  // # ============================================================

  int MaxThreadBlocks_REGS  = AllocatedThreadBlocks;
  int MaxThreadBlocks_WARPS = MAX_WARPS / WarpsPerThreadBlock;
  int MaxThreadBlocks_SHMEM = MaxShmemUnits / ShmemUnitsPerThreadBlock;

#if 0
  printf( "MaxThreadBlocks_REGS  = %d\n", MaxThreadBlocks_REGS );
  printf( "MaxThreadBlocks_WARPS = %d\n", MaxThreadBlocks_WARPS );
  printf( "MaxThreadBlocks_SHMEM = %d\n", MaxThreadBlocks_SHMEM );

  printf( " MaxShmemUnits = %d\n", MaxShmemUnits );
  printf( " ShmemUnitsPerThreadBlock = %d\n", ShmemUnitsPerThreadBlock );
#endif

  int M0 = _min_ (
                  _min_ ( MaxThreadBlocks_REGS, MaxThreadBlocks_SHMEM ),
                  _min_ ( MaxThreadBlocks_WARPS, MAX_BLK ) );

  // # ============================================================

  char *M_PATTERN[2];
  M_PATTERN[0] = (char *)malloc(1024); *M_PATTERN[0] = 0;
  M_PATTERN[1] = (char *)malloc(1024); *M_PATTERN[1] = 0;
  int ptr=0;

  for( int m = M0; m > 0; m-- ) {

    if ( m == M0 || (m+1)*(MaxShmemUnits/m) > MaxShmemUnits ) {

      int OO = (m * WarpsPerThreadBlock * 100) / MAX_WARPS;
      sprintf( M_PATTERN[ptr],
               "%d(%d) %s", m, OO, M_PATTERN[1-ptr] );
      ptr=1-ptr;

    }
  }

  // # ============================================================

  ptr=1-ptr;
  if ( *M_PATTERN[ptr]) {
    printf("0(0) %s\n", M_PATTERN[ptr]);
  } else {
    printf("0(0)\n");
  }

  // # ============================================================

  free(M_PATTERN[0]);
  free(M_PATTERN[1]);

  exit (0);

}

