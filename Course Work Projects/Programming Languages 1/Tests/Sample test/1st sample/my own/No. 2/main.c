#include <stdio.h>
#include <stdlib.h>
isodd(int number);
int main()
{
    int num,noofeven=0,noofodd=0;
    do{
        printf("\nGive a number...");
        scanf("%d",& num);
        if (num==0)
            break;
        if (isodd(num))
           {
                printf("%d is an odd number",num);
            noofodd++;
           }
        else{
                printf("%d is an even number",num);
            noofeven++;}



    } while (1);

    printf("The number of even numbers :-%d \n The number of odd numbers :-%d",noofeven,noofodd);

    return 0;
}

int isodd(int number){
    if (number%2==0)
        return 0;
    else
        return 1;

}
