#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
/*
 * Fast modular exponentiation, gives us base ^ exponent % mod
 */
long long modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
/*
 * calculates (a * b) % mod taking into account that a * b might overflow
 */
long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
//
int main()
{
    int p,g,A;
    printf("Give me p...");
    scanf("%d", &p);
    printf("Give me g...");
    scanf("%d", &g);
    printf("Give me A...");
    scanf("%d", &A);
    //
    srand(time(NULL));
    int b= rand()%(p-1); //So we get from 0 still p-2, p-1 is not included
    printf("Give me b...");
    scanf("%d", &b);
    //
    int m;
    printf("Give me the message...");
    scanf("%d", &m);
    //Encryption
    int B= modulo(g,b,p); //g raised to the power of b mod p
    int c= mulmod(modulo(A,b,p),m,p); //calculates A to the power of b multiplied by m, mod p
    //
    printf("The cipher text, which consists of B and C is \n***(%d,%d)***", B, c);
    //
    return 0;
}


