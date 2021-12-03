#include <stdio.h>
#include <stdlib.h>

int main()
{
   int base, exp, i;
    printf("Enter Base: ");
    scanf("%d", &base);
    //printf("Enter exponent: ");
    //scanf("%lf", &exp);
    int result = 1;
    printf("Result is: ");
    for(i=1;i<=10;i++){
        result *=base;


    printf("%d ", result);
    }


    //printf("Hello world!\n");
    return 0;
}

