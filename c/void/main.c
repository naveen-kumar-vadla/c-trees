#include "binary_search_tree_void.h"
#include "traversals_void.h"

Element create_int_element(int value)
{
  Element element = malloc(sizeof(int));
  *(int *)element = value;
  return element;
}

Element create_char_element(char value)
{
  Element element = malloc(sizeof(char));
  *(char *)element = value;
  return element;
}

void display_int_element(Element number)
{
  printf("%d ", *(int *)number);
}

void display_char_element(Element number)
{
  printf("%c ", *(char *)number);
}

Compare_Status comparator_int(Element a, Element b)
{
  Compare_Status status = Equal;
  if (*(int *)a < *(int *)b)
  {
    status = Lesser;
  }
  if (*(int *)a > *(int *)b)
  {
    status = Greater;
  }
  return status;
}

Compare_Status comparator_char(Element a, Element b)
{
  Compare_Status status = Equal;
  if (*(char *)a < *(char *)b)
  {
    status = Lesser;
  }
  if (*(char *)a > *(char *)b)
  {
    status = Greater;
  }
  return status;
}

int main()
{
  // ------------------------------------------------ Int Array ------------------------------------------------
  Node_ptr tree = NULL;
  tree = insert_into_tree(tree, create_int_element(3), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(1), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(5), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(2), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(0), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(4), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(6), &comparator_int);

  printf("Before Deletion\n");

  printf("in_order\n");
  print_in_order(tree, &display_int_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree, &display_int_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree, &display_int_element);
  printf("\n\n");

  Bool result = search_in_node(tree, create_int_element(3), &comparator_int);
  printf("%d is %s in the list\n\n", 3, result ? "present" : "not present");

  tree = delete_node(tree, create_int_element(3), &comparator_int);
  printf("After Deletion\n");

  printf("in_order\n");
  print_in_order(tree, &display_int_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree, &display_int_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree, &display_int_element);
  printf("\n\n");

  result = search_in_node(tree, create_int_element(3), &comparator_int);
  printf("%d is %s in the list\n\n", 3, result ? "present" : "not present");

  destroy_nodes(tree);
  tree = NULL;
  tree = insert_into_tree(tree, create_int_element(3), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(1), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(5), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(2), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(0), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(4), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(6), &comparator_int);

  printf("Rotate Right 1");
  printf("\nbefore => ");
  print_pre_order(tree, &display_int_element);
  tree = rotate_right(tree, get_node_of(tree, create_int_element(1), &comparator_int), &comparator_int);
  printf("\nafter => ");
  print_pre_order(tree, &display_int_element);

  printf("\n\nRotate Left 0");
  printf("\nbefore => ");
  print_pre_order(tree, &display_int_element);
  tree = rotate_left(tree, get_node_of(tree, create_int_element(0), &comparator_int), &comparator_int);
  printf("\nafter => ");
  print_pre_order(tree, &display_int_element);

  destroy_nodes(tree);
  tree = NULL;
  tree = insert_into_tree(tree, create_int_element(1), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(0), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(2), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(3), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(4), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(5), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(6), &comparator_int);

  printf("Before Balancing\n");

  print_pre_order(tree, &display_int_element);
  printf("\n\n");

  tree = balance_tree(tree, &comparator_int);

  printf("After Balancing\n");

  print_pre_order(tree, &display_int_element);
  printf("\n\n");

  // ------------------------------------------------ Char Array ------------------------------------------------

  destroy_nodes(tree);
  tree = NULL;
  tree = insert_into_tree(tree, create_char_element('d'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('b'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('f'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('c'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('a'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('e'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('g'), &comparator_char);

  printf("Before Deletion\n");

  printf("in_order\n");
  print_in_order(tree, &display_char_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree, &display_char_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree, &display_char_element);
  printf("\n\n");

  result = search_in_node(tree, create_char_element('d'), &comparator_char);
  printf("%c is %s in the list\n\n", 'd', result ? "present" : "not present");

  tree = delete_node(tree, create_char_element('d'), &comparator_char);
  printf("After Deletion\n");

  printf("in_order\n");
  print_in_order(tree, &display_char_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree, &display_char_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree, &display_char_element);
  printf("\n\n");

  result = search_in_node(tree, create_char_element('d'), &comparator_char);
  printf("%c is %s in the list\n\n", 'd', result ? "present" : "not present");

  destroy_nodes(tree);
  tree = NULL;
  tree = insert_into_tree(tree, create_char_element('d'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('b'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('f'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('c'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('a'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('e'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('g'), &comparator_char);

  printf("Rotate Right 1");
  printf("\nbefore => ");
  print_pre_order(tree, &display_char_element);
  tree = rotate_right(tree, get_node_of(tree, create_char_element('b'), &comparator_char), &comparator_char);
  printf("\nafter => ");
  print_pre_order(tree, &display_char_element);

  printf("\n\nRotate Left 0");
  printf("\nbefore => ");
  print_pre_order(tree, &display_char_element);
  tree = rotate_left(tree, get_node_of(tree, create_char_element('a'), &comparator_char), &comparator_char);
  printf("\nafter => ");
  print_pre_order(tree, &display_char_element);
  printf("\n\n");

  destroy_nodes(tree);
  tree = NULL;
  tree = insert_into_tree(tree, create_char_element('b'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('a'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('c'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('d'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('e'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('f'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('g'), &comparator_char);

  printf("Before Balancing\n");

  print_pre_order(tree, &display_char_element);
  printf("\n\n");

  tree = balance_tree(tree, &comparator_char);

  printf("After Balancing\n");

  print_pre_order(tree, &display_char_element);
  printf("\n\n");
}