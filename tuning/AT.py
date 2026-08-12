#! /usr/bin/env python

import sys
import os
import subprocess
import re
import datetime
from pathlib import Path
import shutil


# print message on consle
#   char[]      message
#   streaming   stdout (default is sys.stdout)
#  :: output    none
def console_print( message, stdout=sys.stdout ) :
    stdout.write( '{}\n'.format(message) )
    stdout.flush()

# cat the message onto the file
#   char[]      Fname
#   any_data    data[]
#  :: output    none
def cat_string_to_file( Fname, data ) :
    with open( Fname, mode = 'w' ) as file :
        file.write(data)
        file.flush()

# append the message onto the file
#   char[]      Fname
#   any_data    data[]
#  :: output    none
def append_string_to_file( Fname, data ) :
    with open( Fname, mode = 'a' ) as file :
        file.write(data)
        file.flush()

# run command with an output pipeline or a output file
#   char[]      Command
#   char[]      output (output fline name, if '' then stdout)
#   streaming   stdout (default is subprocess.stdout)
#  :: output    none
def run_command( Command, output='', stdout=subprocess.STDOUT ) :
    if output == '' :
        if stdout == subprocess.STDOUT :
            subprocess.run( Command )
        else :
            subprocess.run( Command, stdout=stdout )
    else :
        with open( output, mode = 'w' ) as file :
            subprocess.run( Command, stdout=file )
            file.flush()

# run command Asynchronously with an output pipeline
#   char[]      Command
#   streaming   in_pipe (default is subprocess.DEVNULL)
#  :: output    stdout (as a pipe)
def run_command_async( Command, in_pipe=subprocess.DEVNULL ) :
    return subprocess.Popen( Command, stdin=in_pipe, stdout=subprocess.PIPE ).stdout

# run command synchronously with an output pipeline
#   char[]      Command
#   streaming   in_pipe (default is subprocess.DEVNULL)
#  :: output    stdout (as a pipe)
#
# usage:
#    run_command_sync( ['tee', '-a', LOG+'.0'],
#        run_command_async( ['/bin/bash', script, '0'] ) )
#
#    ==> /bin/bash $script 0 | tee -a $LOG.0
#
def run_command_sync( Command, in_pipe=subprocess.DEVNULL ) :
    return subprocess.run( Command, stdin=in_pipe ).stdout

def get_from_pipe( in_pipe=subprocess.DEVNULL ) :
    buff = ''
    if in_pipe != subprocess.DEVNULL :
        buff = in_pipe.readline()
    return buff



def echo_Message( arg, stdout=sys.stdout ) :

    stdout.flush()
    stdout.write('<--/****************************************\n')
    stdout.write(' Automatic Performance Tuning for {}\n'.format(KERNEL))
    now=datetime.datetime.now()
    stdout.write(now.strftime(' %a %b %d %H:%M:%S %Z %Y\n'))
    stdout.write(' Host on {}\n'.format(HOST))
    stdout.write(' Device is {}\n'.format(DEVICE))
    if 'begin' in arg :
        stdout.write(' Start\n')
    if 'end' in arg :
        stdout.write(' Successfully completed.\n')
    if 'termination' in arg :
        stdout.write(' Terminated unfortunately.\n')
    stdout.write('****************************************/-->\n')
    stdout.flush()


def init( ) :

    global PYTHON
    global DATE
    global HOST
    global DEVICE
    global MP
    global CG
    global MAXDIM
    global WORK_DIR
    global LOG

    # $ASPEN_SRC/tuning
    HOST = os.uname()[1]
    DATE = datetime.datetime.now().strftime('%Y.%m.%d.%T')

    # $ASPEN_SRC/tuning
    os.chdir('../src')
    # $ASPEN_SRC/src
    run_command( ['make', 'get_dev_info'] )
    # $ASPEN_SRC/src
    os.chdir('../tuning')
    # $ASPEN_SRC/tuning
    run_command( ['../src/get_dev_info'], 'DEV_INFO' ) 

    DEVICE='unkown'
    MP=0
    CG=0
    MAXDIM=0
    with open( 'DEV_INFO', mode = 'r' ) as file :
        line = file.readline()
        while line :
            if 'DEVICE=' in line :
                DEVICE = re.sub('DEVICE=[ ]*','',line)
                DEVICE = DEVICE.strip()
            if 'MP=' in line :
                MP = re.sub('MP=[ ]*','',line)
                MP = MP.strip()
            if 'CG=' in line :
                CG = re.sub('CG=[ ]*','',line)
                CG = CG.strip()
            if 'MAXDIM=' in line :
                MAXDIM = re.sub('MAXDIM=[ ]*','',line)
                MAXDIM = MAXDIM.strip()
            line = file.readline()

    cat_string_to_file( 'CURRENT_GPU', '#define CURRENT_GPU {}\n'.format(CG) )

    # $ASPEN_SRC/tuning
    os.chdir('../src')
    # $ASPEN_SRC/src
    run_command( ['make', 'get_mult', 'get_mult32', 'get_mult48'] )
    # $ASPEN_SRC/src
    os.chdir('../tuning')
    # $ASPEN_SRC/tuning
    
    PYTHON = os.getenv('PYTHON')
    if not PYTHON :
        PYTHON = 'python3'
        os.environ['PYTHON'] = PYTHON

    WORK_DIR='{}-current'.format(kernel)
    LOG='log-{}-AT1X.{}'.format(WORK_DIR, DATE)
    # $ASPEN_SRC/tuning

    aline = subprocess.run( [ 'pip', 'list' ], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True )
    for pack in [ 'numpy', 'scipy', 'cxxfilt' ]:
      if pack not in aline.stdout :
        subprocess.run( [ 'pip', 'install', pack ] )

