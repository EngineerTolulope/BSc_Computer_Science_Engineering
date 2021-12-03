#!/usr/bin/env python
# encoding: utf-8

import sys

def hello(name, repeat=1, postfix=''):
    for i in range(repeat):
        print name + postfix

def main():
    hello('Anne')
    hello('Anne',repeat=3)
    hello('Anne',repeat=2,postfix='!') #The same as writing hello('Anne',2,!), but in this case the order is important
    
    
if __name__ == "__main__":
    main()
