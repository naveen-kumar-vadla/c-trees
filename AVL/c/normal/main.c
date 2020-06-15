#include "avl_tree.h"
#include "traversals.h"

void display_tree_in_all_traversals(Node_ptr root);
void display_tree_in_all_traversals(Node_ptr root)
{
  printf("\nin_order\n");
  print_in_order(root);
  printf("\n");
  printf("\npre_order\n");
  print_pre_order(root);
  printf("\n");
  printf("\npost_order\n");
  print_post_order(root);
  printf("\n\n");
}

int main()
{
  Node_ptr tree = NULL;
  tree = insert_into_tree(tree, 1);
  tree = insert_into_tree(tree, 2);
  tree = insert_into_tree(tree, 3);
  tree = insert_into_tree(tree, 4);
  tree = insert_into_tree(tree, 5);
  tree = insert_into_tree(tree, 6);
  tree = insert_into_tree(tree, 7);
  tree = insert_into_tree(tree, 8);
  tree = insert_into_tree(tree, 9);
  tree = insert_into_tree(tree, 0);

  display_tree_in_all_traversals(tree);
}