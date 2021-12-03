#include <stdio.h>

int power(int x,int n)
{
    int i,res=1;
    for(i=0;i<n;i++)
        res*=x;
    return res;
}
int main()
{
    int a,b;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("%d",power(a,b));//a^b is what we are printing out
    return 0;

}
