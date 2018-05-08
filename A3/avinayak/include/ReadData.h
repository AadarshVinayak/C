#ifndef _READ_DATA_
#define _READ_DATA_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTableAPI.h"

void getDataFromFile(char* location, HTable* ht);

int getInputFromUser();

char* getDefinitionWord(HTable *ht);

FILE* openFile(char* location);

#endif
