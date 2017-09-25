#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"


void* getData(Store *s)
{
   return s->data;
}
