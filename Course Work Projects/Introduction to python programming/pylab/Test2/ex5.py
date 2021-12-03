#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random
"""
Read numbers from a file and prints out the difference between the max and the min of the numbers
"""
INPUT='numbers.txt' #where we are reading the file from
def main():
    f=open(INPUT,'r') #the file pointer
    li=[]
    for num in f:
        li.append(int(num)) # we add every number to a list
    
    print max(li) - min(li) #we print out the difference btw the max and min
    
    
    
    f.close()
      
#############################################################################

if __name__ == '__main__':
    main()
