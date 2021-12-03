#!/usr/bin/env python
# encoding: utf-8


def main():
    """ I am using ASCII code table to print 2016 ord('Z')=90 minus
    ord('F')=70 gives 20 """
    print "{x}{y}".format(x=ord('Z')-ord('F'), y=ord('Z')-ord('J')) 
    


if __name__ == "__main__":
    main()
