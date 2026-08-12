#! /usr/bin/env python

import sys
import os
import subprocess
from pathlib import Path
import shutil
import re


def do_touch_header ( target, MACHINE_DIR, CUDA_DIR ) :

    if Path( target ).exists() :
        return

    source_dir0 = 'tuning-old/{}'.format( MACHINE_DIR )
    if Path( source_dir0 ).exists() :
        source_dir1 = '{}/{}'.format( source_dir0, CUDA_DIR )
        if Path( source_dir1 ).exists() :
            source1 = '{}/{}'.format( source_dir1, target )
            if Path( source1 ).exists() :
                print( 'Copy ' + source1 )
                shutil.copy( source1, target )
                return
        else :
            path = [p for p in Path( source_dir0 ).iterdir()]
            path_new = sorted(path, reverse=True,key=lambda x: int(x.name))
            source1 = '{}/{}/{}'.format( source_dir0, path_new[0].name, target )
            if Path( source1 ).exists() :
                print( 'Copy ' + source1 )
                shutil.copy( source1, target )
                return

    source_dir0 = 'tuning-old/default/{}'.format( CUDA_DIR )
    if Path( source_dir0 ).exists() :
        source0 = '{}/{}'.format( source_dir0, target )
        if Path( source0 ).exists() :
            print( 'Copy ' + source0 )
            shutil.copy( source0, target )
            return

    source_dir0 = 'tuning-old/default/{}'.format( DEFAULT_CUDA )
    if Path( source_dir0 ).exists() :
        source0 = '{}/{}'.format( source_dir0, target )
        if Path( source0 ).exists() :
            print( 'Copy ' + source0 )
            shutil.copy( source0, target )
            return

    source_dir0 = 'tuning-old/default/'
    path = [p for p in Path( source_dir0 ).iterdir()]
    path_new = sorted(path, reverse=True,key=lambda x: int(x.name))
    source_dir1 = path_new[0]

    if 'param' in target :
        another = 'param-dsymvu.h'
    if 'upper-auto.h' in target :
        another = 'dsymv-upper-auto.h'
    if 'upper-auto2.h' in target :
        another = 'dsymv-upper-auto2.h'
    if 'lower-auto.h' in target :
        another = 'dsymv-lower-auto.h'
    if 'lower-auto2.h' in target :
        another = 'dsymv-lower-auto2.h'

    another = '{}/{}'.format(source_dir1, another)

    gpat = re.sub( 'mv.*', '', target )
    print( 'Copy&modify {} as a template of {}'.format( another, target ) )
    cmd = 'awk \'{{ gsub(/dsy/,"{}"); gsub(/DSY/,"{}"); print; }}\' {}'.format( gpat, gpat.upper(), another )
    with open( target, mode = 'wb' ) as outfile :
        subprocess.call( cmd, shell = True, stdout = outfile )


if __name__ == '__main__':

    DEFAULT_CUDA = '13000'
    DEFAULT_MACHINE = 'GeForce-RTX-5080'

    p_list  = [ 'w', 'd', 's', 'h', 'u', 'z', 'c', 'k', 'i128', 'i64', 'i32', 'i16' ]
    f_list  = [ 'sy', 'sy', 'sy', 'sy', 'he', 'he', 'he', 'he', 'sy', 'sy', 'sy', 'sy' ]
    lu_list = [ 'upper', 'lower' ]
    ul_list = [ 'u', 'l' ]
    h_list  = [ '@p.@f.mv-@lu.-auto.h', '@p.@f.mv-@lu.-auto2.h', 'param-@p.@f.mv@ul..h' ]


    os.chdir( '../src' )
    subprocess.call( 'make get_dev_info', shell = True )
    os.chdir( '../tuning' )

    CUDA_PATH = os.getenv( 'CUDA_PATH', default = '/usr/local/cuda' )
    DEFAULT_LD_PATH = os.getenv( 'LD_LIBRARY_PATH' )
    LD_LIBRARY_PATH = '{}/lib64:{}'.format( CUDA_PATH, DEFAULT_LD_PATH )
    os.environ[ 'LD_LIBRARY_PATH' ] = LD_LIBRARY_PATH

    ASPEN_GPU_ID = os.getenv( 'ASPEN_GPU_ID', default = 0 )
    cmd = '../src/get_dev_info {}'.format( ASPEN_GPU_ID )
    with open( 'DEV_INFO', mode = 'wb' ) as dev_info :
        subprocess.call( cmd, shell = True, stdout = dev_info )

    CUDA = DEFAULT_CUDA
    with open( 'DEV_INFO', mode = 'r' ) as file :
        while True :
            line = file.readline()
            if not line :
                break
            if 'DEVICE=' in line :
                DEVICE = line.split()[1]
                if 'NVIDIA-' in DEVICE :
                    DEVICE = re.sub( '^NVIDIA-', '', DEVICE )
            if 'CUDA=' in line :
                CUDA = line.split()[1]

    print( 'DEVICE:::' + DEVICE )
    print( 'CUDA:::' + CUDA )

    MACHINE_DIR = 'default'
    CUDA__DIR   = DEFAULT_CUDA

    if Path( 'tuning-old/default' ).exists() :
        Path( 'tuning-old/default' ).unlink()

    Path( 'tuning-old/default' ).symlink_to( DEFAULT_MACHINE )

    if Path( 'tuning-old/{}'.format( DEVICE ) ).exists() :
        MACHINE_DIR = DEVICE
        if Path( 'tuning-old/{}/{}'.format( MACHINE_DIR, CUDA ) ).exists() :
            CUDA__DIR = CUDA
        else :
            path = [p for p in Path( 'tuning-old/{}'.format( DEVICE ) ).iterdir()]
            if len(path) > 0 :
                path_new = sorted(path, reverse=True,key=lambda x: int(x.name))
                CUDA__DIR = path_new[0].name
            else :
                CUDA__DIR = DEFAULT_CUDA
        print( 'The configuration files tuned for {} CUDA {} might be adopted.'.format( DEVICE, CUDA__DIR ) )
    else :
        MACHINE_DIR = 'default'
        print( 'The default configuration files are adopted.' )
        if Path( 'tuning-old/{}/{}'.format( MACHINE_DIR, CUDA ) ).exists() :
            CUDA__DIR = CUDA
        else :
            CUDA__DIR = DEFAULT_CUDA

    for header in h_list :
        for i in range( len( p_list ) ) :
            h1 = re.sub( '@p.', p_list[i], header )
            header_ = re.sub( '@f.', f_list[i], h1 )
            for j in range( len( lu_list ) ) :
                h2 = re.sub( '@lu.', lu_list[j], header_ )
                target = re.sub( '@ul.', ul_list[j], h2 )
                do_touch_header ( target, MACHINE_DIR, CUDA__DIR )

