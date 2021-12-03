#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar[40];
	int i;
	ar[0]=0;
	ar[1]=1;
    for (i=2;i<40;i++){
        ar[i]= ar[i-1] + ar[i-2];
    }
    printf("Output:-");
    for (i=0;i<40;i++){
        printf("%d ",ar[i]);

    }
    return 0;
}

