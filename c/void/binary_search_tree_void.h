#include <stdio.h>
#include <stdlib.h>

#ifndef __BINARY_SEARCH_TREE_VOID_H_
#define __BINARY_SEARCH_TREE_VOID_H_

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

typedef void *Element;

typedef struct node
{
  Element value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

typedef Compare_Status Compare_Method(Element, Element);
typedef void Display_Data(Element);

Node_ptr create_node(Element value);

Node_ptr insert_into_tree(Node_ptr root, Element value, Compare_Method *comparator);
Bool search_in_node(Node_ptr root, Element value, Compare_Method *comparator);

void swap_two_elements(Element *a, Element *b);
Node_ptr get_min_of_right(Node_ptr root);
Node_ptr delete_node(Node_ptr root, Element value, Compare_Method *comparator);

void print_in_order(Node_ptr tree, Display_Data *displayer);
void print_pre_order(Node_ptr tree, Display_Data *displayer);
void print_post_order(Node_ptr tree, Display_Data *displayer);

#endif