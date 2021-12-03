#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

def main():
    if len(sys.argv)==2:
        print "Hello, " + sys.argv[1] + "!"
    else:
        print "Error: provide a parameter"
    
#############################################################################

if __name__ == '__main__':
    main()
