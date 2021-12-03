#!/usr/bin/env python
import random


def isprime(n):
    if n == 1 or n == 0:  # if this then the number is not a prime number
        return False
    for i in range(2, n):  # n is not included
        if n % i == 0:  # if this then it is not a prime number
            return False

    return True  # if it gets to this stage, then the number is a prime number


def gcd(a, b):  # Euclidean Algorithm
    while (b != 0):
        r = a % b
        a = b
        b = r
    return a;


def calculate(e, phyn):  # Extended Euclidean Algorithm
    a = e
    b = phyn
    X = [1, 0]
    Y = [0, 1]
    count = 0
    while (b != 0):
        q = int(a / b)  # quotient
        r = a % b  # remainder
        a = b
        b = r
        tmpx = X[1] * q + X[0]
        tmpy = Y[1] * q + Y[0]
        X[0] = X[1]
        Y[0] = Y[1]
        X[1] = tmpx
        Y[1] = tmpy
        count += 1
    tmpx = pow(-1, count) * X[0]
    tmpy = pow(-1, count + 1) * Y[0]

    d = tmpx
    while d <= 1:
        d += phyn
    if (1 < d) and (d < phyn):  return d


def main():
    while True:
        p = random.randint(1000, 5001)
        if (isprime(p)):
            break
    while True:
        q = random.randint(1000, 5001)
        if (isprime(q) and q != p):
            break

    n = p * q
    phyn = (p - 1) * (q - 1)
    e = 2  # One is gcd of all numbers

    while (e < phyn):
        if gcd(e, phyn) == 1:
            break
        else:
            e += 1

    d = calculate(e, phyn)

    print() #Includes a new line
    msg= int(input("Give me a number... "))

    c=pow(msg,e,n)
    m=pow(c,d,n)

    print()
    print ("p = {}".format(p))
    print ("q = {}".format(q))
    print ("n = pq = {}".format(n))
    print ("phyn = (p-1)(q-1) = {}".format(phyn))
    print ("e = {}".format(e))
    print ("d = {}".format(d))
    print()
    print ("public key = (n, e) = ({},{})".format(n,e))
    print ("private key = (n, d) = ({},{})".format(n,d))

    print()
    print("CipherText = {}".format(c))
    print("DecryptedMessage = {}".format(m))




if __name__ == "__main__":
    main()
