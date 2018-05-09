#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

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
