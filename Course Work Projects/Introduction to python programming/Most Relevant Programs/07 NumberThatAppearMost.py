#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random
"""
Takes the number 2^4096, and prints out the number that appear the most, with the number of times appeared
"""

def main():
    #n = 2**4096
    li = list(str(2**4096)) #puts each number in a list, for further testing
    count=0
    fcount = 0 #to store the final count
    fnum= 0 #to store the final number
    for num in li: # Goes through every number in the list
        while num in li: # checks if number is still in the list, then it adds one to count
            count+= 1
            li.pop(li.index(num))#removes that it found from the list, then check again
            
        if count > fcount:#if the count is more than our fcount the enters
            fcount = count
            fnum = int(num) #stores the number
            
    print (fnum, '->' , fcount)
        
            
#############################################################################

if __name__ == '__main__':
    main()
