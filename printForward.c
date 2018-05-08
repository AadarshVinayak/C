#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void printForward(List *list){
   if (list== NULL){
      return;
   }

   Node *temp = list->head;

   while(temp != NULL){
      list->printData(temp->data);
      temp = temp->next;
   }

}
