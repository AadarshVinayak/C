#ifndef _READ_DATA_
#define _READ_DATA_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Patient.h"
#include "PriorityQueue.h"
#include "LinkedListAPI.h"


/**Function that opens the file and populates the list and queue with the data from the file
 *@return void
 *@param The string that contains the locatoin of the file
 *@param The empty priority queue
 *@param The empty list that needs to be populated;
 **/
void getDataFromFile(char *location, PriorityQueue *pq, List *l);

/**This gets either 1, 2, or 3 from the user based on the menu
 *@return int, either 1,2,3 based on there choice
 **/
int getInputFromUser();

/**This function asks user for all of the data regarding the Patient and puts it into the queue/list
 *@param The queue in which the patient will be added to
 *@param The list in which the data will be printed from
 **/
void getPatientFromUser(PriorityQueue* pq, List *l);

/**This function computes the final time of all patients, prints them out, and destroys the list and queue
 *@param The queue with all the data in order
 *@param The list where all the data will be printed from 
 **/
void computeTime(PriorityQueue *pq, List* l);

#endif
