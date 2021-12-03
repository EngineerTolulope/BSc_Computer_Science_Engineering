#!/usr/bin/env python
# encoding: utf-8

import sys
import random as r

UPTO = 100


def main():
    count=0    
    for i in xrange(UPTO):
        if count%10==0:
            print ""                    
            """prints an empty string and automatically put a new line after it"""
        count+=1        
        sys.stdout.write(str(r.randint(0, 9)))
    print



if __name__ == "__main__":
    main()
