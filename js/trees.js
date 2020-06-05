const Traversals = require('./traversals');
const { insert_node, search_node, delete_node } = require('./tree_with_recur');

const main = () => {
  let values = [3, 1, 5, 0, 2, 4, 6];
  let tree = values.reduce(insert_node, null);

  console.log('tree =>');
  Traversals.print_in_order(tree);

  let result = search_node(tree, 3);
  console.log(3, 'is', result ? '' : 'not', 'present in the tree.');

  tree = delete_node(tree, 3);
  console.log('tree =>');
  Traversals.print_in_order(tree);

  result = search_node(tree, 3);
  console.log(3, 'is', result ? '' : 'not', 'present in the tree.');
};

main();
