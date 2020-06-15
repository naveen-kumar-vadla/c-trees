const create_node = value => {
  return { value, left: null, right: null };
};

const get_tree_height = (tree, height) => {
  if (tree == null) return height;
  const left_height = get_tree_height(tree.left, height + 1);
  const right_height = get_tree_height(tree.right, height + 1);
  return Math.max(left_height, right_height);
};

const get_balance_factor = tree => {
  if (tree == null) return 0;
  const left_height = get_tree_height(tree.left, 0);
  const right_height = get_tree_height(tree.right, 0);
  return left_height - right_height;
};

const left_rotate = tree => {
  const root_right = tree.right;
  if (root_right == null) return tree;
  tree.right = root_right.left;
  root_right.left = tree;
  return root_right;
};

const right_rotate = tree => {
  const root_left = tree.left;
  if (root_left == null) return tree;
  tree.left = root_left.right;
  root_left.right = tree;
  return root_left;
};

const balance_tree = (tree, value) => {
  const balance_factor = get_balance_factor(tree);
  if (balance_factor > 1 && value < tree.left.value) return right_rotate(tree);
  if (balance_factor < -1 && value > tree.right.value) return left_rotate(tree);
  if (balance_factor > 1 && value > tree.left.value) {
    tree.left = left_rotate(tree.left);
    return right_rotate(tree);
  }
  if (balance_factor < -1 && value < tree.right.value) {
    tree.right = right_rotate(tree.right);
    return left_rotate(tree);
  }
  return tree;
};

const insert_node = (tree, value) => {
  if (tree == null) return create_node(value);
  if (value < tree.value) tree.left = insert_node(tree.left, value);
  else tree.right = insert_node(tree.right, value);
  return balance_tree(tree, value);
};

const get_min_of_tree = tree => {
  let min_of_tree = tree;
  while (min_of_tree && min_of_tree.left != null) {
    min_of_tree = min_of_tree.left;
  }
  return min_of_tree;
};

const get_max_of_tree = tree => {
  let max_of_tree = tree;
  while (max_of_tree && max_of_tree.right != null) {
    max_of_tree = max_of_tree.right;
  }
  return max_of_tree;
};

const delete_node = (tree, value) => {
  tree.left = value < tree.value ? delete_node(tree.left, value) : tree.left;
  tree.right = value > tree.value ? delete_node(tree.right, value) : tree.right;
  if (value == tree.value) {
    if (tree.left == null || tree.right == null)
      return tree.left ? tree.left : tree.right;
    const minOfRight = get_min_of_tree(tree.right);
    tree.value = minOfRight.value;
    tree.right = delete_node(tree.right, minOfRight.value);
  }
  return balance_tree(tree, value);
};

module.exports = { insert_node, get_max_of_tree, get_min_of_tree, delete_node };
