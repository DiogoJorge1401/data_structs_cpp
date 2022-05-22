#include <iostream>
#include <cstddef>
#include "dynamicQueue.h"

using namespace std;

DynamicQueue::DynamicQueue()
{
  first = NULL;
  last = NULL;
}
DynamicQueue::~DynamicQueue()
{
  Node *temp = first;
  while (first)
  {
    first = temp->next;
    delete temp;
  }
  last = NULL;
}
bool DynamicQueue::isFull()
{
  Node *temp;
  try
  {
    temp = new Node;
    delete temp;
    return false;
  }
  catch (bad_alloc err)
  {
    return true;
  }
}
bool DynamicQueue::isEmpty()
{
  return first == NULL;
}
void DynamicQueue::enqueue(ItemType item)
{
  if (isFull())
  {
    cout << "The queue is full!\n";
    return;
  }

  Node *newNode = new Node;
  newNode->value = item;
  newNode->next = NULL;

  if (!first)
    first = newNode;
  else
    last->next = newNode;

  last = newNode;
}
ItemType DynamicQueue::dequeue()
{
  if (isEmpty())
  {
    cout << "\nThe queue is empty!\n";
    return 0;
  }

  Node *temp = first;
  ItemType value = first->value;

  first = first->next;
  if (!first)
    last = NULL;

  delete temp;
  return value;
}
void DynamicQueue::print()
{

  Node *temp = first;
  cout << "Dynamic Queue [ ";
  while (temp)
  {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << "]\n";
}