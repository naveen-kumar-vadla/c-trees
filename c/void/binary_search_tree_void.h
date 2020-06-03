#include <stdio.h>
#include <stdlib.h>

#ifndef __BINARY_SEARCH_TREE_VOID_H_
#define __BINARY_SEARCH_TREE_VOID_H_

typedef enum
{
  False,
  True
} Bool;

typedef void *Element;

typedef struct node
{
  Element value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

typedef struct tree
{
  Node_ptr root;
} Tree;

typedef Tree *Tree_ptr;

typedef Bool Compare_Method(Element, Element);
typedef void Display_Data(Element);

Tree_ptr create_tree();
Node_ptr create_node(Element value);

#endif