#include <stdio.h>
#include <stdlib.h>

#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include "node.h"
#include "array.h"

typedef enum
{
  False,
  True
} Bool;

Node_ptr create_node(int value);

Node_ptr insert_into_tree(Node_ptr root, int value);
Bool search_in_tree(Node_ptr root, int value);

Node_ptr get_min_of_right(Node_ptr root);
Node_ptr delete_node(Node_ptr root, int value);

Node_ptr get_node_of(Node_ptr root, int value);
Node_ptr rotate_right(Node_ptr root, Node_ptr pivot);
Node_ptr rotate_left(Node_ptr root, Node_ptr pivot);

Int_Array_ptr get_sorted_tree_list(Node_ptr root, Int_Array_ptr array);
Node_ptr insert_array_into_tree(Node_ptr root, Int_Array_ptr array, int from, int to);
Node_ptr balance_tree(Node_ptr root);

#endif