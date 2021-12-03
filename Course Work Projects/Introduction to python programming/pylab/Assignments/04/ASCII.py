#!/usr/bin/env python
# encoding: utf-8

import sys


def main():
    for n in range(37,128):
        print "{a}: {b}".format(a=n,b=chr(n))    
    sum=0
    for h in range(ord('A'),ord('Z') +1):
        sum+=h

    print "Sum of upper is :- {0}".format(sum)
if __name__ == "__main__":
    main()
