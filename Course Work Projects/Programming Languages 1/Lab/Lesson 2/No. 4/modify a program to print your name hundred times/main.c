#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[]="Oluwaseun Tolulope David Emmanuel Sunday Chairman Oladipo Olugbenga", yourname[20],ans[5];
    int a=0;
    printf("(Yes/No)Are you Mr. %s\n Answer Here:-",name);
    scanf("%s",&ans);
    if (strcmp(ans,"no")==0)
    {
        printf("Type your name please:-");
        scanf("%s",&name);
    }
    for (;a<100;a++)
    {
        printf("\nYour name is Mr(s) %s\n", name);
    }



    return 0;
}
