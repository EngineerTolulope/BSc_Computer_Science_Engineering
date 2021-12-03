#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[100];
	int i, posEOS;
	
	printf("Give a string... ");
	scanf("%s", str);
	
	for (i=0;i<100;i++)
		if (str[i]=='\0') {
			posEOS=i; 
			break;
		}	
	
	for (i=posEOS-1; i>=0; i--){
		if (str[i]=='a') printf("+");
		else printf("%c", str[i]);
	}
	
	
	return 0;
}
