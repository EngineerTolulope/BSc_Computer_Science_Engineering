#!/usr/bin/env python
# coding: utf-8 

def is_palindrome(s):#This function is to check is the string is the same even when spelt backwards like madam,abba
    #if (s==s[::-1]):
     #   return True
    #else:
     #   return False
    return s==s[::-1]


def main():
    s="abbar"
    print "True" if (s==s[::-1]) else "False"
    #print is_palindrome("abbar")


if __name__=="__main__":
    main()
