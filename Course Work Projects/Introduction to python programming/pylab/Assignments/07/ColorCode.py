#!/usr/bin/env python
# encoding: utf-8

import sys



def main():
    li = []
    s= ""

    if len(sys.argv) == 4: #because the name of the file is the first parameter
        for i in range(len(sys.argv)-1,0,-1): #started from last element, so it is put first in s,
                                              #when we inverse s=s[::-1], it becomes the last element
            n=int(sys.argv[i])
            if n in range(255+1):
                while n is not 0:
                    temp = n%16
                    n= int(n/16)
                    if temp == 10:
                        s+='A'
                    elif temp == 11:
                        s+='B'
                    elif temp == 12:
                        s+='C'
                    elif temp == 13:
                        s+='D'
                    elif temp == 14:
                        s+='E'
                    elif temp == 15:
                        s+='F'
                    else:
                        s+=str(temp)
                    
        s=s[::-1] #After making division, you read it from down to up
            
        print "The color code in hex: #{0}".format(s) 
    
      


    
if __name__ == "__main__":
    main()
