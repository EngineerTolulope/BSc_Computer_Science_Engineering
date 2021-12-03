#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
    # TODO...
    f=open('text.txt','r')
    
    for line in f:
        line = line.rstrip('\n')
        print line
        
    f.close()

#############################################################################

if __name__ == '__main__':
    main()`
