#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *f;
	f=fopen("in.txt","rt");
	int sum=0,num;
	while (fscanf(f,"%d",&num)!=EOF){
		sum+=num;
	}
	printf("Sum : %d",sum);
	fclose(f);
	return 0;
}
