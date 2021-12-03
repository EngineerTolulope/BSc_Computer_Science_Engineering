#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random

"""
Gets a number from the user and prints the highest prime number less than the number gotten and
The first prime number after the number it got
"""
#In C programming we use
"""
int isPrime(int num){ //ex 3
	int i;
	if ((num==1) || (num==0)) return 0;// 1 is not prime
	for(i=2;i<=num/2;i++){
		if (num%i==0) return 0;
	}
	return 1;
}
"""
def isprime(n):
    if n == 1 or n==0: #if this then the number is not a prime number
        return False
    for i in range(2,n):#n is not included
        if n%i == 0:# if this then it is not a prime number
            return False
    
    return True #if it gets to this stage, then the number is a prime number

def main():
    N= int(input('Positive number...'))
    bnum = N - 1 #largest prime number less than N
    anum = N+1#smallest prime number greater than N
    while bnum > 0:#we started from the largest
        if isprime(bnum):#if the number is a prime number then break
            break   
        bnum= bnum - 1 #decrements bnum
    while True: #we don't know have a limit, continue the loop still we get a prime number
        if isprime(anum):
            break
        anum+=1 #increments anum
        
    print ("Before", N, "Prime Number", bnum)
    print ("After", N, "Prime Number", anum)
        
    
    
               
      
              
                    
#############################################################################

if __name__ == '__main__':
    main()
