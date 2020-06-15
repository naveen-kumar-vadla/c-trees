const Traversals = require('./traversals');
const {
  insert_node,
  get_max_of_tree,
  get_min_of_tree,
  delete_node,
} = require('./tree');

const display_tree_in_all_traversals = tree => {
  console.log('\nin_order');
  Traversals.print_in_order(tree);
  console.log('');
  console.log('pre_order');
  Traversals.print_pre_order(tree);
  console.log('');
  console.log('post_order');
  Traversals.print_post_order(tree);
  console.log('\n');
};

const main = () => {
  let values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
  let tree = values.reduce(insert_node, null);

  display_tree_in_all_traversals(tree);

  const min_of_tree = get_min_of_tree(tree);
  const max_of_tree = get_max_of_tree(tree);
  console.log('Min of Tree', min_of_tree.value);
  console.log('Max of Tree', max_of_tree.value);

  tree = delete_node(tree, 2);
  display_tree_in_all_traversals(tree);
};

main();
