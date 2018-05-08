#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "TestInt.h"
#include "Files.h"
#include "Cars.h"


int main(int argc, const char* argv[]){
   List *north= initializeList(&printCars, &deleteCar, &compareCars);
   List *south = initializeList(&printCars, &deleteCar, &compareCars);
   List *east =  initializeList(&printCars, &deleteCar, &compareCars);
   List *west =  initializeList(&printCars, &deleteCar, &compareCars);

   FILE *fp = getFile(argv[1]);

   char start;
   char dir;
   double time;
   int position = 1;
   Cars* car;
   printf("Start   Direction    Time      End Time    Position\n");
   while(fscanf(fp,"%c %c %lf\n", &start, &dir, &time)!= EOF){
     car = initializeCars(start, dir, time, position);
      position+=1;
      switch(car->start){
         case 'N':
             insertBack(north, (void*)car);
	     break;
          case 'S':
	     insertBack(south, (void*)car);
             break;
          case 'E':
	     insertBack(east, (void*)car);
	     break;
	  case 'W':
	     insertBack(west, (void*)car);
	     break;  
	}
      north->printData(car);     
    }

   fclose(fp);
}
