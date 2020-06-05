'use strict';

const assert = require('assert');

const create_node = value => {
  return { value, left: null, right: null };
};

const insert_with_recur = (tree, value) => {
  if (tree == null) return create_node(value);
  if (value < tree.value) tree.left = insert_with_recur(tree.left, value);
  else tree.right = insert_with_recur(tree.right, value);
  return tree;
};

const insert_without_recur = (tree, value) => {
  const new_node = create_node(value);
  let pos_to_insert = null;
  let walker = tree;
  while (walker != null) {
    pos_to_insert = walker;
    if (value < walker.value) walker = walker.left;
    else walker = walker.right;
  }
  if (pos_to_insert == null) return new_node;
  if (value < pos_to_insert.value) pos_to_insert.left = new_node;
  else pos_to_insert.right = new_node;
  return tree;
};

const search_node = (tree, value) => {
  let result = false;
  let walker = tree;
  while (walker != null && !result) {
    if (value == walker.value) result = true;
    if (value < walker.value) walker = walker.left;
    else walker = walker.right;
  }
  return result;
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

const print_in_order = tree => {
  if (tree == null) return;
  print_in_order(tree.left);
  console.log(tree.value);
  print_in_order(tree.right);
};

const create_random_array = length => {
  const array = [];
  while (array.length < length) {
    const num = Math.floor(Math.random() * length);
    !array.includes(num) && array.push(num);
  }
  return array;
};

const main = () => {
  for (const length of [10, 100, 1000]) {
    const values = create_random_array(length);
    const tree1 = values.reduce(insert_with_recur, null);
    const tree2 = values.reduce(insert_without_recur, null);
    assert.deepStrictEqual(tree1, tree2);
  }

  let values = [3, 1, 5, 0, 2, 4, 6];
  let tree = values.reduce(insert_without_recur, null);

  console.log('tree =>');
  print_in_order(tree);

  for (const value of [...values, 9]) {
    const result = search_node(tree, value);
    console.log(value, 'is', result ? '' : 'not', 'present in the tree.');
  }

  console.log('deletion of node (node with 2 children)');

  tree = [3, 1, 5, 0, 2, 4, 6].reduce(insert_without_recur, null);
  console.log('tree =>');
  print_in_order(tree);

  tree = delete_node(tree, 3);
  console.log('tree =>');
  print_in_order(tree);

  console.log('deletion of node (node with 1 children)');

  tree = [3, 1, 5, 0, 2, 4].reduce(insert_without_recur, null);
  console.log('tree =>');
  print_in_order(tree);

  tree = delete_node(tree, 5);
  console.log('tree =>');
  print_in_order(tree);

  console.log('deletion of node (node with 0 children)');

  tree = [3, 1, 5, 0, 2].reduce(insert_without_recur, null);
  console.log('tree =>');
  print_in_order(tree);

  tree = delete_node(tree, 5);
  console.log('tree =>');
  print_in_order(tree);
};

main();
