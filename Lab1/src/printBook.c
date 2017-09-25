#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

void printBook(void *b)
{
  //Book *book = (Book*)b;
   printf("%s : $%.2f\n", getName(b), getPrice(b));
}
