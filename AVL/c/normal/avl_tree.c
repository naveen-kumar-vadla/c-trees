#include "avl_tree.h"

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

int get_tree_height(Node_ptr root, int height)
{
  if (root == NULL)
    return height;
  int left_height = get_tree_height(root->left, height + 1);
  int right_height = get_tree_height(root->right, height + 1);
  return MAX(left_height, right_height);
}

int get_balance_factor(Node_ptr root)
{
  if (root == NULL)
    return 0;
  int left_height = get_tree_height(root->left, 0);
  int right_height = get_tree_height(root->right, 0);
  return left_height - right_height;
}

Node_ptr left_rotate(Node_ptr root)
{
  Node_ptr root_right = root->right;
  if (root_right == NULL)
    return root;
  root->right = root_right->left;
  root_right->left = root;
  return root_right;
}

Node_ptr right_rotate(Node_ptr root)
{
  Node_ptr root_left = root->left;
  if (root_left == NULL)
    return root;
  root->left = root_left->right;
  root_left->right = root;
  return root_left;
}

Node_ptr balance_tree(Node_ptr root, int value)
{
  int balance_factor = get_balance_factor(root);
  if (balance_factor > 1)
  {
    if (value > root->left->value)
      root->left = left_rotate(root->left);
    return right_rotate(root);
  }
  if (balance_factor < -1)
  {
    if (value < root->right->value)
      root->right = right_rotate(root->right);
    return left_rotate(root);
  }
  return root;
}

Node_ptr insert_into_tree(Node_ptr root, int value)
{
  if (root == NULL)
    return create_node(value);
  if (value < root->value)
    root->left = insert_into_tree(root->left, value);
  else
    root->right = insert_into_tree(root->right, value);
  return balance_tree(root, value);
}

Node_ptr get_min_of_tree(Node_ptr root)
{
  Node_ptr min_of_tree = root;
  while (min_of_tree != NULL && min_of_tree->left != NULL)
  {
    min_of_tree = min_of_tree->left;
  }
  return min_of_tree;
}

Node_ptr get_max_of_tree(Node_ptr root)
{
  Node_ptr max_of_tree = root;
  while (max_of_tree != NULL && max_of_tree->right != NULL)
  {
    max_of_tree = max_of_tree->right;
  }
  return max_of_tree;
}

Node_ptr delete_node(Node_ptr root, int value)
{
  if (root == NULL)
    return root;
  root->left = value < root->value ? delete_node(root->left, value) : root->left;
  root->right = value > root->value ? delete_node(root->right, value) : root->right;
  if (value == root->value)
  {
    if (root->left == NULL || root->right == NULL)
    {
      Node_ptr temp = root->left ? root->left : root->right;
      free(root);
      return temp;
    }
    Node_ptr minOfRight = get_min_of_tree(root->right);
    root->value = minOfRight->value;
    root->right = delete_node(root->right, minOfRight->value);
  }
  return balance_tree(root, value);
}

Bool search_in_tree(Node_ptr root, int value)
{
  if (root == NULL)
    return False;
  if (value == root->value)
    return True;
  if (value < root->value)
    return search_in_tree(root->left, value);
  return search_in_tree(root->right, value);
}
