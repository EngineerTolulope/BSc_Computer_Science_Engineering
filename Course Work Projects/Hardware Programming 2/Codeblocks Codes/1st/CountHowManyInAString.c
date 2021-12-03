#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenate(char imref[],char imrel[],char total[]){
    int i=0;
    while(imref[i]!='\0'){
        total[i]=imref[i];
        i++;
    }
    total[i]=' ';//adding a space between the two strings
    i++;//so we don't overwrite the space in the next while loop, we move to the next position
    int j=0;// j is from beginning of 1st loop
    while(imrel[j]!='\0'){
        total[i]=imrel[j];
        i++;
        j++;
    }
    total[i]='\0';//represents this is the last char in the string
    return;
}
int main()
{
    int i;
    char imref[30],imrel[30],total[50];
    puts("Give Me A String");
    scanf("%s %s",imref,imrel);//This simple means scanf should store a string in one place then after a space store the second string
    concatenate(imref,imrel,total);
    //strcpy(total,imref);//This copies the imref to the total string
    //strcat(total," ")//We include a space in the total string
    //strcat(total,imrel);//We join the imrel string to the total string
    for (i=0;total[i]!='\0';i++);
    printf("\"%s\" Has %d Characters",total,i);
    return 0;
}
