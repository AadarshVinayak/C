#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


Node *initializeNode(void *data){
   Node *node1 = malloc(sizeof(Node));

   node1 -> data = data;
   node1 -> previous = NULL;
   node1 -> next = NULL;

   return node1;
}
