#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functionDefns.h"

char * getEmail()
{
    int symbol1 = 0;
    int symbol2 = 0;
    char *email;   
    email = malloc(sizeof(char)*100);
    char *temp;
    email[0] = '\n';
    while(email[0] == '\n' || (symbol1!=1 && symbol2!=1)) {
        int i = 0;
        printf("Email: ");
        fgets(email, 100, stdin);
        for(i=0;i<strlen(email);i++){
            if(email[i] == '@'){
                symbol1=1;
            } else if(email[i]=='.'){
                symbol2=1;
            }
        }
        if(symbol1!=1 || symbol2!=1){
            symbol1=0;
            symbol2=0;
        }
    }
    temp = malloc((sizeof(char)*strlen(email)+1));
    strcpy(temp, removeNewLine(email));
    return temp;
}
