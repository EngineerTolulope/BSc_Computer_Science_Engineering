#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(){
    FILE *f;
    f=fopen("nums.txt","r+");
    int num[10];//array to store numbers
    int i,mask=1;//mask = 1, if you and a number with 1, and the result is not zero, LSB = 1
    for (i=0;i<10;i++){
        fscanf(f,"%d",&num[i]);//copys numbers into an array
    }
    int count=0;
    for (i=0;i<10;i++){
        if ((num[i] & mask) == 1) //if the and is 1 then, LSB =1
            count++;//we count how many LSB =1
    }
    if (count == 0){//if no LSB ==1 then
        printf("ALL");
    }
    else
        printf("NOT ALL");
    fclose(f);
   return 0;
   }
