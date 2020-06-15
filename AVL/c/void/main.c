#include "avl_tree_void.h"
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

void display_tree_in_all_traversals(Node_ptr root, Display_Data *displayer);
void display_tree_in_all_traversals(Node_ptr root, Display_Data *displayer)
{
  printf("\nin_order\n");
  print_in_order(root, displayer);
  printf("\n");
  printf("\npre_order\n");
  print_pre_order(root, displayer);
  printf("\n");
  printf("\npost_order\n");
  print_post_order(root, displayer);
  printf("\n\n");
}

int main()
{
  // ------------------------------------------------ Int Array ------------------------------------------------
  Node_ptr tree = NULL;
  tree = insert_into_tree(tree, create_int_element(0), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(1), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(2), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(3), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(4), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(5), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(6), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(7), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(8), &comparator_int);
  tree = insert_into_tree(tree, create_int_element(9), &comparator_int);
  display_tree_in_all_traversals(tree, &display_int_element);

  Node_ptr min_of_tree = get_min_of_tree(tree);
  Node_ptr max_of_tree = get_max_of_tree(tree);
  printf("Min of Tree ");
  display_int_element(min_of_tree->value);
  printf("\n");
  printf("Max of Tree ");
  display_int_element(max_of_tree->value);
  printf("\n\n");

  tree = delete_node(tree, create_int_element(2), &comparator_int);
  printf("Tree after deleting 2\n");
  display_tree_in_all_traversals(tree, &display_int_element);

  // ------------------------------------------------ Char Array ------------------------------------------------

  tree = NULL;
  tree = insert_into_tree(tree, create_char_element('a'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('b'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('c'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('d'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('e'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('f'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('g'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('h'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('i'), &comparator_char);
  tree = insert_into_tree(tree, create_char_element('j'), &comparator_char);
  display_tree_in_all_traversals(tree, &display_char_element);

  min_of_tree = get_min_of_tree(tree);
  max_of_tree = get_max_of_tree(tree);
  printf("Min of Tree ");
  display_char_element(min_of_tree->value);
  printf("\n");
  printf("Max of Tree ");
  display_char_element(max_of_tree->value);
  printf("\n\n");

  tree = delete_node(tree, create_char_element('c'), &comparator_char);
  printf("Tree after deleting c\n");
  display_tree_in_all_traversals(tree, &display_char_element);
}