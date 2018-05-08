#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTableAPI.h"
#include "ReadData.h"
#include <ctype.h>

void getDataFromFile(char* location, HTable *ht){
   FILE *fp = openFile(location);
   char *word = malloc(sizeof(char)*100);

   while(fgets(word, 100, fp)!=NULL){
     char*temp = malloc(sizeof(char*)*100);
     if(!isalpha((int)word[strlen(word)-1]))word[strlen(word)-1] = '\0';
     strcpy(temp,word);
     insertData(ht,(int)temp[0], (void*)temp);
   }
   free(word);
   fclose(fp);
}

int getInputFromUser(){
   int x =0;
   int correct = 1;

   printf("1. Add a word to Dictionary\n2. Remove a word from Dictionary\n3. Spell Check a file\n4. Show Dictionary Words\n5. Quit\n");
   while(correct != 0){
      scanf("%d", &x);
      getchar();
      if(x >0 && x< 6){
         correct = 0;
      } else {
         printf("Please only enter either 1, 2, 3, 4 or 5\n");
      }
   }
   return x;
}

char* getDefinitionWord(HTable *ht){
   char* word = malloc(sizeof(char)*100);

   printf("Please enter a word: ");

   int toCont =0;
   
   while(toCont == 0){
      if(fgets(word, 100, stdin)!=NULL){
	if(strcmp("\n", word)!=0){
	  word[strlen(word)-1] = '\0';
          toCont=1;
	} else {
          printf("Invalid input\n");
	}
      }
   }
   return word;
}



FILE* openFile(char* location){
   FILE* fp= NULL;
   char *test = malloc(sizeof(char)*100);
   fp = fopen(location, "r+");
   while(fp==NULL){
     printf("Please enter a valid file location: \n");
     fgets(test, 100, stdin);
     test[strlen(test)-1] = '\0';
     fp = fopen(test, "r+");
   }
   free(test);
   return fp;
}

