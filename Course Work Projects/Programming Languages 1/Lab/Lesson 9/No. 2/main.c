#include <stdio.h>
#include <string.h>

struct entry{
   char firstname[50];
   char lastname[50];
   char phonenumber[20];


};//Do not forget the semicolon !!!

void addEntry(FILE *f, struct entry e){

fprintf(f,"%s %s %s\n", e.firstname,e.lastname,e.phonenumber);//we didn't define firstname lastname and  phonenumber because it is in the type struct entry that we are using


}
void searchbyphonenumber(FILE *f,char *str){
    struct entry e;
while(1){
    if (fscanf(f, "%s %s %s", e.firstname,e.lastname,e.phonenumber)==EOF) break;
    if (strcmp(str, e.phonenumber)==0){
        printf("%s %s %s\n",e.firstname,e.lastname,e.phonenumber);
    }
}
}
int main()
{
    int choice;
    char num[20];
    struct entry person;//struct entry is the type like int and person is the name
    FILE *fp;
    while (1){
        printf("What is your choice?\n");
        printf("1. Add an entry\n");
        printf("2. Search by number\n");
        printf("3. Exit \n");
        scanf("%d",&choice);

        switch(choice){
        case 1:fp=fopen("phonebook.txt","at");
    printf("First name :-");
    scanf("%s",person.firstname);
    printf("Last name :-");
    scanf("%s",person.lastname);
    printf("PhoneNumber :-");
    scanf("%s",person.phonenumber);
      addEntry(fp, person);
      fclose(fp);
      break;
    case 2:fp=fopen("phonebook.txt","rt");
    printf("Give me a number:-");
    scanf("%s",num);
          searchbyphonenumber(fp, num);
          fclose(fp);
          break;
    case 3: return 0;//so we can end the whole program
        }
    }



    /*printf("Person data: ");
    printf("%s %s: %s\n",person.firstname,person.lastname,person.phonenumber);*/

    return 0;
}
