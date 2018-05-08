#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){
   List* list1 = malloc(sizeof(List));

   list1 -> head = NULL;
   list1 -> tail = NULL;
   list1 -> printData = printFunction;
   list1 -> deleteData = deleteFunction;
   list1 -> compare = compareFunction;

   return list1;

}
