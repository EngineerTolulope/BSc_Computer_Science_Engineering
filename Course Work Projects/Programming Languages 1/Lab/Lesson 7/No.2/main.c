#include <stdio.h>
#include <stdlib.h>

void readtoarray(int *ar,int size){
int i;
for (i=0;i<size;i++){
    printf("Give me the %d. number...",i+1);
    scanf("%d",&ar[i]);
}
 return;
}
void getsumavg(int *ar,int size,int *sum,float *avg){
int i;
*sum=0;
for (i=0;i<size;i++){
    *sum+=ar[i];
    *avg=(*sum)/(float)size;
}

return;
}
int main()
{
int numbers[20];
int sum;
float avg;
readtoarray(numbers, 20);//fill the array with numbers
 getsumavg(numbers,20,&sum,&avg);//get the sum and the average
 printf("Sum: %d\navg: %.2f",sum,avg);//print out the sum and average
  return 0;
}
