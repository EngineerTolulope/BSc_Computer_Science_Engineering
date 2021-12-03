/*** Example of low-level file usage ***/
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BlockSize 1024//Makes a constant
int main()
{
   char buff[BlockSize];//just an array of 1024 characters
   int in,out;
   int nread;

   in= open("main.c",O_RDONLY);//opens file for read only
   out=open("Apple.txt",O_WRONLY|O_CREAT|O_TEXT|O_TRUNC,S_IRUSR|S_IWUSR);//we write to a file
   while((nread=read(in,buff,BlockSize))>0){//reads the in pointers file, and stores it in an array buff
        //nread gets the number of characters in the file
        //returns a value 0 if it is empty, BlockSize represents the maximum number of characters to be read ,"1024"
      write(out,buff,nread);//writes what was read to the out pointer's file, from the buff array
      //nread here represents the maximum number of characters to be written

   }
   close(in);//closes the files
   close(out);

   return 0;



}
