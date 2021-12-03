#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp= fopen("out.txt","at");
    int num;
    do{
        printf("Give me a number...");
        scanf("%d",&num);
        if (num==0) break;
        else if (num%2==0){
            fprintf(fp,"%d\n",num);
        }

    }while(1==1);
    fclose(fp);
    return 0;
}
