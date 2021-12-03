#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nums[20];
	int i;
	
	for(i=0;i<20;i++){
		printf("Give a number... ");
		scanf("%d", &nums[i]);
	}
	
	printf("++++++++++\n");
	for(i=19;i>=0;i--)
		printf("%d\n", nums[i]);
	printf("++++++++++");
	
	return 0;
}
