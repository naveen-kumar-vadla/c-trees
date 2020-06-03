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

void insert_into_tree(Tree_ptr tree, int value)
{
  Node_ptr *pos_to_insert = &tree->root;
  Node_ptr p_walk = tree->root;
  while (p_walk != NULL)
  {
    pos_to_insert = &p_walk->right;
    Node_ptr p_walk_to_set = p_walk->right;
    if (value < p_walk->value)
    {
      pos_to_insert = &p_walk->left;
      p_walk_to_set = p_walk->left;
    }
    p_walk = p_walk_to_set;
  }
  *pos_to_insert = create_node(value);
}

Bool search_in_tree(Tree_ptr tree, int value)
{
  Bool result = False;
  Node_ptr p_walk = tree->root;
  while (p_walk != NULL && !result)
  {
    if (p_walk->value == value)
    {
      result = True;
    }
    Node_ptr ptr_to_set_p_walk = p_walk->right;
    if (value < p_walk->value)
    {
      ptr_to_set_p_walk = p_walk->left;
    }
    p_walk = ptr_to_set_p_walk;
  }
  return result;
}

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