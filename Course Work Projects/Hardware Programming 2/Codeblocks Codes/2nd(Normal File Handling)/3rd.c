#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int sum=0,num;
    FILE *f,*e,*o;
    f=fopen("in.txt","r+");
    //e=fopen("Even.txt","w+");
    //o=fopen("Old.txt","w+");
    if (f==NULL ){
        fprintf(stderr, "ERROR!!!");
        return 1;//Indicating The Program Can Stop,A problem exists
    }
    while (1){
        fscanf(f,"%d",&num);
        if (feof(f)) break;
        else if (num==6){
            fseek(f,-1,SEEK_CUR);//this function moves the cursor to position of the middle parameter
            //if we use -1, we move the current cursor back by 1, we use 1, we move forward by 1
            Sleep(1000);//This makes the program to wait 1000ms when executing
            fprintf(f,"0");//and it writes 0, it overwrites the number there
            break;
        }
        //else if(num%2==0)
          //  fprintf(e,"%d ",num);
        //else
          //  fprintf(o, "%d num);
    }

    fclose(f);
    //fclose(e);
    //fclose(o);
    return 0;
}
