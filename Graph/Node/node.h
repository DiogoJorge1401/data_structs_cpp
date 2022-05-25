#ifndef NODE_H
#define NODE_H

#include <iostream>
typedef std::string ItemType;

struct Node
{
  ItemType value;
  Node *next;
};

#endif