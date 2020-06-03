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
}