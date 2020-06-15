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

  Node_ptr min_of_tree = get_min_of_tree(tree);
  Node_ptr max_of_tree = get_max_of_tree(tree);
  printf("Min of Tree %d\n", min_of_tree->value);
  printf("Max of Tree %d\n", max_of_tree->value);

  Bool result = search_in_tree(tree, 2);
  printf("%d is %s in the list\n\n", 2, result ? "present" : "not present");

  tree = delete_node(tree, 2);
  printf("\nTree after deleting 2\n");
  display_tree_in_all_traversals(tree);

  result = search_in_tree(tree, 2);
  printf("%d is %s in the list\n\n", 2, result ? "present" : "not present");
}