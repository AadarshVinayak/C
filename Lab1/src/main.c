#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "boardgame.h"
#include "store.h"

int main(int argc, char **argv)
{
   //Declaring and populating the book and boardgame structs
   Book *b = createBook("Harry Potter And The Cursed Child", 19.99);
   Board *bg = createBoardGame("Setlers of Catan", "Catan", 30.00);
   
   //Declaring the store with book as the data then displaying it
   Store *s = createStore((void *)b,&printBook);
   displayStore(s);
  
   //Changing the books name and price then displaying it
   setName(b, "Ready Player One");
   setPrice(b, 14.36);
   displayStore(s);

   //Changing the type of the store to boardgames and displaying it
   setData(s, (void *)bg);
   setPrintFunction(s, &printBoardGame);
   displayStore(s);

   //Changing the boardgames properties then displaying the new boardgame
   setNameBG(bg, "House on the hill");
   setBrandName(bg, "Avalon Hill");
   setPriceBG(bg, 36.00);
   displayStore(s);

   //Freeing all the pointers
   free(b);
   free(bg);
   free(s);
   return 0;
}
