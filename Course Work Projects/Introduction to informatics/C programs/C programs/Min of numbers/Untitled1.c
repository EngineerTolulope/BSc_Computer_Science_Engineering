#include<stdio.h>
int main()
/*gives us the minimum of n numbers, we input numbers until we type zero and it gives us the minimum*/
{
int n,min=0;
printf("n=");
scanf("%d",&n);
min=n;
while(n!=0)
{
if(n<min)
min=n;

printf("n=");
scanf("%d",&n);}
printf("min=%d\n",min);
}
