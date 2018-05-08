#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTableAPI.h"
#include "ReadData.h"
#include "Dictionary.h"

int main(int argc, char* argv[]){
  HTable *ht= createTable(SIZE, &hashNode, &destroyNodeData, &printNodeData);

  getDataFromFile(argv[1], ht);

  
  int x = 0;
  int toContinue = 0;
  while(toContinue == 0){
    x = getInputFromUser();
     switch(x){
        case 1:
	   addWord(ht);
           break;
        case 2:
	   removeWord(ht);
           break;
        case 3:
	   spellCheck(ht);
       	   break;
        case 4:
	   printDictionary(ht);
	   break;
        case 5:
	   toContinue = 1;
	   destroyTable(ht);
	   break;
     }
     x=0;
  }


  return 0;
}
