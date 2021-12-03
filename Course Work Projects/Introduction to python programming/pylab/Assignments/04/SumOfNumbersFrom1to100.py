#!/usr/bin/env python
# encoding: utf-8

import sys

def oneto100():
    li=0
    for i in range(1,101):
        li+=i

   # print li
    return li


def main():
    
    print oneto100()
    
    #li = []
    #init=0;
    #for i in range(5):
    #    li.append(int(raw_input("Give me a number..."))) #it adds elements to a list


    #for i in li: #converts a interger list [1,2] to a string list ['1','2']
    #    li[init]=str(i)
    #    init+=1
      
    


if __name__ == "__main__":
    main()
