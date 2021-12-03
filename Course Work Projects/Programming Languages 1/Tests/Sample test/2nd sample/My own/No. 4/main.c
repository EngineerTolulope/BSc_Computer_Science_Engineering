#include <stdio.h>
#include <stdlib.h>

struct entry{
  char brand[30];
  char type[20];
  int year;

};
int main()
{
    int age1, age2;
    struct entry first,second;
    printf("What is the brand of the first car:- ");
    scanf("%s",first.brand);
    printf("What is the type of the first car:- ");
    scanf("%s",first.type);
    printf("What is the year of the first car:- ");
    scanf("%d",&first.year);
    printf("What is the brand of the second car:- ");
    scanf("%s",second.brand);
    printf("What is the type of the second car:- ");
    scanf("%s",second.type);
    printf("What is the year of the second car:- ");
    scanf("%d",&second.year);
    age1= 2015-first.year;
    age2= 2015-second.year;
    if (age1==age2){
        printf("%s %s:- %d\n",first.brand,first.type,age1);
        printf("%s %s:- %d",second.brand,second.type,age2);

    }
    else if (age1>age2)
                printf("%s %s:- %d",first.brand,first.type,age1);
   else
      printf("%s %s:- %d",second.brand,second.type,age2);





    return 0;
}
