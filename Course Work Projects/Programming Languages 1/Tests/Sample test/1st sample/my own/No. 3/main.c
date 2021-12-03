#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[30],sum=0;
    float avg=0.00;
    int i;
    for (i=0;i<30;i++){
        printf("\nThe %d number is :-",i+1);
        scanf("%d",& num[i]);
    }
    for (i=0;i<30;i++){
        sum += num[i];
        avg = (float)sum/30;
    }
    printf("The sum of the numbers is :-%d\nThe average of the numbers is :-.2%f",sum,avg);

    return 0;
}
