#include <stdio.h>
#include <stdlib.h>

//Determine all divisors of an integer
int main()
{
    int num;
    printf("Give me a number... ");
    scanf("%d", &num);
    int i;
    for (i=1;i<=num;i++){
        if (num%i==0)
            printf("%d, -%d, ", i, i);
    }


    return 0;
}
