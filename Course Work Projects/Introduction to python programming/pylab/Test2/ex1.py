#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random

""" 
Gets a text from the user and shuffles the letters of the text;
then print it back to the user

"""
def main():
    s = raw_input('Text: ')
    li= list(s)
    random.shuffle(li)
    print ("".join(li))
#############################################################################

if __name__ == '__main__':
    main()
