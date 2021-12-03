#include <stdio.h>
#include <stdlib.h>
int main(){
 int a, b, c, *p1;
 int *p2, *p3, **p4;
 a=3; b=4; c=5;

 p1=&a; p2=&b; p3=&c;

printf("*p1: %d, *p2: %d, *p3: %d\n", *p1, *p2, *p3);

 p2=p1;

 printf("*p1: %d, *p2: %d, *p3: %d\n", *p1, *p2, *p3);

 *p2=*p3;

 printf("*p1: %d, *p2: %d, *p3: %d\n", *p1, *p2, *p3);

 p4=&p3;

 printf("*p3: %d, *p4: %d, **p4: %d\n", *p3, *p4, **p4);



 return 0;
}//main
