#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


int deleteDataFromList(List *list, void *toBeDeleted){
   if(list==NULL || list->head == NULL || toBeDeleted == NULL){
      return 0;
   }

   Node *temp = list->head;
   while (temp != NULL){
      if(temp->data == toBeDeleted){
         if(temp == list->head){
         	list->head = list->head->next;
         	if(list->head != NULL){
         		list->head->previous = NULL;
         	}
         } else if(temp == list->tail){
            if(temp->previous != NULL){
            	temp->previous->next = NULL;
            }  
         } else {
         	temp->previous->next = temp -> next;
         	temp->next->previous = temp -> previous;
         }
            list->deleteData(temp->data);
            temp->next=NULL;
            temp->previous = NULL;
            free(temp);
      } else {
         if(temp->next != NULL){
            temp = temp->next; 
         }
      }	
   }
   return 0;
}
