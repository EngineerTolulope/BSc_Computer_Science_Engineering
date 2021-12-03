#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;

	printf("Give a number... ");
	scanf("%d", &num);

	switch (num){
		case 7:
		case 8:
	    case 9:
		case 10:
		case 11:
		case 12: printf("morning\n");break;
		case 13:
		case 14:
		case 15:
	    case 16:
		case 17: printf("afternoon\n");break;
		case 18:
		case 19:
		case 20: printf("evening\n");break;
		case 1:
	    case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 21:
		case 22:
	    case 23:
		case 24: printf("night or dawn\n");break;
		default: printf("Wrong number...");
	}//switch
	system("pause");


	return 0;
}
