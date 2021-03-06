/*** Example of bit operations ***/
#include<stdio.h>

int main(){
  int n,m;
  printf("Give me a number...");
  scanf("%d",&n);
  int i=1<<31;//shifting 1 by 31 places makes 0000....00001 to be 1000.....00000 which represents it in 4 bytes
        //or i= 1<<(sizeof(int)*8-1)    size of int is 4
  do{
    m= n&i;//it checks the number at that bit, if the bit is 1  m is 1, else viceversa
    if (m!=0)
       printf("1");
    else
        printf("0");

    i=i>>1;//shift i by one bit to the right
    i=i&(~(1<<31));//when we shift to the right, the sign bit still remains this changes the sign bit to 0
    // ~(1<<31) = 01111111.....11111111
  }while(i!=0);

  return 0;
  }

