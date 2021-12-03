#!/usr/bin/env python
# encoding: utf-8

import sys


def main():
    
    s=raw_input("Give a string")
    s=s.replace(" ","")
    s=s.replace("\n","")
    s=s.replace("\t","")
    print s        


if __name__ == "__main__":
    main()
