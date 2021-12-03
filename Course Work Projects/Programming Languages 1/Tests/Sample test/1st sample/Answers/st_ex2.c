#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isOdd(int number){ //logical function (returns 0 or 1)
	if (number%2==0) return 0;
	return 1;
	//return number%2;
}


int main(int argc, char *argv[]) {
	int n, evens=0, odds=0;
	
	while(6==6){
		printf("Give a number... ");
		scanf("%d", &n);

		if (n==0) break;
		
		if (isOdd(n)) odds++;
		else evens++;
	}//while
	
	printf("%d numbers were even\n", evens);	
	printf("%d numbers were odd", odds);	
	
	return 0;
}
