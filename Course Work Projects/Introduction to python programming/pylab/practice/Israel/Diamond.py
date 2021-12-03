#!/usr/bin/env python

import math


def main():
    n=int(raw_input("Give me a number...")) # stores the number to be used on the diamonds
    s='*'
    if n%2!=0:    #it can only be an odd number
        for i in range(1,n+1,2):#we go through still n, using only odd numbers
            print s.center(n)#prints out  with s at the center on n spaces
            s+="**"    #add two chars to n, so continue the for loop for the first half
#############################################################################
        for j in range(1,n+1,2):
            s=s[:-2]  #we remove the last two chars from s, so s can be decreasing  
            if len(s)!=n:    #we don't want the complete "*" part to be printed again, because line 12 added '**' again, so if '*' is not complete we print      
                print s.center(n)#prints out  with s at the center on n spaces
            

if __name__ == "__main__":
    main()
