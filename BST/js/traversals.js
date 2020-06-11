const print_in_order = tree => {
  if (tree == null) return;
  print_in_order(tree.left);
  process.stdout.write(`${tree.value} `);
  print_in_order(tree.right);
};

const print_pre_order = tree => {
  if (tree == null) return;
  process.stdout.write(`${tree.value} `);
  print_pre_order(tree.left);
  print_pre_order(tree.right);
};

const print_post_order = tree => {
  if (tree == null) return;
  print_post_order(tree.left);
  print_post_order(tree.right);
  process.stdout.write(`${tree.value} `);
};

module.exports = { print_in_order, print_post_order, print_pre_order };
