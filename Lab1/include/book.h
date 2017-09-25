#ifndef _BOOK_
#define _BOOK_

//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Basic book information
typedef struct book {
   double price;
   char *name;
}Book;

/**
 * Creating and initializing the book struct with entered name and price
 * @param title string of title
 * @param price double
 * @return a dynamically created book
 */
Book* createBook(char *title, double price);

/**
 * Get price of the book
 * @param b Book
 * @return Double price
 */
double getPrice(Book *b);

/**
 * reurns a books name 
 * @param b Book
 * @return char* string of name
 */
char* getName(Book *b);

/**
 * Set the price of a book to a new value
 * @param b Book
 * @param double newPrice
 */
void setPrice(Book *b, double newPrice);

/**
 * Set the name of the book to a new name
 * @param b Book
 * @param char* new name
 */
void setName(Book *b, char* name);

/**
 * Display a books name and price
 * @param b [Book]
 */
void printBook(void *b);

#endif
