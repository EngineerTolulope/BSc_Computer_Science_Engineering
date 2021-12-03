#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

  int a,b,c;
  puts("a=");
  gets(a);
  puts(a);
   printf("\nb=");
  scanf("%d", & b);
   printf("\nc=");
  scanf("%d", & c);

  printf("The sides of the triangle are a:%d\n, b:%d\n, c:%d\n",a,b,c);
  if (a+b>c&&b+c>a&&c+a>b)
    printf("They can form a triangle...\n");
    else
    printf("The triangle cannot be formed");

  return 0;
}
