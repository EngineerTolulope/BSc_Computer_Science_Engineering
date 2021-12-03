#include<stdio.h>
int main()
{
int a,b,sum=0,prod=1;
printf("a=");
scanf("%d",&a);
printf("b=");
scanf("%d",&b);
while(a)
{
/*we want to find the sum of all the digits in a number like 12345=1+2+3+4+5*/
sum+=a%10;
a=a/10;//because of the int a and b can't be a float
}
while(b)
{
/*we want to find the product of all the digits in a number like 123=1*2*3*/
prod*=b%10;
b=b/10;
}
printf("sum=%d prod=%d",sum,prod);
return 0;

}
