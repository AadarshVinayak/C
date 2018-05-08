#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


void insertSorted(List *list, void *toBeAdded){
   if (list == NULL){
   	return;
   }
   if (list->head == NULL){
      list->head = initializeNode(toBeAdded);
      return;
   }

   Node *node = initializeNode(toBeAdded);
   Node *temp = list->head;
   while(temp != NULL){
      if(list->compare(toBeAdded,temp->data)!=0){
	 temp = temp->next;
      } else {
         node -> next = temp->next;
         node -> previous = temp;
         temp->next->previous = node;
         temp -> next = node;
      }
   }
   
}
