#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "PriorityQueue.h"
#include "Patient.h"
#include "ReadData.h"

int main(int argc, char* argv[]){
  PriorityQueue *pq = initializePQ(&printPatient, &deletePatient, &comparePriority);

  List *l = initializeList(&printPatient, &deletePatient, &comparePriority);

  getDataFromFile(argv[1], pq, l);

  
  int x = 0;
  int toContinue = 0;
  while(toContinue == 0){
    x = getInputFromUser();
     switch(x){
        case 1:
	  getPatientFromUser(pq,l);
           break;
        case 2:
	  computeTime(pq,l);
	   toContinue = 1;
           break;
        case 3:
	   toContinue = 1;
       	   break;
     }
     x=0;
  }


  return 0;
}
