#include <stdio.h>
#include <stdlib.h>

//Euclidean Algorithm
int main()
{
    int a,b,r,gcd;
    printf("Give me two numbers with space btw them... ");
    scanf("%d %d", &a, &b);
    a=abs(a);
    b=abs(b);
    while (b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    gcd=a;
    printf("The GCD is %d", gcd);
    return 0;
}
