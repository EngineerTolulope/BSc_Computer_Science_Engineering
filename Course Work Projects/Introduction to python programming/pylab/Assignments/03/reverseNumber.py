#!/usr/bin/env python
# coding: utf-8 

def reverse(n):
    #s = str(n) convert to string
    #s = s[::-1] inverse the string
    #n = int(s)  convert to integer
    #return n    give back the inverted number
   
    return  int(str(n)[::-1])


def main():
   # n = 2016
    n=raw_input("Give Me A Number...")
    rev = reverse(n)
    print rev #6102
            


if __name__=="__main__":
    main()
