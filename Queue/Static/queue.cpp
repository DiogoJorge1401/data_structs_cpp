#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
  first = 0;
  last = 0;
  structure = new ItemType[max_items];
}
Queue::~Queue()
{
  delete[] structure;
}
bool Queue::isEmpty()
{
  return first == last;
}
bool Queue::isFull()
{
  return (last - first) == max_items;
}
void Queue::enqueue(ItemType item)
{
  if (isFull())
  {
    cout << "The queue is full\n";
    return;
  }

  structure[last++ % max_items] = item;
}
ItemType Queue::dequeue()
{
  if (isEmpty())
  {
    cout << "The queue is empty\n";
    return 0;
  }

  return structure[first++ % max_items];
}
void Queue::print()
{
  cout << "Queue: [";
  for (ItemType i = first; i < last; i++)
    cout << structure[i % max_items] << " ";
  cout << "]\n";
}