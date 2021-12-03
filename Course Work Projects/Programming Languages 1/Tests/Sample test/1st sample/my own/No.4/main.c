#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num[20],n;
    for (i=0;i<20;i++)
    {
        printf("\nGive me a number please....");
        scanf("%d",&num[i]);
    }
    printf("++++++++++\n");

    for (i=19;i>=0;i--)
      {
          printf("The %d number is %d\n",i+1,num[i]);
      }
    printf("++++++++++");
    return 0;
}
