#include <stdio.h>
#include <stdlib.h>

#include "functionDefns.h"

FILE *getFile(FILE *fptr)
{
    fptr = fopen("myContactsList.db", "a+");
    if(fptr == NULL){
        fopen("myContactsList.db","w+");
    }
    return fptr;
}