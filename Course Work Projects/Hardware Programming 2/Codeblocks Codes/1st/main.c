#include <stdio.h>
#include <stdlib.h>
//average of numbers between 1 and 1000
int main()
{
    float sum=0,count=0;
    int i;
    for (i=1;i<=1000;i++){
        if (i%2==0){
            sum+=i;
            count++;
        }
    }
    printf("Average: %.2f", sum/count);
    return 0;
}
