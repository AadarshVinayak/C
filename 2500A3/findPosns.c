#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

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