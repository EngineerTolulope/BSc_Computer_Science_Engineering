#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,prod=1,sum=0,i;
    printf("n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=i;
        prod*=i;
    }
    printf("sum=%d\n prod=%d\n",sum,prod);
    return 0;
}
