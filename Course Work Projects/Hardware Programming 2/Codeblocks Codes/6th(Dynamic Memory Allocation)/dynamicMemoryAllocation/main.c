#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Size=1,i=0;
     int A[1000];
    int *B=(int*)malloc(Size*sizeof(int));//allocate an array for 1 element int B[0];because Size is 1
    //int *C=(int*)calloc(1000000,sizeof(int));//initialize an of  1000000 elements to 0
    do{
        printf("\nGive me a number...");
        scanf("%d",&B[i]);//Read a value to the array element
        i++;//i counts the number of elements
        if(i==Size){//if number of elements is equal with the allocated size of array, if no more space
            Size*=2;//increase the size by product of 2
            B=realloc(B,Size*sizeof(int));//reallocate more memory with the new size
                                        //keeping the previous elements
        }

    }while(B[i-1]!=0);//reading numbers until 0 //because we used i++
    //B=realloc(B,100*sizeof(int));
    //...
    //B=realloc(B,10000*sizeof(int));
    free(B);
    //B[13]=536; //B[13]== *(B+13)
    //printf("%d %d %d \n",B[0],B[1],B[2]);
    return 0;
}
