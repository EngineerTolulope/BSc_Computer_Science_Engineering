#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

INPUT = 'num.txt' 
def main():
    f=open(INPUT,'r')
    sumd=0
    
    for line in f:
        line=line.rstrip('\n')
        n=int(line)
        sumd+=n
    #
    print int(str(sumd)[:10])       

    f.close()  
    



   
    
    
    
    
#############################################################################

if __name__ == '__main__':
    main()
