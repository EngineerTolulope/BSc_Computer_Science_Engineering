#include<stdio.h>
int main()
/*we input numbers from the keyboard until we type zero; it tells if the number is divisible by 3 and says how many
of them are there*/
{
int n,i;
printf("n=");
scanf("%d",&n);
i=0;
while(n!=0)
{
if(n%3==0)
{printf("%d can be divided by 3\n",n);
  i++;}
else
{printf("%d cannot be divided by 3\n",n);}
printf("n=");
scanf("%d",&n);}
printf("%d of the input numbers can divided by 3",i);
return 0;
}
