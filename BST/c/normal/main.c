#include "binary_search_tree.h"
#include "traversals.h"

int main()
{
  Node_ptr tree = NULL;
  tree = insert_into_tree(tree, 3);
  tree = insert_into_tree(tree, 1);
  tree = insert_into_tree(tree, 5);
  tree = insert_into_tree(tree, 2);
  tree = insert_into_tree(tree, 0);
  tree = insert_into_tree(tree, 4);
  tree = insert_into_tree(tree, 6);

  printf("Before Deletion\n");

  printf("in_order\n");
  print_in_order(tree);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree);
  printf("\n\n");

  Node_ptr min_of_tree = get_min_of_tree(tree);
  Node_ptr max_of_tree = get_max_of_tree(tree);
  printf("Min of Tree %d\n", min_of_tree->value);
  printf("Max of Tree %d\n", max_of_tree->value);

  Bool result = search_in_tree(tree, 3);
  printf("%d is %s in the list\n\n", 3, result ? "present" : "not present");

  tree = delete_node(tree, 3);
  printf("After Deletion\n");

  printf("in_order\n");
  print_in_order(tree);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree);
  printf("\n\n");

  result = search_in_tree(tree, 3);
  printf("%d is %s in the list\n\n", 3, result ? "present" : "not present");

  destroy_nodes(tree);
  tree = NULL;
  tree = insert_into_tree(tree, 3);
  tree = insert_into_tree(tree, 1);
  tree = insert_into_tree(tree, 5);
  tree = insert_into_tree(tree, 2);
  tree = insert_into_tree(tree, 0);
  tree = insert_into_tree(tree, 4);
  tree = insert_into_tree(tree, 6);

  printf("Rotate Right 1");
  printf("\nbefore => ");
  print_pre_order(tree);
  tree = rotate_right(tree, get_node_of(tree, 1));
  printf("\nafter => ");
  print_pre_order(tree);

  printf("\n\nRotate Left 0");
  printf("\nbefore => ");
  print_pre_order(tree);
  tree = rotate_left(tree, get_node_of(tree, 0));
  printf("\nafter => ");
  print_pre_order(tree);
  printf("\n\n");

  destroy_nodes(tree);
  tree = NULL;
  tree = insert_into_tree(tree, 1);
  tree = insert_into_tree(tree, 0);
  tree = insert_into_tree(tree, 2);
  tree = insert_into_tree(tree, 3);
  tree = insert_into_tree(tree, 4);
  tree = insert_into_tree(tree, 5);
  tree = insert_into_tree(tree, 6);

  printf("Before Balancing\n");

  print_pre_order(tree);
  printf("\n\n");

  tree = balance_tree(tree);

  printf("After Balancing\n");

  print_pre_order(tree);
  printf("\n\n");
}