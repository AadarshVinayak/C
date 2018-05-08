#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "Files.h"
#include "Cars.h"



FILE* getFile(const char* fileName){
  //FILE* file = fopen("/home/undergrad/1/avinayak/test_2.txt","r");
  FILE* file = fopen(fileName, "r");
  if(file == NULL) printf("this actually didnt work\n");
  return file;
}

void readData(FILE* fp, List *north, List *south, List *east, List *west){

}



