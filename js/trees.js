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

const createRandomArray = length => {
  const array = [];
  while (array.length < length) {
    const num = Math.floor(Math.random() * length);
    !array.includes(num) && array.push(num);
  }
  return array;
};

const main = () => {
  for (const length in [10, 100, 1000]) {
    const values = createRandomArray(length);
    const tree1 = values.reduce(insert_with_recur, null);
    const tree2 = values.reduce(insert_without_recur, null);
    assert.deepStrictEqual(tree1, tree2);
  }
};

main();

/* 
4 to insert
  5
3   6

*/
