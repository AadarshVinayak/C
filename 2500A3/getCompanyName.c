#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

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