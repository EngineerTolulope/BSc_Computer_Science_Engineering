#!/usr/bin/env python
# encoding: utf-8

import sys


def main():
    inp = raw_input("Do you really want to quit [y/Y/yes]? ")
    #if inp == 'y' or inp == 'Y' or inp == 'yes':    # <- Can you simplify this line?
    #if inp.startswith('y') or inp.startswith('Y'): 
    if inp == 'y' or inp == 'Y':   
        print 'bye'
        sys.exit(0)
    # for any other input:
    print 'The show goes on...'

##############################################################################

if __name__ == "__main__":
    main()
