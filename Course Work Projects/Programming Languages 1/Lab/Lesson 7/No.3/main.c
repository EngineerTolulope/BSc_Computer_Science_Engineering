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
void getminmax(int *ar,int size,int *min ,int *max){
int i;
*min=ar[0];//get the minimum
for (i=1;i<size;i++){// we check from the second element
    if (ar[i]<*min)
        *min=ar[i];
}
*max=ar[0];
for (i=1;i<size;i++){// we check from the second element
    if (ar[i]>*max)
        *max=ar[i];
}
return;
}
int main()
{
int numbers[20];
int sum,Min,Max;
float avg;
readtoarray(numbers, 20);//fill the array with numbers
 getsumavg(numbers,20,&sum,&avg);//get the sum and the average
 printf("Sum: %d\navg: %.2f\n",sum,avg);//print out the sum and average
 getminmax(numbers,20,&Min,&Max);
 printf("Min: %d\nMax: %d\n",Min,Max);
  return 0;
}
