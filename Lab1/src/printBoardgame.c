#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boardgame.h"

void printBoardGame(void *bg)
{
   Board* bg1 = (Board*)bg; 
   printf("%s : %s : $%.2f\n",getNameBG(bg1), getBrandName(bg1), getPriceBG(bg1));
}
