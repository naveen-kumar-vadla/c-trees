#ifndef __TRAVERSALS_H_
#define __TRAVERSALS_H_

#include "node_void.h"

typedef void Display_Data(Element);

void print_in_order(Node_ptr tree, Display_Data *displayer);
void print_pre_order(Node_ptr tree, Display_Data *displayer);
void print_post_order(Node_ptr tree, Display_Data *displayer);

#endif