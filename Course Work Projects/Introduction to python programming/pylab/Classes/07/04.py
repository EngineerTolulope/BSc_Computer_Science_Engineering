#!/usr/bin/env python
# encoding: utf-8

import sys

def greet(name, greeting='Hello'):
    print "{g} {n}!".format(g=greeting, n=name)
    

def main():
    greet("Peter")
    greet("Peter",greeting="Bonjour")#this overrides the greeting variable to 'Bonjour', so Bonjour is passed to the greet function
    greet("Peter",greeting="Ciao")   
    
if __name__ == "__main__":
    main()
