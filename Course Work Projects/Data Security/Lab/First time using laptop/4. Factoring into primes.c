#include <stdio.h>
#include <stdlib.h>

//Factoring into primes
int main()
{
    int pfact[] = {2,3,5,7,11,13,17,19,23,29};
    int num, i=0;
    printf("Give me a number... ");
    scanf("%d", &num);
    num= num%29;

    //int primf[10];
    while (1){
        if (num%pfact[i]==0){
            if (i == 10) break;
            //primf[i]=pfact[i];
            num/=pfact[i];
            printf("%d ", pfact[i]);
            continue;
        }else {
            if (i == 10) break;
            i++;
            continue;
        }
    }
   /* for (i=0;i<10;i++){
        printf("%d ", primf[i]);
    }*/
    return 0;
}
