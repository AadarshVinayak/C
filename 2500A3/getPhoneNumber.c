#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

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
