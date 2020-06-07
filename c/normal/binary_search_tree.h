#include <stdio.h>
#include <stdlib.h>

#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include "node.h"

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

void print_in_order(Node_ptr tree);
void print_pre_order(Node_ptr tree);
void print_post_order(Node_ptr tree);

#endif