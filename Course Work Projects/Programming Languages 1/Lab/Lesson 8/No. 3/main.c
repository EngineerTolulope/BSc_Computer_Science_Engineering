#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int counter=0,sum=0,num;
    fp=fopen("in2.txt","rt");
    while(fscanf(fp,"%d",&num)!=EOF/*Meaning end of file*/){

        sum+=num;
        counter++;

    }
    printf("Sum:- %d\n",sum);
   printf("Average:- %.2f\n",(float)sum/counter);

    fclose(fp);
    return 0;
}
