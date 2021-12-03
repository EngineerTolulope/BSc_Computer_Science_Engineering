#include <stdio.h>
#include <stdlib.h>

int main()
{
    char girlfriend[20];
    char answer[5];
    char ans[4];
    printf("Are you a boy or a girl(boy/girl):-");
    scanf("%s",&ans);
    while (strcmp(ans, "boy")==0)
        {printf("\nSorry no room for you here, Babes only!!!\n");
        printf("\nAre you a boy or a girl(boy/girl):-");
        scanf("%s",&ans);
        }

    {


    printf("\nAre you Tboy's girlfriend?\n");
    scanf("%s", &answer);
    while (strcmp(answer, "no")==0)
        {printf("\nWhat are you doing here please use the Gate now\n");
          printf("\nAre you Tboy's girlfriend?\n");
          scanf("%s", &answer); }

           printf("\nLet me know if you are lying\n");
           printf("\nI will find out now\n");
           printf("\nok!!! what is your name(please no spaces!!!):-");
           scanf("%s",&girlfriend);
           while ((strcmp(girlfriend, "gift")==0)||(strcmp(girlfriend, "boliah")==0)||(strcmp(girlfriend, "giftboliah")==0)||(strcmp(girlfriend, "giftvivan")==0)||(strcmp(girlfriend, "boliahgift")==0)||(strcmp(girlfriend, "boliahvivan")==0)||(strcmp(girlfriend, "vivanboliah")==0)||(strcmp(girlfriend, "vivangift")==0))
            {
                printf("\n");
                printf("Fuck you, you are not T-boy's girlfriend, Use the gate now\n");
                printf("\nNext please");
                printf("\nWhat is your name (please no spaces!!!) :-");
                scanf("%s",&girlfriend);}


            printf("\n");printf("\n");printf("\n");
               printf("Ok you are right, you are T-boy's girlfriend\n");
               printf("\nHas anyone told you that you are beautiful\n");
               printf("\nOK, T-boy said i should tell you that you are beautiful\n");
               printf("\n");




       }
       return 0;
    }



