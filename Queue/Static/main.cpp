#include <iostream>
#include "queue.cpp"

using namespace std;

ItemType element;
Queue queue;
int choose;

void menu()
{
  cout << "Queue generator program:\n";
  cout
      << "[1] Insert an element\n"
      << "[2] Remove an element\n"
      << "[3] Print the queue\n"
      << "[0] Stop the program\n";
  cin >> choose;
}

void insert()
{
  ItemType item;
  cout << "Type the element to be inserted into the queue: ";
  cin >> item;
  queue.enqueue(item);
}

void remove()
{
  cout << "The element removed was " << queue.dequeue() << endl;
}

void print()
{
  queue.print();
}

void clear()
{
  system("clear");
}

int main(int argc, char const *argv[])
{
  do
  {
    menu();
    switch (choose)
    {
    case 1:
      clear();
      insert();
      break;
    case 2:
      clear();
      remove();
      break;
    case 3:
      clear();
      print();
      break;
    default:
      clear();
      menu();
      break;
    }
  } while (choose);
  return 0;
}