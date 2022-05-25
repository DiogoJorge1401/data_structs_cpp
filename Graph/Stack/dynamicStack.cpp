#include <iostream>
#include <cstddef>
#include "dynamicStack.h"

using namespace std;

DynamicStack::DynamicStack()
{
  topNode = NULL;
}
DynamicStack::~DynamicStack()
{
  Node *temp = topNode;
  while (topNode)
  {
    temp = topNode->next;
    delete topNode;
    topNode = temp;
  }
}
bool DynamicStack::isEmpty()
{
  return topNode == NULL;
}
bool DynamicStack::isFull()
{
  Node *newNode;
  try
  {
    newNode = new Node;
    delete newNode;
    return false;
  }
  catch (bad_alloc err)
  {
    return true;
  }
}
void DynamicStack::push(ItemType item)
{
  if (isFull())
  {
    cout << "The stack is full!\n";
    return;
  }
  Node *newNode = new Node;
  newNode->value = item;
  newNode->next = topNode;
  topNode = newNode;
}
ItemType DynamicStack::pop()
{
  if (isEmpty())
  {
    cout << "The stack is empty!\n";
    return 0;
  }

  Node *temp = topNode;
  ItemType value = topNode->value;
  topNode = topNode->next;

  delete temp;
  return value;
}
void DynamicStack::print()
{
  Node *temp = topNode;
  cout << "Dynamic Stack [ ";
  while (temp)
  {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << "]\n";
}