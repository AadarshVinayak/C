#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

int getContactInformation(struct contact *findContact, FILE *fptr, unsigned long number)
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
    }

   
    char *companyName;
    companyName = malloc(sizeof(char)*100);
    strcpy(companyName, "");
    if(findContact -> company_name_posn != 0){
        fseek(fptr, findContact->company_name_posn, SEEK_SET);
        fread(companyName, sizeof(char), (size_t)(findContact->email_posn-findContact->company_name_posn),fptr);
    }
    
    char *email;
    email = malloc(sizeof(char)*100);
    fseek(fptr,findContact->email_posn,SEEK_SET);
    fread(email, sizeof(char), (size_t)(findContact->next - findContact->email_posn), fptr);


    printf("First Name: %s\nLast Name: %s\nCompany Name: %s\nPhone Number (enter only numbers): %lu\nEmail: %s\n",firstName, lastName, companyName, number, email);
    return 0;
}