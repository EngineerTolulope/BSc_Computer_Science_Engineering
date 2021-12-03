#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char first[50],second[50];
	int last=0,i,j,lastly=0,k,p;
	printf("Give me the first string:- ");
	scanf("%s",first);
	printf("Give me the second string:- ");
	scanf("%s",second);
	
	for (i=0;i<50;i++){
			if (first[i]=='\0'){
				lastly=i;
				break;
			}	

		
	}
		for (k=0;k<lastly;k++){
		   
		    	
		    	if (first[k]=='e'){
				printf("%d",3);
			}
			else{
				printf("%c",first[k]);
				
			}	
		    	
		}
		
		
	
	
	for (j=0;j<50;j++){
	
			if (second[j]=='\0'){
				last=j;
				break;
			}	
		
	}
	printf("\n");
	for (p=last-1;p>=0;p--){
	
			printf("%c",second[p]);	
		
	}
	
	
	return 0;
}
