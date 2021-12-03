/*** Example of bit operations ***/
#include<stdio.h>
//Program increments a number in binary and prints it out in decimal form
int increment(int n){
    int mask=1;

    int m;
    while(1){
        m=n&mask;
        if (m!=0){
            n=n&(~mask);

        }else{
            n=n|mask;
            break;

        }
        mask<<=1;

    }

return n;

}
int main(){
  int n,m;
  printf("Give me a number...");
  scanf("%d",&n);

  printf("%d",increment(n));

  return 0;
  }

