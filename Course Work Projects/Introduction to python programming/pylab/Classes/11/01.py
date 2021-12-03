#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
    
def main():
    f = open("output.txt", "w")
    
    f.write("1st line\n")
    f.write("2nd line\n")
    
    print >>f, "aa", 3.14,"bb",6 #prints out 'aa 3.14 bb 6' to file f
    print >>f, "END"
    
    f.close()  
#############################################################################

if __name__ == '__main__':
    main()
