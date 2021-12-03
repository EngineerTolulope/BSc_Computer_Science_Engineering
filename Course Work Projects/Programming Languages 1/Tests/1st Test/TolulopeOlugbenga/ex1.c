#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int day;
	printf("Give me a number....");
	scanf("%d",&day);
	
	switch(day){
		
		case 1: printf("\nMonday");break;
		case 2: printf("\nTuesday");break;
		case 3: printf("\nWednesday");break;
	    case 4: printf("\nThursday");break;
		case 5: printf("\nFriday");break;
		case 6: printf("\nSaturday");break;
		case 7: printf("\nSunday");break;
		default: printf("\nNo such day in a week");break;
		
		
	
	}
	
	
	
	
	return 0;
}
