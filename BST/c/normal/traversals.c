#include <stdio.h>
#include "traversals.h"

void print_in_order(Node_ptr tree)
{
  if (tree == NULL)
    return;
  print_in_order(tree->left);
  printf("%d ", tree->value);
  print_in_order(tree->right);
}

void print_pre_order(Node_ptr tree)
{
  if (tree == NULL)
    return;
  printf("%d ", tree->value);
  print_pre_order(tree->left);
  print_pre_order(tree->right);
}

void print_post_order(Node_ptr tree)
{
  if (tree == NULL)
    return;
  print_post_order(tree->left);
  print_post_order(tree->right);
  printf("%d ", tree->value);
}