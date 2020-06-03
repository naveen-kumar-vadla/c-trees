#include "binary_search_tree.h"

Tree_ptr create_tree()
{
  Tree_ptr tree = malloc(sizeof(Tree));
  if (tree != NULL)
  {
    tree->root = NULL;
  }
  return tree;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node != NULL)
  {
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
  }
  return new_node;
}
