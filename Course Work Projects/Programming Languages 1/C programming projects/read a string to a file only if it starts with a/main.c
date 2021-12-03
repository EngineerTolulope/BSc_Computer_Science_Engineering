#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int sure(char *s){
if (s[0]=='a'){
    return 1;
}
else
    return 0;
}

int main()
{
    FILE *fp;
    fp=fopen("out.txt","at");
    char str[100];
    int i=0;
    while(i<7){

        printf("Give me a string...");
        gets(str);
        if (sure(str))
            fprintf(fp,"%s\n",str);
    i++;
    }
    fclose(fp);
    return 0;
}
