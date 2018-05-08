#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void *getFromBack(List *list){
   if(list == NULL || list->head==NULL){
   	  return NULL;
   }

   return list->tail->data; 
}
