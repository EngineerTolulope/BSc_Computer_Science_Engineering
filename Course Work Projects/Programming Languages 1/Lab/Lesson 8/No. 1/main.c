#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    FILE *fp;//we need to create a file pointer
    fp=fopen("mult.txt","wt");//we use wt because we want to write text but if we want binary we use wb
    for (i=1;i<11;i++){
        for (j=1;j<11;j++){

                        fprintf(fp,"%2d x %2d =%3d\n",j,i,j*i);//we print it to the address of the file fp

        }
    }
    fclose(fp);//we need to close the file so it can be saved
    return 0;
}
