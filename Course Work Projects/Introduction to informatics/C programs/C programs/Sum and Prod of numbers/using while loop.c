#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,prod=1,sum=0,i;
    printf("n=");
    scanf("%d",&n);
    i=1;
    while(i<=n)
        {
        sum+=i;
        prod*=i;
        i++;
        }
     printf("sum=%d\n prod=%d\n",sum,prod);
    return 0;
}

