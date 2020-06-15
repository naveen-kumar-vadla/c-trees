#include <stdio.h>
#include <stdlib.h>

#ifndef __AVL_TREE_H_
#define __AVL_TREE_H_

#include "node.h"

#define MAX(a, b) a > b ? a : b;

Node_ptr create_node(int value);

Node_ptr insert_into_tree(Node_ptr root, int value);
Node_ptr delete_node(Node_ptr root, int value);

Node_ptr get_min_of_tree(Node_ptr root);
Node_ptr get_max_of_tree(Node_ptr root);

Node_ptr right_rotate(Node_ptr root);
Node_ptr left_rotate(Node_ptr root);

Node_ptr balance_tree(Node_ptr root, int value);

int get_balance_factor(Node_ptr root);
int get_tree_height(Node_ptr root, int height);

#endif