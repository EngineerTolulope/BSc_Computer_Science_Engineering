#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, num[20];
	for (i=0;i<20;i++){
		printf("Give me a number...");
		scanf("%d",&num[i]);
		
		
		
		
	}
	
	for (i=19;i>=0;i--){
	
		if (num[i]<20){
			printf("%d ",num[i]);
			
			
		}
		
		
		
	}
	
	
	
	return 0;
}
