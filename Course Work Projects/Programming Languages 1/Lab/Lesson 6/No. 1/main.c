#include <stdio.h>
#include <stdlib.h>

void printrev(char s[100]){
  int i,end;

  for (i=0; s[i]!='\0';i++);
  end=i;

  for (i=end-1;i>=0;i--){
    printf("%c",s[i]);
  }





return;
}



int main()
{
    char str[100];
    printf("Give me a string...\n");
    gets(str);//gets fuction takes all the line including spaces
    printrev(str);

    return 0;
}
