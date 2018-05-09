#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct contact{
    unsigned long phone_number;
    long first_name_posn;
    long last_name_posn;
    long company_name_posn;
    long email_posn;
    long next;
};

struct information{
    unsigned long phone_number;
    char* firstName;
    char* lastName;
    char* companyName;
    char* email;

};


FILE* getFile(FILE *fptr);
int toAdd();
int toRetrieve();
int addContacts(FILE *fptr, long position);
int retrieveContacts(FILE *fptr);
char * getFirstName();
char * getLastName();
char * getCompanyName();
unsigned long getPhoneNumber();
char * getEmail();
char * removeNewLine (char * string);
int findPosns (struct contact * newContact, char * firstName, char * lastName, char * companyName, char * email, long posiition);
struct *information getContactInformation(struct contact *findContact, FILE *fptr);
struct *information populateStruct(struct information *empty, FILE *fptr);



int main() 
{
    FILE *fptr=NULL;
    fptr = getFile(fptr);
    fseek(fptr, 0, SEEK_END);
    long position = ftell(fptr);
    int toContinue=0;
    struct information *contacts;
    contacts = populateStruct(contacts);
    while(toContinue == 0) {
        int adding=0;
        while(adding == 0) {
            adding = toAdd(); 
            if(adding == 0) {
                position = addContacts(fptr, position);
            }
        }
        if(toRetrieve() == 0){
            if(retrieveContacts(fptr)==-1){
                printf("Match not found\n");
            }
        } else {
            toContinue = 1;
        }
    }

    return 0;
}


struct *informtation populateStruct(struct information * empty, FILE fptr*){
    
    struct contact *findContact;
    int end = 0;
    findContact = malloc(sizeof(struct contact));
    fseek(fptr, 0, SEEK_END);
    end = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    int numElements = 1;
    empty = malloc(sizeof(struct information));
    while(ftell(fptr) != end){
        fread(findContact, sizeof(struct contact), 1, fptr);
        realloc(empty, sizeof(struct information)*numElements);
        empty[numElements-1] = getContactInformation(findContact, fptr, empty)
        fseek(fptr, findContact->next, SEEK_SET);
    }
    return empty;
}



FILE *getFile(FILE *fptr)
{
    fptr = fopen("myContactsList.db", "a+");
    if(fptr == NULL){
        fopen("myContactsList.db","w+");
    }
    return fptr;
}


int retrieveContacts(FILE *fptr)
{
    unsigned long number = 0;
    struct contact *findContact;
    int end = 0;
    findContact = malloc(sizeof(struct contact));
    fseek(fptr, 0, SEEK_END);
    end = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    printf("Phone Number: ");
    scanf("%lu", &number);
    getchar();

    int flag = 1;
    while(ftell(fptr) != end && flag == 1){
        fread(findContact, sizeof(struct contact), 1, fptr);
        if(number == findContact->phone_number) {
               flag=0;
               break;
        }
        fseek(fptr, findContact->next, SEEK_SET);
    }
    if(flag == 1){
        return -1;
    }
    
    getContactInformation(findContact, fptr, number); 
    return 0;
}


int addContacts(FILE *fptr, long position)
{
    struct contact *newContact = NULL;
    char *firstName = getFirstName();
    char *lastName = getLastName();
    char *companyName = getCompanyName();
    while(strlen(lastName)==0 && strlen(companyName)==0){
    printf("Please enter one of Last name or Company Name\n");
    lastName= getLastName();
    companyName = getCompanyName();
    }
    unsigned long number = getPhoneNumber();
    char *email = getEmail();

    newContact = malloc(sizeof(struct contact));
    newContact->phone_number = number;

    findPosns(newContact, firstName, lastName, companyName, email, position);


    fwrite(newContact,sizeof(struct contact),1, fptr);
    if(strlen(firstName)!=0){
        fwrite(firstName, sizeof(char), strlen(firstName)+1, fptr);
    }
    if(strlen(lastName)!=0){
        fwrite(lastName,sizeof(char), strlen(lastName)+1, fptr);
    }
    if(strlen(companyName)!=0){
        fwrite(companyName, sizeof(char), strlen(companyName)+1, fptr);
       }
       if(strlen(email)!=0){
        fwrite(email, sizeof(char), strlen(email)+1,fptr);
       }

    position = ftell(fptr);
    return position;
}


int findPosns (struct contact * newContact, char * firstName, char * lastName, char * companyName, char * email, long position)
{    
    position += sizeof(struct contact);
    if(strlen(firstName) != 0){
      newContact->first_name_posn = position;
      position+=(strlen(firstName)+1);
    } else {
      newContact->first_name_posn = 0;
    }
    if(strlen(lastName) != 0){
      newContact->last_name_posn=position;
      position += (strlen(lastName)+1);
    }else{
      newContact->last_name_posn = 0;
    }
   
    if(strlen(companyName) != 0){
       newContact->company_name_posn = position;
        position += (strlen(companyName)+1);
    } else{
      newContact->company_name_posn=0;
    }
   
    if(strlen(email) != 0){
       newContact->email_posn = position;
        position += (strlen(email)+1);
    } else {
      newContact->email_posn = 0;
    }
    newContact->next = position;

    return 0;
}


