/*** Example of low-level file usage ***/
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BlockSize 1024//Makes a constant
int main()
{
    char buff[BlockSize];
   int in,out;
   int nread;
   //int x=(65<<8)|66;
    int x;
    int a[10];
   //in= open("main.c",O_RDONLY);
   out=open("Apple3.txt",O_WRONLY|O_CREAT|O_TEXT|O_TRUNC,S_IRUSR|S_IWUSR);

   //while((nread=read(in,buff,BlockSize))>0)
    for (x=0;x<10;x++){
        a[x]=rand()%1000000;//stores random numbers in array

    }
    write(out,a,sizeof(a));//write prints the random numbers from the array  as characters
    //write(out,&x,sizeof(int));

   //close(in);
   close(out);

   return 0;



}
