import sys
import os
import subprocess
import re
import datetime
from pathlib import Path
import shutil


def console_print( message, stdout=sys.stdout ) :
    stdout.write( '{}\n'.format(message) )
    stdout.flush()

def cat_string_to_file( Fname, data ) :
    with open( Fname, mode = 'w' ) as file :
        file.write(data)
        file.flush()
def append_string_to_file( Fname, data ) :
    with open( Fname, mode = 'a' ) as file :
        file.write(data)
        file.flush()
def run_command( Command, output='', stdout=subprocess.STDOUT ) :
    if output=='' :
        if stdout==subprocess.STDOUT :
            subprocess.run( Command )
        else :
            subprocess.run( Command, stdout=stdout )
    else :
        with open( output, mode = 'w' ) as file :
            subprocess.run( Command, stdout=file )
            file.flush()
def run_command_async( Command, in_pipe=subprocess.DEVNULL ) :
    return subprocess.Popen( Command, stdin=in_pipe, stdout=subprocess.PIPE ).stdout
def run_command_sync( Command, in_pipe=subprocess.DEVNULL ) :
    return subprocess.run( Command, stdin=in_pipe ).stdout

