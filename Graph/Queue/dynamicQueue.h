#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include "../Node/node.h"
class DynamicQueue
{
private:
  Node *first;
  Node *last;

public:
  DynamicQueue();
  ~DynamicQueue();
  bool isFull();
  bool isEmpty();
  void enqueue(ItemType);
  ItemType dequeue();
  void print();
};

#endif