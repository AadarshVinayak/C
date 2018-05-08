#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Patient.h"
#include "PriorityQueue.h"
#include "LinkedListAPI.h"
#include "ReadData.h"
#include <ctype.h>

void getDataFromFile(char* location, PriorityQueue *pq, List* l){
   FILE* fp= NULL;
   char *test = malloc(sizeof(char)*100);
   fp = fopen(location, "r+");
   while(fp==NULL){
     printf("Please enter a valid file location: \n");
     fgets(test, 100, stdin);
     test[strlen(test)-1] = '\0';
     fp = fopen(test, "r+");
   }
   char *id = malloc(sizeof(char)*100);
   char *symptom = malloc(sizeof(char)*100);
   int priority = 0;

   while(fscanf(fp, "%s %d %s", id, &priority, symptom)!=EOF){
      
      Patient *c = initializePatient(id, priority, symptom);
      insert(pq, (void*)c);
      insertFront(l, (void*)c);
   }
   free(id);
   free(symptom);
   fclose(fp);
   
}

int getInputFromUser(){
   int x =0;
   int correct = 1;

   printf("1) Enter a patient\n2) Compute wait time\n3) Exit program\n");
   while(correct != 0){
      scanf("%d", &x);
      getchar();
      if(x >0 && x< 4){
         correct = 0;
      } else {
         printf("Please only enter either 1, 2, or 3\n");
      }
   }
   return x;
}

void getPatientFromUser(PriorityQueue *pq, List* l){
   char* id = malloc(sizeof(char)*100);
   char* symptom = malloc(sizeof(char)*100);
   int priority;
   char* temp = malloc(sizeof(char)*100);

   printf("Please enter the patient ID: ");

   int toCont =0;
   
   while(toCont == 0){
      if(fgets(id, 100, stdin)!=NULL){
	if(strcmp("\n", id)!=0){
	  id[strlen(id)-1] = '\0';
          toCont=1;
	} else {
          printf("Invalid input\n");
	}
      }
   }

   printf("Please enter the patients priority: ");


   toCont = 0;
   while (toCont == 0){
      if(fgets(temp, 100,stdin)!=NULL){
	if(isdigit((int)*temp)!=0){
	  priority = atoi(temp);
	   if(priority>0 && priority<6){
	      toCont=1;
	   } else {
              printf("Invalid Input, please enter a value between 1 and 5\n");
	   }
	} else {
          printf("Invalid Input\n");
	}
      }
   }


   printf("Please enter the patients symptom code: ");
   toCont = 0;
   while(toCont==0){
       if(fgets(symptom, 100,stdin)!=NULL){
	 symptom[strlen(symptom)-1] = '\0';
          if(strcmp("CV", symptom)==0){
             toCont = 1;
	  } else if(strcmp("HN", symptom)==0){
             toCont = 1;
	  } else if(strcmp("EV",symptom)==0){
             toCont = 1;
	  } else if(strcmp("GI", symptom)==0){
             toCont = 1;
	  } else if(strcmp("MH",symptom)==0){
             toCont = 1; 
	  } else if(strcmp("NC", symptom)==0){
             toCont = 1; 
	  } else if(strcmp("EC",symptom)==0){
             toCont = 1;
	  } else if(strcmp("RC", symptom)==0){
             toCont = 1;
	  } else if(strcmp("SK",symptom)==0){
             toCont = 1;
	  } else if(strcmp("SA", symptom)==0){
             toCont = 1;
	  } else if(strcmp("TR",symptom)==0){
             toCont = 1;
	  } else {
	    printf("Invalid symptom\n");
	  }
       } 
   }


   Patient *p = initializePatient(id, priority, symptom);
   insert(pq, (void*)p);
   insertFront(l, (void*)p);
   
}


void computeTime(PriorityQueue *pq, List *l){
  int counter = 0;
  Node* temp = pq->list->head;

  while(temp!= NULL){
    Patient *s = (Patient*)temp->data;
    counter += 1+ getTime(s -> symptom);
    s->time = counter;
    temp = temp->next;
  }
  printForward(l);
 
  destroy(pq);
  temp = l->head;
  Node* next= l->head->next; 
  while(temp!= NULL){
    free(temp);
    temp = next;
    if(next!=NULL){
      next=next->next;
    }
  }
  free(l);
}