def touch_header( ) :

    # $ASPEN_SRC/tuning
    run_command( [PYTHON, 'touch_header.py'] )
    # $ASPEN_SRC/tuning


def touch_dirs( ) :

    # $ASPEN_SRC/tuning
    console_print('Tuning processes are recorded on {}.'.format(LOG))
    Path(LOG).mkdir()
    Path(WORK_DIR).touch()
    Path(WORK_DIR).unlink()
    Path(WORK_DIR).symlink_to(LOG)
    # $ASPEN_SRC/tuning
    os.chdir(WORK_DIR)
    # $ASPEN_SRC/tuning/$WORK_DIR

    # $ASPEN_SRC/tuning/$WORK_DIR
    os.chdir('../../src')
    # $ASPEN_SRC/src
    run_command( ['make', 'get_dev_info'] )
    # $ASPEN_SRC/src
    os.chdir('../tuning/'+WORK_DIR)
    # $ASPEN_SRC/tuning/$WORK_DIR
    Path('get_dev_info').symlink_to('../../src/get_dev_info')

    #tar_c = subprocess.Popen(['tar', '-C', '../..','-cf','-','src','template'],
    #    stdout=subprocess.PIPE)
    #tar_x = subprocess.run(['tar', '-xf','-'],
    #    stdin=tar_c.stdout)
    run_command_sync( ['tar', '-xf', '-'],
        run_command_async( ['tar', '-C', '../..', '-cf', '-', 'src', 'template'] ) )

    # $ASPEN_SRC/tuning/$WORK_DIR
    os.chdir('src')
    # $ASPEN_SRC/tuning/$WORK_DIR/src
    run_command( ['make', 'clean'] )
    # $ASPEN_SRC/tuning/$WORK_DIR/src
    os.chdir('..')
    # $ASPEN_SRC/tuning/$WORK_DIR

    if Path('done_pattern').exists() :
        Path('done_pattern').unlink()
    # $ASPEN_SRC/tuning/$WORK_DIR
    os.chdir('..')
    # $ASPEN_SRC/tuning


def check_CG( ) :

    is_active_type=False
    if (not (pred_ == 'h' or pred_ == 'k')) or int(CG)==530 or int(CG)>=600 :
        is_active_type=True
    return is_active_type


