#ifndef _BOARDGAME_
#define _BOARDGAME_

//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a basic board game
typedef struct boardGame {
   double price;
   char *name;
   char *brandName;
}Board;

/**
 * Creates a board game struct and assigns it values
 * @param char* name of the game
 * @param char* brand name
 * @param price double
 * @return dynamically created board game
 */
Board* createBoardGame(char *name, char *brandName, double price);

/**
 * Get price of the board game
 * @param bg Board
 * @return double price
 */
double getPriceBG(Board *bg);

/**
 * Get name of the board game
 * @param bg Board
 * @return char* name of the board game
 */
char* getNameBG(Board *bg);

/**
 * Get brand of the board game
 * @param bg Board
 * @return char* brand name
 */
char* getBrandName(Board *bg);

/**
 * Set new price of the board game
 * @param bg Board
 * @param double newPrice
 */
void setPriceBG(Board *bg, double newPrice);

/**
 * Set new name of the board game
 * @param bg Board
 * @param char* the new name
 */
void setNameBG(Board *bg, char* newName);

/**
 * Set new brand name of the board game
 * @param bg Board
 * @param char* new brand name
 */
void setBrandName(Board *bg, char* newBrand);

/**
 * Displays the board games name, brand, and price
 * @param bg [Board]
 */
void printBoardGame(void *bg);

#endif
