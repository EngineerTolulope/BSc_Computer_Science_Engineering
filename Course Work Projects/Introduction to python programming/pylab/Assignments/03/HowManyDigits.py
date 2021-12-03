#!/usr/bin/env python
# coding: utf-8 



def main():
  
    n=int(raw_input("Give Me A Number..."))
    p=int(raw_input("Give me a Power..."))
    num=n**p
    s=str(num)
    numlen=len(s)
    print "The number of digits in {a} is {b}".format(a=num,b=numlen)
            


if __name__=="__main__":
    main()
