#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void printBackwards(List *list){
   if (list == NULL || list->head == NULL){
      return;
   }

   Node *temp;
   if(list-> tail != NULL ){
      temp = list->tail;
   } else {
       Node *temp = list->head;
       list->printData(temp->data);
       return;
   }


   while(temp != NULL){
      list->printData(temp->data);
      temp = temp -> previous;
   }
   
}
