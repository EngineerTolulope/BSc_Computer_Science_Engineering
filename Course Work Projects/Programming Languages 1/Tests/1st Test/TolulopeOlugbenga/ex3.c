#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int even(int num){
	if (num%2==0) return 1;
	else
	return 0;	
	
}



int main(int argc, char *argv[]) {
	int i,num[30],evensum=0,oddsum=0;
	for (i=0;i<30;i++){
		printf("The %d number is: ", i+1);
		scanf("%d",&num[i]);
		
		
	}
	for (i=0;i<30;i++){
	   if (even(num[i])){
	   	evensum+=num[i];
	   }
	   else
	    oddsum+=num[i];
		
	}
	printf("Even sum:-%d\nOdd sum:-%d",evensum,oddsum);
	
	
	return 0;
}
