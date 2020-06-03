const createNode = value => {
  return { value, left: null, right: null };
};

const insert = (tree, value) => {
  if (tree == null) return createNode(value);
  if (value < tree.value) tree.left = insert(tree.left, value);
  else tree.right = insert(tree.right, value);
  return tree;
};

const printInOrder = tree => {
  if (tree == null) return;
  printInOrder(tree.left);
  console.log(tree.value);
  printInOrder(tree.right);
};

const printPreOrder = tree => {
  if (tree == null) return;
  console.log(tree.value);
  printPreOrder(tree.left);
  printPreOrder(tree.right);
};

const printPostOrder = tree => {
  if (tree == null) return;
  printPostOrder(tree.left);
  printPostOrder(tree.right);
  console.log(tree.value);
};

const main = () => {
  const values = [3, 1, 5, 2, 0, 4, 6];
  const tree = values.reduce(insert, null);

  console.log('printInOrder');
  printInOrder(tree);
  console.log('\n');

  console.log('printPreOrder');
  printPreOrder(tree);
  console.log('\n');

  console.log('printPostOrd');
  printPostOrder(tree);
  console.log('\n');
};

main();
