#ifndef _STORE_
#define _STORE_

//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Store struct
typedef struct store{
   void* data;
   void (*printFunction)(void *data);
}Store;

/**
 * Create a store struct with a void data type and a print function
 * @param data [Book]/[Board]
 * @param function pointer to the print function
 * @return dynamically created store
 */
Store *createStore(void* data, void (printFunction)(void *data));

/**
 * Get the data from the store
 * @param s Store
 * @return data void
 */
void* getData(Store *s);

/**
 * Sets new data to the store
 * @param s Store
 * @param data [Book]/[Board]
 */
void setData(Store *s, void *data);

/**
 * Sets new print function to the store
 * @param s Store
 * @param function pointer to new print function
 */
void setPrintFunction(Store *s, void (printFunction)(void *data));

/**
 * Displays the store using the datas print function
 * @param s Store
 */
void displayStore(Store *s);

#endif

