#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Give me the time in  hours that we are in now:-");
    scanf("%d",&num);
    switch (num){
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12: printf("Morning");break;
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:printf("Afternoon");break;
    case 18:
    case 19:
    case 20:printf("Evening");break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 21:
    case 22:
    case 23:
    case 24:printf("Night or dawn");break;
    default : printf("No hour like that");



    }
    return 0;
}
