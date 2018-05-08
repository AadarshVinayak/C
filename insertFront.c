#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void insertFront(List *list, void *toBeAdded){
   if (list == NULL){
   	return;
   }
   if (list->head == NULL){
      list->head = initializeNode(toBeAdded);
      list->tail = list->head;
      return;
   }
   
   Node *node = initializeNode(toBeAdded);
   node -> next = list->head;
   list->head->previous = node;
   list->head = node;
   while (node -> next != NULL){
      node = node->next;
   }
   list -> tail = node; 
}
