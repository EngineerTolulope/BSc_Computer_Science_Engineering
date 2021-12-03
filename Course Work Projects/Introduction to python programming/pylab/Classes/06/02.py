#!/usr/bin/env python
# coding: utf-8 

def is_palindrome(s):#This function is to check is the string is the same even when spelt backwards like madam,abba
    #if (s==s[::-1]):
     #   return True
    #else:
     #   return False
    if len(s) < 2:
        return True
    else:
        return s[0]==s[-1] and is_palindrome(s[1:-1])   
#    return s==s[::-1]


def main():
    s="abba"
    print "True" if (s==s[::-1]) else "False" #Tenary Operator In Python
    #print is_palindrome("madam")


if __name__=="__main__":
    main()
