#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

char * removeNewLine (char * string)
{
    char *position;
    if ((position=strchr(string, '\n')) != NULL){
        *position = '\0';
    }
    return string;
}