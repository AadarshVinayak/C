#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "TestInt.h"
#include "Files.h"


int main(){
  int a=2, c=4;
   //Test initialize List function
   printf("Test 1, initialize List test\n");
   List *testInt = initializeList(&printInt, &deleteInt, &compareInt);
   if(testInt != NULL)printf("Test 1 is successful\n");

   //Test Initialize Node function
   printf("Test 2, initialize node test\n");
   Node *int1 = initializeNode((void*) 1);
   if(int1 != NULL) printf("Test 2 is successful\n");
   free(int1);

   //Test insertFront
   printf("Test 3, insert front test\n");
   insertFront(testInt, &a);
   if(testInt->head->data == &a) printf("Test 3 is successful\n");
   

   //Test insertBack
   printf("Test 4, insert back test\n");
   insertBack(testInt, &c);
   if(testInt->tail->data == &c) printf("Test 4 is successful\n");
   
   /*//Test insertSorted
   printf("Test 5, insert sorted test\n");
   insertSorted(testInt, &b);
   if(testInt->head->next->data == (void*) 3)printf("Test 5 is successful\n");*/

   //Test getFromFront
   printf("Test 6, get from front test\n");
   if(getFromFront(testInt) ==  &a)printf("Test 6 is successful\n");

   //Test getFromBack
   printf("Test 7, get from back test\n");
   if(getFromBack(testInt) == &c)printf("Test 7 is successful\n");

   //Test printForward
   printf("Test 8, print list forward\n");
   printForward(testInt);

   //Test printbackwards
   printf("Test 9, print list backward\n");
   printBackwards(testInt);

   //Test deleteDataFromList
   printf("Test 10, deleting 2 from the list\n");
   deleteDataFromList(testInt, &a);
   printForward(testInt);

    //Test deleteList
    printf("Test 11, delete the entire list\n");
    deleteList(testInt);
    if(testInt == NULL) printf("test 10 = successful\n"); 

   return 0;
}
