#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(){
   DIR *d;//directory pointer
    struct dirent *entry;//we make a pointer of the dirent structure in dirent.h header file
    //places a directory in the directory pointer d
    d=opendir("C:\\Windows");//"." represents current directory, ".." is the previous directory
    do{
        entry=readdir(d);//read one item from directory to entry, one at a time
        if (entry==NULL) break;//if it couldn't read anything then break
        printf("%s\n",(*entry).d_name);//print the item coppied from the directory in line 11, and add a new line


    }while (1==1);
    closedir(d);//closes the directory

   return 0;
   }
