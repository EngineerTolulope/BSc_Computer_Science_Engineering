#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printrev(char str[100]);
int main()
{    char str[100];

    printf("Give me a string:-");
    scanf("%s",str);

    printrev(str);

    return 0;
}

void printrev(char str[100]){
int i,posEOS;

    for (i=0;i<100;i++){
        if (str[i]=='\0') {
			posEOS=i;
			break;
		}

    }
    for (i=posEOS-1;i>=0;i--){//posEOS-1 because we want to eleminate the \0 part
        if (islower(str[i]))
            printf("%c",str[i]);
    }



return;
}



