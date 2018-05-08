#include <stdio.h>
#include <stdlib.h>
#include "TestInt.h"

void deleteInt(void *toBeDeleted){
 return; 
}

int compareInt(const void *first, const void *second){
   if(*(int*)first>*(int*)second) return 0;
   return 1;
}


void printInt(void* toBePrinted){
  int *x = (int*) toBePrinted;
  printf("%d\n", *x);    
}
