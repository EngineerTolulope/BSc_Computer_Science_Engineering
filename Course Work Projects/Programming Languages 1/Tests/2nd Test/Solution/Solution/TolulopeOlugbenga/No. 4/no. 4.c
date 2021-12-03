#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct info{
	char firstname[30];
	char lastname[30];
	int test1,test2;
};
int main(int argc, char *argv[]) {
	struct info p1,p2;
	int a=0,b=0;
	printf("Give me the first name of the 1st person..");
	scanf("%s",p1.firstname);
   printf("Give me the last name of the 1st person..");
   	scanf("%s",p1.lastname);
    printf("Give me the score of the 1st test of the 1st person..");
    scanf("%d",&p1.test1);
	printf("Give me the score of the 2nd test of the 1st person..");
	    scanf("%d",&p1.test2);
   printf("Give me the first name of the 2nd person...");
   	scanf("%s",p2.firstname);
	printf("Give me the last name of the 2nd person...");
		scanf("%s",p2.lastname);
   printf("Give me the score of the 2nd test of the 2nd person..");
    scanf("%d",&p2.test1);
   printf("Give me the score of the 2nd test of the 2nd person..");
    scanf("%d",&p2.test2);
    a=p1.test1+p1.test2;
    b=p2.test1+p2.test2;
    if (a>b){
    	printf("Better result: %s %s - %dp",p1.firstname,p1.lastname,a);
    }
    else if(b>a){
    	    	printf("Better result: %s %s - %dp",p2.firstname,p2.lastname,b);

    }
    else{
             	printf("it was a tie\n");
    	    	printf("1st result: %s %s - %dp\n",p1.firstname,p1.lastname,a);
    	        printf("2nd result: %s %s - %dp",p2.firstname,p2.lastname,b);

    }

	return 0;
}
