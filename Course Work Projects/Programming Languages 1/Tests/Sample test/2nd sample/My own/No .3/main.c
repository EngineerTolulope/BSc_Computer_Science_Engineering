#include <stdio.h>
#include <stdlib.h>

 void calculate(float a, float *surface, float *volume);

int main()
{
    float side,surface,volume;
    printf("Give me the length of one side:-");
    scanf("%f",&side);
    calculate(side,&surface,&volume);
    printf("The surface is:- %.2f\nThe volume is:- %.2f",surface,volume);

    return 0;
}

 void calculate(float a, float *surface, float *volume){
 *surface = 6*a*a;
 *volume =a*a*a;
 return;
 }
