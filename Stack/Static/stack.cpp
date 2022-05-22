#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()
{
  length = 0;
  structure = new ItemType[max_items];
}

Stack::~Stack()
{
  delete[] structure;
}

bool Stack::isFull()
{
  return length == max_items;
}

bool Stack::isEmpty()
{
  return length == 0;
}

void Stack::push(ItemType item)
{
  if (isFull())
  {
    cout << "\nStack is full!\n";
    return;
  }
  structure[length++] = item;
}

ItemType Stack::pop()
{
  if (isEmpty())
  {
    cout << "\nStack is empty!\n";
    return 0;
  }
  return structure[--length];
}

void Stack::print()
{
  cout << "Stack: [ ";
  for (int i = 0; i < length; i++)
    cout << structure[i]<<" ";
  cout << "]\n";
}

int Stack::getLength()
{
  return length;
}