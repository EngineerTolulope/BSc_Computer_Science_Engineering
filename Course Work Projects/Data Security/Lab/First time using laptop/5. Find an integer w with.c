#include <stdio.h>
#include <stdlib.h>

//Find an integer w with, w mod 2 , w mod 3, w mod 5 == 1, we check numbers until b=1000
int main()
{
    int w,b;
    printf("Give me a number... ");
    scanf("%d", &b);
    for (w=0;w<b;w++){
        if (w%2==1 && w%3==1 && w%5==1)
            printf("%d ", w);
    }
    return 0;
}
