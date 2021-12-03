#include <stdio.h>
#include <stdlib.h>

int main()
{
    int jay, dash, i;
    printf("Enter Length: ");
    scanf("%d", &jay);
    printf("+");
    for(i=1; i<jay-1; i++){
        printf("-");
    }
    puts("+");
 //printf("Hello world!\n");
    return 0;
}
