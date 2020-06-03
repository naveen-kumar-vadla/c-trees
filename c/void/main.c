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

Bool is_less_than_int(Element a, Element b)
{
  return *(int *)a < *(int *)b;
}

Bool is_less_than_char(Element a, Element b)
{
  return *(char *)a < *(char *)b;
}

Bool is_equal_to_int(Element a, Element b)
{
  return *(int *)a == *(int *)b;
}

Bool is_equal_to_char(Element a, Element b)
{
  return *(char *)a == *(char *)b;
}

int main()
{
  Tree_ptr tree = create_tree();
  insert_into_tree(tree, create_int_element(3), &is_less_than_int);
  insert_into_tree(tree, create_int_element(1), &is_less_than_int);
  insert_into_tree(tree, create_int_element(5), &is_less_than_int);
  insert_into_tree(tree, create_int_element(2), &is_less_than_int);
  insert_into_tree(tree, create_int_element(0), &is_less_than_int);
  insert_into_tree(tree, create_int_element(4), &is_less_than_int);
  insert_into_tree(tree, create_int_element(6), &is_less_than_int);

  printf("in_order\n");
  print_in_order(tree->root, &display_int_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree->root, &display_int_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree->root, &display_int_element);
  printf("\n\n");

  Bool result = search_in_node(tree, create_int_element(3), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 3, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(1), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 1, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(5), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 5, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(2), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 2, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(0), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 0, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(4), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 4, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(6), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 6, result ? "present" : "not present");

  result = search_in_node(tree, create_int_element(9), &is_less_than_int, &is_equal_to_int);
  printf("%d is %s in the list\n", 9, result ? "present" : "not present");
  printf("\n");

  tree = create_tree();
  insert_into_tree(tree, create_char_element('d'), &is_less_than_char);
  insert_into_tree(tree, create_char_element('b'), &is_less_than_char);
  insert_into_tree(tree, create_char_element('f'), &is_less_than_char);
  insert_into_tree(tree, create_char_element('c'), &is_less_than_char);
  insert_into_tree(tree, create_char_element('a'), &is_less_than_char);
  insert_into_tree(tree, create_char_element('e'), &is_less_than_char);
  insert_into_tree(tree, create_char_element('g'), &is_less_than_char);

  printf("in_order\n");
  print_in_order(tree->root, &display_char_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree->root, &display_char_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree->root, &display_char_element);
  printf("\n\n");

  result = search_in_node(tree, create_char_element('d'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'd', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('b'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'b', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('f'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'f', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('c'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'c', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('a'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'a', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('e'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'e', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('g'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'g', result ? "present" : "not present");

  result = search_in_node(tree, create_char_element('j'), &is_less_than_char, &is_equal_to_char);
  printf("%c is %s in the list\n", 'j', result ? "present" : "not present");
  printf("\n");
}