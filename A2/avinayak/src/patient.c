#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Patient.h"
#include "PriorityQueue.h"

Patient *initializePatient(char *id, int priority, char* symptom){
   Patient *p = malloc(sizeof(Patient));
   p->id = malloc(sizeof(char)*(strlen(id)+1));
   strcpy(p->id, id);
   p->priority = priority;
   p->symptom = malloc(sizeof(char)*(strlen(symptom)+1));
   strcpy(p->symptom, symptom);
   p->time = 0;
   return p;
}


void deletePatient(void* toBeDeleted){
   Patient *p = (Patient*)toBeDeleted;
   free(p->id);
   free(p->symptom);
   free(p);     
}


void printPatient(void *toBePrinted){
   Patient *p = (Patient*) toBePrinted;

   printf("%s  %d  %s  %d\n", p->id, p->priority, p->symptom, p->time);  
}


int comparePriority(const void* first, const void* second){
   Patient* f = (Patient*)first;
   Patient* s = (Patient*)second;

   if(f->priority <= s->priority) return 1;
   return -1;
}


int getTime(char *symptom){
   if(strcmp("CV", symptom)==0){
             return 5;
	  } else if(strcmp("HN", symptom)==0){
     return 3;
      	  } else if(strcmp("EV",symptom)==0){
             return 10;
	  } else if(strcmp("GI", symptom)==0){
     return  2;
	  } else if(strcmp("MH",symptom)==0){
     return 5; 
	  } else if(strcmp("NC", symptom)==0){
     return 5; 
	  } else if(strcmp("EC",symptom)==0){
     return 1;
	  } else if(strcmp("RC", symptom)==0){
     return 1;
	  } else if(strcmp("SK",symptom)==0){
     return 2;
	  } else if(strcmp("SA", symptom)==0){
     return 7;
	  } else if(strcmp("TR",symptom)==0){
     return 4;
	  }
   return -1;
}



