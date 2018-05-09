#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

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
