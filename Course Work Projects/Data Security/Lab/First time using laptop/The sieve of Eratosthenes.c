/*

The sieve of Eratosthenes.

Give all primes p below a given bound C.

*/

#include <stdio.h>

void eratosthenes(int size)
{
    int i, j;


	/*creating the number's array which are smaller than the given bound*/
	int a[size];
	for(i = 0; i < size; i++)
		a[i]=i+1;

	/*deleting (setting 0) the multiplies of a prime)*/
	for(i = 1; i < sqrt(size); i++)
		if(a[i]!=0)
			for(j=2*a[i]; j < size; j=j+a[i])
				a[j-1] = 0;

	/*output the primes below a given bound*/
	for(i = 1; i < size-1; i++)
		if(a[i]!=0)
			printf("%d, ", i+1);

	return;
}

int main()
{
    int num;
    printf("The sieve of Eratosthenes.\n\n");
    printf("Give me an integer as a bound: ");
	scanf("%d",&num);
    printf("The primes below %d: \n", num);
	eratosthenes(num);

	return 0;
}
