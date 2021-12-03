#include <stdio.h>
#include <string.h>

int main()
{
   int i,howmany,total=0;
   float average=0.0;
   int * numbers;
   char movie[20];
  /* puts("Type the name of the fucking movie:-");
  fgets(movie,20,stdin);// learning how to fit the amount into the array so program won't crash, so it reduces it to 20 no matter what
   printf("%s",&movie);*/
   printf("\nHow many fucking numbers do you want the average and total of:-");
   scanf("%d",&howmany);

   numbers =(int *)malloc(howmany*sizeof(int));//The heap statement to reserve some memory for numbers
   for (i=0;i<howmany;i++)
   {
       printf("Give me a number:-");
       scanf("%d",&numbers[i]);
       total+=numbers[i];
   }
   average= (float)total/howmany;
   printf("The total numbers is :-%d\n Average number is :-%.2f",total,average);
    return 0;
}
