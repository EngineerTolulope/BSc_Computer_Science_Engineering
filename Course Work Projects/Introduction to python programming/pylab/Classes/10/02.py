#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random

def my_sum(s):
    sumd=0
    for n in s:
        sumd+=int(n)
    return sumd
    
    
def main():
    print my_sum(raw_input("Give me a number..."))
    
#############################################################################

if __name__ == '__main__':
    main()
