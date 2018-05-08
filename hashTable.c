#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"

Node *createNode(int key, void *data)
{
   struct Node *node = malloc(sizeof(Node));
   node->key = key;
   node -> data = data;
   node -> next = NULL;
   
   return node;
}


HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printData)(void *toBePrinted))
{
  HTable *table = malloc(sizeof(HTable));
   table -> size = size;
   table->table = malloc(sizeof(Node)*size);
   table -> destroyData = destroyData;
   table -> hashFunction = hashFunction;
   table -> printNode = printData;
   
   return table;
}


void destroyTable(HTable *hashTable)
{
   if(hashTable != NULL)
   {
      int i=0;
      for(i=0; i<(hashTable->size-1); i++)
      {
         Node *temp = hashTable->table[i];
         while(temp != NULL)
         {
           Node *tempDel = temp;
           temp = temp->next;
           hashTable->destroyData(tempDel->data);
	   tempDel->next = NULL;
           free(tempDel);
         }
      }
      free(hashTable->table);
      free(hashTable);
   }
}

void insertData(HTable *hashTable, int key, void *data){
   if (hashTable != NULL)
   {
      Node *node = createNode(key, data);
      int index = hashTable->hashFunction(hashTable->size, key);


      if(hashTable -> table[index] != NULL)
      {
            Node *temp = hashTable->table[index]; 
            while (temp->next != NULL)
            {
               temp = temp->next;
            }
            if(temp->next == NULL)
            {
               temp->next = node;
            }
      } 
      else 
      {
         hashTable -> table[index] = node;      
      }
   }
}

void *lookupData(HTable *hashTable, int key)
{
   if(hashTable != NULL)
   {
      int index = hashTable->hashFunction(hashTable->size, key);
      if(hashTable->table[index] == NULL)
      {
         return NULL;
      }

      Node *temp = hashTable->table[index];
      while(temp!=NULL)
      {
         if(temp->key == key)
         {
            return temp->data;
         }
         temp = temp->next;
      }
   }
   return NULL;
}

void removeData(HTable *hashTable, int key)
{
   if(hashTable != NULL)
   {
      int index = hashTable->hashFunction(hashTable->size, key);

      if(hashTable->table[index] != NULL)
      {
         Node *node = hashTable->table[index];
         Node *prev = NULL;

         while(node->key != key)
         {
            prev = node;
            node = node->next;
         }
         if(node->key == key)
         {
            if(prev==NULL)
            {
               hashTable->table[index] = node->next;
               free(node);
               if(hashTable->table[index] == NULL)
               {
                  free(hashTable->table[index]);
               }
            } else 
            {
               prev->next = node->next;
	       node->next = NULL;
               free(node);
            }
         }
      }
   }
}

int hashNode(size_t tableSize, int key){
  if(key<91){
     return (key-65)%(int)tableSize;
  } else {
     return (key-97)%(int)tableSize;
  }
}

void destroyNodeData(void* data){
  free((char*)data);
}

void printNodeData(void* toBePrinted){
  char* temp = (char*)toBePrinted;
  printf("%s",temp);
}
