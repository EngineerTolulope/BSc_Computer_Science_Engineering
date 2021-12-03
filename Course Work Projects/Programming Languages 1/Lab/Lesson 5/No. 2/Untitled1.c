#include <stdio.h>
#include <stdlib.h>

void printRev(char str[100]){
	int i, posEOS;

	//find the position (index) of the '\0' (EOS)
	for (i=0;i<100;i++){
		if (str[i]=='\0') {
			posEOS=i;
			break;
		}
	}

	//printf(str);//printf("%s", str);
	//print out the reversed string
	for (i=posEOS-1; i>=0 ;i--){
		printf("%c", str[i]);
	}
	return;
}//printRev



int main(int argc, char *argv[]) {
	char str[100];
	int i, posEOS;

	//read in a string
	printf("Give a string... ");
	scanf("%s", str); //for strings the & operator is not needed

	printRev(str);

	return 0;
}
