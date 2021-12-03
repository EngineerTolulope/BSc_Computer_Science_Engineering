#!/usr/bin/env python
"""The Sum Of Digits of 2 to the power of 1000"""

def main():
    digit=2**1000
    sumd=0
    for n in str(digit):
        sumd+=int(n)
    #or we can use 'sum([int(e) for e in str(digit)])' it gives the sum of the list 
    print "The Sum Is", sumd
    
if __name__ == "__main__":
    main()
