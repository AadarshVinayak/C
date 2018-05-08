/**
 *Aadarsh Vinayak
 *avinayak@mail.uoguelph.ca
 *0978669
 */
#include "HashTableAPI.h" 
#include <string.h>
#include <stdio.h>


int main(void)
{
   HTable * ht =createTable(SIZE,&hashNode,&destroyNodeData,&printNodeData);

   if(ht!=NULL)printf("The hash table is successfully created\n");


//first insertion
   printf("inserting the word Rick\n");
   char* tmp1 = malloc(sizeof(char));
   strcpy(tmp1,"Rick");
   insertData(ht, (int)tmp1[0], (void *)tmp1);
   if(strcmp((char*)lookupData(ht, (int)tmp1[0]),tmp1)==0)printf("The word was successfully inserted\n");

   
//second insertion
 printf("inserting the word ross\n");
   char* tmp2 = malloc(sizeof(char));
   strcpy(tmp2,"ross");
   insertData(ht, (int)tmp2[0], (void *)tmp2);
   if(strcmp((char*)ht->table[ht->hashFunction(SIZE,(int)tmp2[0])]->next->data,tmp2)==0)printf("The word was successfully inserted\n");


//third insertion
 printf("inserting the word Boss\n");
   char* tmp3 = malloc(sizeof(char));
   strcpy(tmp3,"Boss");
   insertData(ht, (int)tmp3[0], (void *)tmp3);
   if(strcmp((char*)lookupData(ht, (int)tmp3[0]),tmp3)==0)printf("The word was successfully inserted\n");


//first retrieval
   printf("Finding Rick using lookupData\n");
   char* toGetBack = (char*)lookupData(ht,(int)tmp1[0]);
   if(toGetBack != NULL)
   {
        printf("found!: ");
        ht->printNode((void*)toGetBack);
	printf("\n");
   }

   printf("Removing Boss\n");
   removeData(ht, (int)tmp3[0]);
   if(ht->table[ht->hashFunction(SIZE,(int)tmp3[0])]==NULL)printf("Successfully deleted Boss\n");

   printf("Deleteing the whole table\n");
   destroyTable(ht);
   ht = NULL;
   if(ht == NULL)printf("Succesfully deleted the hash table\n");


    return 0;
}
