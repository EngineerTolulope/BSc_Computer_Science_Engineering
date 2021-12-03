#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void calculate(float r,float *area, float *circum){
	*area=r*r*3.14;
	*circum=2*3.14*r;
}
int main(int argc, char *argv[]) {
	float r,a,c;
	printf("Give me a number...");
	scanf("%f",&r);
	calculate(r,&a,&c);
	printf("The area of the circle is %.2f\nThe circumference of the circle is %.2f",a,c);
	
	return 0;
}
