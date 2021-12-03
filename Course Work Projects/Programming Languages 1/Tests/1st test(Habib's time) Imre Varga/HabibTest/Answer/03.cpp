#include <stdio.h>
#include <stdlib.h>

int main()
{
	int lower=0,upper=0,i;
    int str[50];
    printf("Give a string...");
    scanf("%s",str);
    for (i=0;str[i] !='\0';i++){
    	if ((str[i] >= 'A') && (str[i] <= 'Z'))
    		upper++;
    	else if ((str[i] >= 'a') && (str[i] <= 'z'))
    		lower++; 	
	}
	if (lower>upper)
		printf("\nOutput: lowercase");
	else if (lower<upper)
		printf("\nOutput: uppercase");
	else
		printf("\nOutput: equal");
    
    return 0;
}

