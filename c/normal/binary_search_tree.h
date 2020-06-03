#include <stdio.h>
#include <stdlib.h>

#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

typedef struct tree
{
  Node_ptr root;
} Tree;

typedef Tree *Tree_ptr;

Tree_ptr create_tree();
Node_ptr create_node(int value);

#endif