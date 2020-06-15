#include <stdio.h>
#include <stdlib.h>

#ifndef __AVL_TREE_VOID_H_
#define __AVL_TREE_VOID_H_

#include "node_void.h"

typedef enum
{
  False,
  True
} Bool;

typedef enum
{
  Lesser = -1,
  Equal = 0,
  Greater = 1
} Compare_Status;

typedef Compare_Status Compare_Method(Element, Element);

#define MAX(a, b) a > b ? a : b;

Node_ptr create_node(Element value);

Node_ptr insert_into_tree(Node_ptr root, Element value, Compare_Method *comparator);
Node_ptr delete_node(Node_ptr root, Element value, Compare_Method *comparator);
Bool search_in_tree(Node_ptr root, Element value, Compare_Method *comparator);

Node_ptr get_min_of_tree(Node_ptr root);
Node_ptr get_max_of_tree(Node_ptr root);

Node_ptr right_rotate(Node_ptr root);
Node_ptr left_rotate(Node_ptr root);

Node_ptr balance_tree(Node_ptr root, Element value, Compare_Method *comparator);

int get_balance_factor(Node_ptr root);
int get_tree_height(Node_ptr root, int height);

#endif