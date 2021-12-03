#include <stdio.h>
#include <stdlib.h>


int main()
{
   int numbers[10],i,j,flag;
   for (i=0;i<10;i++)//read 10 numbers to the array
   {
       printf("Give me a number...");
       scanf ("%d", &numbers[i]);

   }
   //we have to go through all the elements and check which ones are prime
   for (i=0;i<10;i++)
   {
       flag=1;
       for(j=2;j<numbers[i];j++)// we are not starting from 1 because 1 is always a divisor
       {
           if (numbers[i]%j==0) {flag=0;//j is a divisor so we set flag to 0
           break;}//if we found a divisor no need to go on
           //if flag is 0 then we have found a divisor
           //test if numbers[i] is prime or not

       }
    if ((numbers[i]==1)||(numbers[i]==0)) flag=0;

    if (flag==1) printf("%d ",numbers[i]);//print out the number


   }
    return 0;
}
