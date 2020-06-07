#include "binary_search_tree_void.h"

Node_ptr create_node(Element value)
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

Node_ptr insert_into_tree(Node_ptr root, Element value, Compare_Method *comparator)
{
  Node_ptr *pos_to_insert = &root;
  Node_ptr p_walk = root;
  while (p_walk != NULL)
  {
    pos_to_insert = &p_walk->right;
    Node_ptr p_walk_to_set = p_walk->right;
    if ((*comparator)(value, p_walk->value) == Lesser)
    {
      pos_to_insert = &p_walk->left;
      p_walk_to_set = p_walk->left;
    }
    p_walk = p_walk_to_set;
  }
  *pos_to_insert = create_node(value);
  return root;
}

Bool search_in_node(Node_ptr root, Element value, Compare_Method *comparator)
{
  Bool result = False;
  Node_ptr p_walk = root;
  while (p_walk != NULL && !result)
  {
    if ((*comparator)(value, p_walk->value) == Equal)
    {
      result = True;
    }
    Node_ptr ptr_to_set_p_walk = p_walk->right;
    if ((*comparator)(value, p_walk->value) == Lesser)
    {
      ptr_to_set_p_walk = p_walk->left;
    }
    p_walk = ptr_to_set_p_walk;
  }
  return result;
}

Node_ptr get_min_of_right(Node_ptr root)
{
  Node_ptr min_of_right = root;
  while (min_of_right && min_of_right->left != NULL)
  {
    min_of_right = min_of_right->left;
  }
  return min_of_right;
}

Node_ptr delete_node(Node_ptr root, Element value, Compare_Method *comparator)
{
  if (root == NULL)
    return root;
  Compare_Status result = (*comparator)(value, root->value);
  root->left = result == Lesser ? delete_node(root->left, value, comparator) : root->left;
  root->right = result == Greater ? delete_node(root->right, value, comparator) : root->right;
  if (result == Equal)
  {
    if (root->left == NULL || root->right == NULL)
    {
      Node_ptr temp = root->left ? root->left : root->right;
      free(root);
      return temp;
    }
    Node_ptr minOfRight = get_min_of_right(root->right);
    root->value = minOfRight->value;
    root->right = delete_node(root->right, minOfRight->value, comparator);
  }
  return root;
}

Node_ptr get_node_of(Node_ptr root, Element value, Compare_Method *comparator)
{
  Compare_Status result = (*comparator)(value, root->value);
  if (root == NULL || result == Equal)
    return root;
  if (result == Lesser)
    return get_node_of(root->left, value, comparator);
  return get_node_of(root->right, value, comparator);
}

Node_ptr rotate_right(Node_ptr root, Node_ptr pivot, Compare_Method *comparator)
{
  if (root == NULL)
    return root;
  Compare_Status result = (*comparator)(pivot->value, root->value);
  if (result == Lesser)
  {
    root->left = rotate_right(root->left, pivot, comparator);
    return root;
  }
  if (result == Greater)
  {
    root->right = rotate_right(root->right, pivot, comparator);
    return root;
  }
  Node_ptr pivot_left = pivot->left;
  if (pivot_left == NULL)
    return pivot;
  pivot->left = pivot_left->right;
  pivot_left->right = pivot;
  return pivot_left;
}

Node_ptr rotate_left(Node_ptr root, Node_ptr pivot, Compare_Method *comparator)
{
  if (root == NULL)
    return root;
  Compare_Status result = (*comparator)(pivot->value, root->value);
  if (result == Lesser)
  {
    root->left = rotate_left(root->left, pivot, comparator);
    return root;
  }
  if (result == Greater)
  {
    root->right = rotate_left(root->right, pivot, comparator);
    return root;
  }
  Node_ptr pivot_right = pivot->right;
  if (pivot_right == NULL)
    return pivot;
  pivot->right = pivot_right->left;
  pivot_right->left = pivot;
  return pivot_right;
}

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