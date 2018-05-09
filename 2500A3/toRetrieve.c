#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

int toRetrieve()
{
    char answer[100];
    int isCorrectInput=0;
    while(isCorrectInput == 0) {
        printf("Do you wish to retrieve a contact(Yes or No)?: ");
        fgets(answer, 100, stdin);
        if (strcmp(answer, "Yes\n\0") == 0){
            isCorrectInput = 1;
            return 0;
        }else if(strcmp(answer, "No\n\0")==0){
            isCorrectInput = 1;
            return 1;
        } else {
            isCorrectInput = 0;
        }
    }
    return -1;
}