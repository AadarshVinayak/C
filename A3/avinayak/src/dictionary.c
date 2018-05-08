#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "ReadData.h"
#include "Dictionary.h"

void addWord(HTable *ht){
   char* temp = malloc(sizeof(char)*100);
   temp = getDefinitionWord(ht);
   insertData(ht, (int)temp[0], (void*)temp);
}

void removeWord(HTable *ht){
   char* temp = malloc(sizeof(char)*100);
   temp = getDefinitionWord(ht);
   int index = ht->hashFunction(ht->size, (int)temp[0]);
   Node *tmp = ht->table[index];
   Node *prev = NULL;
   int complete=0;
   while(tmp != NULL){
      if(strcmp(tmp->data, temp)==0){
         prev -> next = tmp->next;
	 tmp->next = NULL;
	 destroyNodeData(tmp->data);
	 free(tmp);
	 complete = 1;
      } else {
	 prev = tmp;
         tmp = tmp->next;
      }
   }
   if(complete==0)printf("The word could not be found\n");
}

void spellCheck(HTable* ht){

}

void printDictionary(HTable* ht){
   int i=0;
   for(i=0; i<SIZE; i++){
      if(ht->table[i] !=NULL){
         Node* temp = ht->table[i];
	 while(temp!=NULL){
	   printf("%d:%d:",i, temp->key);
	    ht->printNode(temp->data);
	    printf("\n");
	    temp = temp->next;
	 }
      }
   }
}
