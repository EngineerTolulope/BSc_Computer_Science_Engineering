#include <stdio.h>
#include <stdlib.h>

//Extended Euclidean Algorithm
int main()
{
    int a,b,r,gcd,x,y,q,n=0; //n represents count
    int tmpx,tmpy;
    int X[2]= {1 , 0};
    int Y[2]= {0,  1};
    printf("Give me two numbers with space btw them... ");
    scanf("%d %d", &a, &b);
    a=abs(a);
    b=abs(b);
    while (b!=0){
        q=a/b; //quotient
        r=a%b; //remainder
        a=b;
        b=r;
        tmpx = X[1] * q + X[0];
        tmpy = Y[1] *q + Y[0];
        X[0]=X[1];
        Y[0]=Y[1];
        X[1]= tmpx;
        Y[1]= tmpy;
        n++;
    }
    x= pow(-1, n) * X[0];
    y= pow(-1,n+1) * Y[0];
    gcd =a; //gcd=a*x + b*y; formula when we use the untouched values e.g 100 and 35
    printf("X is %d, Y is %d, and the GCD is %d", x,y,gcd);
    return 0;
}
