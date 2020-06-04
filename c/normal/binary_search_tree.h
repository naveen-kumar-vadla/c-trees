#include <stdio.h>
#include <stdlib.h>

#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

typedef enum
{
  False,
  True
} Bool;

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

Node_ptr create_node(int value);

Node_ptr insert_into_tree(Node_ptr root, int value);
Bool search_in_tree(Node_ptr root, int value);

void print_in_order(Node_ptr tree);
void print_pre_order(Node_ptr tree);
void print_post_order(Node_ptr tree);

#endif