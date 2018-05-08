#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
#include "LinkedListAPI.h"


PriorityQueue *initializePQ(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){
   PriorityQueue* pq = malloc(sizeof(PriorityQueue));
   pq->list = initializeList(printFunction, deleteFunction, compareFunction);
   return pq;
}

void insert(PriorityQueue *pq, void* data){
	insertSorted(pq->list, data);
}

void pop(PriorityQueue *pq){
   if(pq!=NULL){
      void* data = peek(pq);

      removePQ(pq, data);
   }
}
void* peek(PriorityQueue *pq){
   return getFromFront(pq->list);
}
void removePQ(PriorityQueue* pq, void* toBeDeleted){
   deleteDataFromList(pq->list, toBeDeleted);
}


void destroy(PriorityQueue *pq){
   deleteList(pq->list);
   free(pq);
   
}
