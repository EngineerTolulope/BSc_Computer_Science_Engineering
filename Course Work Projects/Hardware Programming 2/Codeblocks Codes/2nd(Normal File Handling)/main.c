#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0,num;
    FILE *f;
    f=fopen("in.txt","r+");
    while (1){
        fscanf(f,"%d",&num);
        if (feof(f)) break;//if we don't reach the end of file
        printf("%d ",num);
        sum+=num;

    }
    fprintf(stdout,"%d",sum);//print out to the screen "stdout"
    fclose(f);
    return 0;
}
