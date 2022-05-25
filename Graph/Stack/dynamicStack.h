#ifndef DYNAMICSTACK_H
#define DYAMICSTACK_H

#include "../Node/node.h"

class DynamicStack
{
private:
  Node *topNode;

public:
  DynamicStack();
  ~DynamicStack();
  bool isFull();
  bool isEmpty();
  void push(ItemType);
  ItemType pop();
  void print();
};
#endif