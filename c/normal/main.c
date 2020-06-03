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
}