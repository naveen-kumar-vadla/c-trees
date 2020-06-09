const Traversals = require('./traversals');
const {
  insert_node,
  search_node,
  delete_node,
  rotate_left,
  rotate_right,
  get_node_of,
  balance_tree,
  get_max_of_tree,
  get_min_of_tree,
} = require('./tree_with_recur');

const main = () => {
  let values = [3, 1, 5, 0, 2, 4, 6];
  let tree = values.reduce(insert_node, null);

  console.log('tree =>');
  Traversals.print_in_order(tree);

  const min_of_tree = get_min_of_tree(tree);
  const max_of_tree = get_max_of_tree(tree);
  console.log('Min of Tree', min_of_tree.value);
  console.log('Max of Tree', max_of_tree.value);

  let result = search_node(tree, 3);
  console.log(3, 'is', result ? '' : 'not', 'present in the tree.');

  tree = delete_node(tree, 3);
  console.log('tree =>');
  Traversals.print_in_order(tree);

  result = search_node(tree, 3);
  console.log(3, 'is', result ? '' : 'not', 'present in the tree.');

  tree = values.reduce(insert_node, null);
  console.log('Rotate Right 1');
  console.log('before =>');
  Traversals.print_pre_order(tree);
  tree = rotate_right(tree, get_node_of(tree, 1));
  console.log('after =>');
  Traversals.print_pre_order(tree);

  console.log('Rotate Left 0');
  console.log('before =>');
  Traversals.print_pre_order(tree);
  tree = rotate_left(tree, get_node_of(tree, 0));
  console.log('after =>');
  Traversals.print_pre_order(tree);

  values = [1, 0, 2, 3, 4, 5, 6];
  tree = values.reduce(insert_node, null);

  console.log('Before Balancing');
  Traversals.print_pre_order(tree);

  tree = balance_tree(tree);

  console.log('After Balancing');
  Traversals.print_pre_order(tree);
};

main();

/*
     3
   /   \
  1     5
 / \   / \
0   2 4   6
*/
