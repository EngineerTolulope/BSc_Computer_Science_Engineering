#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, a[20];
    int sum=0, lnum;
    FILE *f;
    f=fopen("in.txt","rt");
    lnum=fscanf(f,"%d",&lnum);
    printf("The numbers are:-");
    printf("%d",lnum);
    sum+=lnum;
    for  (i=0;fscanf(f,"%d",&a[i])!=EOF;i++){
        printf(" %d ",a[i]);

        sum+=a[i];
        if (a[i]>lnum){
            lnum=a[i];
        }

    }
   printf("\nThe largest number read to the screen is:- %d",lnum);
    printf("\nThe sum of the numbers is :- %d",sum);



    fclose(f);
    return 0;
}