struct *infomration getContactInformation(struct contact *findContact, FILE *fptr, struct information *contactInfo)
{
    char *firstName;
    firstName = malloc(sizeof(char)*100);
    strcpy(firstName, "");
    if(findContact->first_name_posn!=0){
        fseek(fptr,findContact->first_name_posn, SEEK_SET);
        if(findContact->last_name_posn != 0){
            fread(firstName, sizeof(char), (size_t)(findContact->last_name_posn-findContact->first_name_posn), fptr);
        } else if(findContact -> company_name_posn !=0){
            fread(firstName, sizeof(char), (size_t)(findContact->company_name_posn-findContact->first_name_posn), fptr);
        } else {
            fread(firstName, sizeof(char), (size_t)(findContact->email_posn-findContact->first_name_posn), fptr);
        }
        contactInfo->firstName = malloc(sizeof(char)*(strlen(firstName)+1));
        strcpy(contactInfo->firstName, firstName);
    } else {
        contactInfo->firstName='\0';
    }

    

    char *lastName;
    lastName = malloc(sizeof(char)*100);
    strcpy(lastName, "");
    if(findContact -> last_name_posn != 0){
        fseek(fptr,findContact->last_name_posn,SEEK_SET);
        if(findContact -> company_name_posn != 0){
            fread(lastName, sizeof(char), (size_t)(findContact->company_name_posn-findContact->last_name_posn), fptr);
        } else { 
            fread(lastName, sizeof(char), (size_t)(findContact->email_posn-findContact->last_name_posn), fptr);
        }
        contactInfo->lastName = malloc(sizeof(char)*(strlen(lastName)+1));
        strcpy(contactInfo->lastName, lastName);  
    }

   
    char *companyName;
    companyName = malloc(sizeof(char)*100);
    strcpy(companyName, "");
    if(findContact -> company_name_posn != 0){
        fseek(fptr, findContact->company_name_posn, SEEK_SET);
        fread(companyName, sizeof(char), (size_t)(findContact->email_posn-findContact->company_name_posn),fptr);
        contactInfo->companyName = malloc(sizeof(char)*(strlen(companyName)+1));
        strcpy(contactInfo->companyName, companyName);  
    }
    
    char *email;
    email = malloc(sizeof(char)*100);
    fseek(fptr,findContact->email_posn,SEEK_SET);
    fread(email, sizeof(char), (size_t)(findContact->next - findContact->email_posn), fptr);
    contactInfo->lastName = malloc(sizeof(char)*(strlen(email)+1));
    strcpy(contactInfo->email, email); 

    contactInfo->phone_number = findContact->phone_number;

    return contactInfo;
}


int toAdd()
{
    char answer[100];
    int isCorrectInput=0;
    while(isCorrectInput == 0) {
        printf("Do you wish to enter a new contact(Yes or No)?: ");
        fgets(answer, 100, stdin);
        if (strcmp(answer, "Yes\n\0") == 0){
            isCorrectInput = 1;
            return 0;
        }else if(strcmp(answer, "No\n\0")==0){
            isCorrectInput = 1;
            return 1;
        } else {
            isCorrectInput = 0;
        }
    }
    return -1;
}


int toRetrieve()
{
    char answer[100];
    int isCorrectInput=0;
    while(isCorrectInput == 0) {
        printf("Do you wish to retrieve a contact(Yes or No)?: ");
        fgets(answer, 100, stdin);
        if (strcmp(answer, "Yes\n\0") == 0){
            isCorrectInput = 1;
            return 0;
        }else if(strcmp(answer, "No\n\0")==0){
            isCorrectInput = 1;
            return 1;
        } else {
            isCorrectInput = 0;
        }
    }
    return -1;
}



char * getCompanyName()
{
    char company[100];
    char *temp;
    printf("Company Name: ");
    fgets(company, 100, stdin);
    temp = malloc((sizeof(char)*(strlen(company)+1)));
    strcpy(temp, removeNewLine(company));
    return temp;
}


char * getEmail()
{
    int symbol1 = 0;
    int symbol2 = 0;
    char *email;   
    email = malloc(sizeof(char)*100);
    char *temp;
    email[0] = '\n';
    while(email[0] == '\n' || (symbol1!=1 && symbol2!=1)) {
        int i = 0;
        printf("Email: ");
        fgets(email, 100, stdin);
        for(i=0;i<strlen(email);i++){
            if(email[i] == '@'){
                symbol1=1;
            } else if(email[i]=='.'){
                symbol2=1;
            }
        }
        if(symbol1!=1 || symbol2!=1){
            symbol1=0;
            symbol2=0;
        }
    }
    temp = malloc((sizeof(char)*strlen(email)+1));
    strcpy(temp, removeNewLine(email));
    return temp;
}


char * getFirstName()
{
    char first[100];
    char* temp;
    printf("First Name: ");
    fgets(first, 100, stdin);
    temp = malloc((sizeof(char)*(strlen(first)+1)));
    strcpy(temp, removeNewLine(first));
    return temp;
}


char * getLastName()
{
    char last[100];
    char* temp;
    printf("Last Name: ");
    fgets(last, 100, stdin);
    temp = malloc((sizeof(char)*(strlen(last)+1)));
    strcpy(temp, removeNewLine(last));
    return temp;
}


unsigned long getPhoneNumber()
{
    char *ptr;
    char temp[100];
    unsigned long number=0;
    int flag=0;
    while(flag == 0){
        printf("Phone Number (enter only numbers): ");
        fgets(temp, 100, stdin);
        if(strlen(temp)==8 || strlen(temp)==11){
            number = strtoul(temp, &ptr, 10);
            flag=1;
        }
    }
    return number;
}


char * removeNewLine (char * string)
{
    char *position;
    if ((position=strchr(string, '\n')) != NULL){
        *position = '\0';
    }
    return string;
}