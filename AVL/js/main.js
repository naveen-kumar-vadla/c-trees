const Traversals = require('./traversals');
const { insert_node, get_max_of_tree, get_min_of_tree } = require('./tree');

const main = () => {
  let values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
  let tree = values.reduce(insert_node, null);
  console.log('in_order');
  Traversals.print_in_order(tree);
  console.log('');
  console.log('pre_order');
  Traversals.print_pre_order(tree);
  console.log('');
  console.log('post_order');
  Traversals.print_post_order(tree);
  console.log('');

  const min_of_tree = get_min_of_tree(tree);
  const max_of_tree = get_max_of_tree(tree);
  console.log('\nMin of Tree', min_of_tree.value);
  console.log('Max of Tree', max_of_tree.value, '\n');
};

main();
