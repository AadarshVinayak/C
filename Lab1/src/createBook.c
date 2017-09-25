#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

Book *createBook(char *title, double price)
{
   Book* b = malloc(sizeof(Book));
   b->price = price;
   b->name = title;
   return b;
}

