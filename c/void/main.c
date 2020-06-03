#include "binary_search_tree_void.h"

Element create_int_element(int value)
{
  Element element = malloc(sizeof(int));
  *(int *)element = value;
  return element;
}

Bool is_lessthan_int(Element a, Element b)
{
  return *(int *)a < *(int *)b;
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
}