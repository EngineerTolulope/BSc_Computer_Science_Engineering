#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

INPUT = 'string1.py'
OUTPUT = 'output2.py' 
def main():
    f=open(INPUT,'r')
    to=open(OUTPUT,'w')
    
    for line in f:
        line=line.rstrip("\n")#remove \n at the end of the line
        copy = line #copy the line to a variable
        copy = copy.lstrip() #remove wide spaces at the beginning
        if not copy.startswith("#"): #if it doesn't start with "#", then write it in the file
            print >>to, line

    f.close()  
    to.close()


"""
    f1= open("string1.py", "r")
    f = open("output2.txt", "w")
    
    for l in f1:
        if l.find("#") > -1:
            print >>f,l[:l.find("#")]
        else:
            print >>f,l,
"""     
   
    
    
    
    
#############################################################################

if __name__ == '__main__':
    main()
