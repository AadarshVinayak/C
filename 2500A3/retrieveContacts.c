#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

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