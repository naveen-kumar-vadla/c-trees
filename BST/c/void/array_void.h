#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __ARRAY_VOID_H_
#define __ARRAY_VOID_H_

#include "node_void.h"

typedef struct
{
  Element *values;
  int length;
} Array_void;

typedef Array_void *Array_void_ptr;

Array_void_ptr create_Array_void();
void resize_Array_void(Array_void_ptr array, int length);
void push_to_Array_void(Array_void_ptr array, Element value);
void destroy_Array_void(Array_void_ptr array);

#endif