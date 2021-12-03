#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{double t,p;
    int a,b,c;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("c=");
    scanf("%d",&c);
    if (a+b>c&&b+c>a&&a+c>b)
        {printf("the triangle can be constructed\n");
          p=(a+b+c)/2;
          t=sqrt(p*(p-a)*(p-b)*(p-c));
          printf("t=%.2lf",t);
          }
    else
        printf("the triangle cannot be constructed\n");


    return 0;
}
