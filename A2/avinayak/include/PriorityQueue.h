#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "Patient.h"

/**
 *The queue that is a wrapper for the linked list
 **/
typedef struct queue{
	List *list;
} PriorityQueue;

/**Allocates space for the Priority queue and the linked list
 *@return pointer to the priority queue
*@param printFunction function pointer to print a single node of the list
*@param deleteFunction function pointer to delete a single piece of data from the list
*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order
**/
PriorityQueue *initializePQ(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

/**Inserts the data sorted by the datas priority
 *@param the queue 
 *@param the void data that will be inserted into the queue
 **/
void insert(PriorityQueue *pq, void* data);

/**This function gets rid of the top element of the queue
 *@param The queue where the element gets eraced from
 **/
void pop(PriorityQueue *pq);

/**returns the top element of the queue
 *@param The priority queue
 *@return the data at the top of the queue
 **/
void* peek(PriorityQueue *pq);

/**This function will determine if the pop function can work
 *@param queue
 *@param the dat to be deleted
 **/
void removePQ(PriorityQueue* pq, void* toBeDeleted);

/**Destroys the queue
 *@param queue to be destroyed
 **/
void destroy(PriorityQueue *pq);


#endif
