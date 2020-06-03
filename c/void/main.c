#include "binary_search_tree_void.h"

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
  Tree_ptr tree = create_tree();
  insert_into_tree(tree, create_int_element(3), &comparator_int);
  insert_into_tree(tree, create_int_element(1), &comparator_int);
  insert_into_tree(tree, create_int_element(5), &comparator_int);
  insert_into_tree(tree, create_int_element(2), &comparator_int);
  insert_into_tree(tree, create_int_element(0), &comparator_int);
  insert_into_tree(tree, create_int_element(4), &comparator_int);
  insert_into_tree(tree, create_int_element(6), &comparator_int);

  printf("in_order\n");
  print_in_order(tree->root, &display_int_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree->root, &display_int_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree->root, &display_int_element);
  printf("\n\n");

  Bool result = search_in_node(tree, create_int_element(3), &comparator_int);
  printf("%d is %s in the list\n", 3, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(1), &comparator_int);
  printf("%d is %s in the list\n", 1, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(5), &comparator_int);
  printf("%d is %s in the list\n", 5, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(2), &comparator_int);
  printf("%d is %s in the list\n", 2, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(0), &comparator_int);
  printf("%d is %s in the list\n", 0, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(4), &comparator_int);
  printf("%d is %s in the list\n", 4, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(6), &comparator_int);
  printf("%d is %s in the list\n", 6, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(9), &comparator_int);
  printf("%d is %s in the list\n", 9, result ? "present" : "not present");
  printf("\n");

  tree = create_tree();
  insert_into_tree(tree, create_char_element('d'), &comparator_char);
  insert_into_tree(tree, create_char_element('b'), &comparator_char);
  insert_into_tree(tree, create_char_element('f'), &comparator_char);
  insert_into_tree(tree, create_char_element('c'), &comparator_char);
  insert_into_tree(tree, create_char_element('a'), &comparator_char);
  insert_into_tree(tree, create_char_element('e'), &comparator_char);
  insert_into_tree(tree, create_char_element('g'), &comparator_char);

  printf("in_order\n");
  print_in_order(tree->root, &display_char_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree->root, &display_char_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree->root, &display_char_element);
  printf("\n\n");

  result = search_in_node(tree, create_char_element('d'), &comparator_char);
  printf("%c is %s in the list\n", 'd', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('b'), &comparator_char);
  printf("%c is %s in the list\n", 'b', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('f'), &comparator_char);
  printf("%c is %s in the list\n", 'f', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('c'), &comparator_char);
  printf("%c is %s in the list\n", 'c', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('a'), &comparator_char);
  printf("%c is %s in the list\n", 'a', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('e'), &comparator_char);
  printf("%c is %s in the list\n", 'e', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('g'), &comparator_char);
  printf("%c is %s in the list\n", 'g', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('j'), &comparator_char);
  printf("%c is %s in the list\n", 'j', result ? "present" : "not present");
  printf("\n");
}