#!/usr/bin/env python
# coding: utf-8 

import sys

def hello(name):
    if name == "Batman" or name == "Robin":
       # print "Hello " + name +"!"
       print "Ay! The Batman team is here!"
    else:
       print "Hello " + name +"!" 
 
def main():
    #print=sys.argv[1]
    name = sys.argv[1]#We store the first element as a variable
    hello(name)
    #print "Hello " + name + "!"
    #As We run this program we should use ./1stClass.py with a name so it stores it in sys.argv[1]; and use it when printing
    
if __name__=="__main__":
    main()
