#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    fp=fopen("simple.txt","w");
    fprintf(fp,"It always simple never hard because everything can be simplified\n");
    fclose(fp);
    return 0;
}