def AT_main( ) :

    # $ASPEN_SRC/tuning
    os.chdir(WORK_DIR)
    # $ASPEN_SRC/tuning/$WORK_DIR

    script = '../{}_a.sh'.format(kernel)
    #run_pipe = subprocess.Popen(['/bin/bash', script, '0'],
    #        stdout=subprocess.PIPE)
    #tee_pipe = subprocess.run( ['tee', '-a', LOG+'.0'],
    #        stdin=run_pipe.stdout)
    run_command_sync( ['tee', '-a', LOG+'.0'],
        run_command_async( ['/bin/bash', script, '0'] ) )
    console_print('Complete phase a0')

    #run_pipe = subprocess.Popen(['/bin/bash', script, '1'],
    #        stdout=subprocess.PIPE)
    #tee_pipe = subprocess.run(['tee', '-a', LOG+'.0'],
    #        stdin=run_pipe.stdout)
    ###run_command_sync( ['tee', '-a', LOG+'.0'],
    ###    run_command_async( ['/bin/bash', script, '1'] ) )
    ###console_print('Complete phase a1')
    ###
    ###run_command_sync( ['tee', '-a', LOG+'.0'],
    ###    run_command_async( ['/bin/bash', script, '2'] ) )
    ###console_print('Complete phase a2')

    script = '../{}_b0.sh'.format(kernel)
    run_command( ['/bin/bash', script, LOG, '0', '1', 'top20-0step'] )
    console_print('Complete phase b0')

    script = '../{}_b1.sh'.format(kernel)
    run_command( ['/bin/bash', script, LOG, '1', '2', 'top20-1step'] )
    console_print('Complete phase b1')

    script = '../{}_b2.sh'.format(kernel)
    run_command( ['/bin/bash', script, LOG, '2', '3', 'top20-2step'] )
    console_print('Complete phase b2')

    outfile = 'param-{}.h'.format(kernel)
    cat_string_to_file( outfile,
'''#if defined(PRESERVE_DROP)
#undef PRESERVE_DROP
#endif
#define PRESERVE_DROP   1
''' )
    shutil.copy(outfile, '../'+outfile)
    
    script = '../{}_b3.sh'.format(kernel)
    run_command( ['/bin/bash', script, LOG, '3', '4', 'top20-3step'] )
    console_print('Complete phase b3')

    script = '../{}_b4.sh'.format(kernel)
    run_command( ['/bin/bash', script, LOG, '4', '5', 'top20-final'] )
    console_print('Complete phase b4')

    outfile1 = '{}-{}-auto3.h'.format(kernel_,uplo_)
    run_command( [PYTHON, '../symv_predict.py', 'predict.data', outfile1] )
    console_print('Complete phase c')

    outfile2 = '{}-{}-auto2.h'.format(kernel_,uplo_)
    run_command([PYTHON, '../d_filter.py', outfile1, outfile2])
    console_print('Complete phase d')

    # $ASPEN_SRC/tuning/$WORK_DIR
    os.chdir('..')
    # $ASPEN_SRC/tuning


def post_process_header( ) :

    # $ASPEN_SRC/tuning
    os.chdir(WORK_DIR)
    # $ASPEN_SRC/tuning/$WORK_DIR
    for f in [ '', '2' ] :
        Fname = '{}-{}-auto{}.h'.format(kernel_,uplo_,f)
        Path(Fname).touch()
        Fname_ = Fname+'_'
        cat_string_to_file( Fname_,
'''#ifndef {KERNEL}_AUTO{F}_H_INCLUDED
#define {KERNEL}_AUTO{F}_H_INCLUDED    1

#if 0
'''.format(KERNEL=KERNEL, F=f) )
        with open( Fname_, mode = 'a' ) as file :
            echo_Message('-', stdout=file)
            run_command( ['cat', '../DEV_INFO'], stdout=file )
            file.write( '<--\n' )
            file.flush()
            run_command( ['cat', '../CURRENT_GPU'], stdout=file )
            file.write( '-->\n' )
            file.write( '#endif\n' )
            file.flush()
            if check_CG() :
                run_command( ['cat', Fname], stdout=file )
            file.write( '\n#endif\n' )
        Path(Fname_).rename(Fname)
        shutil.copy(Fname, '../'+Fname)

    outfile = 'param-{}.h'.format(kernel)
    cat_string_to_file( outfile,
'''#if defined(PRESERVE_DROP)
#undef PRESERVE_DROP
#endif
#define PRESERVE_DROP   1
''' )
    shutil.copy(outfile, '../'+outfile)

    # $ASPEN_SRC/tuning/$WORK_DIR
    os.chdir('..')
    # $ASPEN_SRC/tuning


