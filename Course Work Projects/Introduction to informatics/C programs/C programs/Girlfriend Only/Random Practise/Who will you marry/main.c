#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char firstname[35];
    char crush[35];
    int numberofbabies;
    char sentence[100] ="";
    puts("What is your name?");
    gets(firstname);

    puts("Who are you going to marry?");
    gets(crush);

    printf("How many kids would you have? \n");
    scanf("%d", &numberofbabies);

    strcat(sentence,firstname);
    strcat(sentence," and ");
       strcat(sentence,crush);
          strcat(sentence," are going to get married and will have ");

    printf("%s %d children",sentence,numberofbabies);








    return 0;
}
