#include <stdio.h>
#include <stdlib.h>

struct Elem{
    int data;//data of the current element
    struct Elem *next;//a pointer to next element

};

int main()
{
    int tmp; //temporal data
    struct Elem *TP; // temporary struct pointer
    struct Elem *toFree; // which is the location to free up
    struct Elem *Head=NULL; // it points to the first element of the list
    do{
        printf("Give me a number... ");
        scanf("%d",&tmp); // read a number
        TP=(struct Elem*)malloc(sizeof(struct Elem)); // allocate a new structure, TP stores the address

        (*TP).data = tmp; // enter the data to the structure
        (*TP).next=Head; // The next element is the earlier first
        Head=TP; // the new first element is the new (TP pointed)
    }while(tmp!=0); // read until the first 0

    //print out the elements of the linked list starting with the first
    TP=Head; // temporary pointer points to the first element
    while(TP!=NULL){ // while there are elements in the list
        printf("%d ",(*TP).data); //print the data
        toFree=TP; // this is not necessary any more (later free up)
        TP=(*TP).next; // TP moves to the next element
        free(toFree); // free it
    }

    return 0;
}
