#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
int main(){
    FILE *fp;
    int i;
    fp=fopen("out.txt","at");
    char str[100];
    do{
        printf("Give me a string...");
        scanf("%s",str);
        if (str[0]=='0')
            break;
        for (i=0;str[i]!='\0';i++)
        {
            if (islower(str[i])){
                str[i]+=-32;
            }

        }
        fprintf(fp,"\n%s",str);


    }while(1==1);
    fclose(fp);


return 0;
}
