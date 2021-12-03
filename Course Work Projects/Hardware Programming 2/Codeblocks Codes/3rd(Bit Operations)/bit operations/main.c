/*** Example of bit operations ***/
#include<stdio.h>

int main(){
  char c, d;

  c=1;
  c=c<<6;
  printf("%c",c+1);

  c=c&255;
  printf("%c",c+1);

  c=191;
  c=~c;
  printf("%c",c+1);

  c=128>>1;
  c=c^0;
  printf("%c",c+1);

  c=64|1;
  printf("%c\n",c);

  return 0;
  }
