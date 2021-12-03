#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Function that returns 1 if the number is prime
//and 0 if it is a prime
int isPrime(int num){ //ex 3
	int i;
	if ((num==1) || (num==0)) return 0;// 1 is not prime
	for(i=2;i<=num/2;i++){
		if (num%i==0) return 0;
	}
	return 1;
}//isPrime

int main()
{
  int limit, i;

  printf("Give a number...");
  scanf("%d",&limit);

  for (i=2;i<=limit;i++){
    if (isPrime(i)) printf("%d\n",i);
  }//for
    return 0;
}
