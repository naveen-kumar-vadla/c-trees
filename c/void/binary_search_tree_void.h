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

void insert_into_tree(Tree_ptr tree, Element value, Compare_Method *comparator);
Bool search_in_node(Tree_ptr tree, Element value, Compare_Method *is_less_than, Compare_Method *is_equal_to);

void print_in_order(Node_ptr tree, Display_Data *displayer);
void print_pre_order(Node_ptr tree, Display_Data *displayer);
void print_post_order(Node_ptr tree, Display_Data *displayer);

#endif