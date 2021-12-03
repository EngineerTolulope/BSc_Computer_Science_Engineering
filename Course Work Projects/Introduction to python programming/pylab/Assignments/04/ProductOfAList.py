#!/usr/bin/env python
# encoding: utf-8

import sys

def prod(li):
    liprod=1
    for n in li:#n takes the value of the elements and not thier indexes 
        liprod*=n
    return liprod #A function must have a return value

def main():
    li = []
    for i in range(5):
        li.append(int(raw_input("Give me a number..."))) #it adds elements to a list

    print prod(li)


if __name__ == "__main__":
    main()
