#ifndef __NODE_H_
#define __NODE_H_

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

#endif