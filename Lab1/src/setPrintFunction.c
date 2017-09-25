#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

void setPrintFunction(Store *s, void (printFunction)(void* data))
{
   s->printFunction = printFunction;
}
