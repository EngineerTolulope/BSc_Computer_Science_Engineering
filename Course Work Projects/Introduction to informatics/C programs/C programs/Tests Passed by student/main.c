#include <stdio.h>
#include <stdlib.h>

int main()
{
    int point;
    printf("point=");
    scanf("%d",&point);
    if (point<1||point>5)
        {printf("input a number between 1 and 5:-");
        scanf("%d",& point);}
    if (point==1)
        printf("you have failed\n");
    if (point==2)
        printf("you are on the D level\n");
    if (point==3)
        printf("you are on the C level\n");
    if (point==4)
        printf("you are on the B level\n");
    if (point==5)
        printf("you are on the A level\n");


    return 0;
}
