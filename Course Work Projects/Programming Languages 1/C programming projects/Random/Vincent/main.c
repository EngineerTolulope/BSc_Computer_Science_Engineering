#include <stdio.h>
#include <stdlib.h>
/*Write a program that displays a
rectangle from characters "-".
The corners are drawn with character
"+", the left and right side with "|".
The width and the height are user inputs.
E.g., if the user enters 10 and 5,
the program displays

+--------+
|--------|
|--------|
|--------|
+--------+
*/
int main()
{
    int column,row;
    printf("column: ");
    scanf("%d",&column);
    printf("row: ");
    scanf("%d",&row);
    int i,j;
    char simple[row][column];
  /*  printf("+");
    for (i=1;i<length-1;i++){
        printf("-");
    }
    printf("+");*/
    simple[0][0]='+';
    simple[row-1][0]='+';
    simple[0][column-1]='+';
    simple[row-1][column-1]='+';

    for (i=1;i<row-1;i++){
        simple[i][0]='|';
        simple[i][column-1]='|';
    }
    for (i=0;i<row;i++){
        for (j=1;j<column-1;j++){
            simple[i][j]='-';
        }
    }
    for (i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("%c",simple[i][j]);
        }
        printf("\n");
    }
    return 0;
}
