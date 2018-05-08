#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void insertBack(List *list, void *toBeAdded){
   if (list == NULL){
   	return;
   }
   if (list->head == NULL){
      list->head = initializeNode(toBeAdded);
      return;
   }

   Node *temp = list->head;
   while(temp->next != NULL){
      temp = temp->next;
   }

   Node *node = initializeNode(toBeAdded);
   node -> next =NULL;
   node -> previous = temp;
   temp->next = node;
   list -> tail = node;

}
