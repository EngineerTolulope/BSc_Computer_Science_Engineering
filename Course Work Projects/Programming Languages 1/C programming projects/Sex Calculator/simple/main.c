#include<stdio.h>
int main()
{
int number,agesexnumber,presentyear, difference,ans,yeardiff;
char answer[5];
printf("Type the numbers of times you want to have sex this month:-");
scanf(" %d" ,& number);
while (number>=10||number==1||number==0)
  {printf("\nSorry the number should be between 1 and 10\n");printf("\n");printf("\n");
   printf("Please type a new number between 1 and 10:-");
   scanf(" %d" ,& number);
   }


agesexnumber= (number*2)+5;
agesexnumber= agesexnumber*50;
printf("\nWhat year are we in now:-");
scanf(" %d",&presentyear);
difference=presentyear%2015;
printf("\nWhich year were you born(be truthful):-");
scanf(" %d", &ans);
agesexnumber=agesexnumber+1765+difference;
yeardiff=agesexnumber-ans;

printf("\nHave you celebrated your birthday this year(be truthful):-");

scanf(" %s",answer);
printf("\n"); printf("\n");printf("\n");

if (strcmp(answer,"no")==0)
    {
      printf("Look at this number closely:-%d\n",yeardiff-1);
      printf("\nThe number is a 3 digit number\n");
      printf("\nThe first digit is the number of sex you want to have\n");
      printf("\nThe last two digits is your age\n");

    }
else
     {
      printf("\nLook at this number closely:-%d\n",yeardiff);
      printf("\nThe number is a 3 digit number\n");
      printf("\nThe first number is the number of sex you want to have\n");
      printf("\nThe last two digits is your age\n");

    }


return 0;
}
