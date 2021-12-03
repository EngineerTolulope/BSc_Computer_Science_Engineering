#include<stdio.h>
#include<time.h>
int main()
{
    //we need to display  random numbers between 0 to 99 and n represents the number of numbers we want to display
int n,i,a[100];//a[100] is an array to contain 100 numbers
printf("n=");
scanf("%d",&n);
srand(time(NULL));/*we used it because we want it for different numbers and not the same numbers and we include<time.h>
because we used a time function*/
for(i=0;i<n;i++)
    //because of the random function rand we need 98 but because of the = +1 it becomes 100
a[i]=(rand()%99)+1;
for(i=0;i<n;i++)
//we needed to put space after  %d because we need space between our ten numbers
printf("%d ",a[i]);
//now we want to find the sum these random numbers and find how many of them are even
int sum=0,count=0;

for(i=0;i<n;i++)
{
    sum=sum+a[i];
    if(a[i]%2==0)
        count++;
}
printf("sum=%d\n,even elements=%d\n",sum ,count);

int min=0;//now we want to find the minimum of these n numbers
for (i=0;i<n;i++)
if(a[i]<a[min])
    min=i;
printf("min value=%d\n min index=%d\n", a[min],min);// we print out minimum index and minimum value

}
