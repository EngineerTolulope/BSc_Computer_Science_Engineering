#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,arr[20],even=0,odd=0;
	for(i=0;i<20;i++){
		printf("give me a number please..");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<20;i++){
		if (arr[i] %2 ==0){
			even = arr[i];
			break;
	}
}
     for(i=0;i<20;i++){
		if (arr[i] %2 !=0){
			odd = arr[i];
			break;
	}
}
     for (i=0;i<20;i++){
       	if (arr[i]%2==0){
       		if(arr[i]< even)
       		 even = arr[i];
		   }
		   else{
		   	if (arr[i] > odd)
		   	odd= arr[i];
		   }
	 }
printf("smallestEven:%d\nlargestOdd %d", even, odd);
	
	return 0;
}
