#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random

def my_shuffle(li1):
    random.shuffle(li1) #shuffles the li1 directly
    
    return li1


def main():
    li = range (1, 101) #A list from 1 to 100

    n = my_shuffle(li)[-1]    #gets the last element of the shuffled list
    print n


   
    
    
    
    
#############################################################################

if __name__ == '__main__':
    main()
