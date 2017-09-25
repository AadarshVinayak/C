#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

void displayStore(Store *s)
{
   s->printFunction(s->data);
}
