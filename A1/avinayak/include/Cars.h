#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cars{
   char start;
   char dir;
   double time;
   int position;
  double endTime;
}Cars;

Cars* initializeCars(char start, char dir, double time, int position);

int compareCars(const void *first, const void *second);
void printCars(void *toBePrinted);
  void deleteCar(void *toBeDeleted);
