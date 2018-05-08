#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"

FILE* getFile(const char* fileName);
void readData(FILE* fp, List *north, List* south, List *east, List *west);
