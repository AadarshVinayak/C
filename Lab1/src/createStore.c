#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <store.h>

Store *createStore(void* data, void (printFunction)(void *data))
{
   Store *s = malloc(sizeof(Store));
   s-> data = data;
   s-> printFunction = printFunction;
   return s;
}
