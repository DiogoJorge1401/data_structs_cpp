typedef int ItemType;
const int max_items = 5;


class Queue
{
private:
  int first, last;
  ItemType *structure;

public:
  Queue();
  ~Queue();
  bool isEmpty();
  bool isFull();
  void enqueue(ItemType);
  ItemType dequeue();
  void print();
};