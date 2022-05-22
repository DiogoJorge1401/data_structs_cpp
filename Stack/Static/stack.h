typedef int ItemType;
const int max_items = 10;

class Stack
{
private:
  int length;
  ItemType *structure;

public:
  Stack();
  ~Stack();
  bool isFull();
  bool isEmpty();
  void push(ItemType);
  ItemType pop();
  void print();
  int getLength();
};