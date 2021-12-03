#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double base,exp;
    printf("Enter base: ");
    scanf("%lf",&base);
    printf("Enter exponent: ");
    scanf("%lf",&exp);
    double result = 1;
    while(exp!=0){
     result *=base;
     --exp;
    }
    printf("result is : %f", result);
    return 0;
}
