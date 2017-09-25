#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

void setData(Store *s, void* data)
{
   s->data = data;
}
