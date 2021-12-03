#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isnegative(num){
	if (num<0) return 1;
	else
	return 0;
}
int main(int argc, char *argv[]) {
	int num[15];
	int i,nafisa,hannah;

	for (i=0;i<15;i++){
		printf("Give me the %d number...",i+1);
		scanf("%d",&num[i]);
	}
	for (i=0;i<15;i++){
		if (isnegative(num[i])){
	      nafisa=num[i];
	      hannah=i;
		  break;		
		}
	}
	
	for (i=hannah;i<15;i++){
		if (isnegative(num[i])){
	     		if(num[i]>nafisa)
	     		nafisa=num[i];
		}
	}
	if (nafisa==1){
		printf("There is no negative number");
	}
	else{printf("The largest negative number is %d",nafisa);
	}
	
	return 0;
}
