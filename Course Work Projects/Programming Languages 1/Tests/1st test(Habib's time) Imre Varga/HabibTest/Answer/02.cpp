#include <stdio.h>
#include <stdlib.h>

void iloveweed(int n){
	int i;
	for (i=0;i<n;i++)
		printf("+");
	
	
}
int main()
{
    int n;
    printf("Give me a number...");
    scanf("%d",&n);
    do{
    	iloveweed(n);
    	printf("\nGive me a number...");
    	scanf("%d",&n);
    	if (n==0) break;
	}while(1);
    return 0;
}

