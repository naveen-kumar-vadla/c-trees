const createNode = value => {
  return { value, left: null, right: null };
};

const insert_node = (tree, value) => {
  if (tree == null) return createNode(value);
  if (value < tree.value) tree.left = insert_node(tree.left, value);
  else tree.right = insert_node(tree.right, value);
  return tree;
};

const search_node = (tree, value) => {
  if (tree == null) return false;
  if (value == tree.value) return true;
  if (value < tree.value) return search_node(tree.left, value);
  return search_node(tree.right, value);
};

const get_min_of_right = tree => {
  let min_of_right = tree;
  while (min_of_right && min_of_right.left != null) {
    min_of_right = min_of_right.left;
  }
  return min_of_right;
};

const delete_node = (tree, value) => {
  if (tree == null) return tree;
  tree.left = value < tree.value ? delete_node(tree.left, value) : tree.left;
  tree.right = value > tree.value ? delete_node(tree.right, value) : tree.right;
  if (value == tree.value) {
    if (tree.left == null || tree.right == null)
      return tree.left ? tree.left : tree.right;
    const minOfRight = get_min_of_right(tree.right);
    tree.value = minOfRight.value;
    tree.right = delete_node(tree.right, minOfRight.value);
  }
  return tree;
};

module.exports = { insert_node, search_node, delete_node };
