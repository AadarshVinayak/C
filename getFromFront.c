#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void *getFromFront(List *list){
   if(list == NULL || list->head==NULL){
   	  return NULL;
   }

   return list->head->data;
}
