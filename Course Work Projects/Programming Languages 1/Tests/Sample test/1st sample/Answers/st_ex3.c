#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numbers[30];
	int i, sum=0;
	double avg;
	
	for(i=0;i<30;i++){
		printf("Give a number... ");
		scanf("%d", &numbers[i]);
	}
	
	for (i=0;i<30;i++)
		sum+=numbers[i]; //sum = sum + numbers[i];
	
	avg=sum/30.0;
			//remember:
			//5/2   ->    2
			//5/2.0  -> 2.5
	
	printf("The sum is %d\n", sum);
	printf("The average is %.2lf\n", avg);
	
	return 0;
}
