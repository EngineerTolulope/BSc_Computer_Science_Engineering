#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[10],i;
    // the first way
    /*scanf("%d", &numbers[0]);
    scanf("%d", &numbers[1]);
    scanf("%d", &numbers[2]);
    scanf("%d", &numbers[3]);
    scanf("%d", &numbers[4]);
    scanf("%d", &numbers[5]);
    scanf("%d", &numbers[6]);
    scanf("%d", &numbers[7]);
    scanf("%d", &numbers[8]);
    scanf("%d", &numbers[9]);

    printf("%d ", numbers[9]);
     printf("%d ", numbers[8]);
      printf("%d ", numbers[7]);
       printf("%d ", numbers[6]);
        printf("%d ", numbers[5]);
         printf("%d ", numbers[4]);
          printf("%d ", numbers[3]);
           printf("%d ", numbers[2]);
            printf("%d ", numbers[1]);
             printf("%d ", numbers[0]);*/

    for(i=0;i<10;i++)
    {
        printf("Give 10 random numbers:-");
        scanf("%d", &numbers[i]);
    }

    for(i=9;i>=0;i--)
        printf("%d ", numbers[i]);



    return 0;
}
