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

Bool is_lessthan_int(Element a, Element b)
{
  return *(int *)a < *(int *)b;
}

Bool is_lessthan_char(Element a, Element b)
{
  return *(char *)a < *(char *)b;
}

int main()
{
  Tree_ptr tree = create_tree();
  insert_into_tree(tree, create_int_element(3), &is_lessthan_int);
  insert_into_tree(tree, create_int_element(1), &is_lessthan_int);
  insert_into_tree(tree, create_int_element(5), &is_lessthan_int);
  insert_into_tree(tree, create_int_element(2), &is_lessthan_int);
  insert_into_tree(tree, create_int_element(0), &is_lessthan_int);
  insert_into_tree(tree, create_int_element(4), &is_lessthan_int);
  insert_into_tree(tree, create_int_element(6), &is_lessthan_int);

  printf("in_order\n");
  print_in_order(tree->root, &display_int_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree->root, &display_int_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree->root, &display_int_element);
  printf("\n\n");

  tree = create_tree();
  insert_into_tree(tree, create_char_element('d'), &is_lessthan_char);
  insert_into_tree(tree, create_char_element('b'), &is_lessthan_char);
  insert_into_tree(tree, create_char_element('f'), &is_lessthan_char);
  insert_into_tree(tree, create_char_element('c'), &is_lessthan_char);
  insert_into_tree(tree, create_char_element('a'), &is_lessthan_char);
  insert_into_tree(tree, create_char_element('e'), &is_lessthan_char);
  insert_into_tree(tree, create_char_element('g'), &is_lessthan_char);

  printf("in_order\n");
  print_in_order(tree->root, &display_char_element);
  printf("\n\n");

  printf("pre_order\n");
  print_pre_order(tree->root, &display_char_element);
  printf("\n\n");

  printf("post_order\n");
  print_post_order(tree->root, &display_char_element);
  printf("\n\n");
}