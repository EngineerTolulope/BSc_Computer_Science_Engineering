#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p;
    printf("write your score:-");
    scanf("%d",&p);
    if (p<0||p>100)
    {
        printf("default value, give a number between 0 and 100:");
        scanf("%d",&p);
    }
    if (p>0&&p<=20)
        printf("failed\n");
    if (p>20&&p<=40)
        printf("Grade is 2\n");
    if (p>40&&p<=60)
        printf("grade is 3\n");
    if (p>60&&p<=80)
        printf("grade is 4\n");
    if (p>80&&p<=100)
        printf("grade is 5\n");
    return 0;
}
