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
int getContactInformation(struct contact *findContact, FILE *fptr, unsigned long number);