def Make( ) :

    # $ASPEN_SRC
    NULL = subprocess.DEVNULL

    # $ASPEN_SRC
    os.chdir('src')
    # $ASPEN_SRC/src
    objfile = '{}_{}.cu_o'.format(kernel_,uplo_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    objfile = '{}_{}.cu_lo'.format(kernel_,uplo_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    run_command( ['make'], stdout=NULL )

    # $ASPEN_SRC/src
    os.chdir('../bench')
    # $ASPEN_SRC/bench
    objfile = 'test-{}.o'.format(pred_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    objfile = 'test2-{}.o'.format(pred_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    run_command( ['make'], stdout=NULL )

    # $ASPEN_SRC/bench
    os.chdir('..')
    # $ASPEN_SRC


def simple_benchmark( ) :

    # $ASPEN_SRC/bench
    os.chdir('..')
    # $ASPEN_SRC
    Make()
    # $ASPEN_SRC
    console_print('Complete phase e')

    # $ASPEN_SRC
    os.chdir('bench')
    # $ASPEN_SRC/bench
    cat_string_to_file( 'IN-abc',
'''1
10
-1
''' )

    TEST='./test-{}-{}'.format(kernel_,uplo_[0])
    TEST2='./test2-{}-{}'.format(kernel_,uplo_[0])
    NULL=subprocess.DEVNULL

    if check_CG() :
        run_command( ['timeout','-s','KILL','30',TEST,'IN-abc'], stdout=NULL )
        run_command( ['timeout','-s','KILL','30',TEST,'IN-abc'], stdout=NULL )
        run_command( ['timeout','-s','KILL','600',TEST,'IN-medium'] )

    console_print('Complete phase f1')

    if check_CG() :
        run_command( ['timeout','-s','KILL','20',TEST2,'IN-abc'], stdout=NULL )
        run_command( ['timeout','-s','KILL','3600',TEST2,'IN-medium'] )

    Path('IN-abc').unlink()
    console_print('Complete phase f2')
    # $ASPEN_SRC/bench
    os.chdir('..')
    # $ASPEN_SRC

    # $ASPEN_SRC
    os.chdir('tuning')
    # $ASPEN_SRC/tuning
    Path('.done-{}'.format(kernel)).touch()
    # supposed to be $ASPEN_SRC/tuning


def arg_check( ARG ) :

    global KERNEL
    global kernel
    global kernel_
    global uplo_
    global pred_
    global PRED_
    global type_
    global sizeof_

    kernel  = re.sub('_','',ARG)
    KERNEL  = kernel.upper()
    kernel_ = re.sub('_.*','',ARG)
    uplo    = re.sub('.*_','',ARG)
    pred_   = re.sub('(sy|he)mv.*','',kernel_)

    symv_=''
    OK_pred = False
    if pred_ == 'i16' or pred_ == 'i32' or pred_ == 'i64' or pred_ == 'i128' :
        if 'symv' in kernel_ :
            symv_='symv'
            OK_pred = True
    else :
        if len(pred_) == 1 :
            if pred_ in 'wdsh' and 'symv' in kernel_ :
                symv_='symv'
                OK_pred = True
            if pred_ in 'uzck' and 'hemv' in kernel_ :
                symv_='hemv'
                OK_pred = True
    PRED_ = pred_.upper()

    type_=''
    if OK_pred :
        if pred_[0] == 'i' :
            type_ = 'int{}'.format(pred_[1:])
            sizeof_ = int(pred_[1:])/8
        else :
            if pred_ == 'w' :
                type_   = 'ddreal'
                sizeof_ = 16
            if pred_ == 'd' :
                type_   = 'double'
                sizeof_ = 8
            if pred_ == 's' :
                type_   = 'float'
                sizeof_ = 4
            if pred_ == 'h' :
                type_   = 'half'
                sizeof_ = 2
            if pred_ == 'u' :
                type_   = 'ddcomplex'
                sizeof_ = 32
            if pred_ == 'z' :
                type_   = 'cuDoubleComplex'
                sizeof_ = 16
            if pred_ == 'c' :
                type_   = 'cuFloatComplex'
                sizeof_ = 8
            if pred_ == 'k' :
                type_   = 'cuHalfComplex'
                sizeof_ = 4

    uplo_='_'
    OK_uplo = False
    if len(uplo) == 1 :
        if uplo[0]=='u' :
            uplo_='upper'
        if uplo[0]=='l' :
            uplo_='lower'
    if uplo_ != '_' :
        OK_uplo = True

    OK_kernel = False
    if symv_ != '' :
        if ARG == pred_+symv_+'_'+uplo[0] :
            OK_kernel = True

    if not ( OK_pred and OK_kernel and OK_uplo ) :
        exit(1)


def cwd_check() :

    # $ASPEN_SRC/tuning
    if 'tuning' != re.sub('.*/','', os.getcwd()) :
        exit(1)
    if not Path('../src').exists() :
        exit(1)
    if not Path('../template').exists() :
        exit(1)
    if not Path('../bench').exists() :
        exit(1)
    # $ASPEN_SRC/tuning


if __name__ == '__main__' :

    # $ASPEN_SRC/tuning
    cwd_check()
    # $ASPEN_SRC/tuning

    args = sys.argv
    argc = len( args )

    ARG='dsymv_u' if argc != 2 else args[1]
    arg_check(ARG)

    # $ASPEN_SRC/tuning
    init()
    # $ASPEN_SRC/tuning
    echo_Message('begin')
    # $ASPEN_SRC/tuning
    touch_header()
    # $ASPEN_SRC/tuning
    touch_dirs()
    # $ASPEN_SRC/tuning
    if check_CG() :
        AT_main()
    # $ASPEN_SRC/tuning
    post_process_header()
    # $ASPEN_SRC/tuning
    simple_benchmark()
    # $ASPEN_SRC/tuning

    echo_Message('end')

