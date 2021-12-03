#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,vincent;
    printf("give me a number ");
    scanf("%d",&vincent);
    int yunus=1;
    for(i=1;i<=10;i++){
        yunus*=vincent;
        printf("%d ",yunus);
    }
    return 0;
}
