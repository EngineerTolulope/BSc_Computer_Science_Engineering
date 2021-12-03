#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int positive(int num){
	if (num>0) return 1;
	else
	  return 0;
	
} 









int main(int argc, char *argv[]) {
	int num,noofpositive=0;
   do{
   	printf("Give me a number...");
   	scanf("%d",&num);
   	
   	
   	if (positive(num)){
   		noofpositive++;
   		
   	}
   	
   	
   	if (num==0){
   		printf("Number of positive numbers:- %d",noofpositive);
   		break;
   		
   		
   	}

   }while(1);	
	
	
	return 0;
}
