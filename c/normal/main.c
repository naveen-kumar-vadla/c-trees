#include "binary_search_tree.h"

int main()
{
  Tree_ptr tree = create_tree();
  insert_into_tree(tree, 3);
  insert_into_tree(tree, 1);
  insert_into_tree(tree, 5);
  insert_into_tree(tree, 2);
  insert_into_tree(tree, 0);
  insert_into_tree(tree, 4);
  insert_into_tree(tree, 6);

  printf("in_order\n");
  print_in_order(tree->root);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree->root);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree->root);
  printf("\n\n");

  Bool result = search_in_tree(tree, 3);
  printf("%d is %s in the list\n", 3, result ? "present" : "not present");

  result = search_in_tree(tree, 1);
  printf("%d is %s in the list\n", 1, result ? "present" : "not present");

  result = search_in_tree(tree, 5);
  printf("%d is %s in the list\n", 5, result ? "present" : "not present");

  result = search_in_tree(tree, 2);
  printf("%d is %s in the list\n", 2, result ? "present" : "not present");

  result = search_in_tree(tree, 0);
  printf("%d is %s in the list\n", 0, result ? "present" : "not present");

  result = search_in_tree(tree, 4);
  printf("%d is %s in the list\n", 4, result ? "present" : "not present");

  result = search_in_tree(tree, 6);
  printf("%d is %s in the list\n", 6, result ? "present" : "not present");

  result = search_in_tree(tree, 9);
  printf("%d is %s in the list\n", 9, result ? "present" : "not present");

  printf("\n");
}