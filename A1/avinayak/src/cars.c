#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "Cars.h"

Cars* initializeCars(char start, char dir, double time, int position){
   Cars* car = malloc(sizeof(Cars));
   car->start = start;
   car->dir = dir;
   car ->time = time;
   car-> endTime = time+2;
   car -> position = position;
   return car;
}


int compareCars(const void *first, const void *second){
  int x = *((int*)first);
  int y = *((int*)second);
  if(x<y)return 0;
  return 1;
}

void printCars(void *toBePrinted){
  Cars *car = (Cars*)toBePrinted;
   printf("%c       %c            %.2lf      %.2lf        %d\n", car->start, car->dir, car->time, car->endTime, car->position);
}


void deleteCar(void *toBeDeleted){
  Cars *car = (Cars*) toBeDeleted;
  free(car);
}






