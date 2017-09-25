#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boardgame.h"

Board* createBoardGame(char *name, char *brandName, double price)
{
   Board *bg = malloc(sizeof(Board));
   bg->price = price;
   bg->name = name;
   bg->brandName = brandName;
   return bg;   
}
