#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void deleteList(List *list){
   if (list == NULL){
      return;
   }

   while (list -> head != NULL){
      Node *temp = list->head;
      list->head = list->head->next;
      
      temp->next = NULL;
      temp->previous = NULL;
      list->deleteData(temp->data);
      free(temp);
   }
   free(list);
}
