#include <stdio.h>
#include "traversals_void.h"

void print_in_order(Node_ptr tree, Display_Data *displayer)
{
  if (tree == NULL)
    return;
  print_in_order(tree->left, displayer);
  (*displayer)(tree->value);
  print_in_order(tree->right, displayer);
}

void print_pre_order(Node_ptr tree, Display_Data *displayer)
{
  if (tree == NULL)
    return;
  (*displayer)(tree->value);
  print_pre_order(tree->left, displayer);
  print_pre_order(tree->right, displayer);
}

void print_post_order(Node_ptr tree, Display_Data *displayer)
{
  if (tree == NULL)
    return;
  print_post_order(tree->left, displayer);
  print_post_order(tree->right, displayer);
  (*displayer)(tree->value);
}