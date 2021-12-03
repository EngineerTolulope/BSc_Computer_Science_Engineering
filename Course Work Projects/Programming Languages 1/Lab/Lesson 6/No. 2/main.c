#include <stdio.h>
#include <stdlib.h>

int isuppercase(char c){
if ((c<=90)&&(c>=65)) return 1;// or we can use if ((c<='Z')&&(c>'z')) from 90 to 65 is where we have capital letters
return 0;



}
char tocapital(char c){
return c-32; // or c-('a'-'A')

}
int main()
{
    int i;
    char str[100];
    printf("Give a string...\n");
    gets(str);

    for(i=0;str[i]!='\0';i++){
        if (isuppercase(str[i]))
        printf ("%c",str[i]);
        else
            printf("%c", tocapital(str[i]));
    }
    return 0;
}
