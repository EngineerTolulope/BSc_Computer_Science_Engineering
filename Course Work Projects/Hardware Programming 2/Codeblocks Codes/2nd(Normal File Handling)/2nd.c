#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0,num;
    FILE *f,*e,*o;
    f=fopen("in.txt","r+");
    e=fopen("Even.txt","w+");
    o=fopen("Odd.txt","w+");
    if ((f==NULL )||(e==NULL)||(o==NULL)){
        fprintf(stderr, "ERROR!!!");
        return 1;//Indicating The Program Can Stop,A problem exists
    }
    while (1){
        fscanf(f,"%d",&num);
        if (feof(f)) break;
        else if(num%2==0)
            fprintf(e,"%d ",num);
        else
            fprintf(o, "%d ",num);
    }
    fclose(f);
    fclose(e);
    fclose(o);
    return 0;
}
