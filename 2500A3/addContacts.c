#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

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
