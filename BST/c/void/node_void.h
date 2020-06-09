#ifndef __NODE_H_
#define __NODE_H_

typedef void *Element;

typedef struct node
{
  Element value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

#endif