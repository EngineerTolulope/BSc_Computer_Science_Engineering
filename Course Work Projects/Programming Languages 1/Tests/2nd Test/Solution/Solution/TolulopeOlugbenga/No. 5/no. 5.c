#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;
	FILE *f;
	f=fopen("out.txt","wt");
	while (1){
		
		printf("Give me a number please...");
		scanf("%d",&num);
		if (num>10&&num<20){
			fprintf(f,"%d\n",num);
		}
		if (num==0){
			break;
		}
	}
	fclose(f);
	return 0;
}
