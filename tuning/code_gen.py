#! /usr/bin/env python

import sys
import os
import subprocess
import re


def Read_Data( infile ) :

    with open( infile, mode = 'r' ) as file :

        id = 1
        while True :
            line = file.readline()
            if not line :
                break

            a = line.split()
            if len(a) > 0 :
                score[id]      = int(a[0])
                BLOCK_SIZE[id] = int(a[1])
                VX[id]         = int(a[2])
                UX[id]         = int(a[3])
                MULTI[id]      = int(a[4])
                MX[id]         = int(a[5])
                GY[id]         = int(a[6])
                id = id + 1

    num_kernels = id
    return num_kernels


def Write_Data( num_kernels, outfile, lu_op, step ) :

    kernel_name = 'HESYMV{}_ATOMIC__host'.format( lu_op )
    outfile1 = outfile + '.h'
    outfile2 = outfile + '2.h'
    OutFile  = re.sub( '-', '_', outfile ).upper()

    range1 = 1
    range2 = 1
    factor = 1
    if step == 1 :
       range1 = 20
       range2 = 1
       factor = 100
    if step == 10 :
       range1 = 100
       range2 = 10
       factor = 100

    with open( outfile1, mode = 'w' ) as file :

        out_data = \
'''#ifndef\tASPEN_{outfile}
//
//======  \'{outfile1}\'  =====//
//
{{
'''
        file.write( out_data.format( outfile=OutFile, outfile1=outfile1 ) )

        out_data = \
'''    //==========
    if ( blk == -1 ) {{
        #include "{outfile2}"
    }}
    //==========

#if 0
    struct HESYMV_auto_tuning_param_t {{
        int\tBLOCK_SIZE, GY, VX, UX, MULTI, MX;
    }} PARAM[{num:d}+1] = {{
'''
        file.write( out_data.format( outfile2=outfile2, num=num_kernels ) )

        fmt = '        {{ {:3d}, {:3d}, {:2d}, {:3d}, {:2d}, {:2d} }},\n'
        for i in range( 1, num_kernels ) :
            file.write( fmt.\
                format( BLOCK_SIZE[i], GY[i], VX[i], UX[i], MULTI[i], MX[i] ) )
        file.write( fmt.\
            format( 0, 0, 0, 0, 0, 0 ) )

        out_data = \
'''    }};
#endif

'''
        file.write( out_data.format() )

        out_data = \
'''    //==========
    switch ( BLK ) {{

'''
        file.write( out_data.format() )


        fmt=\
'''    #if KERNEL_0
    case 0:
        {name} ( n, alpha, a, lda, x, incx, beta, y, incy );
        break;
    #endif
'''
        kernel_name_head = re.sub( '-', '_', outfile )
        kernel_name_head = re.sub( 'auto', 'small', kernel_name_head )
        file.write( fmt.format( name=kernel_name_head) )

        fmt=\
'''    #if KERNEL_{id}
    case {id:5d}:
        API_private({name})
            < GPU_ARCH, scalar_t, {GX:3d}, {GY:3d}, {VX:2d}, {UX:3d}, {M:2d}, {MX:3d} >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
'''
        for i in range( 1, num_kernels ) :
            for m in range( 0, range1, range2 ) :
                kernel_id = i * factor + m
                mx = ( m if step == 10 else MX[i] )
                gy = ( m if step == 1  else GY[i] )
                file.write( fmt.format( \
                    id=kernel_id, name=kernel_name,
                    GX=BLOCK_SIZE[i], GY=gy, VX=VX[i], UX=UX[i], M=MULTI[i], MX=mx ) )


        out_data = \
'''
    default:
        // nothing to be done here
        break;
    }}
    //==========

'''
        file.write( out_data.format() )

        out_data = \
'''}}
//
//======  \'{outfile1}\'  =====//
//
#define\tASPEN_{outfile}\t1
#endif
'''
        file.write( out_data.format( outfile=OutFile, outfile1=outfile1 ) )


if __name__ == '__main__' :

    args = sys.argv
    argc = len( args )

    infile  = args[1]
    lu_op   = args[2]
    outfile = args[3]
    step    = int(args[4])


    score      = {}
    BLOCK_SIZE = {}
    VX         = {}
    UX         = {}
    MULTI      = {}
    MX         = {}
    GY         = {}

    num_kernels = Read_Data( infile )
    Write_Data( num_kernels, outfile, lu_op, step )


