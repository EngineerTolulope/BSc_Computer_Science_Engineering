#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num;
  do{
    printf("Give a number...");
    scanf("%d",&num);

    if (num!=0){if (num%2==1) printf("Odd\n");
    else printf("Even\n");break;}
  }while(num!=0);
  return 0;
}
