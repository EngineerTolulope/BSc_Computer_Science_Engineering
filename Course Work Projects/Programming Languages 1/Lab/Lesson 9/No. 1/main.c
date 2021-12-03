#include <stdio.h>
#include <stdlib.h>

struct entry{
   char firstname[50];
   char lastname[50];
   char phonenumber[20];


};//Do not forget the semicolon !!!

void addEntry(FILE *f, struct entry e){

fprintf(f,"%s %s %s\n", e.firstname,e.lastname,e.phonenumber);//we didn't define firstname lastname and  phonenumber because it is in the type struct entry that we are using


}
int main()
{
    struct entry person;//struct entry is the type like int and person is the name
    FILE *fp;
    fp=fopen("phonebook.txt","at");
    printf("First name :-");
    scanf("%s",person.firstname);
    printf("Last name :-");
    scanf("%s",person.lastname);
    printf("PhoneNumber :-");
    scanf("%s",person.phonenumber);

    printf("Person data: ");
    printf("%s %s %s\n",person.firstname,person.lastname,person.phonenumber);
    addEntry(fp, person);
    return 0;
}
