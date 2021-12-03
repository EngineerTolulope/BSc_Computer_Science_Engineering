#!/usr/bin/env python
# encoding: utf-8

import sys

def prod(li):
    liprod=1
    for n in li:#n takes the value of the elements and not thier indexes 
        liprod*=n
    return liprod #A function must have a return value

def main():
    li = [5,2,3]
    #li = raw_input("Give me a string:- ")    
    print prod(li) 
    print prod([]) #product of an empty list is 1
    print sum([]) #sum of an empty list is zero       
    


if __name__ == "__main__":
    main()
