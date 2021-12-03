#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(){
   int N=0, rnum;
   DIR* d;
   struct dirent *entry;
   srand(time(NULL));
   d=opendir("C:\\Windows");
   do{
     entry=readdir(d);
     if(entry==NULL) break;
     N++; // it gets the number of files in the directory by incrementing this after reading
     }
   while(1);
   closedir(d); // we close and open the directory, so we can reset the readdir(d)
                //to start reading from the beginning again

    rnum = rand()%N + 1;
    printf("Random Number between %d and %d is :- %d",1,N,rnum);


   /*int i=0;
   d=opendir("C:\\Windows");
   do{
     entry=readdir(d);//read a file from directory
     if(entry==NULL) break;//if the directory is empty break
     if(i==rnum) {//trying to only enter the loop when we read, the random number rnum
            printf("%s\n",(*entry).d_name);//we print the directory at the random number rnum
            break; // we are done, so we break
     }
     i++;// increments the value until we reach rnum
     }
   while(1);
   closedir(d); */

   return 0;
   }
