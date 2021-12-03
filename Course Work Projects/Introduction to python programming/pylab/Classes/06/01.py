#!/usr/bin/env python
# encoding: utf-8

import sys


def main():
    sum=0
    for n in range(1,1001):
        if n%3==0 or n%5==0:
            sum+=n
        
    print "Sum of Multiples of 3 and 5 is... {0}".format(sum)
if __name__ == "__main__":
    main()
