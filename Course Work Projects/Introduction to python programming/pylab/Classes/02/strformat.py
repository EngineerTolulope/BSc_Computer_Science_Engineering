#!/usr/bin/env python
# coding: utf-8 

import sys
def hello(name,what,color):
    #mario, the bus is red!
    #in C language:
    #printf("%s, the %s is %s!\n", name , what ,color);
    
    #ver 1
    #print "{0}, the {1} is {2}! ".format(name,what,color)
    #ver 2
   # print "{}, the {} is {}! ".format(name,what,color)#you have to put this orderly
    #ver 3
    print "{n}, the {w} is {c}! ".format(n=name.capitalize(),w=what,c=color)
def main():
    hello('mario','bus','red')
    hello('sara','sky','blue')
if __name__=="__main__":    
    main()
