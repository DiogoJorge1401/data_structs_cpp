typedef int ItemType;

struct Node
{
  ItemType value;
  Node *next;
};

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