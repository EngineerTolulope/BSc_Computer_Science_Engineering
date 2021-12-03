#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int i,amount,num,sum=0;
    fp=fopen("in.txt","rt");//We are reading a text why we use rt
    fscanf(fp,"%d",&amount);
    for (i=0;i<amount;i++){
        fscanf(fp, "%d",&num);
        sum +=num;
    }
    printf("The average is:-%.2f",sum/(float)amount);



    fclose(fp);
    return 0;
}
